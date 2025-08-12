#pragma once

#include "falcon_core/Gate.hpp" // Using Gate as a placeholder for Connection
#include "falcon_core/Jsonable.hpp"
#include "falcon_core/Ports.hpp"

namespace falcon_core {

// This is a simplified placeholder for AcquisitionContext.
// A full implementation would depend on MeasurementContext.
class AcquisitionContext : public Jsonable {
public:
  AcquisitionContext() = default;

  nlohmann::json to_json() const override {
    nlohmann::json j;
    add_metadata(
        j, "falcon_core.autotuner_interfaces.contexts.acquisition_context",
        "AcquisitionContext");
    return j;
  }

  size_t hash() const override {
    return 0; // Placeholder
  }
};

} // namespace falcon_core
