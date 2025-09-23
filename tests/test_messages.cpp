#include <gtest/gtest.h>

#include <cstddef>
#include <falcon_core/communications/messages/BaseMessage.hpp>
#include <falcon_core/communications/messages/MeasurementRequest.hpp>
#include <falcon_core/communications/messages/MeasurementResponse.hpp>
#include <falcon_core/communications/messages/StandardRequest.hpp>
#include <falcon_core/communications/messages/StandardResponse.hpp>
#include <falcon_core/communications/messages/VoltageStatesResponse.hpp>
#include <falcon_core/communications/voltage_states/DeviceVoltageState.hpp>
#include <falcon_core/communications/voltage_states/DeviceVoltageStates.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>
#include <falcon_core/instrument_interfaces/waveforms/BaseWaveform.hpp>
#include <falcon_core/instrument_interfaces/waveforms/CartesianWaveform1D.hpp>
#include <falcon_core/instrument_interfaces/waveforms/Waveform.hpp>
#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include <falcon_core/math/domains/LabelledDomain.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include <falcon_core/physics/units/SymbolUnit.hpp>
#include <memory>
#include <string>

namespace tests {
using namespace falcon_core::communications::messages;
using namespace falcon_core::communications::voltage_states;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::physics::units;
using namespace falcon_core::instrument_interfaces::names;
using namespace falcon_core::instrument_interfaces::port_transforms;
using namespace falcon_core::instrument_interfaces::waveforms;
using namespace falcon_core::math::domains;
using namespace falcon_core::math::arrays;

// BaseMessage test
TEST(MessagesTest, BaseMessageConstructionAndSerialization) {
  BaseMessage msg("hello world");
  ASSERT_EQ(msg.message(), "hello world");

  std::string json = msg.to_json_string();
  auto        msg2 = BaseMessage::from_json_string<BaseMessage>(json);
  ASSERT_EQ(msg2->message(), "hello world");
}

// StandardRequest test
TEST(MessagesTest, StandardRequestConstructionAndSerialization) {
  StandardRequest req("request message");
  ASSERT_EQ(req.message(), "request message");

  std::string json = req.to_json_string();
  auto        req2 = StandardRequest::from_json_string<StandardRequest>(json);
  ASSERT_EQ(req2->message(), "request message");
}

// StandardResponse test
TEST(MessagesTest, StandardResponseConstructionAndSerialization) {
  StandardResponse resp("response message");
  ASSERT_EQ(resp.message(), "response message");

  std::string json = resp.to_json_string();
  auto resp2       = StandardResponse::from_json_string<StandardResponse>(json);
  ASSERT_EQ(resp2->message(), "response message");
}

// MeasurementRequest test
TEST(MessagesTest, MeasurementRequestConstructionAndSerialization) {
  using waveform_type =
      falcon_core::instrument_interfaces::waveforms::BaseWaveform<
          falcon_core::math::discrete_spaces::BaseDiscreteSpace>;
  auto unit = SymbolUnit::Volt();
  auto conn = std::make_shared<Connection>("gate1", DeviceFeature::BarrierGate);
  auto meter =
      std::make_shared<InstrumentPort>("meter1",   // default_name
                                       nullptr,    // pseudo_name
                                       "UNKNOWN",  // instrument_type as string
                                       nullptr,    // units
                                       ""          // description
      );
  auto meters = std::make_shared<Ports>();
  meters->push_back(meter);
  auto waveform =
      std::make_shared<falcon_core::instrument_interfaces::waveforms::Waveform>(
          nullptr, nullptr);
  falcon_core::generic::ListSP<waveform_type> waveforms;
  waveforms->push_back(waveform);
  falcon_core::generic::MapSP<InstrumentPort, PortTransform> meter_transforms;
  meter_transforms->insert(meter,
                           std::make_shared<PortTransform>(nullptr, nullptr));
  auto time_domain =
      LabelledDomain::from_port(std::make_pair(0.0, 1.0), nullptr);

  MeasurementRequest req("measurement request",
                         "meas1",
                         waveforms,
                         meters,
                         meter_transforms,
                         time_domain);

  ASSERT_EQ(req.message(), "measurement request");
  ASSERT_EQ(req.measurement_name(), "meas1");
  ASSERT_EQ(req.waveforms()->size(), 1);
  ASSERT_EQ(req.getters()->size(), 1);
  ASSERT_EQ(req.meter_transforms()->size(), 1);

  std::string json = req.to_json_string();
  auto req2 = MeasurementRequest::from_json_string<MeasurementRequest>(json);
  ASSERT_EQ(req2->message(), "measurement request");
  ASSERT_EQ(req2->measurement_name(), "meas1");
  ASSERT_EQ(req2->waveforms()->size(), 1);
  ASSERT_EQ(req2->getters()->size(), 1);
  ASSERT_EQ(req2->meter_transforms()->size(), 1);
}

// MeasurementResponse test
TEST(MessagesTest, MeasurementResponseConstructionAndSerialization) {
  auto arrays = LabelledArrays<LabelledMeasuredArray>::LabelledMeasuredArrays();
  MeasurementResponse resp(arrays);

  ASSERT_TRUE(resp.arrays() != nullptr);

  std::string json = resp.to_json_string();
  auto resp2 = MeasurementResponse::from_json_string<MeasurementResponse>(json);
  ASSERT_TRUE(resp2->arrays() != nullptr);
}

// VoltageStatesResponse test
TEST(MessagesTest, VoltageStatesResponseConstructionAndSerialization) {
  auto unit   = SymbolUnit::Volt();
  auto conn   = Connection::PlungerGate("gate3");
  auto dvs    = std::make_shared<DeviceVoltageState>(conn, 2.34, unit);
  auto states = std::make_shared<DeviceVoltageStates>();
  states->add_state(dvs);

  VoltageStatesResponse resp("voltage states response", states);

  ASSERT_EQ(resp.message(), "voltage states response");
  ASSERT_EQ(resp.states()->states()->size(), 1);

  std::string json = resp.to_json_string();
  auto        resp2 =
      VoltageStatesResponse::from_json_string<VoltageStatesResponse>(json);
  ASSERT_EQ(resp2->message(), "voltage states response");
  ASSERT_EQ(resp2->states()->states()->size(), 1);
}

}  // namespace tests
