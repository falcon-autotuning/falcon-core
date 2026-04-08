#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/generic/MapInterpretationContextDouble_c_api.h"
#include "falcon-core/generic/PairInterpretationContextDouble_c_api.h"
#include "falcon-core/generic/String_c_api.h"

class MapInterpretationContextDoubleTest : public ::testing::Test {
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
    p1 = PairInterpretationContextDouble_create(
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp1),
                                     axes_dep1,
                                     SymbolUnit_create_volt()),
        1.0);
    p2 = PairInterpretationContextDouble_create(
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp2),
                                     axes_dep2,
                                     SymbolUnit_create_volt()),
        1.0);
    PairInterpretationContextDoubleHandle arr[2] = {p1, p2};
    map  = MapInterpretationContextDouble_create(arr, 2);
    map2 = MapInterpretationContextDouble_create_empty();
    MapInterpretationContextDouble_insert_or_assign(
        map2,
        PairInterpretationContextDouble_first(p1),
        PairInterpretationContextDouble_second(p1));
    MapInterpretationContextDouble_insert(
        map2,
        PairInterpretationContextDouble_first(p2),
        PairInterpretationContextDouble_second(p2));
  }
  void TearDown() override {
    MapInterpretationContextDouble_destroy(map);
    PairInterpretationContextDouble_destroy(p1);
    PairInterpretationContextDouble_destroy(p2);
  }
  PairInterpretationContextDoubleHandle p1;
  PairInterpretationContextDoubleHandle p2;
  MapInterpretationContextDoubleHandle  map;
  MapInterpretationContextDoubleHandle  map2;
};

TEST_F(MapInterpretationContextDoubleTest, CreateDestroy) {
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInterpretationContextDoubleTest, InsertAssignAccessErase) {
  EXPECT_TRUE(MapInterpretationContextDouble_at(
                  map, PairInterpretationContextDouble_first(p1)) ==
              PairInterpretationContextDouble_second(p1));
  MapInterpretationContextDouble_erase(
      map, PairInterpretationContextDouble_first(p1));
  EXPECT_FALSE(MapInterpretationContextDouble_contains(
      map, PairInterpretationContextDouble_first(p1)));
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_insert_or_assign(                   nullptr,                   PairInterpretationContextDouble_first(p1),                   PairInterpretationContextDouble_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_insert_or_assign(                   map, nullptr, PairInterpretationContextDouble_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_insert(                   nullptr,                   PairInterpretationContextDouble_first(p1),                   PairInterpretationContextDouble_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_insert(                   map, nullptr, PairInterpretationContextDouble_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_at(                   nullptr, PairInterpretationContextDouble_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_at(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_erase(                   nullptr, PairInterpretationContextDouble_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_erase(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInterpretationContextDoubleTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapInterpretationContextDouble_size(map), 2);
  EXPECT_FALSE(MapInterpretationContextDouble_empty(map));
  MapInterpretationContextDouble_clear(map);
  EXPECT_TRUE(MapInterpretationContextDouble_empty(map));
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_contains(                   nullptr, PairInterpretationContextDouble_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_contains(map2, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInterpretationContextDoubleTest, KeysValuesItems) {
  EXPECT_NE(MapInterpretationContextDouble_keys(map), nullptr);
  EXPECT_NE(MapInterpretationContextDouble_values(map), nullptr);
  EXPECT_NE(MapInterpretationContextDouble_items(map), nullptr);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_keys(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_values(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInterpretationContextDoubleTest, Equality) {
  EXPECT_TRUE(MapInterpretationContextDouble_equal(map, map2));
  EXPECT_FALSE(MapInterpretationContextDouble_not_equal(map, map2));
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_not_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_not_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInterpretationContextDoubleTest, ToJsonFromJson) {
  auto json = MapInterpretationContextDouble_to_json_string(map);
  auto m2   = MapInterpretationContextDouble_from_json_string(json);
  EXPECT_TRUE(MapInterpretationContextDouble_equal(map, m2));
  MapInterpretationContextDouble_destroy(m2);
  String_destroy(json);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextDouble_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
