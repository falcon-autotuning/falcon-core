#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon-core/instrument_interfaces/names/Instrument.hpp"
#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon-core/instrument_interfaces/names/InstrumentTypes.hpp"
#include "falcon-core/physics/device_structures/Connection.hpp"
#include "falcon-core/physics/units/SymbolUnit.hpp"

namespace {
using namespace falcon_core::instrument_interfaces::names;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::physics::units;

class InstrumentPortTest : public ::testing::Test {
 protected:
  std::string  default_name    = "foo";
  ConnectionSP pseudo_name     = Connection::PlungerGate("P1");
  Instrument   instrument_type = InstrumentTypes::DC_VOLTAGE_SOURCE;
  SymbolUnitSP units           = SymbolUnit::Volt();
  std::string  description     = "desc";
  PortType     type            = PortType::InstrumentPort;
};

TEST_F(InstrumentPortTest, ConstructValidInstrumentPort) {
  InstrumentPort port(
      default_name, pseudo_name, instrument_type, units, description, type);
  EXPECT_EQ(port.default_name(), default_name);
  EXPECT_EQ(port.pseudo_name(), pseudo_name);
  EXPECT_EQ(port.instrument_type(), instrument_type);
  EXPECT_EQ(port.units()->symbol(), units->symbol());
  EXPECT_EQ(port.description(), description);
  EXPECT_TRUE(port.is_port());
  EXPECT_FALSE(port.is_knob());
  EXPECT_FALSE(port.is_meter());
}

TEST_F(InstrumentPortTest, KnobFactoryValid) {
  auto knob = InstrumentPort::Knob(default_name,
                                   pseudo_name,
                                   instrument_type,
                                   SymbolUnit::MilliVolt(),
                                   "desc");
  EXPECT_TRUE(knob->is_knob());
  EXPECT_FALSE(knob->is_meter());
  EXPECT_FALSE(knob->is_port());
}

TEST_F(InstrumentPortTest, PortNullptrThrowsPsuedoName) {
  InstrumentPort port(
      default_name, nullptr, instrument_type, SymbolUnit::MilliVolt(), "desc");
  EXPECT_EQ(port.instrument_facing_name(), port.instrument_type());
  EXPECT_THROW(port.pseudo_name(), std::runtime_error);
}

TEST_F(InstrumentPortTest, KnobFactoryNullptrThrows) {
  EXPECT_THROW(InstrumentPort::Knob(default_name,
                                    nullptr,
                                    instrument_type,
                                    SymbolUnit::MilliVolt(),
                                    "desc"),
               std::invalid_argument);
}

TEST_F(InstrumentPortTest, KnobFactoryNullUnitThrows) {
  EXPECT_THROW(InstrumentPort::Knob(default_name,
                                    Connection::PlungerGate("P1"),
                                    instrument_type,
                                    nullptr,
                                    "desc"),
               std::invalid_argument);
}

TEST_F(InstrumentPortTest, MeterFactoryValid) {
  auto meter = InstrumentPort::Meter(default_name,
                                     pseudo_name,
                                     instrument_type,
                                     SymbolUnit::NanoAmpere(),
                                     "desc");
  EXPECT_TRUE(meter->is_meter());
  EXPECT_FALSE(meter->is_knob());
  EXPECT_FALSE(meter->is_port());
}

TEST_F(InstrumentPortTest, MeterFactoryNullptrThrows) {
  EXPECT_THROW(InstrumentPort::Meter(default_name,
                                     nullptr,
                                     instrument_type,
                                     SymbolUnit::NanoAmpere(),
                                     "desc"),
               std::invalid_argument);
}

TEST_F(InstrumentPortTest, TimerAndExecutionClock) {
  auto timer = InstrumentPort::Timer();
  auto clock = InstrumentPort::ExecutionClock();
  EXPECT_TRUE(timer != nullptr);
  EXPECT_TRUE(clock != nullptr);
}

TEST_F(InstrumentPortTest, InstrumentFacingNameWithPseudoName) {
  InstrumentPort port(
      default_name, pseudo_name, instrument_type, units, description, type);
  EXPECT_EQ(port.instrument_facing_name(), pseudo_name->name());
}

TEST_F(InstrumentPortTest, SerializationRoundTrip) {
  InstrumentPort port(
      default_name, pseudo_name, instrument_type, units, description, type);
  std::string json  = port.to_json_string();
  auto        port2 = InstrumentPort::from_json_string<InstrumentPort>(json);
  ASSERT_NE(port2, nullptr);
  EXPECT_EQ(port2->default_name(), default_name);
  EXPECT_EQ(port2->pseudo_name()->name(), pseudo_name->name());
  EXPECT_EQ(port2->instrument_type(), instrument_type);
  EXPECT_EQ(port2->units()->symbol(), units->symbol());
  EXPECT_EQ(port2->description(), description);
  EXPECT_TRUE(port2->is_port());
}

TEST_F(InstrumentPortTest, EqualityOperatorTrueForIdentical) {
  InstrumentPort port1(
      default_name, pseudo_name, instrument_type, units, description, type);
  InstrumentPort port2(
      default_name, pseudo_name, instrument_type, units, description, type);
  EXPECT_TRUE(port1 == port2);
  EXPECT_FALSE(port1 != port2);
}

TEST_F(InstrumentPortTest, EqualityOperatorFalseForDifferentName) {
  InstrumentPort port1(
      default_name, pseudo_name, instrument_type, units, description, type);
  InstrumentPort port2(
      "different", pseudo_name, instrument_type, units, description, type);
  EXPECT_FALSE(port1 == port2);
  EXPECT_TRUE(port1 != port2);
}

TEST_F(InstrumentPortTest, EqualityOperatorFalseForDifferentInstrumentType) {
  InstrumentPort port1(
      default_name, pseudo_name, instrument_type, units, description, type);
  InstrumentPort port2(default_name,
                       pseudo_name,
                       InstrumentTypes::DC_CURRENT_SOURCE,
                       units,
                       description,
                       type);
  EXPECT_FALSE(port1 == port2);
  EXPECT_TRUE(port1 != port2);
}

TEST_F(InstrumentPortTest, EqualityOperatorFalseForDifferentUnits) {
  InstrumentPort port1(
      default_name, pseudo_name, instrument_type, units, description, type);
  InstrumentPort port2(default_name,
                       pseudo_name,
                       instrument_type,
                       SymbolUnit::MilliVolt(),
                       description,
                       type);
  EXPECT_FALSE(port1 == port2);
  EXPECT_TRUE(port1 != port2);
}

TEST_F(InstrumentPortTest, EqualityOperatorFalseForDifferentDescription) {
  InstrumentPort port1(
      default_name, pseudo_name, instrument_type, units, description, type);
  InstrumentPort port2(
      default_name, pseudo_name, instrument_type, units, "otherdesc", type);
  EXPECT_FALSE(port1 == port2);
  EXPECT_TRUE(port1 != port2);
}

TEST_F(InstrumentPortTest, EqualityOperatorFalseForDifferentType) {
  InstrumentPort port1(default_name,
                       pseudo_name,
                       instrument_type,
                       units,
                       description,
                       PortType::InstrumentPort);
  InstrumentPort port2(default_name,
                       pseudo_name,
                       instrument_type,
                       units,
                       description,
                       PortType::Knob);
  EXPECT_FALSE(port1 == port2);
  EXPECT_TRUE(port1 != port2);
}

TEST_F(InstrumentPortTest,
       EqualityOperatorFalseForDifferentInstrumentFacingName) {
  InstrumentPort port1(
      default_name, pseudo_name, instrument_type, units, description, type);
  // Use a different pseudo_name to change instrument_facing_name
  ConnectionSP   pseudo_name2 = Connection::PlungerGate("P2");
  InstrumentPort port2(
      default_name, pseudo_name2, instrument_type, units, description, type);
  EXPECT_FALSE(port1 == port2);
  EXPECT_TRUE(port1 != port2);
}

}  // namespace
