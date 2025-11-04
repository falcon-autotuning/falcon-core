#include <gtest/gtest.h>

#include "falcon_core/communications/Time_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class TimeTest : public ::testing::Test {
 protected:
  void SetUp() override {
    now = Time_create_now();
    at  = Time_create_at(123456789);
    at2 = Time_create_at(987654321);
  }
  void TearDown() override {
    Time_destroy(now);
    Time_destroy(at);
    Time_destroy(at2);
  }
  TimeHandle now = nullptr;
  TimeHandle at  = nullptr;
  TimeHandle at2 = nullptr;
};

TEST_F(TimeTest, CreateDestroy) {
  auto t = Time_create_now();
  Time_destroy(t);
  auto t2 = Time_create_at(42);
  Time_destroy(t2);
  EXPECT_THROW(Time_destroy(nullptr), std::invalid_argument);
}

TEST_F(TimeTest, Accessors) {
  EXPECT_GT(Time_micro_seconds_since_epoch(now), 0);
  EXPECT_EQ(Time_micro_seconds_since_epoch(at), 123456789);
  EXPECT_EQ(Time_time(at), 123456789);
  EXPECT_THROW(Time_micro_seconds_since_epoch(nullptr), std::invalid_argument);
  EXPECT_THROW(Time_time(nullptr), std::invalid_argument);
}

TEST_F(TimeTest, ToString) {
  auto s = Time_to_string(at);
  EXPECT_NE(s, nullptr);
  String_destroy(s);
  EXPECT_THROW(Time_to_string(nullptr), std::invalid_argument);
}

TEST_F(TimeTest, Equality) {
  EXPECT_FALSE(Time_equal(at, at2));
  EXPECT_TRUE(Time_not_equal(at, at2));
  EXPECT_TRUE(Time_equal(at, at));
  EXPECT_FALSE(Time_not_equal(at, at));
  EXPECT_THROW(Time_equal(nullptr, at2), std::invalid_argument);
  EXPECT_THROW(Time_equal(at, nullptr), std::invalid_argument);
  EXPECT_THROW(Time_not_equal(nullptr, at2), std::invalid_argument);
  EXPECT_THROW(Time_not_equal(at, nullptr), std::invalid_argument);
}

TEST_F(TimeTest, ToJsonFromJson) {
  auto json = Time_to_json_string(at);
  auto t2   = Time_from_json_string(json);
  EXPECT_TRUE(Time_equal(at, t2));
  Time_destroy(t2);
  String_destroy(json);
  EXPECT_THROW(Time_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(Time_from_json_string(nullptr), std::invalid_argument);
}
