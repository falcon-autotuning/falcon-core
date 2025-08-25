#include <gtest/gtest.h>
#include <memory>
#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"
#include "falcon_core/math/analytic_functions/ConstantFunction.hpp"
#include "falcon_core/math/analytic_functions/Identity.hpp"

using namespace falcon_core::math::analytic_functions;

// Test ConstantFunction: value is always the same
TEST(AnalyticFunctionTest, ConstantFunctionEvaluateAndSerialization) {
    double value = 5.0;
    auto f = std::make_shared<ConstantFunction>(value);

    // Evaluate at several points
    EXPECT_DOUBLE_EQ(f->evaluate(0.0), value);
    EXPECT_DOUBLE_EQ(f->evaluate(123.45), value);

    // Serialization round-trip
    std::string json = f->to_json_string();
    auto f2 = ConstantFunction::from_json_string<ConstantFunction>(json);
    ASSERT_TRUE(f2 != nullptr);
    EXPECT_DOUBLE_EQ(f2->evaluate(0.0), value);
    EXPECT_DOUBLE_EQ(f2->evaluate(123.45), value);
}

// Test Identity: output equals input
TEST(AnalyticFunctionTest, IdentityEvaluateAndSerialization) {
    auto f = std::make_shared<Identity>();

    EXPECT_DOUBLE_EQ(f->evaluate(0.0), 0.0);
    EXPECT_DOUBLE_EQ(f->evaluate(42.0), 42.0);
    EXPECT_DOUBLE_EQ(f->evaluate(-3.14), -3.14);

    // Serialization round-trip
    std::string json = f->to_json_string();
    auto f2 = Identity::from_json_string<Identity>(json);
    ASSERT_TRUE(f2 != nullptr);
    EXPECT_DOUBLE_EQ(f2->evaluate(0.0), 0.0);
    EXPECT_DOUBLE_EQ(f2->evaluate(42.0), 42.0);
    EXPECT_DOUBLE_EQ(f2->evaluate(-3.14), -3.14);
}

// Example of a custom analytic function: multiply by 2
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

TEST(AnalyticFunctionTest, CustomFunctionEvaluateAndSerialization) {
    auto f = std::make_shared<Mult2Function>();

    EXPECT_DOUBLE_EQ(f->evaluate(1.0), 2.0);
    EXPECT_DOUBLE_EQ(f->evaluate(-3.0), -6.0);

    // Serialization round-trip
    std::string json = f->to_json_string();
    auto f2 = Mult2Function::from_json_string<Mult2Function>(json);
    ASSERT_TRUE(f2 != nullptr);
    EXPECT_DOUBLE_EQ(f2->evaluate(1.0), 2.0);
    EXPECT_DOUBLE_EQ(f2->evaluate(-3.0), -6.0);
}
