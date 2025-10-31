#include "falcon_core/physics/config/Loader_c_api.h"

#include <falcon_core/physics/config/Loader.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::physics::config;

extern "C" {

LoaderHandle Loader_create(StringHandle config_path) {
  std::string path_str(config_path->raw, config_path->length);
  return new Loader(path_str);
}

void Loader_destroy(LoaderHandle handle) {
  Loader self = *static_cast<Loader*>(handle);
  delete static_cast<Loader*>(handle);
}

ConfigHandle Loader_config(LoaderHandle handle) {
  Loader self = *static_cast<Loader*>(handle);
  return new falcon_core::physics::config::core::Config(*(self.config()));
}

#ifdef __cplusplus
}
#endif
