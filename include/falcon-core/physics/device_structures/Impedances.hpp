#pragma once

#include "falcon-core/export.h"
#include "falcon-core/generic/List.hpp"
#include "falcon-core/physics/device_structures/Impedance.hpp"

namespace falcon_core {
namespace generic {
extern template class List<physics::device_structures::Impedance>;
}
namespace physics {
namespace device_structures {

/**
 * @brief A collection of Impedances.
 */
class FALCON_CORE_CPP_API Impedances : public generic::List<Impedance> {
 public:
  Impedances();
  Impedances(const std::vector<ImpedanceSP>& vec);
  bool operator==(const Impedances& other) const;
  bool operator!=(const Impedances& other) const;
};
using ImpedancesSP = std::shared_ptr<Impedances>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
