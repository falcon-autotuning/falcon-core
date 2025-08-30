#include "falcon_core/physics/device_structures/PlungerGates.hpp"

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

PlungerGates::PlungerGates() = default;

PlungerGates::PlungerGates(size_t count) : BaseConnections(count) {}

PlungerGates::PlungerGates(size_t count, const BaseConnectionSP& value)
    : BaseConnections(count, value) {}

PlungerGates::PlungerGates(const std::vector<PlungerGateSP>& vec)
    : BaseConnections(vec) {}
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::PlungerGates)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::BaseConnections,
    falcon_core::physics::device_structures::PlungerGates)
