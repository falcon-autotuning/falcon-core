#include <gtest/gtest.h>

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

    start  = Point_create(map_cd, unit);
    end    = Point_create(map_cd, unit);
    vector = Vector_create(start, end);
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
  SymbolUnitHandle            unit   = nullptr;
  MapConnectionDoubleHandle   map_cd = nullptr;
  MapConnectionQuantityHandle map_cq = nullptr;
  ConnectionHandle            conn   = nullptr;
  QuantityHandle              qty    = nullptr;
  PointHandle                 start  = nullptr;
  PointHandle                 end    = nullptr;
  VectorHandle                vector = nullptr;
};

TEST_F(VectorTest, CreateDestroy) {
  auto v = Vector_create(start, end);
  Vector_destroy(v);
  EXPECT_THROW(Vector_create(nullptr, end), std::invalid_argument);
  EXPECT_THROW(Vector_create(start, nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_destroy(nullptr), std::invalid_argument);
}

TEST_F(VectorTest, CreateFromEnd) {
  auto v = Vector_create_from_end(end);
  Vector_destroy(v);
  EXPECT_THROW(Vector_create_from_end(nullptr), std::invalid_argument);
}

TEST_F(VectorTest, CreateFromQuantities) {
  auto v = Vector_create_from_quantities(map_cq, map_cq);
  Vector_destroy(v);
  EXPECT_THROW(Vector_create_from_quantities(nullptr, map_cq),
               std::invalid_argument);
  EXPECT_THROW(Vector_create_from_quantities(map_cq, nullptr),
               std::invalid_argument);
}

TEST_F(VectorTest, CreateFromEndQuantities) {
  auto v = Vector_create_from_end_quantities(map_cq);
  Vector_destroy(v);
  EXPECT_THROW(Vector_create_from_end_quantities(nullptr),
               std::invalid_argument);
}

TEST_F(VectorTest, CreateFromDoubles) {
  auto v = Vector_create_from_doubles(map_cd, map_cd, unit);
  Vector_destroy(v);
  EXPECT_THROW(Vector_create_from_doubles(nullptr, map_cd, unit),
               std::invalid_argument);
  EXPECT_THROW(Vector_create_from_doubles(map_cd, nullptr, unit),
               std::invalid_argument);
  EXPECT_THROW(Vector_create_from_doubles(map_cd, map_cd, nullptr),
               std::invalid_argument);
}

TEST_F(VectorTest, CreateFromEndDoubles) {
  auto v = Vector_create_from_end_doubles(map_cd, unit);
  Vector_destroy(v);
  EXPECT_THROW(Vector_create_from_end_doubles(nullptr, unit),
               std::invalid_argument);
  EXPECT_THROW(Vector_create_from_end_doubles(map_cd, nullptr),
               std::invalid_argument);
}

TEST_F(VectorTest, CreateFromParent) {
  auto v = Vector_create_from_parent(map_cq);
  Vector_destroy(v);
  EXPECT_THROW(Vector_create_from_parent(nullptr), std::invalid_argument);
}

TEST_F(VectorTest, EndStartPoint) {
  auto ep = Vector_endPoint(vector);
  auto sp = Vector_startPoint(vector);
  Point_destroy(ep);
  Point_destroy(sp);
  EXPECT_THROW(Vector_endPoint(nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_startPoint(nullptr), std::invalid_argument);
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
  EXPECT_THROW(Vector_end_quantities(nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_start_quantities(nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_end_map(nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_start_map(nullptr), std::invalid_argument);
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
  EXPECT_THROW(Vector_connections(nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_unit(nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_principle_connection(nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_magnitude(nullptr), std::invalid_argument);
}

TEST_F(VectorTest, InsertOrAssignInsertAtErase) {
  auto pq = PairQuantityQuantity_create(qty, qty);
  Vector_insert_or_assign(vector, conn, pq);
  Vector_insert(vector, conn, pq);
  auto at = Vector_at(vector, conn);
  PairQuantityQuantity_destroy(at);
  Vector_erase(vector, conn);
  PairQuantityQuantity_destroy(pq);

  EXPECT_THROW(Vector_insert_or_assign(nullptr, conn, pq),
               std::invalid_argument);
  EXPECT_THROW(Vector_insert_or_assign(vector, nullptr, pq),
               std::invalid_argument);
  EXPECT_THROW(Vector_insert_or_assign(vector, conn, nullptr),
               std::invalid_argument);

  EXPECT_THROW(Vector_insert(nullptr, conn, pq), std::invalid_argument);
  EXPECT_THROW(Vector_insert(vector, nullptr, pq), std::invalid_argument);
  EXPECT_THROW(Vector_insert(vector, conn, nullptr), std::invalid_argument);

  EXPECT_THROW(Vector_at(nullptr, conn), std::invalid_argument);
  EXPECT_THROW(Vector_at(vector, nullptr), std::invalid_argument);

  EXPECT_THROW(Vector_erase(nullptr, conn), std::invalid_argument);
  EXPECT_THROW(Vector_erase(vector, nullptr), std::invalid_argument);
}

TEST_F(VectorTest, SizeEmptyClearContainsKeysValuesItems) {
  EXPECT_GE(Vector_size(vector), 0);
  EXPECT_FALSE(Vector_empty(vector));
  Vector_clear(vector);
  EXPECT_TRUE(Vector_empty(vector));
  EXPECT_THROW(Vector_size(nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_clear(nullptr), std::invalid_argument);

  EXPECT_TRUE(Vector_contains(vector, conn));
  EXPECT_THROW(Vector_contains(nullptr, conn), std::invalid_argument);
  EXPECT_THROW(Vector_contains(vector, nullptr), std::invalid_argument);

  auto keys   = Vector_keys(vector);
  auto values = Vector_values(vector);
  auto items  = Vector_items(vector);
  ListConnection_destroy(keys);
  ListPairQuantityQuantity_destroy(values);
  ListPairConnectionPairQuantityQuantity_destroy(items);
  EXPECT_THROW(Vector_keys(nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_values(nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_items(nullptr), std::invalid_argument);
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

  EXPECT_THROW(Vector_addition(nullptr, vector), std::invalid_argument);
  EXPECT_THROW(Vector_addition(vector, nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_subtraction(nullptr, vector), std::invalid_argument);
  EXPECT_THROW(Vector_subtraction(vector, nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_double_multiplication(nullptr, 2.0),
               std::invalid_argument);
  EXPECT_THROW(Vector_int_multiplication(nullptr, 2), std::invalid_argument);
  EXPECT_THROW(Vector_double_division(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(Vector_int_division(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(Vector_negation(nullptr), std::invalid_argument);
}

TEST_F(VectorTest,
       UpdateStartTranslateExtendShrinkUnitVectorNormalizeProjectUpdateUnit) {
  DeviceVoltageStatesHandle dvs = DeviceVoltageStates_create_empty();
  auto                      v1  = Vector_update_start_from_states(vector, dvs);
  Vector_destroy(v1);
  DeviceVoltageStates_destroy(dvs);
  EXPECT_THROW(Vector_update_start_from_states(nullptr, dvs),
               std::invalid_argument);
  EXPECT_THROW(Vector_update_start_from_states(vector, nullptr),
               std::invalid_argument);

  auto v2 = Vector_translate_doubles(vector, map_cd, unit);
  Vector_destroy(v2);
  EXPECT_THROW(Vector_translate_doubles(nullptr, map_cd, unit),
               std::invalid_argument);
  EXPECT_THROW(Vector_translate_doubles(vector, nullptr, unit),
               std::invalid_argument);
  EXPECT_THROW(Vector_translate_doubles(vector, map_cd, nullptr),
               std::invalid_argument);

  auto v3 = Vector_translate_quantities(vector, map_cq);
  Vector_destroy(v3);
  EXPECT_THROW(Vector_translate_quantities(nullptr, map_cq),
               std::invalid_argument);
  EXPECT_THROW(Vector_translate_quantities(vector, nullptr),
               std::invalid_argument);

  auto v4 = Vector_translate(vector, start);
  Vector_destroy(v4);
  EXPECT_THROW(Vector_translate(nullptr, start), std::invalid_argument);
  EXPECT_THROW(Vector_translate(vector, nullptr), std::invalid_argument);

  auto v5 = Vector_translate_to_origin(vector);
  Vector_destroy(v5);
  EXPECT_THROW(Vector_translate_to_origin(nullptr), std::invalid_argument);

  auto v6 = Vector_double_extend(vector, 2.0);
  auto v7 = Vector_int_extend(vector, 2);
  auto v8 = Vector_double_shrink(vector, 2.0);
  auto v9 = Vector_int_shrink(vector, 2);
  Vector_destroy(v6);
  Vector_destroy(v7);
  Vector_destroy(v8);
  Vector_destroy(v9);
  EXPECT_THROW(Vector_double_extend(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(Vector_int_extend(nullptr, 2), std::invalid_argument);
  EXPECT_THROW(Vector_double_shrink(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(Vector_int_shrink(nullptr, 2), std::invalid_argument);

  auto v10 = Vector_unit_vector(vector);
  auto v11 = Vector_normalize(vector);
  Vector_destroy(v10);
  Vector_destroy(v11);
  EXPECT_THROW(Vector_unit_vector(nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_normalize(nullptr), std::invalid_argument);

  auto v12 = Vector_create(start, end);
  auto v13 = Vector_project(vector, v12);
  Vector_destroy(v13);
  Vector_destroy(v12);
  EXPECT_THROW(Vector_project(nullptr, vector), std::invalid_argument);
  EXPECT_THROW(Vector_project(vector, nullptr), std::invalid_argument);

  auto new_unit = SymbolUnit_create_millimeter();
  Vector_update_unit(vector, new_unit);
  SymbolUnit_destroy(new_unit);
  EXPECT_THROW(Vector_update_unit(nullptr, unit), std::invalid_argument);
  EXPECT_THROW(Vector_update_unit(vector, nullptr), std::invalid_argument);
}

TEST_F(VectorTest, EqualNotEqual) {
  auto v2 = Vector_create(start, end);
  EXPECT_TRUE(Vector_equal(vector, v2));
  EXPECT_FALSE(Vector_not_equal(vector, v2));
  Vector_destroy(v2);
  EXPECT_THROW(Vector_equal(nullptr, vector), std::invalid_argument);
  EXPECT_THROW(Vector_equal(vector, nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_not_equal(nullptr, vector), std::invalid_argument);
  EXPECT_THROW(Vector_not_equal(vector, nullptr), std::invalid_argument);
}

TEST_F(VectorTest, ToJsonFromJson) {
  auto json = Vector_to_json_string(vector);
  auto v2   = Vector_from_json_string(json);
  EXPECT_TRUE(Vector_equal(vector, v2));
  Vector_destroy(v2);
  String_destroy(json);
  EXPECT_THROW(Vector_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(Vector_from_json_string(nullptr), std::invalid_argument);
}
