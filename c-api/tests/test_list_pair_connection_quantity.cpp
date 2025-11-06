#include <falcon_core/generic/ListPairConnectionQuantity_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/physics/device_structures/Connection_c_api.h"

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
    ConnectionHandle arr[2] = {
        Connection_create_plunger_gate(String_wrap("gate1")),
        Connection_create_barrier_gate(String_wrap("gate2"))};
    ConnectionHandle arr2[2] = {
        Connection_create_reservoir_gate(String_wrap("gate3")),
        Connection_create_screening_gate(String_wrap("gate4"))};
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
  EXPECT_THROW(ListPairConnectionQuantity_destroy(nullptr),
               std::invalid_argument);
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
  EXPECT_THROW(ListPairConnectionQuantity_create(nullptr, 2),
               std::invalid_argument);
  ListPairConnectionQuantity_destroy(handle);
}

TEST_F(ListPairConnectionQuantityTest, SizeEmptyInvalid) {
  auto handle = ListPairConnectionQuantity_create_empty();
  EXPECT_EQ(ListPairConnectionQuantity_size(handle), 0);
  ListPairConnectionQuantity_destroy(handle);
  EXPECT_THROW(ListPairConnectionQuantity_size(nullptr), std::invalid_argument);
}

TEST_F(ListPairConnectionQuantityTest, EmptyInvalid) {
  auto handle = ListPairConnectionQuantity_create_empty();
  EXPECT_TRUE(ListPairConnectionQuantity_empty(handle));
  ListPairConnectionQuantity_destroy(handle);
  EXPECT_THROW(ListPairConnectionQuantity_empty(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionQuantityTest, EraseAtClear) {
  auto handle = ListPairConnectionQuantity_fill_value(2, sh1);
  ListPairConnectionQuantity_erase_at(handle, 0);
  EXPECT_EQ(ListPairConnectionQuantity_size(handle), 1);
  ListPairConnectionQuantity_clear(handle);
  EXPECT_TRUE(ListPairConnectionQuantity_empty(handle));
  ListPairConnectionQuantity_destroy(handle);
  EXPECT_THROW(ListPairConnectionQuantity_erase_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionQuantity_clear(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionQuantityTest, PushBackContainsIndex) {
  auto handle = ListPairConnectionQuantity_create_empty();
  ListPairConnectionQuantity_push_back(handle, sh1);
  EXPECT_TRUE(ListPairConnectionQuantity_contains(handle, sh1));
  EXPECT_EQ(ListPairConnectionQuantity_index(handle, sh1), 0);
  ListPairConnectionQuantity_destroy(handle);
  EXPECT_THROW(ListPairConnectionQuantity_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionQuantity_contains(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionQuantity_index(nullptr, sh1),
               std::invalid_argument);
}

TEST_F(ListPairConnectionQuantityTest, ItemsAt) {
  PairConnectionQuantityHandle arr[2] = {sh1, sh2};
  auto handle = ListPairConnectionQuantity_create(arr, 2);
  PairConnectionQuantityHandle out[2];
  EXPECT_EQ(ListPairConnectionQuantity_items(handle, out, 2), 2);
  ListPairConnectionQuantity_destroy(handle);
  EXPECT_THROW(ListPairConnectionQuantity_items(nullptr, out, 2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionQuantity_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionQuantity_at(nullptr, 0),
               std::invalid_argument);
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
  EXPECT_THROW(ListPairConnectionQuantity_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionQuantity_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionQuantity_not_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionQuantity_not_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionQuantity_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionQuantity_intersection(h1, nullptr),
               std::invalid_argument);
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
  EXPECT_THROW(ListPairConnectionQuantity_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionQuantity_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionQuantityTest, FillValueNull) {
  EXPECT_THROW(ListPairConnectionQuantity_fill_value(3, nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionQuantityTest, PushBackNull) {
  auto handle = ListPairConnectionQuantity_create_empty();
  EXPECT_THROW(ListPairConnectionQuantity_push_back(handle, nullptr),
               std::invalid_argument);
  ListPairConnectionQuantity_destroy(handle);
}

TEST_F(ListPairConnectionQuantityTest, ContainsNull) {
  auto handle = ListPairConnectionQuantity_create_empty();
  EXPECT_THROW(ListPairConnectionQuantity_contains(handle, nullptr),
               std::invalid_argument);
  ListPairConnectionQuantity_destroy(handle);
}

TEST_F(ListPairConnectionQuantityTest, IndexNull) {
  auto handle = ListPairConnectionQuantity_create_empty();
  EXPECT_THROW(ListPairConnectionQuantity_index(handle, nullptr),
               std::invalid_argument);
  ListPairConnectionQuantity_destroy(handle);
}

TEST_F(ListPairConnectionQuantityTest, CreateNullArray) {
  EXPECT_THROW(ListPairConnectionQuantity_create(nullptr, 2),
               std::invalid_argument);
}

TEST_F(ListPairConnectionQuantityTest, At) {
  PairConnectionQuantityHandle arr[2] = {sh1, sh2};
  auto handle = ListPairConnectionQuantity_create(arr, 2);
  auto at0    = ListPairConnectionQuantity_at(handle, 0);
  auto at1    = ListPairConnectionQuantity_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairConnectionQuantity_destroy(handle);
  EXPECT_THROW(ListPairConnectionQuantity_at(nullptr, 0),
               std::invalid_argument);
}
