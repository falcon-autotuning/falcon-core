#include "falcon_core/physics/device_structures/PlungerGate.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
PlungerGate::PlungerGate() = default;
PlungerGate::PlungerGate(std::string name)
    : BaseConnection(name, DeviceFeature::PlungerGate) {}
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
