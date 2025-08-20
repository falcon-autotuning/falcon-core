#pragma once

#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

// Knobs: collection of Knob ports
class Knobs : public Ports<Knob> {
 public:
  using Ports<Knob>::Ports;
};

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core
