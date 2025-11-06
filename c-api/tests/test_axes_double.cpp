#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon_core/math/AxesDouble_c_api.h"

class AxesDoubleTest : public ::testing::Test {
 protected:
  void SetUp() override {
    axes = AxesDouble_create_empty();
    AxesDouble_push_back(axes, 1.0);
    AxesDouble_push_back(axes, 2.0);
    axes2 = AxesDouble_create_empty();
    AxesDouble_push_back(axes2, 3.0);
    AxesDouble_push_back(axes2, 4.0);
    raw_arr[0] = 10.0;
    raw_arr[1] = 20.0;
    raw        = raw_arr;
  }
  void TearDown() override {
    if (axes) {
      AxesDouble_destroy(axes);
      axes = nullptr;
    }
    if (axes2) {
      AxesDouble_destroy(axes2);
      axes2 = nullptr;
    }
  }

  AxesDoubleHandle axes  = nullptr;
  AxesDoubleHandle axes2 = nullptr;
  double           raw_arr[2];
  const double*    raw = nullptr;
};

TEST_F(AxesDoubleTest, CreateDestroy) {
  auto h = AxesDouble_create_empty();
  AxesDouble_destroy(h);
  EXPECT_THROW(AxesDouble_create(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesDouble_destroy(nullptr), std::invalid_argument);
}

TEST_F(AxesDoubleTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesDouble_size(axes), 2u);
  EXPECT_EQ(AxesDouble_at(axes, 1), 2);
  double out[4];
  EXPECT_EQ(AxesDouble_items(axes, out, 4), 2u);
  auto h2 = AxesDouble_create_raw(raw, 2);
  ASSERT_NE(h2, nullptr);
  AxesDouble_destroy(h2);
  AxesDouble_push_back(axes, 3);
  AxesDouble_erase_at(axes, 2);
  AxesDouble_clear(axes);
  EXPECT_TRUE(AxesDouble_empty(axes));
}

TEST_F(AxesDoubleTest, ContainsIndexEquality) {
  EXPECT_TRUE(AxesDouble_contains(axes, 1));
  EXPECT_EQ(AxesDouble_index(axes, 2), 1u);

  auto other = AxesDouble_create_empty();
  AxesDouble_push_back(other, 1);
  AxesDouble_push_back(other, 2);
  EXPECT_TRUE(AxesDouble_equal(axes, other));
  AxesDouble_destroy(other);
}

TEST_F(AxesDoubleTest, SerializationRoundTrip) {
  EXPECT_TRUE(AxesDouble_equal(
      AxesDouble_from_json_string(AxesDouble_to_json_string(axes)), axes));
  EXPECT_THROW(AxesDouble_from_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesDouble_to_json_string(nullptr), std::invalid_argument);
}

TEST_F(AxesDoubleTest, EqualityWorks) {
  EXPECT_TRUE(AxesDouble_equal(axes, axes));
  EXPECT_TRUE(AxesDouble_not_equal(axes, axes2));
  EXPECT_THROW(AxesDouble_equal(axes, nullptr), std::invalid_argument);
  EXPECT_THROW(AxesDouble_not_equal(axes, nullptr), std::invalid_argument);
}

TEST_F(AxesDoubleTest, Intersection) {
  EXPECT_THROW(AxesDouble_intersection(nullptr, axes2), std::invalid_argument);
  EXPECT_THROW(AxesDouble_intersection(axes, nullptr), std::invalid_argument);
  EXPECT_NO_THROW(AxesDouble_intersection(axes, axes2));
}

TEST_F(AxesDoubleTest, MiscNullChecks) {
  EXPECT_THROW(AxesDouble_size(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesDouble_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesDouble_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesDouble_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesDouble_push_back(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesDouble_contains(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesDouble_index(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesDouble_items(nullptr, raw_arr, 2), std::invalid_argument);
  EXPECT_THROW(AxesDouble_items(axes, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(AxesDouble_at(nullptr, 0), std::invalid_argument);
}
