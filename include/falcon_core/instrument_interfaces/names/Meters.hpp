#pragma once

#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

// Meters: collection of Meter ports
class Meters : public Ports<Meter> {
 public:
  using Ports<Meter>::Ports;
};

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core
