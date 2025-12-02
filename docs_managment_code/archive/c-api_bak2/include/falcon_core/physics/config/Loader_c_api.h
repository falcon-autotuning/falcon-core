#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/core/Config_c_api.h"
typedef void* LoaderHandle;

// @category:allocation
LoaderHandle Loader_create(StringHandle config_path);
// @category:deallocation
void Loader_destroy(LoaderHandle handle);
// @category:read
/* AUTO-DOC from cpp: Loader_config | falcon_core::physics::config::Loader::config */
/**
 * @brief Returns the config.
 */
ConfigHandle Loader_config(LoaderHandle handle);

#ifdef __cplusplus
}
#endif
