#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
namespace falcon_core::physics::config::geometries {
/*
 * @brief A gate with an ohmic below it.
 */
class HasImplantedOhmic : public virtual generic::Song {
  device_structures::ConnectionSP _ohmic;

 public:
  HasImplantedOhmic(device_structures::ConnectionSP ohmic);
  /**
   * @brief Returns the ohmic below the gate.
   */
  device_structures::ConnectionSP ohmic() const;

 protected:
  HasImplantedOhmic();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this), _ohmic);
  }
};
using HasImplantedOhmicSP = std::shared_ptr<HasImplantedOhmic>;
}  // namespace falcon_core::physics::config::geometries
