#include <falcon-core/generic/ListImpedance_c_api.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListImpedanceTest : public ::testing::Test {
 protected:
  void destroy_string(ImpedanceHandle sh) { Impedance_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<ImpedanceHandle> created_strings;
  ImpedanceHandle              track_quantity(const ImpedanceHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(Impedance_create(
        Connection_create_barrier_gate(String_wrap("gate1")), 1.0, 2.0));
    sh2 = track_quantity(Impedance_create(
        Connection_create_barrier_gate(String_wrap("gate2")), 1.0, 2.0));
  }
  ImpedanceHandle sh1;
  ImpedanceHandle sh2;
};

TEST_F(ListImpedanceTest, CreateEmpty) {
  auto handle = ListImpedance_create_empty();
  EXPECT_TRUE(ListImpedance_empty(handle));
  EXPECT_EQ(ListImpedance_size(handle), 0);
  ListImpedance_destroy(handle);
  set_last_error(0, nullptr);
  ListImpedance_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListImpedanceTest, FillValue) {
  auto handle = ListImpedance_fill_value(3, sh1);
  EXPECT_EQ(ListImpedance_size(handle), 3);
  ListImpedance_destroy(handle);
}

TEST_F(ListImpedanceTest, CreateFromArray) {
  ImpedanceHandle     arr[2] = {sh1, sh2};
  ListImpedanceHandle handle = ListImpedance_create(arr, 2);
  EXPECT_EQ(ListImpedance_size(handle), 2);
  set_last_error(0, nullptr);
  ListImpedance_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListImpedance_destroy(handle);
}

TEST_F(ListImpedanceTest, SizeEmptyInvalid) {
  auto handle = ListImpedance_create_empty();
  EXPECT_EQ(ListImpedance_size(handle), 0);
  ListImpedance_destroy(handle);
  set_last_error(0, nullptr);
  ListImpedance_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListImpedanceTest, EmptyInvalid) {
  auto handle = ListImpedance_create_empty();
  EXPECT_TRUE(ListImpedance_empty(handle));
  ListImpedance_destroy(handle);
  set_last_error(0, nullptr);
  ListImpedance_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListImpedanceTest, EraseAtClear) {
  auto handle = ListImpedance_fill_value(2, sh1);
  ListImpedance_erase_at(handle, 0);
  EXPECT_EQ(ListImpedance_size(handle), 1);
  ListImpedance_clear(handle);
  EXPECT_TRUE(ListImpedance_empty(handle));
  ListImpedance_destroy(handle);
  set_last_error(0, nullptr);
  ListImpedance_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListImpedance_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListImpedanceTest, PushBackContainsIndex) {
  auto handle = ListImpedance_create_empty();
  ListImpedance_push_back(handle, sh1);
  EXPECT_TRUE(ListImpedance_contains(handle, sh1));
  EXPECT_EQ(ListImpedance_index(handle, sh1), 0);
  ListImpedance_destroy(handle);
  set_last_error(0, nullptr);
  ListImpedance_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListImpedance_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListImpedance_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListImpedanceTest, ItemsAt) {
  ImpedanceHandle arr[2] = {sh1, sh2};
  auto            handle = ListImpedance_create(arr, 2);
  ImpedanceHandle out[2];
  EXPECT_EQ(ListImpedance_items(handle, out, 2), 2);
  ListImpedance_destroy(handle);
  set_last_error(0, nullptr);
  ListImpedance_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListImpedance_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListImpedance_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListImpedanceTest, EqualNotEqualIntersection) {
  ImpedanceHandle arr[2] = {sh1, sh2};
  auto            h1     = ListImpedance_create(arr, 2);
  auto            h2     = ListImpedance_create(arr, 2);
  EXPECT_TRUE(ListImpedance_equal(h1, h2));
  EXPECT_FALSE(ListImpedance_not_equal(h1, h2));
  auto h3 = ListImpedance_intersection(h1, h2);
  EXPECT_EQ(ListImpedance_size(h3), 2);
  ListImpedance_destroy(h1);
  ListImpedance_destroy(h2);
  ListImpedance_destroy(h3);
  set_last_error(0, nullptr);
  ListImpedance_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListImpedance_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListImpedance_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListImpedance_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListImpedance_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListImpedance_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListImpedanceTest, ToJsonFromJson) {
  ImpedanceHandle arr[1]  = {sh1};
  auto            handle  = ListImpedance_create(arr, 1);
  auto            json    = ListImpedance_to_json_string(handle);
  auto            handle2 = ListImpedance_from_json_string(json);
  EXPECT_TRUE(ListImpedance_equal(handle, handle2));
  ListImpedance_destroy(handle);
  ListImpedance_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListImpedance_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListImpedance_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListImpedanceTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListImpedance_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListImpedanceTest, PushBackNull) {
  auto handle = ListImpedance_create_empty();
  set_last_error(0, nullptr);
  ListImpedance_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListImpedance_destroy(handle);
}

TEST_F(ListImpedanceTest, ContainsNull) {
  auto handle = ListImpedance_create_empty();
  set_last_error(0, nullptr);
  ListImpedance_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListImpedance_destroy(handle);
}

TEST_F(ListImpedanceTest, IndexNull) {
  auto handle = ListImpedance_create_empty();
  set_last_error(0, nullptr);
  ListImpedance_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListImpedance_destroy(handle);
}

TEST_F(ListImpedanceTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListImpedance_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListImpedanceTest, At) {
  ImpedanceHandle arr[2] = {sh1, sh2};
  auto            handle = ListImpedance_create(arr, 2);
  auto            at0    = ListImpedance_at(handle, 0);
  auto            at1    = ListImpedance_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListImpedance_destroy(handle);
  set_last_error(0, nullptr);
  ListImpedance_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
