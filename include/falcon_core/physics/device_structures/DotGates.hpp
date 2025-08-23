#pragma once

#include <cereal/archives/json.hpp>

#include "falcon_core/physics/device_structures/DotGate.hpp"
#include "falcon_core/physics/device_structures/Gates.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of DotGate pointers, also a Song.
 *
 * Uses composition: contains a vector of shared_ptr<T>.
 */
template <typename T>
class DotGates : public Gates<T> {
  static_assert(std::is_base_of<DotGate, T>::value,
                "T must be derived from DotGate");

 public:
  DotGates() = default;
  DotGates(size_t count) : Gates<T>(count) {}
  DotGates(size_t count, const std::shared_ptr<T>& value)
      : Gates<T>(count, value) {}
  DotGates(const std::vector<std::shared_ptr<T>>& vec) : Gates<T>(vec) {}
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Gates<T>>(this));
  }

 protected:
  friend class cereal::access;
};
template <typename T>
using DotGatesSP = std::shared_ptr<DotGates<T>>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
using namespace falcon_core::physics::device_structures;

#ifndef SWIG
CEREAL_REGISTER_TYPE(DotGates<DotGate>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     DotGates<DotGate>)
#endif
