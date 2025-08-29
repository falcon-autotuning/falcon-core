#include "falcon_core/physics/device_structures/Ohmic.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
Ohmic::Ohmic() = default;
Ohmic::Ohmic(std::string name) : BaseConnection(name, DeviceFeature::Ohmic) {}
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Ohmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::physics::device_structures::Ohmic)
