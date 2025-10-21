#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/arrays/LabelledControlArray1D.hpp"
namespace {
using namespace falcon_core;
using namespace generic;
using namespace math::arrays;
using autotuner_interfaces::contexts::AcquisitionContext;
using autotuner_interfaces::contexts::AcquisitionContextSP;
using instrument_interfaces::names::InstrumentPort;
using instrument_interfaces::names::InstrumentPortSP;

class LabelledControlArray1DTest : public ::testing::Test {
 protected:
  xt::xarray<double>       arr1 = {1.0, 2.0, 3.0};
  xt::xarray<double>       arr2 = {4.0, 5.0, 6.0};
  AcquisitionContextSP     labelA;
  AcquisitionContextSP     labelB;
  InstrumentPortSP         portA;
  InstrumentPortSP         portB;
  LabelledControlArray1DSP lca1;
  LabelledControlArray1DSP lca2;
  void                     SetUp() override {
    portA = InstrumentPort::Knob(
        "A", physics::device_structures::Connection::PlungerGate("PA"));
    labelA = std::make_shared<AcquisitionContext>(portA);
    portB  = InstrumentPort::Knob(
        "B", physics::device_structures::Connection::PlungerGate("PB"));
    labelB = std::make_shared<AcquisitionContext>(portB);
    lca1   = std::make_shared<LabelledControlArray1D>(
        std::make_shared<ControlArray>(arr1), labelA);
    lca2 = std::make_shared<LabelledControlArray1D>(
        std::make_shared<ControlArray>(arr2), labelB);
  }
};

TEST_F(LabelledControlArray1DTest, ControlArraySPConstructor) {
  auto                   ca = std::make_shared<ControlArray1D>(arr1);
  LabelledControlArray1D lca(ca, labelA);
  EXPECT_EQ(lca.shape(), arr1.shape());
  EXPECT_EQ(lca.label(), labelA);
}

TEST_F(LabelledControlArray1DTest, ControlArraySPConstructorNullThrows) {
  EXPECT_THROW(LabelledControlArray1D((ControlArraySP) nullptr, labelA),
               std::invalid_argument);
  EXPECT_THROW(
      LabelledControlArray1D(std::make_shared<ControlArray1D>(arr1), nullptr),
      std::invalid_argument);
}

TEST_F(LabelledControlArray1DTest, ControlArray1DSPConstructor) {
  auto                   ca = std::make_shared<ControlArray1D>(arr1);
  LabelledControlArray1D lca(ca, labelA);
  EXPECT_EQ(lca.shape(), arr1.shape());
  EXPECT_EQ(lca.label(), labelA);
}

TEST_F(LabelledControlArray1DTest, ControlArray1DSPConstructorNullThrows) {
  EXPECT_THROW(LabelledControlArray1D((ControlArray1DSP) nullptr, labelA),
               std::invalid_argument);
  EXPECT_THROW(
      LabelledControlArray1D(std::make_shared<ControlArray1D>(arr1), nullptr),
      std::invalid_argument);
}

TEST_F(LabelledControlArray1DTest, FArraySPConstructor) {
  auto                   farr = std::make_shared<FArray<double>>(arr1);
  LabelledControlArray1D lca(farr, labelA);
  EXPECT_EQ(lca.shape(), arr1.shape());
  EXPECT_EQ(lca.label(), labelA);
}

TEST_F(LabelledControlArray1DTest, FArraySPConstructorNullThrows) {
  EXPECT_THROW(LabelledControlArray1D((FArraySP<double>)nullptr, labelA),
               std::invalid_argument);
  EXPECT_THROW(
      LabelledControlArray1D(std::make_shared<FArray<double>>(arr1), nullptr),
      std::invalid_argument);
}

TEST_F(LabelledControlArray1DTest, ArithmeticAddDouble) {
  auto result = lca1->operator+(2.0);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*lca1)(0) + 2.0);
}

TEST_F(LabelledControlArray1DTest, ArithmeticAddInt) {
  auto result = lca1->operator+(3);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*lca1)(0) + 3);
}

TEST_F(LabelledControlArray1DTest, ArithmeticAddLabelledControlArray1D) {
  auto result = lca1->operator+(lca2);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArray1DTest,
       ArithmeticAddLabelledControlArray1DNullThrows) {
  EXPECT_THROW(lca1->operator+((LabelledControlArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArray1DTest, ArithmeticAddFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lca1->operator+(farr);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArray1DTest, ArithmeticAddFArraySPNullThrows) {
  EXPECT_THROW(lca1->operator+((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArray1DTest, ArithmeticSubDouble) {
  auto result = lca1->operator-(2.0);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*lca1)(0) - 2.0);
}

TEST_F(LabelledControlArray1DTest, ArithmeticSubInt) {
  auto result = lca1->operator-(1);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*lca1)(0) - 1);
}

TEST_F(LabelledControlArray1DTest, ArithmeticSubLabelledControlArray1D) {
  auto result = (*lca1 * 2)->operator-(lca1);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArray1DTest,
       ArithmeticSubLabelledControlArray1DNullThrows) {
  EXPECT_THROW(lca1->operator-((LabelledControlArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArray1DTest, ArithmeticSubFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = (*lca1 * 2)->operator-(farr);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArray1DTest, ArithmeticSubFArraySPNullThrows) {
  EXPECT_THROW(lca1->operator-((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArray1DTest, ArithmeticNegation) {
  auto result = lca1->operator-();
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), -(*lca1)(0));
}

TEST_F(LabelledControlArray1DTest, ArithmeticMulDouble) {
  auto result = lca1->operator*(2.0);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*lca1)(0) * 2.0);
}

TEST_F(LabelledControlArray1DTest, ArithmeticMulInt) {
  auto result = lca1->operator*(3);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*lca1)(0) * 3);
}

TEST_F(LabelledControlArray1DTest, ArithmeticDivDouble) {
  auto result = lca1->operator/(2.0);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*lca1)(0) / 2.0);
}

TEST_F(LabelledControlArray1DTest, ArithmeticDivInt) {
  auto result = lca1->operator/(2);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), (*lca1)(0) / 2.0);
}

TEST_F(LabelledControlArray1DTest, ArithmeticPow) {
  auto result = lca1->operator^(2.0);
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), std::pow((*lca1)(0), 2.0));
}

TEST_F(LabelledControlArray1DTest, Abs) {
  auto result = lca1->abs();
  EXPECT_EQ(result->shape(), lca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0), std::abs((*lca1)(0)));
}

TEST_F(LabelledControlArray1DTest, MinLabelledControlArray1D) {
  auto result = lca1->min(lca2);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArray1DTest, MinLabelledControlArray1DNullThrows) {
  EXPECT_THROW(lca1->min((LabelledControlArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArray1DTest, MinFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lca1->min(farr);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArray1DTest, MinFArraySPNullThrows) {
  EXPECT_THROW(lca1->min((FArraySP<double>)nullptr), std::invalid_argument);
}

TEST_F(LabelledControlArray1DTest, MaxLabelledControlArray1D) {
  auto result = lca1->max(lca2);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArray1DTest, MaxLabelledControlArray1DNullThrows) {
  EXPECT_THROW(lca1->max((LabelledControlArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArray1DTest, MaxFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lca1->max(farr);
  EXPECT_EQ(result->shape(), lca1->shape());
}

TEST_F(LabelledControlArray1DTest, MaxFArraySPNullThrows) {
  EXPECT_THROW(lca1->max((FArraySP<double>)nullptr), std::invalid_argument);
}

TEST_F(LabelledControlArray1DTest, Reshape) {
  auto reshaped = lca1->reshape({3});
  EXPECT_EQ(reshaped->size(), 3);
}

TEST_F(LabelledControlArray1DTest, Flip) {
  auto flipped = lca1->flip(0);
  EXPECT_EQ(flipped->shape(), lca1->shape());
}

TEST_F(LabelledControlArray1DTest, GradientAxis) {
  auto grad = lca1->gradient(0);
  EXPECT_EQ(grad->shape().size(), 1);
  EXPECT_EQ(grad->size(), lca1->size());
}

TEST_F(LabelledControlArray1DTest, GradientAllAxes) {
  auto grads = lca1->gradient();
  EXPECT_GT(grads->size(), 0);
}

TEST_F(LabelledControlArray1DTest, SerializationRoundTrip) {
  auto string = lca1->to_json_string();
  auto other =
      LabelledControlArray1D::from_json_string<LabelledControlArray1D>(string);
  EXPECT_EQ(*lca1, *other);
}
}  // namespace
