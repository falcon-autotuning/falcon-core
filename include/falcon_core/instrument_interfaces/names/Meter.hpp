#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

// Meter: type alias for InstrumentPort<Ohmic>
using Meter = InstrumentPort<physics::units::Ohmic>;

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core
