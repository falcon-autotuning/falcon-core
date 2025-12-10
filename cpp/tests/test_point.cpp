#include <gtest/gtest.h>

#include <cereal/archives/json.hpp>
#include <cereal/types/memory.hpp>

#include "falcon_core/math/Point.hpp"
#include "falcon_core/math/Quantity.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
namespace {
using namespace falcon_core::math;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::physics::units;
using falcon_core::generic::Map;
using falcon_core::generic::MapSP;

class PointTest : public ::testing::Test {
 protected:
  ConnectionSP connA = Connection::PlungerGate("A");
  ConnectionSP connB = Connection::PlungerGate("B");
  SymbolUnitSP volt  = SymbolUnit::Volt();
  SymbolUnitSP meter = SymbolUnit::Meter();
  QuantitySP   q1    = std::make_shared<Quantity>(1.0, volt);
  QuantitySP   q2    = std::make_shared<Quantity>(2.0, volt);

  MapSP<Connection, double> map_double =
      std::make_shared<Map<Connection, double>>();
  MapSP<Connection, Quantity> map_quantity =
      std::make_shared<Map<Connection, Quantity>>();

  void SetUp() override {
    map_double->insert(connA, 1.0);
    map_double->insert(connB, 2.0);
    map_quantity->insert(connA, q1);
    map_quantity->insert(connB, q2);
  }
};

TEST_F(PointTest, DefaultConstructor) {
  Point p;
  EXPECT_EQ(p.size(), 0u);
}

TEST_F(PointTest, DoubleMapConstructor) {
  Point p(map_double, volt);
  EXPECT_EQ(p.size(), 2u);
  EXPECT_EQ(p.unit()->symbol(), "V");
}

TEST_F(PointTest, DoubleMapConstructorNullptrThrows) {
  EXPECT_THROW(Point(nullptr, volt), std::invalid_argument);
  EXPECT_THROW(Point(map_double, nullptr), std::invalid_argument);
}

TEST_F(PointTest, QuantityMapConstructor) {
  Point p(map_quantity);
  EXPECT_EQ(p.size(), 2u);
  EXPECT_EQ(p.unit()->symbol(), "V");
}

TEST_F(PointTest, QuantityMapConstructorNullptrThrows) {
  EXPECT_THROW(Point(nullptr), std::invalid_argument);
}

TEST_F(PointTest, InsertOrAssignValid) {
  Point        p(map_double, volt);
  QuantitySP   q3    = std::make_shared<Quantity>(3.0, volt);
  ConnectionSP connC = Connection::PlungerGate("C");
  p.insert_or_assign(connC, q3);
  EXPECT_EQ(p.size(), 3u);
}

TEST_F(PointTest, InsertOrAssignNullptrThrows) {
  Point p(map_double, volt);
  EXPECT_THROW(p.insert_or_assign(nullptr, q1), std::invalid_argument);
  EXPECT_THROW(p.insert_or_assign(connA, nullptr), std::invalid_argument);
}

TEST_F(PointTest, InsertValid) {
  Point        p(map_double, volt);
  QuantitySP   q3    = std::make_shared<Quantity>(3.0, volt);
  ConnectionSP connC = Connection::PlungerGate("C");
  auto         res   = p.insert(connC, q3);
  EXPECT_TRUE(res.second);
  EXPECT_EQ(p.size(), 3u);
}

TEST_F(PointTest, InsertNullptrThrows) {
  Point p(map_double, volt);
  EXPECT_THROW(p.insert(nullptr, q1), std::invalid_argument);
  EXPECT_THROW(p.insert(connA, nullptr), std::invalid_argument);
}

TEST_F(PointTest, CoordinatesAndConnections) {
  Point p(map_double, volt);
  auto  coords = p.coordinates();
  auto  conns  = p.connections();
  EXPECT_EQ(coords->size(), 2u);
  EXPECT_EQ(conns->size(), 2u);
}

TEST_F(PointTest, ArithmeticOperators) {
  Point p1(map_double, volt);
  Point p2(map_double, volt);
  auto  sum = *p1.operator+(std::make_shared<Point>(p2));
  EXPECT_EQ(sum.size(), 2u);
  auto diff = *p1.operator-(std::make_shared<Point>(p2));
  EXPECT_EQ(diff.size(), 2u);
  auto scaled = *p1.operator*(2.0);
  EXPECT_DOUBLE_EQ(scaled.at(connA)->value(), 2.0);
  auto divided = *p1.operator/(2.0);
  EXPECT_DOUBLE_EQ(divided.at(connA)->value(), 0.5);
  auto neg = *p1.operator-();
  EXPECT_DOUBLE_EQ(neg.at(connA)->value(), -1.0);
}

TEST_F(PointTest, ArithmeticOperatorsNullptrThrows) {
  Point p(map_double, volt);
  EXPECT_THROW(p.operator+(nullptr), std::invalid_argument);
  EXPECT_THROW(p.operator-(nullptr), std::invalid_argument);
}

TEST_F(PointTest, SetUnitValid) {
  Point p(map_double, volt);
  p.set_unit(meter);
  EXPECT_EQ(p.unit()->symbol(), "m");
}

TEST_F(PointTest, SetUnitNullptrThrows) {
  Point p(map_double, volt);
  EXPECT_THROW(p.set_unit(nullptr), std::invalid_argument);
}

TEST_F(PointTest, EqualityOperators) {
  Point p1(map_double, volt);
  Point p2(map_double, volt);
  EXPECT_TRUE(p1 == p2);
  EXPECT_FALSE(p1 != p2);
}

TEST_F(PointTest, SerializationRoundTrip) {
  Point p1(map_double, volt);
  auto  string = p1.to_json_string();
  auto  p2     = Point::from_json_string<Point>(string);
  EXPECT_EQ(p1, *p2);
}

TEST_F(PointTest, AdditionWithDisjointConnections) {
  // p1: connA, connB; p2: connB, connC
  auto map1 = std::make_shared<Map<Connection, double>>();
  map1->insert(connA, 1.0);
  map1->insert(connB, 2.0);
  auto map2 = std::make_shared<Map<Connection, double>>();
  map2->insert(connB, 3.0);
  ConnectionSP connC = Connection::PlungerGate("C");
  map2->insert(connC, 4.0);

  Point p1(map1, volt);
  Point p2(map2, volt);

  auto sum = *p1.operator+(std::make_shared<Point>(p2));
  EXPECT_EQ(sum.size(), 3u);
  EXPECT_DOUBLE_EQ(sum.at(connA)->value(), 1.0);
  EXPECT_DOUBLE_EQ(sum.at(connB)->value(), 5.0);  // 2.0 + 3.0
  EXPECT_DOUBLE_EQ(sum.at(connC)->value(), 4.0);  // only in p2
}

TEST_F(PointTest, SubtractionWithDisjointConnections) {
  // p1: connA, connB; p2: connB, connC
  auto map1 = std::make_shared<Map<Connection, double>>();
  map1->insert(connA, 5.0);
  map1->insert(connB, 7.0);
  auto map2 = std::make_shared<Map<Connection, double>>();
  map2->insert(connB, 2.0);
  ConnectionSP connC = Connection::PlungerGate("C");
  map2->insert(connC, 1.0);

  Point p1(map1, volt);
  Point p2(map2, volt);

  auto diff = *p1.operator-(std::make_shared<Point>(p2));
  EXPECT_EQ(diff.size(), 3u);
  EXPECT_DOUBLE_EQ(diff.at(connA)->value(), 5.0);
  EXPECT_DOUBLE_EQ(diff.at(connB)->value(), 5.0);   // 7.0 - 2.0
  EXPECT_DOUBLE_EQ(diff.at(connC)->value(), -1.0);  // 0 - 1.0
}

TEST_F(PointTest, InsertOrAssignSetsUnitOnEmptyPoint) {
  Point p;
  EXPECT_EQ(p.size(), 0u);
  // Insert first item, should set unit
  p.insert_or_assign(connA, q1);
  EXPECT_EQ(p.size(), 1u);
  EXPECT_EQ(p.unit()->symbol(), "V");
  EXPECT_DOUBLE_EQ(p.at(connA)->value(), 1.0);
}
}  // namespace
