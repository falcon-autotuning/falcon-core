#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon-core/math/AnalyticFunction.hpp"
#include "falcon-core/math/arrays/ControlArray1D.hpp"

namespace {
using namespace falcon_core;
using namespace math;

TEST(AnalyticFunctionTest, ConstantFunctionEvaluate) {
  AnalyticFunctionSP func = AnalyticFunction::Constant(5.0);
  auto map = std::make_shared<falcon_core::generic::Map<std::string, double>>();
  EXPECT_DOUBLE_EQ(func->evaluate(map, 0.0), 5.0);
}
TEST(AnalyticFunctionTest, IdentityFunctionEvaluate) {
  auto func = AnalyticFunction::Identity();
  auto map = std::make_shared<falcon_core::generic::Map<std::string, double>>();
  map->insert("x", 0.0);
  EXPECT_DOUBLE_EQ(func->evaluate(map, 0.0), 0.0);
}

TEST(AnalyticFunctionTest, Serialization) {
  AnalyticFunctionSP func = AnalyticFunction::Constant(5.0);
  std::string        json = func->to_json_string();
  auto func2 = AnalyticFunction::from_json_string<AnalyticFunction>(json);
  ASSERT_TRUE(func2 != nullptr);
  auto map = std::make_shared<falcon_core::generic::Map<std::string, double>>();
  EXPECT_EQ(*func, *func2);
}

TEST(AnalyticFunctionTest, BadMapThrows) {
  auto func = AnalyticFunction::Identity();
  auto map = std::make_shared<falcon_core::generic::Map<std::string, double>>();
  EXPECT_THROW(func->evaluate(map, 0.0), std::invalid_argument);
}

TEST(AnalyticFunctionTest, NullMapInput) {
  auto func = AnalyticFunction::Identity();
  auto map  = nullptr;
  EXPECT_THROW(func->evaluate(map, 0.0), std::invalid_argument);
}

TEST(AnalyticFunctionTest, NegativeTimeEvaluate) {
  auto func = AnalyticFunction::Identity();
  auto map  = nullptr;
  EXPECT_THROW(func->evaluate(map, -1.0), std::invalid_argument);
}

TEST(AnalyticFunctionTest, BadMapThrowsRange) {
  auto func = AnalyticFunction::Identity();
  auto map = std::make_shared<falcon_core::generic::Map<std::string, double>>();
  EXPECT_THROW(func->evaluate(map, 0.1, 1.0), std::invalid_argument);
}

TEST(AnalyticFunctionTest, NullMapInputRange) {
  auto func = AnalyticFunction::Identity();
  auto map  = nullptr;
  EXPECT_THROW(func->evaluate(map, 0.1, 1.0), std::invalid_argument);
}

TEST(AnalyticFunctionTest, NegativeDeltaT) {
  auto func = AnalyticFunction::Identity();
  auto map  = nullptr;
  EXPECT_THROW(func->evaluate(map, -0.1, 1.0), std::invalid_argument);
}

TEST(AnalyticFunctionTest, ZeroDeltaT) {
  auto func = AnalyticFunction::Identity();
  auto map  = nullptr;
  EXPECT_THROW(func->evaluate(map, 0.0, 1.0), std::invalid_argument);
}

TEST(AnalyticFunctionTest, NegativeMaxTime) {
  auto func = AnalyticFunction::Identity();
  auto map  = nullptr;
  EXPECT_THROW(func->evaluate(map, 0.1, -1.0), std::invalid_argument);
}

TEST(AnalyticFunctionTest, ZeroMaxTime) {
  auto func = AnalyticFunction::Identity();
  auto map  = nullptr;
  EXPECT_THROW(func->evaluate(map, 0.1, 0.0), std::invalid_argument);
}

TEST(AnalyticFunctionTest, CustomEvaluation) {
  generic::ListSP<std::string> labels =
      std::make_shared<generic::List<std::string>>(
          std::vector<std::string>{"constant"});
  std::string expression = "2.0x[0]";
  auto        func       = AnalyticFunction(labels, expression);
  auto map = std::make_shared<falcon_core::generic::Map<std::string, double>>();
  map->insert("constant", 1.0);
  EXPECT_DOUBLE_EQ(func.evaluate(map, 0.0), 2.0);
}

TEST(AnalyticFunctionTest, CustomDeltaEvaluation) {
  AnalyticFunctionSP func = AnalyticFunction::Constant(5.0);
  auto map = std::make_shared<falcon_core::generic::Map<std::string, double>>();
  auto out = func->evaluate(map, 0.1, 1.0);
  EXPECT_EQ(out->size(), 11);
  EXPECT_EQ(out->data().at(0), 5.0);
  EXPECT_EQ(out->data().at(9), 5.0);
}

TEST(AnalyticFunctionTest, NullLabelsInput) {
  generic::ListSP<std::string> labels     = nullptr;
  std::string                  expression = "";
  EXPECT_THROW(AnalyticFunction(labels, expression), std::invalid_argument);
}

TEST(AnalyticFunctionTest, EmptyExpressionThrows) {
  generic::ListSP<std::string> labels =
      std::make_shared<generic::List<std::string>>(
          std::vector<std::string>{"constant"});
  std::string expression = "";
  EXPECT_THROW(AnalyticFunction(labels, expression), std::invalid_argument);
}

TEST(AnalyticFunctionTest, InvalidExpressionThrows) {
  generic::ListSP<std::string> labels =
      std::make_shared<generic::List<std::string>>(
          std::vector<std::string>{"constant"});
  std::string expression = "x[0]x[i";
  EXPECT_THROW(AnalyticFunction(labels, expression), std::invalid_argument);
}

TEST(AnalyticFunctionTest, TooManyLabels) {
  generic::ListSP<std::string> labels =
      std::make_shared<generic::List<std::string>>(
          std::vector<std::string>{"constant", "extra"});
  std::string expression = "2x[0]";
  EXPECT_THROW(AnalyticFunction(labels, expression), std::length_error);
}

TEST(AnalyticFunctionTest, TooFewLabels) {
  generic::ListSP<std::string> labels =
      std::make_shared<generic::List<std::string>>(
          std::vector<std::string>{"constant"});
  std::string expression = "2x[0] + x[1]";
  EXPECT_THROW(AnalyticFunction(labels, expression), std::length_error);
}

TEST(AnalyticFunctionTest, CustomQuadraticTimeEvaluation) {
  generic::ListSP<std::string> labels =
      std::make_shared<generic::List<std::string>>(std::vector<std::string>{});
  std::string expression = "t^2";
  auto        func       = AnalyticFunction(labels, expression);
  auto map = std::make_shared<falcon_core::generic::Map<std::string, double>>();
  EXPECT_DOUBLE_EQ(func.evaluate(map, 2.0), 4.0);
}

TEST(AnalyticFunctionTest, CustomQuadraticTimeArray) {
  generic::ListSP<std::string> labels =
      std::make_shared<generic::List<std::string>>(std::vector<std::string>{});
  std::string expression = "t^2";
  auto        func       = AnalyticFunction(labels, expression);
  auto map = std::make_shared<falcon_core::generic::Map<std::string, double>>();
  double                                    delta     = 0.1;
  double                                    start     = 0.0;
  double                                    end       = 2.0;
  const double                              tolerance = 1e-6;
  falcon_core::math::arrays::ControlArray1D expected_result =
      falcon_core::math::arrays::ControlArray1D(
          xt::pow(xt::arange(start, end, delta), 2));
  auto result = *func.evaluate(map, delta, end);
  for (int i = 0; i < expected_result.size(); i++) {
    EXPECT_NEAR(result.data().at(i), expected_result.data().at(i), tolerance);
  }
}
TEST(AnalyticFunctionTest, BrokenHardestPrompt) {
  double                       delta      = 0.1;
  double                       end        = 2.0;
  double                       gate_value = 0.3;
  generic::ListSP<std::string> labels =
      std::make_shared<generic::List<std::string>>(
          std::vector<std::string>{"gate"});
  std::string expression = "2*x[0]*t^3";
  auto        func       = AnalyticFunction(labels, expression);
  auto map = std::make_shared<falcon_core::generic::Map<std::string, double>>();
  map->insert("g", gate_value);
  EXPECT_THROW(func.evaluate(map, delta, end), std::invalid_argument);
}

TEST(AnalyticFunctionTest, HardestPrompt) {
  double                       delta      = 0.1;
  double                       start      = 0.0;
  double                       end        = 2.0;
  double                       gate_value = 0.3;
  const double                 tolerance  = 1e-6;
  generic::ListSP<std::string> labels =
      std::make_shared<generic::List<std::string>>(
          std::vector<std::string>{"gate"});
  std::string expression = "2*x[0]*t^3";
  auto        func       = AnalyticFunction(labels, expression);
  auto map = std::make_shared<falcon_core::generic::Map<std::string, double>>();
  map->insert("gate", gate_value);
  falcon_core::math::arrays::ControlArray1D expected_result =
      falcon_core::math::arrays::ControlArray1D(
          xt::pow(xt::arange(start, end, delta), 3) * 2 * gate_value);
  auto result = *func.evaluate(map, delta, end);
  for (int i = 0; i < expected_result.size(); i++) {
    EXPECT_NEAR(result.data().at(i), expected_result.data().at(i), tolerance);
  }
}

TEST(AnalyticFunctionTest, InEqualOperator) {
  auto func1 = AnalyticFunction::Constant(5.0);
  auto func2 = AnalyticFunction::Constant(6.0);
  EXPECT_TRUE(*func1 != *func2);
  EXPECT_FALSE(*func1 != *func1);
}

}  // namespace
