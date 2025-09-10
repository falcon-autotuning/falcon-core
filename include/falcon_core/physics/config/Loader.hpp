#pragma once
#include <boost/filesystem.hpp>

#include "falcon_core/physics/config/ConfigManipulations.hpp"
namespace falcon_core::physics::config {
class Loader : public ConfigManipulations {
  boost::filesystem::path _config_path;
  core::ConfigSP          _config;

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
  /**
   * @brief Loads the config file into nodes.
   */
  core::ConfigSP _load_config();
  /**
   * @brief Returns the config.
   */
  core::ConfigSP config() const;
};
}  // namespace falcon_core::physics::config
