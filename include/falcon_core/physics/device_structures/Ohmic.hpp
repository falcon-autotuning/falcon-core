#pragma once

#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

class Ohmic : public virtual BaseConnection {
 public:
  Ohmic(std::string name);

 protected:
  Ohmic();
  friend class cereal::access;
};
using OhmicSP = std::shared_ptr<Ohmic>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
