#include <falcon_core/generic/ListDotGateWithNeighbors_c_api.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/geometries/DotGateWithNeighbors_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"

class ListDotGateWithNeighborsTest : public ::testing::Test {
 protected:
  void destroy_string(DotGateWithNeighborsHandle sh) {
    DotGateWithNeighbors_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<DotGateWithNeighborsHandle> created_strings;
  DotGateWithNeighborsHandle              track_quantity(
                   const DotGateWithNeighborsHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(DotGateWithNeighbors_create_plungergatewithneighbors(
        String_wrap("G1"),
        Connection_create_barrier_gate(String_wrap("B1")),
        Connection_create_barrier_gate(String_wrap("B2"))));
    sh2 = track_quantity(DotGateWithNeighbors_create_plungergatewithneighbors(
        String_wrap("G2"),
        Connection_create_barrier_gate(String_wrap("B3")),
        Connection_create_barrier_gate(String_wrap("B4"))));
  }
  DotGateWithNeighborsHandle sh1;
  DotGateWithNeighborsHandle sh2;
};

TEST_F(ListDotGateWithNeighborsTest, CreateEmpty) {
  auto handle = ListDotGateWithNeighbors_create_empty();
  EXPECT_TRUE(ListDotGateWithNeighbors_empty(handle));
  EXPECT_EQ(ListDotGateWithNeighbors_size(handle), 0);
  ListDotGateWithNeighbors_destroy(handle);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDotGateWithNeighborsTest, FillValue) {
  auto handle = ListDotGateWithNeighbors_fill_value(3, sh1);
  EXPECT_EQ(ListDotGateWithNeighbors_size(handle), 3);
  ListDotGateWithNeighbors_destroy(handle);
}

TEST_F(ListDotGateWithNeighborsTest, CreateFromArray) {
  DotGateWithNeighborsHandle     arr[2] = {sh1, sh2};
  ListDotGateWithNeighborsHandle handle =
      ListDotGateWithNeighbors_create(arr, 2);
  EXPECT_EQ(ListDotGateWithNeighbors_size(handle), 2);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListDotGateWithNeighbors_destroy(handle);
}

TEST_F(ListDotGateWithNeighborsTest, SizeEmptyInvalid) {
  auto handle = ListDotGateWithNeighbors_create_empty();
  EXPECT_EQ(ListDotGateWithNeighbors_size(handle), 0);
  ListDotGateWithNeighbors_destroy(handle);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDotGateWithNeighborsTest, EmptyInvalid) {
  auto handle = ListDotGateWithNeighbors_create_empty();
  EXPECT_TRUE(ListDotGateWithNeighbors_empty(handle));
  ListDotGateWithNeighbors_destroy(handle);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDotGateWithNeighborsTest, EraseAtClear) {
  auto handle = ListDotGateWithNeighbors_fill_value(2, sh1);
  ListDotGateWithNeighbors_erase_at(handle, 0);
  EXPECT_EQ(ListDotGateWithNeighbors_size(handle), 1);
  ListDotGateWithNeighbors_clear(handle);
  EXPECT_TRUE(ListDotGateWithNeighbors_empty(handle));
  ListDotGateWithNeighbors_destroy(handle);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDotGateWithNeighborsTest, PushBackContainsIndex) {
  auto handle = ListDotGateWithNeighbors_create_empty();
  ListDotGateWithNeighbors_push_back(handle, sh1);
  EXPECT_TRUE(ListDotGateWithNeighbors_contains(handle, sh1));
  EXPECT_EQ(ListDotGateWithNeighbors_index(handle, sh1), 0);
  ListDotGateWithNeighbors_destroy(handle);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDotGateWithNeighborsTest, ItemsAt) {
  DotGateWithNeighborsHandle arr[2] = {sh1, sh2};
  auto                       handle = ListDotGateWithNeighbors_create(arr, 2);
  DotGateWithNeighborsHandle out[2];
  EXPECT_EQ(ListDotGateWithNeighbors_items(handle, out, 2), 2);
  ListDotGateWithNeighbors_destroy(handle);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDotGateWithNeighborsTest, EqualNotEqualIntersection) {
  DotGateWithNeighborsHandle arr[2] = {sh1, sh2};
  auto                       h1     = ListDotGateWithNeighbors_create(arr, 2);
  auto                       h2     = ListDotGateWithNeighbors_create(arr, 2);
  EXPECT_TRUE(ListDotGateWithNeighbors_equal(h1, h2));
  EXPECT_FALSE(ListDotGateWithNeighbors_not_equal(h1, h2));
  auto h3 = ListDotGateWithNeighbors_intersection(h1, h2);
  EXPECT_EQ(ListDotGateWithNeighbors_size(h3), 2);
  ListDotGateWithNeighbors_destroy(h1);
  ListDotGateWithNeighbors_destroy(h2);
  ListDotGateWithNeighbors_destroy(h3);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDotGateWithNeighborsTest, ToJsonFromJson) {
  DotGateWithNeighborsHandle arr[1] = {sh1};
  auto                       handle = ListDotGateWithNeighbors_create(arr, 1);
  auto json    = ListDotGateWithNeighbors_to_json_string(handle);
  auto handle2 = ListDotGateWithNeighbors_from_json_string(json);
  EXPECT_TRUE(ListDotGateWithNeighbors_equal(handle, handle2));
  ListDotGateWithNeighbors_destroy(handle);
  ListDotGateWithNeighbors_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDotGateWithNeighborsTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDotGateWithNeighborsTest, PushBackNull) {
  auto handle = ListDotGateWithNeighbors_create_empty();
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListDotGateWithNeighbors_destroy(handle);
}

TEST_F(ListDotGateWithNeighborsTest, ContainsNull) {
  auto handle = ListDotGateWithNeighbors_create_empty();
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListDotGateWithNeighbors_destroy(handle);
}

TEST_F(ListDotGateWithNeighborsTest, IndexNull) {
  auto handle = ListDotGateWithNeighbors_create_empty();
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListDotGateWithNeighbors_destroy(handle);
}

TEST_F(ListDotGateWithNeighborsTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDotGateWithNeighborsTest, At) {
  DotGateWithNeighborsHandle arr[2] = {sh1, sh2};
  auto                       handle = ListDotGateWithNeighbors_create(arr, 2);
  auto                       at0    = ListDotGateWithNeighbors_at(handle, 0);
  auto                       at1    = ListDotGateWithNeighbors_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListDotGateWithNeighbors_destroy(handle);
  set_last_error(0, nullptr);
  ListDotGateWithNeighbors_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
