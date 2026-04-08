#include <gtest/gtest.h>

#include <string>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/PairStringBool_c_api.h"
#include "falcon-core/generic/String_c_api.h"

class PairStringBoolTest : public ::testing::Test {
 protected:
  void SetUp() override {
    t1    = String_wrap("hello");
    t2    = true;
    pair1 = PairStringBool_create(t1, t2);
    pair2 = PairStringBool_create(t1, t2);
  }
  void TearDown() override {
    PairStringBool_destroy(pair1);
    PairStringBool_destroy(pair2);
    String_destroy(t1);
  }
  PairStringBoolHandle pair1;
  PairStringBoolHandle pair2;
  StringHandle         t1;
  bool                 t2;
  bool                 String_equal(StringHandle a, StringHandle b) {
    if (a == nullptr || b == nullptr) {
      throw std::invalid_argument("Null StringHandle provided");
    }
    std::string str_a = std::string(a->raw, a->length);
    std::string str_b = std::string(b->raw, b->length);
    return std::string(str_a) == std::string(str_b);
  }
};

TEST_F(PairStringBoolTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairStringBool_create(nullptr, t2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairStringBool_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairStringBoolTest, Accessors) {
  auto f = PairStringBool_first(pair1);
  EXPECT_TRUE(String_equal(f, t1));
  set_last_error(0, nullptr);
  PairStringBool_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairStringBool_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairStringBoolTest, Equality) {
  EXPECT_TRUE(PairStringBool_equal(pair1, pair2));
  EXPECT_FALSE(PairStringBool_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairStringBool_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairStringBool_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairStringBool_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairStringBool_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairStringBoolTest, ToJsonFromJson) {
  auto json = PairStringBool_to_json_string(pair1);
  auto p2   = PairStringBool_from_json_string(json);
  EXPECT_TRUE(PairStringBool_equal(pair1, p2));
  PairStringBool_destroy(p2);
  set_last_error(0, nullptr);
  PairStringBool_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairStringBool_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
