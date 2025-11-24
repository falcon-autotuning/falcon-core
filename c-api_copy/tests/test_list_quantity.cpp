#include <falcon_core/generic/ListQuantity_c_api.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListQuantityTest : public ::testing::Test {
 protected:
  void destroy_string(QuantityHandle sh) { Quantity_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<QuantityHandle> created_strings;
  QuantityHandle              track_quantity(const QuantityHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(Quantity_create(1.0, SymbolUnit_create_volt()));
    sh2 = track_quantity(Quantity_create(2.0, SymbolUnit_create_ampere()));
  }
  QuantityHandle sh1;
  QuantityHandle sh2;
};

TEST_F(ListQuantityTest, CreateEmpty) {
  auto handle = ListQuantity_create_empty();
  EXPECT_TRUE(ListQuantity_empty(handle));
  EXPECT_EQ(ListQuantity_size(handle), 0);
  ListQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListQuantity_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListQuantityTest, FillValue) {
  auto handle = ListQuantity_fill_value(3, sh1);
  EXPECT_EQ(ListQuantity_size(handle), 3);
  ListQuantity_destroy(handle);
}

TEST_F(ListQuantityTest, CreateFromArray) {
  QuantityHandle     arr[2] = {sh1, sh2};
  ListQuantityHandle handle = ListQuantity_create(arr, 2);
  EXPECT_EQ(ListQuantity_size(handle), 2);
  set_last_error(0, nullptr);
  ListQuantity_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListQuantity_destroy(handle);
}

TEST_F(ListQuantityTest, SizeEmptyInvalid) {
  auto handle = ListQuantity_create_empty();
  EXPECT_EQ(ListQuantity_size(handle), 0);
  ListQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListQuantity_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListQuantityTest, EmptyInvalid) {
  auto handle = ListQuantity_create_empty();
  EXPECT_TRUE(ListQuantity_empty(handle));
  ListQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListQuantity_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListQuantityTest, EraseAtClear) {
  auto handle = ListQuantity_fill_value(2, sh1);
  ListQuantity_erase_at(handle, 0);
  EXPECT_EQ(ListQuantity_size(handle), 1);
  ListQuantity_clear(handle);
  EXPECT_TRUE(ListQuantity_empty(handle));
  ListQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListQuantity_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListQuantity_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListQuantityTest, PushBackContainsIndex) {
  auto handle = ListQuantity_create_empty();
  ListQuantity_push_back(handle, sh1);
  EXPECT_TRUE(ListQuantity_contains(handle, sh1));
  EXPECT_EQ(ListQuantity_index(handle, sh1), 0);
  ListQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListQuantity_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListQuantity_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListQuantity_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListQuantityTest, ItemsAt) {
  QuantityHandle arr[2] = {sh1, sh2};
  auto           handle = ListQuantity_create(arr, 2);
  QuantityHandle out[2];
  EXPECT_EQ(ListQuantity_items(handle, out, 2), 2);
  ListQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListQuantity_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListQuantity_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListQuantity_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListQuantityTest, EqualNotEqualIntersection) {
  QuantityHandle arr[2] = {sh1, sh2};
  auto           h1     = ListQuantity_create(arr, 2);
  auto           h2     = ListQuantity_create(arr, 2);
  EXPECT_TRUE(ListQuantity_equal(h1, h2));
  EXPECT_FALSE(ListQuantity_not_equal(h1, h2));
  auto h3 = ListQuantity_intersection(h1, h2);
  EXPECT_EQ(ListQuantity_size(h3), 2);
  ListQuantity_destroy(h1);
  ListQuantity_destroy(h2);
  ListQuantity_destroy(h3);
  set_last_error(0, nullptr);
  ListQuantity_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListQuantity_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListQuantity_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListQuantity_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListQuantity_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListQuantity_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListQuantityTest, ToJsonFromJson) {
  QuantityHandle arr[1]  = {sh1};
  auto           handle  = ListQuantity_create(arr, 1);
  auto           json    = ListQuantity_to_json_string(handle);
  auto           handle2 = ListQuantity_from_json_string(json);
  EXPECT_TRUE(ListQuantity_equal(handle, handle2));
  ListQuantity_destroy(handle);
  ListQuantity_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListQuantity_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListQuantity_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListQuantityTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListQuantity_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListQuantityTest, PushBackNull) {
  auto handle = ListQuantity_create_empty();
  set_last_error(0, nullptr);
  ListQuantity_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListQuantity_destroy(handle);
}

TEST_F(ListQuantityTest, ContainsNull) {
  auto handle = ListQuantity_create_empty();
  set_last_error(0, nullptr);
  ListQuantity_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListQuantity_destroy(handle);
}

TEST_F(ListQuantityTest, IndexNull) {
  auto handle = ListQuantity_create_empty();
  set_last_error(0, nullptr);
  ListQuantity_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListQuantity_destroy(handle);
}

TEST_F(ListQuantityTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListQuantity_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListQuantityTest, At) {
  QuantityHandle arr[2] = {sh1, sh2};
  auto           handle = ListQuantity_create(arr, 2);
  auto           at0    = ListQuantity_at(handle, 0);
  auto           at1    = ListQuantity_at(handle, 1);
  EXPECT_EQ(Quantity_value(at0), 1.0);
  EXPECT_EQ(Quantity_value(at1), 2.0);
  destroy_string(at0);
  destroy_string(at1);
  ListQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListQuantity_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
