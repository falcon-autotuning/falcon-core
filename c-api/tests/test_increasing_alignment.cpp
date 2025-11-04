#include <gtest/gtest.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/IncreasingAlignment_c_api.h"

class IncreasingAlignmentTest : public ::testing::Test {
 protected:
  void SetUp() override {
    ia_true  = IncreasingAlignment_create(true);
    ia_false = IncreasingAlignment_create(false);
    ia_empty = IncreasingAlignment_create_empty();
  }
  void TearDown() override {
    IncreasingAlignment_destroy(ia_true);
    IncreasingAlignment_destroy(ia_false);
    IncreasingAlignment_destroy(ia_empty);
  }
  IncreasingAlignmentHandle ia_true  = nullptr;
  IncreasingAlignmentHandle ia_false = nullptr;
  IncreasingAlignmentHandle ia_empty = nullptr;
};

TEST_F(IncreasingAlignmentTest, CreateDestroy) {
  auto ia = IncreasingAlignment_create(true);
  IncreasingAlignment_destroy(ia);
  ia = IncreasingAlignment_create(false);
  IncreasingAlignment_destroy(ia);
  ia = IncreasingAlignment_create_empty();
  IncreasingAlignment_destroy(ia);
  EXPECT_THROW(IncreasingAlignment_destroy(nullptr), std::invalid_argument);
}

TEST_F(IncreasingAlignmentTest, AlignmentAccessor) {
  EXPECT_EQ(IncreasingAlignment_alignment(ia_true), 1);
  EXPECT_EQ(IncreasingAlignment_alignment(ia_false), 0);
  EXPECT_EQ(IncreasingAlignment_alignment(ia_empty), 0);
  EXPECT_THROW(IncreasingAlignment_alignment(nullptr), std::invalid_argument);
}

TEST_F(IncreasingAlignmentTest, EqualityOperators) {
  EXPECT_TRUE(IncreasingAlignment_equal(ia_true, ia_true));
  EXPECT_FALSE(IncreasingAlignment_equal(ia_true, ia_false));
  EXPECT_TRUE(IncreasingAlignment_not_equal(ia_true, ia_false));
  EXPECT_FALSE(IncreasingAlignment_not_equal(ia_true, ia_true));
  EXPECT_THROW(IncreasingAlignment_equal(nullptr, ia_true),
               std::invalid_argument);
  EXPECT_THROW(IncreasingAlignment_equal(ia_true, nullptr),
               std::invalid_argument);
  EXPECT_THROW(IncreasingAlignment_not_equal(nullptr, ia_true),
               std::invalid_argument);
  EXPECT_THROW(IncreasingAlignment_not_equal(ia_true, nullptr),
               std::invalid_argument);
}

TEST_F(IncreasingAlignmentTest, ToJsonFromJson) {
  auto json_true  = IncreasingAlignment_to_json_string(ia_true);
  auto json_false = IncreasingAlignment_to_json_string(ia_false);
  auto ia_true2   = IncreasingAlignment_from_json_string(json_true);
  auto ia_false2  = IncreasingAlignment_from_json_string(json_false);
  EXPECT_TRUE(IncreasingAlignment_equal(ia_true, ia_true2));
  EXPECT_TRUE(IncreasingAlignment_equal(ia_false, ia_false2));
  IncreasingAlignment_destroy(ia_true2);
  IncreasingAlignment_destroy(ia_false2);
  String_destroy(json_true);
  String_destroy(json_false);
  EXPECT_THROW(IncreasingAlignment_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(IncreasingAlignment_from_json_string(nullptr),
               std::invalid_argument);
}
