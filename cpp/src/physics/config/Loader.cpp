#include "falcon_core/physics/config/Loader.hpp"

#include <mutex>

namespace falcon_core {
namespace physics {
namespace config {
Loader::Loader(const Loader& other) {
  std::unique_lock<std::shared_timed_mutex> lock_config_path(_mu_config_path,
                                                             std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_config(_mu_config,
                                                        std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_other_config_path(
      other._mu_config_path, std::defer_lock);
  std::lock(lock_config_path, lock_config, lock_other_config_path);
  _config_path = other._config_path;
  if (!other.config()) {
    throw std::invalid_argument("Loader: other.config() is null.");
  }
  _config = std::make_shared<core::Config>(*other.config());
}
Loader& Loader::operator=(const Loader& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_config_path(_mu_config_path,
                                                               std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_config(_mu_config,
                                                          std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_other_config_path(
        other._mu_config_path, std::defer_lock);
    std::lock(lock_config_path, lock_config, lock_other_config_path);
    _config_path = other._config_path;
    if (!other.config()) {
      throw std::invalid_argument("Loader: other.config() is null.");
    }
    _config = std::make_shared<core::Config>(*other.config());
  }
  return *this;
}
Loader::Loader(const boost::filesystem::path& config_path)
    : _config_path(config_path) {
  _load_config();
}
Loader::Loader(const std::string config_path)
    : Loader(boost::filesystem::path(config_path)) {}
core::ConfigSP Loader::_load_config() {
  std::unique_lock<std::shared_timed_mutex> lock(_mu_config_path);
  YAML::Node config = YAML::LoadFile(_config_path.string());
  _config           = unpack_device_config(config);
  return _config;
}
core::ConfigSP Loader::config() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_config);
  return _config;
}
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
