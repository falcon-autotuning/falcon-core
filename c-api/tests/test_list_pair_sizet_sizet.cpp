#include <falcon_core/generic/ListPairSizeTSizeT_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListPairSizeTSizeTTest : public ::testing::Test {
 protected:
  void destroy_string(PairSizeTSizeTHandle sh) { PairSizeTSizeT_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairSizeTSizeTHandle> created_strings;
  PairSizeTSizeTHandle track_quantity(const PairSizeTSizeTHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(PairSizeTSizeT_create(1, 2));
    sh2 = track_quantity(PairSizeTSizeT_create(2, 2));
  }
  PairSizeTSizeTHandle sh1;
  PairSizeTSizeTHandle sh2;
};

TEST_F(ListPairSizeTSizeTTest, CreateEmpty) {
  auto handle = ListPairSizeTSizeT_create_empty();
  EXPECT_TRUE(ListPairSizeTSizeT_empty(handle));
  EXPECT_EQ(ListPairSizeTSizeT_size(handle), 0);
  ListPairSizeTSizeT_destroy(handle);
  EXPECT_THROW(ListPairSizeTSizeT_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListPairSizeTSizeTTest, FillValue) {
  auto handle = ListPairSizeTSizeT_fill_value(3, sh1);
  EXPECT_EQ(ListPairSizeTSizeT_size(handle), 3);
  ListPairSizeTSizeT_destroy(handle);
}

TEST_F(ListPairSizeTSizeTTest, CreateFromArray) {
  PairSizeTSizeTHandle     arr[2] = {sh1, sh2};
  ListPairSizeTSizeTHandle handle = ListPairSizeTSizeT_create(arr, 2);
  EXPECT_EQ(ListPairSizeTSizeT_size(handle), 2);
  EXPECT_THROW(ListPairSizeTSizeT_create(nullptr, 2), std::invalid_argument);
  ListPairSizeTSizeT_destroy(handle);
}

TEST_F(ListPairSizeTSizeTTest, SizeEmptyInvalid) {
  auto handle = ListPairSizeTSizeT_create_empty();
  EXPECT_EQ(ListPairSizeTSizeT_size(handle), 0);
  ListPairSizeTSizeT_destroy(handle);
  EXPECT_THROW(ListPairSizeTSizeT_size(nullptr), std::invalid_argument);
}

TEST_F(ListPairSizeTSizeTTest, EmptyInvalid) {
  auto handle = ListPairSizeTSizeT_create_empty();
  EXPECT_TRUE(ListPairSizeTSizeT_empty(handle));
  ListPairSizeTSizeT_destroy(handle);
  EXPECT_THROW(ListPairSizeTSizeT_empty(nullptr), std::invalid_argument);
}

TEST_F(ListPairSizeTSizeTTest, EraseAtClear) {
  auto handle = ListPairSizeTSizeT_fill_value(2, sh1);
  ListPairSizeTSizeT_erase_at(handle, 0);
  EXPECT_EQ(ListPairSizeTSizeT_size(handle), 1);
  ListPairSizeTSizeT_clear(handle);
  EXPECT_TRUE(ListPairSizeTSizeT_empty(handle));
  ListPairSizeTSizeT_destroy(handle);
  EXPECT_THROW(ListPairSizeTSizeT_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListPairSizeTSizeT_clear(nullptr), std::invalid_argument);
}

TEST_F(ListPairSizeTSizeTTest, PushBackContainsIndex) {
  auto handle = ListPairSizeTSizeT_create_empty();
  ListPairSizeTSizeT_push_back(handle, sh1);
  EXPECT_TRUE(ListPairSizeTSizeT_contains(handle, sh1));
  EXPECT_EQ(ListPairSizeTSizeT_index(handle, sh1), 0);
  ListPairSizeTSizeT_destroy(handle);
  EXPECT_THROW(ListPairSizeTSizeT_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListPairSizeTSizeT_contains(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListPairSizeTSizeT_index(nullptr, sh1), std::invalid_argument);
}

TEST_F(ListPairSizeTSizeTTest, ItemsAt) {
  PairSizeTSizeTHandle arr[2] = {sh1, sh2};
  auto                 handle = ListPairSizeTSizeT_create(arr, 2);
  PairSizeTSizeTHandle out[2];
  EXPECT_EQ(ListPairSizeTSizeT_items(handle, out, 2), 2);
  ListPairSizeTSizeT_destroy(handle);
  EXPECT_THROW(ListPairSizeTSizeT_items(nullptr, out, 2),
               std::invalid_argument);
  EXPECT_THROW(ListPairSizeTSizeT_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListPairSizeTSizeT_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListPairSizeTSizeTTest, EqualNotEqualIntersection) {
  PairSizeTSizeTHandle arr[2] = {sh1, sh2};
  auto                 h1     = ListPairSizeTSizeT_create(arr, 2);
  auto                 h2     = ListPairSizeTSizeT_create(arr, 2);
  EXPECT_TRUE(ListPairSizeTSizeT_equal(h1, h2));
  EXPECT_FALSE(ListPairSizeTSizeT_not_equal(h1, h2));
  auto h3 = ListPairSizeTSizeT_intersection(h1, h2);
  EXPECT_EQ(ListPairSizeTSizeT_size(h3), 2);
  ListPairSizeTSizeT_destroy(h1);
  ListPairSizeTSizeT_destroy(h2);
  ListPairSizeTSizeT_destroy(h3);
  EXPECT_THROW(ListPairSizeTSizeT_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListPairSizeTSizeT_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListPairSizeTSizeT_not_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairSizeTSizeT_not_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairSizeTSizeT_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairSizeTSizeT_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListPairSizeTSizeTTest, ToJsonFromJson) {
  PairSizeTSizeTHandle arr[1]  = {sh1};
  auto                 handle  = ListPairSizeTSizeT_create(arr, 1);
  auto                 json    = ListPairSizeTSizeT_to_json_string(handle);
  auto                 handle2 = ListPairSizeTSizeT_from_json_string(json);
  EXPECT_TRUE(ListPairSizeTSizeT_equal(handle, handle2));
  ListPairSizeTSizeT_destroy(handle);
  ListPairSizeTSizeT_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListPairSizeTSizeT_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairSizeTSizeT_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairSizeTSizeTTest, FillValueNull) {
  EXPECT_THROW(ListPairSizeTSizeT_fill_value(3, nullptr),
               std::invalid_argument);
}

TEST_F(ListPairSizeTSizeTTest, PushBackNull) {
  auto handle = ListPairSizeTSizeT_create_empty();
  EXPECT_THROW(ListPairSizeTSizeT_push_back(handle, nullptr),
               std::invalid_argument);
  ListPairSizeTSizeT_destroy(handle);
}

TEST_F(ListPairSizeTSizeTTest, ContainsNull) {
  auto handle = ListPairSizeTSizeT_create_empty();
  EXPECT_THROW(ListPairSizeTSizeT_contains(handle, nullptr),
               std::invalid_argument);
  ListPairSizeTSizeT_destroy(handle);
}

TEST_F(ListPairSizeTSizeTTest, IndexNull) {
  auto handle = ListPairSizeTSizeT_create_empty();
  EXPECT_THROW(ListPairSizeTSizeT_index(handle, nullptr),
               std::invalid_argument);
  ListPairSizeTSizeT_destroy(handle);
}

TEST_F(ListPairSizeTSizeTTest, CreateNullArray) {
  EXPECT_THROW(ListPairSizeTSizeT_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListPairSizeTSizeTTest, At) {
  PairSizeTSizeTHandle arr[2] = {sh1, sh2};
  auto                 handle = ListPairSizeTSizeT_create(arr, 2);
  auto                 at0    = ListPairSizeTSizeT_at(handle, 0);
  auto                 at1    = ListPairSizeTSizeT_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairSizeTSizeT_destroy(handle);
  EXPECT_THROW(ListPairSizeTSizeT_at(nullptr, 0), std::invalid_argument);
}
