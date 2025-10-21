#include <gtest/gtest.h>

#include "falcon_core/physics/config/geometries/BarrierGateWithNeighbors.hpp"
#include "falcon_core/physics/config/geometries/DotGatesWithNeighbors.hpp"
#include "falcon_core/physics/config/geometries/PlungerGateWithNeighbors.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
namespace {
using namespace falcon_core;
using namespace physics;
using namespace config;
using namespace geometries;
using namespace device_structures;
TEST(DotGatesWithNeighborsTest, DefaultConstructor) {
  DotGatesWithNeighbors gates;
  EXPECT_EQ(gates.size(), 0);
}

TEST(DotGatesWithNeighborsTest, VectorConstructorValid) {
  ConnectionSP b1    = Connection::BarrierGate("b1");
  ConnectionSP b2    = Connection::BarrierGate("b2");
  ConnectionSP b3    = Connection::BarrierGate("b3");
  auto         gate1 = std::make_shared<PlungerGateWithNeighbors>("g", b1, b2);
  auto         gate2 = std::make_shared<PlungerGateWithNeighbors>("g", b3, b2);
  std::vector<DotGateWithNeighborsSP> vec{gate1, gate2};
  DotGatesWithNeighbors               gates(vec);
  EXPECT_EQ(gates.size(), 2);
  EXPECT_EQ(gates[0], gate1);
  EXPECT_EQ(gates[1], gate2);
}

TEST(DotGatesWithNeighborsTest, VectorConstructorNullptrThrows) {
  ConnectionSP b1   = Connection::BarrierGate("b1");
  ConnectionSP b2   = Connection::BarrierGate("b2");
  auto         gate = std::make_shared<PlungerGateWithNeighbors>("g", b1, b2);
  std::vector<DotGateWithNeighborsSP> vec{gate, nullptr};
  EXPECT_THROW({ DotGatesWithNeighbors gates(vec); }, std::invalid_argument);
}

TEST(DotGatesWithNeighborsTest, InitializerListConstructorValid) {
  ConnectionSP b1    = Connection::BarrierGate("b1");
  ConnectionSP b2    = Connection::BarrierGate("b2");
  ConnectionSP b3    = Connection::BarrierGate("b3");
  auto         gate1 = std::make_shared<PlungerGateWithNeighbors>("g", b1, b2);
  auto         gate2 = std::make_shared<PlungerGateWithNeighbors>("g", b3, b2);
  std::vector<DotGateWithNeighborsSP> vec{gate1, gate2};
  DotGatesWithNeighbors               gates(vec);
  EXPECT_EQ(gates.size(), 2);
  EXPECT_EQ(gates[0], gate1);
  EXPECT_EQ(gates[1], gate2);
}

TEST(DotGatesWithNeighborsTest, InitializerListConstructorNullptrThrows) {
  ConnectionSP b1    = Connection::BarrierGate("b1");
  ConnectionSP b2    = Connection::BarrierGate("b2");
  auto         gate1 = std::make_shared<PlungerGateWithNeighbors>("g", b1, b2);
  PlungerGateWithNeighborsSP          gate2;
  std::vector<DotGateWithNeighborsSP> vec{gate1, gate2};
  EXPECT_THROW((DotGatesWithNeighbors(vec)), std::invalid_argument);
}

TEST(DotGatesWithNeighborsTest, Serialization) {
  ConnectionSP b1    = Connection::BarrierGate("b1");
  ConnectionSP b2    = Connection::BarrierGate("b2");
  ConnectionSP b3    = Connection::BarrierGate("b3");
  auto         gate1 = std::make_shared<PlungerGateWithNeighbors>("g", b1, b2);
  auto         gate2 = std::make_shared<PlungerGateWithNeighbors>("g", b3, b2);
  std::vector<DotGateWithNeighborsSP> vec{gate1, gate2};
  DotGatesWithNeighbors               gates(vec);
  auto                                string = gates.to_json_string();
  auto                                loaded =
      DotGatesWithNeighbors::from_json_string<DotGatesWithNeighbors>(string);
  EXPECT_EQ(loaded->size(), 2);
}

TEST(DotGatesWithNeighborsTest, IsPlungerGatesTrue) {
  ConnectionSP b1    = Connection::BarrierGate("b1");
  ConnectionSP b2    = Connection::BarrierGate("b2");
  ConnectionSP b3    = Connection::BarrierGate("b3");
  auto         gate1 = std::make_shared<PlungerGateWithNeighbors>("g", b1, b2);
  auto         gate2 = std::make_shared<PlungerGateWithNeighbors>("g", b3, b2);
  std::vector<DotGateWithNeighborsSP> vec{gate1, gate2};
  DotGatesWithNeighbors               gates(vec);
  EXPECT_TRUE(gates.is_plunger_gates());
  EXPECT_FALSE(gates.is_barrier_gates());
}

TEST(DotGatesWithNeighborsTest, IsBarrierGatesTrue) {
  ConnectionSP b1    = Connection::PlungerGate("b1");
  ConnectionSP b2    = Connection::PlungerGate("b2");
  ConnectionSP b3    = Connection::PlungerGate("b3");
  auto         gate1 = std::make_shared<BarrierGateWithNeighbors>("g", b1, b2);
  auto         gate2 = std::make_shared<BarrierGateWithNeighbors>("g", b3, b2);
  std::vector<DotGateWithNeighborsSP> vec{gate1, gate2};
  DotGatesWithNeighbors               gates(vec);
  EXPECT_TRUE(gates.is_barrier_gates());
  EXPECT_FALSE(gates.is_plunger_gates());
}

TEST(DotGatesWithNeighborsTest, IsPlungerAndBarrierGatesMixed) {
  ConnectionSP b1    = Connection::PlungerGate("b1");
  ConnectionSP b2    = Connection::PlungerGate("b2");
  ConnectionSP b3    = Connection::BarrierGate("b3");
  ConnectionSP b4    = Connection::BarrierGate("b4");
  auto         gate1 = std::make_shared<BarrierGateWithNeighbors>("g", b1, b2);
  auto         gate2 = std::make_shared<PlungerGateWithNeighbors>("g", b3, b4);
  std::vector<DotGateWithNeighborsSP> vec{gate1, gate2};
  DotGatesWithNeighbors               gates(vec);
  EXPECT_FALSE(gates.is_plunger_gates());
  EXPECT_FALSE(gates.is_barrier_gates());
}

TEST(DotGatesWithNeighborsTest, IsPlungerAndBarrierGatesEmpty) {
  DotGatesWithNeighbors gates;
  EXPECT_TRUE(gates.is_plunger_gates());
  EXPECT_TRUE(gates.is_barrier_gates());
}

TEST(DotGatesWithNeighborsTest, EqualityDifferentSizes) {
  ConnectionSP b1    = Connection::BarrierGate("b1");
  ConnectionSP b2    = Connection::BarrierGate("b2");
  auto         gate1 = std::make_shared<PlungerGateWithNeighbors>("g", b1, b2);
  DotGatesWithNeighbors gates1({gate1});
  DotGatesWithNeighbors gates2;
  EXPECT_FALSE(gates1 == gates2);
  EXPECT_TRUE(gates1 != gates2);
}

TEST(DotGatesWithNeighborsTest, EqualityDifferentElements) {
  ConnectionSP b1    = Connection::BarrierGate("b1");
  ConnectionSP b2    = Connection::BarrierGate("b2");
  ConnectionSP b3    = Connection::BarrierGate("b3");
  auto         gate1 = std::make_shared<PlungerGateWithNeighbors>("g", b1, b2);
  auto         gate2 = std::make_shared<PlungerGateWithNeighbors>("g", b3, b2);
  DotGatesWithNeighbors gates1({gate1});
  DotGatesWithNeighbors gates2({gate2});
  EXPECT_FALSE(gates1 == gates2);
  EXPECT_TRUE(gates1 != gates2);
}

TEST(DotGatesWithNeighborsTest, InequalityFalseForEqual) {
  ConnectionSP b1    = Connection::BarrierGate("b1");
  ConnectionSP b2    = Connection::BarrierGate("b2");
  auto         gate1 = std::make_shared<PlungerGateWithNeighbors>("g", b1, b2);
  DotGatesWithNeighbors gates1({gate1});
  DotGatesWithNeighbors gates2({gate1});
  EXPECT_TRUE(gates1 == gates2);
  EXPECT_FALSE(gates1 != gates2);
}
}  // namespace
