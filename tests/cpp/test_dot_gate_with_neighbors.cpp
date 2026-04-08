#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon-core/physics/config/geometries/DotGateWithNeighbors.hpp"
#include "falcon-core/physics/device_structures/Connection.hpp"

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

TEST(DotGateWithNeighborsTest,
     BarrierConstructorWithNonReservoirPlungerNeighbor) {
  auto neighbor = Connection::BarrierGate("neighbor");
  EXPECT_THROW(
      {
        DotGateWithNeighbors::BarrierGateWithNeighbors(
            "B1", neighbor, neighbor);
      },
      std::invalid_argument);
  auto reservoir = Connection::ReservoirGate("reservoir");
  EXPECT_THROW(
      {
        DotGateWithNeighbors::BarrierGateWithNeighbors(
            "B1", reservoir, neighbor);
      },
      std::invalid_argument);
  EXPECT_THROW(
      {
        DotGateWithNeighbors::BarrierGateWithNeighbors(
            "B1", neighbor, reservoir);
      },
      std::invalid_argument);
}

TEST(DotGateWithNeighborsTest,
     PlungerConstructorWithNonReservoirBarrierNeighbor) {
  auto neighbor = Connection::PlungerGate("neighbor");
  EXPECT_THROW(
      {
        DotGateWithNeighbors::PlungerGateWithNeighbors(
            "P1", neighbor, neighbor);
      },
      std::invalid_argument);
  auto barrier = Connection::BarrierGate("reservoir");
  EXPECT_THROW(
      {
        DotGateWithNeighbors::PlungerGateWithNeighbors("P1", barrier, neighbor);
      },
      std::invalid_argument);
  EXPECT_THROW(
      {
        DotGateWithNeighbors::PlungerGateWithNeighbors("P1", neighbor, barrier);
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

TEST(DotGateWithNeighborsTest, ThrowsIfNotDotGate) {
  auto left  = Connection::PlungerGate("left");
  auto right = Connection::PlungerGate("right");
  // Use a DeviceFeature that is definitely not a dot gate
  EXPECT_THROW(
      DotGateWithNeighbors("center", DeviceFeature::ReservoirGate, left, right),
      std::invalid_argument);
}

TEST(DotGateWithNeighborsTest, EqualityOperatorTrueForIdentical) {
  auto                 left  = Connection::PlungerGate("left");
  auto                 right = Connection::PlungerGate("right");
  DotGateWithNeighbors gate1("center", DeviceFeature::PlungerGate, left, right);
  DotGateWithNeighbors gate2("center", DeviceFeature::PlungerGate, left, right);
  EXPECT_TRUE(gate1 == gate2);
  EXPECT_FALSE(gate1 != gate2);
}

TEST(DotGateWithNeighborsTest, EqualityOperatorFalseForDifferentLeft) {
  auto                 left1 = Connection::PlungerGate("left");
  auto                 left2 = Connection::PlungerGate("left2");
  auto                 right = Connection::PlungerGate("right");
  DotGateWithNeighbors gate1(
      "center", DeviceFeature::PlungerGate, left1, right);
  DotGateWithNeighbors gate2(
      "center", DeviceFeature::PlungerGate, left2, right);
  EXPECT_FALSE(gate1 == gate2);
  EXPECT_TRUE(gate1 != gate2);
}

TEST(DotGateWithNeighborsTest, EqualityOperatorFalseForDifferentRight) {
  auto                 left   = Connection::PlungerGate("left");
  auto                 right1 = Connection::PlungerGate("right");
  auto                 right2 = Connection::PlungerGate("right2");
  DotGateWithNeighbors gate1(
      "center", DeviceFeature::PlungerGate, left, right1);
  DotGateWithNeighbors gate2(
      "center", DeviceFeature::PlungerGate, left, right2);
  EXPECT_FALSE(gate1 == gate2);
  EXPECT_TRUE(gate1 != gate2);
}

}  // namespace
