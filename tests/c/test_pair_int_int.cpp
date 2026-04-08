#include <gtest/gtest.h>

#include <string>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/PairIntInt_c_api.h"
#include "falcon-core/generic/String_c_api.h"

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
  set_last_error(0, nullptr);
  PairIntInt_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairIntIntTest, Accessors) {
  set_last_error(0, nullptr);
  PairIntInt_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairIntInt_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairIntIntTest, Equality) {
  EXPECT_TRUE(PairIntInt_equal(pair1, pair2));
  EXPECT_FALSE(PairIntInt_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairIntInt_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairIntInt_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairIntInt_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairIntInt_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairIntIntTest, ToJsonFromJson) {
  auto json = PairIntInt_to_json_string(pair1);
  auto p2   = PairIntInt_from_json_string(json);
  EXPECT_TRUE(PairIntInt_equal(pair1, p2));
  PairIntInt_destroy(p2);
  set_last_error(0, nullptr);
  PairIntInt_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairIntInt_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
