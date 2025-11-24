#include <gtest/gtest.h>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/MapInstrumentPortPortTransform_c_api.h"
#include "falcon_core/generic/PairInstrumentPortPortTransform_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class MapInstrumentPortPortTransformTest : public ::testing::Test {
 protected:
  void SetUp() override {
    p1 = PairInstrumentPortPortTransform_create(
        InstrumentPort_create_knob(
            String_wrap("knob1"),
            Connection_create_barrier_gate(String_wrap("gate1")),
            InstrumentTypes_voltmeter(),
            SymbolUnit_create_volt(),
            String_wrap("")),
        PortTransform_create(
            InstrumentPort_create_knob(
                String_wrap("name1"),
                Connection_create_barrier_gate(String_wrap("gate1")),
                InstrumentTypes_voltmeter(),
                SymbolUnit_create_volt(),
                String_wrap("")),
            AnalyticFunction_create_identity()));

    p2 = PairInstrumentPortPortTransform_create(
        InstrumentPort_create_knob(
            String_wrap("knob2"),
            Connection_create_barrier_gate(String_wrap("gate2")),
            InstrumentTypes_voltmeter(),
            SymbolUnit_create_volt(),
            String_wrap("")),
        PortTransform_create(
            InstrumentPort_create_knob(
                String_wrap("name2"),
                Connection_create_barrier_gate(String_wrap("gate2")),
                InstrumentTypes_voltmeter(),
                SymbolUnit_create_volt(),
                String_wrap("")),
            AnalyticFunction_create_identity()));

    PairInstrumentPortPortTransformHandle arr[2] = {p1, p2};
    map  = MapInstrumentPortPortTransform_create(arr, 2);
    map2 = MapInstrumentPortPortTransform_create_empty();
    MapInstrumentPortPortTransform_insert_or_assign(
        map2,
        PairInstrumentPortPortTransform_first(p1),
        PairInstrumentPortPortTransform_second(p1));
    MapInstrumentPortPortTransform_insert(
        map2,
        PairInstrumentPortPortTransform_first(p2),
        PairInstrumentPortPortTransform_second(p2));
  }
  void TearDown() override {
    MapInstrumentPortPortTransform_destroy(map);
    PairInstrumentPortPortTransform_destroy(p1);
    PairInstrumentPortPortTransform_destroy(p2);
  }
  PairInstrumentPortPortTransformHandle p1;
  PairInstrumentPortPortTransformHandle p2;
  MapInstrumentPortPortTransformHandle  map;
  MapInstrumentPortPortTransformHandle  map2;
};

TEST_F(MapInstrumentPortPortTransformTest, CreateDestroy) {
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInstrumentPortPortTransformTest, InsertAssignAccessErase) {
  EXPECT_TRUE(
      PortTransform_equal(MapInstrumentPortPortTransform_at(
                              map, PairInstrumentPortPortTransform_first(p1)),
                          PairInstrumentPortPortTransform_second(p1)));
  MapInstrumentPortPortTransform_erase(
      map, PairInstrumentPortPortTransform_first(p1));
  EXPECT_FALSE(MapInstrumentPortPortTransform_contains(
      map, PairInstrumentPortPortTransform_first(p1)));
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_insert_or_assign(
      nullptr,
      PairInstrumentPortPortTransform_first(p1),
      PairInstrumentPortPortTransform_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_insert_or_assign(
      map, nullptr, PairInstrumentPortPortTransform_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_insert_or_assign(
      map, PairInstrumentPortPortTransform_first(p1), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_insert(
      nullptr,
      PairInstrumentPortPortTransform_first(p1),
      PairInstrumentPortPortTransform_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_insert(
      map, nullptr, PairInstrumentPortPortTransform_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_insert(
      map, PairInstrumentPortPortTransform_first(p1), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_at(nullptr,
                                    PairInstrumentPortPortTransform_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_at(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_erase(
      nullptr, PairInstrumentPortPortTransform_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_erase(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInstrumentPortPortTransformTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapInstrumentPortPortTransform_size(map), 2);
  EXPECT_FALSE(MapInstrumentPortPortTransform_empty(map));
  MapInstrumentPortPortTransform_clear(map);
  EXPECT_TRUE(MapInstrumentPortPortTransform_empty(map));
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_contains(
      nullptr, PairInstrumentPortPortTransform_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_contains(map2, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInstrumentPortPortTransformTest, KeysValuesItems) {
  EXPECT_NE(MapInstrumentPortPortTransform_keys(map), nullptr);
  EXPECT_NE(MapInstrumentPortPortTransform_values(map), nullptr);
  EXPECT_NE(MapInstrumentPortPortTransform_items(map), nullptr);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_keys(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_values(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInstrumentPortPortTransformTest, Equality) {
  EXPECT_TRUE(MapInstrumentPortPortTransform_equal(map, map2));
  EXPECT_FALSE(MapInstrumentPortPortTransform_not_equal(map, map2));
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_not_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_not_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapInstrumentPortPortTransformTest, ToJsonFromJson) {
  auto json = MapInstrumentPortPortTransform_to_json_string(map);
  auto m2   = MapInstrumentPortPortTransform_from_json_string(json);
  EXPECT_TRUE(MapInstrumentPortPortTransform_equal(map, m2));
  MapInstrumentPortPortTransform_destroy(m2);
  String_destroy(json);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapInstrumentPortPortTransform_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
