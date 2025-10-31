#include <gtest/gtest.h>

#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/ListDotGateWithNeighbors_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"
#include "falcon_core/physics/config/geometries/DotGateWithNeighbors_c_api.h"
#include "falcon_core/physics/config/geometries/DotGatesWithNeighbors_c_api.h"
#include "falcon_core/physics/device_structures/Connection.hpp"

using namespace falcon_core::physics::device_structures;

class DotGatesWithNeighborsTest : public ::testing::Test {
 protected:
  DotGateWithNeighborsHandle     gate1;
  DotGateWithNeighborsHandle     gate2;
  ListDotGateWithNeighborsHandle list;
  DotGatesWithNeighborsHandle    gates;

  void SetUp() override {
    StringHandle     name = String_create("g", 1);
    ConnectionHandle b1   = new Connection(*Connection::BarrierGate("b1"));
    ConnectionHandle b2   = new Connection(*Connection::BarrierGate("b2"));
    ConnectionHandle b3   = new Connection(*Connection::BarrierGate("b3"));

    gate1 = DotGateWithNeighbors_create_plungergatewithneighbors(name, b1, b2);
    gate2 = DotGateWithNeighbors_create_plungergatewithneighbors(name, b3, b2);

    list = new falcon_core::generic::List<
        falcon_core::physics::config::geometries::DotGateWithNeighbors>();
    ListDotGateWithNeighbors_push_back(list, gate1);
    ListDotGateWithNeighbors_push_back(list, gate2);

    gates = DotGatesWithNeighbors_create(list);

    // Clean up handles not owned by the fixture
    delete static_cast<Connection*>(b1);
    delete static_cast<Connection*>(b2);
    delete static_cast<Connection*>(b3);
    String_destroy(name);
  }

  void TearDown() override {
    DotGateWithNeighbors_destroy(gate1);
    DotGateWithNeighbors_destroy(gate2);
    DotGatesWithNeighbors_destroy(gates);
    ListDotGateWithNeighbors_destroy(list);
  }
};

TEST_F(DotGatesWithNeighborsTest, SizeAndEmpty) {
  EXPECT_EQ(DotGatesWithNeighbors_size(gates), 2);
  EXPECT_FALSE(DotGatesWithNeighbors_empty(gates));
}

TEST_F(DotGatesWithNeighborsTest, AtAndConstAt) {
  DotGateWithNeighborsHandle g1 = DotGatesWithNeighbors_at(gates, 0);
  DotGateWithNeighborsHandle g2 = DotGatesWithNeighbors_const_at(gates, 1);
  EXPECT_TRUE(DotGateWithNeighbors_equal(g1, gate1));
  EXPECT_TRUE(DotGateWithNeighbors_equal(g2, gate2));
  DotGateWithNeighbors_destroy(g1);
  DotGateWithNeighbors_destroy(g2);
}

TEST_F(DotGatesWithNeighborsTest, Items) {
  ListDotGateWithNeighborsHandle items = DotGatesWithNeighbors_items(gates);
  EXPECT_EQ(ListDotGateWithNeighbors_size(items), 2);
  ListDotGateWithNeighbors_destroy(items);
}

TEST_F(DotGatesWithNeighborsTest, PushBackAndEraseAt) {
  DotGatesWithNeighbors_push_back(gates, gate1);
  EXPECT_EQ(DotGatesWithNeighbors_size(gates), 3);
  DotGatesWithNeighbors_erase_at(gates, 2);
  EXPECT_EQ(DotGatesWithNeighbors_size(gates), 2);
}

TEST_F(DotGatesWithNeighborsTest, Clear) {
  DotGatesWithNeighbors_clear(gates);
  EXPECT_EQ(DotGatesWithNeighbors_size(gates), 0);
  EXPECT_TRUE(DotGatesWithNeighbors_empty(gates));
}

TEST_F(DotGatesWithNeighborsTest, ContainsAndIndex) {
  EXPECT_TRUE(DotGatesWithNeighbors_contains(gates, gate1));
  EXPECT_EQ(DotGatesWithNeighbors_index(gates, gate2), 1);
}

TEST_F(DotGatesWithNeighborsTest, IsPlungerGatesTrue) {
  EXPECT_TRUE(DotGatesWithNeighbors_is_plunger_gates(gates));
  EXPECT_FALSE(DotGatesWithNeighbors_is_barrier_gates(gates));
}

TEST_F(DotGatesWithNeighborsTest, EqualityAndInequality) {
  DotGatesWithNeighborsHandle gates2 = DotGatesWithNeighbors_create(list);
  EXPECT_TRUE(DotGatesWithNeighbors_equal(gates, gates2));
  EXPECT_FALSE(DotGatesWithNeighbors_not_equal(gates, gates2));
  DotGatesWithNeighbors_destroy(gates2);
}

TEST_F(DotGatesWithNeighborsTest, Intersection) {
  DotGatesWithNeighborsHandle gates2 = DotGatesWithNeighbors_create(list);
  DotGatesWithNeighborsHandle inter =
      DotGatesWithNeighbors_intersection(gates, gates2);
  EXPECT_EQ(DotGatesWithNeighbors_size(inter), 2);
  DotGatesWithNeighbors_destroy(gates2);
  DotGatesWithNeighbors_destroy(inter);
}

TEST_F(DotGatesWithNeighborsTest, SerializationRoundTrip) {
  StringHandle json = DotGatesWithNeighbors_to_json_string(gates);
  DotGatesWithNeighborsHandle loaded =
      DotGatesWithNeighbors_from_json_string(json);
  EXPECT_TRUE(DotGatesWithNeighbors_equal(gates, loaded));
  DotGatesWithNeighbors_destroy(loaded);
  String_destroy(json);
}

TEST_F(DotGatesWithNeighborsTest, CreateEmpty) {
  DotGatesWithNeighborsHandle empty = DotGatesWithNeighbors_create_empty();
  EXPECT_EQ(DotGatesWithNeighbors_size(empty), 0);
  EXPECT_TRUE(DotGatesWithNeighbors_empty(empty));
  DotGatesWithNeighbors_destroy(empty);
}
