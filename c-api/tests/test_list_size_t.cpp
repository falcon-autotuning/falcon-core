#include <falcon_core/generic/ListSizeT_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <string>
#include <vector>

class ListSizeTTest : public ::testing::Test {
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

TEST_F(ListSizeTTest, CreateEmpty) {
  auto handle = ListSizeT_create_empty();
  EXPECT_TRUE(ListSizeT_empty(handle));
  EXPECT_EQ(ListSizeT_size(handle), 0);
  ListSizeT_destroy(handle);
  EXPECT_THROW(ListSizeT_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListSizeTTest, FillValue) {
  auto handle = ListSizeT_fill_value(3, true);
  EXPECT_EQ(ListSizeT_size(handle), 3);
  ListSizeT_destroy(handle);
}

TEST_F(ListSizeTTest, Allocate) {
  auto handle = ListSizeT_allocate(5);
  EXPECT_EQ(ListSizeT_size(handle), 5);
  ListSizeT_destroy(handle);
}

TEST_F(ListSizeTTest, CreateFromArray) {
  size_t          arr[2] = {true, false};
  ListSizeTHandle handle = ListSizeT_create(arr, 2);
  EXPECT_EQ(ListSizeT_size(handle), 2);
  ListSizeT_destroy(handle);
  EXPECT_THROW(ListSizeT_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListSizeTTest, SizeEmptyInvalid) {
  auto handle = ListSizeT_create_empty();
  EXPECT_EQ(ListSizeT_size(handle), 0);
  ListSizeT_destroy(handle);
  EXPECT_THROW(ListSizeT_size(nullptr), std::invalid_argument);
}

TEST_F(ListSizeTTest, EmptyInvalid) {
  auto handle = ListSizeT_create_empty();
  EXPECT_TRUE(ListSizeT_empty(handle));
  ListSizeT_destroy(handle);
  EXPECT_THROW(ListSizeT_empty(nullptr), std::invalid_argument);
}

TEST_F(ListSizeTTest, EraseAtClear) {
  auto handle = ListSizeT_fill_value(2, true);
  ListSizeT_erase_at(handle, 0);
  EXPECT_EQ(ListSizeT_size(handle), 1);
  ListSizeT_clear(handle);
  EXPECT_TRUE(ListSizeT_empty(handle));
  ListSizeT_destroy(handle);
  EXPECT_THROW(ListSizeT_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListSizeT_clear(nullptr), std::invalid_argument);
}

TEST_F(ListSizeTTest, PushBackContainsIndex) {
  auto handle = ListSizeT_create_empty();
  ListSizeT_push_back(handle, true);
  EXPECT_TRUE(ListSizeT_contains(handle, true));
  EXPECT_EQ(ListSizeT_index(handle, true), 0);
  ListSizeT_destroy(handle);
  EXPECT_THROW(ListSizeT_push_back(nullptr, true), std::invalid_argument);
  EXPECT_THROW(ListSizeT_contains(nullptr, true), std::invalid_argument);
  EXPECT_THROW(ListSizeT_index(nullptr, true), std::invalid_argument);
}

TEST_F(ListSizeTTest, ItemsAt) {
  size_t arr[2] = {true, false};
  auto   handle = ListSizeT_create(arr, 2);
  size_t out[2];
  EXPECT_EQ(ListSizeT_items(handle, out, 2), 2);
  EXPECT_EQ(ListSizeT_at(handle, 0), true);
  EXPECT_EQ(ListSizeT_at(handle, 1), false);
  ListSizeT_destroy(handle);
  EXPECT_THROW(ListSizeT_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListSizeT_items(handle, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(ListSizeT_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListSizeTTest, EqualNotEqualSizeTersection) {
  size_t arr[2] = {true, false};
  auto   h1     = ListSizeT_create(arr, 2);
  auto   h2     = ListSizeT_create(arr, 2);
  EXPECT_TRUE(ListSizeT_equal(h1, h2));
  EXPECT_FALSE(ListSizeT_not_equal(h1, h2));
  auto h3 = ListSizeT_intersection(h1, h2);
  EXPECT_EQ(ListSizeT_size(h3), 2);
  ListSizeT_destroy(h1);
  ListSizeT_destroy(h2);
  ListSizeT_destroy(h3);
  EXPECT_THROW(ListSizeT_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListSizeT_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListSizeT_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListSizeT_not_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListSizeT_intersection(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListSizeT_intersection(h1, nullptr), std::invalid_argument);
}

TEST_F(ListSizeTTest, ToJsonFromJson) {
  size_t arr[1]  = {1};
  auto   handle  = ListSizeT_create(arr, 1);
  auto   json    = ListSizeT_to_json_string(handle);
  auto   handle2 = ListSizeT_from_json_string(json);
  EXPECT_TRUE(ListSizeT_equal(handle, handle2));
  ListSizeT_destroy(handle);
  ListSizeT_destroy(handle2);
  destroy_string(json);
  EXPECT_THROW(ListSizeT_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ListSizeT_from_json_string(nullptr), std::invalid_argument);
}
