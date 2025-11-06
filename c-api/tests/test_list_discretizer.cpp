#include <falcon_core/generic/ListDiscretizer_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"

class ListDiscretizerTest : public ::testing::Test {
 protected:
  void destroy_string(DiscretizerHandle sh) { Discretizer_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<DiscretizerHandle> created_strings;
  DiscretizerHandle              track_quantity(const DiscretizerHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(Discretizer_create_cartesian_discretizer(0.1));
    sh2 = track_quantity(Discretizer_create_cartesian_discretizer(0.1));
  }
  DiscretizerHandle sh1;
  DiscretizerHandle sh2;
};

TEST_F(ListDiscretizerTest, CreateEmpty) {
  auto handle = ListDiscretizer_create_empty();
  EXPECT_TRUE(ListDiscretizer_empty(handle));
  EXPECT_EQ(ListDiscretizer_size(handle), 0);
  ListDiscretizer_destroy(handle);
  EXPECT_THROW(ListDiscretizer_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListDiscretizerTest, FillValue) {
  auto handle = ListDiscretizer_fill_value(3, sh1);
  EXPECT_EQ(ListDiscretizer_size(handle), 3);
  ListDiscretizer_destroy(handle);
}

TEST_F(ListDiscretizerTest, CreateFromArray) {
  DiscretizerHandle     arr[2] = {sh1, sh2};
  ListDiscretizerHandle handle = ListDiscretizer_create(arr, 2);
  EXPECT_EQ(ListDiscretizer_size(handle), 2);
  EXPECT_THROW(ListDiscretizer_create(nullptr, 2), std::invalid_argument);
  ListDiscretizer_destroy(handle);
}

TEST_F(ListDiscretizerTest, SizeEmptyInvalid) {
  auto handle = ListDiscretizer_create_empty();
  EXPECT_EQ(ListDiscretizer_size(handle), 0);
  ListDiscretizer_destroy(handle);
  EXPECT_THROW(ListDiscretizer_size(nullptr), std::invalid_argument);
}

TEST_F(ListDiscretizerTest, EmptyInvalid) {
  auto handle = ListDiscretizer_create_empty();
  EXPECT_TRUE(ListDiscretizer_empty(handle));
  ListDiscretizer_destroy(handle);
  EXPECT_THROW(ListDiscretizer_empty(nullptr), std::invalid_argument);
}

TEST_F(ListDiscretizerTest, EraseAtClear) {
  auto handle = ListDiscretizer_fill_value(2, sh1);
  ListDiscretizer_erase_at(handle, 0);
  EXPECT_EQ(ListDiscretizer_size(handle), 1);
  ListDiscretizer_clear(handle);
  EXPECT_TRUE(ListDiscretizer_empty(handle));
  ListDiscretizer_destroy(handle);
  EXPECT_THROW(ListDiscretizer_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListDiscretizer_clear(nullptr), std::invalid_argument);
}

TEST_F(ListDiscretizerTest, PushBackContainsIndex) {
  auto handle = ListDiscretizer_create_empty();
  ListDiscretizer_push_back(handle, sh1);
  EXPECT_TRUE(ListDiscretizer_contains(handle, sh1));
  EXPECT_EQ(ListDiscretizer_index(handle, sh1), 0);
  ListDiscretizer_destroy(handle);
  EXPECT_THROW(ListDiscretizer_push_back(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListDiscretizer_contains(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListDiscretizer_index(nullptr, sh1), std::invalid_argument);
}

TEST_F(ListDiscretizerTest, ItemsAt) {
  DiscretizerHandle arr[2] = {sh1, sh2};
  auto              handle = ListDiscretizer_create(arr, 2);
  DiscretizerHandle out[2];
  EXPECT_EQ(ListDiscretizer_items(handle, out, 2), 2);
  ListDiscretizer_destroy(handle);
  EXPECT_THROW(ListDiscretizer_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListDiscretizer_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListDiscretizer_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListDiscretizerTest, EqualNotEqualIntersection) {
  DiscretizerHandle arr[2] = {sh1, sh2};
  auto              h1     = ListDiscretizer_create(arr, 2);
  auto              h2     = ListDiscretizer_create(arr, 2);
  EXPECT_TRUE(ListDiscretizer_equal(h1, h2));
  EXPECT_FALSE(ListDiscretizer_not_equal(h1, h2));
  auto h3 = ListDiscretizer_intersection(h1, h2);
  EXPECT_EQ(ListDiscretizer_size(h3), 2);
  ListDiscretizer_destroy(h1);
  ListDiscretizer_destroy(h2);
  ListDiscretizer_destroy(h3);
  EXPECT_THROW(ListDiscretizer_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListDiscretizer_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListDiscretizer_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListDiscretizer_not_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListDiscretizer_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListDiscretizer_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListDiscretizerTest, ToJsonFromJson) {
  DiscretizerHandle arr[1]  = {sh1};
  auto              handle  = ListDiscretizer_create(arr, 1);
  auto              json    = ListDiscretizer_to_json_string(handle);
  auto              handle2 = ListDiscretizer_from_json_string(json);
  EXPECT_TRUE(ListDiscretizer_equal(handle, handle2));
  ListDiscretizer_destroy(handle);
  ListDiscretizer_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListDiscretizer_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ListDiscretizer_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListDiscretizerTest, FillValueNull) {
  EXPECT_THROW(ListDiscretizer_fill_value(3, nullptr), std::invalid_argument);
}

TEST_F(ListDiscretizerTest, PushBackNull) {
  auto handle = ListDiscretizer_create_empty();
  EXPECT_THROW(ListDiscretizer_push_back(handle, nullptr),
               std::invalid_argument);
  ListDiscretizer_destroy(handle);
}

TEST_F(ListDiscretizerTest, ContainsNull) {
  auto handle = ListDiscretizer_create_empty();
  EXPECT_THROW(ListDiscretizer_contains(handle, nullptr),
               std::invalid_argument);
  ListDiscretizer_destroy(handle);
}

TEST_F(ListDiscretizerTest, IndexNull) {
  auto handle = ListDiscretizer_create_empty();
  EXPECT_THROW(ListDiscretizer_index(handle, nullptr), std::invalid_argument);
  ListDiscretizer_destroy(handle);
}

TEST_F(ListDiscretizerTest, CreateNullArray) {
  EXPECT_THROW(ListDiscretizer_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListDiscretizerTest, At) {
  DiscretizerHandle arr[2] = {sh1, sh2};
  auto              handle = ListDiscretizer_create(arr, 2);
  auto              at0    = ListDiscretizer_at(handle, 0);
  auto              at1    = ListDiscretizer_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListDiscretizer_destroy(handle);
  EXPECT_THROW(ListDiscretizer_at(nullptr, 0), std::invalid_argument);
}
