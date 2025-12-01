#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/generic/MapInterpretationContextString_c_api.h"
#include "falcon_core/generic/PairInterpretationContextString_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class MapInterpretationContextStringTest : public ::testing::Test {
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
    p1 = PairInterpretationContextString_create(
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp1),
                                     axes_dep1,
                                     SymbolUnit_create_volt()),
        String_wrap("hello"));
    p2 = PairInterpretationContextString_create(
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp2),
                                     axes_dep2,
                                     SymbolUnit_create_volt()),
        String_wrap("world"));
    PairInterpretationContextStringHandle arr[2] = {p1, p2};
    map  = MapInterpretationContextString_create(arr, 2);
    map2 = MapInterpretationContextString_create_empty();
    MapInterpretationContextString_insert_or_assign(
        map2,
        PairInterpretationContextString_first(p1),
        PairInterpretationContextString_second(p1));
    MapInterpretationContextString_insert(
        map2,
        PairInterpretationContextString_first(p2),
        PairInterpretationContextString_second(p2));
  }
  void TearDown() override {
    MapInterpretationContextString_destroy(map);
    PairInterpretationContextString_destroy(p1);
    PairInterpretationContextString_destroy(p2);
  }
  PairInterpretationContextStringHandle p1;
  PairInterpretationContextStringHandle p2;
  MapInterpretationContextStringHandle  map;
  MapInterpretationContextStringHandle  map2;
  bool String_equal(StringHandle a, StringHandle b) {
    if (a == nullptr || b == nullptr) {
      throw std::invalid_argument("Null StringHandle provided");
    }
    std::string str_a = std::string(a->raw, a->length);
    std::string str_b = std::string(b->raw, b->length);
    return std::string(str_a) == std::string(str_b);
  }
};

TEST_F(MapInterpretationContextStringTest, CreateDestroy) {
  set_last_error(0, nullptr);
  MapInterpretationContextString_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInterpretationContextStringTest, InsertAssignAccessErase) {
  EXPECT_TRUE(String_equal(MapInterpretationContextString_at(
                               map, PairInterpretationContextString_first(p1)),
                           PairInterpretationContextString_second(p1)));
  MapInterpretationContextString_erase(
      map, PairInterpretationContextString_first(p1));
  EXPECT_FALSE(MapInterpretationContextString_contains(
      map, PairInterpretationContextString_first(p1)));
  set_last_error(0, nullptr);
  MapInterpretationContextString_insert_or_assign(                   nullptr,                   PairInterpretationContextString_first(p1),                   PairInterpretationContextString_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_insert_or_assign(                   map, nullptr, PairInterpretationContextString_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_insert_or_assign(                   map, PairInterpretationContextString_first(p1), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_insert(                   nullptr,                   PairInterpretationContextString_first(p1),                   PairInterpretationContextString_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_insert(                   map, nullptr, PairInterpretationContextString_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_insert(                   map, PairInterpretationContextString_first(p1), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_at(                   nullptr, PairInterpretationContextString_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_at(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_erase(                   nullptr, PairInterpretationContextString_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_erase(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInterpretationContextStringTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapInterpretationContextString_size(map), 2);
  EXPECT_FALSE(MapInterpretationContextString_empty(map));
  MapInterpretationContextString_clear(map);
  EXPECT_TRUE(MapInterpretationContextString_empty(map));
  set_last_error(0, nullptr);
  MapInterpretationContextString_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_contains(                   nullptr, PairInterpretationContextString_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_contains(map2, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInterpretationContextStringTest, KeysValuesItems) {
  EXPECT_NE(MapInterpretationContextString_keys(map), nullptr);
  EXPECT_NE(MapInterpretationContextString_values(map), nullptr);
  EXPECT_NE(MapInterpretationContextString_items(map), nullptr);
  set_last_error(0, nullptr);
  MapInterpretationContextString_keys(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_values(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInterpretationContextStringTest, Equality) {
  EXPECT_TRUE(MapInterpretationContextString_equal(map, map2));
  EXPECT_FALSE(MapInterpretationContextString_not_equal(map, map2));
  set_last_error(0, nullptr);
  MapInterpretationContextString_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_not_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_not_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInterpretationContextStringTest, ToJsonFromJson) {
  auto json = MapInterpretationContextString_to_json_string(map);
  auto m2   = MapInterpretationContextString_from_json_string(json);
  EXPECT_TRUE(MapInterpretationContextString_equal(map, m2));
  MapInterpretationContextString_destroy(m2);
  String_destroy(json);
  set_last_error(0, nullptr);
  MapInterpretationContextString_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInterpretationContextString_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
