#include <gtest/gtest.h>

#include "falcon_core/physics/config/geometries/BarrierGateWithNeighbors.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
namespace {
using namespace falcon_core;
using namespace physics;
using namespace config;
using namespace device_structures;
using namespace geometries;
TEST(BarrierGateWithNeighborsTest, Serialization) {
  auto                     left  = Connection::PlungerGate("left");
  auto                     right = Connection::PlungerGate("right");
  BarrierGateWithNeighbors gate("barrier", left, right);
  auto                     string = gate.to_json_string();
  auto                     loaded =
      BarrierGateWithNeighbors::from_json_string<BarrierGateWithNeighbors>(
          string);
  ASSERT_EQ(gate.name(), loaded->name());
  ASSERT_EQ(*gate.left_neighbor(), *loaded->left_neighbor());
  ASSERT_EQ(*gate.right_neighbor(), *loaded->right_neighbor());
}

TEST(BarrierGateWithNeighborsTest, NullptrLeftNeighborThrows) {
  auto right = Connection::PlungerGate("right");
  EXPECT_THROW(
      { BarrierGateWithNeighbors gate("barrier", nullptr, right); },
      std::invalid_argument);
}

TEST(BarrierGateWithNeighborsTest, NullptrRightNeighborThrows) {
  auto left = Connection::PlungerGate("left");
  EXPECT_THROW(
      { BarrierGateWithNeighbors gate("barrier", left, nullptr); },
      std::invalid_argument);
}

TEST(BarrierGateWithNeighborsTest, BarrierGateAsLeftNeighborThrows) {
  auto left  = Connection::BarrierGate("left_barrier");
  auto right = Connection::PlungerGate("right");
  EXPECT_THROW(
      { BarrierGateWithNeighbors gate("barrier", left, right); },
      std::invalid_argument);
}

TEST(BarrierGateWithNeighborsTest, BarrierGateAsRightNeighborThrows) {
  auto left  = Connection::PlungerGate("left");
  auto right = Connection::BarrierGate("right_barrier");
  EXPECT_THROW(
      { BarrierGateWithNeighbors gate("barrier", left, right); },
      std::invalid_argument);
}
}  // namespace
