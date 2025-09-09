#pragma once
#include <boost/filesystem.hpp>

#include "falcon_core/physics/config/ConfigManipulations.hpp"
#include "falcon_core/physics/config/core/Config.hpp"
namespace falcon_core {
namespace physics {
namespace config {
class Loader : public ConfigManipulations {
  boost::filesystem::path _config_path;
  core::Config            _config;

 public:
  /**
   * @brief Constructor for config loading utility.
   * @param config_path Path to the configuration file.
   */
  Loader(const boost::filesystem::path& config_path);
  /**
   * @brief Constructor for config loading utility.
   * @param config_path Complete Path to the configuration file.
   */
  Loader(const std::string config_path);
  generic::MapSP<std::string, auto> load_config() const;
};
}  // namespace config

}  // namespace physics
}  // namespace falcon_core
