#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Ohmic.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
/*
 * @brief A gate with an ohmic below it.
 */
class HasImplantedOhmic : public generic::Song {
  device_structures::OhmicSP _ohmic;

 public:
  HasImplantedOhmic(device_structures::OhmicSP ohmic) : _ohmic(ohmic) {}
  /**
   * @brief Returns the ohmic below the gate.
   */
  device_structures::OhmicSP ohmic() const { return _ohmic; }
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<HasImplantedOhmic>(this), _ohmic);
  }

 protected:
  HasImplantedOhmic() : _ohmic(nullptr) {};
  friend class cereal::access;
};
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::config::geometries;
CEREAL_REGISTER_TYPE(HasImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     HasImplantedOhmic)
#endif
