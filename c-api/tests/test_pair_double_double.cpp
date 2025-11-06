#include <gtest/gtest.h>

#include <string>

#include "falcon_core/generic/PairDoubleDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class PairDoubleDoubleTest : public ::testing::Test {
 protected:
  void SetUp() override {
    t1    = 2.0;
    t2    = 1.0;
    pair1 = PairDoubleDouble_create(t1, t2);
    pair2 = PairDoubleDouble_create(t1, t2);
  }
  void TearDown() override {
    PairDoubleDouble_destroy(pair1);
    PairDoubleDouble_destroy(pair2);
  }
  PairDoubleDoubleHandle pair1;
  PairDoubleDoubleHandle pair2;
  double                 t1;
  double                 t2;
  bool                   String_equal(StringHandle a, StringHandle b) {
    if (a == nullptr || b == nullptr) {
      throw std::invalid_argument("Null StringHandle provided");
    }
    std::string str_a = std::string(a->raw, a->length);
    std::string str_b = std::string(b->raw, b->length);
    return std::string(str_a) == std::string(str_b);
  }
};

TEST_F(PairDoubleDoubleTest, CreateDestroy) {
  EXPECT_THROW(PairDoubleDouble_destroy(nullptr), std::invalid_argument);
}

TEST_F(PairDoubleDoubleTest, Accessors) {
  auto f = PairDoubleDouble_first(pair1);
  auto s = PairDoubleDouble_second(pair1);
  EXPECT_THROW(PairDoubleDouble_first(nullptr), std::invalid_argument);
  EXPECT_THROW(PairDoubleDouble_second(nullptr), std::invalid_argument);
}

TEST_F(PairDoubleDoubleTest, Equality) {
  EXPECT_TRUE(PairDoubleDouble_equal(pair1, pair2));
  EXPECT_FALSE(PairDoubleDouble_not_equal(pair1, pair2));
  EXPECT_THROW(PairDoubleDouble_equal(nullptr, pair2), std::invalid_argument);
  EXPECT_THROW(PairDoubleDouble_equal(pair1, nullptr), std::invalid_argument);
  EXPECT_THROW(PairDoubleDouble_not_equal(nullptr, pair2),
               std::invalid_argument);
  EXPECT_THROW(PairDoubleDouble_not_equal(pair1, nullptr),
               std::invalid_argument);
}

TEST_F(PairDoubleDoubleTest, ToJsonFromJson) {
  auto json = PairDoubleDouble_to_json_string(pair1);
  auto p2   = PairDoubleDouble_from_json_string(json);
  EXPECT_TRUE(PairDoubleDouble_equal(pair1, p2));
  PairDoubleDouble_destroy(p2);
  EXPECT_THROW(PairDoubleDouble_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(PairDoubleDouble_from_json_string(nullptr),
               std::invalid_argument);
}
