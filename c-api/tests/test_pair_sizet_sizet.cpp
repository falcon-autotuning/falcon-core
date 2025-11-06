#include <gtest/gtest.h>

#include <string>

#include "falcon_core/generic/PairSizeTSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class PairSizeTSizeTTest : public ::testing::Test {
 protected:
  void SetUp() override {
    t1    = 2;
    t2    = 1;
    pair1 = PairSizeTSizeT_create(t1, t2);
    pair2 = PairSizeTSizeT_create(t1, t2);
  }
  void TearDown() override {
    PairSizeTSizeT_destroy(pair1);
    PairSizeTSizeT_destroy(pair2);
  }
  PairSizeTSizeTHandle pair1;
  PairSizeTSizeTHandle pair2;
  size_t               t1;
  size_t               t2;
  bool                 String_equal(StringHandle a, StringHandle b) {
    if (a == nullptr || b == nullptr) {
      throw std::invalid_argument("Null StringHandle provided");
    }
    std::string str_a = std::string(a->raw, a->length);
    std::string str_b = std::string(b->raw, b->length);
    return std::string(str_a) == std::string(str_b);
  }
};

TEST_F(PairSizeTSizeTTest, CreateDestroy) {
  EXPECT_THROW(PairSizeTSizeT_destroy(nullptr), std::invalid_argument);
}

TEST_F(PairSizeTSizeTTest, Accessors) {
  auto f = PairSizeTSizeT_first(pair1);
  auto s = PairSizeTSizeT_second(pair1);
  EXPECT_THROW(PairSizeTSizeT_first(nullptr), std::invalid_argument);
  EXPECT_THROW(PairSizeTSizeT_second(nullptr), std::invalid_argument);
}

TEST_F(PairSizeTSizeTTest, Equality) {
  EXPECT_TRUE(PairSizeTSizeT_equal(pair1, pair2));
  EXPECT_FALSE(PairSizeTSizeT_not_equal(pair1, pair2));
  EXPECT_THROW(PairSizeTSizeT_equal(nullptr, pair2), std::invalid_argument);
  EXPECT_THROW(PairSizeTSizeT_equal(pair1, nullptr), std::invalid_argument);
  EXPECT_THROW(PairSizeTSizeT_not_equal(nullptr, pair2), std::invalid_argument);
  EXPECT_THROW(PairSizeTSizeT_not_equal(pair1, nullptr), std::invalid_argument);
}

TEST_F(PairSizeTSizeTTest, ToJsonFromJson) {
  auto json = PairSizeTSizeT_to_json_string(pair1);
  auto p2   = PairSizeTSizeT_from_json_string(json);
  EXPECT_TRUE(PairSizeTSizeT_equal(pair1, p2));
  PairSizeTSizeT_destroy(p2);
  EXPECT_THROW(PairSizeTSizeT_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(PairSizeTSizeT_from_json_string(nullptr), std::invalid_argument);
}
