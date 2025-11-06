#include <falcon_core/generic/ListPairIntInt_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListPairIntIntTest : public ::testing::Test {
 protected:
  void destroy_string(PairIntIntHandle sh) { PairIntInt_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairIntIntHandle> created_strings;
  PairIntIntHandle              track_quantity(const PairIntIntHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(PairIntInt_create(1, 2));
    sh2 = track_quantity(PairIntInt_create(4, 5));
  }
  PairIntIntHandle sh1;
  PairIntIntHandle sh2;
};

TEST_F(ListPairIntIntTest, CreateEmpty) {
  auto handle = ListPairIntInt_create_empty();
  EXPECT_TRUE(ListPairIntInt_empty(handle));
  EXPECT_EQ(ListPairIntInt_size(handle), 0);
  ListPairIntInt_destroy(handle);
  EXPECT_THROW(ListPairIntInt_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListPairIntIntTest, FillValue) {
  auto handle = ListPairIntInt_fill_value(3, sh1);
  EXPECT_EQ(ListPairIntInt_size(handle), 3);
  ListPairIntInt_destroy(handle);
}

TEST_F(ListPairIntIntTest, CreateFromArray) {
  PairIntIntHandle     arr[2] = {sh1, sh2};
  ListPairIntIntHandle handle = ListPairIntInt_create(arr, 2);
  EXPECT_EQ(ListPairIntInt_size(handle), 2);
  EXPECT_THROW(ListPairIntInt_create(nullptr, 2), std::invalid_argument);
  ListPairIntInt_destroy(handle);
}

TEST_F(ListPairIntIntTest, SizeEmptyInvalid) {
  auto handle = ListPairIntInt_create_empty();
  EXPECT_EQ(ListPairIntInt_size(handle), 0);
  ListPairIntInt_destroy(handle);
  EXPECT_THROW(ListPairIntInt_size(nullptr), std::invalid_argument);
}

TEST_F(ListPairIntIntTest, EmptyInvalid) {
  auto handle = ListPairIntInt_create_empty();
  EXPECT_TRUE(ListPairIntInt_empty(handle));
  ListPairIntInt_destroy(handle);
  EXPECT_THROW(ListPairIntInt_empty(nullptr), std::invalid_argument);
}

TEST_F(ListPairIntIntTest, EraseAtClear) {
  auto handle = ListPairIntInt_fill_value(2, sh1);
  ListPairIntInt_erase_at(handle, 0);
  EXPECT_EQ(ListPairIntInt_size(handle), 1);
  ListPairIntInt_clear(handle);
  EXPECT_TRUE(ListPairIntInt_empty(handle));
  ListPairIntInt_destroy(handle);
  EXPECT_THROW(ListPairIntInt_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListPairIntInt_clear(nullptr), std::invalid_argument);
}

TEST_F(ListPairIntIntTest, PushBackContainsIndex) {
  auto handle = ListPairIntInt_create_empty();
  ListPairIntInt_push_back(handle, sh1);
  EXPECT_TRUE(ListPairIntInt_contains(handle, sh1));
  EXPECT_EQ(ListPairIntInt_index(handle, sh1), 0);
  ListPairIntInt_destroy(handle);
  EXPECT_THROW(ListPairIntInt_push_back(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListPairIntInt_contains(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListPairIntInt_index(nullptr, sh1), std::invalid_argument);
}

TEST_F(ListPairIntIntTest, ItemsAt) {
  PairIntIntHandle arr[2] = {sh1, sh2};
  auto             handle = ListPairIntInt_create(arr, 2);
  PairIntIntHandle out[2];
  EXPECT_EQ(ListPairIntInt_items(handle, out, 2), 2);
  ListPairIntInt_destroy(handle);
  EXPECT_THROW(ListPairIntInt_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListPairIntInt_items(handle, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(ListPairIntInt_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListPairIntIntTest, EqualNotEqualIntersection) {
  PairIntIntHandle arr[2] = {sh1, sh2};
  auto             h1     = ListPairIntInt_create(arr, 2);
  auto             h2     = ListPairIntInt_create(arr, 2);
  EXPECT_TRUE(ListPairIntInt_equal(h1, h2));
  EXPECT_FALSE(ListPairIntInt_not_equal(h1, h2));
  auto h3 = ListPairIntInt_intersection(h1, h2);
  EXPECT_EQ(ListPairIntInt_size(h3), 2);
  ListPairIntInt_destroy(h1);
  ListPairIntInt_destroy(h2);
  ListPairIntInt_destroy(h3);
  EXPECT_THROW(ListPairIntInt_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListPairIntInt_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListPairIntInt_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListPairIntInt_not_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListPairIntInt_intersection(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListPairIntInt_intersection(h1, nullptr), std::invalid_argument);
}

TEST_F(ListPairIntIntTest, ToJsonFromJson) {
  PairIntIntHandle arr[1]  = {sh1};
  auto             handle  = ListPairIntInt_create(arr, 1);
  auto             json    = ListPairIntInt_to_json_string(handle);
  auto             handle2 = ListPairIntInt_from_json_string(json);
  EXPECT_TRUE(ListPairIntInt_equal(handle, handle2));
  ListPairIntInt_destroy(handle);
  ListPairIntInt_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListPairIntInt_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ListPairIntInt_from_json_string(nullptr), std::invalid_argument);
}

TEST_F(ListPairIntIntTest, FillValueNull) {
  EXPECT_THROW(ListPairIntInt_fill_value(3, nullptr), std::invalid_argument);
}

TEST_F(ListPairIntIntTest, PushBackNull) {
  auto handle = ListPairIntInt_create_empty();
  EXPECT_THROW(ListPairIntInt_push_back(handle, nullptr),
               std::invalid_argument);
  ListPairIntInt_destroy(handle);
}

TEST_F(ListPairIntIntTest, ContainsNull) {
  auto handle = ListPairIntInt_create_empty();
  EXPECT_THROW(ListPairIntInt_contains(handle, nullptr), std::invalid_argument);
  ListPairIntInt_destroy(handle);
}

TEST_F(ListPairIntIntTest, IndexNull) {
  auto handle = ListPairIntInt_create_empty();
  EXPECT_THROW(ListPairIntInt_index(handle, nullptr), std::invalid_argument);
  ListPairIntInt_destroy(handle);
}

TEST_F(ListPairIntIntTest, CreateNullArray) {
  EXPECT_THROW(ListPairIntInt_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListPairIntIntTest, At) {
  PairIntIntHandle arr[2] = {sh1, sh2};
  auto             handle = ListPairIntInt_create(arr, 2);
  auto             at0    = ListPairIntInt_at(handle, 0);
  auto             at1    = ListPairIntInt_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairIntInt_destroy(handle);
  EXPECT_THROW(ListPairIntInt_at(nullptr, 0), std::invalid_argument);
}
