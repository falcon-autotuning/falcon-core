#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core::instrument_interfaces::names {

class Knob : public InstrumentPort {
 public:
  Knob(std::string                              default_name,
       physics::device_structures::ConnectionSP pseudo_name,
       Instrument                               instrument_type,
       physics::units::SymbolUnitSP             units,
       std::string                              description);

 protected:
  Knob();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<InstrumentPort>(this));
  }
};
using KnobSP = std::shared_ptr<Knob>;
}  // namespace falcon_core::instrument_interfaces::names
