#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {

// This is a simplified placeholder for AcquisitionContext.
// A full implementation would depend on MeasurementContext.
class AcquisitionContext : public generic::Song {
 public:
  AcquisitionContext() = default;
};
}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
