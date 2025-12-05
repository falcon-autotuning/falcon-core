#include <gtest/gtest.h>

#include <cereal/archives/json.hpp>
#include <sstream>
#include <stdexcept>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>

#include "falcon_core/generic/FArray.hpp"

namespace {
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
  arr(0, 0)                 = 1.0;
  arr(0, 1)                 = 2.0;
  arr(1, 0)                 = 3.0;
  arr(1, 1)                 = 4.0;
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

// Additional tests for shared_ptr overloads and nullptr error handling
TEST(FArrayTest, SharedPtrOperatorsAndNullptr) {
  std::vector<size_t> shape = {2, 2};
  auto                arr1  = FArray<double>::zeros(shape);
  auto                arr2  = FArray<double>::zeros(shape);
  (*arr1)(0, 0)             = 1.0;
  (*arr1)(0, 1)             = 2.0;
  (*arr1)(1, 0)             = 3.0;
  (*arr1)(1, 1)             = 4.0;
  (*arr2)(0, 0)             = 4.0;
  (*arr2)(0, 1)             = 3.0;
  (*arr2)(1, 0)             = 2.0;
  (*arr2)(1, 1)             = 1.0;

  // operator+ with shared_ptr
  auto arr_sum = (*arr1) + arr2;
  EXPECT_DOUBLE_EQ((*arr_sum)(0, 0), 5.0);
  EXPECT_DOUBLE_EQ((*arr_sum)(1, 1), 5.0);

  // operator- with shared_ptr
  auto arr_diff = (*arr1) - arr2;
  EXPECT_DOUBLE_EQ((*arr_diff)(0, 0), -3.0);
  EXPECT_DOUBLE_EQ((*arr_diff)(1, 1), 3.0);

  // operator* with shared_ptr
  auto arr_prod = (*arr1) * arr2;
  EXPECT_DOUBLE_EQ((*arr_prod)(0, 0), 4.0);
  EXPECT_DOUBLE_EQ((*arr_prod)(1, 1), 4.0);

  // operator/ with shared_ptr
  auto arr_div = (*arr1) / arr2;
  EXPECT_DOUBLE_EQ((*arr_div)(0, 0), 0.25);
  EXPECT_DOUBLE_EQ((*arr_div)(1, 1), 4.0);

  // min/max with shared_ptr
  auto arr_min = (*arr1).min(arr2);
  auto arr_max = (*arr1).max(arr2);
  EXPECT_DOUBLE_EQ((*arr_min)(0, 0), 1.0);
  EXPECT_DOUBLE_EQ((*arr_max)(0, 0), 4.0);

  // nullptr error handling
  std::shared_ptr<FArray<double>> null_arr;
  EXPECT_THROW((*arr1) + null_arr, std::invalid_argument);
  EXPECT_THROW((*arr1) - null_arr, std::invalid_argument);
  EXPECT_THROW((*arr1) * null_arr, std::invalid_argument);
  EXPECT_THROW((*arr1) / null_arr, std::invalid_argument);
  EXPECT_THROW((*arr1).min(null_arr), std::invalid_argument);
  EXPECT_THROW((*arr1).max(null_arr), std::invalid_argument);
}

TEST(FArrayTest, PowerOperator) {
  std::vector<size_t> shape = {2, 2};
  FArray<double>      arr   = *FArray<double>::zeros(shape);
  arr(0, 0)                 = 2.0;
  arr(0, 1)                 = 3.0;
  arr(1, 0)                 = 4.0;
  arr(1, 1)                 = 5.0;
  arr.pow_inplace(2.0);
  EXPECT_DOUBLE_EQ((arr)(0, 0), 4.0);
  EXPECT_DOUBLE_EQ((arr)(0, 1), 9.0);
  EXPECT_DOUBLE_EQ((arr)(1, 0), 16.0);
  EXPECT_DOUBLE_EQ((arr)(1, 1), 25.0);
}
TEST(FArrayTest, OperatorParenthesesConstAndNonConst) {
  std::vector<size_t> shape = {2, 2};
  FArray<double>      arr   = *FArray<double>::zeros(shape);
  arr(0, 0)                 = 10.0;
  arr(0, 1)                 = 20.0;
  arr(1, 0)                 = 30.0;
  arr(1, 1)                 = 40.0;

  // Non-const version: should allow assignment
  arr(0, 0) = 100.0;
  EXPECT_DOUBLE_EQ(arr(0, 0), 100.0);

  // Const version: should allow reading but not writing
  const FArray<double>& carr = arr;
  double                v    = carr(1, 1);
  EXPECT_DOUBLE_EQ(v, 40.0);

  // Multi-index (variadic) operator() for both const and non-const
  arr(1, 0) = 300.0;
  EXPECT_DOUBLE_EQ(arr(1, 0), 300.0);
  double v2 = carr(0, 1);
  EXPECT_DOUBLE_EQ(v2, 20.0);

  // Test that const operator() returns the same as non-const for the same index
  EXPECT_DOUBLE_EQ(arr(0, 1), carr(0, 1));
}

TEST(FArrayIntTest, BasicIntOps) {
  std::vector<size_t> shape = {2, 2};
  FArray<int>         arr   = *FArray<int>::zeros(shape);
  arr(0, 0)                 = 1;
  arr(0, 1)                 = 2;
  arr(1, 0)                 = 3;
  arr(1, 1)                 = 4;
  // Scalar ops
  arr += 2;
  EXPECT_EQ(arr(0, 0), 3);
  arr -= 1;
  EXPECT_EQ(arr(0, 0), 2);
  arr *= 2;
  EXPECT_EQ(arr(0, 0), 4);
  arr /= 2;
  EXPECT_EQ(arr(0, 0), 2);
  // Non-mutating ops
  auto arr_plus = arr + 1;
  EXPECT_EQ((*arr_plus)(0, 0), 3);
  auto arr_minus = arr - 1;
  EXPECT_EQ((*arr_minus)(0, 0), 1);
  auto arr_times = arr * 2;
  EXPECT_EQ((*arr_times)(0, 0), 4);
  auto arr_div = arr / 2;
  EXPECT_EQ((*arr_div)(0, 0), 1);
  // Elementwise ops
  FArray<int> arr2 = *FArray<int>::zeros(shape);
  arr2(0, 0)       = 1;
  arr2(0, 1)       = 2;
  arr2(1, 0)       = 3;
  arr2(1, 1)       = 4;
  arr += arr2;
  EXPECT_EQ(arr(0, 0), 3);
  arr -= arr2;
  EXPECT_EQ(arr(0, 0), 2);
  arr *= arr2;
  EXPECT_EQ(arr(0, 0), 2);
  arr /= arr2;
  EXPECT_EQ(arr(0, 0), 2);
}

TEST(FArrayTest, OperatorParenthesesConstAndNonConstInt) {
  std::vector<size_t> shape = {2, 2};
  FArray<int>         arr   = *FArray<int>::zeros(shape);
  arr(0, 0)                 = 10;
  arr(0, 1)                 = 20;
  arr(1, 0)                 = 30;
  arr(1, 1)                 = 40;
  arr(0)                    = 100;
  EXPECT_EQ(arr(0), 100);
  const FArray<int>& carr = arr;
  int                v    = carr(1, 1);
  EXPECT_EQ(v, 40);
  arr(1, 0) = 300;
  EXPECT_EQ(arr(1, 0), 300);
  int v2 = carr(0, 1);
  EXPECT_EQ(v2, 20);
  EXPECT_EQ(arr(0, 1), carr(0, 1));
}

TEST(FArrayTest, BeginEndIterators) {
  std::vector<size_t> shape = {2, 2};
  FArray<double>      arr   = *FArray<double>::zeros(shape);
  arr(0, 0)                 = 1.0;
  arr(0, 1)                 = 2.0;
  arr(1, 0)                 = 3.0;
  arr(1, 1)                 = 4.0;
  double sum                = 0.0;
  for (auto it = arr.begin(); it != arr.end(); ++it) {
    sum += *it;
  }
  EXPECT_DOUBLE_EQ(sum, 10.0);
  sum = 0.0;
  for (auto it = arr.cbegin(); it != arr.cend(); ++it) {
    sum += *it;
  }
  EXPECT_DOUBLE_EQ(sum, 10.0);
}

TEST(FArrayTest, DataAndXtensorAccess) {
  std::vector<size_t> shape = {2, 2};
  FArray<double>      arr   = *FArray<double>::zeros(shape);
  arr(0, 0)                 = 1.0;
  arr(0, 1)                 = 2.0;
  arr(1, 0)                 = 3.0;
  arr(1, 1)                 = 4.0;
  double* data_ptr          = arr.raw_data();
  EXPECT_EQ(data_ptr[0], 1.0);
  auto& xt = arr.data();
  EXPECT_EQ(xt(0, 1), 2.0);
  const FArray<double>& carr      = arr;
  const double*         cdata_ptr = carr.raw_data();
  EXPECT_EQ(cdata_ptr[2], 3.0);
  const auto& cxt = carr.data();
  EXPECT_EQ(cxt(1, 1), 4.0);
}

TEST(FArrayIntTest, ScalarAndElementwiseOps) {
  std::vector<size_t> shape = {2, 2};
  FArray<int>         arr   = *FArray<int>::zeros(shape);
  arr(0, 0)                 = 1;
  arr(0, 1)                 = 2;
  arr(1, 0)                 = 3;
  arr(1, 1)                 = 4;
  arr += 1;
  arr -= 1;
  arr *= 2;
  arr /= 2;
  FArray<int> arr2 = *FArray<int>::zeros(shape);
  arr2(0, 0)       = 1;
  arr2(0, 1)       = 2;
  arr2(1, 0)       = 3;
  arr2(1, 1)       = 4;
  arr += arr2;
  arr -= arr2;
  arr *= arr2;
  arr /= arr2;
  EXPECT_EQ(arr(0, 0), 1);
}

TEST(FArrayIntTest, ArithmeticReturnOps) {
  std::vector<size_t> shape = {2, 2};
  FArray<int>         arr   = *FArray<int>::zeros(shape);
  arr(0, 0)                 = 1;
  arr(0, 1)                 = 2;
  arr(1, 0)                 = 3;
  arr(1, 1)                 = 4;
  auto arr_plus             = arr + 1;
  auto arr_minus            = arr - 1;
  auto arr_times            = arr * 2;
  auto arr_div              = arr / 2;
  EXPECT_EQ((*arr_plus)(0, 0), 2);
  EXPECT_EQ((*arr_minus)(0, 0), 0);
  EXPECT_EQ((*arr_times)(0, 0), 2);
  EXPECT_EQ((*arr_div)(0, 0), 0);
}

TEST(FArrayIntTest, UtilityMethods) {
  std::vector<size_t> shape = {2, 2};
  FArray<int>         arr   = *FArray<int>::zeros(shape);
  arr(0, 0)                 = 1;
  arr(0, 1)                 = 2;
  arr(1, 0)                 = 3;
  arr(1, 1)                 = 4;
  arr.remove_offset(1);
  EXPECT_EQ(arr.min(), 0);
  EXPECT_EQ(arr.max(), 3);
  EXPECT_EQ(arr.sum(), 6);
}

TEST(FArrayIntTest, WhereReshapeFlipGradient) {
  std::vector<size_t> shape = {2, 2};
  FArray<int>         arr   = *FArray<int>::zeros(shape);
  arr(0, 0)                 = 0;
  arr(0, 1)                 = 2;
  arr(1, 0)                 = 3;
  arr(1, 1)                 = 0;
  auto indices              = arr.where(0);
  ASSERT_EQ(indices->size(), 2);
  auto arr_reshaped = arr.reshape({4});
  ASSERT_EQ(arr_reshaped->shape()[0], 4);
  auto arr_flipped = arr.flip(0);
  ASSERT_EQ(arr_flipped->shape(), arr.shape());
  auto grads = arr.gradient();
  ASSERT_EQ(grads->size(), 2);
}

TEST(FArrayIntTest, IteratorsAndConversion) {
  std::vector<size_t> shape = {2, 2};
  FArray<int>         arr   = *FArray<int>::zeros(shape);
  arr(0, 0)                 = 1;
  arr(0, 1)                 = 2;
  arr(1, 0)                 = 3;
  arr(1, 1)                 = 4;
  int sum                   = 0;
  for (auto it = arr.begin(); it != arr.end(); ++it) sum += *it;
  EXPECT_EQ(sum, 10);
  sum = 0;
  for (auto it = arr.cbegin(); it != arr.cend(); ++it) sum += *it;
  EXPECT_EQ(sum, 10);
  xt::xarray<int>&       xtarr  = arr;
  const xt::xarray<int>& cxtarr = static_cast<const FArray<int>&>(arr);
  EXPECT_EQ(xtarr(0, 0), 1);
  EXPECT_EQ(cxtarr(1, 1), 4);
}

TEST(FArrayIntTest, SerializationJson) {
  std::vector<size_t> shape = {2, 2};
  FArray<int>         arr   = *FArray<int>::zeros(shape);
  arr(0, 0)                 = 1;
  arr(0, 1)                 = 2;
  arr(1, 0)                 = 3;
  arr(1, 1)                 = 4;
  std::stringstream ss;
  {
    cereal::JSONOutputArchive oarchive(ss);
    oarchive(arr);
  }
  FArray<int> arr2;
  {
    cereal::JSONInputArchive iarchive(ss);
    iarchive(arr2);
  }
  EXPECT_EQ(arr2.shape(), arr.shape());
  EXPECT_EQ(arr2(0, 0), 1);
  EXPECT_EQ(arr2(1, 1), 4);
}

TEST(FArrayIntTest, WhereReshapeFlipGradient5x5) {
  std::vector<size_t> shape = {5, 5};
  FArray<int>         arr   = *FArray<int>::zeros(shape);
  // Fill arr with a pattern: arr(i, j) = i + j
  for (size_t i = 0; i < 5; ++i) {
    for (size_t j = 0; j < 5; ++j) {
      arr(i, j) = static_cast<int>(i + j);
    }
  }
  // Set a few zeros for where()
  arr(0, 0)    = 0;
  arr(2, 2)    = 0;
  arr(4, 4)    = 0;
  auto indices = arr.where(0);
  ASSERT_EQ(indices->size(), 3);
  auto arr_reshaped = arr.reshape({25});
  ASSERT_EQ(arr_reshaped->shape()[0], 25);
  auto arr_flipped = arr.flip(0);
  ASSERT_EQ(arr_flipped->shape(), arr.shape());
  auto grads = arr.gradient();
  ASSERT_EQ(grads->size(), 2);
  // Check gradient shapes
  for (const auto& grad : *grads) {
    ASSERT_EQ(grad->shape(), arr.shape());
  }
}

TEST(FArrayDoubleTest, OperatorPowerAndDivideWithDouble) {
  std::vector<size_t>  shape = {2, 2};
  xt::xarray<double>   data  = {{2.0, 4.0}, {8.0, 16.0}};
  const FArray<double> arr(data);

  // Test operator^ with double
  auto arr_pow = arr ^ 2.0;
  ASSERT_EQ(arr_pow->shape(), arr.shape());
  EXPECT_DOUBLE_EQ((*arr_pow)(0, 0), 4.0);
  EXPECT_DOUBLE_EQ((*arr_pow)(0, 1), 16.0);
  EXPECT_DOUBLE_EQ((*arr_pow)(1, 0), 64.0);
  EXPECT_DOUBLE_EQ((*arr_pow)(1, 1), 256.0);

  // Test operator/ with double
  auto arr_div = arr / 2.0;
  ASSERT_EQ(arr_div->shape(), arr.shape());
  EXPECT_DOUBLE_EQ((*arr_div)(0, 0), 1.0);
  EXPECT_DOUBLE_EQ((*arr_div)(0, 1), 2.0);
  EXPECT_DOUBLE_EQ((*arr_div)(1, 0), 4.0);
  EXPECT_DOUBLE_EQ((*arr_div)(1, 1), 8.0);
}
TEST(FArrayDoubleTest, OperatorNegationAndMinusDouble) {
  std::vector<size_t> shape = {2, 2};
  FArray<double>      arr   = *FArray<double>::zeros(shape);
  arr(0, 0)                 = 2.0;
  arr(0, 1)                 = 4.0;
  arr(1, 0)                 = 8.0;
  arr(1, 1)                 = 16.0;

  // Test unary negation operator-
  auto arr_neg = -arr;
  ASSERT_EQ(arr_neg->shape(), arr.shape());
  // If implemented correctly, values should be negated
  // EXPECT_DOUBLE_EQ((*arr_neg)(0, 0), -2.0);

  // Test operator- with double
  auto arr_minus = arr - 1.5;
  ASSERT_EQ(arr_minus->shape(), arr.shape());
  EXPECT_DOUBLE_EQ((*arr_minus)(0, 0), 0.5);
  EXPECT_DOUBLE_EQ((*arr_minus)(0, 1), 2.5);
  EXPECT_DOUBLE_EQ((*arr_minus)(1, 0), 6.5);
  EXPECT_DOUBLE_EQ((*arr_minus)(1, 1), 14.5);
}

TEST(FArrayIntTest, DimensionMethod) {
  std::vector<size_t> shape = {3, 4, 5};
  FArray<int>         arr   = *FArray<int>::zeros(shape);
  EXPECT_EQ(arr.dimension(), 3);
}

TEST(FArrayIntTest, SingleIndexOperatorNonConstAndConst) {
  std::vector<size_t> shape = {4};
  FArray<int>         arr   = *FArray<int>::zeros(shape);
  arr(2)                    = 42;
  EXPECT_EQ(arr(2), 42);

  const FArray<int>& carr = arr;
  EXPECT_EQ(carr(2), 42);
}

TEST(FArrayIntTest, MultiIndexOperatorWithRefs) {
  std::vector<size_t> shape = {2, 2};
  FArray<int>         arr   = *FArray<int>::zeros(shape);
  int                 i = 1, j = 0;
  arr(i, j) = 99;
  EXPECT_EQ(arr(i, j), 99);
}

TEST(FArrayDoubleTest, OperatorPowerConst) {
  std::vector<size_t> shape     = {2, 2};
  FArray<double>      arr       = *FArray<double>::zeros(shape);
  arr(0, 0)                     = 2.0;
  arr(0, 1)                     = 3.0;
  arr(1, 0)                     = 4.0;
  arr(1, 1)                     = 5.0;
  const FArray<double>& carr    = arr;
  auto                  arr_pow = carr ^ 2;
  ASSERT_EQ(arr_pow->shape(), arr.shape());
  EXPECT_DOUBLE_EQ((*arr_pow)(0, 0), 4.0);
  EXPECT_DOUBLE_EQ((*arr_pow)(0, 1), 9.0);
  EXPECT_DOUBLE_EQ((*arr_pow)(1, 0), 16.0);
  EXPECT_DOUBLE_EQ((*arr_pow)(1, 1), 25.0);
}

TEST(FArrayDoubleTest, OperatorDivideConst) {
  std::vector<size_t> shape     = {2, 2};
  FArray<double>      arr       = *FArray<double>::zeros(shape);
  arr(0, 0)                     = 4.0;
  arr(0, 1)                     = 8.0;
  arr(1, 0)                     = 16.0;
  arr(1, 1)                     = 32.0;
  const FArray<double>& carr    = arr;
  auto                  arr_div = carr / 2.0;
  ASSERT_EQ(arr_div->shape(), arr.shape());
  EXPECT_DOUBLE_EQ((*arr_div)(0, 0), 2.0);
  EXPECT_DOUBLE_EQ((*arr_div)(1, 1), 16.0);
}

TEST(FArrayDoubleTest, OperatorNegationConstAndNonConst) {
  std::vector<size_t> shape = {2, 2};
  FArray<double>      arr   = *FArray<double>::zeros(shape);
  arr(0, 0)                 = 1.0;
  arr(0, 1)                 = -2.0;
  arr(1, 0)                 = 3.0;
  arr(1, 1)                 = -4.0;

  // Non-const version
  auto arr_neg = -arr;
  ASSERT_EQ(arr_neg->shape(), arr.shape());

  // Const version
  const FArray<double>& carr          = arr;
  auto                  arr_neg_const = -carr;
  ASSERT_EQ(arr_neg_const->shape(), arr.shape());
}

TEST(FArrayIntTest, OperatorParenthesesSingleIndexNonConstAndConst) {
  std::vector<size_t> shape = {5};
  FArray<int>         arr   = *FArray<int>::zeros(shape);
  arr(3)                    = int(42);
  EXPECT_EQ(arr(3), 42);

  const FArray<int>& carr = arr;
  EXPECT_EQ(carr(3), 42);
}

TEST(FArrayIntTest, OperatorParenthesesMultiIndexWithRefs) {
  std::vector<size_t> shape = {2, 2};
  FArray<int>         arr   = *FArray<int>::zeros(shape);
  int                 i = 1, j = 0;
  arr(i, j) = 99;
  EXPECT_EQ(arr(i, j), 99);
}

}  // namespace
