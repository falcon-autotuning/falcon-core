#include "falcon_core/physics/device_structures/ReservoirGates.hpp"

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

ReservoirGates::ReservoirGates() = default;

ReservoirGates::ReservoirGates(size_t count) : BaseConnections(count) {}

ReservoirGates::ReservoirGates(size_t count, const BaseConnectionSP& value)
    : BaseConnections(count, value) {}

ReservoirGates::ReservoirGates(const std::vector<ReservoirGateSP>& vec)
    : BaseConnections(vec) {}
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::ReservoirGates)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::BaseConnections,
    falcon_core::physics::device_structures::ReservoirGates)
