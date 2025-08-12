#pragma once

#include "falcon_core/AnalyticFunction.hpp"

namespace falcon_core {

class ConstantFunction : public AnalyticFunction {
public:
    ConstantFunction(double value) : _value(value) {}

    double evaluate(double x) const override {
        // x is ignored for a constant function
        (void)x;
        return _value;
    }

    nlohmann::json to_json() const override {
        nlohmann::json j = AnalyticFunction::to_json();
        add_metadata(j, "falcon_core.math.functions.analytic_function", "ConstantFunction");
        j["_value"] = _value;
        return j;
    }

private:
    double _value;
};

} // namespace falcon_core
