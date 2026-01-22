

# File Loader.hpp

[**File List**](files.md) **>** [**config**](dir_69d97931c0a02cb6e53f9a12d673b99f.md) **>** [**Loader.hpp**](Loader_8hpp.md)

[Go to the documentation of this file](Loader_8hpp.md)


```C++
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
  Loader(const boost::filesystem::path& config_path);
  Loader(const std::string config_path);
  core::ConfigSP _load_config();
  core::ConfigSP config() const;
};
using LoaderSP = std::shared_ptr<Loader>;
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
```


