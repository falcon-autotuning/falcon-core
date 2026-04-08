#include <gtest/gtest.h>

#include "falcon-core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon-core/generic/FArray.hpp"
#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon-core/math/arrays/LabelledControlArray.hpp"
namespace {
using namespace falcon_core;
using namespace generic;
using namespace autotuner_interfaces;
using namespace contexts;
using namespace math::arrays;
using falcon_core::instrument_interfaces::names::InstrumentPort;
using falcon_core::instrument_interfaces::names::InstrumentPortSP;

class LabelledControlArrayTest : public ::testing::Test {
 protected:
  xt::xarray<double>     arr1 = {{1.0, 2.0}, {1.0, 2.0}};
  xt::xarray<double>     arr2 = {{5.0, 5.0}, {7.0, 7.0}};
  AcquisitionContextSP   labelA;
  AcquisitionContextSP   labelB;
  InstrumentPortSP       portA;
  InstrumentPortSP       portB;
  LabelledControlArraySP lca1;
  LabelledControlArraySP lca2;
  void                   SetUp() override {
    portA = InstrumentPort::Knob(
        "A", physics::device_structures::Connection::PlungerGate("PA"));
    labelA = std::make_shared<AcquisitionContext>(portA);
    portB  = InstrumentPort::Knob(
        "B", physics::device_structures::Connection::PlungerGate("PB"));
    labelB = std::make_shared<AcquisitionContext>(portB);
    lca1   = std::make_shared<LabelledControlArray>(
        std::make_shared<ControlArray>(arr1), labelA);
    lca2 = std::make_shared<LabelledControlArray>(
        std::make_shared<ControlArray>(arr2), labelB);
  }
};

TEST_F(LabelledControlArrayTest, ControlArraySPConstructor) {
  auto                 ca = std::make_shared<ControlArray>(arr1);
  LabelledControlArray lca(ca, labelA);
  EXPECT_EQ(lca.shape(), arr1.shape());
  EXPECT_EQ(*lca.label(), *labelA);
}

TEST_F(LabelledControlArrayTest, ControlArraySPConstructorNullThrows) {
  EXPECT_THROW(LabelledControlArray((ControlArraySP) nullptr, labelA),
               std::invalid_argument);
  EXPECT_THROW(
      LabelledControlArray(std::make_shared<ControlArray>(arr1), nullptr),
      std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, FArraySPConstructor) {
  auto                 farr = std::make_shared<FArray<double>>(arr1);
  LabelledControlArray lca(farr, labelA);
  EXPECT_EQ(lca.shape(), arr1.shape());
  EXPECT_EQ(lca.label(), labelA);
}

TEST_F(LabelledControlArrayTest, FArraySPConstructorNullThrows) {
  EXPECT_THROW(LabelledControlArray((FArraySP<double>)nullptr, labelA),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray(std::make_shared<FArray<double>>(arr1),
                                    (AcquisitionContextSP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, InstrumentPortConstructor) {
  auto                 farr = std::make_shared<FArray<double>>(arr1);
  LabelledControlArray lca(farr, portA);
  EXPECT_EQ(lca.shape(), arr1.shape());
  EXPECT_NE(lca.label(), nullptr);
}

TEST_F(LabelledControlArrayTest, InstrumentPortConstructorNullThrows) {
  auto farr = std::make_shared<FArray<double>>(arr1);
  EXPECT_THROW(LabelledControlArray(farr, (InstrumentPortSP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, ArithmeticAddDouble) {
  auto result = lca1->operator+(2.0);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lca1)(0, 0) + 2.0);
}

TEST_F(LabelledControlArrayTest, ArithmeticAddInt) {
  auto result = lca1->operator+(3);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lca1)(0, 0) + 3);
}

TEST_F(LabelledControlArrayTest, ArithmeticAddLabelledControlArray) {
  auto result = lca1->operator+(lca1);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArrayTest, ArithmeticAddLabelledControlArrayNullThrows) {
  EXPECT_THROW(lca1->operator+((LabelledControlArraySP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, ArithmeticAddFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lca1->operator+(farr);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArrayTest, ArithmeticAddFArraySPNullThrows) {
  EXPECT_THROW(lca1->operator+((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, ArithmeticSubDouble) {
  auto result = lca1->operator-(2.0);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lca1)(0, 0) - 2.0);
}

TEST_F(LabelledControlArrayTest, ArithmeticSubInt) {
  auto result = lca1->operator-(1);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lca1)(0, 0) - 1);
}

TEST_F(LabelledControlArrayTest, ArithmeticSubLabelledControlArray) {
  auto result = (*lca1 * 2)->operator-(lca1);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArrayTest, ArithmeticSubLabelledControlArrayNullThrows) {
  EXPECT_THROW(lca1->operator-((LabelledControlArraySP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, ArithmeticSubFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = (*lca1 * 2)->operator-(farr);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArrayTest, ArithmeticSubFArraySPNullThrows) {
  EXPECT_THROW(lca1->operator-((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, ArithmeticNegation) {
  auto result = lca1->operator-();
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), -(*lca1)(0, 0));
}

TEST_F(LabelledControlArrayTest, ArithmeticMulDouble) {
  auto result = lca1->operator*(2.0);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lca1)(0, 0) * 2.0);
}

TEST_F(LabelledControlArrayTest, ArithmeticMulInt) {
  auto result = lca1->operator*(3);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lca1)(0, 0) * 3);
}

TEST_F(LabelledControlArrayTest, ArithmeticDivDouble) {
  auto result = lca1->operator/(2.0);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lca1)(0, 0) / 2.0);
}

TEST_F(LabelledControlArrayTest, ArithmeticDivInt) {
  auto result = lca1->operator/(2);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lca1)(0, 0) / 2.0);
}

TEST_F(LabelledControlArrayTest, ArithmeticPow) {
  auto result = lca1->operator^(2.0);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), std::pow((*lca1)(0, 0), 2.0));
}

TEST_F(LabelledControlArrayTest, Abs) {
  auto result = lca1->abs();
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), std::abs((*lca1)(0, 0)));
}

TEST_F(LabelledControlArrayTest, MinLabelledControlArray) {
  auto result = lca1->min(lca1);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArrayTest, MinLabelledControlArrayNullThrows) {
  EXPECT_THROW(lca1->min((LabelledControlArraySP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, MinFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lca1->min(farr);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArrayTest, MinFArraySPNullThrows) {
  EXPECT_THROW(lca1->min((FArraySP<double>)nullptr), std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, MaxLabelledControlArray) {
  auto result = lca1->max(lca1);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArrayTest, MaxLabelledControlArrayNullThrows) {
  EXPECT_THROW(lca1->max((LabelledControlArraySP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, MaxFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lca1->max(farr);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArrayTest, MaxFArraySPNullThrows) {
  EXPECT_THROW(lca1->max((FArraySP<double>)nullptr), std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, Reshape) {
  auto reshaped = lca1->reshape({2});
  EXPECT_EQ(reshaped->size(), 2);
}

TEST_F(LabelledControlArrayTest, Flip) {
  auto flipped = lca1->flip(0);
  EXPECT_EQ(flipped->shape(), lca1->shape());
}

TEST_F(LabelledControlArrayTest, GradientAxis) {
  auto grad = lca1->gradient(0);
  EXPECT_EQ(grad->shape().size(), 2);
  EXPECT_EQ(grad->size(), lca1->size());
}

TEST_F(LabelledControlArrayTest, GradientAllAxes) {
  auto grads = lca1->gradient();
  EXPECT_GT(grads->size(), 0);
}

TEST_F(LabelledControlArrayTest, SerializationRoundTrip) {
  auto string = lca1->to_json_string();
  auto other =
      LabelledControlArray::from_json_string<LabelledControlArray>(string);
  EXPECT_EQ(*lca1, *other);
}

TEST_F(LabelledControlArrayTest, InEqualOperator) {
  auto lcaA = std::make_shared<LabelledControlArray>(
      std::make_shared<ControlArray>(arr1), labelA);
  auto lcaB = std::make_shared<LabelledControlArray>(
      std::make_shared<ControlArray>(arr2), labelA);
  EXPECT_TRUE(*lcaA != *lcaB);
  EXPECT_FALSE(*lcaA != *lcaA);
}

TEST_F(LabelledControlArrayTest, SubtractDoubleThrowsIfZero) {
  auto lcaA = std::make_shared<LabelledControlArray>(
      std::make_shared<ControlArray>(arr1), labelA);
  EXPECT_THROW(lcaA->operator-(0.0), std::invalid_argument);
}

}  // namespace
