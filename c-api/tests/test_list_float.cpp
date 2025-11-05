#include <falcon_core/generic/ListFloat_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <string>
#include <vector>

class ListFloatTest : public ::testing::Test {
 protected:
  StringHandle make_json(const std::string& s) {
    return String_create(s.c_str(), s.size());
  }
  void destroy_string(StringHandle sh) { String_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<StringHandle> created_strings;
  StringHandle              track_string(const std::string& s) {
    auto sh = make_json(s);
    created_strings.push_back(sh);
    return sh;
  }
};

TEST_F(ListFloatTest, CreateEmpty) {
  auto handle = ListFloat_create_empty();
  EXPECT_TRUE(ListFloat_empty(handle));
  EXPECT_EQ(ListFloat_size(handle), 0);
  ListFloat_destroy(handle);
  EXPECT_THROW(ListFloat_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListFloatTest, FillValue) {
  auto handle = ListFloat_fill_value(3, true);
  EXPECT_EQ(ListFloat_size(handle), 3);
  ListFloat_destroy(handle);
}

TEST_F(ListFloatTest, Allocate) {
  auto handle = ListFloat_allocate(5);
  EXPECT_EQ(ListFloat_size(handle), 5);
  ListFloat_destroy(handle);
}

TEST_F(ListFloatTest, CreateFromArray) {
  float           arr[2] = {true, false};
  ListFloatHandle handle = ListFloat_create(arr, 2);
  EXPECT_EQ(ListFloat_size(handle), 2);
  ListFloat_destroy(handle);
  EXPECT_THROW(ListFloat_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListFloatTest, SizeEmptyInvalid) {
  auto handle = ListFloat_create_empty();
  EXPECT_EQ(ListFloat_size(handle), 0);
  ListFloat_destroy(handle);
  EXPECT_THROW(ListFloat_size(nullptr), std::invalid_argument);
}

TEST_F(ListFloatTest, EmptyInvalid) {
  auto handle = ListFloat_create_empty();
  EXPECT_TRUE(ListFloat_empty(handle));
  ListFloat_destroy(handle);
  EXPECT_THROW(ListFloat_empty(nullptr), std::invalid_argument);
}

TEST_F(ListFloatTest, EraseAtClear) {
  auto handle = ListFloat_fill_value(2, true);
  ListFloat_erase_at(handle, 0);
  EXPECT_EQ(ListFloat_size(handle), 1);
  ListFloat_clear(handle);
  EXPECT_TRUE(ListFloat_empty(handle));
  ListFloat_destroy(handle);
  EXPECT_THROW(ListFloat_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListFloat_clear(nullptr), std::invalid_argument);
}

TEST_F(ListFloatTest, PushBackContainsIndex) {
  auto handle = ListFloat_create_empty();
  ListFloat_push_back(handle, true);
  EXPECT_TRUE(ListFloat_contains(handle, true));
  EXPECT_EQ(ListFloat_index(handle, true), 0);
  ListFloat_destroy(handle);
  EXPECT_THROW(ListFloat_push_back(nullptr, true), std::invalid_argument);
  EXPECT_THROW(ListFloat_contains(nullptr, true), std::invalid_argument);
  EXPECT_THROW(ListFloat_index(nullptr, true), std::invalid_argument);
}

TEST_F(ListFloatTest, ItemsAt) {
  float arr[2] = {true, false};
  auto  handle = ListFloat_create(arr, 2);
  float out[2];
  EXPECT_EQ(ListFloat_items(handle, out, 2), 2);
  EXPECT_EQ(ListFloat_at(handle, 0), true);
  EXPECT_EQ(ListFloat_at(handle, 1), false);
  ListFloat_destroy(handle);
  EXPECT_THROW(ListFloat_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListFloat_items(handle, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(ListFloat_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListFloatTest, EqualNotEqualFloatersection) {
  float arr[2] = {true, false};
  auto  h1     = ListFloat_create(arr, 2);
  auto  h2     = ListFloat_create(arr, 2);
  EXPECT_TRUE(ListFloat_equal(h1, h2));
  EXPECT_FALSE(ListFloat_not_equal(h1, h2));
  auto h3 = ListFloat_intersection(h1, h2);
  EXPECT_EQ(ListFloat_size(h3), 2);
  ListFloat_destroy(h1);
  ListFloat_destroy(h2);
  ListFloat_destroy(h3);
  EXPECT_THROW(ListFloat_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListFloat_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListFloat_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListFloat_not_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListFloat_intersection(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListFloat_intersection(h1, nullptr), std::invalid_argument);
}

TEST_F(ListFloatTest, ToJsonFromJson) {
  float arr[1]  = {1.0};
  auto  handle  = ListFloat_create(arr, 1);
  auto  json    = ListFloat_to_json_string(handle);
  auto  handle2 = ListFloat_from_json_string(json);
  EXPECT_TRUE(ListFloat_equal(handle, handle2));
  ListFloat_destroy(handle);
  ListFloat_destroy(handle2);
  destroy_string(json);
  EXPECT_THROW(ListFloat_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ListFloat_from_json_string(nullptr), std::invalid_argument);
}
