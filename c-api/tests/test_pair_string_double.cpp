#include <gtest/gtest.h>

#include <string>

#include "falcon_core/generic/PairStringDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class PairStringDoubleTest : public ::testing::Test {
 protected:
  void SetUp() override {
    t1    = String_wrap("hello");
    t2    = 1.0;
    pair1 = PairStringDouble_create(t1, t2);
    pair2 = PairStringDouble_create(t1, t2);
  }
  void TearDown() override {
    PairStringDouble_destroy(pair1);
    PairStringDouble_destroy(pair2);
    String_destroy(t1);
  }
  PairStringDoubleHandle pair1;
  PairStringDoubleHandle pair2;
  StringHandle           t1;
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

TEST_F(PairStringDoubleTest, CreateDestroy) {
  EXPECT_THROW(PairStringDouble_create(nullptr, t2), std::invalid_argument);
  EXPECT_THROW(PairStringDouble_destroy(nullptr), std::invalid_argument);
}

TEST_F(PairStringDoubleTest, Accessors) {
  auto f = PairStringDouble_first(pair1);
  auto s = PairStringDouble_second(pair1);
  EXPECT_TRUE(String_equal(f, t1));
  EXPECT_THROW(PairStringDouble_first(nullptr), std::invalid_argument);
  EXPECT_THROW(PairStringDouble_second(nullptr), std::invalid_argument);
}

TEST_F(PairStringDoubleTest, Equality) {
  EXPECT_TRUE(PairStringDouble_equal(pair1, pair2));
  EXPECT_FALSE(PairStringDouble_not_equal(pair1, pair2));
  EXPECT_THROW(PairStringDouble_equal(nullptr, pair2), std::invalid_argument);
  EXPECT_THROW(PairStringDouble_equal(pair1, nullptr), std::invalid_argument);
  EXPECT_THROW(PairStringDouble_not_equal(nullptr, pair2),
               std::invalid_argument);
  EXPECT_THROW(PairStringDouble_not_equal(pair1, nullptr),
               std::invalid_argument);
}

TEST_F(PairStringDoubleTest, ToJsonFromJson) {
  auto json = PairStringDouble_to_json_string(pair1);
  auto p2   = PairStringDouble_from_json_string(json);
  EXPECT_TRUE(PairStringDouble_equal(pair1, p2));
  PairStringDouble_destroy(p2);
  EXPECT_THROW(PairStringDouble_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(PairStringDouble_from_json_string(nullptr),
               std::invalid_argument);
}
