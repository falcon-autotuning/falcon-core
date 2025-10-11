#include "falcon_core/physics/config/Loader.hpp"

namespace falcon_core {
namespace physics {
namespace config {
Loader::Loader(const boost::filesystem::path& config_path)
    : _config_path(config_path) {
  _load_config();
}
Loader::Loader(const std::string config_path)
    : Loader(boost::filesystem::path(config_path)) {}
core::ConfigSP Loader::_load_config() {
  YAML::Node config = YAML::LoadFile(_config_path.string());
  _config           = unpack_device_config(config);
  return _config;
}
core::ConfigSP Loader::config() const { return _config; }
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
