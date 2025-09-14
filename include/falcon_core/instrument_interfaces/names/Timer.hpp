#pragma once

#include "falcon_core/instrument_interfaces/names/Knob.hpp"

namespace falcon_core::instrument_interfaces::names {

class Timer : public Knob {
 public:
  Timer();

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Knob>(this));
  }
};

}  // namespace falcon_core::instrument_interfaces::names
