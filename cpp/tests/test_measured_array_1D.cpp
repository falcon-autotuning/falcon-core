
#include <gtest/gtest.h>

#include <stdexcept>
#include <xtensor/xarray.hpp>

#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/math/arrays/MeasuredArray1D.hpp"
namespace {
using namespace falcon_core;
using namespace generic;
using namespace math::arrays;

class MeasuredArray1DTest : public ::testing::Test {
 protected:
  xt::xarray<double> arr1 = {{1.0, 2.0}, {3.0, 4.0}};
  xt::xarray<double> arr2 = {{5.0, 6.0}, {7.0, 8.0}};
  MeasuredArray1DSP  ma1;
  MeasuredArray1DSP  ma2;
  void               SetUp() override {
    ma1 = std::make_shared<MeasuredArray1D>(arr1);
    ma2 = std::make_shared<MeasuredArray1D>(arr2);
  }
};

TEST_F(MeasuredArray1DTest, XtArrayConstructor) {
  MeasuredArray1D ma(arr1);
  EXPECT_EQ(ma.shape(), arr1.shape());
}

TEST_F(MeasuredArray1DTest, FArraySPConstructor) {
  auto            farr = std::make_shared<FArray<double>>(arr1);
  MeasuredArray1D ma(farr);
  EXPECT_EQ(ma.shape(), arr1.shape());
}

TEST_F(MeasuredArray1DTest, FArraySPConstructorNullThrows) {
  FArraySP<double> dummy;
  EXPECT_THROW(MeasuredArray1D varname(dummy), std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, MoveXtArrayConstructor) {
  xt::xarray<double> arr = {{9.0, 10.0}, {11.0, 12.0}};
  MeasuredArray1D    ma(std::move(arr));
  EXPECT_EQ(ma.shape().size(), 2);
}

TEST_F(MeasuredArray1DTest, ZerosAndEmptyStatic) {
  auto zeros = MeasuredArray1D::zeros({2, 2});
  EXPECT_EQ(zeros->size(), 4);
  auto empty = MeasuredArray1D::empty({2, 2});
  EXPECT_EQ(empty->size(), 4);
}

TEST_F(MeasuredArray1DTest, ArithmeticAddDouble) {
  auto result = ma1->operator+(2.0);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) + 2.0);
}

TEST_F(MeasuredArray1DTest, ArithmeticAddInt) {
  auto result = ma1->operator+(3);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) + 3);
}

TEST_F(MeasuredArray1DTest, ArithmeticAddMeasuredArray) {
  auto result = ma1->operator+(ma2);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArray1DTest, ArithmeticAddMeasuredArrayNullThrows) {
  EXPECT_THROW(ma1->operator+((MeasuredArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, ArithmeticAddFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = ma1->operator+(farr);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArray1DTest, ArithmeticAddFArraySPNullThrows) {
  EXPECT_THROW(ma1->operator+((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, ArithmeticSubDouble) {
  auto result = ma1->operator-(2.0);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) - 2.0);
}

TEST_F(MeasuredArray1DTest, ArithmeticSubInt) {
  auto result = ma1->operator-(1);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) - 1);
}

TEST_F(MeasuredArray1DTest, ArithmeticSubMeasuredArray) {
  auto result = ma1->operator-(ma2);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArray1DTest, ArithmeticSubMeasuredArrayNullThrows) {
  EXPECT_THROW(ma1->operator-((MeasuredArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, ArithmeticSubFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = ma1->operator-(farr);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArray1DTest, ArithmeticSubFArraySPNullThrows) {
  EXPECT_THROW(ma1->operator-((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, ArithmeticNegation) {
  auto result = ma1->operator-();
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), -(*ma1)(0, 0));
}

TEST_F(MeasuredArray1DTest, ArithmeticMulDouble) {
  auto result = ma1->operator*(2.0);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) * 2.0);
}

TEST_F(MeasuredArray1DTest, ArithmeticMulInt) {
  auto result = ma1->operator*(3);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) * 3);
}

TEST_F(MeasuredArray1DTest, ArithmeticMulMeasuredArray) {
  auto result = ma1->operator*(ma2);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArray1DTest, ArithmeticMulMeasuredArrayNullThrows) {
  EXPECT_THROW(ma1->operator*((MeasuredArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, ArithmeticMulFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = ma1->operator*(farr);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArray1DTest, ArithmeticMulFArraySPNullThrows) {
  EXPECT_THROW(ma1->operator*((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, ArithmeticDivDouble) {
  auto result = ma1->operator/(2.0);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) / 2.0);
}

TEST_F(MeasuredArray1DTest, ArithmeticDivInt) {
  auto result = ma1->operator/(2);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) / 2.0);
}

TEST_F(MeasuredArray1DTest, ArithmeticDivMeasuredArray) {
  auto result = ma1->operator/(ma2);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArray1DTest, ArithmeticDivMeasuredArrayNullThrows) {
  EXPECT_THROW(ma1->operator/((MeasuredArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, ArithmeticDivFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = ma1->operator/(farr);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArray1DTest, ArithmeticDivFArraySPNullThrows) {
  EXPECT_THROW(ma1->operator/((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, ArithmeticPow) {
  auto result = ma1->operator^(2.0);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), std::pow((*ma1)(0, 0), 2.0));
}

TEST_F(MeasuredArray1DTest, Abs) {
  auto result = ma1->abs();
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), std::abs((*ma1)(0, 0)));
}

TEST_F(MeasuredArray1DTest, MinMeasuredArray) {
  auto result = ma1->min(ma2);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArray1DTest, MinMeasuredArrayNullThrows) {
  EXPECT_THROW(ma1->min((MeasuredArray1DSP) nullptr), std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, MinFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = ma1->min(farr);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArray1DTest, MinFArraySPNullThrows) {
  EXPECT_THROW(ma1->min((FArraySP<double>)nullptr), std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, MaxMeasuredArray) {
  auto result = ma1->max(ma2);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArray1DTest, MaxMeasuredArrayNullThrows) {
  EXPECT_THROW(ma1->max((MeasuredArray1DSP) nullptr), std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, MaxFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = ma1->max(farr);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArray1DTest, MaxFArraySPNullThrows) {
  EXPECT_THROW(ma1->max((FArraySP<double>)nullptr), std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, Reshape) {
  auto reshaped = ma1->reshape({4});
  EXPECT_EQ(reshaped->size(), 4);
}

TEST_F(MeasuredArray1DTest, Flip) {
  auto flipped = ma1->flip(0);
  EXPECT_EQ(flipped->shape(), ma1->shape());
}

TEST_F(MeasuredArray1DTest, GradientAxis) {
  auto grad = ma1->gradient(0);
  EXPECT_EQ(grad->shape().size(), 2);
  EXPECT_EQ(grad->size(), ma1->size());
}

TEST_F(MeasuredArray1DTest, GradientAllAxes) {
  auto grads = ma1->gradient();
  EXPECT_GT(grads->size(), 0);
}

TEST_F(MeasuredArray1DTest, SerializationRoundTrip) {
  auto string = ma1->to_json_string();
  auto other  = MeasuredArray1D::from_json_string<MeasuredArray>(string);
  EXPECT_EQ(*ma1, *other);
}
}  // namespace
