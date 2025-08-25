#pragma once

#include "falcon_core/autotuner_interfaces/names/Channels.hpp"
#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/config/core/VoltageConstraints.hpp"
#include "falcon_core/physics/device_structures/Impedances.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
/**
 * @brief The imported config file for falcon use.
 */
class Config : public StandardConfigConnections {
  int                _num_unique_channels;
  Impedances         _wiring_DC;
  Channels           _channels;
  VoltageConstraints _voltage_constraints;
};
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
