#pragma once

#include "falcon_core/autotuner_interfaces/names/Channel.hpp"
#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/config/geometries/GateGeometryArray1D.hpp"
namespace falcon_core {
namespace physics {
namespace core {
/**
 * @breif Elements of the config that pertain to an individual group of gates.
 */
class Group : public StandardConfigConnections {
  autotuner_interfaces::names::Channel _name;
  int                                  _num_dots;
  GateGeometryArray1DSP                _gate_geometries;
};
}  // namespace core
}  // namespace physics
}  // namespace falcon_core
