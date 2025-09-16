#pragma once

#include "falcon_core/instrument_interfaces/names/Knob.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"

namespace falcon_core::instrument_interfaces::names {

// Knobs: collection of Knob ports
class Knobs : public Ports<Knob> {
 public:
  Knobs();
  /**
   * @brief Initialize knobs from a collection of knob.
   */
  Knobs(const std::vector<KnobSP>& knobs);

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Ports<Knob>>(this));
  }
};
using KnobsSP = std::shared_ptr<Knobs>;
}  // namespace falcon_core::instrument_interfaces::names
