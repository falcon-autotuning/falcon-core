#include <falcon_core/generic/ListBool_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <string>
#include <vector>

class ListBoolTest : public ::testing::Test {
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

TEST_F(ListBoolTest, CreateEmpty) {
  auto handle = ListBool_create_empty();
  EXPECT_TRUE(ListBool_empty(handle));
  EXPECT_EQ(ListBool_size(handle), 0);
  ListBool_destroy(handle);
  EXPECT_THROW(ListBool_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListBoolTest, FillValue) {
  auto handle = ListBool_fill_value(3, true);
  EXPECT_EQ(ListBool_size(handle), 3);
  ListBool_destroy(handle);
}

TEST_F(ListBoolTest, Allocate) {
  auto handle = ListBool_allocate(5);
  EXPECT_EQ(ListBool_size(handle), 5);
  ListBool_destroy(handle);
}

TEST_F(ListBoolTest, CreateFromArray) {
  bool           arr[2] = {true, false};
  ListBoolHandle handle = ListBool_create(arr, 2);
  EXPECT_EQ(ListBool_size(handle), 2);
  ListBool_destroy(handle);
  EXPECT_THROW(ListBool_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListBoolTest, SizeEmptyInvalid) {
  auto handle = ListBool_create_empty();
  EXPECT_EQ(ListBool_size(handle), 0);
  ListBool_destroy(handle);
  EXPECT_THROW(ListBool_size(nullptr), std::invalid_argument);
}

TEST_F(ListBoolTest, EmptyInvalid) {
  auto handle = ListBool_create_empty();
  EXPECT_TRUE(ListBool_empty(handle));
  ListBool_destroy(handle);
  EXPECT_THROW(ListBool_empty(nullptr), std::invalid_argument);
}

TEST_F(ListBoolTest, EraseAtClear) {
  auto handle = ListBool_fill_value(2, true);
  ListBool_erase_at(handle, 0);
  EXPECT_EQ(ListBool_size(handle), 1);
  ListBool_clear(handle);
  EXPECT_TRUE(ListBool_empty(handle));
  ListBool_destroy(handle);
  EXPECT_THROW(ListBool_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListBool_clear(nullptr), std::invalid_argument);
}

TEST_F(ListBoolTest, PushBackContainsIndex) {
  auto handle = ListBool_create_empty();
  ListBool_push_back(handle, true);
  EXPECT_TRUE(ListBool_contains(handle, true));
  EXPECT_EQ(ListBool_index(handle, true), 0);
  ListBool_destroy(handle);
  EXPECT_THROW(ListBool_push_back(nullptr, true), std::invalid_argument);
  EXPECT_THROW(ListBool_contains(nullptr, true), std::invalid_argument);
  EXPECT_THROW(ListBool_index(nullptr, true), std::invalid_argument);
}

TEST_F(ListBoolTest, ItemsAt) {
  bool arr[2] = {true, false};
  auto handle = ListBool_create(arr, 2);
  bool out[2];
  EXPECT_EQ(ListBool_items(handle, out, 2), 2);
  EXPECT_EQ(ListBool_at(handle, 0), true);
  EXPECT_EQ(ListBool_at(handle, 1), false);
  ListBool_destroy(handle);
  EXPECT_THROW(ListBool_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListBool_items(handle, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(ListBool_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListBoolTest, EqualNotEqualIntersection) {
  bool arr[2] = {true, false};
  auto h1     = ListBool_create(arr, 2);
  auto h2     = ListBool_create(arr, 2);
  EXPECT_TRUE(ListBool_equal(h1, h2));
  EXPECT_FALSE(ListBool_not_equal(h1, h2));
  auto h3 = ListBool_intersection(h1, h2);
  EXPECT_EQ(ListBool_size(h3), 2);
  ListBool_destroy(h1);
  ListBool_destroy(h2);
  ListBool_destroy(h3);
  EXPECT_THROW(ListBool_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListBool_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListBool_intersection(nullptr, h2), std::invalid_argument);
}

TEST_F(ListBoolTest, ToJsonFromJson) {
  bool arr[1]  = {true};
  auto handle  = ListBool_create(arr, 1);
  auto json    = ListBool_to_json_string(handle);
  auto handle2 = ListBool_from_json_string(json);
  EXPECT_TRUE(ListBool_equal(handle, handle2));
  ListBool_destroy(handle);
  ListBool_destroy(handle2);
  destroy_string(json);
  EXPECT_THROW(ListBool_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ListBool_from_json_string(nullptr), std::invalid_argument);
}
