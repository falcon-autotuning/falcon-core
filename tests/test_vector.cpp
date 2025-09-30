#include <gtest/gtest.h>

#include "falcon_core/generic/Map.hpp"
#include "falcon_core/math/Vector.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace tests {
using namespace falcon_core::math;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::physics::units;
using namespace falcon_core::generic;

TEST(VectorTest, SerializationRoundTrip) {
  auto unit  = SymbolUnit::Volt();
  auto conn1 = Connection::BarrierGate("A");
  auto conn2 = Connection::BarrierGate("B");

  Map<Connection, double> end(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 1.0}, {conn2, 2.0}});
  Map<Connection, double> start(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 0.0}, {conn2, 1.0}});

  auto vec =
      std::make_shared<Vector>(std::make_shared<Map<Connection, double>>(end),
                               std::make_shared<Map<Connection, double>>(start),
                               unit);
  auto string = vec->to_json_string();
  auto vec2   = Vector::from_json_string<Vector>(string);
  ASSERT_EQ(*vec, *vec2);
}

TEST(VectorTest, ArithmeticOperators) {
  auto unit  = SymbolUnit::Volt();
  auto conn1 = std::make_shared<Connection>("A", DeviceFeature::BarrierGate);
  auto conn2 = std::make_shared<Connection>("B", DeviceFeature::BarrierGate);

  Map<Connection, double> end1(
      std::vector<std::pair<std::shared_ptr<Connection>, double>>{
          {conn1, 1.0}, {conn2, 2.0}});
  Map<Connection, double> start1(
      std::vector<std::pair<std::shared_ptr<Connection>, double>>{
          {conn1, 0.0}, {conn2, 1.0}});
  Map<Connection, double> end2(
      std::vector<std::pair<std::shared_ptr<Connection>, double>>{
          {conn1, 3.0}, {conn2, 4.0}});
  Map<Connection, double> start2(
      std::vector<std::pair<std::shared_ptr<Connection>, double>>{
          {conn1, 1.0}, {conn2, 2.0}});

  auto v1 = std::make_shared<Vector>(
      std::make_shared<Map<Connection, double>>(end1),
      std::make_shared<Map<Connection, double>>(start1),
      unit);
  auto v2 = std::make_shared<Vector>(
      std::make_shared<Map<Connection, double>>(end2),
      std::make_shared<Map<Connection, double>>(start2),
      unit);

  auto v_add = *v1 + *v2;
  EXPECT_DOUBLE_EQ((*v_add->endPoint())[conn1] -> value(), 4.0);
  EXPECT_DOUBLE_EQ((*v_add->endPoint())[conn2] -> value(), 6.0);
  EXPECT_DOUBLE_EQ((*v_add->startPoint())[conn1] -> value(), 1.0);
  EXPECT_DOUBLE_EQ((*v_add->startPoint())[conn2] -> value(), 3.0);

  auto v_sub = *v1 - *v2;
  EXPECT_DOUBLE_EQ((*v_sub->endPoint())[conn1] -> value(), -2.0);
  EXPECT_DOUBLE_EQ((*v_sub->endPoint())[conn2] -> value(), -2.0);
  EXPECT_DOUBLE_EQ((*v_sub->startPoint())[conn1] -> value(), -1.0);
  EXPECT_DOUBLE_EQ((*v_sub->startPoint())[conn2] -> value(), -1.0);

  auto v_mul = *v1 * 2.0;
  EXPECT_DOUBLE_EQ((*v_mul->endPoint())[conn1] -> value(), 2.0);
  EXPECT_DOUBLE_EQ((*v_mul->endPoint())[conn2] -> value(), 4.0);
  EXPECT_DOUBLE_EQ((*v_mul->startPoint())[conn1] -> value(), 0.0);
  EXPECT_DOUBLE_EQ((*v_mul->startPoint())[conn2] -> value(), 2.0);

  auto v_div = *v1 / 2.0;
  EXPECT_DOUBLE_EQ((*v_div->endPoint())[conn1] -> value(), 0.5);
  EXPECT_DOUBLE_EQ((*v_div->endPoint())[conn2] -> value(), 1.0);
  EXPECT_DOUBLE_EQ((*v_div->startPoint())[conn1] -> value(), 0.0);
  EXPECT_DOUBLE_EQ((*v_div->startPoint())[conn2] -> value(), 0.5);

  auto v_neg = -(*v1);
  EXPECT_DOUBLE_EQ((*v_neg->endPoint())[conn1] -> value(), -1.0);
  EXPECT_DOUBLE_EQ((*v_neg->endPoint())[conn2] -> value(), -2.0);
  EXPECT_DOUBLE_EQ((*v_neg->startPoint())[conn1] -> value(), -0.0);
  EXPECT_DOUBLE_EQ((*v_neg->startPoint())[conn2] -> value(), -1.0);
}

TEST(VectorTest, MagnitudeAndIndexing) {
  auto unit  = SymbolUnit::Volt();
  auto conn1 = Connection::BarrierGate("A");
  auto conn2 = Connection::BarrierGate("B");

  auto end = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<std::shared_ptr<Connection>, double>>{
          {conn1, 3.0}, {conn2, 4.0}});
  auto start = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<std::shared_ptr<Connection>, double>>{
          {conn1, 0.0}, {conn2, 0.0}});

  auto vec = std::make_shared<Vector>(end, start, unit);

  EXPECT_DOUBLE_EQ(vec->magnitude(), 5.0);

  auto pair = (*vec)[conn1];
  EXPECT_DOUBLE_EQ(pair->first()->value(), 3.0);
  EXPECT_DOUBLE_EQ(pair->second()->value(), 0.0);

  pair = (*vec)[conn2];
  EXPECT_DOUBLE_EQ(pair->first()->value(), 4.0);
  EXPECT_DOUBLE_EQ(pair->second()->value(), 0.0);
}

TEST(VectorTest, UnitConversion) {
  auto unit1 = SymbolUnit::Volt();
  auto unit2 = SymbolUnit::Volt();
  auto conn1 = Connection::BarrierGate("A");

  auto end = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<std::shared_ptr<Connection>, double>>{
          {conn1, 1.0}});
  auto start = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<std::shared_ptr<Connection>, double>>{
          {conn1, 0.0}});

  auto vec = std::make_shared<Vector>(end, start, unit1);
  vec->update_unit(unit2);

  ASSERT_EQ(vec->unit(), unit2);
  ASSERT_EQ(vec->endPoint()->unit(), unit2);
  ASSERT_EQ(vec->startPoint()->unit(), unit2);
}
}  // namespace tests
