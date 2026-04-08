#include <gtest/gtest.h>

#include "falcon-core/math/arrays/IncreasingAlignment.hpp"

namespace {
using namespace falcon_core::math::arrays;

class IncreasingAlignmentTest : public ::testing::Test {};

TEST_F(IncreasingAlignmentTest, DefaultConstructor) {
  IncreasingAlignment align;
  EXPECT_EQ(align.alignment(), 0);
}

TEST_F(IncreasingAlignmentTest, BoolConstructorTrue) {
  IncreasingAlignment align(true);
  EXPECT_EQ(align.alignment(), 1);
}

TEST_F(IncreasingAlignmentTest, BoolConstructorFalse) {
  IncreasingAlignment align(false);
  EXPECT_EQ(align.alignment(), -1);
}

TEST_F(IncreasingAlignmentTest, EqualityOperators) {
  IncreasingAlignment a1(true);
  IncreasingAlignment a2(true);
  IncreasingAlignment a3(false);
  IncreasingAlignment a4;
  EXPECT_TRUE(a1 == a2);
  EXPECT_FALSE(a1 != a2);
  EXPECT_FALSE(a1 == a3);
  EXPECT_TRUE(a1 != a3);
  EXPECT_FALSE(a1 == a4);
  EXPECT_TRUE(a1 != a4);
}

TEST_F(IncreasingAlignmentTest, SerializationRoundTrip) {
  IncreasingAlignment original(true);
  auto                string = original.to_json_string();
  auto                restored =
      IncreasingAlignment::from_json_string<IncreasingAlignment>(string);
  EXPECT_EQ(original, *restored);
}

}  // namespace
