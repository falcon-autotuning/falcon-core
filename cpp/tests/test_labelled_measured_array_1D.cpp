#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray1D.hpp"
namespace {
using namespace falcon_core;
using namespace generic;
using namespace autotuner_interfaces;
using namespace contexts;
using namespace math::arrays;
using falcon_core::instrument_interfaces::names::InstrumentPort;
using falcon_core::instrument_interfaces::names::InstrumentPortSP;

class LabelledMeasuredArray1DTest : public ::testing::Test {
 protected:
  xt::xarray<double>        arr1 = {{1.0, 2.0}, {3.0, 4.0}};
  xt::xarray<double>        arr2 = {{5.0, 6.0}, {7.0, 8.0}};
  AcquisitionContextSP      labelA;
  AcquisitionContextSP      labelB;
  InstrumentPortSP          portA;
  InstrumentPortSP          portB;
  LabelledMeasuredArray1DSP lma1;
  LabelledMeasuredArray1DSP lma2;
  void                      SetUp() override {
    portA = InstrumentPort::Meter(
        "A", physics::device_structures::Connection::Ohmic("OA"));
    labelA = std::make_shared<AcquisitionContext>(portA);
    portB  = InstrumentPort::Meter(
        "B", physics::device_structures::Connection::Ohmic("OB"));
    labelB = std::make_shared<AcquisitionContext>(portB);
    lma1   = std::make_shared<LabelledMeasuredArray1D>(
        std::make_shared<MeasuredArray>(arr1), labelA);
    lma2 = std::make_shared<LabelledMeasuredArray1D>(
        std::make_shared<MeasuredArray>(arr2), labelB);
  }
};

TEST_F(LabelledMeasuredArray1DTest, MeasuredArraySPConstructor) {
  auto                    ma = std::make_shared<MeasuredArray>(arr1);
  LabelledMeasuredArray1D lma(ma, labelA);
  EXPECT_EQ(lma.shape(), arr1.shape());
  EXPECT_EQ(lma.label(), labelA);
}

TEST_F(LabelledMeasuredArray1DTest, MeasuredArraySPConstructorNullThrows) {
  EXPECT_THROW(LabelledMeasuredArray1D((MeasuredArraySP) nullptr, labelA),
               std::invalid_argument);
  EXPECT_THROW(
      LabelledMeasuredArray1D(std::make_shared<MeasuredArray>(arr1), nullptr),
      std::invalid_argument);
}

TEST_F(LabelledMeasuredArray1DTest, FArraySPConstructor) {
  auto                    farr = std::make_shared<FArray<double>>(arr1);
  LabelledMeasuredArray1D lma(farr, labelA);
  EXPECT_EQ(lma.shape(), arr1.shape());
  EXPECT_EQ(lma.label(), labelA);
}

TEST_F(LabelledMeasuredArray1DTest, FArraySPConstructorNullThrows) {
  EXPECT_THROW(LabelledMeasuredArray1D((FArraySP<double>)nullptr, labelA),
               std::invalid_argument);
  EXPECT_THROW(LabelledMeasuredArray1D(std::make_shared<FArray<double>>(arr1),
                                       (AcquisitionContextSP) nullptr),
               std::invalid_argument);
  // EXPECT_THROW(LabelledMeasuredArray1D(std::make_shared<FArray<double>>(arr1),
  //                                      (InstrumentPortSP) nullptr),
  //              std::invalid_argument);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticAddDouble) {
  auto result = lma1->operator+(2.0);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) + 2.0);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticAddInt) {
  auto result = lma1->operator+(3);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) + 3);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticAddLabelledMeasuredArray) {
  auto result = lma1->operator+(lma1);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArray1DTest,
       ArithmeticAddLabelledMeasuredArray1DNullThrows) {
  EXPECT_THROW(lma1->operator+((LabelledMeasuredArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticAddFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lma1->operator+(farr);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticAddFArraySPNullThrows) {
  EXPECT_THROW(lma1->operator+((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticSubDouble) {
  auto result = lma1->operator-(2.0);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) - 2.0);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticSubInt) {
  auto result = lma1->operator-(1);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) - 1);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticSubLabelledMeasuredArray) {
  auto result = (*lma1 * 2)->operator-(lma1);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArray1DTest,
       ArithmeticSubLabelledMeasuredArray1DNullThrows) {
  EXPECT_THROW(lma1->operator-((LabelledMeasuredArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticSubFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lma1->operator-(farr);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticSubFArraySPNullThrows) {
  EXPECT_THROW(lma1->operator-((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticNegation) {
  auto result = lma1->operator-();
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), -(*lma1)(0, 0));
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticMulDouble) {
  auto result = lma1->operator*(2.0);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) * 2.0);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticMulInt) {
  auto result = lma1->operator*(3);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) * 3);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticMulLabelledMeasuredArray) {
  auto result = lma1->operator*(lma1);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArray1DTest,
       ArithmeticMulLabelledMeasuredArray1DNullThrows) {
  EXPECT_THROW(lma1->operator*((LabelledMeasuredArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticMulFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lma1->operator*(farr);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticMulFArraySPNullThrows) {
  EXPECT_THROW(lma1->operator*((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticDivDouble) {
  auto result = lma1->operator/(2.0);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) / 2.0);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticDivInt) {
  auto result = lma1->operator/(2);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*lma1)(0, 0) / 2.0);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticDivLabelledMeasuredArray) {
  auto result = lma1->operator/(lma1);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArray1DTest,
       ArithmeticDivLabelledMeasuredArray1DNullThrows) {
  EXPECT_THROW(lma1->operator/((LabelledMeasuredArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticDivFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lma1->operator/(farr);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticDivFArraySPNullThrows) {
  EXPECT_THROW(lma1->operator/((FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticPow) {
  auto result = lma1->operator^(2.0);
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), std::pow((*lma1)(0, 0), 2.0));
}

TEST_F(LabelledMeasuredArray1DTest, Abs) {
  auto result = lma1->abs();
  EXPECT_EQ(result->shape(), lma1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), std::abs((*lma1)(0, 0)));
}

TEST_F(LabelledMeasuredArray1DTest, MinLabelledMeasuredArray) {
  auto result = lma1->min(*lma1 * 2);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArray1DTest, MinLabelledMeasuredArrayNullThrows) {
  EXPECT_THROW(lma1->min((LabelledMeasuredArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArray1DTest, MinFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lma1->min(farr);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArray1DTest, MinFArraySPNullThrows) {
  EXPECT_THROW(lma1->min((FArraySP<double>)nullptr), std::invalid_argument);
}

TEST_F(LabelledMeasuredArray1DTest, MaxLabelledMeasuredArray) {
  auto result = lma1->max(*lma1 * 2);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArray1DTest, MaxLabelledMeasuredArrayNullThrows) {
  EXPECT_THROW(lma1->max((LabelledMeasuredArray1DSP) nullptr),
               std::invalid_argument);
}

TEST_F(LabelledMeasuredArray1DTest, MaxFArraySP) {
  auto farr   = std::make_shared<FArray<double>>(arr1);
  auto result = lma1->max(farr);
  EXPECT_EQ(result->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArray1DTest, MaxFArraySPNullThrows) {
  EXPECT_THROW(lma1->max((FArraySP<double>)nullptr), std::invalid_argument);
}

TEST_F(LabelledMeasuredArray1DTest, Reshape) {
  auto reshaped = lma1->reshape({4});
  EXPECT_EQ(reshaped->size(), 4);
}

TEST_F(LabelledMeasuredArray1DTest, Flip) {
  auto flipped = lma1->flip(0);
  EXPECT_EQ(flipped->shape(), lma1->shape());
}

TEST_F(LabelledMeasuredArray1DTest, GradientAxis) {
  auto grad = lma1->gradient(0);
  EXPECT_EQ(grad->shape().size(), 2);
  EXPECT_EQ(grad->size(), lma1->size());
}

TEST_F(LabelledMeasuredArray1DTest, GradientAllAxes) {
  auto grads = lma1->gradient();
  EXPECT_GT(grads->size(), 0);
}

TEST_F(LabelledMeasuredArray1DTest, SerializationRoundTrip) {
  auto string = lma1->to_json_string();
  auto other =
      LabelledMeasuredArray1D::from_json_string<LabelledMeasuredArray>(string);
  EXPECT_EQ(*lma1, *other);
}

// TODO: These commented out tests are not applicable to the current
// implementation, but we may want to fix that.
// TEST_F(LabelledMeasuredArray1DTest, InstrumentPortConstructorAndNullThrows) {
//   auto             farr = std::make_shared<FArray<double>>(arr1);
//   InstrumentPortSP port = std::make_shared<InstrumentPort>("portA");
//   EXPECT_THROW(LabelledMeasuredArray1D lma(farr, port), std::runtime_error);
// }

// TEST_F(LabelledMeasuredArray1DTest, AddLabelMismatchThrows) {
//   auto lmaA = std::make_shared<LabelledMeasuredArray1D>(
//       std::make_shared<MeasuredArray>(arr1), labelA);
//   auto lmaB = std::make_shared<LabelledMeasuredArray1D>(
//       std::make_shared<MeasuredArray>(arr2), labelB);
//   EXPECT_THROW(lmaA->operator+(lmaB), std::invalid_argument);
// }
//
// TEST_F(LabelledMeasuredArray1DTest, SubLabelMismatchThrows) {
//   auto lmaA = std::make_shared<LabelledMeasuredArray1D>(
//       std::make_shared<MeasuredArray>(arr1), labelA);
//   auto lmaB = std::make_shared<LabelledMeasuredArray1D>(
//       std::make_shared<MeasuredArray>(arr2), labelB);
//   EXPECT_THROW(lmaA->operator-(lmaB), std::invalid_argument);
// }
//
// TEST_F(LabelledMeasuredArray1DTest, MulLabelMismatchThrows) {
//   auto lmaA = std::make_shared<LabelledMeasuredArray1D>(
//       std::make_shared<MeasuredArray>(arr1), labelA);
//   auto lmaB = std::make_shared<LabelledMeasuredArray1D>(
//       std::make_shared<MeasuredArray>(arr2), labelB);
//   EXPECT_THROW(lmaA->operator*(lmaB), std::invalid_argument);
// }
//
// TEST_F(LabelledMeasuredArray1DTest, DivLabelMismatchThrows) {
//   auto lmaA = std::make_shared<LabelledMeasuredArray1D>(
//       std::make_shared<MeasuredArray>(arr1), labelA);
//   auto lmaB = std::make_shared<LabelledMeasuredArray1D>(
//       std::make_shared<MeasuredArray>(arr2), labelB);
//   EXPECT_THROW(lmaA->operator/(lmaB), std::invalid_argument);
// }
//
// TEST_F(LabelledMeasuredArray1DTest, MinLabelMismatchThrows) {
//   auto lmaA = std::make_shared<LabelledMeasuredArray1D>(
//       std::make_shared<MeasuredArray>(arr1), labelA);
//   auto lmaB = std::make_shared<LabelledMeasuredArray1D>(
//       std::make_shared<MeasuredArray>(arr2), labelB);
//   EXPECT_THROW(lmaA->min(lmaB), std::invalid_argument);
// }
//
// TEST_F(LabelledMeasuredArray1DTest, MaxLabelMismatchThrows) {
//   auto lmaA = std::make_shared<LabelledMeasuredArray1D>(
//       std::make_shared<MeasuredArray>(arr1), labelA);
//   auto lmaB = std::make_shared<LabelledMeasuredArray1D>(
//       std::make_shared<MeasuredArray>(arr2), labelB);
//   EXPECT_THROW(lmaA->max(lmaB), std::invalid_argument);
// }

TEST_F(LabelledMeasuredArray1DTest, InequalityOperator) {
  auto lmaA = std::make_shared<LabelledMeasuredArray1D>(
      std::make_shared<MeasuredArray>(arr1), labelA);
  auto lmaB = std::make_shared<LabelledMeasuredArray1D>(
      std::make_shared<MeasuredArray>(arr2), labelA);
  EXPECT_TRUE(*lmaA != *lmaB);
  EXPECT_FALSE(*lmaA != *lmaA);
}
}  // namespace
