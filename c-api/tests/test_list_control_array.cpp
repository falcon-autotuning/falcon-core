#include <falcon_core/generic/ListControlArray_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListControlArrayTest : public ::testing::Test {
 protected:
  void destroy_string(ControlArrayHandle sh) { ControlArray_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<ControlArrayHandle> created_strings;
  ControlArrayHandle              track_quantity(const ControlArrayHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    double             data1[3] = {1.0, 2.0, 3.0};
    double             data2[3] = {4.0, 5.0, 6.0};
    FArrayDoubleHandle farray1 =
        FArrayDouble_from_data(data1, (size_t[]){3}, 1);
    FArrayDoubleHandle farray2 =
        FArrayDouble_from_data(data2, (size_t[]){3}, 1);
    sh1 = track_quantity(ControlArray_from_farray(farray1));
    sh2 = track_quantity(ControlArray_from_farray(farray2));
  }
  ControlArrayHandle sh1;
  ControlArrayHandle sh2;
};

TEST_F(ListControlArrayTest, CreateEmpty) {
  auto handle = ListControlArray_create_empty();
  EXPECT_TRUE(ListControlArray_empty(handle));
  EXPECT_EQ(ListControlArray_size(handle), 0);
  ListControlArray_destroy(handle);
  EXPECT_THROW(ListControlArray_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListControlArrayTest, FillValue) {
  auto handle = ListControlArray_fill_value(3, sh1);
  EXPECT_EQ(ListControlArray_size(handle), 3);
  ListControlArray_destroy(handle);
}

TEST_F(ListControlArrayTest, CreateFromArray) {
  ControlArrayHandle     arr[2] = {sh1, sh2};
  ListControlArrayHandle handle = ListControlArray_create(arr, 2);
  EXPECT_EQ(ListControlArray_size(handle), 2);
  EXPECT_THROW(ListControlArray_create(nullptr, 2), std::invalid_argument);
  ListControlArray_destroy(handle);
}

TEST_F(ListControlArrayTest, SizeEmptyInvalid) {
  auto handle = ListControlArray_create_empty();
  EXPECT_EQ(ListControlArray_size(handle), 0);
  ListControlArray_destroy(handle);
  EXPECT_THROW(ListControlArray_size(nullptr), std::invalid_argument);
}

TEST_F(ListControlArrayTest, EmptyInvalid) {
  auto handle = ListControlArray_create_empty();
  EXPECT_TRUE(ListControlArray_empty(handle));
  ListControlArray_destroy(handle);
  EXPECT_THROW(ListControlArray_empty(nullptr), std::invalid_argument);
}

TEST_F(ListControlArrayTest, EraseAtClear) {
  auto handle = ListControlArray_fill_value(2, sh1);
  ListControlArray_erase_at(handle, 0);
  EXPECT_EQ(ListControlArray_size(handle), 1);
  ListControlArray_clear(handle);
  EXPECT_TRUE(ListControlArray_empty(handle));
  ListControlArray_destroy(handle);
  EXPECT_THROW(ListControlArray_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListControlArray_clear(nullptr), std::invalid_argument);
}

TEST_F(ListControlArrayTest, PushBackContainsIndex) {
  auto handle = ListControlArray_create_empty();
  ListControlArray_push_back(handle, sh1);
  EXPECT_TRUE(ListControlArray_contains(handle, sh1));
  EXPECT_EQ(ListControlArray_index(handle, sh1), 0);
  ListControlArray_destroy(handle);
  EXPECT_THROW(ListControlArray_push_back(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListControlArray_contains(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListControlArray_index(nullptr, sh1), std::invalid_argument);
}

TEST_F(ListControlArrayTest, ItemsAt) {
  ControlArrayHandle arr[2] = {sh1, sh2};
  auto               handle = ListControlArray_create(arr, 2);
  ControlArrayHandle out[2];
  EXPECT_EQ(ListControlArray_items(handle, out, 2), 2);
  ListControlArray_destroy(handle);
  EXPECT_THROW(ListControlArray_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListControlArray_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListControlArray_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListControlArrayTest, EqualNotEqualIntersection) {
  ControlArrayHandle arr[2] = {sh1, sh2};
  auto               h1     = ListControlArray_create(arr, 2);
  auto               h2     = ListControlArray_create(arr, 2);
  EXPECT_TRUE(ListControlArray_equal(h1, h2));
  EXPECT_FALSE(ListControlArray_not_equal(h1, h2));
  auto h3 = ListControlArray_intersection(h1, h2);
  EXPECT_EQ(ListControlArray_size(h3), 2);
  ListControlArray_destroy(h1);
  ListControlArray_destroy(h2);
  ListControlArray_destroy(h3);
  EXPECT_THROW(ListControlArray_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListControlArray_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListControlArray_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListControlArray_not_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListControlArray_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListControlArray_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListControlArrayTest, ToJsonFromJson) {
  ControlArrayHandle arr[1]  = {sh1};
  auto               handle  = ListControlArray_create(arr, 1);
  auto               json    = ListControlArray_to_json_string(handle);
  auto               handle2 = ListControlArray_from_json_string(json);
  EXPECT_TRUE(ListControlArray_equal(handle, handle2));
  ListControlArray_destroy(handle);
  ListControlArray_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListControlArray_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ListControlArray_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListControlArrayTest, FillValueNull) {
  EXPECT_THROW(ListControlArray_fill_value(3, nullptr), std::invalid_argument);
}

TEST_F(ListControlArrayTest, PushBackNull) {
  auto handle = ListControlArray_create_empty();
  EXPECT_THROW(ListControlArray_push_back(handle, nullptr),
               std::invalid_argument);
  ListControlArray_destroy(handle);
}

TEST_F(ListControlArrayTest, ContainsNull) {
  auto handle = ListControlArray_create_empty();
  EXPECT_THROW(ListControlArray_contains(handle, nullptr),
               std::invalid_argument);
  ListControlArray_destroy(handle);
}

TEST_F(ListControlArrayTest, IndexNull) {
  auto handle = ListControlArray_create_empty();
  EXPECT_THROW(ListControlArray_index(handle, nullptr), std::invalid_argument);
  ListControlArray_destroy(handle);
}

TEST_F(ListControlArrayTest, CreateNullArray) {
  EXPECT_THROW(ListControlArray_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListControlArrayTest, At) {
  ControlArrayHandle arr[2] = {sh1, sh2};
  auto               handle = ListControlArray_create(arr, 2);
  auto               at0    = ListControlArray_at(handle, 0);
  auto               at1    = ListControlArray_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListControlArray_destroy(handle);
  EXPECT_THROW(ListControlArray_at(nullptr, 0), std::invalid_argument);
}
