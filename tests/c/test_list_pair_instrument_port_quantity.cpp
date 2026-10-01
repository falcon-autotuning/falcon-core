#include <falcon-core/generic/ListPairInstrumentPortQuantity_c_api.h>
#include <gtest/gtest.h>

#include <vector>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/PairInstrumentPortQuantity_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon-core/math/Quantity_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class ListPairInstrumentPortQuantityTest : public ::testing::Test {
protected:
  void destroy_pair(PairInstrumentPortQuantityHandle handle) {
    PairInstrumentPortQuantity_destroy(handle);
  }

  void TearDown() override {
    for (auto handle : created_pairs) {
      destroy_pair(handle);
    }
    created_pairs.clear();
  }

  PairInstrumentPortQuantityHandle
  track_pair(const PairInstrumentPortQuantityHandle &handle) {
    created_pairs.push_back(handle);
    return handle;
  }

  void SetUp() override {
    sh1 = track_pair(PairInstrumentPortQuantity_create(
        InstrumentPort_create_knob(
            String_wrap("Channel1"), String_wrap("inst"),
            Connection_create_plunger_gate(String_wrap("gate1")),
            INSTRUMENT_VOLTMETER, SymbolUnit_create_volt(), String_wrap("")),
        Quantity_create(1.0, SymbolUnit_create_volt())));

    sh2 = track_pair(PairInstrumentPortQuantity_create(
        InstrumentPort_create_knob(
            String_wrap("Channel2"), String_wrap("inst"),
            Connection_create_plunger_gate(String_wrap("gate2")),
            INSTRUMENT_VOLTMETER, SymbolUnit_create_volt(), String_wrap("")),
        Quantity_create(2.0, SymbolUnit_create_volt())));
  }

  PairInstrumentPortQuantityHandle sh1;
  PairInstrumentPortQuantityHandle sh2;

  std::vector<PairInstrumentPortQuantityHandle> created_pairs;
};
TEST_F(ListPairInstrumentPortQuantityTest, CreateEmpty) {
  auto handle = ListPairInstrumentPortQuantity_create_empty();

  EXPECT_TRUE(ListPairInstrumentPortQuantity_empty(handle));
  EXPECT_EQ(ListPairInstrumentPortQuantity_size(handle), 0);

  ListPairInstrumentPortQuantity_destroy(handle);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ListPairInstrumentPortQuantityTest, FillValue) {
  auto handle = ListPairInstrumentPortQuantity_fill_value(3, sh1);

  EXPECT_EQ(ListPairInstrumentPortQuantity_size(handle), 3);

  ListPairInstrumentPortQuantity_destroy(handle);
}
TEST_F(ListPairInstrumentPortQuantityTest, CreateFromArray) {
  PairInstrumentPortQuantityHandle arr[2] = {sh1, sh2};

  auto handle = ListPairInstrumentPortQuantity_create(arr, 2);

  EXPECT_EQ(ListPairInstrumentPortQuantity_size(handle), 2);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  ListPairInstrumentPortQuantity_destroy(handle);
}
TEST_F(ListPairInstrumentPortQuantityTest, SizeEmptyInvalid) {
  auto handle = ListPairInstrumentPortQuantity_create_empty();

  EXPECT_EQ(ListPairInstrumentPortQuantity_size(handle), 0);

  ListPairInstrumentPortQuantity_destroy(handle);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ListPairInstrumentPortQuantityTest, EmptyInvalid) {
  auto handle = ListPairInstrumentPortQuantity_create_empty();

  EXPECT_TRUE(ListPairInstrumentPortQuantity_empty(handle));

  ListPairInstrumentPortQuantity_destroy(handle);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ListPairInstrumentPortQuantityTest, EraseAtClear) {
  auto handle = ListPairInstrumentPortQuantity_fill_value(2, sh1);

  ListPairInstrumentPortQuantity_erase_at(handle, 0);

  EXPECT_EQ(ListPairInstrumentPortQuantity_size(handle), 1);

  ListPairInstrumentPortQuantity_clear(handle);

  EXPECT_TRUE(ListPairInstrumentPortQuantity_empty(handle));

  ListPairInstrumentPortQuantity_destroy(handle);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ListPairInstrumentPortQuantityTest, PushBackContainsIndex) {
  auto handle = ListPairInstrumentPortQuantity_create_empty();

  ListPairInstrumentPortQuantity_push_back(handle, sh1);

  EXPECT_TRUE(ListPairInstrumentPortQuantity_contains(handle, sh1));

  EXPECT_EQ(ListPairInstrumentPortQuantity_index(handle, sh1), 0);

  ListPairInstrumentPortQuantity_destroy(handle);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ListPairInstrumentPortQuantityTest, ItemsAt) {
  PairInstrumentPortQuantityHandle arr[2] = {sh1, sh2};

  auto handle = ListPairInstrumentPortQuantity_create(arr, 2);

  PairInstrumentPortQuantityHandle out[2];

  EXPECT_EQ(ListPairInstrumentPortQuantity_items(handle, out, 2), 2);

  ListPairInstrumentPortQuantity_destroy(handle);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ListPairInstrumentPortQuantityTest, EqualNotEqualIntersection) {
  PairInstrumentPortQuantityHandle arr[2] = {sh1, sh2};

  auto h1 = ListPairInstrumentPortQuantity_create(arr, 2);

  auto h2 = ListPairInstrumentPortQuantity_create(arr, 2);

  EXPECT_TRUE(ListPairInstrumentPortQuantity_equal(h1, h2));

  EXPECT_FALSE(ListPairInstrumentPortQuantity_not_equal(h1, h2));

  auto h3 = ListPairInstrumentPortQuantity_intersection(h1, h2);

  EXPECT_EQ(ListPairInstrumentPortQuantity_size(h3), 2);

  ListPairInstrumentPortQuantity_destroy(h1);
  ListPairInstrumentPortQuantity_destroy(h2);
  ListPairInstrumentPortQuantity_destroy(h3);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ListPairInstrumentPortQuantityTest, ToJsonFromJson) {
  PairInstrumentPortQuantityHandle arr[1] = {sh1};

  auto handle = ListPairInstrumentPortQuantity_create(arr, 1);

  auto json = ListPairInstrumentPortQuantity_to_json_string(handle);

  auto handle2 = ListPairInstrumentPortQuantity_from_json_string(json);

  EXPECT_TRUE(ListPairInstrumentPortQuantity_equal(handle, handle2));

  ListPairInstrumentPortQuantity_destroy(handle);
  ListPairInstrumentPortQuantity_destroy(handle2);

  String_destroy(json);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ListPairInstrumentPortQuantityTest, FillValueNull) {
  set_last_error(0, nullptr);

  ListPairInstrumentPortQuantity_fill_value(3, nullptr);

  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ListPairInstrumentPortQuantityTest, PushBackNull) {
  auto handle = ListPairInstrumentPortQuantity_create_empty();

  set_last_error(0, nullptr);

  ListPairInstrumentPortQuantity_push_back(handle, nullptr);

  EXPECT_EQ(get_last_error_code(), 1);

  ListPairInstrumentPortQuantity_destroy(handle);
}
TEST_F(ListPairInstrumentPortQuantityTest, ContainsNull) {
  auto handle = ListPairInstrumentPortQuantity_create_empty();

  set_last_error(0, nullptr);

  ListPairInstrumentPortQuantity_contains(handle, nullptr);

  EXPECT_EQ(get_last_error_code(), 1);

  ListPairInstrumentPortQuantity_destroy(handle);
}
TEST_F(ListPairInstrumentPortQuantityTest, IndexNull) {
  auto handle = ListPairInstrumentPortQuantity_create_empty();

  set_last_error(0, nullptr);

  ListPairInstrumentPortQuantity_index(handle, nullptr);

  EXPECT_EQ(get_last_error_code(), 1);

  ListPairInstrumentPortQuantity_destroy(handle);
}
TEST_F(ListPairInstrumentPortQuantityTest, CreateNullArray) {
  set_last_error(0, nullptr);

  ListPairInstrumentPortQuantity_create(nullptr, 2);

  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ListPairInstrumentPortQuantityTest, At) {
  PairInstrumentPortQuantityHandle arr[2] = {sh1, sh2};

  auto handle = ListPairInstrumentPortQuantity_create(arr, 2);

  auto at0 = ListPairInstrumentPortQuantity_at(handle, 0);

  auto at1 = ListPairInstrumentPortQuantity_at(handle, 1);

  destroy_pair(at0);
  destroy_pair(at1);

  ListPairInstrumentPortQuantity_destroy(handle);

  set_last_error(0, nullptr);
  ListPairInstrumentPortQuantity_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
