#include <falcon_core/generic/ListFArrayDouble_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListFArrayDoubleTest : public ::testing::Test {
 protected:
  void destroy_string(FArrayDoubleHandle sh) { FArrayDouble_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<FArrayDoubleHandle> created_strings;
  FArrayDoubleHandle              track_quantity(const FArrayDoubleHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    double arr1[3]  = {1.0, 5.0, 8.0};
    size_t shape[1] = {3};
    double arr2[3]  = {2.0, 3.0, 4.0};
    sh1             = track_quantity(FArrayDouble_from_data(arr1, shape, 1));
    sh2             = track_quantity(FArrayDouble_from_data(arr2, shape, 1));
  }
  FArrayDoubleHandle sh1;
  FArrayDoubleHandle sh2;
};

TEST_F(ListFArrayDoubleTest, CreateEmpty) {
  auto handle = ListFArrayDouble_create_empty();
  EXPECT_TRUE(ListFArrayDouble_empty(handle));
  EXPECT_EQ(ListFArrayDouble_size(handle), 0);
  ListFArrayDouble_destroy(handle);
  EXPECT_THROW(ListFArrayDouble_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListFArrayDoubleTest, FillValue) {
  auto handle = ListFArrayDouble_fill_value(3, sh1);
  EXPECT_EQ(ListFArrayDouble_size(handle), 3);
  ListFArrayDouble_destroy(handle);
}

TEST_F(ListFArrayDoubleTest, CreateFromArray) {
  FArrayDoubleHandle     arr[2] = {sh1, sh2};
  ListFArrayDoubleHandle handle = ListFArrayDouble_create(arr, 2);
  EXPECT_EQ(ListFArrayDouble_size(handle), 2);
  EXPECT_THROW(ListFArrayDouble_create(nullptr, 2), std::invalid_argument);
  ListFArrayDouble_destroy(handle);
}

TEST_F(ListFArrayDoubleTest, SizeEmptyInvalid) {
  auto handle = ListFArrayDouble_create_empty();
  EXPECT_EQ(ListFArrayDouble_size(handle), 0);
  ListFArrayDouble_destroy(handle);
  EXPECT_THROW(ListFArrayDouble_size(nullptr), std::invalid_argument);
}

TEST_F(ListFArrayDoubleTest, EmptyInvalid) {
  auto handle = ListFArrayDouble_create_empty();
  EXPECT_TRUE(ListFArrayDouble_empty(handle));
  ListFArrayDouble_destroy(handle);
  EXPECT_THROW(ListFArrayDouble_empty(nullptr), std::invalid_argument);
}

TEST_F(ListFArrayDoubleTest, EraseAtClear) {
  auto handle = ListFArrayDouble_fill_value(2, sh1);
  ListFArrayDouble_erase_at(handle, 0);
  EXPECT_EQ(ListFArrayDouble_size(handle), 1);
  ListFArrayDouble_clear(handle);
  EXPECT_TRUE(ListFArrayDouble_empty(handle));
  ListFArrayDouble_destroy(handle);
  EXPECT_THROW(ListFArrayDouble_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListFArrayDouble_clear(nullptr), std::invalid_argument);
}

TEST_F(ListFArrayDoubleTest, PushBackContainsIndex) {
  auto handle = ListFArrayDouble_create_empty();
  ListFArrayDouble_push_back(handle, sh1);
  EXPECT_TRUE(ListFArrayDouble_contains(handle, sh1));
  EXPECT_EQ(ListFArrayDouble_index(handle, sh1), 0);
  ListFArrayDouble_destroy(handle);
  EXPECT_THROW(ListFArrayDouble_push_back(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListFArrayDouble_contains(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListFArrayDouble_index(nullptr, sh1), std::invalid_argument);
}

TEST_F(ListFArrayDoubleTest, ItemsAt) {
  FArrayDoubleHandle arr[2] = {sh1, sh2};
  auto               handle = ListFArrayDouble_create(arr, 2);
  FArrayDoubleHandle out[2];
  EXPECT_EQ(ListFArrayDouble_items(handle, out, 2), 2);
  ListFArrayDouble_destroy(handle);
  EXPECT_THROW(ListFArrayDouble_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListFArrayDouble_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListFArrayDouble_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListFArrayDoubleTest, EqualNotEqualIntersection) {
  FArrayDoubleHandle arr[2] = {sh1, sh2};
  auto               h1     = ListFArrayDouble_create(arr, 2);
  auto               h2     = ListFArrayDouble_create(arr, 2);
  EXPECT_TRUE(ListFArrayDouble_equal(h1, h2));
  EXPECT_FALSE(ListFArrayDouble_not_equal(h1, h2));
  auto h3 = ListFArrayDouble_intersection(h1, h2);
  EXPECT_EQ(ListFArrayDouble_size(h3), 2);
  ListFArrayDouble_destroy(h1);
  ListFArrayDouble_destroy(h2);
  ListFArrayDouble_destroy(h3);
  EXPECT_THROW(ListFArrayDouble_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListFArrayDouble_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListFArrayDouble_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListFArrayDouble_not_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListFArrayDouble_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListFArrayDouble_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListFArrayDoubleTest, ToJsonFromJson) {
  FArrayDoubleHandle arr[1]  = {sh1};
  auto               handle  = ListFArrayDouble_create(arr, 1);
  auto               json    = ListFArrayDouble_to_json_string(handle);
  auto               handle2 = ListFArrayDouble_from_json_string(json);
  EXPECT_TRUE(ListFArrayDouble_equal(handle, handle2));
  ListFArrayDouble_destroy(handle);
  ListFArrayDouble_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListFArrayDouble_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ListFArrayDouble_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListFArrayDoubleTest, FillValueNull) {
  EXPECT_THROW(ListFArrayDouble_fill_value(3, nullptr), std::invalid_argument);
}

TEST_F(ListFArrayDoubleTest, PushBackNull) {
  auto handle = ListFArrayDouble_create_empty();
  EXPECT_THROW(ListFArrayDouble_push_back(handle, nullptr),
               std::invalid_argument);
  ListFArrayDouble_destroy(handle);
}

TEST_F(ListFArrayDoubleTest, ContainsNull) {
  auto handle = ListFArrayDouble_create_empty();
  EXPECT_THROW(ListFArrayDouble_contains(handle, nullptr),
               std::invalid_argument);
  ListFArrayDouble_destroy(handle);
}

TEST_F(ListFArrayDoubleTest, IndexNull) {
  auto handle = ListFArrayDouble_create_empty();
  EXPECT_THROW(ListFArrayDouble_index(handle, nullptr), std::invalid_argument);
  ListFArrayDouble_destroy(handle);
}

TEST_F(ListFArrayDoubleTest, CreateNullArray) {
  EXPECT_THROW(ListFArrayDouble_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListFArrayDoubleTest, At) {
  FArrayDoubleHandle arr[2] = {sh1, sh2};
  auto               handle = ListFArrayDouble_create(arr, 2);
  auto               at0    = ListFArrayDouble_at(handle, 0);
  auto               at1    = ListFArrayDouble_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListFArrayDouble_destroy(handle);
  EXPECT_THROW(ListFArrayDouble_at(nullptr, 0), std::invalid_argument);
}
