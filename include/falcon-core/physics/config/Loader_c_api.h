#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/physics/config/core/Config_c_api.h"
typedef void* LoaderHandle;

// @category:allocation
FALCON_CORE_C_API LoaderHandle Loader_create(StringHandle config_path);
// @category:deallocation
FALCON_CORE_C_API void Loader_destroy(LoaderHandle handle);
// @category:read
/* AUTO-DOC from cpp: Loader_config |
 * falcon_core::physics::config::Loader::config */
/**
 * @brief Returns the config.
 */
FALCON_CORE_C_API ConfigHandle Loader_config(LoaderHandle handle);

#ifdef __cplusplus
}
#endif
