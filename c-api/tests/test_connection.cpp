#include <gtest/gtest.h>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"

class ConnectionTest : public ::testing::Test {
 protected:
  void SetUp() override {
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
  ConnectionHandle barrier = nullptr, plunger = nullptr, reservoir = nullptr,
                   screening = nullptr, ohmic = nullptr;
};

TEST_F(ConnectionTest, CreateDestroy) {
  auto c = Connection_create_barrier_gate(String_wrap("x"));
  Connection_destroy(c);

  set_last_error(0, nullptr);
  Connection_create_barrier_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_create_plunger_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_create_reservoir_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_create_screening_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_create_ohmic(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ConnectionTest, Accessors) {
  StringHandle n = Connection_name(barrier);
  StringHandle t = Connection_type(barrier);
  EXPECT_STREQ(n->raw, "b");
  EXPECT_STREQ(t->raw, "BarrierGate");
  String_destroy(n);
  String_destroy(t);

  set_last_error(0, nullptr);
  Connection_name(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_type(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ConnectionTest, FeatureChecks) {
  EXPECT_TRUE(Connection_is_barrier_gate(barrier));
  EXPECT_TRUE(Connection_is_dot_gate(barrier));
  EXPECT_TRUE(Connection_is_gate(barrier));
  EXPECT_FALSE(Connection_is_ohmic(barrier));
  EXPECT_TRUE(Connection_is_plunger_gate(plunger));
  EXPECT_TRUE(Connection_is_dot_gate(plunger));
  EXPECT_TRUE(Connection_is_gate(plunger));
  EXPECT_FALSE(Connection_is_ohmic(plunger));
  EXPECT_TRUE(Connection_is_reservoir_gate(reservoir));
  EXPECT_FALSE(Connection_is_dot_gate(reservoir));
  EXPECT_TRUE(Connection_is_gate(reservoir));
  EXPECT_FALSE(Connection_is_ohmic(reservoir));
  EXPECT_TRUE(Connection_is_screening_gate(screening));
  EXPECT_FALSE(Connection_is_dot_gate(screening));
  EXPECT_TRUE(Connection_is_gate(screening));
  EXPECT_FALSE(Connection_is_ohmic(screening));
  EXPECT_TRUE(Connection_is_ohmic(ohmic));
  EXPECT_FALSE(Connection_is_gate(ohmic));
  EXPECT_FALSE(Connection_is_dot_gate(ohmic));

  set_last_error(0, nullptr);
  Connection_is_barrier_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_is_plunger_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_is_reservoir_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_is_screening_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_is_ohmic(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_is_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_is_dot_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ConnectionTest, EqualityAndInEqual) {
  ConnectionHandle a = Connection_create_barrier_gate(String_wrap("a"));
  ConnectionHandle b = Connection_create_barrier_gate(String_wrap("b"));
  EXPECT_TRUE(Connection_not_equal(a, b));
  EXPECT_TRUE(Connection_equal(a, a));
  EXPECT_FALSE(Connection_equal(a, b));
  EXPECT_FALSE(Connection_not_equal(a, a));

  set_last_error(0, nullptr);
  Connection_equal(nullptr, b);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_equal(a, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_not_equal(nullptr, b);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_not_equal(a, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  Connection_destroy(a);
  Connection_destroy(b);
}

TEST_F(ConnectionTest, SerializationRoundTrip) {
  ConnectionHandle c    = Connection_create_screening_gate(String_wrap("foo"));
  StringHandle     json = Connection_to_json_string(c);
  ConnectionHandle c2   = Connection_from_json_string(json);
  EXPECT_STREQ(Connection_name(c2)->raw, "foo");
  EXPECT_STREQ(Connection_type(c2)->raw, "ScreeningGate");
  EXPECT_TRUE(Connection_is_screening_gate(c2));
  Connection_destroy(c);
  Connection_destroy(c2);
  String_destroy(json);

  set_last_error(0, nullptr);
  Connection_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Connection_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ConnectionTest, CopyConstructor) {
  ConnectionHandle copy = Connection_copy(barrier);
  EXPECT_NE(copy, nullptr);
  EXPECT_TRUE(Connection_equal(barrier, copy));
  Connection_destroy(copy);

  set_last_error(0, nullptr);
  EXPECT_EQ(Connection_copy(nullptr), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
