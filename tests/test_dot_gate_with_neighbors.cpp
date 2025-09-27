#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace {
using namespace falcon_core::physics::config::geometries;
using namespace falcon_core::physics::device_structures;

TEST(DotGateWithNeighborsTest, ConstructorWithValidNeighbors) {
  auto                 left  = Connection::PlungerGate("left");
  auto                 right = Connection::PlungerGate("right");
  DotGateWithNeighbors gate("center", DeviceFeature::PlungerGate, left, right);
  EXPECT_EQ(gate.name(), "center");
  EXPECT_EQ(gate.left_neighbor(), left);
  EXPECT_EQ(gate.right_neighbor(), right);
}

TEST(DotGateWithNeighborsTest, ConstructorWithNullLeftNeighborThrows) {
  auto right = Connection::PlungerGate("right");
  EXPECT_THROW(
      {
        DotGateWithNeighbors gate(
            "center", DeviceFeature::PlungerGate, nullptr, right);
      },
      std::invalid_argument);
}

TEST(DotGateWithNeighborsTest, ConstructorWithNullRightNeighborThrows) {
  auto left = Connection::PlungerGate("left");
  EXPECT_THROW(
      {
        DotGateWithNeighbors gate(
            "center", DeviceFeature::PlungerGate, left, nullptr);
      },
      std::invalid_argument);
}

TEST(DotGateWithNeighborsTest, SerializationRoundTripJson) {
  auto                 left  = Connection::PlungerGate("left");
  auto                 right = Connection::PlungerGate("right");
  DotGateWithNeighbors gate("center", DeviceFeature::PlungerGate, left, right);
  auto                 string = gate.to_json_string();
  auto                 loaded =
      DotGateWithNeighbors::from_json_string<DotGateWithNeighbors>(string);
  EXPECT_EQ(loaded->name(), "center");
  EXPECT_EQ(loaded->left_neighbor()->name(), "left");
  EXPECT_EQ(loaded->right_neighbor()->name(), "right");
}

TEST(DotGateWithNeighborsTest, ConstructorWithNonDotGateThrows) {
  auto left  = Connection::PlungerGate("left");
  auto right = Connection::PlungerGate("right");
  // Use a DeviceFeature that is NOT a dot gate (replace with an actual non-dot
  // feature from your enum)
  EXPECT_THROW(
      {
        DotGateWithNeighbors gate(
            "center", DeviceFeature::ReservoirGate, left, right);
      },
      std::invalid_argument);
}

}  // namespace
