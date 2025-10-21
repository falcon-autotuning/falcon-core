#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/physics/device_structures/Impedance.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of Impedances.
 */
class Impedances : public generic::List<Impedance> {
 public:
  Impedances();
  Impedances(const std::vector<ImpedanceSP>& vec);
  bool operator==(const Impedances& other) const;
  bool operator!=(const Impedances& other) const;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<List<Impedance>>(this));
  }

 protected:
  friend class cereal::access;
};
using ImpedancesSP = std::shared_ptr<Impedances>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
