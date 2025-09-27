
#include <gtest/gtest.h>

#include <memory>
#include <stdexcept>

#include "falcon_core/physics/config/geometries/RightReservoirWithImplantedOhmic.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
namespace {
using namespace falcon_core::physics::config::geometries;
using namespace falcon_core::physics::device_structures;

TEST(RightReservoirWithImplantedOhmicTest, ConstructorWorks) {
  auto right_neighbor = Connection::BarrierGate("right");
  auto ohmic = std::make_shared<Connection>("ohmic", DeviceFeature::Ohmic);
  RightReservoirWithImplantedOhmic obj("rr", right_neighbor, ohmic);

  EXPECT_EQ(obj.name(), "rr");
  EXPECT_EQ(obj.left_neighbor(), right_neighbor);
  EXPECT_EQ(obj.ohmic(), ohmic);
}

TEST(RightReservoirWithImplantedOhmicTest, ThrowsOnNullRightNeighbor) {
  auto ohmic = std::make_shared<Connection>("ohmic", DeviceFeature::Ohmic);
  EXPECT_THROW(
      { RightReservoirWithImplantedOhmic obj("rr", nullptr, ohmic); },
      std::invalid_argument);
}

TEST(RightReservoirWithImplantedOhmicTest, ThrowsOnNullOhmic) {
  auto right_neighbor = Connection::BarrierGate("right");
  EXPECT_THROW(
      { RightReservoirWithImplantedOhmic obj("rr", right_neighbor, nullptr); },
      std::invalid_argument);
}

TEST(RightReservoirWithImplantedOhmicTest, SerializationRoundTrip) {
  auto right_neighbor = Connection::BarrierGate("right");
  auto ohmic = std::make_shared<Connection>("ohmic", DeviceFeature::Ohmic);
  RightReservoirWithImplantedOhmic obj("rr", right_neighbor, ohmic);

  auto json = obj.to_json_string();
  auto obj2 = RightReservoirWithImplantedOhmic::from_json_string<
      RightReservoirWithImplantedOhmic>(json);

  EXPECT_EQ(obj2->name(), "rr");
  ASSERT_NE(obj2->left_neighbor(), nullptr);
  ASSERT_NE(obj2->ohmic(), nullptr);
  EXPECT_EQ(obj2->left_neighbor()->name(), "right");
  EXPECT_EQ(obj2->ohmic()->name(), "ohmic");
}

TEST(RightReservoirWithImplantedOhmicTest, ThrowsOnNonOhmicImplantedOhmic) {
  auto right_neighbor = Connection::BarrierGate("right");
  auto not_ohmic      = Connection::BarrierGate("not_ohmic");
  ASSERT_THROW(
      RightReservoirWithImplantedOhmic obj("rr", right_neighbor, not_ohmic),
      std::invalid_argument);
}

TEST(RightReservoirWithImplantedOhmicTest, ThrowsOnNonBarrierGateLeftNeighbor) {
  auto not_barrier = Connection::PlungerGate("not_barrier");
  auto ohmic = std::make_shared<Connection>("ohmic", DeviceFeature::Ohmic);
  ASSERT_THROW(RightReservoirWithImplantedOhmic obj("rr", not_barrier, ohmic),
               std::invalid_argument);
}
}  // namespace
