#include <gtest/gtest.h>

#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/device_structures/Impedance_c_api.h"

TEST(ImpedanceCAPI_Constructors, ValueConstructor) {
  ConnectionHandle conn = Connection_create_plunger_gate("foo");
  ImpedanceHandle  imp  = Impedance_create(conn, 42.5, 3.14);
  EXPECT_TRUE(Connection_equal(Impedance_connection(imp), conn));
  EXPECT_DOUBLE_EQ(Impedance_resistance(imp), 42.5);
  EXPECT_DOUBLE_EQ(Impedance_capacitance(imp), 3.14);
  Impedance_destroy(imp);
  Connection_destroy(conn);
}

TEST(ImpedanceCAPI_Constructors, NullConnectionThrows) {
  EXPECT_ANY_THROW(Impedance_create(nullptr, 1.0, 2.0));
}

TEST(ImpedanceCAPI_Serialization, SerializationRoundTrip) {
  ConnectionHandle conn = Connection_create_ohmic("bar");
  ImpedanceHandle  imp  = Impedance_create(conn, 10.0, 5.0);
  const char*      json = Impedance_to_json_string(imp);
  ImpedanceHandle  imp2 = Impedance_from_json_string(json);
  EXPECT_TRUE(Impedance_equal(imp, imp2));
  EXPECT_DOUBLE_EQ(Impedance_resistance(imp2), 10.0);
  EXPECT_DOUBLE_EQ(Impedance_capacitance(imp2), 5.0);
  EXPECT_STREQ(Connection_name(Impedance_connection(imp2)), "bar");
  Impedance_destroy(imp);
  Impedance_destroy(imp2);
  Connection_destroy(conn);
}

TEST(ImpedanceCAPI_Comparison, EqualityAndInequality) {
  ConnectionHandle conn1 = Connection_create_plunger_gate("foo");
  ImpedanceHandle  imp1  = Impedance_create(conn1, 42.5, 3.14);

  ConnectionHandle conn2 = Connection_create_plunger_gate("boo");
  ImpedanceHandle  imp2  = Impedance_create(conn2, 42.5, 3.12);

  EXPECT_TRUE(Impedance_equal(imp1, imp1));
  EXPECT_TRUE(Impedance_not_equal(imp1, imp2));

  Impedance_destroy(imp1);
  Impedance_destroy(imp2);
  Connection_destroy(conn1);
  Connection_destroy(conn2);
}
