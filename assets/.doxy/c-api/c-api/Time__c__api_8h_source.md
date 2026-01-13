

# File Time\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**communications**](dir_333323e88b5d6263154607a1eb6b024f.md) **>** [**Time\_c\_api.h**](Time__c__api_8h.md)

[Go to the documentation of this file](Time__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* TimeHandle;

// @category:allocation
TimeHandle Time_copy(TimeHandle handle);
// @category:deallocation
void Time_destroy(TimeHandle handle);
// @category:read
bool Time_equal(TimeHandle handle, TimeHandle other);
// @category:read
bool Time_not_equal(TimeHandle handle, TimeHandle other);
// @category:read
StringHandle Time_to_json_string(TimeHandle handle);
// @category:allocation
TimeHandle Time_from_json_string(StringHandle json);
// @category:allocation
TimeHandle Time_create_now();
// @category:allocation
TimeHandle Time_create_at(long long micro_seconds_since_epoch);
// @category:read
/* AUTO-DOC from cpp: Time_micro_seconds_since_epoch |
 * falcon_core::communications::Time::micro_seconds_since_epoch */
long long Time_micro_seconds_since_epoch(TimeHandle handle);
// @category:read
/* AUTO-DOC from cpp: Time_time | falcon_core::communications::Time::time */
long long Time_time(TimeHandle handle);
// @category:read
/* AUTO-DOC from cpp: Time_to_string |
 * falcon_core::communications::Time::to_string */
StringHandle Time_to_string(TimeHandle handle);

#ifdef __cplusplus
}
#endif
```


