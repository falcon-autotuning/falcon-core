#include <gtest/gtest.h>
#include <falcon_core/communications/messages/BaseMessage.hpp>
#include <falcon_core/communications/messages/StandardRequest.hpp>
#include <falcon_core/communications/messages/StandardResponse.hpp>
#include <falcon_core/communications/messages/MeasurementRequest.hpp>
#include <falcon_core/communications/messages/MeasurementResponse.hpp>
#include <falcon_core/communications/messages/VoltageStatesResponse.hpp>
#include <falcon_core/communications/voltage_states/DeviceVoltageState.hpp>
#include <falcon_core/communications/voltage_states/DeviceVoltageStates.hpp>
#include <falcon_core/physics/device_structures/BaseConnection.hpp>
#include <falcon_core/physics/units/CommonUnits.hpp>
#include <falcon_core/physics/units/SymbolUnit.hpp>
#include <falcon_core/instrument_interfaces/names/Meters.hpp>
#include <falcon_core/instrument_interfaces/names/Meter.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>
#include <falcon_core/instrument_interfaces/waveforms/BaseWaveform.hpp>
#include <falcon_core/math/domains/KnobDomain.hpp>
#include <falcon_core/math/labelled_arrays/LabelledMeasuredArrays.hpp>
#include <memory>
#include <string>
#include <map>
#include <vector>

namespace tests {
using namespace falcon_core::communications::messages;
using namespace falcon_core::communications::voltage_states;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::physics::units;
using namespace falcon_core::instrument_interfaces::names;
using namespace falcon_core::instrument_interfaces::port_transforms;
using namespace falcon_core::instrument_interfaces::waveforms;
using namespace falcon_core::math::domains;
using namespace falcon_core::math::labelled_arrays;

// BaseMessage test
TEST(MessagesTest, BaseMessageConstructionAndSerialization) {
  BaseMessage msg("hello world");
  ASSERT_EQ(msg.message(), "hello world");

  std::string json = msg.to_json_string();
  auto msg2 = BaseMessage::from_json_string<BaseMessage>(json);
  ASSERT_EQ(msg2->message(), "hello world");
}

// StandardRequest test
TEST(MessagesTest, StandardRequestConstructionAndSerialization) {
  StandardRequest req("request message");
  ASSERT_EQ(req.message(), "request message");

  std::string json = req.to_json_string();
  auto req2 = StandardRequest::from_json_string<StandardRequest>(json);
  ASSERT_EQ(req2->message(), "request message");
}

// StandardResponse test
TEST(MessagesTest, StandardResponseConstructionAndSerialization) {
  StandardResponse resp("response message");
  ASSERT_EQ(resp.message(), "response message");

  std::string json = resp.to_json_string();
  auto resp2 = StandardResponse::from_json_string<StandardResponse>(json);
  ASSERT_EQ(resp2->message(), "response message");
}

// MeasurementRequest test
TEST(MessagesTest, MeasurementRequestConstructionAndSerialization) {
  auto unit = std::make_shared<SymbolUnit>(CommonUnits::Volt);
  auto conn = std::make_shared<BaseConnection>("gate1", DeviceFeature::BarrierGate);
  auto meter = std::make_shared<Meter>("meter1");
  auto meters = std::make_shared<Meters>(std::vector<std::shared_ptr<Meter>>{meter});
  auto waveform = std::make_shared<BaseWaveform>();
  std::vector<std::shared_ptr<BaseWaveform>> waveforms{waveform};
  std::map<std::shared_ptr<Meter>, std::shared_ptr<PortTransform>> meter_transforms;
  meter_transforms[meter] = std::make_shared<PortTransform>();
  auto time_domain = std::make_shared<KnobDomain>(0.0, 1.0, nullptr);

  MeasurementRequest req(
      "measurement request",
      "meas1",
      waveforms,
      meters,
      meter_transforms,
      time_domain);

  ASSERT_EQ(req.message(), "measurement request");
  ASSERT_EQ(req.measurement_name(), "meas1");
  ASSERT_EQ(req.waveforms().size(), 1);
  ASSERT_EQ(req.getters()->size(), 1);
  ASSERT_EQ(req.meter_transforms().size(), 1);

  std::string json = req.to_json_string();
  auto req2 = MeasurementRequest::from_json_string<MeasurementRequest>(json);
  ASSERT_EQ(req2->message(), "measurement request");
  ASSERT_EQ(req2->measurement_name(), "meas1");
  ASSERT_EQ(req2->waveforms().size(), 1);
  ASSERT_EQ(req2->getters()->size(), 1);
  ASSERT_EQ(req2->meter_transforms().size(), 1);
}

// MeasurementResponse test
TEST(MessagesTest, MeasurementResponseConstructionAndSerialization) {
  auto arrays = std::make_shared<LabelledMeasuredArrays>();
  MeasurementResponse resp(arrays);

  ASSERT_TRUE(resp.arrays() != nullptr);

  std::string json = resp.to_json_string();
  auto resp2 = MeasurementResponse::from_json_string<MeasurementResponse>(json);
  ASSERT_TRUE(resp2->arrays() != nullptr);
}

// VoltageStatesResponse test
TEST(MessagesTest, VoltageStatesResponseConstructionAndSerialization) {
  auto unit = std::make_shared<SymbolUnit>(CommonUnits::Volt);
  auto conn = std::make_shared<BaseConnection>("gate3", DeviceFeature::PlungerGate);
  auto dvs = std::make_shared<DeviceVoltageState>(conn, 2.34, unit);
  auto states = std::make_shared<DeviceVoltageStates>();
  states->add_state(dvs);

  VoltageStatesResponse resp("voltage states response", states);

  ASSERT_EQ(resp.message(), "voltage states response");
  ASSERT_EQ(resp.states()->states().size(), 1);

  std::string json = resp.to_json_string();
  auto resp2 = VoltageStatesResponse::from_json_string<VoltageStatesResponse>(json);
  ASSERT_EQ(resp2->message(), "voltage states response");
  ASSERT_EQ(resp2->states()->states().size(), 1);
}

} // namespace tests
