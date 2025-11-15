#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"
#include "falcon_core/physics/device_structures/GateRelations_c_api.h"

class GateRelationsTest : public ::testing::Test {
 protected:
  ConnectionHandle  gate1, gate2, neighbor1, neighbor2, ohmic;
  ConnectionsHandle neighbors1, neighbors2, ohmic_neighbors;
  void              SetUp() override {
    gate1 = Connection_create_barrier_gate(String_wrap("g1"));
    gate2 = Connection_create_barrier_gate(String_wrap("g2"));
    neighbor1 = Connection_create_screening_gate(String_wrap("n1"));
    neighbor2 = Connection_create_screening_gate(String_wrap("n2"));
    ohmic = Connection_create_ohmic(String_wrap("o"));

    neighbors1 = Connections_create_empty();
    Connections_push_back(neighbors1, neighbor1);

    neighbors2 = Connections_create_empty();
    Connections_push_back(neighbors2, neighbor2);

    ohmic_neighbors = Connections_create_empty();
    Connections_push_back(ohmic_neighbors, ohmic);
  }
  void TearDown() override {
    Connection_destroy(gate1);
    Connection_destroy(gate2);
    Connection_destroy(neighbor1);
    Connection_destroy(neighbor2);
    Connection_destroy(ohmic);

    Connections_destroy(neighbors1);
    Connections_destroy(neighbors2);
    Connections_destroy(ohmic_neighbors);
  }
};

TEST_F(GateRelationsTest, DefaultConstructor) {
  GateRelationsHandle gr = GateRelations_create_empty();
  EXPECT_EQ(GateRelations_size(gr), 0);
  EXPECT_TRUE(GateRelations_empty(gr));
  GateRelations_destroy(gr);
}

TEST_F(GateRelationsTest, InitConstructor) {
  ListPairConnectionConnectionsHandle init =
      ListPairConnectionConnections_create_empty();
  PairConnectionConnectionsHandle pair1 =
      PairConnectionConnections_create(gate1, neighbors1);
  PairConnectionConnectionsHandle pair2 =
      PairConnectionConnections_create(gate2, neighbors2);
  ListPairConnectionConnections_push_back(init, pair1);
  ListPairConnectionConnections_push_back(init, pair2);

  GateRelationsHandle gr = GateRelations_create(init);
  EXPECT_EQ(GateRelations_size(gr), 2);

  ConnectionsHandle conns1 = GateRelations_at(gr, gate1);
  ConnectionsHandle conns2 = GateRelations_at(gr, gate2);
  EXPECT_TRUE(Connections_not_equal(conns1, conns2));

  ListConnectionsHandle values = GateRelations_values(gr);
  ConnectionsHandle     val1   = ListConnections_at(values, 0);
  ConnectionsHandle     val2   = ListConnections_at(values, 1);
  EXPECT_STREQ(Connection_name(Connections_at(val1, 0))->raw, "n1");
  EXPECT_STREQ(Connection_name(Connections_at(val2, 0))->raw, "n2");

  ListConnections_destroy(values);
  GateRelations_destroy(gr);
  ListPairConnectionConnections_destroy(init);
}

TEST_F(GateRelationsTest, InsertOrAssign) {
  GateRelationsHandle gr = GateRelations_create_empty();
  GateRelations_insert_or_assign(gr, gate1, neighbors1);
  EXPECT_EQ(GateRelations_size(gr), 1);

  ConnectionsHandle     conns  = GateRelations_at(gr, gate1);
  ListConnectionsHandle values = GateRelations_values(gr);
  ConnectionsHandle     val    = ListConnections_at(values, 0);
  EXPECT_STREQ(Connection_name(Connections_at(val, 0))->raw, "n1");

  ListConnections_destroy(values);
  GateRelations_destroy(gr);
}

TEST_F(GateRelationsTest, Insert) {
  GateRelationsHandle gr = GateRelations_create_empty();
  GateRelations_insert(gr, gate1, neighbors1);
  EXPECT_EQ(GateRelations_size(gr), 1);

  ConnectionsHandle     conns  = GateRelations_at(gr, gate1);
  ListConnectionsHandle values = GateRelations_values(gr);
  ConnectionsHandle     val    = ListConnections_at(values, 0);
  EXPECT_STREQ(Connection_name(Connections_at(val, 0))->raw, "n1");

  ListConnections_destroy(values);
  GateRelations_destroy(gr);
}

TEST_F(GateRelationsTest, SerializationRoundTrip) {
  GateRelationsHandle gr = GateRelations_create_empty();
  GateRelations_insert_or_assign(gr, gate1, neighbors1);

  StringHandle        json = GateRelations_to_json_string(gr);
  GateRelationsHandle gr2  = GateRelations_from_json_string(json);

  EXPECT_EQ(GateRelations_size(gr2), 1);
  ConnectionsHandle     conns  = GateRelations_at(gr, gate1);
  ListConnectionsHandle values = GateRelations_values(gr2);
  ConnectionsHandle     val    = ListConnections_at(values, 0);
  EXPECT_STREQ(Connection_name(Connections_at(val, 0))->raw, "n1");

  ListConnections_destroy(values);
  GateRelations_destroy(gr);
  GateRelations_destroy(gr2);
}

TEST_F(GateRelationsTest, InsertOrAssignThrowsOnNonGateKey) {
  GateRelationsHandle gr = GateRelations_create_empty();
  // Should throw or handle error gracefully
  set_last_error(0, nullptr);
  GateRelations_insert_or_assign(gr, ohmic, neighbors1);
  EXPECT_EQ(get_last_error_code(), 1);
  GateRelations_destroy(gr);
}

TEST_F(GateRelationsTest, InsertOrAssignThrowsOnNonGatesValue) {
  GateRelationsHandle gr = GateRelations_create_empty();
  set_last_error(0, nullptr);
  GateRelations_insert_or_assign(gr, gate1, ohmic_neighbors);
  EXPECT_EQ(get_last_error_code(), 1);
  GateRelations_destroy(gr);
}

TEST_F(GateRelationsTest, InsertThrowsOnNonGateKey) {
  GateRelationsHandle gr = GateRelations_create_empty();
  set_last_error(0, nullptr);
  GateRelations_insert(gr, ohmic, neighbors1);
  EXPECT_EQ(get_last_error_code(), 1);
  GateRelations_destroy(gr);
}

TEST_F(GateRelationsTest, InsertThrowsOnNonGatesValue) {
  GateRelationsHandle gr = GateRelations_create_empty();
  set_last_error(0, nullptr);
  GateRelations_insert(gr, gate1, ohmic_neighbors);
  EXPECT_EQ(get_last_error_code(), 1);
  GateRelations_destroy(gr);
}

TEST_F(GateRelationsTest, Methods_EraseClearContainsKeysValuesItemsEquality) {
  GateRelationsHandle gr = GateRelations_create_empty();
  GateRelations_insert_or_assign(gr, gate1, neighbors1);
  GateRelations_insert_or_assign(gr, gate2, neighbors2);

  EXPECT_TRUE(GateRelations_contains(gr, gate1));
  GateRelations_erase(gr, gate1);
  EXPECT_FALSE(GateRelations_contains(gr, gate1));
  EXPECT_EQ(GateRelations_size(gr), 1);

  GateRelations_clear(gr);
  EXPECT_EQ(GateRelations_size(gr), 0);
  EXPECT_TRUE(GateRelations_empty(gr));

  // Keys, values, items
  GateRelations_insert_or_assign(gr, gate1, neighbors1);
  GateRelations_insert_or_assign(gr, gate2, neighbors2);

  ListConnectionHandle keys = GateRelations_keys(gr);
  EXPECT_EQ(ListConnection_size(keys), 2);
  ListConnection_destroy(keys);

  ListConnectionsHandle values = GateRelations_values(gr);
  EXPECT_EQ(ListConnections_size(values), 2);
  ListConnections_destroy(values);

  ListPairConnectionConnectionsHandle items = GateRelations_items(gr);
  EXPECT_EQ(ListPairConnectionConnections_size(items), 2);
  ListPairConnectionConnections_destroy(items);

  // Equality
  GateRelationsHandle gr2 = GateRelations_create_empty();
  GateRelations_insert_or_assign(gr2, gate1, neighbors1);
  GateRelations_insert_or_assign(gr2, gate2, neighbors2);

  EXPECT_TRUE(GateRelations_equal(gr, gr2));
  EXPECT_FALSE(GateRelations_not_equal(gr, gr2));

  GateRelations_destroy(gr);
  GateRelations_destroy(gr2);
}

TEST_F(GateRelationsTest, NullptrCoverage) {
  // GateRelations_create
  set_last_error(0, nullptr);
  GateRelations_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  // GateRelations_destroy
  set_last_error(0, nullptr);
  GateRelations_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  // GateRelations_insert_or_assign
  GateRelationsHandle gr = GateRelations_create_empty();
  set_last_error(0, nullptr);
  GateRelations_insert_or_assign(nullptr, gate1, neighbors1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  GateRelations_insert_or_assign(gr, nullptr, neighbors1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  GateRelations_insert_or_assign(gr, gate1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  // GateRelations_insert
  set_last_error(0, nullptr);
  GateRelations_insert(nullptr, gate1, neighbors1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  GateRelations_insert(gr, nullptr, neighbors1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  GateRelations_insert(gr, gate1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  // GateRelations_at
  set_last_error(0, nullptr);
  GateRelations_at(nullptr, gate1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  GateRelations_at(gr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  // GateRelations_erase
  set_last_error(0, nullptr);
  GateRelations_erase(nullptr, gate1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  GateRelations_erase(gr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  // GateRelations_size, empty, clear
  set_last_error(0, nullptr);
  GateRelations_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  GateRelations_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  GateRelations_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  // GateRelations_contains
  set_last_error(0, nullptr);
  GateRelations_contains(nullptr, gate1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  GateRelations_contains(gr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  // GateRelations_keys, values, items
  set_last_error(0, nullptr);
  GateRelations_keys(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  GateRelations_values(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  GateRelations_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  // GateRelations_equal, not_equal
  set_last_error(0, nullptr);
  GateRelations_equal(nullptr, gr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  GateRelations_equal(gr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  GateRelations_not_equal(nullptr, gr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  GateRelations_not_equal(gr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  // GateRelations_to_json_string, from_json_string
  set_last_error(0, nullptr);
  GateRelations_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  GateRelations_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  GateRelations_destroy(gr);
}
