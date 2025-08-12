#pragma once

#include "falcon_core/Jsonable.hpp"

namespace falcon_core {

class AnalyticFunction : public Jsonable {
public:
  virtual ~AnalyticFunction() = default;
  virtual double evaluate(double x) const = 0;

  nlohmann::json to_json() const override {
    nlohmann::json j;
    add_metadata(j, "falcon_core.math.functions.analytic_function",
                 "AnalyticFunction");
    return j;
  }

  size_t hash() const override {
    return 0; // Base hash
  }
};

} // namespace falcon_core
