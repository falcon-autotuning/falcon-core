#include <gtest/gtest.h>

#include <string>

#include "falcon_core/generic/PairIntInt_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class PairIntIntTest : public ::testing::Test {
 protected:
  void SetUp() override {
    t1    = 2;
    t2    = 1;
    pair1 = PairIntInt_create(t1, t2);
    pair2 = PairIntInt_create(t1, t2);
  }
  void TearDown() override {
    PairIntInt_destroy(pair1);
    PairIntInt_destroy(pair2);
  }
  PairIntIntHandle pair1;
  PairIntIntHandle pair2;
  int              t1;
  int              t2;
  bool             String_equal(StringHandle a, StringHandle b) {
    if (a == nullptr || b == nullptr) {
      throw std::invalid_argument("Null StringHandle provided");
    }
    std::string str_a = std::string(a->raw, a->length);
    std::string str_b = std::string(b->raw, b->length);
    return std::string(str_a) == std::string(str_b);
  }
};

TEST_F(PairIntIntTest, CreateDestroy) {
  EXPECT_THROW(PairIntInt_destroy(nullptr), std::invalid_argument);
}

TEST_F(PairIntIntTest, Accessors) {
  auto f = PairIntInt_first(pair1);
  auto s = PairIntInt_second(pair1);
  EXPECT_THROW(PairIntInt_first(nullptr), std::invalid_argument);
  EXPECT_THROW(PairIntInt_second(nullptr), std::invalid_argument);
}

TEST_F(PairIntIntTest, Equality) {
  EXPECT_TRUE(PairIntInt_equal(pair1, pair2));
  EXPECT_FALSE(PairIntInt_not_equal(pair1, pair2));
  EXPECT_THROW(PairIntInt_equal(nullptr, pair2), std::invalid_argument);
  EXPECT_THROW(PairIntInt_equal(pair1, nullptr), std::invalid_argument);
  EXPECT_THROW(PairIntInt_not_equal(nullptr, pair2), std::invalid_argument);
  EXPECT_THROW(PairIntInt_not_equal(pair1, nullptr), std::invalid_argument);
}

TEST_F(PairIntIntTest, ToJsonFromJson) {
  auto json = PairIntInt_to_json_string(pair1);
  auto p2   = PairIntInt_from_json_string(json);
  EXPECT_TRUE(PairIntInt_equal(pair1, p2));
  PairIntInt_destroy(p2);
  EXPECT_THROW(PairIntInt_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(PairIntInt_from_json_string(nullptr), std::invalid_argument);
}
