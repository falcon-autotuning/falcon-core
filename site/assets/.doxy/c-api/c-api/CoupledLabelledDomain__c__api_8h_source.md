

# File CoupledLabelledDomain\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**domains**](dir_f5c6b653fd63ad902756e04c4af35f80.md) **>** [**CoupledLabelledDomain\_c\_api.h**](CoupledLabelledDomain__c__api_8h.md)

[Go to the documentation of this file](CoupledLabelledDomain__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListLabelledDomain_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/Ports_c_api.h"
#include "falcon_core/math/domains/LabelledDomain_c_api.h"
typedef void* CoupledLabelledDomainHandle;

// @category:allocation
CoupledLabelledDomainHandle CoupledLabelledDomain_copy(
    CoupledLabelledDomainHandle handle);
// @category:deallocation
void CoupledLabelledDomain_destroy(CoupledLabelledDomainHandle handle);
// @category:read
bool CoupledLabelledDomain_equal(CoupledLabelledDomainHandle handle,
                                 CoupledLabelledDomainHandle other);
// @category:read
bool CoupledLabelledDomain_not_equal(CoupledLabelledDomainHandle handle,
                                     CoupledLabelledDomainHandle other);
// @category:read
StringHandle CoupledLabelledDomain_to_json_string(
    CoupledLabelledDomainHandle handle);
// @category:allocation
CoupledLabelledDomainHandle CoupledLabelledDomain_from_json_string(
    StringHandle json);
// @category:allocation
CoupledLabelledDomainHandle CoupledLabelledDomain_create_empty();
// @category:allocation
CoupledLabelledDomainHandle CoupledLabelledDomain_create(
    ListLabelledDomainHandle items);
// @category:read
/* AUTO-DOC from cpp: CoupledLabelledDomain_domains |
 * falcon_core::math::domains::CoupledLabelledDomain::domains */
ListLabelledDomainHandle CoupledLabelledDomain_domains(
    CoupledLabelledDomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: CoupledLabelledDomain_labels |
 * falcon_core::math::domains::CoupledLabelledDomain::labels */
PortsHandle CoupledLabelledDomain_labels(CoupledLabelledDomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: CoupledLabelledDomain_get_domain |
 * falcon_core::math::domains::CoupledLabelledDomain::get_domain */
LabelledDomainHandle CoupledLabelledDomain_get_domain(
    CoupledLabelledDomainHandle handle, InstrumentPortHandle search);
// @category:read
CoupledLabelledDomainHandle CoupledLabelledDomain_intersection(
    CoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle other);
// @category:write
void CoupledLabelledDomain_push_back(CoupledLabelledDomainHandle handle,
                                     LabelledDomainHandle        value);
// @category:read
size_t CoupledLabelledDomain_size(CoupledLabelledDomainHandle handle);
// @category:read
bool CoupledLabelledDomain_empty(CoupledLabelledDomainHandle handle);
// @category:write
void CoupledLabelledDomain_erase_at(CoupledLabelledDomainHandle handle,
                                    size_t                      idx);
// @category:write
void CoupledLabelledDomain_clear(CoupledLabelledDomainHandle handle);
// @category:read
LabelledDomainHandle CoupledLabelledDomain_const_at(
    CoupledLabelledDomainHandle handle, size_t idx);
// @category:read
LabelledDomainHandle CoupledLabelledDomain_at(
    CoupledLabelledDomainHandle handle, size_t idx);
// @category:read
ListLabelledDomainHandle CoupledLabelledDomain_items(
    CoupledLabelledDomainHandle handle);
// @category:read
bool CoupledLabelledDomain_contains(CoupledLabelledDomainHandle handle,
                                    LabelledDomainHandle        value);
// @category:read
size_t CoupledLabelledDomain_index(CoupledLabelledDomainHandle handle,
                                   LabelledDomainHandle        value);

#ifdef __cplusplus
}
#endif
```


