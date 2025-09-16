#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
/**
 * @brief A transform that applies the identity function to the data.
 */
namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

class IdentityTransform : public PortTransform {
 public:
  IdentityTransform(names::InstrumentPortSP               port,
                    names::PortsSP<names::InstrumentPort> ports);

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<port_transforms::PortTransform>(this));
  };

 protected:
  IdentityTransform();
  friend class cereal::access;
};

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core
