#include <gtest/gtest.h>

#include "falcon_core/physics/device_structures/Connection_c_api.h"

// Fixture for Connection creation/destruction
class ConnectionCAPI_Fixture : public ::testing::Test {
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

TEST(ConnectionCAPI_Constructors, ConstructorsAndAccessors) {
  ConnectionHandle c2 = Connection_create_barrier_gate(String_wrap("foo"));
  EXPECT_STREQ(Connection_name(c2)->raw, "foo");
  EXPECT_STREQ(Connection_type(c2)->raw, "BarrierGate");
  ConnectionHandle c3 = Connection_create_ohmic(String_wrap("bar"));
  EXPECT_STREQ(Connection_name(c3)->raw, "bar");
  EXPECT_STREQ(Connection_type(c3)->raw, "Ohmic");
  Connection_destroy(c2);
  Connection_destroy(c3);
}

TEST_F(ConnectionCAPI_Fixture, StaticFactories_NamesAndTypes) {
  EXPECT_STREQ(Connection_name(barrier)->raw, "b");
  EXPECT_STREQ(Connection_type(barrier)->raw, "BarrierGate");
  EXPECT_STREQ(Connection_name(plunger)->raw, "p");
  EXPECT_STREQ(Connection_type(plunger)->raw, "PlungerGate");
  EXPECT_STREQ(Connection_name(reservoir)->raw, "r");
  EXPECT_STREQ(Connection_type(reservoir)->raw, "ReservoirGate");
  EXPECT_STREQ(Connection_name(screening)->raw, "s");
  EXPECT_STREQ(Connection_type(screening)->raw, "ScreeningGate");
  EXPECT_STREQ(Connection_name(ohmic)->raw, "o");
  EXPECT_STREQ(Connection_type(ohmic)->raw, "Ohmic");
}

TEST_F(ConnectionCAPI_Fixture, StaticFactories_FeatureChecks) {
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
}

TEST(ConnectionCAPI_Comparison, EqualityAndInequality) {
  ConnectionHandle a = Connection_create_barrier_gate(String_wrap("a"));
  ConnectionHandle b = Connection_create_barrier_gate(String_wrap("b"));
  EXPECT_TRUE(Connection_not_equal(a, b));
  EXPECT_TRUE(Connection_equal(a, a));
  Connection_destroy(a);
  Connection_destroy(b);
}

TEST(ConnectionCAPI_Serialization, SerializationRoundTrip) {
  ConnectionHandle c    = Connection_create_screening_gate(String_wrap("foo"));
  StringHandle     json = Connection_to_json_string(c);
  ConnectionHandle c2   = Connection_from_json_string(json);
  EXPECT_STREQ(Connection_name(c2)->raw, "foo");
  EXPECT_STREQ(Connection_type(c2)->raw, "ScreeningGate");
  EXPECT_TRUE(Connection_is_screening_gate(c2));
  Connection_destroy(c);
  Connection_destroy(c2);
}
