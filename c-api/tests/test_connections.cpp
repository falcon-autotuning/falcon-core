#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"

class ConnectionsTest : public ::testing::Test {
 protected:
  ConnectionHandle barrier, plunger, reservoir, screening, ohmic;
  void             SetUp() override {
    barrier   = Connection_create_barrier_gate(String_wrap("b"));
    plunger   = Connection_create_plunger_gate(String_wrap("p"));
    reservoir = Connection_create_reservoir_gate(String_wrap("r"));
    screening = Connection_create_screening_gate(String_wrap("s"));
    ohmic     = Connection_create_ohmic(String_wrap("o"));
  }
  void TearDown() override {
    Connection_destroy(barrier);
    Connection_destroy(plunger);
    Connection_destroy(reservoir);
    Connection_destroy(screening);
    Connection_destroy(ohmic);
  }
};

TEST_F(ConnectionsTest, DefaultConstructor) {
  ConnectionsHandle c = Connections_create_empty();
  EXPECT_EQ(Connections_size(c), 0);
  Connections_destroy(c);
  set_last_error(0, nullptr);
  Connections_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ConnectionsTest, CreateNull) {
  set_last_error(0, nullptr);
  Connections_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ConnectionsTest, CountValueConstructor) {
  ConnectionsHandle c = Connections_create_empty();
  Connections_push_back(c, barrier);
  Connections_push_back(c, barrier);
  EXPECT_EQ(Connections_size(c), 2);
  for (size_t i = 0; i < Connections_size(c); ++i) {
    EXPECT_TRUE(Connection_equal(Connections_at(c, i), barrier));
  }
  Connections_destroy(c);
}

TEST_F(ConnectionsTest, VectorConstructor) {
  ConnectionsHandle c = Connections_create_empty();
  Connections_push_back(c, barrier);
  Connections_push_back(c, ohmic);
  EXPECT_EQ(Connections_size(c), 2);
  EXPECT_TRUE(Connection_equal(Connections_at(c, 0), barrier));
  EXPECT_TRUE(Connection_equal(Connections_at(c, 1), ohmic));
  Connections_destroy(c);
}

TEST_F(ConnectionsTest, TypeChecks) {
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

  // Nullptr coverage for all type checks
  set_last_error(0, nullptr);
  Connections_is_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_is_ohmics(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_is_dot_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_is_plunger_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_is_barrier_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_is_reservoir_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_is_screening_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ConnectionsTest, Methods_PushBackEraseClearContainsIndex) {
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

  // Nullptr coverage for methods
  set_last_error(0, nullptr);
  Connections_push_back(nullptr, barrier);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_push_back(c, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_contains(nullptr, plunger);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_contains(c, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_index(nullptr, plunger);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_index(c, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ConnectionsTest, Items_Buffer) {
  ConnectionsHandle c = Connections_create_empty();
  Connections_push_back(c, barrier);
  Connections_push_back(c, plunger);
  Connections_push_back(c, ohmic);
  ListConnectionHandle handle = Connections_items(c);
  EXPECT_TRUE(Connection_equal(ListConnection_at(handle, 0), barrier));
  EXPECT_TRUE(Connection_equal(ListConnection_at(handle, 1), plunger));
  EXPECT_TRUE(Connection_equal(ListConnection_at(handle, 2), ohmic));
  Connections_destroy(c);
}

TEST_F(ConnectionsTest, EqualityAndInEqual) {
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

  // Nullptr coverage for Equal
  set_last_error(0, nullptr);
  Connections_equal(nullptr, c3);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_equal(c1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_not_equal(nullptr, c3);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_not_equal(c1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ConnectionsTest, SerializationRoundTrip) {
  ConnectionsHandle c = Connections_create_empty();
  Connections_push_back(c, plunger);
  Connections_push_back(c, ohmic);
  StringHandle      json = Connections_to_json_string(c);
  ConnectionsHandle c2   = Connections_from_json_string(json);
  EXPECT_EQ(Connections_size(c2), 2);
  EXPECT_STREQ(Connection_name(Connections_at(c2, 0))->raw, "p");
  EXPECT_STREQ(Connection_name(Connections_at(c2, 1))->raw, "o");
  EXPECT_TRUE(Connections_equal(c, c2));
  Connections_destroy(c);
  Connections_destroy(c2);

  // Nullptr coverage for serialization
  set_last_error(0, nullptr);
  Connections_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ConnectionsTest, IntersectionThrowsOnNullptr) {
  ConnectionsHandle c1 = Connections_create_empty();
  Connections_push_back(c1, barrier);
  ConnectionsHandle null_ptr = NULL;
  set_last_error(0, nullptr);
  Connections_intersection(c1, null_ptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Connections_intersection(nullptr, c1);
  EXPECT_EQ(get_last_error_code(), 1);
  Connections_destroy(c1);
}

TEST_F(ConnectionsTest, IntersectionNormalCase) {
  ConnectionHandle  a  = Connection_create_barrier_gate(String_wrap("a"));
  ConnectionHandle  b  = Connection_create_barrier_gate(String_wrap("b"));
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

TEST_F(ConnectionsTest, CreateWithNullItemsThrows) {
  set_last_error(0, nullptr);
  Connections_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ConnectionsTest, CreateFromListConnectionHandle) {
  ListConnectionHandle list = ListConnection_create_empty();
  ListConnection_push_back(list, barrier);
  ListConnection_push_back(list, plunger);
  ConnectionsHandle c = Connections_create(list);
  EXPECT_EQ(Connections_size(c), 2);
  EXPECT_TRUE(Connection_equal(Connections_at(c, 0), barrier));
  EXPECT_TRUE(Connection_equal(Connections_at(c, 1), plunger));
  Connections_destroy(c);
  ListConnection_destroy(list);
}
