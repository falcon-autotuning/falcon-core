#include <falcon_core/generic/ListPairConnectionPairQuantityQuantity_c_api.h>
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
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_destroy(nullptr),
               std::invalid_argument);
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
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_create(nullptr, 2),
               std::invalid_argument);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, SizeEmptyInvalid) {
  auto handle = ListPairConnectionPairQuantityQuantity_create_empty();
  EXPECT_EQ(ListPairConnectionPairQuantityQuantity_size(handle), 0);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_size(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, EmptyInvalid) {
  auto handle = ListPairConnectionPairQuantityQuantity_create_empty();
  EXPECT_TRUE(ListPairConnectionPairQuantityQuantity_empty(handle));
  ListPairConnectionPairQuantityQuantity_destroy(handle);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_empty(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, EraseAtClear) {
  auto handle = ListPairConnectionPairQuantityQuantity_fill_value(2, sh1);
  ListPairConnectionPairQuantityQuantity_erase_at(handle, 0);
  EXPECT_EQ(ListPairConnectionPairQuantityQuantity_size(handle), 1);
  ListPairConnectionPairQuantityQuantity_clear(handle);
  EXPECT_TRUE(ListPairConnectionPairQuantityQuantity_empty(handle));
  ListPairConnectionPairQuantityQuantity_destroy(handle);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_erase_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_clear(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, PushBackContainsIndex) {
  auto handle = ListPairConnectionPairQuantityQuantity_create_empty();
  ListPairConnectionPairQuantityQuantity_push_back(handle, sh1);
  EXPECT_TRUE(ListPairConnectionPairQuantityQuantity_contains(handle, sh1));
  EXPECT_EQ(ListPairConnectionPairQuantityQuantity_index(handle, sh1), 0);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_contains(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_index(nullptr, sh1),
               std::invalid_argument);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, ItemsAt) {
  PairConnectionPairQuantityQuantityHandle arr[2] = {sh1, sh2};
  auto handle = ListPairConnectionPairQuantityQuantity_create(arr, 2);
  PairConnectionPairQuantityQuantityHandle out[2];
  EXPECT_EQ(ListPairConnectionPairQuantityQuantity_items(handle, out, 2), 2);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_items(nullptr, out, 2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_at(nullptr, 0),
               std::invalid_argument);
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
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_not_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_not_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_intersection(h1, nullptr),
               std::invalid_argument);
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
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, FillValueNull) {
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_fill_value(3, nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, PushBackNull) {
  auto handle = ListPairConnectionPairQuantityQuantity_create_empty();
  EXPECT_THROW(
      ListPairConnectionPairQuantityQuantity_push_back(handle, nullptr),
      std::invalid_argument);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, ContainsNull) {
  auto handle = ListPairConnectionPairQuantityQuantity_create_empty();
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_contains(handle, nullptr),
               std::invalid_argument);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, IndexNull) {
  auto handle = ListPairConnectionPairQuantityQuantity_create_empty();
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_index(handle, nullptr),
               std::invalid_argument);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, CreateNullArray) {
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_create(nullptr, 2),
               std::invalid_argument);
}

TEST_F(ListPairConnectionPairQuantityQuantityTest, At) {
  PairConnectionPairQuantityQuantityHandle arr[2] = {sh1, sh2};
  auto handle = ListPairConnectionPairQuantityQuantity_create(arr, 2);
  auto at0    = ListPairConnectionPairQuantityQuantity_at(handle, 0);
  auto at1    = ListPairConnectionPairQuantityQuantity_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairConnectionPairQuantityQuantity_destroy(handle);
  EXPECT_THROW(ListPairConnectionPairQuantityQuantity_at(nullptr, 0),
               std::invalid_argument);
}
