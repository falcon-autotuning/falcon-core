

# File AxesCoupledLabelledDomain\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesCoupledLabelledDomain\_c\_api.h**](AxesCoupledLabelledDomain__c__api_8h.md)

[Go to the documentation of this file](AxesCoupledLabelledDomain__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/domains/CoupledLabelledDomain_c_api.h"
#include "falcon_core/generic/ListCoupledLabelledDomain_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesCoupledLabelledDomainHandle;
// Function declarations

// @category:allocation
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create_empty();
// @category:allocation
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_copy(AxesCoupledLabelledDomainHandle handle);
// @category:allocation
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create(ListCoupledLabelledDomainHandle data);
// @category:deallocation
void AxesCoupledLabelledDomain_destroy(AxesCoupledLabelledDomainHandle handle);
// @category:write
void AxesCoupledLabelledDomain_push_back(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value);
// @category:read
size_t AxesCoupledLabelledDomain_size(AxesCoupledLabelledDomainHandle handle);
// @category:read
bool AxesCoupledLabelledDomain_empty(AxesCoupledLabelledDomainHandle handle);
// @category:write
void AxesCoupledLabelledDomain_erase_at(AxesCoupledLabelledDomainHandle handle, size_t idx);
// @category:write
void AxesCoupledLabelledDomain_clear(AxesCoupledLabelledDomainHandle handle);
// @category:read
CoupledLabelledDomainHandle AxesCoupledLabelledDomain_at(AxesCoupledLabelledDomainHandle handle, size_t idx);
// @category:read
size_t AxesCoupledLabelledDomain_items(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle* out_buffer, size_t buffer_size);
// @category:read
bool AxesCoupledLabelledDomain_contains(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value);
// @category:read
size_t AxesCoupledLabelledDomain_index(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value);
// @category:read
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_intersection(AxesCoupledLabelledDomainHandle handle, AxesCoupledLabelledDomainHandle other);
// @category:read
bool AxesCoupledLabelledDomain_equal(AxesCoupledLabelledDomainHandle handle, AxesCoupledLabelledDomainHandle other);
// @category:read
bool AxesCoupledLabelledDomain_not_equal(AxesCoupledLabelledDomainHandle handle, AxesCoupledLabelledDomainHandle other);

// @category:read
StringHandle      AxesCoupledLabelledDomain_to_json_string(AxesCoupledLabelledDomainHandle handle);
// @category:allocation
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


