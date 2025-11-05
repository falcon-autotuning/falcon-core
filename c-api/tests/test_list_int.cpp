#include <falcon_core/generic/ListInt_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <string>
#include <vector>

class ListIntTest : public ::testing::Test {
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

TEST_F(ListIntTest, CreateEmpty) {
  auto handle = ListInt_create_empty();
  EXPECT_TRUE(ListInt_empty(handle));
  EXPECT_EQ(ListInt_size(handle), 0);
  ListInt_destroy(handle);
  EXPECT_THROW(ListInt_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListIntTest, FillValue) {
  auto handle = ListInt_fill_value(3, true);
  EXPECT_EQ(ListInt_size(handle), 3);
  ListInt_destroy(handle);
}

TEST_F(ListIntTest, Allocate) {
  auto handle = ListInt_allocate(5);
  EXPECT_EQ(ListInt_size(handle), 5);
  ListInt_destroy(handle);
}

TEST_F(ListIntTest, CreateFromArray) {
  int           arr[2] = {true, false};
  ListIntHandle handle = ListInt_create(arr, 2);
  EXPECT_EQ(ListInt_size(handle), 2);
  ListInt_destroy(handle);
  EXPECT_THROW(ListInt_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListIntTest, SizeEmptyInvalid) {
  auto handle = ListInt_create_empty();
  EXPECT_EQ(ListInt_size(handle), 0);
  ListInt_destroy(handle);
  EXPECT_THROW(ListInt_size(nullptr), std::invalid_argument);
}

TEST_F(ListIntTest, EmptyInvalid) {
  auto handle = ListInt_create_empty();
  EXPECT_TRUE(ListInt_empty(handle));
  ListInt_destroy(handle);
  EXPECT_THROW(ListInt_empty(nullptr), std::invalid_argument);
}

TEST_F(ListIntTest, EraseAtClear) {
  auto handle = ListInt_fill_value(2, true);
  ListInt_erase_at(handle, 0);
  EXPECT_EQ(ListInt_size(handle), 1);
  ListInt_clear(handle);
  EXPECT_TRUE(ListInt_empty(handle));
  ListInt_destroy(handle);
  EXPECT_THROW(ListInt_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListInt_clear(nullptr), std::invalid_argument);
}

TEST_F(ListIntTest, PushBackContainsIndex) {
  auto handle = ListInt_create_empty();
  ListInt_push_back(handle, true);
  EXPECT_TRUE(ListInt_contains(handle, true));
  EXPECT_EQ(ListInt_index(handle, true), 0);
  ListInt_destroy(handle);
  EXPECT_THROW(ListInt_push_back(nullptr, true), std::invalid_argument);
  EXPECT_THROW(ListInt_contains(nullptr, true), std::invalid_argument);
  EXPECT_THROW(ListInt_index(nullptr, true), std::invalid_argument);
}

TEST_F(ListIntTest, ItemsAt) {
  int  arr[2] = {true, false};
  auto handle = ListInt_create(arr, 2);
  int  out[2];
  EXPECT_EQ(ListInt_items(handle, out, 2), 2);
  EXPECT_EQ(ListInt_at(handle, 0), true);
  EXPECT_EQ(ListInt_at(handle, 1), false);
  ListInt_destroy(handle);
  EXPECT_THROW(ListInt_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListInt_items(handle, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(ListInt_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListIntTest, EqualNotEqualIntersection) {
  int  arr[2] = {true, false};
  auto h1     = ListInt_create(arr, 2);
  auto h2     = ListInt_create(arr, 2);
  EXPECT_TRUE(ListInt_equal(h1, h2));
  EXPECT_FALSE(ListInt_not_equal(h1, h2));
  auto h3 = ListInt_intersection(h1, h2);
  EXPECT_EQ(ListInt_size(h3), 2);
  ListInt_destroy(h1);
  ListInt_destroy(h2);
  ListInt_destroy(h3);
  EXPECT_THROW(ListInt_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListInt_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListInt_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListInt_not_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListInt_intersection(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListInt_intersection(h1, nullptr), std::invalid_argument);
}

TEST_F(ListIntTest, ToJsonFromJson) {
  int  arr[1]  = {1};
  auto handle  = ListInt_create(arr, 1);
  auto json    = ListInt_to_json_string(handle);
  auto handle2 = ListInt_from_json_string(json);
  EXPECT_TRUE(ListInt_equal(handle, handle2));
  ListInt_destroy(handle);
  ListInt_destroy(handle2);
  destroy_string(json);
  EXPECT_THROW(ListInt_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ListInt_from_json_string(nullptr), std::invalid_argument);
}
