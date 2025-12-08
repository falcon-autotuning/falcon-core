#include <gtest/gtest.h>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/Point_c_api.h"
#include "falcon_core/math/Quantity_c_api.h"
#include "falcon_core/math/Vector_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class VectorTest : public ::testing::Test {
 protected:
  void SetUp() override {
    unit   = SymbolUnit_create_volt();
    map_cd = MapConnectionDouble_create_empty();
    conn   = Connection_create_plunger_gate(String_wrap("A"));
    MapConnectionDouble_insert(map_cd, conn, 1.0);

    map_cq = MapConnectionQuantity_create_empty();
    qty    = Quantity_create(2.0, unit);
    MapConnectionQuantity_insert(map_cq, conn, qty);

    std::cout << "Creating start and end points\n";
    start = Point_create(map_cd, unit);
    std::cout << "Start point created\n";
    end = Point_create(map_cq, unit);
    std::cout << "End point created\n";
    vector = Vector_create(start, end);
    std::cout << "Vector created\n";
  }
  void TearDown() override {
    Vector_destroy(vector);
    Point_destroy(start);
    Point_destroy(end);
    Quantity_destroy(qty);
    SymbolUnit_destroy(unit);
    MapConnectionDouble_destroy(map_cd);
    MapConnectionQuantity_destroy(map_cq);
    Connection_destroy(conn);
  }
  SymbolUnitHandle            unit;
  MapConnectionDoubleHandle   map_cd;
  MapConnectionQuantityHandle map_cq;
  ConnectionHandle            conn;
  QuantityHandle              qty;
  PointHandle                 start;
  PointHandle                 end;
  VectorHandle                vector;
};

TEST_F(VectorTest, CreateDestroy) {
  auto v = Vector_create(start, end);
  Vector_destroy(v);
  set_last_error(0, nullptr);
  Vector_create(nullptr, end);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_create(start, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest, CreateFromEnd) {
  auto v = Vector_create_from_end(end);
  Vector_destroy(v);
  set_last_error(0, nullptr);
  Vector_create_from_end(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest, CreateFromQuantities) {
  auto v = Vector_create_from_quantities(map_cq, map_cq);
  Vector_destroy(v);
  set_last_error(0, nullptr);
  Vector_create_from_quantities(nullptr, map_cq);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_create_from_quantities(map_cq, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest, CreateFromEndQuantities) {
  auto v = Vector_create_from_end_quantities(map_cq);
  Vector_destroy(v);
  set_last_error(0, nullptr);
  Vector_create_from_end_quantities(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest, CreateFromDoubles) {
  auto v = Vector_create_from_doubles(map_cd, map_cd, unit);
  Vector_destroy(v);
  set_last_error(0, nullptr);
  Vector_create_from_doubles(nullptr, map_cd, unit);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_create_from_doubles(map_cd, nullptr, unit);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_create_from_doubles(map_cd, map_cd, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest, CreateFromEndDoubles) {
  auto v = Vector_create_from_end_doubles(map_cd, unit);
  Vector_destroy(v);
  set_last_error(0, nullptr);
  Vector_create_from_end_doubles(nullptr, unit);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_create_from_end_doubles(map_cd, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest, CreateFromParent) {
  auto v = Vector_create_from_parent(map_cq);
  Vector_destroy(v);
  set_last_error(0, nullptr);
  Vector_create_from_parent(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest, EndStartPoint) {
  auto ep = Vector_end_point(vector);
  auto sp = Vector_start_point(vector);
  Point_destroy(ep);
  Point_destroy(sp);
  set_last_error(0, nullptr);
  Vector_end_point(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_start_point(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest, EndStartQuantitiesAndMap) {
  auto eq = Vector_end_quantities(vector);
  auto sq = Vector_start_quantities(vector);
  auto em = Vector_end_map(vector);
  auto sm = Vector_start_map(vector);
  MapConnectionQuantity_destroy(eq);
  MapConnectionQuantity_destroy(sq);
  MapConnectionDouble_destroy(em);
  MapConnectionDouble_destroy(sm);
  set_last_error(0, nullptr);
  Vector_end_quantities(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_start_quantities(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_end_map(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_start_map(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest, ConnectionsUnitPrincipleMagnitude) {
  auto   conns = Vector_connections(vector);
  auto   u     = Vector_unit(vector);
  auto   pc    = Vector_principle_connection(vector);
  double mag   = Vector_magnitude(vector);
  ListConnection_destroy(conns);
  SymbolUnit_destroy(u);
  Connection_destroy(pc);
  EXPECT_GE(mag, 0.0);
  set_last_error(0, nullptr);
  Vector_connections(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_unit(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_principle_connection(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_magnitude(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest, InsertOrAssignInsertAtErase) {
  auto pq = PairQuantityQuantity_create(qty, qty);
  Vector_insert_or_assign(vector, conn, pq);
  Vector_insert(vector, conn, pq);
  auto at = Vector_at(vector, conn);
  PairQuantityQuantity_destroy(at);
  Vector_erase(vector, conn);
  PairQuantityQuantity_destroy(pq);

  set_last_error(0, nullptr);
  Vector_insert_or_assign(nullptr, conn, pq);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_insert_or_assign(vector, nullptr, pq);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_insert_or_assign(vector, conn, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Vector_insert(nullptr, conn, pq);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_insert(vector, nullptr, pq);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_insert(vector, conn, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Vector_at(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_at(vector, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Vector_erase(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_erase(vector, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest, SizeEmptyClear) {
  EXPECT_GE(Vector_size(vector), 0);
  EXPECT_FALSE(Vector_empty(vector));
  Vector_clear(vector);
  EXPECT_TRUE(Vector_empty(vector));
  set_last_error(0, nullptr);
  Vector_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest, ContainsKeysValuesItems) {
  EXPECT_TRUE(Vector_contains(vector, conn));
  set_last_error(0, nullptr);
  Vector_contains(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_contains(vector, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  auto keys   = Vector_keys(vector);
  auto values = Vector_values(vector);
  auto items  = Vector_items(vector);
  ListConnection_destroy(keys);
  ListPairQuantityQuantity_destroy(values);
  ListPairConnectionPairQuantityQuantity_destroy(items);
  set_last_error(0, nullptr);
  Vector_keys(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_values(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest, Arithmetic) {
  auto v2   = Vector_create(start, end);
  auto add  = Vector_addition(vector, v2);
  auto sub  = Vector_subtraction(vector, v2);
  auto muld = Vector_double_multiplication(vector, 2.0);
  auto muli = Vector_int_multiplication(vector, 2);
  auto divd = Vector_double_division(vector, 2.0);
  auto divi = Vector_int_division(vector, 2.0);
  auto neg  = Vector_negation(vector);

  Vector_destroy(add);
  Vector_destroy(sub);
  Vector_destroy(muld);
  Vector_destroy(muli);
  Vector_destroy(divd);
  Vector_destroy(divi);
  Vector_destroy(neg);
  Vector_destroy(v2);

  set_last_error(0, nullptr);
  Vector_addition(nullptr, vector);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_addition(vector, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_subtraction(nullptr, vector);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_subtraction(vector, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_double_multiplication(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_int_multiplication(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_double_division(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_int_division(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_negation(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest,
       UpdateStartTranslateExtendShrinkUnitVectorNormalizeProjectUpdateUnit) {
  DeviceVoltageStatesHandle dvs = DeviceVoltageStates_create_empty();
  auto                      v1  = Vector_update_start_from_states(vector, dvs);
  Vector_destroy(v1);
  DeviceVoltageStates_destroy(dvs);
  set_last_error(0, nullptr);
  Vector_update_start_from_states(nullptr, dvs);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_update_start_from_states(vector, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  auto v2 = Vector_translate_doubles(vector, map_cd, unit);
  Vector_destroy(v2);
  set_last_error(0, nullptr);
  Vector_translate_doubles(nullptr, map_cd, unit);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_translate_doubles(vector, nullptr, unit);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_translate_doubles(vector, map_cd, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  auto v3 = Vector_translate_quantities(vector, map_cq);
  Vector_destroy(v3);
  set_last_error(0, nullptr);
  Vector_translate_quantities(nullptr, map_cq);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_translate_quantities(vector, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  auto v4 = Vector_translate(vector, start);
  Vector_destroy(v4);
  set_last_error(0, nullptr);
  Vector_translate(nullptr, start);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_translate(vector, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  auto v5 = Vector_translate_to_origin(vector);
  Vector_destroy(v5);
  set_last_error(0, nullptr);
  Vector_translate_to_origin(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  auto v6 = Vector_double_extend(vector, 2.0);
  auto v7 = Vector_int_extend(vector, 2);
  auto v8 = Vector_double_shrink(vector, 2.0);
  auto v9 = Vector_int_shrink(vector, 2);
  Vector_destroy(v6);
  Vector_destroy(v7);
  Vector_destroy(v8);
  Vector_destroy(v9);
  set_last_error(0, nullptr);
  Vector_double_extend(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_int_extend(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_double_shrink(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_int_shrink(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  auto v10 = Vector_unit_vector(vector);
  auto v11 = Vector_normalize(vector);
  Vector_destroy(v10);
  Vector_destroy(v11);
  set_last_error(0, nullptr);
  Vector_unit_vector(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_normalize(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  auto v12 = Vector_create(start, end);
  auto v13 = Vector_project(vector, v12);
  Vector_destroy(v13);
  Vector_destroy(v12);
  set_last_error(0, nullptr);
  Vector_project(nullptr, vector);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_project(vector, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  auto new_unit = SymbolUnit_create_millivolt();
  Vector_update_unit(vector, new_unit);
  SymbolUnit_destroy(new_unit);
  set_last_error(0, nullptr);
  Vector_update_unit(nullptr, unit);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_update_unit(vector, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest, EqualNotEqual) {
  auto v2 = Vector_create(start, end);
  EXPECT_TRUE(Vector_equal(vector, v2));
  EXPECT_FALSE(Vector_not_equal(vector, v2));
  Vector_destroy(v2);
  set_last_error(0, nullptr);
  Vector_equal(nullptr, vector);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_equal(vector, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_not_equal(nullptr, vector);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_not_equal(vector, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VectorTest, ToJsonFromJson) {
  auto json = Vector_to_json_string(vector);
  auto v2   = Vector_from_json_string(json);
  EXPECT_TRUE(Vector_equal(vector, v2));
  Vector_destroy(v2);
  String_destroy(json);
  set_last_error(0, nullptr);
  Vector_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Vector_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
