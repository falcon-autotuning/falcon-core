#include <gtest/gtest.h>

#include "falcon-core/physics/config/geometries/HasLeftNeighbor.hpp"
#include "falcon-core/physics/device_structures/Connection.hpp"
namespace {
using namespace falcon_core;
using namespace physics;
using namespace config;
using namespace geometries;
using namespace device_structures;
using namespace config;
using namespace geometries;

TEST(HasLeftNeighborTest, LeftNeighborConstruction) {
  ConnectionSP b1            = Connection::BarrierGate("b1");
  auto         left_neighbor = HasLeftNeighbor(b1);
  EXPECT_EQ(left_neighbor.left_neighbor(), b1);
}

TEST(HasLeftNeighborTest, InitializerListConstructorNullptrThrows) {
  ConnectionSP b1 = Connection::BarrierGate("b1");
  // auto         left_neighbor = HasLeftNeighbor(nullptr);
  EXPECT_THROW(HasLeftNeighbor(nullptr), std::invalid_argument);
}
//
// TEST(HasLeftNeighborTest, Serialization) {
//   ConnectionSP b1 = Connection::BarrierGate("b1");
//   ConnectionSP b2 = Connection::BarrierGate("b2");
//   ConnectionSP b3 = Connection::BarrierGate("b3");
//   auto gate1      = DotGateWithNeighbors::PlungerGateWithNeighbors("g", b1,
//   b2); auto gate2      = DotGateWithNeighbors::PlungerGateWithNeighbors("g",
//   b3, b2); std::vector<DotGateWithNeighborsSP> vec{gate1, gate2};
//   HasLeftNeighbor                     gates(vec);
//   auto                                string = gates.to_json_string();
//   auto                                loaded =
//       HasLeftNeighbor::from_json_string<DotGatesWithNeighbors>(string);
//   EXPECT_EQ(loaded->size(), 2);
// }
//
// TEST(HasLeftNeighborTest, IsPlungerGatesTrue) {
//   ConnectionSP b1 = Connection::BarrierGate("b1");
//   ConnectionSP b2 = Connection::BarrierGate("b2");
//   ConnectionSP b3 = Connection::BarrierGate("b3");
//   auto gate1      = DotGateWithNeighbors::PlungerGateWithNeighbors("g", b1,
//   b2); auto gate2      = DotGateWithNeighbors::PlungerGateWithNeighbors("g",
//   b3, b2); std::vector<DotGateWithNeighborsSP> vec{gate1, gate2};
//   HasLeftNeighbor                     gates(vec);
//   EXPECT_TRUE(gates.is_plunger_gates());
//   EXPECT_FALSE(gates.is_barrier_gates());
// }
//
// TEST(HasLeftNeighborTest, IsBarrierGatesTrue) {
//   ConnectionSP b1 = Connection::PlungerGate("b1");
//   ConnectionSP b2 = Connection::PlungerGate("b2");
//   ConnectionSP b3 = Connection::PlungerGate("b3");
//   auto gate1      = DotGateWithNeighbors::BarrierGateWithNeighbors("g", b1,
//   b2); auto gate2      = DotGateWithNeighbors::BarrierGateWithNeighbors("g",
//   b3, b2); std::vector<DotGateWithNeighborsSP> vec{gate1, gate2};
//   HasLeftNeighbor                     gates(vec);
//   EXPECT_TRUE(gates.is_barrier_gates());
//   EXPECT_FALSE(gates.is_plunger_gates());
// }
//
// TEST(HasLeftNeighborTest, IsPlungerAndBarrierGatesMixed) {
//   ConnectionSP b1 = Connection::PlungerGate("b1");
//   ConnectionSP b2 = Connection::PlungerGate("b2");
//   ConnectionSP b3 = Connection::BarrierGate("b3");
//   ConnectionSP b4 = Connection::BarrierGate("b4");
//   auto gate1      = DotGateWithNeighbors::BarrierGateWithNeighbors("g", b1,
//   b2); auto gate2      = DotGateWithNeighbors::PlungerGateWithNeighbors("g",
//   b3, b4); std::vector<DotGateWithNeighborsSP> vec{gate1, gate2};
//   HasLeftNeighbor                     gates(vec);
//   EXPECT_FALSE(gates.is_plunger_gates());
//   EXPECT_FALSE(gates.is_barrier_gates());
// }
//
// TEST(HasLeftNeighborTest, IsPlungerAndBarrierGatesEmpty) {
//   HasLeftNeighbor gates;
//   EXPECT_TRUE(gates.is_plunger_gates());
//   EXPECT_TRUE(gates.is_barrier_gates());
// }
//
// TEST(HasLeftNeighborTest, EqualityDifferentSizes) {
//   ConnectionSP b1 = Connection::BarrierGate("b1");
//   ConnectionSP b2 = Connection::BarrierGate("b2");
//   auto gate1      = DotGateWithNeighbors::PlungerGateWithNeighbors("g", b1,
//   b2); HasLeftNeighbor gates1({gate1}); HasLeftNeighbor gates2;
//   EXPECT_FALSE(gates1 == gates2);
//   EXPECT_TRUE(gates1 != gates2);
// }
//
// TEST(HasLeftNeighborTest, EqualityDifferentElements) {
//   ConnectionSP b1 = Connection::BarrierGate("b1");
//   ConnectionSP b2 = Connection::BarrierGate("b2");
//   ConnectionSP b3 = Connection::BarrierGate("b3");
//   auto gate1      = DotGateWithNeighbors::PlungerGateWithNeighbors("g", b1,
//   b2); auto gate2      = DotGateWithNeighbors::PlungerGateWithNeighbors("g",
//   b3, b2); HasLeftNeighbor gates1({gate1}); HasLeftNeighbor gates2({gate2});
//   EXPECT_FALSE(gates1 == gates2);
//   EXPECT_TRUE(gates1 != gates2);
// }
//
// TEST(HasLeftNeighborTest, InEqualFalseForEqual) {
//   ConnectionSP b1 = Connection::BarrierGate("b1");
//   ConnectionSP b2 = Connection::BarrierGate("b2");
//   auto gate1      = DotGateWithNeighbors::PlungerGateWithNeighbors("g", b1,
//   b2); HasLeftNeighbor gates1({gate1}); HasLeftNeighbor gates2({gate1});
//   EXPECT_TRUE(gates1 == gates2);
//   EXPECT_FALSE(gates1 != gates2);
// }
}  // namespace
