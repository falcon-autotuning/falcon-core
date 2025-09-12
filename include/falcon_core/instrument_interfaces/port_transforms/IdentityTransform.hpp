#pragma once

#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"

/**
 * @brief A transform that applies the identity function to the data.
 */
namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

class IdentityTransform : public PortTransform {
 public:
  IdentityTransform();

  template <class Archive>
  void serialize(Archive& ar);

 protected:
  friend class cereal::access;
};

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core
