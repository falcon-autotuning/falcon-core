#include <gtest/gtest.h>

#include "falcon_core/instrument_interfaces/names/ExecutionClock.hpp"
#include "falcon_core/instrument_interfaces/names/Knob.hpp"
#include "falcon_core/instrument_interfaces/names/Knobs.hpp"
#include "falcon_core/instrument_interfaces/names/Meter.hpp"
#include "falcon_core/instrument_interfaces/names/Meters.hpp"
#include "falcon_core/instrument_interfaces/names/Timer.hpp"
namespace tests {
using namespace falcon_core::instrument_interfaces::names;

// Test Knob serialization
TEST(InstrumentInterfacesNamesTest, KnobSerializationRoundTrip) {
  auto knob = std::make_shared<Knob>(
      "test_knob", nullptr, "test_type", nullptr, "Test knob");

  std::string json = knob->to_json_string();
  std::cout << "Serialized Knob JSON:\n" << json << std::endl;

  auto knob2 = Knob::from_json_string<Knob>(json);

  ASSERT_EQ(knob2->default_name(), "test_knob");
  ASSERT_EQ(knob2->instrument_type(), "test_type");
  ASSERT_EQ(knob2->description(), "Test knob");
}

// Test Meter serialization
TEST(InstrumentInterfacesNamesTest, MeterSerializationRoundTrip) {
  auto meter = std::make_shared<Meter>(
      "test_meter", nullptr, "test_type", nullptr, "Test meter");

  std::string json = meter->to_json_string();
  std::cout << "Serialized Meter JSON:\n" << json << std::endl;

  auto meter2 = Meter::from_json_string<Meter>(json);

  ASSERT_EQ(meter2->default_name(), "test_meter");
  ASSERT_EQ(meter2->instrument_type(), "test_type");
  ASSERT_EQ(meter2->description(), "Test meter");
}

// Test Timer serialization
TEST(InstrumentInterfacesNamesTest, TimerSerializationRoundTrip) {
  auto timer = std::make_shared<Timer>();

  std::string json = timer->to_json_string();
  std::cout << "Serialized Timer JSON:\n" << json << std::endl;

  auto timer2 = Timer::from_json_string<Timer>(json);

  ASSERT_EQ(timer2->default_name(), falcon_core::INSTRUMENT_TYPES::CLOCK);
  ASSERT_EQ(timer2->instrument_type(), falcon_core::INSTRUMENT_TYPES::CLOCK);
  ASSERT_EQ(timer2->description(), "Clock");
}

// Test ExecutionClock serialization
TEST(InstrumentInterfacesNamesTest, ExecutionClockSerializationRoundTrip) {
  auto exec_clock = std::make_shared<ExecutionClock>();

  std::string json = exec_clock->to_json_string();
  std::cout << "Serialized ExecutionClock JSON:\n" << json << std::endl;

  auto exec_clock2 = ExecutionClock::from_json_string<ExecutionClock>(json);

  ASSERT_EQ(exec_clock2->default_name(), falcon_core::INSTRUMENT_TYPES::CLOCK);
  ASSERT_EQ(exec_clock2->instrument_type(),
            falcon_core::INSTRUMENT_TYPES::CLOCK);
  ASSERT_EQ(exec_clock2->description(), "Execution clock");
}

// Test Knobs collection serialization
TEST(InstrumentInterfacesNamesTest, KnobsSerializationRoundTrip) {
  auto knobs = std::make_shared<Knobs>();
  knobs->push_back(
      std::make_shared<Knob>("knob1", nullptr, "type1", nullptr, "desc1"));
  knobs->push_back(
      std::make_shared<Knob>("knob2", nullptr, "type2", nullptr, "desc2"));

  std::string json = knobs->to_json_string();
  std::cout << "Serialized Knobs JSON:\n" << json << std::endl;

  auto knobs2 = Knobs::from_json_string<Knobs>(json);

  ASSERT_EQ(knobs2->size(), 2);
  ASSERT_EQ(knobs2->at(0)->default_name(), "knob1");
  ASSERT_EQ(knobs2->at(1)->default_name(), "knob2");
}

// Test Meters collection serialization
TEST(InstrumentInterfacesNamesTest, MetersSerializationRoundTrip) {
  auto meters = std::make_shared<Meters>();
  meters->push_back(
      std::make_shared<Meter>("meter1", nullptr, "type1", nullptr, "desc1"));
  meters->push_back(
      std::make_shared<Meter>("meter2", nullptr, "type2", nullptr, "desc2"));

  std::string json = meters->to_json_string();
  std::cout << "Serialized Meters JSON:\n" << json << std::endl;

  auto meters2 = Meters::from_json_string<Meters>(json);

  ASSERT_EQ(meters2->size(), 2);
  ASSERT_EQ(meters2->at(0)->default_name(), "meter1");
  ASSERT_EQ(meters2->at(1)->default_name(), "meter2");
}
}  // namespace tests
