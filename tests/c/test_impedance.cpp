#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"
#include "falcon-core/physics/device_structures/Impedance_c_api.h"

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
  set_last_error(0, nullptr);
  Impedance_create(nullptr, 1.0, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
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

TEST(ImpedanceTest, EqualityAndInEqual) {
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

  set_last_error(0, nullptr);
  Impedance_equal(nullptr, imp);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Impedance_equal(imp, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Impedance_not_equal(nullptr, imp);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Impedance_not_equal(imp, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Impedance_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Impedance_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Impedance_capacitance(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Impedance_resistance(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Impedance_connection(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  Impedance_destroy(imp);
  set_last_error(0, nullptr);
  Impedance_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Connection_destroy(conn);
}
