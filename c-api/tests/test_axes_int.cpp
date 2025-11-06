#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon_core/math/AxesInt_c_api.h"

class AxesIntTest : public ::testing::Test {
 protected:
  void SetUp() override {
    axes = AxesInt_create_empty();
    AxesInt_push_back(axes, 1);
    AxesInt_push_back(axes, 2);
    axes2 = AxesInt_create_empty();
    AxesInt_push_back(axes2, 3);
    AxesInt_push_back(axes2, 4);
    raw_arr[0] = 10;
    raw_arr[1] = 20;
    raw        = raw_arr;
  }
  void TearDown() override { AxesInt_destroy(axes); }

  AxesIntHandle axes  = nullptr;
  AxesIntHandle axes2 = nullptr;
  int           raw_arr[2];
  const int*    raw = nullptr;
};

TEST_F(AxesIntTest, CreateDestroy) {
  auto h = AxesInt_create_empty();
  AxesInt_destroy(h);
  EXPECT_THROW(AxesInt_create(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesInt_destroy(nullptr), std::invalid_argument);
}

TEST_F(AxesIntTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesInt_size(axes), 2u);
  EXPECT_EQ(AxesInt_at(axes, 1), 2);
  int out[4];
  EXPECT_EQ(AxesInt_items(axes, out, 4), 2u);
  auto h2 = AxesInt_create_raw(raw, 2);
  ASSERT_NE(h2, nullptr);
  AxesInt_destroy(h2);
  AxesInt_push_back(axes, 3);
  AxesInt_erase_at(axes, 2);
  AxesInt_clear(axes);
  EXPECT_TRUE(AxesInt_empty(axes));
}

TEST_F(AxesIntTest, ContainsIndexEquality) {
  EXPECT_TRUE(AxesInt_contains(axes, 1));
  EXPECT_EQ(AxesInt_index(axes, 2), 1u);

  auto other = AxesInt_create_empty();
  AxesInt_push_back(other, 1);
  AxesInt_push_back(other, 2);
  EXPECT_TRUE(AxesInt_equal(axes, other));
  AxesInt_destroy(other);
}

TEST_F(AxesIntTest, SerializationRoundTrip) {
  EXPECT_TRUE(AxesInt_equal(
      AxesInt_from_json_string(AxesInt_to_json_string(axes)), axes));
  EXPECT_THROW(AxesInt_from_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesInt_to_json_string(nullptr), std::invalid_argument);
}

TEST_F(AxesIntTest, EqualityWorks) {
  EXPECT_TRUE(AxesInt_equal(axes, axes));
  EXPECT_TRUE(AxesInt_not_equal(axes, axes2));
  EXPECT_THROW(AxesInt_equal(axes, nullptr), std::invalid_argument);
  EXPECT_THROW(AxesInt_not_equal(axes, nullptr), std::invalid_argument);
}

TEST_F(AxesIntTest, Intersection) {
  EXPECT_THROW(AxesInt_intersection(nullptr, axes2), std::invalid_argument);
  EXPECT_THROW(AxesInt_intersection(axes, nullptr), std::invalid_argument);
  EXPECT_NO_THROW(AxesInt_intersection(axes, axes2));
}

TEST_F(AxesIntTest, MiscNullChecks) {
  EXPECT_THROW(AxesInt_size(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesInt_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesInt_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesInt_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesInt_push_back(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesInt_contains(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesInt_index(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesInt_items(nullptr, raw_arr, 2), std::invalid_argument);
  EXPECT_THROW(AxesInt_items(axes, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(AxesInt_at(nullptr, 0), std::invalid_argument);
}
