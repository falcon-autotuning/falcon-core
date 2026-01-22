

# File DestroyMacro\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**DestroyMacro\_c\_api.h**](DestroyMacro__c__api_8h.md)

[Go to the documentation of this file](DestroyMacro__c__api_8h.md)


```C++
#pragma once

#define DEFINE_C_API_DESTROY_TEMPLATE(CType, CPPType)                        \
  void CType##_destroy(CType##Handle handle) {                               \
    FALCON_C_API_BEGIN                                                       \
    if (!handle) {                                                           \
      throw std::invalid_argument(#CType "_destroy: handle cannot be null"); \
    }                                                                        \
    delete static_cast<std::shared_ptr<CPPType>*>(handle);                   \
    FALCON_C_API_END()                                                       \
  }

#define DEFINE_C_API_DESTROY(Type) DEFINE_C_API_DESTROY_TEMPLATE(Type, Type)
```


