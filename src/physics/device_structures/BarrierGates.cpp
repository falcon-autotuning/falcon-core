#include "falcon_core/physics/device_structures/BarrierGates.hpp"

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

BarrierGates::BarrierGates() = default;

BarrierGates::BarrierGates(size_t count) : BaseConnections(count) {}

BarrierGates::BarrierGates(size_t count, const BaseConnectionSP& value)
    : BaseConnections(count, value) {}

BarrierGates::BarrierGates(const std::vector<BarrierGateSP>& vec)
    : BaseConnections(vec) {}
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::BarrierGates)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::BaseConnections,
    falcon_core::physics::device_structures::BarrierGates)
