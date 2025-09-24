#include <gtest/gtest.h>

#include "falcon_core/math/AnalyticFunction.hpp"
#include "falcon_core/math/arrays/ControlArray1D.hpp"

namespace tests {
using namespace falcon_core;
using namespace math;

// Test constant function with ValidatedAnalyticFunction (mimics
// test_constant_function in Python)
TEST(AnalyticFunctionTest, ValidatedConstantFunctionEvaluateAndSerialization) {
  AnalyticFunctionSP func = AnalyticFunction::Constant(5.0);

  // Serialization round-trip
  std::string json = func->to_json_string();
  auto func2       = AnalyticFunction::from_json_string<AnalyticFunction>(json);
  ASSERT_TRUE(func2 != nullptr);

  // Evaluate with dummy values for all knobs
  falcon_core::generic::MapSP<std::string, double> map;
  EXPECT_DOUBLE_EQ(func->evaluate(map, 0.0), 5.0);
  EXPECT_DOUBLE_EQ(func2->evaluate(map, 0.0), 5.0);
}

// Test identity function with ValidatedAnalyticFunction (mimics
// test_analytic_function_identity in Python)
TEST(AnalyticFunctionTest, ValidatedIdentityFunctionEvaluateAndSerialization) {
  auto func = AnalyticFunction::Identity();

  // Serialization round-trip
  std::string json = func->to_json_string();
  auto func2       = AnalyticFunction::from_json_string<AnalyticFunction>(json);
  ASSERT_TRUE(func2 != nullptr);

  // Evaluate
  falcon_core::generic::MapSP<std::string, double> map;
  EXPECT_DOUBLE_EQ(func->evaluate(map, 0.0), 0.0);
  EXPECT_DOUBLE_EQ(func2->evaluate(map, 0.0), 0.0);
}

// Test custom function with ValidatedAnalyticFunction (mimics
// test_analytic_function_custom in Python)
TEST(AnalyticFunctionTest, ValidatedCustomFunctionEvaluateAndSerialization) {
  generic::ListSP<std::string> labels =
      std::make_shared<generic::List<std::string>>(
          std::vector<std::string>{"constant"});
  std::string expression = "2.0x[0]";
  auto        func = std::make_shared<AnalyticFunction>(labels, expression);

  falcon_core::generic::MapSP<std::string, double> map;
  map->insert("constant", 1.0);
  EXPECT_DOUBLE_EQ(func->evaluate(map, 0.0), 2.0);

  std::string json = func->to_json_string();
  auto func2       = AnalyticFunction::from_json_string<AnalyticFunction>(json);
  ASSERT_TRUE(func2 != nullptr);
  xt::xarray<double>     rawArray = xt::arange(0.0, 1.0, 0.1);
  arrays::ControlArray1D answer   = math::arrays::ControlArray1D(rawArray);
  EXPECT_EQ(*(func2->evaluate(map, 0.1, 1.0)), answer);
}
}  // namespace tests
