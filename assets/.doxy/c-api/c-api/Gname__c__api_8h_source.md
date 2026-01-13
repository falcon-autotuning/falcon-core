

# File Gname\_c\_api.h

[**File List**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**names**](dir_ad3a832d6f582aa08d8da369374ec299.md) **>** [**Gname\_c\_api.h**](Gname__c__api_8h.md)

[Go to the documentation of this file](Gname__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* GnameHandle;

// @category:allocation
GnameHandle Gname_copy(GnameHandle handle);
// @category:deallocation
void Gname_destroy(GnameHandle handle);
// @category:read
bool Gname_equal(GnameHandle handle, GnameHandle other);
// @category:read
bool Gname_not_equal(GnameHandle handle, GnameHandle other);
// @category:read
StringHandle Gname_to_json_string(GnameHandle handle);
// @category:allocation
GnameHandle Gname_from_json_string(StringHandle json);
// @category:allocation
GnameHandle Gname_create_from_num(int num);
// @category:allocation
GnameHandle Gname_create(StringHandle name);
// @category:read
/* AUTO-DOC from cpp: Gname_gname |
 * falcon_core::autotuner_interfaces::names::Gname::gname */
StringHandle Gname_gname(GnameHandle handle);

#ifdef __cplusplus
}
#endif
```


