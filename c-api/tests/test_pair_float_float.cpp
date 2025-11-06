#include <gtest/gtest.h>

#include <string>

#include "falcon_core/generic/PairFloatFloat_c_api.h"
#include "falcon_core/generic/String_c_api.h"

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
  EXPECT_THROW(PairFloatFloat_destroy(nullptr), std::invalid_argument);
}

TEST_F(PairFloatFloatTest, Accessors) {
  auto f = PairFloatFloat_first(pair1);
  auto s = PairFloatFloat_second(pair1);
  EXPECT_THROW(PairFloatFloat_first(nullptr), std::invalid_argument);
  EXPECT_THROW(PairFloatFloat_second(nullptr), std::invalid_argument);
}

TEST_F(PairFloatFloatTest, Equality) {
  EXPECT_TRUE(PairFloatFloat_equal(pair1, pair2));
  EXPECT_FALSE(PairFloatFloat_not_equal(pair1, pair2));
  EXPECT_THROW(PairFloatFloat_equal(nullptr, pair2), std::invalid_argument);
  EXPECT_THROW(PairFloatFloat_equal(pair1, nullptr), std::invalid_argument);
  EXPECT_THROW(PairFloatFloat_not_equal(nullptr, pair2), std::invalid_argument);
  EXPECT_THROW(PairFloatFloat_not_equal(pair1, nullptr), std::invalid_argument);
}

TEST_F(PairFloatFloatTest, ToJsonFromJson) {
  auto json = PairFloatFloat_to_json_string(pair1);
  auto p2   = PairFloatFloat_from_json_string(json);
  EXPECT_TRUE(PairFloatFloat_equal(pair1, p2));
  PairFloatFloat_destroy(p2);
  EXPECT_THROW(PairFloatFloat_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(PairFloatFloat_from_json_string(nullptr), std::invalid_argument);
}
