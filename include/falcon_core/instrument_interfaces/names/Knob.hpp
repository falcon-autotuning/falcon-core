#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"
namespace falcon_core {
namespace instrument_interfaces {
namespace names {

class Knob : public InstrumentPort<physics::device_structures::Gate> {
 public:
  using InstrumentPort<physics::device_structures::Gate>::InstrumentPort;

  Knob() = default;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<InstrumentPort<physics::device_structures::Gate>>(
        this));
  }

 private:
  friend class cereal::access;
};

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Knob)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::instrument_interfaces::names::Knob)
#endif
