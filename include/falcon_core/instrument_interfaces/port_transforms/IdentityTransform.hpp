#pragma once

#include <memory>

#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/analytic_functions/Identity.hpp"

/**
 * @brief A transform that applies the identity function to the data.
 */
namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

class IdentityTransform : public PortTransform {
 public:
  /**
   * @brief Construct an IdentityTransform.
   */
  IdentityTransform()
      : PortTransform(std::make_shared<math::analytic_functions::Identity>()) {}

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<PortTransform>(this));
  }
};

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::port_transforms::IdentityTransform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::instrument_interfaces::port_transforms::IdentityTransform)
#endif
