#pragma once

#include "falcon_core/instrument_interfaces/names/Meter.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

// Meters: collection of Meter ports
class Meters : public Ports<Meter> {
 public:
  Meters();

  template <class Archive>
  void serialize(Archive& ar);

 private:
  friend class cereal::access;
};

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core
