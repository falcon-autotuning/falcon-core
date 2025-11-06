#include <falcon_core/generic/ListImpedance_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListImpedanceTest : public ::testing::Test {
 protected:
  void destroy_string(ImpedanceHandle sh) { Impedance_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<ImpedanceHandle> created_strings;
  ImpedanceHandle              track_quantity(const ImpedanceHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(Impedance_create(
        Connection_create_barrier_gate(String_wrap("gate1")), 1.0, 2.0));
    sh2 = track_quantity(Impedance_create(
        Connection_create_barrier_gate(String_wrap("gate2")), 1.0, 2.0));
  }
  ImpedanceHandle sh1;
  ImpedanceHandle sh2;
};

TEST_F(ListImpedanceTest, CreateEmpty) {
  auto handle = ListImpedance_create_empty();
  EXPECT_TRUE(ListImpedance_empty(handle));
  EXPECT_EQ(ListImpedance_size(handle), 0);
  ListImpedance_destroy(handle);
  EXPECT_THROW(ListImpedance_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListImpedanceTest, FillValue) {
  auto handle = ListImpedance_fill_value(3, sh1);
  EXPECT_EQ(ListImpedance_size(handle), 3);
  ListImpedance_destroy(handle);
}

TEST_F(ListImpedanceTest, CreateFromArray) {
  ImpedanceHandle     arr[2] = {sh1, sh2};
  ListImpedanceHandle handle = ListImpedance_create(arr, 2);
  EXPECT_EQ(ListImpedance_size(handle), 2);
  EXPECT_THROW(ListImpedance_create(nullptr, 2), std::invalid_argument);
  ListImpedance_destroy(handle);
}

TEST_F(ListImpedanceTest, SizeEmptyInvalid) {
  auto handle = ListImpedance_create_empty();
  EXPECT_EQ(ListImpedance_size(handle), 0);
  ListImpedance_destroy(handle);
  EXPECT_THROW(ListImpedance_size(nullptr), std::invalid_argument);
}

TEST_F(ListImpedanceTest, EmptyInvalid) {
  auto handle = ListImpedance_create_empty();
  EXPECT_TRUE(ListImpedance_empty(handle));
  ListImpedance_destroy(handle);
  EXPECT_THROW(ListImpedance_empty(nullptr), std::invalid_argument);
}

TEST_F(ListImpedanceTest, EraseAtClear) {
  auto handle = ListImpedance_fill_value(2, sh1);
  ListImpedance_erase_at(handle, 0);
  EXPECT_EQ(ListImpedance_size(handle), 1);
  ListImpedance_clear(handle);
  EXPECT_TRUE(ListImpedance_empty(handle));
  ListImpedance_destroy(handle);
  EXPECT_THROW(ListImpedance_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListImpedance_clear(nullptr), std::invalid_argument);
}

TEST_F(ListImpedanceTest, PushBackContainsIndex) {
  auto handle = ListImpedance_create_empty();
  ListImpedance_push_back(handle, sh1);
  EXPECT_TRUE(ListImpedance_contains(handle, sh1));
  EXPECT_EQ(ListImpedance_index(handle, sh1), 0);
  ListImpedance_destroy(handle);
  EXPECT_THROW(ListImpedance_push_back(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListImpedance_contains(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListImpedance_index(nullptr, sh1), std::invalid_argument);
}

TEST_F(ListImpedanceTest, ItemsAt) {
  ImpedanceHandle arr[2] = {sh1, sh2};
  auto            handle = ListImpedance_create(arr, 2);
  ImpedanceHandle out[2];
  EXPECT_EQ(ListImpedance_items(handle, out, 2), 2);
  ListImpedance_destroy(handle);
  EXPECT_THROW(ListImpedance_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListImpedance_items(handle, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(ListImpedance_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListImpedanceTest, EqualNotEqualIntersection) {
  ImpedanceHandle arr[2] = {sh1, sh2};
  auto            h1     = ListImpedance_create(arr, 2);
  auto            h2     = ListImpedance_create(arr, 2);
  EXPECT_TRUE(ListImpedance_equal(h1, h2));
  EXPECT_FALSE(ListImpedance_not_equal(h1, h2));
  auto h3 = ListImpedance_intersection(h1, h2);
  EXPECT_EQ(ListImpedance_size(h3), 2);
  ListImpedance_destroy(h1);
  ListImpedance_destroy(h2);
  ListImpedance_destroy(h3);
  EXPECT_THROW(ListImpedance_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListImpedance_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListImpedance_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListImpedance_not_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListImpedance_intersection(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListImpedance_intersection(h1, nullptr), std::invalid_argument);
}

TEST_F(ListImpedanceTest, ToJsonFromJson) {
  ImpedanceHandle arr[1]  = {sh1};
  auto            handle  = ListImpedance_create(arr, 1);
  auto            json    = ListImpedance_to_json_string(handle);
  auto            handle2 = ListImpedance_from_json_string(json);
  EXPECT_TRUE(ListImpedance_equal(handle, handle2));
  ListImpedance_destroy(handle);
  ListImpedance_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListImpedance_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ListImpedance_from_json_string(nullptr), std::invalid_argument);
}

TEST_F(ListImpedanceTest, FillValueNull) {
  EXPECT_THROW(ListImpedance_fill_value(3, nullptr), std::invalid_argument);
}

TEST_F(ListImpedanceTest, PushBackNull) {
  auto handle = ListImpedance_create_empty();
  EXPECT_THROW(ListImpedance_push_back(handle, nullptr), std::invalid_argument);
  ListImpedance_destroy(handle);
}

TEST_F(ListImpedanceTest, ContainsNull) {
  auto handle = ListImpedance_create_empty();
  EXPECT_THROW(ListImpedance_contains(handle, nullptr), std::invalid_argument);
  ListImpedance_destroy(handle);
}

TEST_F(ListImpedanceTest, IndexNull) {
  auto handle = ListImpedance_create_empty();
  EXPECT_THROW(ListImpedance_index(handle, nullptr), std::invalid_argument);
  ListImpedance_destroy(handle);
}

TEST_F(ListImpedanceTest, CreateNullArray) {
  EXPECT_THROW(ListImpedance_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListImpedanceTest, At) {
  ImpedanceHandle arr[2] = {sh1, sh2};
  auto            handle = ListImpedance_create(arr, 2);
  auto            at0    = ListImpedance_at(handle, 0);
  auto            at1    = ListImpedance_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListImpedance_destroy(handle);
  EXPECT_THROW(ListImpedance_at(nullptr, 0), std::invalid_argument);
}
