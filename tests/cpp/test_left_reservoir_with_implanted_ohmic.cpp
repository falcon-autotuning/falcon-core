#include <gtest/gtest.h>

#include "falcon-core/physics/config/geometries/LeftReservoirWithImplantedOhmic.hpp"
#include "falcon-core/physics/device_structures/Connection.hpp"
namespace {
using namespace falcon_core;
using namespace physics;
using namespace falcon_core::physics::config::geometries;

TEST(LeftReservoirWithImplantedOhmicTest, SerializationRoundTrip) {
  auto right = device_structures::Connection::BarrierGate("right");
  auto ohmic = device_structures::Connection::Ohmic("ohmic");
  LeftReservoirWithImplantedOhmic orig("left", right, ohmic);
  auto                            string = orig.to_json_string();
  auto copy = LeftReservoirWithImplantedOhmic::from_json_string<
      LeftReservoirWithImplantedOhmic>(string);

  EXPECT_EQ(orig.name(), copy->name());
  // Add more checks as needed
}

TEST(LeftReservoirWithImplantedOhmicTest, ThrowsOnNullRightNeighbor) {
  auto ohmic = device_structures::Connection::Ohmic("ohmic");
  EXPECT_THROW(LeftReservoirWithImplantedOhmic("left", nullptr, ohmic),
               std::invalid_argument);
}

TEST(LeftReservoirWithImplantedOhmicTest, ThrowsOnNullOhmic) {
  auto right = device_structures::Connection::BarrierGate("right");
  EXPECT_THROW(LeftReservoirWithImplantedOhmic("left", right, nullptr),
               std::invalid_argument);
}

TEST(LeftReservoirWithImplantedOhmicTest, ThrowsOnNonOhmicAsOhmic) {
  auto right     = device_structures::Connection::BarrierGate("right");
  auto not_ohmic = device_structures::Connection::BarrierGate("ohmic");
  EXPECT_THROW(LeftReservoirWithImplantedOhmic("left", right, not_ohmic),
               std::runtime_error);
}

TEST(LeftReservoirWithImplantedOhmicTest,
     ThrowsOnNonBarrierGateAsRightNeighbor) {
  auto not_right = device_structures::Connection::ScreeningGate("right");
  auto ohmic     = device_structures::Connection::Ohmic("ohmic");
  EXPECT_THROW(LeftReservoirWithImplantedOhmic("left", not_right, ohmic),
               std::runtime_error);
}
}  // namespace
