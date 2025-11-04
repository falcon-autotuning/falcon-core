#include <gtest/gtest.h>

#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/device_structures/Impedance_c_api.h"

TEST(ImpedanceTest, ValueConstructor) {
  ConnectionHandle conn = Connection_create_plunger_gate(String_wrap("foo"));
  ImpedanceHandle  imp  = Impedance_create(conn, 42.5, 3.14);
  EXPECT_TRUE(Connection_equal(Impedance_connection(imp), conn));
  EXPECT_DOUBLE_EQ(Impedance_resistance(imp), 42.5);
  EXPECT_DOUBLE_EQ(Impedance_capacitance(imp), 3.14);
  Impedance_destroy(imp);
  Connection_destroy(conn);
}

TEST(ImpedanceTest, NullConnectionThrows) {
  EXPECT_ANY_THROW(Impedance_create(nullptr, 1.0, 2.0));
}

TEST(ImpedanceTest, SerializationRoundTrip) {
  ConnectionHandle conn = Connection_create_ohmic(String_wrap("bar"));
  ImpedanceHandle  imp  = Impedance_create(conn, 10.0, 5.0);
  StringHandle     json = Impedance_to_json_string(imp);
  ImpedanceHandle  imp2 = Impedance_from_json_string(json);
  EXPECT_TRUE(Impedance_equal(imp, imp2));
  EXPECT_DOUBLE_EQ(Impedance_resistance(imp2), 10.0);
  EXPECT_DOUBLE_EQ(Impedance_capacitance(imp2), 5.0);
  EXPECT_STREQ(Connection_name(Impedance_connection(imp2))->raw, "bar");
  Impedance_destroy(imp);
  Impedance_destroy(imp2);
  Connection_destroy(conn);
}

TEST(ImpedanceTest, EqualityAndInequality) {
  ConnectionHandle conn1 = Connection_create_plunger_gate(String_wrap("foo"));
  ImpedanceHandle  imp1  = Impedance_create(conn1, 42.5, 3.14);

  ConnectionHandle conn2 = Connection_create_plunger_gate(String_wrap("boo"));
  ImpedanceHandle  imp2  = Impedance_create(conn2, 42.5, 3.12);

  EXPECT_TRUE(Impedance_equal(imp1, imp1));
  EXPECT_TRUE(Impedance_not_equal(imp1, imp2));

  Impedance_destroy(imp1);
  Impedance_destroy(imp2);
  Connection_destroy(conn1);
  Connection_destroy(conn2);
}

TEST(ImpedanceTest, NullHandlesThrow) {
  ConnectionHandle conn = Connection_create_ohmic(String_wrap("baz"));
  ImpedanceHandle  imp  = Impedance_create(conn, 1.0, 1.0);

  EXPECT_THROW(Impedance_equal(nullptr, imp), std::invalid_argument);
  EXPECT_THROW(Impedance_equal(imp, nullptr), std::invalid_argument);
  EXPECT_THROW(Impedance_not_equal(nullptr, imp), std::invalid_argument);
  EXPECT_THROW(Impedance_not_equal(imp, nullptr), std::invalid_argument);
  EXPECT_THROW(Impedance_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(Impedance_from_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(Impedance_capacitance(nullptr), std::invalid_argument);
  EXPECT_THROW(Impedance_resistance(nullptr), std::invalid_argument);
  EXPECT_THROW(Impedance_connection(nullptr), std::invalid_argument);

  Impedance_destroy(imp);
  EXPECT_THROW(Impedance_destroy(nullptr), std::invalid_argument);
  Connection_destroy(conn);
}
