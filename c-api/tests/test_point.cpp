#include <gtest/gtest.h>

#include "falcon_core/math/Point_c_api.h"

class PointTest : public ::testing::Test {
 protected:
  void SetUp() override {
    conn   = Connection_create_plunger_gate(String_wrap("A"));
    unit   = SymbolUnit_create_volt();
    qty    = Quantity_create(42.0, unit);
    map_cd = MapConnectionDouble_create_empty();
    MapConnectionDouble_insert(map_cd, conn, 1.0);
    map_cq = MapConnectionQuantity_create_empty();
    MapConnectionQuantity_insert(map_cq, conn, qty);
    point = Point_create(map_cd, unit);
  }
  void TearDown() override {
    Point_destroy(point);
    Connection_destroy(conn);
    Quantity_destroy(qty);
    SymbolUnit_destroy(unit);
    MapConnectionDouble_destroy(map_cd);
    MapConnectionQuantity_destroy(map_cq);
  }
  ConnectionHandle            conn;
  QuantityHandle              qty;
  SymbolUnitHandle            unit;
  MapConnectionDoubleHandle   map_cd;
  MapConnectionQuantityHandle map_cq;
  PointHandle                 point;
};

TEST_F(PointTest, CreateEmptyDestroy) {
  auto p = Point_create_empty();
  EXPECT_TRUE(Point_empty(p));
  Point_destroy(p);
  EXPECT_THROW(Point_destroy(nullptr), std::invalid_argument);
}

TEST_F(PointTest, CreateAndCreateFromParent) {
  auto p2 = Point_create(map_cd, unit);
  Point_destroy(p2);
  EXPECT_THROW(Point_create(nullptr, unit), std::invalid_argument);
  EXPECT_THROW(Point_create(map_cd, nullptr), std::invalid_argument);

  auto p3 = Point_create_from_parent(map_cq);
  Point_destroy(p3);
  EXPECT_THROW(Point_create_from_parent(nullptr), std::invalid_argument);
}

TEST_F(PointTest, Unit) {
  auto u = Point_unit(point);
  EXPECT_NE(u, nullptr);
  EXPECT_THROW(Point_unit(nullptr), std::invalid_argument);
  SymbolUnit_destroy(u);
}

TEST_F(PointTest, InsertOrAssignInsertAtErase) {
  auto p = Point_create_empty();
  EXPECT_TRUE(Point_empty(p));
  Point_insert_or_assign(p, conn, qty);
  EXPECT_FALSE(Point_empty(p));
  EXPECT_EQ(Point_size(p), 1);
  std::cout << "Inserted or assigned quantity." << std::endl;
  Point_insert(p, conn, qty);
  std::cout << "Inserted quantity." << std::endl;
  EXPECT_EQ(Point_size(p), 1);
  auto q = Point_at(p, conn);
  EXPECT_NE(q, nullptr);
  Point_erase(p, conn);
  Point_destroy(p);
  Quantity_destroy(q);
}

TEST_F(PointTest, InsertOrAssignInsertAtEraseNullptr) {
  EXPECT_THROW(Point_insert_or_assign(nullptr, conn, qty),
               std::invalid_argument);
  EXPECT_THROW(Point_insert_or_assign(point, nullptr, qty),
               std::invalid_argument);
  EXPECT_THROW(Point_insert_or_assign(point, conn, nullptr),
               std::invalid_argument);

  EXPECT_THROW(Point_insert(nullptr, conn, qty), std::invalid_argument);
  EXPECT_THROW(Point_insert(point, nullptr, qty), std::invalid_argument);
  EXPECT_THROW(Point_insert(point, conn, nullptr), std::invalid_argument);

  EXPECT_THROW(Point_at(nullptr, conn), std::invalid_argument);
  EXPECT_THROW(Point_at(point, nullptr), std::invalid_argument);

  EXPECT_THROW(Point_erase(nullptr, conn), std::invalid_argument);
  EXPECT_THROW(Point_erase(point, nullptr), std::invalid_argument);
}

TEST_F(PointTest, SizeEmptyClear) {
  EXPECT_EQ(Point_size(point), 1);
  EXPECT_FALSE(Point_empty(point));
  Point_clear(point);
  EXPECT_TRUE(Point_empty(point));
  EXPECT_THROW(Point_size(nullptr), std::invalid_argument);
  EXPECT_THROW(Point_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(Point_clear(nullptr), std::invalid_argument);
}

TEST_F(PointTest, Contains) {
  EXPECT_TRUE(Point_contains(point, conn));
  EXPECT_FALSE(
      Point_contains(point, Connection_create_barrier_gate(String_wrap("B"))));
  EXPECT_THROW(Point_contains(nullptr, conn), std::invalid_argument);
  EXPECT_THROW(Point_contains(point, nullptr), std::invalid_argument);
}

TEST_F(PointTest, KeysValuesItemsCoordinatesConnections) {
  auto keys = Point_keys(point);
  EXPECT_EQ(ListConnection_size(keys), 1);
  ListConnection_destroy(keys);

  auto values = Point_values(point);
  EXPECT_EQ(ListQuantity_size(values), 1);
  ListQuantity_destroy(values);

  auto items = Point_items(point);
  EXPECT_EQ(ListPairConnectionQuantity_size(items), 1);
  ListPairConnectionQuantity_destroy(items);

  auto coords = Point_coordinates(point);
  EXPECT_EQ(MapConnectionQuantity_size(coords), 1);
  MapConnectionQuantity_destroy(coords);

  auto conns = Point_connections(point);
  EXPECT_EQ(ListConnection_size(conns), 1);
  ListConnection_destroy(conns);

  EXPECT_THROW(Point_keys(nullptr), std::invalid_argument);
  EXPECT_THROW(Point_values(nullptr), std::invalid_argument);
  EXPECT_THROW(Point_items(nullptr), std::invalid_argument);
  EXPECT_THROW(Point_coordinates(nullptr), std::invalid_argument);
  EXPECT_THROW(Point_connections(nullptr), std::invalid_argument);
}

TEST_F(PointTest, Arithmetic) {
  auto p2  = Point_create(map_cd, unit);
  auto add = Point_addition(point, p2);
  auto sub = Point_subtraction(point, p2);
  auto mul = Point_multiplication(point, 2.0);
  auto div = Point_division(point, 2.0);
  auto neg = Point_negation(point);

  Point_destroy(add);
  Point_destroy(sub);
  Point_destroy(mul);
  Point_destroy(div);
  Point_destroy(neg);
  Point_destroy(p2);

  EXPECT_THROW(Point_addition(nullptr, point), std::invalid_argument);
  EXPECT_THROW(Point_addition(point, nullptr), std::invalid_argument);
  EXPECT_THROW(Point_subtraction(nullptr, point), std::invalid_argument);
  EXPECT_THROW(Point_subtraction(point, nullptr), std::invalid_argument);
  EXPECT_THROW(Point_multiplication(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(Point_division(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(Point_negation(nullptr), std::invalid_argument);
}

TEST_F(PointTest, SetUnit) {
  Point_set_unit(point, unit);
  EXPECT_THROW(Point_set_unit(nullptr, unit), std::invalid_argument);
  EXPECT_THROW(Point_set_unit(point, nullptr), std::invalid_argument);
}

TEST_F(PointTest, EqualNotEqual) {
  auto p2 = Point_create(map_cd, unit);
  EXPECT_TRUE(Point_equal(point, p2));
  EXPECT_FALSE(Point_not_equal(point, p2));
  Point_destroy(p2);
  EXPECT_THROW(Point_equal(nullptr, point), std::invalid_argument);
  EXPECT_THROW(Point_equal(point, nullptr), std::invalid_argument);
  EXPECT_THROW(Point_not_equal(nullptr, point), std::invalid_argument);
  EXPECT_THROW(Point_not_equal(point, nullptr), std::invalid_argument);
}

TEST_F(PointTest, ToJsonFromJson) {
  auto json = Point_to_json_string(point);
  auto p2   = Point_from_json_string(json);
  EXPECT_TRUE(Point_equal(point, p2));
  String_destroy(json);
  Point_destroy(p2);
  EXPECT_THROW(Point_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(Point_from_json_string(nullptr), std::invalid_argument);
}
