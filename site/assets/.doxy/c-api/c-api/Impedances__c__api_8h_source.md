

# File Impedances\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**device\_structures**](dir_8f58be43a4a4299c8fba030674c04b93.md) **>** [**Impedances\_c\_api.h**](Impedances__c__api_8h.md)

[Go to the documentation of this file](Impedances__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListImpedance_c_api.h"
typedef void* ImpedancesHandle;

// @category:allocation
ImpedancesHandle Impedances_copy(ImpedancesHandle handle);
// @category:deallocation
void Impedances_destroy(ImpedancesHandle handle);
// @category:read
bool Impedances_equal(ImpedancesHandle handle, ImpedancesHandle other);
// @category:read
bool Impedances_not_equal(ImpedancesHandle handle, ImpedancesHandle other);
// @category:read
StringHandle Impedances_to_json_string(ImpedancesHandle handle);
// @category:allocation
ImpedancesHandle Impedances_from_json_string(StringHandle json);
// @category:allocation
ImpedancesHandle Impedances_create_empty();
// @category:allocation
ImpedancesHandle Impedances_create(ListImpedanceHandle items);
// @category:write
void Impedances_push_back(ImpedancesHandle handle, ImpedanceHandle value);
// @category:read
size_t Impedances_size(ImpedancesHandle handle);
// @category:read
bool Impedances_empty(ImpedancesHandle handle);
// @category:write
void Impedances_erase_at(ImpedancesHandle handle, size_t idx);
// @category:write
void Impedances_clear(ImpedancesHandle handle);
// @category:read
ImpedanceHandle Impedances_at(ImpedancesHandle handle, size_t idx);
// @category:read
ListImpedanceHandle Impedances_items(ImpedancesHandle handle);
// @category:read
bool Impedances_contains(ImpedancesHandle handle, ImpedanceHandle value);
// @category:read
ImpedancesHandle Impedances_intersection(ImpedancesHandle handle,
                                         ImpedancesHandle other);
// @category:read
size_t Impedances_index(ImpedancesHandle handle, ImpedanceHandle value);

#ifdef __cplusplus
}
#endif
```


