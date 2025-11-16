#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include <string>

#include "falcon_core/generic/PairStringString_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class PairStringStringTest : public ::testing::Test {
 protected:
  void SetUp() override {
    t1    = String_wrap("hello");
    t2    = String_wrap("world");
    pair1 = PairStringString_create(t1, t2);
    pair2 = PairStringString_create(t1, t2);
  }
  void TearDown() override {
    PairStringString_destroy(pair1);
    PairStringString_destroy(pair2);
    String_destroy(t1);
    String_destroy(t2);
  }
  PairStringStringHandle pair1;
  PairStringStringHandle pair2;
  StringHandle           t1;
  StringHandle           t2;
  bool                   String_equal(StringHandle a, StringHandle b) {
    if (a == nullptr || b == nullptr) {
      throw std::invalid_argument("Null StringHandle provided");
    }
    std::string str_a = std::string(a->raw, a->length);
    std::string str_b = std::string(b->raw, b->length);
    return std::string(str_a) == std::string(str_b);
  }
};

TEST_F(PairStringStringTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairStringString_create(nullptr, t2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairStringString_create(t1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairStringString_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairStringStringTest, Accessors) {
  auto f = PairStringString_first(pair1);
  auto s = PairStringString_second(pair1);
  EXPECT_TRUE(String_equal(f, t1));
  EXPECT_TRUE(String_equal(s, t2));
  set_last_error(0, nullptr);
  PairStringString_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairStringString_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairStringStringTest, Equality) {
  EXPECT_TRUE(PairStringString_equal(pair1, pair2));
  EXPECT_FALSE(PairStringString_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairStringString_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairStringString_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairStringString_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairStringString_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairStringStringTest, ToJsonFromJson) {
  auto json = PairStringString_to_json_string(pair1);
  auto p2   = PairStringString_from_json_string(json);
  EXPECT_TRUE(PairStringString_equal(pair1, p2));
  PairStringString_destroy(p2);
  set_last_error(0, nullptr);
  PairStringString_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairStringString_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
