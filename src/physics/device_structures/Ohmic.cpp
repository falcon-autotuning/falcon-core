#include "falcon_core/physics/device_structures/Ohmic.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
Ohmic::Ohmic() = default;
Ohmic::Ohmic(std::string name) : BaseConnection(name, DeviceFeature::Ohmic) {}
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
