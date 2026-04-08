#include <falcon-core/generic/ListPairConnectionQuantity_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"

class ListPairConnectionQuantityTest : public ::testing::Test {
 protected:
  void destroy_string(PairConnectionQuantityHandle sh) {
    PairConnectionQuantity_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairConnectionQuantityHandle> created_strings;
  PairConnectionQuantityHandle              track_quantity(
                   const PairConnectionQuantityHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(PairConnectionQuantity_create(
        Connection_create_plunger_gate(String_wrap("Connection1")),
        Quantity_create(1.0, SymbolUnit_create_volt())));
    sh2 = track_quantity(PairConnectionQuantity_create(
        Connection_create_plunger_gate(String_wrap("Connection2")),
        Quantity_create(2.0, SymbolUnit_create_volt())));
  }
  PairConnectionQuantityHandle sh1;
  PairConnectionQuantityHandle sh2;
};

TEST_F(ListPairConnectionQuantityTest, CreateEmpty) {
  auto handle = ListPairConnectionQuantity_create_empty();
  EXPECT_TRUE(ListPairConnectionQuantity_empty(handle));
  EXPECT_EQ(ListPairConnectionQuantity_size(handle), 0);
  ListPairConnectionQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionQuantityTest, FillValue) {
  auto handle = ListPairConnectionQuantity_fill_value(3, sh1);
  EXPECT_EQ(ListPairConnectionQuantity_size(handle), 3);
  ListPairConnectionQuantity_destroy(handle);
}

TEST_F(ListPairConnectionQuantityTest, CreateFromArray) {
  PairConnectionQuantityHandle     arr[2] = {sh1, sh2};
  ListPairConnectionQuantityHandle handle =
      ListPairConnectionQuantity_create(arr, 2);
  EXPECT_EQ(ListPairConnectionQuantity_size(handle), 2);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairConnectionQuantity_destroy(handle);
}

TEST_F(ListPairConnectionQuantityTest, SizeEmptyInvalid) {
  auto handle = ListPairConnectionQuantity_create_empty();
  EXPECT_EQ(ListPairConnectionQuantity_size(handle), 0);
  ListPairConnectionQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionQuantityTest, EmptyInvalid) {
  auto handle = ListPairConnectionQuantity_create_empty();
  EXPECT_TRUE(ListPairConnectionQuantity_empty(handle));
  ListPairConnectionQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionQuantityTest, EraseAtClear) {
  auto handle = ListPairConnectionQuantity_fill_value(2, sh1);
  ListPairConnectionQuantity_erase_at(handle, 0);
  EXPECT_EQ(ListPairConnectionQuantity_size(handle), 1);
  ListPairConnectionQuantity_clear(handle);
  EXPECT_TRUE(ListPairConnectionQuantity_empty(handle));
  ListPairConnectionQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionQuantityTest, PushBackContainsIndex) {
  auto handle = ListPairConnectionQuantity_create_empty();
  ListPairConnectionQuantity_push_back(handle, sh1);
  EXPECT_TRUE(ListPairConnectionQuantity_contains(handle, sh1));
  EXPECT_EQ(ListPairConnectionQuantity_index(handle, sh1), 0);
  ListPairConnectionQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionQuantityTest, ItemsAt) {
  PairConnectionQuantityHandle arr[2] = {sh1, sh2};
  auto handle = ListPairConnectionQuantity_create(arr, 2);
  PairConnectionQuantityHandle out[2];
  EXPECT_EQ(ListPairConnectionQuantity_items(handle, out, 2), 2);
  ListPairConnectionQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionQuantityTest, EqualNotEqualIntersection) {
  PairConnectionQuantityHandle arr[2] = {sh1, sh2};
  auto                         h1 = ListPairConnectionQuantity_create(arr, 2);
  auto                         h2 = ListPairConnectionQuantity_create(arr, 2);
  EXPECT_TRUE(ListPairConnectionQuantity_equal(h1, h2));
  EXPECT_FALSE(ListPairConnectionQuantity_not_equal(h1, h2));
  auto h3 = ListPairConnectionQuantity_intersection(h1, h2);
  EXPECT_EQ(ListPairConnectionQuantity_size(h3), 2);
  ListPairConnectionQuantity_destroy(h1);
  ListPairConnectionQuantity_destroy(h2);
  ListPairConnectionQuantity_destroy(h3);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionQuantityTest, ToJsonFromJson) {
  PairConnectionQuantityHandle arr[1] = {sh1};
  auto handle  = ListPairConnectionQuantity_create(arr, 1);
  auto json    = ListPairConnectionQuantity_to_json_string(handle);
  auto handle2 = ListPairConnectionQuantity_from_json_string(json);
  EXPECT_TRUE(ListPairConnectionQuantity_equal(handle, handle2));
  ListPairConnectionQuantity_destroy(handle);
  ListPairConnectionQuantity_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionQuantityTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionQuantityTest, PushBackNull) {
  auto handle = ListPairConnectionQuantity_create_empty();
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairConnectionQuantity_destroy(handle);
}

TEST_F(ListPairConnectionQuantityTest, ContainsNull) {
  auto handle = ListPairConnectionQuantity_create_empty();
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairConnectionQuantity_destroy(handle);
}

TEST_F(ListPairConnectionQuantityTest, IndexNull) {
  auto handle = ListPairConnectionQuantity_create_empty();
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairConnectionQuantity_destroy(handle);
}

TEST_F(ListPairConnectionQuantityTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionQuantityTest, At) {
  PairConnectionQuantityHandle arr[2] = {sh1, sh2};
  auto handle = ListPairConnectionQuantity_create(arr, 2);
  auto at0    = ListPairConnectionQuantity_at(handle, 0);
  auto at1    = ListPairConnectionQuantity_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairConnectionQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionQuantity_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
