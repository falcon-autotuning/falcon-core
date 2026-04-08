#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/math/Sign_c_api.h"

class SignTest : public ::testing::Test {};

TEST_F(SignTest, PositiveValue) {
  int val = Sign_positive();
  EXPECT_EQ(val, 1);  // Assuming Sign::POSITIVE == 1
}

TEST_F(SignTest, NegativeValue) {
  int val = Sign_negative();
  EXPECT_EQ(val, -1);  // Assuming Sign::NEGATIVE == -1
}
