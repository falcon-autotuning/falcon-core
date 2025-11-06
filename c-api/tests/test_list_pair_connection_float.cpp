#include <falcon_core/generic/ListPairConnectionFloat_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/physics/device_structures/Connection_c_api.h"

class ListPairConnectionFloatTest : public ::testing::Test {
 protected:
  void destroy_string(PairConnectionFloatHandle sh) {
    PairConnectionFloat_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairConnectionFloatHandle> created_strings;
  PairConnectionFloatHandle track_quantity(const PairConnectionFloatHandle& s) {
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
    sh1 = track_quantity(PairConnectionFloat_create(
        Connection_create_plunger_gate(String_wrap("Connection1")), 1.0));
    sh2 = track_quantity(PairConnectionFloat_create(
        Connection_create_plunger_gate(String_wrap("Connection2")), 2.0));
  }
  PairConnectionFloatHandle sh1;
  PairConnectionFloatHandle sh2;
};

TEST_F(ListPairConnectionFloatTest, CreateEmpty) {
  auto handle = ListPairConnectionFloat_create_empty();
  EXPECT_TRUE(ListPairConnectionFloat_empty(handle));
  EXPECT_EQ(ListPairConnectionFloat_size(handle), 0);
  ListPairConnectionFloat_destroy(handle);
  EXPECT_THROW(ListPairConnectionFloat_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListPairConnectionFloatTest, FillValue) {
  auto handle = ListPairConnectionFloat_fill_value(3, sh1);
  EXPECT_EQ(ListPairConnectionFloat_size(handle), 3);
  ListPairConnectionFloat_destroy(handle);
}

TEST_F(ListPairConnectionFloatTest, CreateFromArray) {
  PairConnectionFloatHandle     arr[2] = {sh1, sh2};
  ListPairConnectionFloatHandle handle = ListPairConnectionFloat_create(arr, 2);
  EXPECT_EQ(ListPairConnectionFloat_size(handle), 2);
  EXPECT_THROW(ListPairConnectionFloat_create(nullptr, 2),
               std::invalid_argument);
  ListPairConnectionFloat_destroy(handle);
}

TEST_F(ListPairConnectionFloatTest, SizeEmptyInvalid) {
  auto handle = ListPairConnectionFloat_create_empty();
  EXPECT_EQ(ListPairConnectionFloat_size(handle), 0);
  ListPairConnectionFloat_destroy(handle);
  EXPECT_THROW(ListPairConnectionFloat_size(nullptr), std::invalid_argument);
}

TEST_F(ListPairConnectionFloatTest, EmptyInvalid) {
  auto handle = ListPairConnectionFloat_create_empty();
  EXPECT_TRUE(ListPairConnectionFloat_empty(handle));
  ListPairConnectionFloat_destroy(handle);
  EXPECT_THROW(ListPairConnectionFloat_empty(nullptr), std::invalid_argument);
}

TEST_F(ListPairConnectionFloatTest, EraseAtClear) {
  auto handle = ListPairConnectionFloat_fill_value(2, sh1);
  ListPairConnectionFloat_erase_at(handle, 0);
  EXPECT_EQ(ListPairConnectionFloat_size(handle), 1);
  ListPairConnectionFloat_clear(handle);
  EXPECT_TRUE(ListPairConnectionFloat_empty(handle));
  ListPairConnectionFloat_destroy(handle);
  EXPECT_THROW(ListPairConnectionFloat_erase_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionFloat_clear(nullptr), std::invalid_argument);
}

TEST_F(ListPairConnectionFloatTest, PushBackContainsIndex) {
  auto handle = ListPairConnectionFloat_create_empty();
  ListPairConnectionFloat_push_back(handle, sh1);
  EXPECT_TRUE(ListPairConnectionFloat_contains(handle, sh1));
  EXPECT_EQ(ListPairConnectionFloat_index(handle, sh1), 0);
  ListPairConnectionFloat_destroy(handle);
  EXPECT_THROW(ListPairConnectionFloat_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionFloat_contains(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionFloat_index(nullptr, sh1),
               std::invalid_argument);
}

TEST_F(ListPairConnectionFloatTest, ItemsAt) {
  PairConnectionFloatHandle arr[2] = {sh1, sh2};
  auto                      handle = ListPairConnectionFloat_create(arr, 2);
  PairConnectionFloatHandle out[2];
  EXPECT_EQ(ListPairConnectionFloat_items(handle, out, 2), 2);
  ListPairConnectionFloat_destroy(handle);
  EXPECT_THROW(ListPairConnectionFloat_items(nullptr, out, 2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionFloat_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionFloat_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListPairConnectionFloatTest, EqualNotEqualIntersection) {
  PairConnectionFloatHandle arr[2] = {sh1, sh2};
  auto                      h1     = ListPairConnectionFloat_create(arr, 2);
  auto                      h2     = ListPairConnectionFloat_create(arr, 2);
  EXPECT_TRUE(ListPairConnectionFloat_equal(h1, h2));
  EXPECT_FALSE(ListPairConnectionFloat_not_equal(h1, h2));
  auto h3 = ListPairConnectionFloat_intersection(h1, h2);
  EXPECT_EQ(ListPairConnectionFloat_size(h3), 2);
  ListPairConnectionFloat_destroy(h1);
  ListPairConnectionFloat_destroy(h2);
  ListPairConnectionFloat_destroy(h3);
  EXPECT_THROW(ListPairConnectionFloat_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionFloat_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionFloat_not_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionFloat_not_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionFloat_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionFloat_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionFloatTest, ToJsonFromJson) {
  PairConnectionFloatHandle arr[1] = {sh1};
  auto                      handle = ListPairConnectionFloat_create(arr, 1);
  auto json    = ListPairConnectionFloat_to_json_string(handle);
  auto handle2 = ListPairConnectionFloat_from_json_string(json);
  EXPECT_TRUE(ListPairConnectionFloat_equal(handle, handle2));
  ListPairConnectionFloat_destroy(handle);
  ListPairConnectionFloat_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListPairConnectionFloat_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionFloat_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionFloatTest, FillValueNull) {
  EXPECT_THROW(ListPairConnectionFloat_fill_value(3, nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionFloatTest, PushBackNull) {
  auto handle = ListPairConnectionFloat_create_empty();
  EXPECT_THROW(ListPairConnectionFloat_push_back(handle, nullptr),
               std::invalid_argument);
  ListPairConnectionFloat_destroy(handle);
}

TEST_F(ListPairConnectionFloatTest, ContainsNull) {
  auto handle = ListPairConnectionFloat_create_empty();
  EXPECT_THROW(ListPairConnectionFloat_contains(handle, nullptr),
               std::invalid_argument);
  ListPairConnectionFloat_destroy(handle);
}

TEST_F(ListPairConnectionFloatTest, IndexNull) {
  auto handle = ListPairConnectionFloat_create_empty();
  EXPECT_THROW(ListPairConnectionFloat_index(handle, nullptr),
               std::invalid_argument);
  ListPairConnectionFloat_destroy(handle);
}

TEST_F(ListPairConnectionFloatTest, CreateNullArray) {
  EXPECT_THROW(ListPairConnectionFloat_create(nullptr, 2),
               std::invalid_argument);
}

TEST_F(ListPairConnectionFloatTest, At) {
  PairConnectionFloatHandle arr[2] = {sh1, sh2};
  auto                      handle = ListPairConnectionFloat_create(arr, 2);
  auto                      at0    = ListPairConnectionFloat_at(handle, 0);
  auto                      at1    = ListPairConnectionFloat_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairConnectionFloat_destroy(handle);
  EXPECT_THROW(ListPairConnectionFloat_at(nullptr, 0), std::invalid_argument);
}
