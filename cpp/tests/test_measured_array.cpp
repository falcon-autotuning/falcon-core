#include <gtest/gtest.h>

#include <stdexcept>
#include <xtensor/xarray.hpp>

#include "falcon_core/math/arrays/MeasuredArray.hpp"
namespace {
using namespace falcon_core;
using namespace math::arrays;

class MeasuredArrayTest : public ::testing::Test {
 protected:
  xt::xarray<double> arr1 = {{1.0, 2.0}, {3.0, 4.0}};
  xt::xarray<double> arr2 = {{5.0, 6.0}, {7.0, 8.0}};
  MeasuredArraySP    ma1;
  MeasuredArraySP    ma2;
  void               SetUp() override {
    ma1 = std::make_shared<MeasuredArray>(arr1);
    ma2 = std::make_shared<MeasuredArray>(arr2);
  }
};

TEST_F(MeasuredArrayTest, XtArrayConstructor) {
  MeasuredArray ma(arr1);
  EXPECT_EQ(ma.shape(), arr1.shape());
}

TEST_F(MeasuredArrayTest, FArraySPConstructor) {
  auto          farr = std::make_shared<generic::FArray<double>>(arr1);
  MeasuredArray ma(farr);
  EXPECT_EQ(ma.shape(), arr1.shape());
}

TEST_F(MeasuredArrayTest, FArraySPConstructorNullThrows) {
  generic::FArraySP<double> dummy;
  EXPECT_THROW(MeasuredArray varname(dummy), std::invalid_argument);
}

TEST_F(MeasuredArrayTest, MoveXtArrayConstructor) {
  xt::xarray<double> arr = {{9.0, 10.0}, {11.0, 12.0}};
  MeasuredArray      ma(std::move(arr));
  EXPECT_EQ(ma.shape().size(), 2);
}

TEST_F(MeasuredArrayTest, ArithmeticAddDouble) {
  auto result = ma1->operator+(2.0);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) + 2.0);
}

TEST_F(MeasuredArrayTest, ArithmeticAddInt) {
  auto result = ma1->operator+(3);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) + 3);
}

TEST_F(MeasuredArrayTest, ArithmeticAddMeasuredArray) {
  auto result = ma1->operator+(ma2);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArrayTest, ArithmeticAddMeasuredArrayNullThrows) {
  EXPECT_THROW(ma1->operator+((MeasuredArraySP) nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArrayTest, ArithmeticAddFArraySP) {
  auto farr   = std::make_shared<generic::FArray<double>>(arr1);
  auto result = ma1->operator+(farr);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArrayTest, ArithmeticAddFArraySPNullThrows) {
  EXPECT_THROW(ma1->operator+((generic::FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArrayTest, ArithmeticSubDouble) {
  auto result = ma1->operator-(2.0);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) - 2.0);
}

TEST_F(MeasuredArrayTest, ArithmeticSubInt) {
  auto result = ma1->operator-(1);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) - 1);
}

TEST_F(MeasuredArrayTest, ArithmeticSubMeasuredArray) {
  auto result = ma1->operator-(ma2);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArrayTest, ArithmeticSubMeasuredArrayNullThrows) {
  EXPECT_THROW(ma1->operator-((MeasuredArraySP) nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArrayTest, ArithmeticSubFArraySP) {
  auto farr   = std::make_shared<generic::FArray<double>>(arr1);
  auto result = ma1->operator-(farr);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArrayTest, ArithmeticSubFArraySPNullThrows) {
  EXPECT_THROW(ma1->operator-((generic::FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArrayTest, ArithmeticNegation) {
  auto result = ma1->operator-();
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), -(*ma1)(0, 0));
}

TEST_F(MeasuredArrayTest, ArithmeticMulDouble) {
  auto result = ma1->operator*(2.0);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) * 2.0);
}

TEST_F(MeasuredArrayTest, ArithmeticMulInt) {
  auto result = ma1->operator*(3);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) * 3);
}

TEST_F(MeasuredArrayTest, ArithmeticMulMeasuredArray) {
  auto result = ma1->operator*(ma2);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArrayTest, ArithmeticMulMeasuredArrayNullThrows) {
  EXPECT_THROW(ma1->operator*((MeasuredArraySP) nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArrayTest, ArithmeticMulFArraySP) {
  auto farr   = std::make_shared<generic::FArray<double>>(arr1);
  auto result = ma1->operator*(farr);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArrayTest, ArithmeticMulFArraySPNullThrows) {
  EXPECT_THROW(ma1->operator*((generic::FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArrayTest, ArithmeticDivDouble) {
  auto result = ma1->operator/(2.0);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) / 2.0);
}

TEST_F(MeasuredArrayTest, ArithmeticDivInt) {
  auto result = ma1->operator/(2);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ma1)(0, 0) / 2.0);
}

TEST_F(MeasuredArrayTest, ArithmeticDivMeasuredArray) {
  auto result = ma1->operator/(ma2);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArrayTest, ArithmeticDivMeasuredArrayNullThrows) {
  EXPECT_THROW(ma1->operator/((MeasuredArraySP) nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArrayTest, ArithmeticDivFArraySP) {
  auto farr   = std::make_shared<generic::FArray<double>>(arr1);
  auto result = ma1->operator/(farr);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArrayTest, ArithmeticDivFArraySPNullThrows) {
  EXPECT_THROW(ma1->operator/((generic::FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArrayTest, ArithmeticPow) {
  auto result = ma1->operator^(2.0);
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), std::pow((*ma1)(0, 0), 2.0));
}

TEST_F(MeasuredArrayTest, Abs) {
  auto result = ma1->abs();
  EXPECT_EQ(result->shape(), ma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), std::abs((*ma1)(0, 0)));
}

TEST_F(MeasuredArrayTest, MinMeasuredArray) {
  auto result = ma1->min(ma2);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArrayTest, MinMeasuredArrayNullThrows) {
  EXPECT_THROW(ma1->min((MeasuredArraySP) nullptr), std::invalid_argument);
}

TEST_F(MeasuredArrayTest, MinFArraySP) {
  auto farr   = std::make_shared<generic::FArray<double>>(arr1);
  auto result = ma1->min(farr);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArrayTest, MinFArraySPNullThrows) {
  EXPECT_THROW(ma1->min((generic::FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArrayTest, MaxMeasuredArray) {
  auto result = ma1->max(ma2);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArrayTest, MaxMeasuredArrayNullThrows) {
  EXPECT_THROW(ma1->max((MeasuredArraySP) nullptr), std::invalid_argument);
}

TEST_F(MeasuredArrayTest, MaxFArraySP) {
  auto farr   = std::make_shared<generic::FArray<double>>(arr1);
  auto result = ma1->max(farr);
  EXPECT_EQ(result->shape(), ma1->shape());
}

TEST_F(MeasuredArrayTest, MaxFArraySPNullThrows) {
  EXPECT_THROW(ma1->max((generic::FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArrayTest, Reshape) {
  auto reshaped = ma1->reshape({4});
  EXPECT_EQ(reshaped->size(), 4);
}

TEST_F(MeasuredArrayTest, Flip) {
  auto flipped = ma1->flip(0);
  EXPECT_EQ(flipped->shape(), ma1->shape());
}

TEST_F(MeasuredArrayTest, GradientAxis) {
  auto grad = ma1->gradient(0);
  EXPECT_EQ(grad->shape().size(), 2);
  EXPECT_EQ(grad->size(), ma1->size());
}

TEST_F(MeasuredArrayTest, GradientAllAxes) {
  auto grads = ma1->gradient();
  EXPECT_GT(grads->size(), 0);
}

TEST_F(MeasuredArrayTest, SerializationRoundTrip) {
  auto string = ma1->to_json_string();
  auto other  = MeasuredArray::from_json_string<MeasuredArray>(string);
  EXPECT_EQ(*ma1, *other);
}
}  // namespace
