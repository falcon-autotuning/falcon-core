#include <falcon_core/generic/ListPairConnectionDouble_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/physics/device_structures/Connection_c_api.h"

class ListPairConnectionDoubleTest : public ::testing::Test {
 protected:
  void destroy_string(PairConnectionDoubleHandle sh) {
    PairConnectionDouble_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairConnectionDoubleHandle> created_strings;
  PairConnectionDoubleHandle              track_quantity(
                   const PairConnectionDoubleHandle& s) {
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
    sh1 = track_quantity(PairConnectionDouble_create(
        Connection_create_plunger_gate(String_wrap("Connection1")), 1.0));
    sh2 = track_quantity(PairConnectionDouble_create(
        Connection_create_plunger_gate(String_wrap("Connection2")), 2.0));
  }
  PairConnectionDoubleHandle sh1;
  PairConnectionDoubleHandle sh2;
};

TEST_F(ListPairConnectionDoubleTest, CreateEmpty) {
  auto handle = ListPairConnectionDouble_create_empty();
  EXPECT_TRUE(ListPairConnectionDouble_empty(handle));
  EXPECT_EQ(ListPairConnectionDouble_size(handle), 0);
  ListPairConnectionDouble_destroy(handle);
  EXPECT_THROW(ListPairConnectionDouble_destroy(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionDoubleTest, FillValue) {
  auto handle = ListPairConnectionDouble_fill_value(3, sh1);
  EXPECT_EQ(ListPairConnectionDouble_size(handle), 3);
  ListPairConnectionDouble_destroy(handle);
}

TEST_F(ListPairConnectionDoubleTest, CreateFromArray) {
  PairConnectionDoubleHandle     arr[2] = {sh1, sh2};
  ListPairConnectionDoubleHandle handle =
      ListPairConnectionDouble_create(arr, 2);
  EXPECT_EQ(ListPairConnectionDouble_size(handle), 2);
  EXPECT_THROW(ListPairConnectionDouble_create(nullptr, 2),
               std::invalid_argument);
  ListPairConnectionDouble_destroy(handle);
}

TEST_F(ListPairConnectionDoubleTest, SizeEmptyInvalid) {
  auto handle = ListPairConnectionDouble_create_empty();
  EXPECT_EQ(ListPairConnectionDouble_size(handle), 0);
  ListPairConnectionDouble_destroy(handle);
  EXPECT_THROW(ListPairConnectionDouble_size(nullptr), std::invalid_argument);
}

TEST_F(ListPairConnectionDoubleTest, EmptyInvalid) {
  auto handle = ListPairConnectionDouble_create_empty();
  EXPECT_TRUE(ListPairConnectionDouble_empty(handle));
  ListPairConnectionDouble_destroy(handle);
  EXPECT_THROW(ListPairConnectionDouble_empty(nullptr), std::invalid_argument);
}

TEST_F(ListPairConnectionDoubleTest, EraseAtClear) {
  auto handle = ListPairConnectionDouble_fill_value(2, sh1);
  ListPairConnectionDouble_erase_at(handle, 0);
  EXPECT_EQ(ListPairConnectionDouble_size(handle), 1);
  ListPairConnectionDouble_clear(handle);
  EXPECT_TRUE(ListPairConnectionDouble_empty(handle));
  ListPairConnectionDouble_destroy(handle);
  EXPECT_THROW(ListPairConnectionDouble_erase_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionDouble_clear(nullptr), std::invalid_argument);
}

TEST_F(ListPairConnectionDoubleTest, PushBackContainsIndex) {
  auto handle = ListPairConnectionDouble_create_empty();
  ListPairConnectionDouble_push_back(handle, sh1);
  EXPECT_TRUE(ListPairConnectionDouble_contains(handle, sh1));
  EXPECT_EQ(ListPairConnectionDouble_index(handle, sh1), 0);
  ListPairConnectionDouble_destroy(handle);
  EXPECT_THROW(ListPairConnectionDouble_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionDouble_contains(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionDouble_index(nullptr, sh1),
               std::invalid_argument);
}

TEST_F(ListPairConnectionDoubleTest, ItemsAt) {
  PairConnectionDoubleHandle arr[2] = {sh1, sh2};
  auto                       handle = ListPairConnectionDouble_create(arr, 2);
  PairConnectionDoubleHandle out[2];
  EXPECT_EQ(ListPairConnectionDouble_items(handle, out, 2), 2);
  ListPairConnectionDouble_destroy(handle);
  EXPECT_THROW(ListPairConnectionDouble_items(nullptr, out, 2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionDouble_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionDouble_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListPairConnectionDoubleTest, EqualNotEqualIntersection) {
  PairConnectionDoubleHandle arr[2] = {sh1, sh2};
  auto                       h1     = ListPairConnectionDouble_create(arr, 2);
  auto                       h2     = ListPairConnectionDouble_create(arr, 2);
  EXPECT_TRUE(ListPairConnectionDouble_equal(h1, h2));
  EXPECT_FALSE(ListPairConnectionDouble_not_equal(h1, h2));
  auto h3 = ListPairConnectionDouble_intersection(h1, h2);
  EXPECT_EQ(ListPairConnectionDouble_size(h3), 2);
  ListPairConnectionDouble_destroy(h1);
  ListPairConnectionDouble_destroy(h2);
  ListPairConnectionDouble_destroy(h3);
  EXPECT_THROW(ListPairConnectionDouble_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionDouble_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionDouble_not_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionDouble_not_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionDouble_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionDouble_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionDoubleTest, ToJsonFromJson) {
  PairConnectionDoubleHandle arr[1] = {sh1};
  auto                       handle = ListPairConnectionDouble_create(arr, 1);
  auto json    = ListPairConnectionDouble_to_json_string(handle);
  auto handle2 = ListPairConnectionDouble_from_json_string(json);
  EXPECT_TRUE(ListPairConnectionDouble_equal(handle, handle2));
  ListPairConnectionDouble_destroy(handle);
  ListPairConnectionDouble_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListPairConnectionDouble_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairConnectionDouble_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionDoubleTest, FillValueNull) {
  EXPECT_THROW(ListPairConnectionDouble_fill_value(3, nullptr),
               std::invalid_argument);
}

TEST_F(ListPairConnectionDoubleTest, PushBackNull) {
  auto handle = ListPairConnectionDouble_create_empty();
  EXPECT_THROW(ListPairConnectionDouble_push_back(handle, nullptr),
               std::invalid_argument);
  ListPairConnectionDouble_destroy(handle);
}

TEST_F(ListPairConnectionDoubleTest, ContainsNull) {
  auto handle = ListPairConnectionDouble_create_empty();
  EXPECT_THROW(ListPairConnectionDouble_contains(handle, nullptr),
               std::invalid_argument);
  ListPairConnectionDouble_destroy(handle);
}

TEST_F(ListPairConnectionDoubleTest, IndexNull) {
  auto handle = ListPairConnectionDouble_create_empty();
  EXPECT_THROW(ListPairConnectionDouble_index(handle, nullptr),
               std::invalid_argument);
  ListPairConnectionDouble_destroy(handle);
}

TEST_F(ListPairConnectionDoubleTest, CreateNullArray) {
  EXPECT_THROW(ListPairConnectionDouble_create(nullptr, 2),
               std::invalid_argument);
}

TEST_F(ListPairConnectionDoubleTest, At) {
  PairConnectionDoubleHandle arr[2] = {sh1, sh2};
  auto                       handle = ListPairConnectionDouble_create(arr, 2);
  auto                       at0    = ListPairConnectionDouble_at(handle, 0);
  auto                       at1    = ListPairConnectionDouble_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairConnectionDouble_destroy(handle);
  EXPECT_THROW(ListPairConnectionDouble_at(nullptr, 0), std::invalid_argument);
}
