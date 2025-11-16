#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include <string>

#include "falcon_core/generic/PairIntFloat_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class PairIntFloatTest : public ::testing::Test {
 protected:
  void SetUp() override {
    t1    = 2;
    t2    = 1.0;
    pair1 = PairIntFloat_create(t1, t2);
    pair2 = PairIntFloat_create(t1, t2);
  }
  void TearDown() override {
    PairIntFloat_destroy(pair1);
    PairIntFloat_destroy(pair2);
  }
  PairIntFloatHandle pair1;
  PairIntFloatHandle pair2;
  int                t1;
  float              t2;
  bool               String_equal(StringHandle a, StringHandle b) {
    if (a == nullptr || b == nullptr) {
      throw std::invalid_argument("Null StringHandle provided");
    }
    std::string str_a = std::string(a->raw, a->length);
    std::string str_b = std::string(b->raw, b->length);
    return std::string(str_a) == std::string(str_b);
  }
};

TEST_F(PairIntFloatTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairIntFloat_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairIntFloatTest, Accessors) {
  auto f = PairIntFloat_first(pair1);
  auto s = PairIntFloat_second(pair1);
  set_last_error(0, nullptr);
  PairIntFloat_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairIntFloat_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairIntFloatTest, Equality) {
  EXPECT_TRUE(PairIntFloat_equal(pair1, pair2));
  EXPECT_FALSE(PairIntFloat_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairIntFloat_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairIntFloat_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairIntFloat_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairIntFloat_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairIntFloatTest, ToJsonFromJson) {
  auto json = PairIntFloat_to_json_string(pair1);
  auto p2   = PairIntFloat_from_json_string(json);
  EXPECT_TRUE(PairIntFloat_equal(pair1, p2));
  PairIntFloat_destroy(p2);
  set_last_error(0, nullptr);
  PairIntFloat_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairIntFloat_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
