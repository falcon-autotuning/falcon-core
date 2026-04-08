
#include <gtest/gtest.h>

#include "falcon-core/physics/device_structures/Connection.hpp"
namespace {
using namespace falcon_core::physics::device_structures;

TEST(ConnectionTest, ConstructorsAndAccessors) {
  Connection c2("foo", DeviceFeature::BarrierGate);
  EXPECT_EQ(c2.name(), "foo");
  EXPECT_EQ(c2.type(), "BarrierGate");

  Connection c3("bar", DeviceFeature::Ohmic);
  EXPECT_EQ(c3.name(), "bar");
  EXPECT_EQ(c3.type(), "Ohmic");
}

TEST(ConnectionTest, StaticFactories) {
  auto b = Connection::BarrierGate("b");
  auto p = Connection::PlungerGate("p");
  auto r = Connection::ReservoirGate("r");
  auto s = Connection::ScreeningGate("s");
  auto o = Connection::Ohmic("o");

  EXPECT_EQ(b->name(), "b");
  EXPECT_EQ(b->type(), "BarrierGate");
  EXPECT_TRUE(b->is_barrier_gate());
  EXPECT_TRUE(b->is_dot_gate());
  EXPECT_TRUE(b->is_gate());
  EXPECT_FALSE(b->is_ohmic());

  EXPECT_EQ(p->name(), "p");
  EXPECT_EQ(p->type(), "PlungerGate");
  EXPECT_TRUE(p->is_plunger_gate());
  EXPECT_TRUE(p->is_dot_gate());
  EXPECT_TRUE(p->is_gate());
  EXPECT_FALSE(p->is_ohmic());

  EXPECT_EQ(r->name(), "r");
  EXPECT_EQ(r->type(), "ReservoirGate");
  EXPECT_TRUE(r->is_reservoir_gate());
  EXPECT_FALSE(r->is_dot_gate());
  EXPECT_TRUE(r->is_gate());
  EXPECT_FALSE(r->is_ohmic());

  EXPECT_EQ(s->name(), "s");
  EXPECT_EQ(s->type(), "ScreeningGate");
  EXPECT_TRUE(s->is_screening_gate());
  EXPECT_FALSE(s->is_dot_gate());
  EXPECT_TRUE(s->is_gate());
  EXPECT_FALSE(s->is_ohmic());

  EXPECT_EQ(o->name(), "o");
  EXPECT_EQ(o->type(), "Ohmic");
  EXPECT_TRUE(o->is_ohmic());
  EXPECT_FALSE(o->is_gate());
  EXPECT_FALSE(o->is_dot_gate());
}

TEST(ConnectionTest, OperatorLess) {
  Connection a("a", DeviceFeature::BarrierGate);
  Connection b("b", DeviceFeature::BarrierGate);
  EXPECT_TRUE(a < b);
  EXPECT_FALSE(b < a);
  EXPECT_FALSE(a < a);
}

TEST(ConnectionTest, SerializationRoundTrip) {
  Connection c("foo", DeviceFeature::ScreeningGate);
  auto       string = c.to_json_string();
  auto       c2     = Connection::from_json_string<Connection>(string);
  EXPECT_EQ(c2->name(), "foo");
  EXPECT_EQ(c2->type(), "ScreeningGate");
  EXPECT_TRUE(c2->is_screening_gate());
}

TEST(ConnectionTest, Equality) {
  Connection a("a", DeviceFeature::BarrierGate);
  Connection b("b", DeviceFeature::BarrierGate);
  EXPECT_NE(a, b);
  EXPECT_EQ(a, a);
}
}  // namespace
