#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/math/AxesDouble_c_api.h"

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
  set_last_error(0, nullptr);
  AxesDouble_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesDouble_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AxesDoubleTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesDouble_size(axes), 2u);
  EXPECT_EQ(AxesDouble_at(axes, 1), 2);
  double out[4];
  EXPECT_EQ(AxesDouble_items(axes, out, 4), 2u);
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
  set_last_error(0, nullptr);
  AxesDouble_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesDouble_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AxesDoubleTest, EqualityWorks) {
  EXPECT_TRUE(AxesDouble_equal(axes, axes));
  EXPECT_TRUE(AxesDouble_not_equal(axes, axes2));
  set_last_error(0, nullptr);
  AxesDouble_equal(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesDouble_not_equal(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AxesDoubleTest, Intersection) {
  set_last_error(0, nullptr);
  AxesDouble_intersection(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesDouble_intersection(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesDouble_intersection(axes, axes2));
}

TEST_F(AxesDoubleTest, MiscNullChecks) {
  set_last_error(0, nullptr);
  AxesDouble_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesDouble_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesDouble_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesDouble_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesDouble_push_back(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesDouble_contains(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesDouble_index(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesDouble_items(nullptr, raw_arr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesDouble_items(axes, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesDouble_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
