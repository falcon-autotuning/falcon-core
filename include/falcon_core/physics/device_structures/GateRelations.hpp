#pragma once

#include <memory>

#include "falcon_core/physics/device_structures/Gate.hpp"
#include "falcon_core/physics/device_structures/Gates.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of Gate pointers, also a Song.
 *
 * Supports all std::vector methods and cereal serialization.
 */
template <typename K, typename V>
class GateRelations : public std::map<std::shared_ptr<K>, std::shared_ptr<V>>,
                      public generic::Song {
  static_assert(std::is_base_of<Gate, K>::value, "T must be derived from Gate");
  static_assert(std::is_base_of<Gates<Gate>, V>::value,
                "T must be derived from Gates");

 public:
  using std::map<std::shared_ptr<K>, std::shared_ptr<V>>::map;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       cereal::base_class<
           std::map<std::shared_ptr<Gate>, std::shared_ptr<Gates<Gate>>>>(
           this));
  }

 protected:
  GateRelations() = default;  // or initialize _name with a default value
  friend class cereal::access;
};
template <typename K, typename V>
struct GateRelationsSP {
  typedef std::shared_ptr<GateRelations<K, V>> type;
};
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core

#ifndef SWIG

using GR = falcon_core::physics::device_structures::GateRelations<
    falcon_core::physics::device_structures::Gate,
    falcon_core::physics::device_structures::Gates<
        falcon_core::physics::device_structures::Gate>>;
CEREAL_REGISTER_TYPE(GR)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, GR)
#endif
