#include <gtest/gtest.h>

#include <cereal/types/memory.hpp>
#include <cereal/types/polymorphic.hpp>
#include <memory>
#include <string>
#include <vector>

#include "falcon_core/communications/HDF5Data.hpp"
#include "falcon_core/communications/messages/MeasurementRequest.hpp"
#include "falcon_core/communications/messages/MeasurementResponse.hpp"
#include "falcon_core/communications/voltage_states/DeviceVoltageStates.hpp"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Map.hpp"
#include "falcon_core/instrument_interfaces/Waveform.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/Axes.hpp"
#include "falcon_core/math/arrays/ControlArray.hpp"
#include "falcon_core/math/arrays/LabelledArrays.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"
#include "falcon_core/math/domains/LabelledDomain.hpp"

#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentTypes.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

using namespace falcon_core;

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::MeasurementRequest)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::communications::messages::MeasurementRequest)
CEREAL_REGISTER_TYPE(falcon_core::communications::messages::MeasurementResponse)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::communications::messages::MeasurementResponse)

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
  const std::string tmp_path = "/tmp/test_hdf5_data_roundtrip.h5";
  ASSERT_NO_THROW(hdf.to_file(tmp_path));
  auto loaded = HDF5Data::from_file(tmp_path);
  ASSERT_NE(loaded, nullptr);

  // Compare JSON representations for equality
  std::string loaded_json = loaded->to_json_string();
  EXPECT_EQ(loaded_json, orig_json);
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
  auto pseudo_conn = Connection::PlungerGate("P1");
  Instrument instr = InstrumentTypes::DC_VOLTAGE_SOURCE;
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

}  // namespace
