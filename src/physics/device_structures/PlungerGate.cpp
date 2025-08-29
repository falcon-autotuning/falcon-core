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
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::PlungerGate)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::device_structures::PlungerGate)
