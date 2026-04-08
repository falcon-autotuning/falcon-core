#include <gtest/gtest.h>

#include <string>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/PairFloatFloat_c_api.h"
#include "falcon-core/generic/String_c_api.h"

class PairFloatFloatTest : public ::testing::Test {
 protected:
  void SetUp() override {
    t1    = 2.0;
    t2    = 1.0;
    pair1 = PairFloatFloat_create(t1, t2);
    pair2 = PairFloatFloat_create(t1, t2);
  }
  void TearDown() override {
    PairFloatFloat_destroy(pair1);
    PairFloatFloat_destroy(pair2);
  }
  PairFloatFloatHandle pair1;
  PairFloatFloatHandle pair2;
  float                t1;
  float                t2;
  bool                 String_equal(StringHandle a, StringHandle b) {
    if (a == nullptr || b == nullptr) {
      throw std::invalid_argument("Null StringHandle provided");
    }
    std::string str_a = std::string(a->raw, a->length);
    std::string str_b = std::string(b->raw, b->length);
    return std::string(str_a) == std::string(str_b);
  }
};

TEST_F(PairFloatFloatTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairFloatFloat_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairFloatFloatTest, Accessors) {
  set_last_error(0, nullptr);
  PairFloatFloat_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairFloatFloat_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairFloatFloatTest, Equality) {
  EXPECT_TRUE(PairFloatFloat_equal(pair1, pair2));
  EXPECT_FALSE(PairFloatFloat_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairFloatFloat_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairFloatFloat_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairFloatFloat_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairFloatFloat_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairFloatFloatTest, ToJsonFromJson) {
  auto json = PairFloatFloat_to_json_string(pair1);
  auto p2   = PairFloatFloat_from_json_string(json);
  EXPECT_TRUE(PairFloatFloat_equal(pair1, p2));
  PairFloatFloat_destroy(p2);
  set_last_error(0, nullptr);
  PairFloatFloat_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairFloatFloat_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
