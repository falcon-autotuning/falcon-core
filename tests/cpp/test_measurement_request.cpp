#include <gtest/gtest.h>

#include <cereal/archives/binary.hpp>
#include <sstream>

#include "falcon-core/communications/messages/MeasurementRequest.hpp"
#include "falcon-core/generic/Map.hpp"
#include "falcon-core/instrument_interfaces/Waveform.hpp"
#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon-core/instrument_interfaces/names/Ports.hpp"
#include "falcon-core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon-core/instrument_interfaces/port_transforms/PortTransforms.hpp"
#include "falcon-core/math/Axes.hpp"
#include "falcon-core/math/discrete_spaces/DiscreteSpace.hpp"
#include "falcon-core/math/domains/Domain.hpp"
#include "falcon-core/math/domains/LabelledDomain.hpp"
namespace {
using namespace falcon_core::communications::messages;
using namespace falcon_core::instrument_interfaces;
using namespace falcon_core::instrument_interfaces::names;
using namespace falcon_core::instrument_interfaces::port_transforms;
using namespace falcon_core::math;
using namespace falcon_core::math::domains;
using namespace falcon_core::math::discrete_spaces;
using namespace falcon_core::generic;

class MeasurementRequestTest : public ::testing::Test {
 protected:
  std::string                          message;
  std::string                          measurement_name;
  ListSP<Waveform>                     waveforms;
  PortsSP                              getters;
  MapSP<InstrumentPort, PortTransform> meter_transforms;
  LabelledDomainSP                     time_domain;
  InstrumentPortSP                     knob_port;
  DomainSP                             domain;
  LabelledDomainSP                     labelled_domain;
  CoupledLabelledDomainSP              coupled_domain;
  AxesSP<CoupledLabelledDomain>        axes;
  AxesSP<Map<std::string, bool>>       increasing;
  MapSP<std::string, bool>             map_increasing;
  DiscreteSpaceSP                      discrete_space;
  ListSP<PortTransform>                transforms;

  void SetUp() override {
    message          = "msg";
    measurement_name = "meas";
    knob_port        = InstrumentPort::Knob(
        "Vg1",
        falcon_core::physics::device_structures::Connection::PlungerGate("P1"));
    domain          = std::make_shared<Domain>(std::pair<double, double>(0, 1));
    labelled_domain = LabelledDomain::from_port_and_domain(knob_port, domain);
    coupled_domain  = std::make_shared<CoupledLabelledDomain>(
        std::vector<LabelledDomainSP>{labelled_domain});
    axes = std::make_shared<Axes<CoupledLabelledDomain>>();
    axes->push_back(coupled_domain);
    map_increasing = std::make_shared<Map<std::string, bool>>();
    map_increasing->insert("Vg1", true);
    increasing = std::make_shared<Axes<Map<std::string, bool>>>();
    increasing->push_back(map_increasing);
    discrete_space = DiscreteSpace::CartesianDiscreteSpace(
        std::make_shared<Axes<int>>(std::vector<int>{10}),
        axes,
        increasing,
        domain);
    transforms = std::make_shared<List<PortTransform>>();
    transforms->push_back(PortTransform::IdentityTransform(knob_port));
    waveforms = std::make_shared<List<Waveform>>();
    waveforms->push_back(Waveform::CartesianWaveform(
        std::make_shared<Axes<int>>(std::vector<int>{10}),
        axes,
        increasing,
        transforms,
        domain));
    getters = std::make_shared<Ports>();
    getters->push_back(knob_port);
    meter_transforms = std::make_shared<Map<InstrumentPort, PortTransform>>();
    meter_transforms->insert(knob_port, transforms->at(0));
    time_domain = labelled_domain;
  }
};

TEST_F(MeasurementRequestTest, ConstructorWorks) {
  MeasurementRequest req(message,
                         measurement_name,
                         waveforms,
                         getters,
                         meter_transforms,
                         time_domain);
  EXPECT_EQ(req.measurement_name(), measurement_name);
  EXPECT_EQ(req.waveforms(), waveforms);
  EXPECT_EQ(req.getters(), getters);
  EXPECT_EQ(req.meter_transforms(), meter_transforms);
  EXPECT_EQ(req.time_domain(), time_domain);
}

TEST_F(MeasurementRequestTest, ThrowsOnNullWaveforms) {
  EXPECT_THROW(MeasurementRequest(message,
                                  measurement_name,
                                  nullptr,
                                  getters,
                                  meter_transforms,
                                  time_domain),
               std::invalid_argument);
}

TEST_F(MeasurementRequestTest, ThrowsOnNullGetters) {
  EXPECT_THROW(MeasurementRequest(message,
                                  measurement_name,
                                  waveforms,
                                  nullptr,
                                  meter_transforms,
                                  time_domain),
               std::invalid_argument);
}

TEST_F(MeasurementRequestTest, ThrowsOnNullMeterTransforms) {
  EXPECT_THROW(
      MeasurementRequest(
          message, measurement_name, waveforms, getters, nullptr, time_domain),
      std::invalid_argument);
}

TEST_F(MeasurementRequestTest, ThrowsOnNullTimeDomain) {
  EXPECT_THROW(MeasurementRequest(message,
                                  measurement_name,
                                  waveforms,
                                  getters,
                                  meter_transforms,
                                  nullptr),
               std::invalid_argument);
}

TEST_F(MeasurementRequestTest, SerializationRoundTrip) {
  MeasurementRequest req(message,
                         measurement_name,
                         waveforms,
                         getters,
                         meter_transforms,
                         time_domain);
  auto               string = req.to_json_string();
  auto               loaded =
      MeasurementRequest::from_json_string<MeasurementRequest>(string);
  EXPECT_EQ(req, *loaded);
}
}  // namespace
