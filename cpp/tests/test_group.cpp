#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon_core/autotuner_interfaces/names/Channel.hpp"
#include "falcon_core/physics/config/core/Group.hpp"
#include "falcon_core/physics/config/geometries/GateGeometryArray1D.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"

namespace {
using namespace falcon_core::physics::config::core;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::autotuner_interfaces::names;
using namespace falcon_core::physics::config::geometries;

struct GroupTest : public ::testing::Test {
 protected:
  ChannelSP     channel;
  int           num_dots;
  ConnectionsSP screening;
  ConnectionsSP reservoir;
  ConnectionsSP plunger;
  ConnectionsSP barrier;
  ConnectionsSP order;

  GroupTest() {
    channel   = std::make_shared<Channel>("test");
    num_dots  = 2;
    screening = std::make_shared<Connections>(std::vector<ConnectionSP>{
        Connection::ScreeningGate("s1"), Connection::ScreeningGate("s2")});
    reservoir = std::make_shared<Connections>(std::vector<ConnectionSP>{
        Connection::ReservoirGate("R1"), Connection::ReservoirGate("R2")});
    plunger   = std::make_shared<Connections>(
        std::vector<ConnectionSP>{Connection::PlungerGate("P1")});
    barrier = std::make_shared<Connections>(std::vector<ConnectionSP>{
        Connection::BarrierGate("B1"), Connection::BarrierGate("B2")});
    // Ordered linear array: Ohmic, Reservoir, Barrier, Plunger, Barrier,
    // Reservoir, Ohmic
    order = std::make_shared<Connections>();
    order->push_back(Connection::Ohmic("O1"));
    order->push_back(Connection::ReservoirGate("R1"));
    order->push_back(Connection::BarrierGate("B1"));
    order->push_back(Connection::PlungerGate("P1"));
    order->push_back(Connection::BarrierGate("B2"));
    order->push_back(Connection::ReservoirGate("R2"));
    order->push_back(Connection::Ohmic("O2"));
  }
};

TEST_F(GroupTest, FullConstructorAndGetters) {
  Group g(channel, num_dots, screening, reservoir, plunger, barrier, order);
  EXPECT_EQ(g.name(), channel);
  EXPECT_EQ(g.num_dots(), num_dots);
  EXPECT_NE(*g.ohmics(), Connections());
}

TEST_F(GroupTest, NullChannelThrows) {
  EXPECT_THROW(
      Group(nullptr, num_dots, screening, reservoir, plunger, barrier, order),
      std::invalid_argument);
}

TEST_F(GroupTest, NullScreeningThrows) {
  EXPECT_THROW(
      Group(channel, num_dots, nullptr, reservoir, plunger, barrier, order),
      std::invalid_argument);
}

TEST_F(GroupTest, NullReservoirThrows) {
  EXPECT_THROW(
      Group(channel, num_dots, screening, nullptr, plunger, barrier, order),
      std::invalid_argument);
}

TEST_F(GroupTest, NullPlungerThrows) {
  EXPECT_THROW(
      Group(channel, num_dots, screening, reservoir, nullptr, barrier, order),
      std::invalid_argument);
}

TEST_F(GroupTest, NullBarrierThrows) {
  EXPECT_THROW(
      Group(channel, num_dots, screening, reservoir, plunger, nullptr, order),
      std::invalid_argument);
}

TEST_F(GroupTest, NullOrderThrows) {
  EXPECT_THROW(
      Group(channel, num_dots, screening, reservoir, plunger, barrier, nullptr),
      std::invalid_argument);
}

TEST_F(GroupTest, HasChannel) {
  Group g(channel, num_dots, screening, reservoir, plunger, barrier, order);
  auto  other = std::make_shared<Channel>("other");
  EXPECT_TRUE(g.has_channel(channel));
  EXPECT_FALSE(g.has_channel(other));
  EXPECT_THROW(g.has_channel(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, IsChargeSensor) {
  Group g(channel, 1, screening, reservoir, plunger, barrier, order);
  EXPECT_TRUE(g.is_charge_sensor());
  Group g2(channel, 2, screening, reservoir, plunger, barrier, order);
  EXPECT_FALSE(g2.is_charge_sensor());
}

TEST_F(GroupTest, GetAllChannelGates) {
  Group g(channel, num_dots, screening, reservoir, plunger, barrier, order);
  auto  gates = g.get_all_channel_gates(channel);
  ASSERT_NE(gates, nullptr);
  EXPECT_GT(gates->size(), 0);

  auto empty = g.get_all_channel_gates(std::make_shared<Channel>("other"));
  EXPECT_NE(empty, nullptr);
  EXPECT_EQ(empty->size(), 0);

  EXPECT_THROW(g.get_all_channel_gates(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, SerializationRoundTrip) {
  Group g(channel, num_dots, screening, reservoir, plunger, barrier, order);
  std::stringstream ss;
  auto              string = g.to_json_string();
  auto              g2     = Group::from_json_string<Group>(string);
  EXPECT_EQ(g2->num_dots(), num_dots);
  ASSERT_NE(g2->name(), nullptr);
  EXPECT_EQ(g2->name()->name(), "test");
  ASSERT_NE(g2->order(), nullptr);
  EXPECT_EQ(g2->order()->lineararray()->size(), 7);
  EXPECT_EQ(*g2, g);
}
}  // namespace
