#include <gtest/gtest.h>

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"
namespace tests {
using namespace falcon_core::instrument_interfaces::names;

// Test Knob serialization
TEST(InstrumentInterfacesNamesTest, KnobSerializationRoundTrip) {
  auto knob = InstrumentPort::Knob(
      "test_knob", nullptr, "test_type", nullptr, "Test knob");

  std::string json = knob->to_json_string();
  std::cout << "Serialized Knob JSON:\n" << json << std::endl;

  InstrumentPortSP knob2 =
      InstrumentPort::from_json_string<InstrumentPort>(json);

  ASSERT_EQ(knob2->default_name(), "test_knob");
  ASSERT_EQ(knob2->instrument_type(), "test_type");
  ASSERT_EQ(knob2->description(), "Test knob");
}

// Test Meter serialization
TEST(InstrumentInterfacesNamesTest, MeterSerializationRoundTrip) {
  auto meter = InstrumentPort::Meter(
      "test_meter", nullptr, "test_type", nullptr, "Test meter");

  std::string json = meter->to_json_string();
  std::cout << "Serialized Meter JSON:\n" << json << std::endl;

  InstrumentPortSP meter2 =
      InstrumentPort::from_json_string<InstrumentPort>(json);

  ASSERT_EQ(meter2->default_name(), "test_meter");
  ASSERT_EQ(meter2->instrument_type(), "test_type");
  ASSERT_EQ(meter2->description(), "Test meter");
}

// Test Timer serialization
TEST(InstrumentInterfacesNamesTest, TimerSerializationRoundTrip) {
  auto timer = InstrumentPort::Timer();

  std::string json = timer->to_json_string();
  std::cout << "Serialized Timer JSON:\n" << json << std::endl;

  auto timer2 = InstrumentPort::from_json_string<InstrumentPort>(json);

  ASSERT_EQ(timer2->default_name(), falcon_core::INSTRUMENT_TYPES::CLOCK);
  ASSERT_EQ(timer2->instrument_type(), falcon_core::INSTRUMENT_TYPES::CLOCK);
  ASSERT_EQ(timer2->description(), "Clock");
}

// Test ExecutionClock serialization
TEST(InstrumentInterfacesNamesTest, ExecutionClockSerializationRoundTrip) {
  auto exec_clock = InstrumentPort::ExecutionClock();

  std::string json = exec_clock->to_json_string();
  std::cout << "Serialized ExecutionClock JSON:\n" << json << std::endl;

  auto exec_clock2 = InstrumentPort::from_json_string<InstrumentPort>(json);

  ASSERT_EQ(exec_clock2->default_name(), falcon_core::INSTRUMENT_TYPES::CLOCK);
  ASSERT_EQ(exec_clock2->instrument_type(),
            falcon_core::INSTRUMENT_TYPES::CLOCK);
  ASSERT_EQ(exec_clock2->description(), "Execution clock");
}

// Test Knobs collection serialization
TEST(InstrumentInterfacesNamesTest, KnobsSerializationRoundTrip) {
  auto knobs = std::make_shared<Ports>();
  knobs->push_back(
      InstrumentPort::Knob("knob1", nullptr, "type1", nullptr, "desc1"));
  knobs->push_back(
      InstrumentPort::Knob("knob2", nullptr, "type2", nullptr, "desc2"));

  std::string json = knobs->to_json_string();
  std::cout << "Serialized Knobs JSON:\n" << json << std::endl;

  auto knobs2 = Ports::from_json_string<Ports>(json);

  ASSERT_EQ(knobs2->size(), 2);
  ASSERT_TRUE(knobs2->is_knobs());
  ASSERT_EQ(knobs2->at(0)->default_name(), "knob1");
  ASSERT_EQ(knobs2->at(1)->default_name(), "knob2");
}

// Test Meters collection serialization
TEST(InstrumentInterfacesNamesTest, MetersSerializationRoundTrip) {
  auto meters = std::make_shared<Ports>();
  meters->push_back(
      InstrumentPort::Meter("meter1", nullptr, "type1", nullptr, "desc1"));
  meters->push_back(
      InstrumentPort::Meter("meter2", nullptr, "type2", nullptr, "desc2"));

  std::string json = meters->to_json_string();
  std::cout << "Serialized Meters JSON:\n" << json << std::endl;

  auto meters2 = Ports::from_json_string<Ports>(json);

  ASSERT_EQ(meters2->size(), 2);
  ASSERT_TRUE(meters2->is_meters());
  ASSERT_EQ(meters2->at(0)->default_name(), "meter1");
  ASSERT_EQ(meters2->at(1)->default_name(), "meter2");
}
}  // namespace tests
