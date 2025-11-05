#include <gtest/gtest.h>

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
  EXPECT_THROW(Connection_create_barrier_gate(nullptr), std::invalid_argument);
  EXPECT_THROW(Connection_create_plunger_gate(nullptr), std::invalid_argument);
  EXPECT_THROW(Connection_create_reservoir_gate(nullptr),
               std::invalid_argument);
  EXPECT_THROW(Connection_create_screening_gate(nullptr),
               std::invalid_argument);
  EXPECT_THROW(Connection_create_ohmic(nullptr), std::invalid_argument);
  EXPECT_THROW(Connection_destroy(nullptr), std::invalid_argument);
}

TEST_F(ConnectionTest, Accessors) {
  StringHandle n = Connection_name(barrier);
  StringHandle t = Connection_type(barrier);
  EXPECT_STREQ(n->raw, "b");
  EXPECT_STREQ(t->raw, "BarrierGate");
  String_destroy(n);
  String_destroy(t);
  EXPECT_THROW(Connection_name(nullptr), std::invalid_argument);
  EXPECT_THROW(Connection_type(nullptr), std::invalid_argument);
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

  EXPECT_THROW(Connection_is_barrier_gate(nullptr), std::invalid_argument);
  EXPECT_THROW(Connection_is_plunger_gate(nullptr), std::invalid_argument);
  EXPECT_THROW(Connection_is_reservoir_gate(nullptr), std::invalid_argument);
  EXPECT_THROW(Connection_is_screening_gate(nullptr), std::invalid_argument);
  EXPECT_THROW(Connection_is_ohmic(nullptr), std::invalid_argument);
  EXPECT_THROW(Connection_is_gate(nullptr), std::invalid_argument);
  EXPECT_THROW(Connection_is_dot_gate(nullptr), std::invalid_argument);
}

TEST_F(ConnectionTest, EqualityAndInequality) {
  ConnectionHandle a = Connection_create_barrier_gate(String_wrap("a"));
  ConnectionHandle b = Connection_create_barrier_gate(String_wrap("b"));
  EXPECT_TRUE(Connection_not_equal(a, b));
  EXPECT_TRUE(Connection_equal(a, a));
  EXPECT_FALSE(Connection_equal(a, b));
  EXPECT_FALSE(Connection_not_equal(a, a));
  EXPECT_THROW(Connection_equal(nullptr, b), std::invalid_argument);
  EXPECT_THROW(Connection_equal(a, nullptr), std::invalid_argument);
  EXPECT_THROW(Connection_not_equal(nullptr, b), std::invalid_argument);
  EXPECT_THROW(Connection_not_equal(a, nullptr), std::invalid_argument);
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
  EXPECT_THROW(Connection_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(Connection_from_json_string(nullptr), std::invalid_argument);
}
