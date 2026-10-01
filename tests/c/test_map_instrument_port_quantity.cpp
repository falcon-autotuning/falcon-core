#include <gtest/gtest.h>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/MapInstrumentPortQuantity_c_api.h"
#include "falcon-core/generic/PairInstrumentPortQuantity_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon-core/math/Quantity_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class MapInstrumentPortQuantityTest : public ::testing::Test {
protected:
  void SetUp() override {
    p1 = PairInstrumentPortQuantity_create(
        InstrumentPort_create_knob(
            String_wrap("knob1"), String_wrap("inst"),
            Connection_create_barrier_gate(String_wrap("gate1")),
            INSTRUMENT_VOLTMETER, SymbolUnit_create_volt(), String_wrap("")),
        Quantity_create(1.0, SymbolUnit_create_volt()));

    p2 = PairInstrumentPortQuantity_create(
        InstrumentPort_create_knob(
            String_wrap("knob2"), String_wrap("inst"),
            Connection_create_barrier_gate(String_wrap("gate2")),
            INSTRUMENT_VOLTMETER, SymbolUnit_create_volt(), String_wrap("")),
        Quantity_create(2.0, SymbolUnit_create_volt()));

    PairInstrumentPortQuantityHandle arr[2] = {p1, p2};

    map = MapInstrumentPortQuantity_create(arr, 2);

    map2 = MapInstrumentPortQuantity_create_empty();

    MapInstrumentPortQuantity_insert_or_assign(
        map2, PairInstrumentPortQuantity_first(p1),
        PairInstrumentPortQuantity_second(p1));

    MapInstrumentPortQuantity_insert(map2, PairInstrumentPortQuantity_first(p2),
                                     PairInstrumentPortQuantity_second(p2));
  }

  void TearDown() override {
    MapInstrumentPortQuantity_destroy(map);
    PairInstrumentPortQuantity_destroy(p1);
    PairInstrumentPortQuantity_destroy(p2);
  }

  PairInstrumentPortQuantityHandle p1;
  PairInstrumentPortQuantityHandle p2;

  MapInstrumentPortQuantityHandle map;
  MapInstrumentPortQuantityHandle map2;
};
TEST_F(MapInstrumentPortQuantityTest, CreateDestroy) {
  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(MapInstrumentPortQuantityTest, InsertAssignAccessErase) {
  EXPECT_TRUE(Quantity_equal(
      MapInstrumentPortQuantity_at(map, PairInstrumentPortQuantity_first(p1)),
      PairInstrumentPortQuantity_second(p1)));

  MapInstrumentPortQuantity_erase(map, PairInstrumentPortQuantity_first(p1));

  EXPECT_FALSE(MapInstrumentPortQuantity_contains(
      map, PairInstrumentPortQuantity_first(p1)));

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_insert_or_assign(
      nullptr, PairInstrumentPortQuantity_first(p1),
      PairInstrumentPortQuantity_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_insert_or_assign(
      map, nullptr, PairInstrumentPortQuantity_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_insert_or_assign(
      map, PairInstrumentPortQuantity_first(p1), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_insert(nullptr,
                                   PairInstrumentPortQuantity_first(p1),
                                   PairInstrumentPortQuantity_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_insert(map, nullptr,
                                   PairInstrumentPortQuantity_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_insert(map, PairInstrumentPortQuantity_first(p1),
                                   nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_at(nullptr, PairInstrumentPortQuantity_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_at(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_erase(nullptr,
                                  PairInstrumentPortQuantity_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_erase(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(MapInstrumentPortQuantityTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapInstrumentPortQuantity_size(map), 2);

  EXPECT_FALSE(MapInstrumentPortQuantity_empty(map));

  MapInstrumentPortQuantity_clear(map);

  EXPECT_TRUE(MapInstrumentPortQuantity_empty(map));

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_contains(nullptr,
                                     PairInstrumentPortQuantity_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_contains(map2, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(MapInstrumentPortQuantityTest, KeysValuesItems) {
  EXPECT_NE(MapInstrumentPortQuantity_keys(map), nullptr);

  EXPECT_NE(MapInstrumentPortQuantity_values(map), nullptr);

  EXPECT_NE(MapInstrumentPortQuantity_items(map), nullptr);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_keys(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_values(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(MapInstrumentPortQuantityTest, Equality) {
  EXPECT_TRUE(MapInstrumentPortQuantity_equal(map, map2));

  EXPECT_FALSE(MapInstrumentPortQuantity_not_equal(map, map2));

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_not_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_not_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(MapInstrumentPortQuantityTest, ToJsonFromJson) {
  auto json = MapInstrumentPortQuantity_to_json_string(map);

  auto m2 = MapInstrumentPortQuantity_from_json_string(json);

  EXPECT_TRUE(MapInstrumentPortQuantity_equal(map, m2));

  MapInstrumentPortQuantity_destroy(m2);
  String_destroy(json);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MapInstrumentPortQuantity_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
