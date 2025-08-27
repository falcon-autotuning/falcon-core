#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Gates.hpp"
#include "falcon_core/physics/device_structures/ScreeningGate.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of ScreeningGates.
 */
class ScreeningGates : public Gates<ScreeningGate, ScreeningGates> {
 public:
  ScreeningGates() = default;
  ScreeningGates(size_t count) : Gates<ScreeningGate, ScreeningGates>(count) {}
  ScreeningGates(size_t count, const ScreeningGateSP& value)
      : Gates<ScreeningGate, ScreeningGates>(count, value) {}
  ScreeningGates(const std::vector<ScreeningGateSP>& vec)
      : Gates<ScreeningGate, ScreeningGates>(vec) {}
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Gates<ScreeningGate, ScreeningGates>>(this));
  }

 protected:
  friend class cereal::access;
};
using ScreeningGatesSP = std::shared_ptr<ScreeningGates>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(ScreeningGates)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, ScreeningGates)
#endif
