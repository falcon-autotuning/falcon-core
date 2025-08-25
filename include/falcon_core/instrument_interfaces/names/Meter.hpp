#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/physics/device_structures/Ohmic.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

class Meter : public InstrumentPort<physics::device_structures::Ohmic> {
 public:
  Meter() = default;
  Meter(std::string                                        default_name,
        std::shared_ptr<physics::device_structures::Ohmic> pseudo_name,
        Instrument                                         instrument_type,
        std::shared_ptr<physics::units::SymbolUnit>        units,
        std::string                                        description)
      : InstrumentPort<physics::device_structures::Ohmic>(
            default_name, pseudo_name, instrument_type, units, description) {}

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<InstrumentPort<physics::device_structures::Ohmic>>(
        this));
  };

 private:
  friend class cereal::access;
};

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Meter)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::Meter)
#endif
