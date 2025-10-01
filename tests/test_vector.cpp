#include <gtest/gtest.h>

#include "falcon_core/generic/Map.hpp"
#include "falcon_core/math/Point.hpp"
#include "falcon_core/math/Vector.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace {
using namespace falcon_core::math;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::physics::units;
using namespace falcon_core::generic;

class VectorTest : public ::testing::Test {
 protected:
  SymbolUnitSP unit = SymbolUnit::Volt();
  ConnectionSP conn1 =
      std::make_shared<Connection>("A", DeviceFeature::BarrierGate);
  ConnectionSP conn2 =
      std::make_shared<Connection>("B", DeviceFeature::BarrierGate);

  MapSP<Connection, double> start1 = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 0.0}, {conn2, 1.0}});
  MapSP<Connection, double> end1 = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 1.0}, {conn2, 2.0}});
  MapSP<Connection, double> start2 = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 1.0}, {conn2, 2.0}});
  MapSP<Connection, double> end2 = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 3.0}, {conn2, 4.0}});

  VectorSP v1;
  VectorSP v2;

  void SetUp() override {
    v1 = std::make_shared<Vector>(start1, end1, unit);
    v2 = std::make_shared<Vector>(start2, end2, unit);
  }
};

TEST_F(VectorTest, ConstructorStartEnd) {
  auto vec = std::make_shared<Vector>(start1, end1, unit);
  ASSERT_NE(vec, nullptr);
  EXPECT_EQ(*vec->startPoint(), Point(start1, unit));
  EXPECT_EQ(*vec->endPoint(), Point(end1, unit));
}

TEST_F(VectorTest, AdditionOperator) {
  auto v_add = *v1 + v2;
  EXPECT_DOUBLE_EQ((*v_add->endPoint())[conn1] -> value(), 4.0);
  EXPECT_DOUBLE_EQ((*v_add->endPoint())[conn2] -> value(), 6.0);
  EXPECT_DOUBLE_EQ((*v_add->startPoint())[conn1] -> value(), 1.0);
  EXPECT_DOUBLE_EQ((*v_add->startPoint())[conn2] -> value(), 3.0);
}

TEST_F(VectorTest, SubtractionOperator) {
  auto v_sub = *v1 - v2;
  EXPECT_DOUBLE_EQ((*v_sub->endPoint())[conn1] -> value(), -2.0);
  EXPECT_DOUBLE_EQ((*v_sub->endPoint())[conn2] -> value(), -2.0);
  EXPECT_DOUBLE_EQ((*v_sub->startPoint())[conn1] -> value(), -1.0);
  EXPECT_DOUBLE_EQ((*v_sub->startPoint())[conn2] -> value(), -1.0);
}

TEST_F(VectorTest, MultiplicationOperator) {
  auto v_mul = *v1 * 2.0;
  EXPECT_DOUBLE_EQ((*v_mul->endPoint())[conn1] -> value(), 2.0);
  EXPECT_DOUBLE_EQ((*v_mul->endPoint())[conn2] -> value(), 4.0);
  EXPECT_DOUBLE_EQ((*v_mul->startPoint())[conn1] -> value(), 0.0);
  EXPECT_DOUBLE_EQ((*v_mul->startPoint())[conn2] -> value(), 2.0);
}

TEST_F(VectorTest, DivisionOperator) {
  auto v_div = *v1 / 2.0;
  EXPECT_DOUBLE_EQ((*v_div->endPoint())[conn1] -> value(), 0.5);
  EXPECT_DOUBLE_EQ((*v_div->endPoint())[conn2] -> value(), 1.0);
  EXPECT_DOUBLE_EQ((*v_div->startPoint())[conn1] -> value(), 0.0);
  EXPECT_DOUBLE_EQ((*v_div->startPoint())[conn2] -> value(), 0.5);
}

TEST_F(VectorTest, NegationOperator) {
  auto v_neg = -(*v1);
  EXPECT_DOUBLE_EQ((*v_neg->endPoint())[conn1] -> value(), -1.0);
  EXPECT_DOUBLE_EQ((*v_neg->endPoint())[conn2] -> value(), -2.0);
  EXPECT_DOUBLE_EQ((*v_neg->startPoint())[conn1] -> value(), -0.0);
  EXPECT_DOUBLE_EQ((*v_neg->startPoint())[conn2] -> value(), -1.0);
}

TEST_F(VectorTest, MagnitudeAndIndexing) {
  auto end = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 3.0}, {conn2, 4.0}});
  auto start = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 0.0}, {conn2, 0.0}});
  auto vec = std::make_shared<Vector>(end, start, unit);
  EXPECT_DOUBLE_EQ(vec->magnitude(), 5.0);
  auto pair = (*vec)[conn1];
  EXPECT_DOUBLE_EQ(pair->first()->value(), 3.0);
  EXPECT_DOUBLE_EQ(pair->second()->value(), 0.0);
  pair = (*vec)[conn2];
  EXPECT_DOUBLE_EQ(pair->first()->value(), 4.0);
  EXPECT_DOUBLE_EQ(pair->second()->value(), 0.0);
}

TEST_F(VectorTest, UnitConversion) {
  auto unit2 = SymbolUnit::Volt();
  auto end   = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 1.0}});
  auto start = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 0.0}});
  auto vec = std::make_shared<Vector>(end, start, unit);
  vec->update_unit(unit2);
  ASSERT_EQ(*vec->unit(), *unit2);
  ASSERT_EQ(*vec->endPoint()->unit(), *unit2);
  ASSERT_EQ(*vec->startPoint()->unit(), *unit2);
}

TEST_F(VectorTest, SerializationRoundTrip) {
  Map<Connection, double> end(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 1.0}, {conn2, 2.0}});
  Map<Connection, double> start(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 0.0}, {conn2, 1.0}});
  auto vec =
      std::make_shared<Vector>(std::make_shared<Map<Connection, double>>(start),
                               std::make_shared<Map<Connection, double>>(end),
                               unit);
  auto string = vec->to_json_string();
  auto vec2   = Vector::from_json_string<Vector>(string);
  ASSERT_EQ(*vec, *vec2);
}

TEST_F(VectorTest, EndQuantities) {
  auto quantities = v1->end_quantities();
  ASSERT_EQ(quantities->size(), 2);
  EXPECT_DOUBLE_EQ(quantities->at(conn1)->value(), 1.0);
  EXPECT_DOUBLE_EQ(quantities->at(conn2)->value(), 2.0);
}

TEST_F(VectorTest, StartQuantities) {
  auto quantities = v1->start_quantities();
  ASSERT_EQ(quantities->size(), 2);
  EXPECT_DOUBLE_EQ(quantities->at(conn1)->value(), 0.0);
  EXPECT_DOUBLE_EQ(quantities->at(conn2)->value(), 1.0);
}

TEST_F(VectorTest, EndMap) {
  auto map = v1->end_map();
  ASSERT_EQ(map->size(), 2);
  EXPECT_DOUBLE_EQ(map->at(conn1), 1.0);
  EXPECT_DOUBLE_EQ(map->at(conn2), 2.0);
}

TEST_F(VectorTest, StartMap) {
  auto map = v1->start_map();
  ASSERT_EQ(map->size(), 2);
  EXPECT_DOUBLE_EQ(map->at(conn1), 0.0);
  EXPECT_DOUBLE_EQ(map->at(conn2), 1.0);
}

TEST_F(VectorTest, PrincipleConnection) {
  auto conn = v1->principle_connection();
  ASSERT_TRUE(conn == conn2 ||
              conn == conn1);  // Should be one of the connections
}

TEST_F(VectorTest, TranslateWithPoint) {
  auto point      = v1->startPoint();
  auto translated = v1->translate(point);
  ASSERT_NE(translated, nullptr);
}

TEST_F(VectorTest, TranslateWithNullPointThrows) {
  EXPECT_THROW(v1->translate(PointSP()), std::invalid_argument);
}

TEST_F(VectorTest, TranslateWithMapAndUnit) {
  auto map = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 1.0}, {conn2, 2.0}});
  auto translated = v1->translate(map, unit);
  ASSERT_NE(translated, nullptr);
}

TEST_F(VectorTest, TranslateWithNullMapOrUnitThrows) {
  auto map = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 1.0}});
  EXPECT_THROW(v1->translate(nullptr, unit), std::invalid_argument);
  EXPECT_THROW(v1->translate(map, nullptr), std::invalid_argument);
}

TEST_F(VectorTest, TranslateWithQuantityMap) {
  auto qmap = std::make_shared<Map<Connection, Quantity>>();
  qmap->insert(conn1, std::make_shared<Quantity>(1.0, unit));
  qmap->insert(conn2, std::make_shared<Quantity>(2.0, unit));
  auto translated = v1->translate(qmap);
  ASSERT_NE(translated, nullptr);
}

TEST_F(VectorTest, TranslateWithNullQuantityMapThrows) {
  EXPECT_THROW(v1->translate(std::shared_ptr<Map<Connection, Quantity>>()),
               std::invalid_argument);
}

TEST_F(VectorTest, TranslateToOrigin) {
  auto origin = v1->translate_to_origin();
  ASSERT_NE(origin, nullptr);
}

TEST_F(VectorTest, UpdateStartFromStatesThrowsOnNull) {
  EXPECT_THROW(v1->update_start_from_states(nullptr), std::invalid_argument);
}

TEST_F(VectorTest, UnitVector) {
  auto unit_vec = v1->unit_vector();
  ASSERT_NE(unit_vec, nullptr);
}

TEST_F(VectorTest, ExtendDouble) {
  auto extended = v1->extend(2.0);
  ASSERT_NE(extended, nullptr);
}

TEST_F(VectorTest, ExtendInt) {
  auto extended = v1->extend(2);
  ASSERT_NE(extended, nullptr);
}

TEST_F(VectorTest, ShrinkDouble) {
  auto shrunk = v1->shrink(2.0);
  ASSERT_NE(shrunk, nullptr);
}

TEST_F(VectorTest, ShrinkInt) {
  auto shrunk = v1->shrink(2);
  ASSERT_NE(shrunk, nullptr);
}

TEST_F(VectorTest, Normalize) {
  auto norm = v1->normalize();
  ASSERT_NE(norm, nullptr);
}

TEST_F(VectorTest, ProjectValid) {
  auto projected = v1->project(v2);
  ASSERT_NE(projected, nullptr);
}

TEST_F(VectorTest, ProjectNullThrows) {
  EXPECT_THROW(v1->project(nullptr), std::invalid_argument);
}

TEST_F(VectorTest, PrincipleConnectionSingleConnection) {
  auto single_map = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 5.0}});
  auto vec  = std::make_shared<Vector>(single_map, unit);
  auto conn = vec->principle_connection();
  ASSERT_EQ(conn, conn1);
}

TEST_F(VectorTest, PrincipleConnectionEqualValues) {
  auto equal_map = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 2.0}, {conn2, 2.0}});
  auto start_map = std::make_shared<Map<Connection, double>>(
      std::vector<std::pair<ConnectionSP, double>>{{conn1, 0.0}, {conn2, 0.0}});
  auto vec  = std::make_shared<Vector>(start_map, equal_map, unit);
  auto conn = vec->principle_connection();
  // Should be one of the connections, since both have equal values
  ASSERT_TRUE(conn == conn1 || conn == conn2);
}

TEST_F(VectorTest, PrincipleConnectionNullThrows) {
  // If connections() is empty, at(0) will throw
  auto empty_map = std::make_shared<Map<Connection, double>>();
  auto vec       = std::make_shared<Vector>(empty_map, unit);
  EXPECT_THROW(vec->principle_connection(), std::out_of_range);
}

TEST_F(VectorTest, NotEqualOperator) {
  ASSERT_TRUE(*v1 != *v2);
  ASSERT_FALSE(*v1 != *v1);
}
}  // namespace
