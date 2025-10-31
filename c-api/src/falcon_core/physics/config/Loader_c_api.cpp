#include "falcon_core/physics/config/Loader_c_api.h"

#include <falcon_core/physics/config/Loader.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::physics::config;

extern "C" {

LoaderHandle Loader_create(StringHandle config_path) {
  if (!config_path) {
    throw std::invalid_argument("Loader_create: config_path cannot be null");
  }
  std::string path_str(config_path->raw, config_path->length);
  return new Loader(path_str);
}

void Loader_destroy(LoaderHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Loader_destroy: handle cannot be null");
  }
  Loader self = *static_cast<Loader*>(handle);
  delete static_cast<Loader*>(handle);
}

ConfigHandle Loader_config(LoaderHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Loader_config: handle cannot be null");
  }
  Loader self = *static_cast<Loader*>(handle);
  return new falcon_core::physics::config::core::Config(*(self.config()));
}

#ifdef __cplusplus
}
#endif
