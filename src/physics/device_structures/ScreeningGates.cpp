#include "falcon_core/physics/device_structures/ScreeningGates.hpp"

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

ScreeningGates::ScreeningGates() = default;

ScreeningGates::ScreeningGates(size_t count) : BaseConnections(count) {}

ScreeningGates::ScreeningGates(size_t count, const BaseConnectionSP& value)
    : BaseConnections(count, value) {}

ScreeningGates::ScreeningGates(const std::vector<ScreeningGateSP>& vec)
    : BaseConnections(vec) {}
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::ScreeningGates)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::BaseConnections,
    falcon_core::physics::device_structures::ScreeningGates)
