#pragma once

#include "falcon_core/instrument_interfaces/names/Meter.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"

namespace falcon_core::instrument_interfaces::names {

// Meters: collection of Meter ports
class Meters : public Ports<Meter> {
 public:
  Meters();
  /**
   * @brief Initialize meters from a collection of Meter ports.
   */
  Meters(const std::vector<MeterSP>& knobs);

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Ports<Meter>>(this));
  }
};

}  // namespace falcon_core::instrument_interfaces::names
