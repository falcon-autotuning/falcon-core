#include <gtest/gtest.h>

#include <cereal/archives/binary.hpp>
#include <sstream>

#include "falcon_core/instrument_interfaces/names/Instrument.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace {
using namespace falcon_core;
using namespace generic;
using namespace instrument_interfaces;
using namespace names;

class PortsTest : public ::testing::Test {
 protected:
  InstrumentPortSP portA = std::make_shared<InstrumentPort>(
      "A",
      falcon_core::physics::device_structures::Connection::PlungerGate("PA"),
      INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE,
      physics::units::SymbolUnit::Volt(),
      "descA",
      PortType::InstrumentPort);
  InstrumentPortSP portB = std::make_shared<InstrumentPort>(
      "B",
      falcon_core::physics::device_structures::Connection::PlungerGate("PB"),
      INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE,
      physics::units::SymbolUnit::Volt(),
      "descB",
      PortType::InstrumentPort);
  InstrumentPortSP portC = std::make_shared<InstrumentPort>(
      "C",
      falcon_core::physics::device_structures::Connection::PlungerGate("PC"),
      INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE,
      physics::units::SymbolUnit::Volt(),
      "descC",
      PortType::InstrumentPort);
  PortsSP ports_empty = std::make_shared<Ports>();
  PortsSP ports_ABC   = std::make_shared<Ports>(
      std::vector<InstrumentPortSP>{portA, portB, portC});
};

TEST_F(PortsTest, ListSPConstructorAndNullptrThrows) {
  PortsSP valid = std::make_shared<Ports>(std::vector<InstrumentPortSP>{portA});
  Ports   from_list(valid);
  EXPECT_EQ(from_list.size(), 1u);
  EXPECT_THROW(Ports(nullptr), std::invalid_argument);
}

TEST_F(PortsTest, PortsGetter) {
  Ports ports(*ports_ABC);
  auto  list = ports.ports();
  EXPECT_EQ(list->size(), 3u);
  EXPECT_EQ((*list)[0], portA);
}

TEST_F(PortsTest, GetDefaultNames) {
  Ports ports(*ports_ABC);
  auto  names = ports.get_default_names();
  ASSERT_EQ(names->size(), 3u);
  EXPECT_EQ((*names)[0], "A");
  EXPECT_EQ((*names)[1], "B");
  EXPECT_EQ((*names)[2], "C");
}

TEST_F(PortsTest, GetPseudoNames) {
  Ports ports(*ports_ABC);
  auto  pseudos = ports.get_pseudo_names();
  ASSERT_EQ(pseudos->size(), 3u);
  EXPECT_EQ((*pseudos)[0]->name(), "PA");
  EXPECT_EQ((*pseudos)[1]->name(), "PB");
  EXPECT_EQ((*pseudos)[2]->name(), "PC");
}

TEST_F(PortsTest, GetPseudoNamesThrowsIfMissing) {
  InstrumentPortSP no_pseudo = std::make_shared<InstrumentPort>("D");
  Ports            ports({no_pseudo});
  EXPECT_THROW(ports.get_pseudo_names(), std::runtime_error);
}

TEST_F(PortsTest, GetRawNames) {
  Ports ports(*ports_ABC);
  auto  raw = ports._get_raw_names();
  ASSERT_EQ(raw->size(), 3u);
  EXPECT_EQ((*raw)[0], "PA");
}

TEST_F(PortsTest, GetInstrumentFacingNames) {
  Ports ports(*ports_ABC);
  auto  names = ports._get_instrument_facing_names();
  ASSERT_EQ(names->size(), 3u);
  EXPECT_EQ((*names)[0], portA->instrument_facing_name());
}

TEST_F(PortsTest, GetPsuedonameMatchingPort) {
  Ports ports(*ports_ABC);
  auto  found = ports._get_psuedoname_matching_port(portA->pseudo_name());
  EXPECT_EQ(found, portA);
  EXPECT_THROW(ports._get_psuedoname_matching_port(nullptr),
               std::invalid_argument);
  InstrumentPortSP not_found = std::make_shared<InstrumentPort>(
      "X",
      falcon_core::physics::device_structures::Connection::PlungerGate("PX"));
  EXPECT_THROW(ports._get_psuedoname_matching_port(not_found->pseudo_name()),
               std::runtime_error);
}

TEST_F(PortsTest, GetInstrumentTypeMatchingPort) {
  Ports ports(*ports_ABC);
  auto  found = ports._get_instrument_type_matching_port(
      INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE);
  EXPECT_EQ(found->instrument_type(), INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE);
  EXPECT_THROW(
      ports._get_instrument_type_matching_port(INSTRUMENT_TYPES::AMNMETER),
      std::runtime_error);
}

TEST_F(PortsTest, IsKnobsAndIsMeters) {
  auto knob = InstrumentPort::Knob(
      "K",
      falcon_core::physics::device_structures::Connection::PlungerGate("P1"));
  auto meter = InstrumentPort::Meter(
      "M", falcon_core::physics::device_structures::Connection::Ohmic("O1"));
  Ports knobs({knob, knob});
  Ports meters({meter, meter});
  Ports mixed({knob, meter});
  EXPECT_TRUE(knobs.is_knobs());
  EXPECT_FALSE(knobs.is_meters());
  EXPECT_TRUE(meters.is_meters());
  EXPECT_FALSE(meters.is_knobs());
  EXPECT_FALSE(mixed.is_knobs());
  EXPECT_FALSE(mixed.is_meters());
}

TEST_F(PortsTest, EqualityOperators) {
  // Equal ports
  Ports ports1({portA, portB, portC});
  Ports ports2({portA, portB, portC});
  EXPECT_TRUE(ports1 == ports2);
  EXPECT_FALSE(ports1 != ports2);

  // Different size
  Ports ports3({portA, portB});
  EXPECT_FALSE(ports1 == ports3);
  EXPECT_TRUE(ports1 != ports3);

  // Same size, different content
  InstrumentPortSP portC_alt = std::make_shared<InstrumentPort>(
      "C_alt",
      falcon_core::physics::device_structures::Connection::PlungerGate(
          "PC_alt"),
      INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE,
      physics::units::SymbolUnit::Volt(),
      "descC_alt",
      PortType::InstrumentPort);
  Ports ports4({portA, portB, portC_alt});
  EXPECT_FALSE(ports1 == ports4);
  EXPECT_TRUE(ports1 != ports4);
}

TEST_F(PortsTest, GetPseudoNamesThrowsIfPortIsNullptr) {
  InstrumentPortSP erroroneus_port =
      std::make_shared<InstrumentPort>("badport");
  Ports ports({erroroneus_port});
  EXPECT_THROW(ports.get_pseudo_names(), std::runtime_error);
}

TEST_F(PortsTest, GetPseudoNamesThrowsIfPortIsNullptrInList) {
  InstrumentPortSP no_pseudo = std::make_shared<InstrumentPort>("D");
  Ports            ports({portA, no_pseudo, portC});
  EXPECT_THROW(ports.get_pseudo_names(), std::runtime_error);
}

}  // namespace
