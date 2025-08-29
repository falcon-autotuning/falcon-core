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
  Timer();

  template <class Archive>
  void serialize(Archive& ar);

 private:
  friend class cereal::access;
};

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core
