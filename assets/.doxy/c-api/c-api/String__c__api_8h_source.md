

# File String\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**String\_c\_api.h**](String__c__api_8h.md)

[Go to the documentation of this file](String__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>
struct string {
  char*  raw;
  size_t length;
};

typedef struct string* StringHandle;
// @category:allocation
StringHandle String_create(const char* raw, size_t length);
// @category:allocation
StringHandle String_wrap(const char* raw);
// @category:deallocation
void String_destroy(StringHandle handle);
#ifdef __cplusplus
}
#endif
```


