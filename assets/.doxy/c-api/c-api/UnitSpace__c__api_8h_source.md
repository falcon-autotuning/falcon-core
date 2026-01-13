

# File UnitSpace\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**UnitSpace\_c\_api.h**](UnitSpace__c__api_8h.md)

[Go to the documentation of this file](UnitSpace__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListInt_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesControlArray_c_api.h"
#include "falcon_core/math/AxesDiscretizer_c_api.h"
#include "falcon_core/math/AxesDouble_c_api.h"
#include "falcon_core/math/AxesInt_c_api.h"
#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"

typedef void* UnitSpaceHandle;

// @category:allocation
UnitSpaceHandle UnitSpace_copy(UnitSpaceHandle handle);
// @category:deallocation
void UnitSpace_destroy(UnitSpaceHandle handle);
// @category:read
bool UnitSpace_equal(UnitSpaceHandle handle, UnitSpaceHandle other);
// @category:read
bool UnitSpace_not_equal(UnitSpaceHandle handle, UnitSpaceHandle other);
// @category:read
StringHandle UnitSpace_to_json_string(UnitSpaceHandle handle);
// @category:allocation
UnitSpaceHandle UnitSpace_from_json_string(StringHandle json);
// @category:allocation
UnitSpaceHandle UnitSpace_create(AxesDiscretizerHandle axes,
                                 DomainHandle          domain);
// @category:allocation
UnitSpaceHandle UnitSpace_create_ray_space(double       dr,
                                           double       dtheta,
                                           DomainHandle domain);
// @category:allocation
UnitSpaceHandle UnitSpace_create_cartesian_space(AxesDoubleHandle deltas,
                                                 DomainHandle     domain);
// @category:allocation
UnitSpaceHandle UnitSpace_create_cartesian_1D_space(double       delta,
                                                    DomainHandle domain);
// @category:allocation
UnitSpaceHandle UnitSpace_create_cartesian_2D_space(AxesDoubleHandle deltas,
                                                    DomainHandle     domain);
// @category:read
/* AUTO-DOC from cpp: UnitSpace_axes | falcon_core::math::UnitSpace::axes */
AxesDiscretizerHandle UnitSpace_axes(UnitSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: UnitSpace_domain | falcon_core::math::UnitSpace::domain */
DomainHandle UnitSpace_domain(UnitSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: UnitSpace_space | falcon_core::math::UnitSpace::space */
FArrayDoubleHandle UnitSpace_space(UnitSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: UnitSpace_shape | falcon_core::math::UnitSpace::shape */
ListIntHandle UnitSpace_shape(UnitSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: UnitSpace_dimension |
 * falcon_core::math::UnitSpace::dimension */
size_t UnitSpace_dimension(UnitSpaceHandle handle);
// @category:write
/* AUTO-DOC from cpp: UnitSpace_compile | falcon_core::math::UnitSpace::compile
 */
void UnitSpace_compile(UnitSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: UnitSpace_create_array |
 * falcon_core::math::UnitSpace::create_array */
AxesControlArrayHandle UnitSpace_create_array(UnitSpaceHandle handle,
                                              AxesIntHandle   axes);
// @category:write
void UnitSpace_push_back(UnitSpaceHandle handle, DiscretizerHandle value);
// @category:read
size_t UnitSpace_size(UnitSpaceHandle handle);
// @category:read
bool UnitSpace_empty(UnitSpaceHandle handle);
// @category:write
void UnitSpace_erase_at(UnitSpaceHandle handle, size_t idx);
// @category:write
void UnitSpace_clear(UnitSpaceHandle handle);
// @category:read
DiscretizerHandle UnitSpace_at(UnitSpaceHandle handle, size_t idx);
// @category:read
size_t UnitSpace_items(UnitSpaceHandle    handle,
                       DiscretizerHandle* out_buffer,
                       size_t             buffer_size);
// @category:read
bool UnitSpace_contains(UnitSpaceHandle handle, DiscretizerHandle value);
// @category:read
size_t UnitSpace_index(UnitSpaceHandle handle, DiscretizerHandle value);
// @category:read
UnitSpaceHandle UnitSpace_intersection(UnitSpaceHandle handle,
                                       UnitSpaceHandle other);

#ifdef __cplusplus
}
#endif
```


