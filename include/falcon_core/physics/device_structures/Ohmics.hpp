#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/device_structures/Ohmic.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of Ohmic contacts to a quantum dot device.
 */
class Ohmics : public BaseConnections<Ohmic> {
 public:
  Ohmics() = default;
  Ohmics(size_t count) : BaseConnections<Ohmic>(count) {}
  Ohmics(size_t count, const OhmicSP& value)
      : BaseConnections<Ohmic>(count, value) {}
  Ohmics(const std::vector<OhmicSP>& vec) : BaseConnections<Ohmic>(vec) {}
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseConnections<Ohmic>>(this));
  }

 protected:
  friend class cereal::access;
};
using OhmicsSP = std::shared_ptr<Ohmics>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(Ohmics)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, Ohmics)
#endif
