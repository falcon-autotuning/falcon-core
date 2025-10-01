#include <gtest/gtest.h>

#include <stdexcept>
#include <xtensor/xarray.hpp>

#include "falcon_core/math/arrays/ControlArray.hpp"

namespace {
using namespace falcon_core;
using namespace math::arrays;

class ControlArrayTest : public ::testing::Test {
 protected:
  xt::xarray<double>            arr1 = {{1.0, 2.0}, {1.0, 2.0}};
  xt::xarray<double>            arr2 = {{5.0, 5.0}, {7.0, 7.0}};
  std::shared_ptr<ControlArray> ca1;
  std::shared_ptr<ControlArray> ca2;
  void                          SetUp() override {
    ca1 = std::make_shared<ControlArray>(arr1);
    ca2 = std::make_shared<ControlArray>(arr2);
  }
};

TEST_F(ControlArrayTest, DefaultConstructor) {
  ControlArray ca;
  EXPECT_EQ(ca.shape().size(), 0);
}

TEST_F(ControlArrayTest, XtArrayConstructor) {
  ControlArray ca(arr1);
  EXPECT_EQ(ca.shape(), arr1.shape());
}

TEST_F(ControlArrayTest, FArraySPConstructor) {
  auto         farr = std::make_shared<generic::FArray<double>>(arr1);
  ControlArray ca(farr);
  EXPECT_EQ(ca.shape(), arr1.shape());
}

TEST_F(ControlArrayTest, FArraySPConstructorNullThrows) {
  EXPECT_THROW(ControlArray(nullptr), std::invalid_argument);
}

TEST_F(ControlArrayTest, MoveXtArrayConstructor) {
  xt::xarray<double> arr = {{9.0, 10.0}, {9.0, 10.0}};
  ControlArray       ca(std::move(arr));
  EXPECT_EQ(ca.shape().size(), 2);
}

TEST_F(ControlArrayTest, DifferentAlignmentsNotEqual) {
  ASSERT_NE(*ca1->alignment(), *ca2->alignment());
}

TEST_F(ControlArrayTest, ArithmeticAddSameAlignment) {
  auto add = *ca1 + ca1;
  EXPECT_EQ(add->shape(), ca1->shape());
}

TEST_F(ControlArrayTest, ArithmeticSubSameAlignment) {
  auto sub = *(*ca1 * 2) - ca1;
  EXPECT_EQ(sub->shape(), ca1->shape());
}

TEST_F(ControlArrayTest, ArithmeticMulSameAlignment) {
  auto mul = *ca1 * 2.0;
  EXPECT_EQ(mul->shape(), ca1->shape());
}

TEST_F(ControlArrayTest, ArithmeticDivSameAlignment) {
  auto div = *ca1 / 2.0;
  EXPECT_EQ(div->shape(), ca1->shape());
}

TEST_F(ControlArrayTest, ArithmeticNegation) {
  auto neg = -(*ca1);
  EXPECT_EQ(neg->shape(), ca1->shape());
}

TEST_F(ControlArrayTest, ArithmeticAddNullThrows) {
  EXPECT_THROW(ca1->operator+((ControlArraySP) nullptr), std::invalid_argument);
}

TEST_F(ControlArrayTest, ArithmeticSubNullThrows) {
  EXPECT_THROW(ca1->operator-((ControlArraySP) nullptr), std::invalid_argument);
}

TEST_F(ControlArrayTest, ArithmeticMulNullThrows) {
  EXPECT_THROW(ca1->operator*((ControlArraySP) nullptr), std::invalid_argument);
}

TEST_F(ControlArrayTest, ArithmeticDivNullThrows) {
  EXPECT_THROW(ca1->operator/((ControlArraySP) nullptr), std::invalid_argument);
}

TEST_F(ControlArrayTest, MinSameAlignment) {
  auto min = ca1->min(*ca1 * 2);
  EXPECT_EQ(min->shape(), ca1->shape());
  EXPECT_EQ(*min, *ca1);
}

TEST_F(ControlArrayTest, MaxSameAlignment) {
  auto max = ca1->max(*ca1 * 2);
  EXPECT_EQ(max->shape(), ca1->shape());
  EXPECT_EQ(*(*ca1 * 2), *max);
}

TEST_F(ControlArrayTest, MinNullThrows) {
  EXPECT_THROW(ca1->min((ControlArraySP) nullptr), std::invalid_argument);
}

TEST_F(ControlArrayTest, MaxNullThrows) {
  EXPECT_THROW(ca1->max((ControlArraySP) nullptr), std::invalid_argument);
}

TEST_F(ControlArrayTest, Reshape) {
  auto reshaped = ca1->reshape({2});
  EXPECT_EQ(reshaped->size(), 2);
}

TEST_F(ControlArrayTest, Flip) {
  auto flipped = ca1->flip(0);
  EXPECT_EQ(flipped->shape(), ca1->shape());
}

TEST_F(ControlArrayTest, Abs) {
  auto abs = ca1->abs();
  EXPECT_EQ(abs->shape(), ca1->shape());
}

TEST_F(ControlArrayTest, Pow) {
  auto pow = ca1->operator^(2.0);
  EXPECT_EQ(pow->shape(), ca1->shape());
}

TEST_F(ControlArrayTest, GradientAxis) {
  auto grad0 = ca1->gradient(0);
  EXPECT_EQ(grad0->shape(), ca1->shape());
}

TEST_F(ControlArrayTest, GradientAllAxes) {
  auto grads = ca1->gradient();
  EXPECT_GT(grads->size(), 0);
}

TEST_F(ControlArrayTest, SerializationRoundTrip) {
  auto           string = ca1->to_json_string();
  ControlArraySP other  = ControlArray::from_json_string<ControlArray>(string);
  EXPECT_EQ(*ca1, *other);
}

TEST_F(ControlArrayTest, AddDouble) {
  auto result = ca1->operator+(2.5);
  EXPECT_EQ(result->shape(), ca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ca1)(0, 0) + 2.5);
}

TEST_F(ControlArrayTest, AddInt) {
  auto result = ca1->operator+(3);
  EXPECT_EQ(result->shape(), ca1->shape());
  EXPECT_DOUBLE_EQ((*result)(0, 0), (*ca1)(0, 0) + 3);
}

TEST_F(ControlArrayTest, MulControlArrayNullThrows) {
  EXPECT_THROW(ca1->operator*((ControlArraySP) nullptr), std::invalid_argument);
}

TEST_F(ControlArrayTest, MulControlArrayDifferentAlignmentThrows) {
  EXPECT_THROW(ca1->operator*(ca2), std::runtime_error);
}

TEST_F(ControlArrayTest, MulFArraySP) {
  auto farr   = std::make_shared<generic::FArray<double>>(arr1);
  auto result = ca1->operator*(farr);
  EXPECT_EQ(result->shape(), ca1->shape());
}

TEST_F(ControlArrayTest, MulFArraySPNullThrows) {
  EXPECT_THROW(ca1->operator*((generic::FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(ControlArrayTest, AddFArraySP) {
  auto farr   = std::make_shared<generic::FArray<double>>(arr1);
  auto result = ca1->operator+(farr);
  EXPECT_EQ(result->shape(), ca1->shape());
}

TEST_F(ControlArrayTest, AddFArraySPNullThrows) {
  EXPECT_THROW(ca1->operator+((generic::FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(ControlArrayTest, MinFArraySP) {
  auto farr   = std::make_shared<generic::FArray<double>>(arr1);
  auto result = ca1->min(farr);
  EXPECT_EQ(result->shape(), ca1->shape());
}

TEST_F(ControlArrayTest, MinFArraySPNullThrows) {
  EXPECT_THROW(ca1->min((generic::FArraySP<double>)nullptr),
               std::invalid_argument);
}

TEST_F(ControlArrayTest, MaxControlArrayNullThrows) {
  EXPECT_THROW(ca1->max((ControlArraySP) nullptr), std::invalid_argument);
}

TEST_F(ControlArrayTest, MaxControlArrayDifferentAlignmentThrows) {
  std::cout << ca1->alignment()->to_json_string() << std::endl;
  std::cout << ca2->alignment()->to_json_string() << std::endl;
  EXPECT_THROW(ca1->max(ca2), std::invalid_argument);
}

TEST_F(ControlArrayTest, MaxFArraySPNullThrows) {
  EXPECT_THROW(ca1->max((generic::FArraySP<double>)nullptr),
               std::invalid_argument);
}

}  // namespace
