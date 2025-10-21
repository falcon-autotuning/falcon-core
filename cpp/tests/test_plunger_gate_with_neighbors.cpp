#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon_core/physics/config/geometries/PlungerGateWithNeighbors.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace {
using namespace falcon_core::physics::config::geometries;
using namespace falcon_core::physics::device_structures;

TEST(PlungerGateWithNeighborsTest, ConstructorWithValidNeighbors) {
  auto                     left  = Connection::BarrierGate("left");
  auto                     right = Connection::BarrierGate("right");
  PlungerGateWithNeighbors gate("center", left, right);
  EXPECT_EQ(gate.name(), "center");
  EXPECT_EQ(gate.left_neighbor(), left);
  EXPECT_EQ(gate.right_neighbor(), right);
}

TEST(PlungerGateWithNeighborsTest, ConstructorWithNullLeftNeighborThrows) {
  auto right = Connection::BarrierGate("right");
  EXPECT_THROW(
      { PlungerGateWithNeighbors gate("center", nullptr, right); },
      std::invalid_argument);
}

TEST(PlungerGateWithNeighborsTest, ConstructorWithNullRightNeighborThrows) {
  auto left = Connection::BarrierGate("left");
  EXPECT_THROW(
      { PlungerGateWithNeighbors gate("center", left, nullptr); },
      std::invalid_argument);
}

TEST(PlungerGateWithNeighborsTest, ConstructorWithRightPlungerNeighborThrows) {
  auto left  = Connection::BarrierGate("left");
  auto right = Connection::PlungerGate("right");
  EXPECT_THROW(
      { PlungerGateWithNeighbors gate("center", left, right); },
      std::runtime_error);
}

TEST(PlungerGateWithNeighborsTest, ConstructorWithLeftPlungerNeighborThrows) {
  auto left  = Connection::PlungerGate("left");
  auto right = Connection::BarrierGate("right");
  EXPECT_THROW(
      { PlungerGateWithNeighbors gate("center", left, right); },
      std::runtime_error);
}

TEST(PlungerGateWithNeighborsTest, SerializationRoundTripJson) {
  auto                     left  = Connection::BarrierGate("left");
  auto                     right = Connection::BarrierGate("right");
  PlungerGateWithNeighbors gate =
      PlungerGateWithNeighbors("center", left, right);
  auto string = gate.to_json_string();
  auto loaded =
      PlungerGateWithNeighbors::from_json_string<PlungerGateWithNeighbors>(
          string);
  EXPECT_EQ(loaded->name(), "center");
  EXPECT_EQ(loaded->left_neighbor()->name(), "left");
  EXPECT_EQ(loaded->right_neighbor()->name(), "right");
}

}  // namespace
