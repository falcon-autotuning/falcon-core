#include <gtest/gtest.h>

#include <chrono>
#include <cstdlib>
#include <regex>
#include <string>

#include "falcon_core/communications/Time.hpp"

using namespace falcon_core::communications;

TEST(TimeTest, DefaultConstructorSetsCurrentTime) {
  using namespace std::chrono;
  auto now_us = duration_cast<microseconds>(
                    system_clock::now().time_since_epoch())
                    .count();

  Time t;
  long long t_us = t.micro_seconds_since_epoch();

  // The constructed Time should be near "now". Allow 1 second tolerance.
  long long diff = std::llabs(now_us - t_us);
  EXPECT_LE(diff, 1000000LL);
}

TEST(TimeTest, ParameterConstructorAndAccessors) {
  long long expected = 1234567890123456LL;
  Time t(expected);

  EXPECT_EQ(t.micro_seconds_since_epoch(), expected);
  EXPECT_EQ(t.time(), expected);
}

TEST(TimeTest, ToStringFormat) {
  // Use a deterministic microsecond value. We only check formatting, not the
  // actual wall-clock value (localtime can vary by timezone).
  Time t(1609459200000000LL);  // corresponds to 2021-01-01 00:00:00 UTC
  std::string s = t.to_string();

  // Expect "YYYY-MM-DD HH:MM:SS"
  std::regex re(R"(^\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}$)");
  EXPECT_TRUE(std::regex_match(s, re)) << "to_string() returned: " << s;
}

TEST(TimeTest, JsonSerializationRoundTrip) {
  long long expected = 1610000000123456LL;
  Time orig(expected);

  std::string json = orig.to_json_string();
  ASSERT_FALSE(json.empty());

  // static template method is defined in Song and accessible via derived class
  auto loaded = Time::from_json_string<Time>(json);
  ASSERT_NE(loaded, nullptr);

  EXPECT_EQ(loaded->micro_seconds_since_epoch(), orig.micro_seconds_since_epoch());
  EXPECT_EQ(loaded->time(), orig.time());
}
