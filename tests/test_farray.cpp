#include <gtest/gtest.h>

#include <cereal/archives/json.hpp>
#include <sstream>
#include <xtensor/containers/xarray.hpp>
#include <xtensor/io/xio.hpp>

#include "falcon_core/generic/FArray.hpp"

namespace tests {
using namespace falcon_core::generic;
TEST(FArrayTest, BasicOperations) {
  std::vector<size_t> shape = {2, 2};
  FArray<double>      arr1  = *FArray<double>::zeros(shape);
  FArray<double>      arr2  = *FArray<double>::empty(shape);

  // Fill arr2 with values
  arr2(0, 0) = 1.0;
  arr2(0, 1) = 2.0;
  arr2(1, 0) = 3.0;
  arr2(1, 1) = 4.0;

  // Test operator+=
  arr1 += arr2;
  EXPECT_DOUBLE_EQ(arr1(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(arr1(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(arr1(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(arr1(1, 1), 4.0);

  // Test operator*=
  arr1 *= arr2;
  EXPECT_DOUBLE_EQ(arr1(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(arr1(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(arr1(1, 0), 9.0);
  EXPECT_DOUBLE_EQ(arr1(1, 1), 16.0);

  // Test operator-=
  arr1 -= arr2;
  EXPECT_DOUBLE_EQ(arr1(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(arr1(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(arr1(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(arr1(1, 1), 12.0);

  // Test operator/=
  arr1 /= arr2;
  EXPECT_DOUBLE_EQ(arr1(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(arr1(0, 1), 1.0);
  EXPECT_DOUBLE_EQ(arr1(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(arr1(1, 1), 3.0);

  // Test comparison
  FArray<double> arr3 = arr1;
  EXPECT_TRUE(arr1 == arr3);
  arr3(0, 0) = 42.0;
  EXPECT_FALSE(arr1 == arr3);
}
TEST(FArrayTest, MathAndUtilityMethods) {
  std::vector<size_t> shape = {2, 2};
  FArray<double>      arr   = *FArray<double>::zeros(shape);

  arr(0, 0) = 1.0;
  arr(0, 1) = 2.0;
  arr(1, 0) = 3.0;
  arr(1, 1) = 4.0;

  // Test min, max, sum
  EXPECT_DOUBLE_EQ(arr.min(), 1.0);
  EXPECT_DOUBLE_EQ(arr.max(), 4.0);
  EXPECT_DOUBLE_EQ(arr.sum(), 10.0);

  // Test greater_than, less_than
  EXPECT_TRUE(arr > 3.0);
  EXPECT_TRUE(arr < 5.0);
  EXPECT_FALSE(arr > 4.0);
  EXPECT_FALSE(arr < 1.0);

  // Test remove_offset
  arr.remove_offset(1.0);
  EXPECT_DOUBLE_EQ(arr(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(arr(0, 1), 1.0);

  // Test reshape
  auto arr_reshaped = arr.reshape({4});
  ASSERT_EQ(arr_reshaped->shape()[0], 4);
  EXPECT_DOUBLE_EQ((*arr_reshaped)(0), 0.0);
  EXPECT_DOUBLE_EQ((*arr_reshaped)(1), 1.0);

  // Test where
  auto indices = *arr.where(1.0);
  ASSERT_EQ(indices.size(), 1);
  EXPECT_EQ(indices[0]->size(), 2);
  EXPECT_EQ((*indices[0])[0], 0);
  EXPECT_EQ((*indices[0])[1], 1);

  // Test flip
  auto arr_flipped = arr.flip(0);
  EXPECT_DOUBLE_EQ((*arr_flipped)(0, 0), arr(1, 0));
  EXPECT_DOUBLE_EQ((*arr_flipped)(1, 1), arr(0, 1));

  // Test abs
  arr(0, 0)    = -5.0;
  auto arr_abs = arr.abs();
  EXPECT_DOUBLE_EQ((*arr_abs)(0, 0), 5.0);

  // Test element-wise min/max
  FArray<double> arr2 = *FArray<double>::zeros(shape);
  arr2(0, 0)          = 2.0;
  arr2(0, 1)          = 0.5;
  arr2(1, 0)          = 3.5;
  arr2(1, 1)          = 4.5;
  auto arr_min        = arr.min(std::make_shared<FArray<double>>(arr2));
  auto arr_max        = arr.max(std::make_shared<FArray<double>>(arr2));
  EXPECT_DOUBLE_EQ((*arr_min)(0, 0), -5.0);
  EXPECT_DOUBLE_EQ((*arr_min)(0, 1), 0.5);
  EXPECT_DOUBLE_EQ((*arr_max)(1, 1), 4.5);

  // Test gradient
  auto grads = *arr.gradient();
  ASSERT_EQ(grads.size(), 2);
  auto grad0 = grads[0];
  auto grad1 = grads[1];
  ASSERT_EQ(grad0->shape(), arr.shape());
  ASSERT_EQ(grad1->shape(), arr.shape());
}

TEST(FArrayTest, ScalarAndElementwiseOperations) {
  std::vector<size_t> shape = {2, 2};
  FArray<double>      arr   = *FArray<double>::zeros(shape);
  arr(0, 0)                 = 1.0;
  arr(0, 1)                 = 2.0;
  arr(1, 0)                 = 3.0;
  arr(1, 1)                 = 4.0;

  // Scalar addition
  arr += 2.0;
  EXPECT_DOUBLE_EQ(arr(0, 0), 3.0);
  EXPECT_DOUBLE_EQ(arr(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(arr(1, 0), 5.0);
  EXPECT_DOUBLE_EQ(arr(1, 1), 6.0);

  arr += 2;
  EXPECT_DOUBLE_EQ(arr(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(arr(0, 1), 6.0);

  // Scalar subtraction
  arr -= 1.0;
  EXPECT_DOUBLE_EQ(arr(0, 0), 4.0);
  EXPECT_DOUBLE_EQ(arr(0, 1), 5.0);

  arr -= 1;
  EXPECT_DOUBLE_EQ(arr(0, 0), 3.0);
  EXPECT_DOUBLE_EQ(arr(0, 1), 4.0);

  // Scalar multiplication
  arr *= 2.0;
  EXPECT_DOUBLE_EQ(arr(0, 0), 6.0);
  EXPECT_DOUBLE_EQ(arr(0, 1), 8.0);

  arr *= 2;
  EXPECT_DOUBLE_EQ(arr(0, 0), 12.0);
  EXPECT_DOUBLE_EQ(arr(0, 1), 16.0);

  // Scalar division
  arr /= 2.0;
  EXPECT_DOUBLE_EQ(arr(0, 0), 6.0);
  EXPECT_DOUBLE_EQ(arr(0, 1), 8.0);

  arr /= 2;
  EXPECT_DOUBLE_EQ(arr(0, 0), 3.0);
  EXPECT_DOUBLE_EQ(arr(0, 1), 4.0);

  // Non-mutating operators
  auto arr_plus = arr + 1.0;
  EXPECT_DOUBLE_EQ((*arr_plus)(0, 0), 4.0);

  auto arr_minus = arr - 1;
  EXPECT_DOUBLE_EQ((*arr_minus)(0, 0), 2.0);

  auto arr_times = arr * 2.0;
  EXPECT_DOUBLE_EQ((*arr_times)(0, 0), 6.0);

  auto arr_div = arr / 3;
  EXPECT_DOUBLE_EQ((*arr_div)(0, 0), 1.0);

  // Elementwise operations with another array
  FArray<double> arr2 = *FArray<double>::zeros(shape);
  arr2(0, 0)          = 1.0;
  arr2(0, 1)          = 2.0;
  arr2(1, 0)          = 3.0;
  arr2(1, 1)          = 4.0;

  arr += arr2;
  EXPECT_DOUBLE_EQ(arr(0, 0), 4.0);
  EXPECT_DOUBLE_EQ(arr(0, 1), 6.0);

  arr -= arr2;
  EXPECT_DOUBLE_EQ(arr(0, 0), 3.0);
  EXPECT_DOUBLE_EQ(arr(0, 1), 4.0);

  arr *= arr2;
  EXPECT_DOUBLE_EQ(arr(0, 0), 3.0);
  EXPECT_DOUBLE_EQ(arr(0, 1), 8.0);

  arr /= arr2;
  EXPECT_DOUBLE_EQ(arr(0, 0), 3.0);
  EXPECT_DOUBLE_EQ(arr(0, 1), 4.0);
}
TEST(FArrayTest, SerializationRoundTrip) {
  std::vector<size_t> shape = {2, 3};
  FArray<double>      arr(shape);
  arr(0, 0) = 1.1;
  arr(0, 1) = 2.2;
  arr(0, 2) = 3.3;
  arr(1, 0) = 4.4;
  arr(1, 1) = 5.5;
  arr(1, 2) = 6.6;

  // Serialize to JSON
  std::stringstream ss;
  {
    cereal::JSONOutputArchive oarchive(ss);
    oarchive(arr);
  }

  // Deserialize from JSON
  FArray<double> arr2;
  {
    cereal::JSONInputArchive iarchive(ss);
    iarchive(arr2);
  }

  ASSERT_EQ(arr.shape(), arr2.shape());
  for (size_t i = 0; i < arr.shape()[0]; ++i) {
    for (size_t j = 0; j < arr.shape()[1]; ++j) {
      EXPECT_DOUBLE_EQ(arr(i, j), arr2(i, j));
    }
  }
}
}  // namespace tests
