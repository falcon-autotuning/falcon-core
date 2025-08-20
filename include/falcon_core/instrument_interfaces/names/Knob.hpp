#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

// Knob: type alias for InstrumentPort<UsefulGate>
using Knob = InstrumentPort<physics::device_structures::UsefulGate>;

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core

// No CEREAL_REGISTER_TYPE for Knob because it is a type alias.
