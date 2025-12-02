#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/core/Config_c_api.h"
typedef void* LoaderHandle;

// Constructors
LoaderHandle Loader_create(StringHandle config_path);

// Destructor
void Loader_destroy(LoaderHandle handle);

// Methods
ConfigHandle Loader_config(LoaderHandle handle);

#ifdef __cplusplus
}
#endif
