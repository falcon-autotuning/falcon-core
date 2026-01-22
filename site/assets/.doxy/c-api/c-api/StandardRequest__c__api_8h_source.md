

# File StandardRequest\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**communications**](dir_333323e88b5d6263154607a1eb6b024f.md) **>** [**messages**](dir_b9b9af6e426ae6e63b9b7113e9a16e28.md) **>** [**StandardRequest\_c\_api.h**](StandardRequest__c__api_8h.md)

[Go to the documentation of this file](StandardRequest__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* StandardRequestHandle;

// @category:allocation
StandardRequestHandle StandardRequest_copy(StandardRequestHandle handle);
// @category:deallocation
void StandardRequest_destroy(StandardRequestHandle handle);
// @category:read
bool StandardRequest_equal(StandardRequestHandle handle,
                           StandardRequestHandle other);
// @category:read
bool StandardRequest_not_equal(StandardRequestHandle handle,
                               StandardRequestHandle other);
// @category:read
StringHandle StandardRequest_to_json_string(StandardRequestHandle handle);
// @category:allocation
StandardRequestHandle StandardRequest_from_json_string(StringHandle json);
// @category:allocation
StandardRequestHandle StandardRequest_create(StringHandle message);
// @category:read
StringHandle StandardRequest_message(StandardRequestHandle handle);

#ifdef __cplusplus
}
#endif
```


