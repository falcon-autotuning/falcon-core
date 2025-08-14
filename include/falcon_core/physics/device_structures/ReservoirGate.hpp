#pragma once

#include "falcon_core/physics/device_structures/Gate.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
/*
 * @brief A reservoir gate on a quantum dot device.
 */
class ReservoirGate : public Gate {
 public:
  ReservoirGate(std::string name) : Gate(std::move(name)) {}

 private:
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<Gate>(this));
  }

 protected:
  ReservoirGate() = default;    // for cereal access
  friend class cereal::access;  // cereal can access private members
};
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
