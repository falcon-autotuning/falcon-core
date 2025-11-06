#include <falcon_core/generic/ListGname_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListGnameTest : public ::testing::Test {
 protected:
  void destroy_string(GnameHandle sh) { Gname_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<GnameHandle> created_strings;
  GnameHandle              track_quantity(const GnameHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(Gname_create(String_wrap("name1")));
    sh2 = track_quantity(Gname_create(String_wrap("name2")));
  }
  GnameHandle sh1;
  GnameHandle sh2;
};

TEST_F(ListGnameTest, CreateEmpty) {
  auto handle = ListGname_create_empty();
  EXPECT_TRUE(ListGname_empty(handle));
  EXPECT_EQ(ListGname_size(handle), 0);
  ListGname_destroy(handle);
  EXPECT_THROW(ListGname_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListGnameTest, FillValue) {
  auto handle = ListGname_fill_value(3, sh1);
  EXPECT_EQ(ListGname_size(handle), 3);
  ListGname_destroy(handle);
}

TEST_F(ListGnameTest, CreateFromArray) {
  GnameHandle     arr[2] = {sh1, sh2};
  ListGnameHandle handle = ListGname_create(arr, 2);
  EXPECT_EQ(ListGname_size(handle), 2);
  EXPECT_THROW(ListGname_create(nullptr, 2), std::invalid_argument);
  ListGname_destroy(handle);
}

TEST_F(ListGnameTest, SizeEmptyInvalid) {
  auto handle = ListGname_create_empty();
  EXPECT_EQ(ListGname_size(handle), 0);
  ListGname_destroy(handle);
  EXPECT_THROW(ListGname_size(nullptr), std::invalid_argument);
}

TEST_F(ListGnameTest, EmptyInvalid) {
  auto handle = ListGname_create_empty();
  EXPECT_TRUE(ListGname_empty(handle));
  ListGname_destroy(handle);
  EXPECT_THROW(ListGname_empty(nullptr), std::invalid_argument);
}

TEST_F(ListGnameTest, EraseAtClear) {
  auto handle = ListGname_fill_value(2, sh1);
  ListGname_erase_at(handle, 0);
  EXPECT_EQ(ListGname_size(handle), 1);
  ListGname_clear(handle);
  EXPECT_TRUE(ListGname_empty(handle));
  ListGname_destroy(handle);
  EXPECT_THROW(ListGname_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListGname_clear(nullptr), std::invalid_argument);
}

TEST_F(ListGnameTest, PushBackContainsIndex) {
  auto handle = ListGname_create_empty();
  ListGname_push_back(handle, sh1);
  EXPECT_TRUE(ListGname_contains(handle, sh1));
  EXPECT_EQ(ListGname_index(handle, sh1), 0);
  ListGname_destroy(handle);
  EXPECT_THROW(ListGname_push_back(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListGname_contains(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListGname_index(nullptr, sh1), std::invalid_argument);
}

TEST_F(ListGnameTest, ItemsAt) {
  GnameHandle arr[2] = {sh1, sh2};
  auto        handle = ListGname_create(arr, 2);
  GnameHandle out[2];
  EXPECT_EQ(ListGname_items(handle, out, 2), 2);
  ListGname_destroy(handle);
  EXPECT_THROW(ListGname_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListGname_items(handle, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(ListGname_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListGnameTest, EqualNotEqualIntersection) {
  GnameHandle arr[2] = {sh1, sh2};
  auto        h1     = ListGname_create(arr, 2);
  auto        h2     = ListGname_create(arr, 2);
  EXPECT_TRUE(ListGname_equal(h1, h2));
  EXPECT_FALSE(ListGname_not_equal(h1, h2));
  auto h3 = ListGname_intersection(h1, h2);
  EXPECT_EQ(ListGname_size(h3), 2);
  ListGname_destroy(h1);
  ListGname_destroy(h2);
  ListGname_destroy(h3);
  EXPECT_THROW(ListGname_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListGname_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListGname_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListGname_not_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListGname_intersection(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListGname_intersection(h1, nullptr), std::invalid_argument);
}

TEST_F(ListGnameTest, ToJsonFromJson) {
  GnameHandle arr[1]  = {sh1};
  auto        handle  = ListGname_create(arr, 1);
  auto        json    = ListGname_to_json_string(handle);
  auto        handle2 = ListGname_from_json_string(json);
  EXPECT_TRUE(ListGname_equal(handle, handle2));
  ListGname_destroy(handle);
  ListGname_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListGname_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ListGname_from_json_string(nullptr), std::invalid_argument);
}

TEST_F(ListGnameTest, FillValueNull) {
  EXPECT_THROW(ListGname_fill_value(3, nullptr), std::invalid_argument);
}

TEST_F(ListGnameTest, PushBackNull) {
  auto handle = ListGname_create_empty();
  EXPECT_THROW(ListGname_push_back(handle, nullptr), std::invalid_argument);
  ListGname_destroy(handle);
}

TEST_F(ListGnameTest, ContainsNull) {
  auto handle = ListGname_create_empty();
  EXPECT_THROW(ListGname_contains(handle, nullptr), std::invalid_argument);
  ListGname_destroy(handle);
}

TEST_F(ListGnameTest, IndexNull) {
  auto handle = ListGname_create_empty();
  EXPECT_THROW(ListGname_index(handle, nullptr), std::invalid_argument);
  ListGname_destroy(handle);
}

TEST_F(ListGnameTest, CreateNullArray) {
  EXPECT_THROW(ListGname_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListGnameTest, At) {
  GnameHandle arr[2] = {sh1, sh2};
  auto        handle = ListGname_create(arr, 2);
  auto        at0    = ListGname_at(handle, 0);
  auto        at1    = ListGname_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListGname_destroy(handle);
  EXPECT_THROW(ListGname_at(nullptr, 0), std::invalid_argument);
}
