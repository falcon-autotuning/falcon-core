#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon-core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon-core/math/arrays/LabelledMeasuredArray.hpp"
namespace {
using namespace falcon_core;
using namespace generic;
using namespace autotuner_interfaces;
using namespace contexts;
using namespace math::arrays;
using falcon_core::instrument_interfaces::names::InstrumentPort;
using falcon_core::instrument_interfaces::names::InstrumentPortSP;

class LabelledMeasuredArrayTest : public ::testing::Test {
 protected:
  xt::xarray<double>      arr1 = {{1.0, 2.0}, {3.0, 4.0}};
  xt::xarray<double>      arr2 = {{5.0, 6.0}, {7.0, 8.0}};
  AcquisitionContextSP    labelA;
  AcquisitionContextSP    labelB;
  InstrumentPortSP        portA;
  InstrumentPortSP        portB;
  LabelledMeasuredArraySP lma1;
  LabelledMeasuredArraySP lma2;
  void                    SetUp() override {
    portA = InstrumentPort::Meter(
        "A", physics::device_structures::Connection::Ohmic("OA"));
    labelA = std::make_shared<AcquisitionContext>(portA);
    portB  = InstrumentPort::Meter(
        "B", physics::device_structures::Connection::Ohmic("OB"));
    labelB = std::make_shared<AcquisitionContext>(portB);
    lma1   = std::make_shared<LabelledMeasuredArray>(
        std::make_shared<MeasuredArray>(arr1), labelA);
    lma2 = std::make_shared<LabelledMeasuredArray>(
        std::make_shared<MeasuredArray>(arr2), labelB);
  }
};

TEST_F(LabelledMeasuredArrayTest, MeasuredArraySPConstructor) {
  auto                  ma = std::make_shared<MeasuredArray>(arr1);
  LabelledMeasuredArray lma(ma, labelA);
  EXPECT_EQ(lma.shape(), arr1.shape());
  EXPECT_EQ(lma.label(), labelA);
}

TEST_F(LabelledMeasuredArrayTest, MeasuredArraySPConstructorNullThrows) {
  EXPECT_THROW(LabelledMeasuredArray((MeasuredArraySP) nullptr, labelA),
               std::invalid_argument);
  EXPECT_THROW(
      LabelledMeasuredArray(std::make_shared<MeasuredArray>(arr1), nullptr),
      std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, FArraySPConstructor) {
  auto                  farr = std::make_shared<FArray<double>>(arr1);
  LabelledMeasuredArray lma(farr, labelA);
  EXPECT_EQ(lma.shape(), arr1.shape());
  EXPECT_EQ(lma.label(), labelA);
}

TEST_F(LabelledMeasuredArrayTest, FArraySPConstructorNullThrows) {
  EXPECT_THROW(LabelledMeasuredArray((FArraySP<double>)nullptr, labelA),
               std::invalid_argument);
  EXPECT_THROW(LabelledMeasuredArray(std::make_shared<FArray<double>>(arr1),
                                     (AcquisitionContextSP) nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledMeasuredArray(std::make_shared<FArray<double>>(arr1),
                                     (InstrumentPortSP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticAddDouble) {
  auto result = lma1->operator+(2.0);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) + 2.0);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticAddInt) {
  auto result = lma1->operator+(3);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) + 3);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticAddLabelledMeasuredArray) {
  auto result = lma1->operator+(lma1);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArrayTest,
       ArithmeticAddLabelledMeasuredArrayNullThrows) {
  EXPECT_THROW(lma1->operator+((LabelledMeasuredArraySP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticAddFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lma1->operator+(farr);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticAddFArraySPNullThrows) {
  EXPECT_THROW(lma1->operator+((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticSubDouble) {
  auto result = lma1->operator-(2.0);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) - 2.0);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticSubInt) {
  auto result = lma1->operator-(1);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) - 1);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticSubLabelledMeasuredArray) {
  auto result = (*lma1 * 2)->operator-(lma1);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArrayTest,
       ArithmeticSubLabelledMeasuredArrayNullThrows) {
  EXPECT_THROW(lma1->operator-((LabelledMeasuredArraySP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticSubFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lma1->operator-(farr);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticSubFArraySPNullThrows) {
  EXPECT_THROW(lma1->operator-((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticNegation) {
  auto result = lma1->operator-();
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), -(*lma1)(0, 0));
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticMulDouble) {
  auto result = lma1->operator*(2.0);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) * 2.0);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticMulInt) {
  auto result = lma1->operator*(3);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) * 3);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticMulLabelledMeasuredArray) {
  auto result = lma1->operator*(lma1);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArrayTest,
       ArithmeticMulLabelledMeasuredArrayNullThrows) {
  EXPECT_THROW(lma1->operator*((LabelledMeasuredArraySP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticMulFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lma1->operator*(farr);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticMulFArraySPNullThrows) {
  EXPECT_THROW(lma1->operator*((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticDivDouble) {
  auto result = lma1->operator/(2.0);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) / 2.0);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticDivInt) {
  auto result = lma1->operator/(2);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) / 2.0);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticDivLabelledMeasuredArray) {
  auto result = lma1->operator/(lma1);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArrayTest,
       ArithmeticDivLabelledMeasuredArrayNullThrows) {
  EXPECT_THROW(lma1->operator/((LabelledMeasuredArraySP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticDivFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lma1->operator/(farr);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticDivFArraySPNullThrows) {
  EXPECT_THROW(lma1->operator/((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticPow) {
  auto result = lma1->operator^(2.0);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), std::pow((*lma1)(0, 0), 2.0));
}

TEST_F(LabelledMeasuredArrayTest, Abs) {
  auto result = lma1->abs();
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), std::abs((*lma1)(0, 0)));
}

TEST_F(LabelledMeasuredArrayTest, MinLabelledMeasuredArray) {
  auto result = lma1->min(*lma1 * 2);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArrayTest, MinLabelledMeasuredArrayNullThrows) {
  EXPECT_THROW(lma1->min((LabelledMeasuredArraySP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, MinFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lma1->min(farr);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArrayTest, MinFArraySPNullThrows) {
  EXPECT_THROW(lma1->min((FArraySP<double>)nullptr), std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, MaxLabelledMeasuredArray) {
  auto result = lma1->max(*lma1 * 2);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArrayTest, MaxLabelledMeasuredArrayNullThrows) {
  EXPECT_THROW(lma1->max((LabelledMeasuredArraySP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, MaxFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lma1->max(farr);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArrayTest, MaxFArraySPNullThrows) {
  EXPECT_THROW(lma1->max((FArraySP<double>)nullptr), std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, Reshape) {
  auto reshaped = lma1->reshape({4});
  EXPECT_EQ(reshaped->size(), 4);
}

TEST_F(LabelledMeasuredArrayTest, Flip) {
  auto flipped = lma1->flip(0);
  EXPECT_EQ(flipped->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArrayTest, GradientAxis) {
  auto grad = lma1->gradient(0);
  EXPECT_EQ(grad->shape().size(), 2);
  EXPECT_EQ(grad->size(), lma1->size());
}

TEST_F(LabelledMeasuredArrayTest, GradientAllAxes) {
  auto grads = lma1->gradient();
  EXPECT_GT(grads->size(), 0);
}

TEST_F(LabelledMeasuredArrayTest, SerializationRoundTrip) {
  auto string = lma1->to_json_string();
  auto other =
      LabelledMeasuredArray::from_json_string<LabelledMeasuredArray>(string);
  EXPECT_EQ(*lma1, *other);
}

TEST_F(LabelledMeasuredArrayTest, InstrumentPortConstructorAndNullThrows) {
  auto             farr = std::make_shared<FArray<double>>(arr1);
  InstrumentPortSP port = std::make_shared<InstrumentPort>("portA");
  EXPECT_THROW(LabelledMeasuredArray lma(farr, port), std::runtime_error);
}

TEST_F(LabelledMeasuredArrayTest, AddLabelMismatchThrows) {
  auto lmaA = std::make_shared<LabelledMeasuredArray>(
      std::make_shared<MeasuredArray>(arr1), labelA);
  auto lmaB = std::make_shared<LabelledMeasuredArray>(
      std::make_shared<MeasuredArray>(arr2), labelB);
  EXPECT_THROW(lmaA->operator+(lmaB), std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, SubLabelMismatchThrows) {
  auto lmaA = std::make_shared<LabelledMeasuredArray>(
      std::make_shared<MeasuredArray>(arr1), labelA);
  auto lmaB = std::make_shared<LabelledMeasuredArray>(
      std::make_shared<MeasuredArray>(arr2), labelB);
  EXPECT_THROW(lmaA->operator-(lmaB), std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, MulLabelMismatchThrows) {
  auto lmaA = std::make_shared<LabelledMeasuredArray>(
      std::make_shared<MeasuredArray>(arr1), labelA);
  auto lmaB = std::make_shared<LabelledMeasuredArray>(
      std::make_shared<MeasuredArray>(arr2), labelB);
  EXPECT_THROW(lmaA->operator*(lmaB), std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, DivLabelMismatchThrows) {
  auto lmaA = std::make_shared<LabelledMeasuredArray>(
      std::make_shared<MeasuredArray>(arr1), labelA);
  auto lmaB = std::make_shared<LabelledMeasuredArray>(
      std::make_shared<MeasuredArray>(arr2), labelB);
  EXPECT_THROW(lmaA->operator/(lmaB), std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, MinLabelMismatchThrows) {
  auto lmaA = std::make_shared<LabelledMeasuredArray>(
      std::make_shared<MeasuredArray>(arr1), labelA);
  auto lmaB = std::make_shared<LabelledMeasuredArray>(
      std::make_shared<MeasuredArray>(arr2), labelB);
  EXPECT_THROW(lmaA->min(lmaB), std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, MaxLabelMismatchThrows) {
  auto lmaA = std::make_shared<LabelledMeasuredArray>(
      std::make_shared<MeasuredArray>(arr1), labelA);
  auto lmaB = std::make_shared<LabelledMeasuredArray>(
      std::make_shared<MeasuredArray>(arr2), labelB);
  EXPECT_THROW(lmaA->max(lmaB), std::invalid_argument);
}

TEST_F(LabelledMeasuredArrayTest, InEqualOperator) {
  auto lmaA = std::make_shared<LabelledMeasuredArray>(
      std::make_shared<MeasuredArray>(arr1), labelA);
  auto lmaB = std::make_shared<LabelledMeasuredArray>(
      std::make_shared<MeasuredArray>(arr2), labelA);
  EXPECT_TRUE(*lmaA != *lmaB);
  EXPECT_FALSE(*lmaA != *lmaA);
}
}  // namespace
