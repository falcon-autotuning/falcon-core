#include <gtest/gtest.h>

#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"

class ConnectionsCAPI_Fixture : public ::testing::Test {
 protected:
  ConnectionHandle barrier, plunger, reservoir, screening, ohmic;
  void             SetUp() override {
    barrier   = Connection_create_barrier_gate("b");
    plunger   = Connection_create_plunger_gate("p");
    reservoir = Connection_create_reservoir_gate("r");
    screening = Connection_create_screening_gate("s");
    ohmic     = Connection_create_ohmic("o");
  }
  void TearDown() override {
    Connection_destroy(barrier);
    Connection_destroy(plunger);
    Connection_destroy(reservoir);
    Connection_destroy(screening);
    Connection_destroy(ohmic);
  }
};

TEST(ConnectionsCAPI_Constructors, DefaultConstructor) {
  ConnectionsHandle c = Connections_create_empty();
  EXPECT_EQ(Connections_size(c), 0);
  Connections_destroy(c);
}

TEST_F(ConnectionsCAPI_Fixture, CountValueConstructor) {
  ConnectionsHandle c = Connections_create_empty();
  Connections_push_back(c, barrier);
  Connections_push_back(c, barrier);
  EXPECT_EQ(Connections_size(c), 2);
  for (size_t i = 0; i < Connections_size(c); ++i) {
    EXPECT_TRUE(Connection_equal(Connections_at(c, i), barrier));
  }
  Connections_destroy(c);
}

TEST_F(ConnectionsCAPI_Fixture, VectorConstructor) {
  ConnectionsHandle c = Connections_create_empty();
  Connections_push_back(c, barrier);
  Connections_push_back(c, ohmic);
  EXPECT_EQ(Connections_size(c), 2);
  EXPECT_TRUE(Connection_equal(Connections_at(c, 0), barrier));
  EXPECT_TRUE(Connection_equal(Connections_at(c, 1), ohmic));
  Connections_destroy(c);
}

TEST_F(ConnectionsCAPI_Fixture, TypeChecks) {
  ConnectionsHandle gates = Connections_create_empty();
  Connections_push_back(gates, screening);
  Connections_push_back(gates, screening);
  EXPECT_TRUE(Connections_is_gates(gates));
  EXPECT_FALSE(Connections_is_dot_gates(gates));
  EXPECT_FALSE(Connections_is_reservoir_gates(gates));
  EXPECT_FALSE(Connections_is_barrier_gates(gates));
  EXPECT_FALSE(Connections_is_plunger_gates(gates));
  EXPECT_FALSE(Connections_is_ohmics(gates));
  Connections_destroy(gates);

  ConnectionsHandle ohmics = Connections_create_empty();
  Connections_push_back(ohmics, ohmic);
  Connections_push_back(ohmics, ohmic);
  EXPECT_TRUE(Connections_is_ohmics(ohmics));
  EXPECT_FALSE(Connections_is_screening_gates(ohmics));
  EXPECT_FALSE(Connections_is_gates(ohmics));
  Connections_destroy(ohmics);

  ConnectionsHandle plungers = Connections_create_empty();
  Connections_push_back(plungers, plunger);
  Connections_push_back(plungers, plunger);
  EXPECT_TRUE(Connections_is_plunger_gates(plungers));
  EXPECT_TRUE(Connections_is_dot_gates(plungers));
  Connections_destroy(plungers);

  ConnectionsHandle barriers = Connections_create_empty();
  Connections_push_back(barriers, barrier);
  Connections_push_back(barriers, barrier);
  EXPECT_TRUE(Connections_is_barrier_gates(barriers));
  Connections_destroy(barriers);

  ConnectionsHandle dotmixed = Connections_create_empty();
  Connections_push_back(dotmixed, plunger);
  Connections_push_back(dotmixed, barrier);
  EXPECT_TRUE(Connections_is_dot_gates(dotmixed));
  EXPECT_FALSE(Connections_is_plunger_gates(dotmixed));
  EXPECT_FALSE(Connections_is_barrier_gates(dotmixed));
  Connections_destroy(dotmixed);

  ConnectionsHandle reservoirs = Connections_create_empty();
  Connections_push_back(reservoirs, reservoir);
  Connections_push_back(reservoirs, reservoir);
  EXPECT_TRUE(Connections_is_reservoir_gates(reservoirs));
  Connections_destroy(reservoirs);

  ConnectionsHandle screenings = Connections_create_empty();
  Connections_push_back(screenings, screening);
  Connections_push_back(screenings, screening);
  EXPECT_TRUE(Connections_is_screening_gates(screenings));
  Connections_destroy(screenings);

  ConnectionsHandle mixed = Connections_create_empty();
  Connections_push_back(mixed, screening);
  Connections_push_back(mixed, ohmic);
  EXPECT_FALSE(Connections_is_gates(mixed));
  EXPECT_FALSE(Connections_is_ohmics(mixed));
  Connections_destroy(mixed);
}

TEST_F(ConnectionsCAPI_Fixture, Methods_PushBackEraseClearContainsIndex) {
  ConnectionsHandle c = Connections_create_empty();
  Connections_push_back(c, barrier);
  Connections_push_back(c, plunger);
  Connections_push_back(c, ohmic);
  EXPECT_EQ(Connections_size(c), 3);
  EXPECT_FALSE(Connections_empty(c));
  EXPECT_TRUE(Connections_contains(c, plunger));
  EXPECT_EQ(Connections_index(c, plunger), 1);

  Connections_erase_at(c, 1);
  EXPECT_EQ(Connections_size(c), 2);
  EXPECT_FALSE(Connections_contains(c, plunger));
  Connections_clear(c);
  EXPECT_EQ(Connections_size(c), 0);
  EXPECT_TRUE(Connections_empty(c));
  Connections_destroy(c);
}

TEST_F(ConnectionsCAPI_Fixture, Items_Buffer) {
  ConnectionsHandle c = Connections_create_empty();
  Connections_push_back(c, barrier);
  Connections_push_back(c, plunger);
  Connections_push_back(c, ohmic);

  ConnectionHandle buffer[3];
  size_t           n = Connections_items(c, buffer, 3);
  EXPECT_EQ(n, 3);
  EXPECT_TRUE(Connection_equal(buffer[0], barrier));
  EXPECT_TRUE(Connection_equal(buffer[1], plunger));
  EXPECT_TRUE(Connection_equal(buffer[2], ohmic));
  Connections_destroy(c);
}

TEST_F(ConnectionsCAPI_Fixture, EqualityAndInequality) {
  ConnectionsHandle c1 = Connections_create_empty();
  Connections_push_back(c1, barrier);
  Connections_push_back(c1, plunger);

  ConnectionsHandle c2 = Connections_create_empty();
  Connections_push_back(c2, barrier);
  Connections_push_back(c2, plunger);

  ConnectionsHandle c3 = Connections_create_empty();
  Connections_push_back(c3, barrier);

  EXPECT_TRUE(Connections_equal(c1, c2));
  EXPECT_TRUE(Connections_not_equal(c1, c3));
  Connections_destroy(c1);
  Connections_destroy(c2);
  Connections_destroy(c3);
}

TEST_F(ConnectionsCAPI_Fixture, SerializationRoundTrip) {
  ConnectionsHandle c = Connections_create_empty();
  Connections_push_back(c, plunger);
  Connections_push_back(c, ohmic);

  const char*       json = Connections_to_json_string(c);
  ConnectionsHandle c2   = Connections_from_json_string(json);

  EXPECT_EQ(Connections_size(c2), 2);
  EXPECT_STREQ(Connection_name(Connections_at(c2, 0)), "p");
  EXPECT_STREQ(Connection_name(Connections_at(c2, 1)), "o");
  EXPECT_TRUE(Connections_equal(c, c2));

  Connections_destroy(c);
  Connections_destroy(c2);
}

TEST_F(ConnectionsCAPI_Fixture, IntersectionThrowsOnNullptr) {
  ConnectionsHandle c1 = Connections_create_empty();
  Connections_push_back(c1, barrier);
  ConnectionsHandle null_ptr = NULL;
  EXPECT_THROW(Connections_intersection(c1, null_ptr), std::invalid_argument);
  Connections_destroy(c1);
}

TEST_F(ConnectionsCAPI_Fixture, IntersectionNormalCase) {
  ConnectionHandle  a  = Connection_create_barrier_gate("a");
  ConnectionHandle  b  = Connection_create_barrier_gate("b");
  ConnectionsHandle c1 = Connections_create_empty();
  Connections_push_back(c1, a);
  Connections_push_back(c1, b);

  ConnectionsHandle c2 = Connections_create_empty();
  Connections_push_back(c2, a);

  ConnectionsHandle result = Connections_intersection(c1, c2);
  ASSERT_NE(result, nullptr);
  ASSERT_EQ(Connections_size(result), 1);
  EXPECT_TRUE(Connection_equal(Connections_at(result, 0), a));

  Connection_destroy(a);
  Connection_destroy(b);
  Connections_destroy(c1);
  Connections_destroy(c2);
  Connections_destroy(result);
}
