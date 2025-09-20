#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

namespace falcon_core::instrument_interfaces::names {

class Meter : public InstrumentPort {
 public:
  Meter(std::string                              default_name,
        physics::device_structures::ConnectionSP pseudo_name,
        Instrument                               instrument_type,
        physics::units::SymbolUnitSP             units,
        std::string                              description);

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
