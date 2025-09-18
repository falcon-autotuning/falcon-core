#include <gtest/gtest.h>

#include <memory>

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/analytic_functions/ConstantFunction.hpp"
#include "falcon_core/math/analytic_functions/Identity.hpp"
#include "falcon_core/math/analytic_functions/ValidatedAnalyticFunction.hpp"

namespace tests {
using namespace falcon_core::math::analytic_functions;
using namespace falcon_core::instrument_interfaces::names;

// Helper to create a clock knob (mimics Python Clock class)
std::shared_ptr<InstrumentPort> make_clock_knob() {
  return std::make_shared<InstrumentPort>(
      "CLOCK", nullptr, "CLOCK", nullptr, "Clock");
}

// Test constant function with ValidatedAnalyticFunction (mimics
// test_constant_function in Python)
TEST(AnalyticFunctionTest, ValidatedConstantFunctionEvaluateAndSerialization) {
  std::vector<std::string> stuff = {"a", "b", "c", "d", "e", "f", "g", "h"};
  auto                     ports = std::make_shared<Ports<InstrumentPort>>();
  for (const auto& name : stuff) {
    ports->push_back(std::make_shared<InstrumentPort>(
        name, nullptr, "PLUNGER", nullptr, ""));
  }
  ports->push_back(make_clock_knob());

  auto func      = std::make_shared<ConstantFunction>(5.0);
  auto validated = std::make_shared<ValidatedAnalyticFunction>(ports, func);

  // Serialization round-trip
  std::string json = validated->to_json_string();
  auto        validated2 =
      ValidatedAnalyticFunction::from_json_string<ValidatedAnalyticFunction>(
          json);
  ASSERT_TRUE(validated2 != nullptr);

  // Evaluate with dummy values for all knobs
  falcon_core::generic::MapSP<std::string, double> map;
  map->insert("x", 0.0);
  EXPECT_DOUBLE_EQ(validated->function()->function(map), 5.0);
  EXPECT_DOUBLE_EQ(validated2->function()->function(map), 5.0);
}

// Test identity function with ValidatedAnalyticFunction (mimics
// test_analytic_function_identity in Python)
TEST(AnalyticFunctionTest, ValidatedIdentityFunctionEvaluateAndSerialization) {
  std::vector<std::string> stuff = {"a", "b", "c", "d", "e", "f", "g", "h"};
  auto                     ports = std::make_shared<Ports<InstrumentPort>>();
  for (const auto& name : stuff) {
    ports->push_back(std::make_shared<InstrumentPort>(
        name, nullptr, "PLUNGER", nullptr, ""));
  }
  ports->push_back(make_clock_knob());

  auto knob      = ports->at(0);
  auto func      = std::make_shared<Identity>(ports, ports->at(0));
  auto validated = std::make_shared<ValidatedAnalyticFunction>(
      ports, std::dynamic_pointer_cast<AnalyticFunction>(func));

  // Serialization round-trip
  std::string json = validated->to_json_string();
  auto        validated2 =
      ValidatedAnalyticFunction::from_json_string<ValidatedAnalyticFunction>(
          json);
  ASSERT_TRUE(validated2 != nullptr);

  // Evaluate
  falcon_core::generic::MapSP<std::string, double> map;
  map->insert("x", 0.0);
  EXPECT_DOUBLE_EQ(validated->function()->function(map), 0.0);
  EXPECT_DOUBLE_EQ(validated2->function()->function(map), 0.0);
}

// Example of a custom analytic function: multiply by 2 (mimics mult2 in Python)
class Mult2Function : public AnalyticFunction {
 public:
  Mult2Function() = default;
  double evaluate(double x) const { return x * 2.0; }

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<AnalyticFunction>(this));
  }
};
}  // namespace tests
CEREAL_REGISTER_TYPE(tests::Mult2Function)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     tests::Mult2Function)
namespace tests {
// Test custom function with ValidatedAnalyticFunction (mimics
// test_analytic_function_custom in Python)
TEST(AnalyticFunctionTest, ValidatedCustomFunctionEvaluateAndSerialization) {
  std::vector<std::string> stuff = {"a"};
  auto                     ports = std::make_shared<Ports<InstrumentPort>>();
  for (const auto& name : stuff) {
    ports->push_back(std::make_shared<InstrumentPort>(
        name, nullptr, "PLUNGER", nullptr, ""));
  }
  ports->push_back(make_clock_knob());

  auto func      = std::make_shared<Mult2Function>();
  auto validated = std::make_shared<ValidatedAnalyticFunction>(ports, func);

  falcon_core::generic::MapSP<std::string, double> map;
  map->insert("x", 1.0);
  EXPECT_DOUBLE_EQ(validated->function()->function(map), 2.0);

  std::string json = validated->to_json_string();
  auto        validated2 =
      ValidatedAnalyticFunction::from_json_string<ValidatedAnalyticFunction>(
          json);
  ASSERT_TRUE(validated2 != nullptr);
  EXPECT_DOUBLE_EQ(validated2->function()->function(map), 2.0);
}
}  // namespace tests
