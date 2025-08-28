#pragma once

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/device_structures/Ohmic.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of Ohmics.
 */
class Ohmics : public BaseConnections<Ohmic, Ohmics> {
 public:
  Ohmics();
  explicit Ohmics(size_t count);
  Ohmics(size_t count, const OhmicSP& value);
  Ohmics(const std::vector<OhmicSP>& vec);

  template <class Archive>
  void serialize(Archive& ar);

 protected:
  friend class cereal::access;
};
using OhmicsSP = std::shared_ptr<Ohmics>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
