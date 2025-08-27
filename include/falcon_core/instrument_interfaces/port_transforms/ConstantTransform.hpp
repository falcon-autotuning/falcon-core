#pragma once

#include <memory>

#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/analytic_functions/ConstantFunction.hpp"

/**
 * @brief A transform that applies a constant function to the data.
 */
namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

class ConstantTransform : public PortTransform {
 public:
  /**
   * @brief Construct a ConstantTransform.
   * @param value The constant value to apply.
   */
  ConstantTransform(double value)
      : PortTransform(
            std::make_shared<math::analytic_functions::ConstantFunction>(
                value)) {}

  /**
   * @brief Default constructor for serialization.
   */
  ConstantTransform() : PortTransform() {}

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<PortTransform>(this));
  }

 protected:
  friend class cereal::access;
};

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::ConstantTransform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::port_transforms::ConstantTransform)
#endif
