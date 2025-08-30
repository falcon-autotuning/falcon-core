#include "falcon_core/physics/device_structures/ScreeningGate.hpp"

using namespace falcon_core::physics::device_structures;
namespace falcon_core {
namespace physics {
namespace device_structures {
ScreeningGate::ScreeningGate(std::string name)
    : BaseConnection(name, DeviceFeature::ScreeningGate) {}
ScreeningGate::ScreeningGate() = default;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::ScreeningGate)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::device_structures::ScreeningGate)
