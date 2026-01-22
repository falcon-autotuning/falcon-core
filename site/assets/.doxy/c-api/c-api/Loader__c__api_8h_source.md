

# File Loader\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**Loader\_c\_api.h**](Loader__c__api_8h.md)

[Go to the documentation of this file](Loader__c__api_8h.md)


```C++
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
/* AUTO-DOC from cpp: Loader_config |
 * falcon_core::physics::config::Loader::config */
ConfigHandle Loader_config(LoaderHandle handle);

#ifdef __cplusplus
}
#endif
```


