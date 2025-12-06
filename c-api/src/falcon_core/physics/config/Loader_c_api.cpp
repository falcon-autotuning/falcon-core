#include "falcon_core/physics/config/Loader_c_api.h"

#include <falcon_core/physics/config/Loader.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::physics::config;

extern "C" {
LoaderHandle Loader_create(StringHandle config_path) {
  FALCON_C_API_BEGIN
  if (!config_path) {
    throw std::invalid_argument("Loader_create: config_path cannot be null");
  }
  std::string path_str(config_path->raw, config_path->length);
  return new LoaderSP(std::make_shared<Loader>(path_str));
  FALCON_C_API_END(nullptr)
}

void Loader_destroy(LoaderHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Loader_destroy: handle cannot be null");
  }
  delete static_cast<LoaderSP*>(handle);
  FALCON_C_API_END()
}

ConfigHandle Loader_config(LoaderHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Loader_config: handle cannot be null");
  }
  LoaderSP self = *static_cast<LoaderSP*>(handle);
  return new falcon_core::physics::config::core::ConfigSP(self->config());
  FALCON_C_API_END(nullptr)
}
}
