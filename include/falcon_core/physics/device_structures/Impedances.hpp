#pragma once

#include "falcon_core/physics/device_structures/Impedance.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of Impedance pointers, also a Song.
 *
 * Supports all std::vector methods and cereal serialization.
 */
template <typename T>
class Impedances : public std::vector<std::shared_ptr<T>>,
                   public generic::Song {
  static_assert(std::is_base_of<Impedance, T>::value,
                "T must be derived from Impedance");

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       cereal::base_class<std::vector<std::shared_ptr<Impedance>>>(this));
  }

 public:
  using std::vector<std::shared_ptr<Impedance>>::vector;
};

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
