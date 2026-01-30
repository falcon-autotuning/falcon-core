#include "falcon_core/physics/config/geometries/HasImplantedOhmic.hpp"

#include <stdexcept>

#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
HasImplantedOhmic::HasImplantedOhmic(const HasImplantedOhmic& other) {
  std::unique_lock<std::shared_timed_mutex> lock_ohmic(_mu_ohmic);
  if (!other.ohmic()) {
    throw std::invalid_argument(
        "HasImplantedOhmic: The other ohmic cannot be null.");
  }
  _ohmic = std::make_shared<device_structures::Connection>(*other.ohmic());
}
HasImplantedOhmic& HasImplantedOhmic::operator=(
    const HasImplantedOhmic& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_ohmic(_mu_ohmic);
    if (!other.ohmic()) {
      throw std::invalid_argument(
          "HasImplantedOhmic: The other ohmic cannot be null.");
    }
    _ohmic = std::make_shared<device_structures::Connection>(*other.ohmic());
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
