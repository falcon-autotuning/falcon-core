#pragma once

#include "falcon_core/instrument_interfaces/names/Knob.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

// Knobs: collection of Knob ports
class Knobs : public Ports<Knob> {
 public:
  Knobs();

  template <class Archive>
  void serialize(Archive& ar);

 private:
  friend class cereal::access;
};

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core
