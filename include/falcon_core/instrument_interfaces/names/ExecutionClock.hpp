#pragma once

#include "falcon_core/instrument_interfaces/names/Meter.hpp"

namespace falcon_core::instrument_interfaces::names {

class ExecutionClock : public Meter {
 public:
  ExecutionClock();

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Meter>(this));
  }
};

}  // namespace falcon_core::instrument_interfaces::names
