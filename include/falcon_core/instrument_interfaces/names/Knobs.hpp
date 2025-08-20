#pragma once

#include "falcon_core/instrument_interfaces/names/Knob.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

// Knobs: collection of Knob ports
class Knobs : public Ports<Knob> {
 public:
  using Ports<Knob>::Ports;
  Knobs() = default;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Ports<Knob>>(this));
  }

 private:
  friend class cereal::access;
};

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Knobs)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::Knobs)
#endif
