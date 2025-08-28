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
  OhmicSP _ohmic;

 public:
  HasImplantedOhmic(OhmicSP ohmic);
  /**
   * @brief Returns the ohmic below the gate.
   */
  OhmicSP ohmic() const;
  template <class Archive>
  void serialize(Archive& ar);

 protected:
  HasImplantedOhmic();
  friend class cereal::access;
};
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
