#include "falcon_core/physics/device_structures/BarrierGate.hpp"

using namespace falcon_core::physics::device_structures;
namespace falcon_core {
namespace physics {
namespace device_structures {
BarrierGate::BarrierGate(std::string name)
    : BaseConnection(name, DeviceFeature::BarrierGate) {}
BarrierGate::BarrierGate() = default;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
