#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/physics/device_structures/Impedance.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {
/**
 * @brief A collection of Impedance measurements on a quantum dot sample.
 */
class Impedances : public generic::List<Impedance> {
 public:
  Impedances() = default;
  Impedances(size_t count) : List<Impedance>(count) {}
  Impedances(size_t count, const ImpedanceSP& value)
      : List<Impedance>(count, value) {}
  Impedances(const std::vector<ImpedanceSP>& vec) : List<Impedance>(vec) {}

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::List<Impedance>>(this));
  }

 protected:
  friend class cereal::access;
};
using ImpedancesSP = std::shared_ptr<Impedances>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(falcon_core::generic::List<Impedance>)
CEREAL_REGISTER_TYPE(Impedances)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::List<Impedance>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, Impedances)
#endif
