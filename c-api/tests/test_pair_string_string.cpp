#include <gtest/gtest.h>

#include "falcon_core/generic/PairStringString_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class PairStringStringTest : public ::testing::Test {
 protected:
  StringHandle make_str(const std::string& s) {
    return String_create(s.c_str(), s.size());
  }
  void destroy_str(StringHandle sh) { String_destroy(sh); }
};

TEST_F(PairStringStringTest, CreateDestroy) {
  auto s1 = make_str("foo");
  auto s2 = make_str("bar");
  auto p  = PairStringString_create(s1, s2);
  PairStringString_destroy(p);
  EXPECT_THROW(PairStringString_create(nullptr, s2), std::invalid_argument);
  EXPECT_THROW(PairStringString_create(s1, nullptr), std::invalid_argument);
  EXPECT_THROW(PairStringString_destroy(nullptr), std::invalid_argument);
  destroy_str(s1);
  destroy_str(s2);
}

TEST_F(PairStringStringTest, Accessors) {
  auto s1 = make_str("foo");
  auto s2 = make_str("bar");
  auto p  = PairStringString_create(s1, s2);
  auto f  = PairStringString_first(p);
  auto s  = PairStringString_second(p);
  EXPECT_STREQ(f->raw, "foo");
  EXPECT_STREQ(s->raw, "bar");
  destroy_str(f);
  destroy_str(s);
  PairStringString_destroy(p);
  destroy_str(s1);
  destroy_str(s2);
  EXPECT_THROW(PairStringString_first(nullptr), std::invalid_argument);
  EXPECT_THROW(PairStringString_second(nullptr), std::invalid_argument);
}

TEST_F(PairStringStringTest, Equality) {
  auto s1 = make_str("foo");
  auto s2 = make_str("bar");
  auto p1 = PairStringString_create(s1, s2);
  auto p2 = PairStringString_create(s1, s2);
  EXPECT_TRUE(PairStringString_equal(p1, p2));
  EXPECT_FALSE(PairStringString_not_equal(p1, p2));
  PairStringString_destroy(p1);
  PairStringString_destroy(p2);
  destroy_str(s1);
  destroy_str(s2);
  EXPECT_THROW(PairStringString_equal(nullptr, p2), std::invalid_argument);
  EXPECT_THROW(PairStringString_equal(p1, nullptr), std::invalid_argument);
  EXPECT_THROW(PairStringString_not_equal(nullptr, p2), std::invalid_argument);
  EXPECT_THROW(PairStringString_not_equal(p1, nullptr), std::invalid_argument);
}

TEST_F(PairStringStringTest, ToJsonFromJson) {
  auto s1   = make_str("foo");
  auto s2   = make_str("bar");
  auto p    = PairStringString_create(s1, s2);
  auto json = PairStringString_to_json_string(p);
  auto p2   = PairStringString_from_json_string(json);
  EXPECT_TRUE(PairStringString_equal(p, p2));
  PairStringString_destroy(p);
  PairStringString_destroy(p2);
  destroy_str(json);
  destroy_str(s1);
  destroy_str(s2);
  EXPECT_THROW(PairStringString_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(PairStringString_from_json_string(nullptr),
               std::invalid_argument);
}
