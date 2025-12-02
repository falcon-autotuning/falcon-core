#include <falcon_core/generic/ListPairConnectionPairQuantityQuantity_c_api.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/physics/device_structures/Connection_c_api.h"

class ListPairConnectionPairQuantityQuantityTest : public ::testing::Test {
 protected:
  void destroy_string(PairConnectionPairQuantityQuantityHandle sh) {
    PairConnectionPairQuantityQuantity_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairConnectionPairQuantityQuantityHandle> created_strings;
  PairConnectionPairQuantityQuantityHandle              track_quantity(
                   const PairConnectionPairQuantityQuantityHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(PairConnectionPairQuantityQuantity_create(
        Connection_create_plunger_gate(String_wrap("Connection1")),
        PairQuantityQuantity_create(
            Quantity_create(1.0, SymbolUnit_create_volt()),
            Quantity_create(0.5, SymbolUnit_create_ampere()))));
    sh2 = track_quantity(PairConnectionPairQuantityQuantity_create(
        Connection_create_plunger_gate(String_wrap("Connection2")),
        PairQuantityQuantity_create(
            Quantity_create(2.0, SymbolUnit_create_volt()),
            Quantity_create(1.5, SymbolUnit_create_ampere()))));
  }
  PairConnectionPairQuantityQuantityHandle sh1;
  PairConnectionPairQuantityQuantityHandle sh2;
};

TEST_F(ListPairConnectionPairQuantityQuantityTest, CreateEmpty) {
  auto handle = ListPairConnectionPairQuantityQuantity_create_empty();
  EXPECT_TRUE(ListPairConnectionPairQuantityQuantity_empty(handle));
  EXPECT_EQ(ListPairConnectionPairQuantityQuantity_size(handle), 0);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, FillValue) {
  auto handle = ListPairConnectionPairQuantityQuantity_fill_value(3, sh1);
  EXPECT_EQ(ListPairConnectionPairQuantityQuantity_size(handle), 3);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, CreateFromArray) {
  PairConnectionPairQuantityQuantityHandle     arr[2] = {sh1, sh2};
  ListPairConnectionPairQuantityQuantityHandle handle =
      ListPairConnectionPairQuantityQuantity_create(arr, 2);
  EXPECT_EQ(ListPairConnectionPairQuantityQuantity_size(handle), 2);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, SizeEmptyInvalid) {
  auto handle = ListPairConnectionPairQuantityQuantity_create_empty();
  EXPECT_EQ(ListPairConnectionPairQuantityQuantity_size(handle), 0);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, EmptyInvalid) {
  auto handle = ListPairConnectionPairQuantityQuantity_create_empty();
  EXPECT_TRUE(ListPairConnectionPairQuantityQuantity_empty(handle));
  ListPairConnectionPairQuantityQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, EraseAtClear) {
  auto handle = ListPairConnectionPairQuantityQuantity_fill_value(2, sh1);
  ListPairConnectionPairQuantityQuantity_erase_at(handle, 0);
  EXPECT_EQ(ListPairConnectionPairQuantityQuantity_size(handle), 1);
  ListPairConnectionPairQuantityQuantity_clear(handle);
  EXPECT_TRUE(ListPairConnectionPairQuantityQuantity_empty(handle));
  ListPairConnectionPairQuantityQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, PushBackContainsIndex) {
  auto handle = ListPairConnectionPairQuantityQuantity_create_empty();
  ListPairConnectionPairQuantityQuantity_push_back(handle, sh1);
  EXPECT_TRUE(ListPairConnectionPairQuantityQuantity_contains(handle, sh1));
  EXPECT_EQ(ListPairConnectionPairQuantityQuantity_index(handle, sh1), 0);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, ItemsAt) {
  PairConnectionPairQuantityQuantityHandle arr[2] = {sh1, sh2};
  auto handle = ListPairConnectionPairQuantityQuantity_create(arr, 2);
  PairConnectionPairQuantityQuantityHandle out[2];
  EXPECT_EQ(ListPairConnectionPairQuantityQuantity_items(handle, out, 2), 2);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, EqualNotEqualIntersection) {
  PairConnectionPairQuantityQuantityHandle arr[2] = {sh1, sh2};
  auto h1 = ListPairConnectionPairQuantityQuantity_create(arr, 2);
  auto h2 = ListPairConnectionPairQuantityQuantity_create(arr, 2);
  EXPECT_TRUE(ListPairConnectionPairQuantityQuantity_equal(h1, h2));
  EXPECT_FALSE(ListPairConnectionPairQuantityQuantity_not_equal(h1, h2));
  auto h3 = ListPairConnectionPairQuantityQuantity_intersection(h1, h2);
  EXPECT_EQ(ListPairConnectionPairQuantityQuantity_size(h3), 2);
  ListPairConnectionPairQuantityQuantity_destroy(h1);
  ListPairConnectionPairQuantityQuantity_destroy(h2);
  ListPairConnectionPairQuantityQuantity_destroy(h3);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, ToJsonFromJson) {
  PairConnectionPairQuantityQuantityHandle arr[1] = {sh1};
  auto handle  = ListPairConnectionPairQuantityQuantity_create(arr, 1);
  auto json    = ListPairConnectionPairQuantityQuantity_to_json_string(handle);
  auto handle2 = ListPairConnectionPairQuantityQuantity_from_json_string(json);
  EXPECT_TRUE(ListPairConnectionPairQuantityQuantity_equal(handle, handle2));
  ListPairConnectionPairQuantityQuantity_destroy(handle);
  ListPairConnectionPairQuantityQuantity_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, PushBackNull) {
  auto handle = ListPairConnectionPairQuantityQuantity_create_empty();
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, ContainsNull) {
  auto handle = ListPairConnectionPairQuantityQuantity_create_empty();
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, IndexNull) {
  auto handle = ListPairConnectionPairQuantityQuantity_create_empty();
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, At) {
  PairConnectionPairQuantityQuantityHandle arr[2] = {sh1, sh2};
  auto handle = ListPairConnectionPairQuantityQuantity_create(arr, 2);
  auto at0    = ListPairConnectionPairQuantityQuantity_at(handle, 0);
  auto at1    = ListPairConnectionPairQuantityQuantity_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionPairQuantityQuantity_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
