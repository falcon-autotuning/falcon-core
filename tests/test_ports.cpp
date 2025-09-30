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
  InstrumentPortSP portA =
      std::make_shared<InstrumentPort>("A",
                                       nullptr,
                                       INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE,
                                       physics::units::SymbolUnit::Volt(),
                                       "descA",
                                       PortType::InstrumentPort);
  InstrumentPortSP portB =
      std::make_shared<InstrumentPort>("B",
                                       nullptr,
                                       INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE,
                                       physics::units::SymbolUnit::Volt(),
                                       "descB",
                                       PortType::InstrumentPort);
  InstrumentPortSP portC =
      std::make_shared<InstrumentPort>("C",
                                       nullptr,
                                       INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE,
                                       physics::units::SymbolUnit::Volt(),
                                       "descC",
                                       PortType::InstrumentPort);
  PortsSP ports_empty = std::make_shared<Ports>();
  PortsSP ports_ABC   = std::make_shared<Ports>(
      std::vector<InstrumentPortSP>{portA, portB, portC});
};

TEST_F(PortsTest, DefaultConstructor) {
  EXPECT_TRUE(ports_empty->empty());
  EXPECT_EQ(ports_empty->size(), 0u);
}

TEST_F(PortsTest, VectorConstructor) {
  Ports ports(*ports_ABC);
  EXPECT_EQ(ports.size(), 3u);
  EXPECT_EQ(ports[0], portA);
  EXPECT_EQ(ports[1], portB);
  EXPECT_EQ(ports[2], portC);
}

TEST_F(PortsTest, PushBackValid) {
  Ports ports;
  ports.push_back(portA);
  EXPECT_EQ(ports.size(), 1u);
  EXPECT_EQ(ports[0], portA);
}

TEST_F(PortsTest, PushBackNullptrThrows) {
  Ports            ports;
  InstrumentPortSP dummy;
  EXPECT_THROW(ports.push_back(dummy), std::invalid_argument);
}

TEST_F(PortsTest, AtAndOperatorIndex) {
  Ports ports(*ports_ABC);
  EXPECT_EQ(ports.at(0), portA);
  EXPECT_EQ(ports[1], portB);
  EXPECT_EQ(ports[2], portC);
  EXPECT_THROW(ports.at(3), std::out_of_range);
  EXPECT_THROW(ports[3], std::out_of_range);
}

TEST_F(PortsTest, ContainsAndIndex) {
  Ports ports(*ports_ABC);
  EXPECT_TRUE(ports.contains(portA));
  EXPECT_TRUE(ports.contains(portB));
  EXPECT_TRUE(ports.contains(portC));
  EXPECT_EQ(ports.index(portB), 1u);
  InstrumentPortSP dummy;
  EXPECT_THROW(ports.contains(dummy), std::invalid_argument);
  EXPECT_THROW(ports.index(dummy), std::invalid_argument);
  InstrumentPortSP portD = std::make_shared<InstrumentPort>("D");
  EXPECT_FALSE(ports.contains(portD));
  EXPECT_THROW(ports.index(portD), std::out_of_range);
}

TEST_F(PortsTest, InsertThrowsOnNullptr) {
  Ports                         ports(*ports_ABC);
  std::vector<InstrumentPortSP> vec{nullptr};
  EXPECT_THROW(ports.insert(ports.begin(), vec.begin(), vec.end()),
               std::invalid_argument);
}

TEST_F(PortsTest, IntersectionThrowsOnNullptr) {
  Ports ports(*ports_ABC);
  EXPECT_THROW(ports.intersection(nullptr), std::invalid_argument);
}

TEST_F(PortsTest, IntersectionWorks) {
  Ports   ports1(*ports_ABC);
  Ports   ports2(std::vector{portB, portC});
  PortsSP result = std::make_shared<Ports>(
      ports1.intersection(std::make_shared<Ports>(ports2)));
  ASSERT_EQ(result->size(), 2u);
  EXPECT_EQ((*result)[0], portB);
  EXPECT_EQ((*result)[1], portC);
}

TEST_F(PortsTest, ClearAndEraseAt) {
  Ports ports(*ports_ABC);
  ports.erase_at(2);
  EXPECT_EQ(ports.size(), 2u);
  ports.clear();
  EXPECT_TRUE(ports.empty());
  EXPECT_THROW(ports.erase_at(0), std::out_of_range);
}

TEST_F(PortsTest, BackThrowsOnEmpty) {
  Ports ports;
  EXPECT_THROW(ports.back(), std::out_of_range);
  EXPECT_THROW(const_cast<const Ports&>(ports).back(), std::out_of_range);
}

TEST_F(PortsTest, BackReturnsLast) {
  Ports ports(*ports_ABC);
  EXPECT_EQ(ports.back(), portC);
  EXPECT_EQ(const_cast<const Ports&>(ports).back(), portC);
}

TEST_F(PortsTest, EqualityOperators) {
  Ports ports1(*ports_ABC);
  Ports ports2(*ports_ABC);
  Ports ports3(std::vector{portA});
  EXPECT_TRUE(ports1 == ports2);
  EXPECT_FALSE(ports1 != ports2);
  EXPECT_FALSE(ports1 == ports3);
  EXPECT_TRUE(ports1 != ports3);
}

TEST_F(PortsTest, SerializationRoundTrip) {
  Ports ports1(*ports_ABC);
  auto  string = ports1.to_json_string();
  auto  ports2 = Ports::from_json_string<Ports>(string);
  std::cout << ports1.to_json_string();
  std::cout << ports2->to_json_string();
  EXPECT_EQ(ports1, *ports2);
}
}  // namespace
