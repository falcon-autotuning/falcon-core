#pragma once

#include "falcon_core/instrument_interfaces/names/Meter.hpp"
#include "falcon_core/physics/units/CommonUnits.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

class ExecutionClock : public Meter {
 public:
  ExecutionClock();

  template <class Archive>
  void serialize(Archive& ar);

 private:
  friend class cereal::access;
};

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core
