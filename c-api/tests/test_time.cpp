#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

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
  set_last_error(0, nullptr);
  Time_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(TimeTest, Accessors) {
  EXPECT_GT(Time_micro_seconds_since_epoch(now), 0);
  EXPECT_EQ(Time_micro_seconds_since_epoch(at), 123456789);
  EXPECT_EQ(Time_time(at), 123456789);
  set_last_error(0, nullptr);
  Time_micro_seconds_since_epoch(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Time_time(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(TimeTest, ToString) {
  auto s = Time_to_string(at);
  EXPECT_NE(s, nullptr);
  String_destroy(s);
  set_last_error(0, nullptr);
  Time_to_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(TimeTest, Equality) {
  EXPECT_FALSE(Time_equal(at, at2));
  EXPECT_TRUE(Time_not_equal(at, at2));
  EXPECT_TRUE(Time_equal(at, at));
  EXPECT_FALSE(Time_not_equal(at, at));
  set_last_error(0, nullptr);
  Time_equal(nullptr, at2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Time_equal(at, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Time_not_equal(nullptr, at2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Time_not_equal(at, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(TimeTest, ToJsonFromJson) {
  auto json = Time_to_json_string(at);
  auto t2   = Time_from_json_string(json);
  EXPECT_TRUE(Time_equal(at, t2));
  Time_destroy(t2);
  String_destroy(json);
  set_last_error(0, nullptr);
  Time_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Time_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
