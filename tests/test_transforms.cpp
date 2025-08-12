#include <gtest/gtest.h>
#include "falcon_core/AnalyticFunction.hpp"
#include "falcon_core/PortTransform.hpp"
#include "falcon_core/PortTransforms.hpp"
#include <memory>

using namespace falcon_core;

// A concrete implementation of AnalyticFunction for testing
class LinearFunction : public AnalyticFunction {
public:
    LinearFunction(double slope, double intercept) : _slope(slope), _intercept(intercept) {}

    double evaluate(double x) const override {
        return _slope * x + _intercept;
    }

    nlohmann::json to_json() const override {
        nlohmann::json j = AnalyticFunction::to_json();
        add_metadata(j, "test", "LinearFunction");
        j["_slope"] = _slope;
        j["_intercept"] = _intercept;
        return j;
    }

private:
    double _slope;
    double _intercept;
};

TEST(AnalyticFunctionTest, Evaluation) {
    auto func = std::make_shared<LinearFunction>(2.0, 1.0);
    ASSERT_DOUBLE_EQ(func->evaluate(5.0), 11.0);
}

TEST(PortTransformTest, Application) {
    auto func = std::make_shared<LinearFunction>(3.0, -2.0);
    PortTransform transform(func);
    ASSERT_DOUBLE_EQ(transform.apply(10.0), 28.0);
}

TEST(PortTransformsTest, Collection) {
    auto func1 = std::make_shared<LinearFunction>(1.0, 0.0);
    auto func2 = std::make_shared<LinearFunction>(2.0, 1.0);
    auto transform1 = std::make_shared<PortTransform>(func1);
    auto transform2 = std::make_shared<PortTransform>(func2);

    PortTransforms transforms;
    transforms.append(transform1);
    transforms.append(transform2);

    ASSERT_EQ(transforms.get_transforms().size(), 2);
    ASSERT_EQ(transforms.get_transforms()[0], transform1);
    ASSERT_EQ(transforms.get_transforms()[1], transform2);
}

// This test simulates how SWIG's director feature would be used.
// We create a C++ class that overrides a virtual method.
class DirectorTestFunction : public AnalyticFunction {
public:
    double evaluate(double x) const override {
        // In a real director call, this would call into Python.
        // Here, we just implement a different function (e.g., quadratic).
        return x * x;
    }
};

TEST(DirectorTest, PolymorphicCall) {
    std::shared_ptr<AnalyticFunction> func = std::make_shared<DirectorTestFunction>();
    PortTransform transform(func);

    // The PortTransform should call the overridden `evaluate` method.
    ASSERT_DOUBLE_EQ(transform.apply(5.0), 25.0);
}
