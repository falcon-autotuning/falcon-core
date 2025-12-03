#include "falcon_core/physics/config/geometries/HasImplantedOhmic.hpp"

#include <stdexcept>

#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
HasImplantedOhmic::HasImplantedOhmic(const HasImplantedOhmic& other) {
  std::shared_lock<std::shared_timed_mutex> lock_other_ohmic(other._mu_ohmic,
                                                             std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_ohmic(_mu_ohmic,
                                                       std::defer_lock);
  std::lock(lock_ohmic, lock_other_ohmic);
  _ohmic = other._ohmic;
}
HasImplantedOhmic HasImplantedOhmic::operator=(const HasImplantedOhmic& other) {
  if (this != &other) {
    std::shared_lock<std::shared_timed_mutex> lock_other_ohmic(other._mu_ohmic,
                                                               std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_ohmic(_mu_ohmic,
                                                         std::defer_lock);
    std::lock(lock_ohmic, lock_other_ohmic);
    _ohmic = other._ohmic;
  }
  return *this;
}
HasImplantedOhmic::HasImplantedOhmic() = default;
HasImplantedOhmic::HasImplantedOhmic(device_structures::ConnectionSP ohmic)
    : _ohmic(ohmic) {
  if (!ohmic) {
    throw std::invalid_argument(
        "HasImplantedOhmic: The ohmic needs to not be null.");
  }
  if (!ohmic->is_ohmic()) {
    throw std::runtime_error(
        "HasImplantedOhmic: This needs to be an ohmic, not a " + ohmic->type());
  }
}
device_structures::ConnectionSP HasImplantedOhmic::ohmic() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_ohmic);
  return _ohmic;
}
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::HasImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::HasImplantedOhmic)
