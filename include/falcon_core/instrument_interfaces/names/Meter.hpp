#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/physics/device_structures/Ohmic.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

class Meter : public InstrumentPort {
 public:
  Meter();
  Meter(std::string                                        default_name,
        std::shared_ptr<physics::device_structures::Ohmic> pseudo_name,
        Instrument                                         instrument_type,
        std::shared_ptr<physics::units::SymbolUnit>        units,
        std::string                                        description);

  template <class Archive>
  void serialize(Archive& ar);

 private:
  friend class cereal::access;
};

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core
