#include <gtest/gtest.h>

#include "falcon_core/physics/device_structures/Connection_c_api.h"

// Fixture for Connection creation/destruction
class ConnectionCAPI_Fixture : public ::testing::Test {
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

TEST(ConnectionCAPI_Constructors, ConstructorsAndAccessors) {
  ConnectionHandle c2 = Connection_create("foo", DEVICE_FEATURE_BARRIER_GATE);
  EXPECT_STREQ(Connection_get_name(c2), "foo");
  EXPECT_STREQ(Connection_get_type(c2), "BarrierGate");
  ConnectionHandle c3 = Connection_create("bar", DEVICE_FEATURE_OHMIC);
  EXPECT_STREQ(Connection_get_name(c3), "bar");
  EXPECT_STREQ(Connection_get_type(c3), "Ohmic");
  Connection_destroy(c2);
  Connection_destroy(c3);
}

TEST_F(ConnectionCAPI_Fixture, StaticFactories_NamesAndTypes) {
  EXPECT_STREQ(Connection_get_name(barrier), "b");
  EXPECT_STREQ(Connection_get_type(barrier), "BarrierGate");
  EXPECT_STREQ(Connection_get_name(plunger), "p");
  EXPECT_STREQ(Connection_get_type(plunger), "PlungerGate");
  EXPECT_STREQ(Connection_get_name(reservoir), "r");
  EXPECT_STREQ(Connection_get_type(reservoir), "ReservoirGate");
  EXPECT_STREQ(Connection_get_name(screening), "s");
  EXPECT_STREQ(Connection_get_type(screening), "ScreeningGate");
  EXPECT_STREQ(Connection_get_name(ohmic), "o");
  EXPECT_STREQ(Connection_get_type(ohmic), "Ohmic");
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
  ConnectionHandle a = Connection_create("a", DEVICE_FEATURE_BARRIER_GATE);
  ConnectionHandle b = Connection_create("b", DEVICE_FEATURE_BARRIER_GATE);
  EXPECT_TRUE(Connection_not_equal(a, b));
  EXPECT_TRUE(Connection_equal(a, a));
  Connection_destroy(a);
  Connection_destroy(b);
}

TEST(ConnectionCAPI_Serialization, SerializationRoundTrip) {
  ConnectionHandle c = Connection_create("foo", DEVICE_FEATURE_SCREENING_GATE);
  const char*      json = Connection_to_json_string(c);
  ConnectionHandle c2   = Connection_from_json_string(json);
  EXPECT_STREQ(Connection_get_name(c2), "foo");
  EXPECT_STREQ(Connection_get_type(c2), "ScreeningGate");
  EXPECT_TRUE(Connection_is_screening_gate(c2));
  Connection_destroy(c);
  Connection_destroy(c2);
}
