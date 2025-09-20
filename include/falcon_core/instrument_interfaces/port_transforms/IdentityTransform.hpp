#pragma once

#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
/**
 * @brief A transform that applies the identity function to the data.
 */
namespace falcon_core::instrument_interfaces::port_transforms {

class IdentityTransform : public PortTransform {
 public:
  IdentityTransform(names::InstrumentPortSP port, names::PortsSP ports);

 protected:
  IdentityTransform();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<port_transforms::PortTransform>(this));
  };
};

}  // namespace falcon_core::instrument_interfaces::port_transforms
