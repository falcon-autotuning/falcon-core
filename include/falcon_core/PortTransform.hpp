#pragma once

#include "falcon_core/AnalyticFunction.hpp"
#include "falcon_core/Jsonable.hpp"
#include <memory>

namespace falcon_core {

class PortTransform : public Jsonable {
public:
  PortTransform(std::shared_ptr<AnalyticFunction> function)
      : _function(std::move(function)) {}

  double apply(double value) const {
    if (!_function)
      return value;
    return _function->evaluate(value);
  }

  nlohmann::json to_json() const override {
    nlohmann::json j;
    add_metadata(j, "falcon_core.physics.transforms.port_transform",
                 "PortTransform");
    if (_function) {
      j["_function"] = _function->to_json();
    }
    return j;
  }

  size_t hash() const override { return _function ? _function->hash() : 0; }

private:
  std::shared_ptr<AnalyticFunction> _function;
};

} // namespace falcon_core
