#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/math/AxesInt_c_api.h"

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
  void TearDown() override {
    if (axes) {
      AxesInt_destroy(axes);
      axes = nullptr;
    }
    if (axes2) {
      AxesInt_destroy(axes2);
      axes2 = nullptr;
    }
  }

  AxesIntHandle axes  = nullptr;
  AxesIntHandle axes2 = nullptr;
  int           raw_arr[2];
  const int*    raw = nullptr;
};

TEST_F(AxesIntTest, CreateDestroy) {
  auto h = AxesInt_create_empty();
  AxesInt_destroy(h);
  set_last_error(0, nullptr);
  AxesInt_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInt_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AxesIntTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesInt_size(axes), 2u);
  EXPECT_EQ(AxesInt_at(axes, 1), 2);
  int out[4];
  EXPECT_EQ(AxesInt_items(axes, out, 4), 2u);
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
  set_last_error(0, nullptr);
  AxesInt_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInt_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AxesIntTest, EqualityWorks) {
  EXPECT_TRUE(AxesInt_equal(axes, axes));
  EXPECT_TRUE(AxesInt_not_equal(axes, axes2));
  set_last_error(0, nullptr);
  AxesInt_equal(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInt_not_equal(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AxesIntTest, Intersection) {
  set_last_error(0, nullptr);
  AxesInt_intersection(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInt_intersection(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesInt_intersection(axes, axes2));
}

TEST_F(AxesIntTest, MiscNullChecks) {
  set_last_error(0, nullptr);
  AxesInt_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInt_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInt_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInt_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInt_push_back(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInt_contains(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInt_index(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInt_items(nullptr, raw_arr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInt_items(axes, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInt_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
