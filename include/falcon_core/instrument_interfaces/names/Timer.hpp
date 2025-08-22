#pragma once

#include "falcon_core/Constants.hpp"
#include "falcon_core/instrument_interfaces/names/Knob.hpp"
#include "falcon_core/physics/units/CommonUnits.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

class Timer : public Knob {
 public:
  Timer()
      : Knob(falcon_core::INSTRUMENT_TYPES::CLOCK,  // default_name
             nullptr,                               // pseudo_name
             falcon_core::INSTRUMENT_TYPES::CLOCK,  // instrument_type
             std::make_shared<physics::units::SymbolUnit>(
                 physics::units::CommonUnits::Second),
             "Clock") {}

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Knob>(this));
  }

 private:
  friend class cereal::access;
};

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Timer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::Timer)
#endif
