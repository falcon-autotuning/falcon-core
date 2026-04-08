#include <gtest/gtest.h>

#include <stdexcept>
#include <xtensor/xarray.hpp>

#include "falcon-core/generic/FArray.hpp"
#include "falcon-core/math/arrays/ControlArray.hpp"
#include "falcon-core/math/arrays/ControlArray1D.hpp"
namespace {
using namespace falcon_core;
using namespace generic;
using namespace math::arrays;

class ControlArray1DTest : public ::testing::Test {
 protected:
  xt::xarray<double> arr1 = {1.0, 2.0, 3.0};
  xt::xarray<double> arr2 = {4.0, 5.0, 6.0};
  ControlArray1DSP   ca1;
  ControlArray1DSP   ca2;
  void               SetUp() override {
    ca1 = std::make_shared<ControlArray1D>(arr1);
    ca2 = std::make_shared<ControlArray1D>(arr2);
  }
};

TEST_F(ControlArray1DTest, XtArrayConstructor) {
  ControlArray1D ca(arr1);
  EXPECT_EQ(ca.shape(), arr1.shape());
}

TEST_F(ControlArray1DTest, FArraySPConstructor) {
  auto           farr = std::make_shared<FArray<double>>(arr1);
  ControlArray1D ca(farr);
  EXPECT_EQ(ca.shape(), arr1.shape());
}

TEST_F(ControlArray1DTest, FArraySPConstructorNullThrows) {
  FArraySP<double> dummy;
  EXPECT_THROW(ControlArray1D varname(dummy), std::runtime_error);
}

TEST_F(ControlArray1DTest, ControlArraySPConstructor) {
  auto           ca = std::make_shared<ControlArray>(arr1);
  ControlArray1D ca1d(ca);
  EXPECT_EQ(ca1d.shape(), arr1.shape());
}

TEST_F(ControlArray1DTest, ControlArraySPConstructorNullThrows) {
  EXPECT_THROW(ControlArray1D((ControlArraySP) nullptr), std::invalid_argument);
}

TEST_F(ControlArray1DTest, MoveXtArrayConstructor) {
  xt::xarray<double> arr = {7.0, 8.0, 9.0};
  ControlArray1D     ca(std::move(arr));
  EXPECT_EQ(ca.shape().size(), 1);
}

TEST_F(ControlArray1DTest, ArithmeticAddDouble) {
  auto result = ca1->operator+(2.0);
  EXPECT_EQ(result->shape(), ca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*ca1)(0) + 2.0);
}

TEST_F(ControlArray1DTest, ArithmeticAddInt) {
  auto result = ca1->operator+(3);
  EXPECT_EQ(result->shape(), ca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*ca1)(0) + 3);
}

TEST_F(ControlArray1DTest, ArithmeticAddControlArray1D) {
  auto result = ca1->operator+(ca2);
  EXPECT_EQ(result->shape(), ca1->shape());
}

TEST_F(ControlArray1DTest, ArithmeticAddControlArray1DNullThrows) {
  EXPECT_THROW(ca1->operator+((ControlArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(ControlArray1DTest, ArithmeticAddFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = ca1->operator+(farr);
  EXPECT_EQ(result->shape(), ca1->shape());
}

TEST_F(ControlArray1DTest, ArithmeticAddFArraySPNullThrows) {
  EXPECT_THROW(ca1->operator+((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(ControlArray1DTest, ArithmeticSubDouble) {
  auto result = ca1->operator-(2.0);
  EXPECT_EQ(result->shape(), ca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*ca1)(0) - 2.0);
}

TEST_F(ControlArray1DTest, ArithmeticSubInt) {
  auto result = ca1->operator-(1);
  EXPECT_EQ(result->shape(), ca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*ca1)(0) - 1);
}

TEST_F(ControlArray1DTest, ArithmeticSubControlArray1D) {
  auto result = (*ca1 * 2)->operator-(ca1);
  EXPECT_EQ(result->shape(), ca1->shape());
}

TEST_F(ControlArray1DTest, ArithmeticSubControlArray1DNullThrows) {
  EXPECT_THROW(ca1->operator-((ControlArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(ControlArray1DTest, ArithmeticSubFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = (*ca1 * 2)->operator-(farr);
  EXPECT_EQ(result->shape(), ca1->shape());
}

TEST_F(ControlArray1DTest, ArithmeticSubFArraySPNullThrows) {
  EXPECT_THROW(ca1->operator-((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(ControlArray1DTest, ArithmeticNegation) {
  auto result = ca1->operator-();
  EXPECT_EQ(result->shape(), ca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), -(*ca1)(0));
}

TEST_F(ControlArray1DTest, ArithmeticMulDouble) {
  auto result = ca1->operator*(2.0);
  EXPECT_EQ(result->shape(), ca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*ca1)(0) * 2.0);
}

TEST_F(ControlArray1DTest, ArithmeticMulInt) {
  auto result = ca1->operator*(3);
  EXPECT_EQ(result->shape(), ca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*ca1)(0) * 3);
}

TEST_F(ControlArray1DTest, ArithmeticDivDouble) {
  auto result = ca1->operator/(2.0);
  EXPECT_EQ(result->shape(), ca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*ca1)(0) / 2.0);
}

TEST_F(ControlArray1DTest, ArithmeticDivInt) {
  auto result = ca1->operator/(2);
  EXPECT_EQ(result->shape(), ca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*ca1)(0) / 2.0);
}

TEST_F(ControlArray1DTest, ArithmeticPow) {
  auto result = ca1->operator^(2.0);
  EXPECT_EQ(result->shape(), ca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), std::pow((*ca1)(0), 2.0));
}

TEST_F(ControlArray1DTest, Abs) {
  auto result = ca1->abs();
  EXPECT_EQ(result->shape(), ca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), std::abs((*ca1)(0)));
}

TEST_F(ControlArray1DTest, MinControlArray1D) {
  auto result = ca1->min(ca2);
  EXPECT_EQ(result->shape(), ca1->shape());
}

TEST_F(ControlArray1DTest, MinControlArray1DNullThrows) {
  EXPECT_THROW(ca1->min((ControlArray1DSP) nullptr), std::invalid_argument);
}

TEST_F(ControlArray1DTest, MinFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = ca1->min(farr);
  EXPECT_EQ(result->shape(), ca1->shape());
}

TEST_F(ControlArray1DTest, MinFArraySPNullThrows) {
  EXPECT_THROW(ca1->min((FArraySP<double>)nullptr), std::invalid_argument);
}

TEST_F(ControlArray1DTest, MaxControlArray1D) {
  auto result = ca1->max(ca2);
  EXPECT_EQ(result->shape(), ca1->shape());
}

TEST_F(ControlArray1DTest, MaxControlArray1DNullThrows) {
  EXPECT_THROW(ca1->max((ControlArray1DSP) nullptr), std::invalid_argument);
}

TEST_F(ControlArray1DTest, MaxFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = ca1->max(farr);
  EXPECT_EQ(result->shape(), ca1->shape());
}

TEST_F(ControlArray1DTest, MaxFArraySPNullThrows) {
  EXPECT_THROW(ca1->max((FArraySP<double>)nullptr), std::invalid_argument);
}

TEST_F(ControlArray1DTest, Reshape) {
  auto reshaped = ca1->reshape({3});
  EXPECT_EQ(reshaped->size(), 3);
}

TEST_F(ControlArray1DTest, Flip) {
  auto flipped = ca1->flip(0);
  EXPECT_EQ(flipped->shape(), ca1->shape());
}

TEST_F(ControlArray1DTest, GradientAxis) {
  auto grad = ca1->gradient(0);
  EXPECT_EQ(grad->shape().size(), 1);
  EXPECT_EQ(grad->size(), ca1->size());
}

TEST_F(ControlArray1DTest, GradientAllAxes) {
  auto grads = ca1->gradient();
  EXPECT_GT(grads->size(), 0);
}

TEST_F(ControlArray1DTest, SerializationRoundTrip) {
  auto string = ca1->to_json_string();
  auto other  = ControlArray1D::from_json_string<ControlArray1D>(string);
  EXPECT_EQ(*ca1, *other);
}

TEST_F(ControlArray1DTest, GetStart) {
  EXPECT_DOUBLE_EQ(ca1->get_start(), (*ca1)(0));
}
}  // namespace
