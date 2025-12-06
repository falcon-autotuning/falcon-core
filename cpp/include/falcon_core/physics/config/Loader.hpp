#pragma once
#include <boost/filesystem.hpp>

#include "falcon_core/physics/config/ConfigManipulations.hpp"
namespace falcon_core {
namespace physics {
namespace config {
class Loader : public ConfigManipulations {
  boost::filesystem::path         _config_path;
  core::ConfigSP                  _config;
  mutable std::shared_timed_mutex _mu_config;
  mutable std::shared_timed_mutex _mu_config_path;

 public:
  Loader(const Loader& other);
  Loader& operator=(const Loader& other);
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
using LoaderSP = std::shared_ptr<Loader>;
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
