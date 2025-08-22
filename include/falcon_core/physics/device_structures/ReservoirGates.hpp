#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Gates.hpp"
#include "falcon_core/physics/device_structures/ReservoirGate.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of ReservoirGate pointers, also a Song.
 *
 * Uses composition: contains a vector of shared_ptr<T>.
 */
class ReservoirGates : public Gates<ReservoirGate> {
 public:
  using Gates<ReservoirGate>::Gates;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Gates<ReservoirGate>>(this));
  }

 protected:
  friend class cereal::access;
};
using ReservoirGatesSP = std::shared_ptr<ReservoirGates>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(ReservoirGates)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, ReservoirGates)
#endif
