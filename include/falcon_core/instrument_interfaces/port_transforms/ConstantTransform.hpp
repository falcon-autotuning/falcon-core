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
  ConstantTransform(double value);
  ConstantTransform();

  template <class Archive>
  void serialize(Archive& ar);

 protected:
  friend class cereal::access;
};

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core
