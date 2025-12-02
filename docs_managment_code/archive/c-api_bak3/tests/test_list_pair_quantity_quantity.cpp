#include <falcon_core/generic/ListPairQuantityQuantity_c_api.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class ListPairQuantityQuantityTest : public ::testing::Test {
 protected:
  void destroy_string(PairQuantityQuantityHandle sh) {
    PairQuantityQuantity_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairQuantityQuantityHandle> created_strings;
  PairQuantityQuantityHandle              track_quantity(
                   const PairQuantityQuantityHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(PairQuantityQuantity_create(
        Quantity_create(1.0, SymbolUnit_create_volt()),
        Quantity_create(5.0, SymbolUnit_create_ampere())));
    sh2 = track_quantity(PairQuantityQuantity_create(
        Quantity_create(4.0, SymbolUnit_create_volt()),
        Quantity_create(5.0, SymbolUnit_create_ampere())));
  }
  PairQuantityQuantityHandle sh1;
  PairQuantityQuantityHandle sh2;
};

TEST_F(ListPairQuantityQuantityTest, CreateEmpty) {
  auto handle = ListPairQuantityQuantity_create_empty();
  EXPECT_TRUE(ListPairQuantityQuantity_empty(handle));
  EXPECT_EQ(ListPairQuantityQuantity_size(handle), 0);
  ListPairQuantityQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairQuantityQuantityTest, FillValue) {
  auto handle = ListPairQuantityQuantity_fill_value(3, sh1);
  EXPECT_EQ(ListPairQuantityQuantity_size(handle), 3);
  ListPairQuantityQuantity_destroy(handle);
}

TEST_F(ListPairQuantityQuantityTest, CreateFromArray) {
  PairQuantityQuantityHandle     arr[2] = {sh1, sh2};
  ListPairQuantityQuantityHandle handle =
      ListPairQuantityQuantity_create(arr, 2);
  EXPECT_EQ(ListPairQuantityQuantity_size(handle), 2);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairQuantityQuantity_destroy(handle);
}

TEST_F(ListPairQuantityQuantityTest, SizeEmptyInvalid) {
  auto handle = ListPairQuantityQuantity_create_empty();
  EXPECT_EQ(ListPairQuantityQuantity_size(handle), 0);
  ListPairQuantityQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairQuantityQuantityTest, EmptyInvalid) {
  auto handle = ListPairQuantityQuantity_create_empty();
  EXPECT_TRUE(ListPairQuantityQuantity_empty(handle));
  ListPairQuantityQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairQuantityQuantityTest, EraseAtClear) {
  auto handle = ListPairQuantityQuantity_fill_value(2, sh1);
  ListPairQuantityQuantity_erase_at(handle, 0);
  EXPECT_EQ(ListPairQuantityQuantity_size(handle), 1);
  ListPairQuantityQuantity_clear(handle);
  EXPECT_TRUE(ListPairQuantityQuantity_empty(handle));
  ListPairQuantityQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairQuantityQuantityTest, PushBackContainsIndex) {
  auto handle = ListPairQuantityQuantity_create_empty();
  ListPairQuantityQuantity_push_back(handle, sh1);
  EXPECT_TRUE(ListPairQuantityQuantity_contains(handle, sh1));
  EXPECT_EQ(ListPairQuantityQuantity_index(handle, sh1), 0);
  ListPairQuantityQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairQuantityQuantityTest, ItemsAt) {
  PairQuantityQuantityHandle arr[2] = {sh1, sh2};
  auto                       handle = ListPairQuantityQuantity_create(arr, 2);
  PairQuantityQuantityHandle out[2];
  EXPECT_EQ(ListPairQuantityQuantity_items(handle, out, 2), 2);
  ListPairQuantityQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairQuantityQuantityTest, EqualNotEqualIntersection) {
  PairQuantityQuantityHandle arr[2] = {sh1, sh2};
  auto                       h1     = ListPairQuantityQuantity_create(arr, 2);
  auto                       h2     = ListPairQuantityQuantity_create(arr, 2);
  EXPECT_TRUE(ListPairQuantityQuantity_equal(h1, h2));
  EXPECT_FALSE(ListPairQuantityQuantity_not_equal(h1, h2));
  auto h3 = ListPairQuantityQuantity_intersection(h1, h2);
  EXPECT_EQ(ListPairQuantityQuantity_size(h3), 2);
  ListPairQuantityQuantity_destroy(h1);
  ListPairQuantityQuantity_destroy(h2);
  ListPairQuantityQuantity_destroy(h3);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairQuantityQuantityTest, ToJsonFromJson) {
  PairQuantityQuantityHandle arr[1] = {sh1};
  auto                       handle = ListPairQuantityQuantity_create(arr, 1);
  auto json    = ListPairQuantityQuantity_to_json_string(handle);
  auto handle2 = ListPairQuantityQuantity_from_json_string(json);
  EXPECT_TRUE(ListPairQuantityQuantity_equal(handle, handle2));
  ListPairQuantityQuantity_destroy(handle);
  ListPairQuantityQuantity_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairQuantityQuantityTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairQuantityQuantityTest, PushBackNull) {
  auto handle = ListPairQuantityQuantity_create_empty();
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairQuantityQuantity_destroy(handle);
}

TEST_F(ListPairQuantityQuantityTest, ContainsNull) {
  auto handle = ListPairQuantityQuantity_create_empty();
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairQuantityQuantity_destroy(handle);
}

TEST_F(ListPairQuantityQuantityTest, IndexNull) {
  auto handle = ListPairQuantityQuantity_create_empty();
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairQuantityQuantity_destroy(handle);
}

TEST_F(ListPairQuantityQuantityTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairQuantityQuantityTest, At) {
  PairQuantityQuantityHandle arr[2] = {sh1, sh2};
  auto                       handle = ListPairQuantityQuantity_create(arr, 2);
  auto                       at0    = ListPairQuantityQuantity_at(handle, 0);
  auto                       at1    = ListPairQuantityQuantity_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairQuantityQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairQuantityQuantity_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
