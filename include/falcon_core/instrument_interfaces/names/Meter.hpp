#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/physics/device_structures/Ohmic.hpp"

namespace falcon_core::instrument_interfaces::names {

class Meter : public InstrumentPort {
 public:
  Meter(std::string                                        default_name,
        std::shared_ptr<physics::device_structures::Ohmic> pseudo_name,
        Instrument                                         instrument_type,
        std::shared_ptr<physics::units::SymbolUnit>        units,
        std::string                                        description);

 protected:
  Meter();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<InstrumentPort>(this));
  }
};
using MeterSP = std::shared_ptr<Meter>;
}  // namespace falcon_core::instrument_interfaces::names
