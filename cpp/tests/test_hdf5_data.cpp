#include <gtest/gtest.h>

#include <boost/filesystem.hpp>
#include <boost/uuid/random_generator.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/polymorphic.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <xtensor/xarray.hpp>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/communications/HDF5Data.hpp"
#include "falcon_core/communications/messages/MeasurementRequest.hpp"
#include "falcon_core/communications/messages/MeasurementResponse.hpp"
#include "falcon_core/communications/voltage_states/DeviceVoltageStates.hpp"
#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Map.hpp"
#include "falcon_core/instrument_interfaces/Waveform.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentTypes.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/Axes.hpp"
#include "falcon_core/math/arrays/ControlArray.hpp"
#include "falcon_core/math/arrays/LabelledArrays.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"
#include "falcon_core/math/domains/LabelledDomain.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

using namespace falcon_core;

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::MeasurementRequest)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::communications::messages::MeasurementRequest)
CEREAL_REGISTER_TYPE(falcon_core::communications::messages::MeasurementResponse)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::communications::messages::MeasurementResponse)

CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::InstrumentPort)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::InstrumentPort)

CEREAL_REGISTER_TYPE(falcon_core::math::domains::LabelledDomain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::domains::LabelledDomain)

CEREAL_REGISTER_TYPE(falcon_core::math::domains::CoupledLabelledDomain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::domains::CoupledLabelledDomain)

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::arrays::ControlArray)

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledMeasuredArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::arrays::LabelledMeasuredArray)

CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::contexts::AcquisitionContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::contexts::AcquisitionContext)

CEREAL_REGISTER_TYPE(falcon_core::physics::units::SymbolUnit)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::physics::units::SymbolUnit)

namespace {

using communications::HDF5Data;
using communications::HDF5DataSP;
using communications::messages::MeasurementRequest;
using communications::messages::MeasurementResponse;
using communications::voltage_states::DeviceVoltageStates;
using communications::voltage_states::DeviceVoltageStatesSP;
using math::Axes;
using axes = math::Axes<int>;
using generic::List;
using generic::Map;
using instrument_interfaces::Waveform;
using instrument_interfaces::names::Ports;
using instrument_interfaces::port_transforms::PortTransform;
using math::arrays::ControlArray;
using math::arrays::LabelledArrays;
using math::arrays::LabelledMeasuredArray;
using math::domains::LabelledDomain;

// Helper function to create a temporary file path
boost::filesystem::path create_temp_path(const std::string& filename) {
  boost::filesystem::path temp_dir = boost::filesystem::temp_directory_path();
  return temp_dir / filename;
}

TEST(HDF5DataTest, FileRoundTripEmptyMetadata) {
  // Build minimal empty axes/domains/ranges and empty metadata to avoid
  // known parsing branches that expect datasets.
  auto shape_axes =
      std::make_shared<Axes<int>>(std::vector<int>{});  // empty shape
  auto unit_domain = std::make_shared<Axes<ControlArray>>(
      std::vector<std::shared_ptr<ControlArray>>{});  // empty
  auto domain_labels =
      std::make_shared<Axes<math::domains::CoupledLabelledDomain>>(
          std::vector<std::shared_ptr<math::domains::CoupledLabelledDomain>>{});
  auto ranges = LabelledArrays<LabelledMeasuredArray>::LabelledMeasuredArrays();

  // Empty metadata
  std::vector<std::pair<std::string, std::string>> md_init;
  auto metadata = std::make_shared<Map<std::string, std::string>>(md_init);

  HDF5Data hdf(shape_axes,
               unit_domain,
               domain_labels,
               ranges,
               metadata,
               "test_title",
               12345,
               67890);

  // Serialize to JSON (Song) before writing
  std::string orig_json = hdf.to_json_string();
  ASSERT_FALSE(orig_json.empty());

  // Write to a temp file and read back
  boost::filesystem::path tmp_path =
      create_temp_path("test_hdf5_data_roundtrip.h5");
  ASSERT_NO_THROW(hdf.to_file(tmp_path.string()));
  auto loaded = HDF5Data::from_file(tmp_path.string());
  ASSERT_NE(loaded, nullptr);

  // Compare JSON representations for Equal
  std::string loaded_json = loaded->to_json_string();
  EXPECT_EQ(loaded_json, orig_json);

  // Clean up
  boost::filesystem::remove(tmp_path);
}

TEST(HDF5DataTest, ToCommunicationsRoundTrip) {
  // Construct minimal MeasurementRequest and MeasurementResponse objects.
  // Use empty/placeholder containers so their serialization still works.
  auto waveforms = std::make_shared<List<Waveform>>();
  auto getters   = std::make_shared<instrument_interfaces::names::Ports>();
  auto meter_transforms = std::make_shared<
      Map<instrument_interfaces::names::InstrumentPort,
          instrument_interfaces::port_transforms::PortTransform>>();

  // Build a valid LabelledDomain using the public factory
  using namespace falcon_core::physics::device_structures;
  using namespace falcon_core::instrument_interfaces::names;
  auto       pseudo_conn = Connection::PlungerGate("P1");
  Instrument instr       = InstrumentTypes::DC_VOLTAGE_SOURCE;
  auto port = std::make_shared<InstrumentPort>("port", pseudo_conn, instr);
  auto time_domain =
      math::domains::LabelledDomain::from_port(std::make_pair(0.0, 1.0), port);

  auto request =
      std::make_shared<MeasurementRequest>(std::string("msg"),
                                           std::string("measurement_name"),
                                           waveforms,
                                           getters,
                                           meter_transforms,
                                           time_domain);

  auto arrays = LabelledArrays<LabelledMeasuredArray>::LabelledMeasuredArrays();
  auto response = std::make_shared<MeasurementResponse>(arrays);

  // Put the serialized request/response into metadata as
  // HDF5Data::from_communications would do internally.
  std::vector<std::pair<std::string, std::string>> md_init = {
      {"song_request", request->to_json_string()},
      {"song_response", response->to_json_string()},
  };
  auto metadata = std::make_shared<Map<std::string, std::string>>(md_init);

  auto shape_axes =
      std::make_shared<Axes<int>>(std::vector<int>{});  // empty shape
  auto unit_domain = std::make_shared<Axes<ControlArray>>(
      std::vector<std::shared_ptr<ControlArray>>{});  // empty
  auto domain_labels =
      std::make_shared<Axes<math::domains::CoupledLabelledDomain>>(
          std::vector<std::shared_ptr<math::domains::CoupledLabelledDomain>>{});
  auto ranges_sp =
      LabelledArrays<LabelledMeasuredArray>::LabelledMeasuredArrays();

  HDF5Data hdf_with_meta(shape_axes,
                         unit_domain,
                         domain_labels,
                         ranges_sp,
                         metadata,
                         "comm_test",
                         1,
                         2);

  // to_communications should deserialize the stored JSON strings back into
  // MeasurementResponse and MeasurementRequest objects.
  auto pair         = hdf_with_meta.to_communications();
  auto got_response = pair.first;
  auto got_request  = pair.second;

  ASSERT_NE(got_response, nullptr);
  ASSERT_NE(got_request, nullptr);

  // Compare the JSON strings to ensure round-trip fidelity.
  EXPECT_EQ(got_response->to_json_string(), response->to_json_string());
  EXPECT_EQ(got_request->to_json_string(), request->to_json_string());
}

TEST(HDF5DataTest, FileRoundTripFull) {
  using namespace falcon_core::physics::device_structures;
  using namespace falcon_core::instrument_interfaces::names;

  // shape: one axis with value 1
  auto shape_axes = std::make_shared<Axes<int>>(std::vector<int>{1});

  // unit_domain: one ControlArray containing a small xtensor
  xt::xarray<double> ctrl_arr = {{0.0, 1.0}};  // 1 x 2
  auto control_array = std::make_shared<math::arrays::ControlArray>(ctrl_arr);
  auto unit_domain   = std::make_shared<Axes<math::arrays::ControlArray>>(
      std::vector<std::shared_ptr<math::arrays::ControlArray>>{control_array});

  // domain_labels: one CoupledLabelledDomain with a single LabelledDomain from
  // a port
  auto       pseudo_conn = Connection::PlungerGate("P1");
  Instrument instr       = InstrumentTypes::DC_VOLTAGE_SOURCE;
  auto port = std::make_shared<InstrumentPort>("port", pseudo_conn, instr);
  auto labelled =
      math::domains::LabelledDomain::from_port(std::make_pair(0.0, 1.0), port);
  auto coupled = std::make_shared<math::domains::CoupledLabelledDomain>(
      std::vector<math::domains::LabelledDomainSP>{labelled});
  auto domain_labels =
      std::make_shared<Axes<math::domains::CoupledLabelledDomain>>(
          std::vector<std::shared_ptr<math::domains::CoupledLabelledDomain>>{
              coupled});

  // ranges: one LabelledMeasuredArray (simple measured array with a port)
  xt::xarray<double> meas_arr = {{10.0, 20.0}};
  auto               farr = std::make_shared<generic::FArray<double>>(meas_arr);
  auto lm = std::make_shared<math::arrays::LabelledMeasuredArray>(farr, port);
  auto ranges =
      math::arrays::LabelledArrays<math::arrays::LabelledMeasuredArray>::
          LabelledMeasuredArrays(
              std::vector<math::arrays::LabelledMeasuredArraySP>{lm});

  // metadata
  std::vector<std::pair<std::string, std::string>> md_init = {
      {"author", "tester"}, {"description", "full roundtrip test"}};
  auto metadata =
      std::make_shared<generic::Map<std::string, std::string>>(md_init);

  HDF5Data hdf(shape_axes,
               unit_domain,
               domain_labels,
               ranges,
               metadata,
               "full_test",
               42,
               123456);

  // write and read back
  boost::filesystem::path tmp_path = create_temp_path("test_hdf5_data_full.h5");
  ASSERT_NO_THROW(hdf.to_file(tmp_path.string()));
  auto loaded = HDF5Data::from_file(tmp_path.string());
  ASSERT_NE(loaded, nullptr);

  // Loaded JSON should contain key semantic elements from the original (avoid
  // brittle exact pointer-id checks from cereal)
  std::string loaded_json = loaded->to_json_string();
  EXPECT_NE(loaded_json.find("full_test"), std::string::npos);
  EXPECT_NE(loaded_json.find("42"), std::string::npos);
  EXPECT_NE(loaded_json.find("123456"), std::string::npos);
  EXPECT_NE(loaded_json.find("author"), std::string::npos);
  EXPECT_NE(loaded_json.find("tester"), std::string::npos);
  EXPECT_NE(loaded_json.find("P1"), std::string::npos);
  EXPECT_NE(loaded_json.find("10.0"), std::string::npos);
  EXPECT_NE(loaded_json.find("20.0"), std::string::npos);
  EXPECT_NE(loaded_json.find("0.0"), std::string::npos);
  EXPECT_NE(loaded_json.find("1.0"), std::string::npos);

  // Clean up
  boost::filesystem::remove(tmp_path);
}

TEST(HDF5DataTest, EqualityOperators) {
  auto shape_axes  = std::make_shared<Axes<int>>(std::vector<int>{1});
  auto unit_domain = std::make_shared<Axes<ControlArray>>(
      std::vector<std::shared_ptr<ControlArray>>{});
  auto domain_labels =
      std::make_shared<Axes<math::domains::CoupledLabelledDomain>>(
          std::vector<std::shared_ptr<math::domains::CoupledLabelledDomain>>{});
  auto ranges = LabelledArrays<LabelledMeasuredArray>::LabelledMeasuredArrays();
  auto metadata = std::make_shared<Map<std::string, std::string>>(
      std::vector<std::pair<std::string, std::string>>{});
  HDF5Data hdf1(
      shape_axes, unit_domain, domain_labels, ranges, metadata, "title", 1, 2);
  HDF5Data hdf2(
      shape_axes, unit_domain, domain_labels, ranges, metadata, "title", 1, 2);
  HDF5Data hdf3(
      shape_axes, unit_domain, domain_labels, ranges, metadata, "other", 1, 2);
  EXPECT_TRUE(hdf1 == hdf2);
  EXPECT_FALSE(hdf1 != hdf2);
  EXPECT_FALSE(hdf1 == hdf3);
  EXPECT_TRUE(hdf1 != hdf3);
}

TEST(HDF5DataTest, FromCommunicationsSetsFields) {
  using namespace falcon_core;
  using namespace communications;
  using namespace communications::messages;
  using namespace communications::voltage_states;
  using namespace math;
  using namespace domains;
  using namespace instrument_interfaces;
  using namespace instrument_interfaces::names;
  using namespace instrument_interfaces::port_transforms;

  // Build valid waveform using CartesianWaveform1D
  auto knob_port = InstrumentPort::Knob(
      "Vg1", physics::device_structures::Connection::PlungerGate("P1"));
  auto domain = std::make_shared<Domain>(std::pair<double, double>(0, 1));
  auto labelled_domain =
      LabelledDomain::from_port_and_domain(knob_port, domain);
  auto coupled_domain = std::make_shared<CoupledLabelledDomain>(
      std::vector<LabelledDomainSP>{labelled_domain});
  auto map_increasing = std::make_shared<Map<std::string, bool>>();
  map_increasing->insert("Vg1", true);
  auto transforms = std::make_shared<List<PortTransform>>();
  transforms->push_back(PortTransform::IdentityTransform(knob_port));
  auto waveform = Waveform::CartesianWaveform1D(
      10, coupled_domain, map_increasing, transforms, domain);
  auto waveforms = std::make_shared<List<Waveform>>();
  waveforms->push_back(waveform);
  // Minimal valid getters, meter_transforms, time_domain
  auto getters = std::make_shared<Ports>();
  auto meter_transforms =
      std::make_shared<Map<InstrumentPort, PortTransform>>();
  auto time_domain = LabelledDomain::from_port_and_domain(knob_port, domain);

  auto request = std::make_shared<MeasurementRequest>(
      "msg", "name", waveforms, getters, meter_transforms, time_domain);
  auto arrays = math::arrays::LabelledArrays<
      math::arrays::LabelledMeasuredArray>::LabelledMeasuredArrays();
  auto               response = std::make_shared<MeasurementResponse>(arrays);
  auto               voltage_states = std::make_shared<DeviceVoltageStates>();
  boost::uuids::uuid session_id     = boost::uuids::random_generator()();
  std::string        title          = "comm_title";
  int                unique_id      = 123;
  int                timestamp      = 456;
  auto               request1       = std::make_shared<MeasurementRequest>(
      "msg", "name", waveforms, getters, meter_transforms, time_domain);
  std::cout << "Request JSON: " << request1->to_json_string() << std::endl;
  auto hdf = HDF5Data::from_communications(request,
                                           response,
                                           voltage_states,
                                           session_id,
                                           title,
                                           unique_id,
                                           timestamp);
  ASSERT_NE(hdf, nullptr);
  EXPECT_EQ(hdf->measurement_title(), title);
  EXPECT_EQ(hdf->unique_id(), unique_id);
  EXPECT_EQ(hdf->timestamp(), timestamp);
  EXPECT_NO_THROW(hdf->metadata()->at("song_request"));
  EXPECT_NO_THROW(hdf->metadata()->at("song_response"));
}

TEST(HDF5DataTest, MeasurementTitleRoundTrip) {
  using namespace falcon_core;
  using namespace math;
  using namespace math::arrays;
  using namespace math::domains;
  using namespace generic;

  auto shape_axes = std::make_shared<Axes<int>>(std::vector<int>{1});
  auto control_array =
      std::make_shared<ControlArray>(xt::xarray<double>{{0.0, 1.0}});
  auto unit_domain = std::make_shared<Axes<ControlArray>>(
      std::vector<std::shared_ptr<ControlArray>>{control_array});
  auto knob_port = instrument_interfaces::names::InstrumentPort::Knob(
      "Vg1", physics::device_structures::Connection::PlungerGate("P1"));
  auto domain = std::make_shared<Domain>(std::pair<double, double>(0, 1));
  auto labelled_domain =
      LabelledDomain::from_port_and_domain(knob_port, domain);
  auto coupled_domain = std::make_shared<CoupledLabelledDomain>(
      std::vector<LabelledDomainSP>{labelled_domain});
  auto domain_labels = std::make_shared<Axes<CoupledLabelledDomain>>(
      std::vector<std::shared_ptr<CoupledLabelledDomain>>{coupled_domain});
  auto ranges = LabelledArrays<LabelledMeasuredArray>::LabelledMeasuredArrays();
  auto metadata = std::make_shared<Map<std::string, std::string>>(
      std::vector<std::pair<std::string, std::string>>{});
  std::string title = "special_title";
  HDF5Data    hdf(shape_axes,
               unit_domain,
               domain_labels,
               ranges,
               metadata,
               title,
               42,
               123456);
  EXPECT_EQ(hdf.measurement_title(), title);

  boost::filesystem::path tmp_path =
      create_temp_path("test_hdf5_data_title.h5");
  hdf.to_file(tmp_path.string());
  auto loaded = HDF5Data::from_file(tmp_path.string());
  ASSERT_NE(loaded, nullptr);
  EXPECT_EQ(loaded->measurement_title(), title);

  // Clean up
  boost::filesystem::remove(tmp_path);
}

}  // namespace
