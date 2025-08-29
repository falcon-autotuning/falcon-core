#include "falcon_core/physics/device_structures/Ohmics.hpp"

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

Ohmics::Ohmics() = default;

Ohmics::Ohmics(size_t count) : BaseConnections(count) {}

Ohmics::Ohmics(size_t count, const BaseConnectionSP& value)
    : BaseConnections(count, value) {}

Ohmics::Ohmics(const std::vector<OhmicSP>& vec) : BaseConnections(vec) {}
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Ohmics)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::BaseConnections,
    falcon_core::physics::device_structures::Ohmics)
