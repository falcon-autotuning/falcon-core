#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include <string>
#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"
#include "falcon_core/math/analytic_functions/ConstantFunction.hpp"
#include "falcon_core/math/analytic_functions/Identity.hpp"
#include "falcon_core/math/analytic_functions/ValidatedAnalyticFunction.hpp"
#include "falcon_core/instrument_interfaces/names/Knob.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"

using namespace falcon_core::math::analytic_functions;
using namespace falcon_core::instrument_interfaces::names;

// Helper to create a clock knob (mimics Python Clock class)
std::shared_ptr<Knob> make_clock_knob() {
    return std::make_shared<Knob>(
        "CLOCK", nullptr, "CLOCK", nullptr, "Clock"
    );
}

// Test constant function with ValidatedAnalyticFunction (mimics test_constant_function in Python)
TEST(AnalyticFunctionTest, ValidatedConstantFunctionEvaluateAndSerialization) {
    std::vector<std::string> stuff = {"a", "b", "c", "d", "e", "f", "g", "h"};
    auto ports = std::make_shared<Ports<Knob>>();
    for (const auto& name : stuff) {
        ports->push_back(std::make_shared<Knob>(name, nullptr, "PLUNGER", nullptr, ""));
    }
    ports->push_back(make_clock_knob());

    auto func = std::make_shared<ConstantFunction>(5.0);
    auto validated = std::make_shared<ValidatedAF_KnobPorts>(ports, func);

    // Serialization round-trip
    std::string json = validated->to_json_string();
    auto validated2 = ValidatedAF_KnobPorts::from_json_string<ValidatedAF_KnobPorts>(json);
    ASSERT_TRUE(validated2 != nullptr);

    // Evaluate with dummy values for all knobs
    EXPECT_DOUBLE_EQ(validated->evaluate(0.0), 5.0);
    EXPECT_DOUBLE_EQ(validated2->evaluate(0.0), 5.0);
}

// Test identity function with ValidatedAnalyticFunction (mimics test_analytic_function_identity in Python)
TEST(AnalyticFunctionTest, ValidatedIdentityFunctionEvaluateAndSerialization) {
    std::vector<std::string> stuff = {"a", "b", "c", "d", "e", "f", "g", "h"};
    auto ports = std::make_shared<Ports<Knob>>();
    for (const auto& name : stuff) {
        ports->push_back(std::make_shared<Knob>(name, nullptr, "PLUNGER", nullptr, ""));
    }
    ports->push_back(make_clock_knob());

    auto knob = ports->at(0);
    auto func = std::make_shared<Identity>();
    auto validated = std::make_shared<ValidatedAF_KnobPorts>(ports, func);

    // Serialization round-trip
    std::string json = validated->to_json_string();
    auto validated2 = ValidatedAF_KnobPorts::from_json_string<ValidatedAF_KnobPorts>(json);
    ASSERT_TRUE(validated2 != nullptr);

    // Evaluate
    EXPECT_DOUBLE_EQ(validated->evaluate(0.0), 0.0);
    EXPECT_DOUBLE_EQ(validated2->evaluate(0.0), 0.0);
}

// Example of a custom analytic function: multiply by 2 (mimics mult2 in Python)
class Mult2Function : public AnalyticFunction {
public:
    Mult2Function() = default;
    double evaluate(double x) const override {
        return x * 2.0;
    }
private:
    friend class cereal::access;
    template <class Archive>
    void serialize(Archive& ar) {
        ar(cereal::base_class<AnalyticFunction>(this));
    }
};

CEREAL_REGISTER_TYPE(Mult2Function)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, Mult2Function)

// Test custom function with ValidatedAnalyticFunction (mimics test_analytic_function_custom in Python)
TEST(AnalyticFunctionTest, ValidatedCustomFunctionEvaluateAndSerialization) {
    std::vector<std::string> stuff = {"a"};
    auto ports = std::make_shared<Ports<Knob>>();
    for (const auto& name : stuff) {
        ports->push_back(std::make_shared<Knob>(name, nullptr, "PLUNGER", nullptr, ""));
    }
    ports->push_back(make_clock_knob());

    auto func = std::make_shared<Mult2Function>();
    auto validated = std::make_shared<ValidatedAF_KnobPorts>(ports, func);

    EXPECT_DOUBLE_EQ(validated->evaluate(1.0), 2.0);

    std::string json = validated->to_json_string();
    auto validated2 = ValidatedAF_KnobPorts::from_json_string<ValidatedAF_KnobPorts>(json);
    ASSERT_TRUE(validated2 != nullptr);
    EXPECT_DOUBLE_EQ(validated2->evaluate(1.0), 2.0);
}
