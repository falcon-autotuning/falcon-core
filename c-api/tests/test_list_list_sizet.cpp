#include <falcon_core/generic/ListListSizeT_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListListSizeTTest : public ::testing::Test {
 protected:
  void destroy_string(ListSizeTHandle sh) { ListSizeT_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<ListSizeTHandle> created_strings;
  ListSizeTHandle              track_quantity(const ListSizeTHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    size_t arr1[2] = {1, 2};
    size_t arr2[3] = {3, 4, 5};
    sh1            = track_quantity(ListSizeT_create(arr1, 2));
    sh2            = track_quantity(ListSizeT_create(arr2, 3));
  }
  ListSizeTHandle sh1;
  ListSizeTHandle sh2;
};

TEST_F(ListListSizeTTest, CreateEmpty) {
  auto handle = ListListSizeT_create_empty();
  EXPECT_TRUE(ListListSizeT_empty(handle));
  EXPECT_EQ(ListListSizeT_size(handle), 0);
  ListListSizeT_destroy(handle);
  EXPECT_THROW(ListListSizeT_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListListSizeTTest, FillValue) {
  auto handle = ListListSizeT_fill_value(3, sh1);
  EXPECT_EQ(ListListSizeT_size(handle), 3);
  ListListSizeT_destroy(handle);
}

TEST_F(ListListSizeTTest, CreateFromArray) {
  ListSizeTHandle     arr[2] = {sh1, sh2};
  ListListSizeTHandle handle = ListListSizeT_create(arr, 2);
  EXPECT_EQ(ListListSizeT_size(handle), 2);
  EXPECT_THROW(ListListSizeT_create(nullptr, 2), std::invalid_argument);
  ListListSizeT_destroy(handle);
}

TEST_F(ListListSizeTTest, SizeEmptyInvalid) {
  auto handle = ListListSizeT_create_empty();
  EXPECT_EQ(ListListSizeT_size(handle), 0);
  ListListSizeT_destroy(handle);
  EXPECT_THROW(ListListSizeT_size(nullptr), std::invalid_argument);
}

TEST_F(ListListSizeTTest, EmptyInvalid) {
  auto handle = ListListSizeT_create_empty();
  EXPECT_TRUE(ListListSizeT_empty(handle));
  ListListSizeT_destroy(handle);
  EXPECT_THROW(ListListSizeT_empty(nullptr), std::invalid_argument);
}

TEST_F(ListListSizeTTest, EraseAtClear) {
  auto handle = ListListSizeT_fill_value(2, sh1);
  ListListSizeT_erase_at(handle, 0);
  EXPECT_EQ(ListListSizeT_size(handle), 1);
  ListListSizeT_clear(handle);
  EXPECT_TRUE(ListListSizeT_empty(handle));
  ListListSizeT_destroy(handle);
  EXPECT_THROW(ListListSizeT_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListListSizeT_clear(nullptr), std::invalid_argument);
}

TEST_F(ListListSizeTTest, PushBackContainsIndex) {
  auto handle = ListListSizeT_create_empty();
  ListListSizeT_push_back(handle, sh1);
  EXPECT_TRUE(ListListSizeT_contains(handle, sh1));
  EXPECT_EQ(ListListSizeT_index(handle, sh1), 0);
  ListListSizeT_destroy(handle);
  EXPECT_THROW(ListListSizeT_push_back(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListListSizeT_contains(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListListSizeT_index(nullptr, sh1), std::invalid_argument);
}

TEST_F(ListListSizeTTest, ItemsAt) {
  ListSizeTHandle arr[2] = {sh1, sh2};
  auto            handle = ListListSizeT_create(arr, 2);
  ListSizeTHandle out[2];
  EXPECT_EQ(ListListSizeT_items(handle, out, 2), 2);
  ListListSizeT_destroy(handle);
  EXPECT_THROW(ListListSizeT_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListListSizeT_items(handle, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(ListListSizeT_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListListSizeTTest, EqualNotEqualIntersection) {
  ListSizeTHandle arr[2] = {sh1, sh2};
  auto            h1     = ListListSizeT_create(arr, 2);
  auto            h2     = ListListSizeT_create(arr, 2);
  EXPECT_TRUE(ListListSizeT_equal(h1, h2));
  EXPECT_FALSE(ListListSizeT_not_equal(h1, h2));
  auto h3 = ListListSizeT_intersection(h1, h2);
  EXPECT_EQ(ListListSizeT_size(h3), 2);
  ListListSizeT_destroy(h1);
  ListListSizeT_destroy(h2);
  ListListSizeT_destroy(h3);
  EXPECT_THROW(ListListSizeT_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListListSizeT_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListListSizeT_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListListSizeT_not_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListListSizeT_intersection(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListListSizeT_intersection(h1, nullptr), std::invalid_argument);
}

TEST_F(ListListSizeTTest, ToJsonFromJson) {
  ListSizeTHandle arr[1]  = {sh1};
  auto            handle  = ListListSizeT_create(arr, 1);
  auto            json    = ListListSizeT_to_json_string(handle);
  auto            handle2 = ListListSizeT_from_json_string(json);
  EXPECT_TRUE(ListListSizeT_equal(handle, handle2));
  ListListSizeT_destroy(handle);
  ListListSizeT_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListListSizeT_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ListListSizeT_from_json_string(nullptr), std::invalid_argument);
}

TEST_F(ListListSizeTTest, FillValueNull) {
  EXPECT_THROW(ListListSizeT_fill_value(3, nullptr), std::invalid_argument);
}

TEST_F(ListListSizeTTest, PushBackNull) {
  auto handle = ListListSizeT_create_empty();
  EXPECT_THROW(ListListSizeT_push_back(handle, nullptr), std::invalid_argument);
  ListListSizeT_destroy(handle);
}

TEST_F(ListListSizeTTest, ContainsNull) {
  auto handle = ListListSizeT_create_empty();
  EXPECT_THROW(ListListSizeT_contains(handle, nullptr), std::invalid_argument);
  ListListSizeT_destroy(handle);
}

TEST_F(ListListSizeTTest, IndexNull) {
  auto handle = ListListSizeT_create_empty();
  EXPECT_THROW(ListListSizeT_index(handle, nullptr), std::invalid_argument);
  ListListSizeT_destroy(handle);
}

TEST_F(ListListSizeTTest, CreateNullArray) {
  EXPECT_THROW(ListListSizeT_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListListSizeTTest, At) {
  ListSizeTHandle arr[2] = {sh1, sh2};
  auto            handle = ListListSizeT_create(arr, 2);
  auto            at0    = ListListSizeT_at(handle, 0);
  auto            at1    = ListListSizeT_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListListSizeT_destroy(handle);
  EXPECT_THROW(ListListSizeT_at(nullptr, 0), std::invalid_argument);
}
