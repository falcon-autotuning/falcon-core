#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"

namespace falcon_core::instrument_interfaces::port_transforms {

class ConstantTransform : public PortTransform {
 public:
  ConstantTransform(const double&                                scale,
                    const names::PortsSP<names::InstrumentPort>& ports);

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<port_transforms::PortTransform>(this));
  };

 protected:
  friend class cereal::access;
  ConstantTransform();
};

}  // namespace falcon_core::instrument_interfaces::port_transforms
