#include <gtest/gtest.h>

#include <memory>

#include "falcon-core/physics/device_structures/Connection.hpp"
#include "falcon-core/physics/device_structures/Impedance.hpp"
namespace {
using namespace falcon_core::physics::device_structures;

TEST(ImpedanceTest, ValueConstructor) {
  auto      conn = Connection::PlungerGate("foo");
  Impedance imp(conn, 42.5, 3.14);
  EXPECT_EQ(imp.connection(), conn);
  EXPECT_DOUBLE_EQ(imp.resistance(), 42.5);
  EXPECT_DOUBLE_EQ(imp.capacitance(), 3.14);
}

TEST(ImpedanceTest, CreateConstructor) {
  auto conn = Connection::PlungerGate("foo");
  // Impedance imp(conn, 42.5, 3.14);
  auto imp{Impedance::create(conn, 42.5, 3.14)};
  EXPECT_EQ(imp->connection(), conn);
  EXPECT_DOUBLE_EQ(imp->resistance(), 42.5);
  EXPECT_DOUBLE_EQ(imp->capacitance(), 3.14);
}

TEST(ImpedanceTest, NullConnectionThrows) {
  EXPECT_THROW({ Impedance imp(nullptr, 1.0, 2.0); }, std::invalid_argument);
}

TEST(ImpedanceTest, SerializationRoundTrip) {
  auto      conn = Connection::Ohmic("bar");
  Impedance imp(conn, 10.0, 5.0);
  auto      json = imp.to_json_string();
  auto      imp2 = Impedance::from_json_string<Impedance>(json);
  ASSERT_EQ(*imp2, imp);
}

TEST(ImpedanceTest, Equality) {
  auto      conn = Connection::PlungerGate("foo");
  Impedance imp(conn, 42.5, 3.14);
  auto      conn2 = Connection::PlungerGate("boo");
  Impedance imp2(conn2, 42.5, 3.12);
  ASSERT_EQ(imp, imp);
  ASSERT_NE(imp, imp2);
}
}  // namespace
