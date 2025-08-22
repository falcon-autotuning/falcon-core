#pragma once

#include "falcon_core/Constants.hpp"
#include "falcon_core/instrument_interfaces/names/Meter.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

class ExecutionClock : public Meter {
 public:
  ExecutionClock()
      : Meter(falcon_core::INSTRUMENT_TYPES::CLOCK,  // default_name
              nullptr,                               // pseudo_name
              falcon_core::INSTRUMENT_TYPES::CLOCK,  // instrument_type
              std::make_shared<physics::units::SymbolUnit>(
                  physics::units::CommonUnits::Second),
              "Execution clock") {}

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Meter>(this));
  }

 private:
  friend class cereal::access;
};

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::ExecutionClock)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::ExecutionClock)
#endif
