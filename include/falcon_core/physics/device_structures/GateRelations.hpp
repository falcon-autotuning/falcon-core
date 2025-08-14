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
                      public falcon_core::generic::Song {
  static_assert(std::is_base_of<Gate, K>::value, "T must be derived from Gate");
  static_assert(std::is_base_of<Gates<Gate>, V>::value,
                "T must be derived from Gates");

 public:
  using std::map<std::shared_ptr<K>, std::shared_ptr<V>>::map;

 private:
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       cereal::base_class<
           std::map<std::shared_ptr<Gate>, std::shared_ptr<Gates<Gate>>>>(
           this));
  }

 protected:
  GateRelations() = default;
  friend class cereal::access;
};

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
