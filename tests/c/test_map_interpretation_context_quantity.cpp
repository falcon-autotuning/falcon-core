#include <gtest/gtest.h>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/MapInterpretationContextQuantity_c_api.h"
#include "falcon-core/generic/PairInterpretationContextQuantity_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class MapInterpretationContextQuantityTest : public ::testing::Test {
 protected:
  void SetUp() override {
    ListMeasurementContextHandle axes_indp1 =
        ListMeasurementContext_create_empty();
    ListMeasurementContext_push_back(
        axes_indp1,
        MeasurementContext_create(
            Connection_create_plunger_gate(String_wrap("gateA")),
            InstrumentTypes_voltmeter()));
    ListMeasurementContextHandle axes_dep1 =
        ListMeasurementContext_create_empty();
    ListMeasurementContext_push_back(
        axes_dep1,
        MeasurementContext_create(
            Connection_create_plunger_gate(String_wrap("gateB")),
            InstrumentTypes_voltmeter()));
    ListMeasurementContextHandle axes_indp2 =
        ListMeasurementContext_create_empty();
    ListMeasurementContext_push_back(
        axes_indp2,
        MeasurementContext_create(
            Connection_create_plunger_gate(String_wrap("gateC")),
            InstrumentTypes_voltmeter()));
    ListMeasurementContextHandle axes_dep2 =
        ListMeasurementContext_create_empty();
    ListMeasurementContext_push_back(
        axes_dep2,
        MeasurementContext_create(
            Connection_create_plunger_gate(String_wrap("gateD")),
            InstrumentTypes_voltmeter()));
    p1 = PairInterpretationContextQuantity_create(
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp1),
                                     axes_dep1,
                                     SymbolUnit_create_volt()),
        Quantity_create(1.0, SymbolUnit_create_volt()));
    p2 = PairInterpretationContextQuantity_create(
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp2),
                                     axes_dep2,
                                     SymbolUnit_create_volt()),
        Quantity_create(2.0, SymbolUnit_create_volt()));
    PairInterpretationContextQuantityHandle arr[2] = {p1, p2};
    map  = MapInterpretationContextQuantity_create(arr, 2);
    map2 = MapInterpretationContextQuantity_create_empty();
    MapInterpretationContextQuantity_insert_or_assign(
        map2,
        PairInterpretationContextQuantity_first(p1),
        PairInterpretationContextQuantity_second(p1));
    MapInterpretationContextQuantity_insert(
        map2,
        PairInterpretationContextQuantity_first(p2),
        PairInterpretationContextQuantity_second(p2));
  }
  void TearDown() override {
    MapInterpretationContextQuantity_destroy(map);
    PairInterpretationContextQuantity_destroy(p1);
    PairInterpretationContextQuantity_destroy(p2);
  }
  PairInterpretationContextQuantityHandle p1;
  PairInterpretationContextQuantityHandle p2;
  MapInterpretationContextQuantityHandle  map;
  MapInterpretationContextQuantityHandle  map2;
};

TEST_F(MapInterpretationContextQuantityTest, CreateDestroy) {
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInterpretationContextQuantityTest, InsertAssignAccessErase) {
  EXPECT_TRUE(
      Quantity_equal(MapInterpretationContextQuantity_at(
                         map, PairInterpretationContextQuantity_first(p1)),
                     PairInterpretationContextQuantity_second(p1)));
  MapInterpretationContextQuantity_erase(
      map, PairInterpretationContextQuantity_first(p1));
  EXPECT_FALSE(MapInterpretationContextQuantity_contains(
      map, PairInterpretationContextQuantity_first(p1)));
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_insert_or_assign(
      nullptr,
      PairInterpretationContextQuantity_first(p1),
      PairInterpretationContextQuantity_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_insert_or_assign(
      map, nullptr, PairInterpretationContextQuantity_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_insert_or_assign(
      map, PairInterpretationContextQuantity_first(p1), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_insert(
      nullptr,
      PairInterpretationContextQuantity_first(p1),
      PairInterpretationContextQuantity_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_insert(
      map, nullptr, PairInterpretationContextQuantity_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_insert(
      map, PairInterpretationContextQuantity_first(p1), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_at(
      nullptr, PairInterpretationContextQuantity_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_at(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_erase(
      nullptr, PairInterpretationContextQuantity_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_erase(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInterpretationContextQuantityTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapInterpretationContextQuantity_size(map), 2);
  EXPECT_FALSE(MapInterpretationContextQuantity_empty(map));
  MapInterpretationContextQuantity_clear(map);
  EXPECT_TRUE(MapInterpretationContextQuantity_empty(map));
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_contains(
      nullptr, PairInterpretationContextQuantity_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_contains(map2, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInterpretationContextQuantityTest, KeysValuesItems) {
  EXPECT_NE(MapInterpretationContextQuantity_keys(map), nullptr);
  EXPECT_NE(MapInterpretationContextQuantity_values(map), nullptr);
  EXPECT_NE(MapInterpretationContextQuantity_items(map), nullptr);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_keys(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_values(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInterpretationContextQuantityTest, Equality) {
  EXPECT_TRUE(MapInterpretationContextQuantity_equal(map, map2));
  EXPECT_FALSE(MapInterpretationContextQuantity_not_equal(map, map2));
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_not_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_not_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInterpretationContextQuantityTest, ToJsonFromJson) {
  auto json = MapInterpretationContextQuantity_to_json_string(map);
  auto m2   = MapInterpretationContextQuantity_from_json_string(json);
  EXPECT_TRUE(MapInterpretationContextQuantity_equal(map, m2));
  MapInterpretationContextQuantity_destroy(m2);
  String_destroy(json);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextQuantity_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
