#pragma once

#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/analytic_functions/Identity.hpp"

#include <memory>

namespace falcon_core
{
namespace instrument_interfaces
{
namespace port_transforms
{

class IdentityTransform : public PortTransform
{
public:
  IdentityTransform ()
      : PortTransform (std::make_shared<math::analytic_functions::Identity> ())
  {
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j = PortTransform::to_json ();
    add_metadata (j,
                  "falcon_core.physics.transforms.identity_transform",
                  "IdentityTransform");
    return j;
  }
};
}
}
} // namespace falcon_core
