#pragma once

#include <memory>

#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/analytic_functions/Identity.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

class IdentityTransform : public PortTransform {
 public:
  IdentityTransform()
      : PortTransform(std::make_shared<math::analytic_functions::Identity>()) {}
};
}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core
