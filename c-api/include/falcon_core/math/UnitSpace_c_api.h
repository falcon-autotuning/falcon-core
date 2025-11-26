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
UnitSpaceHandle UnitSpace_create(AxesDiscretizerHandle axes,
                                 DomainHandle          domain);
// @category:allocation
UnitSpaceHandle UnitSpace_create_rayspace(double       dr,
                                          double       dtheta,
                                          DomainHandle domain);
// @category:allocation
UnitSpaceHandle UnitSpace_create_cartesianspace(AxesDoubleHandle deltas,
                                                DomainHandle     domain);
// @category:allocation
UnitSpaceHandle UnitSpace_create_cartesian1Dspace(double       delta,
                                                  DomainHandle domain);
// @category:allocation
UnitSpaceHandle UnitSpace_create_cartesian2Dspace(AxesDoubleHandle deltas,
                                                  DomainHandle     domain);
// @category:deallocation
void UnitSpace_destroy(UnitSpaceHandle handle);
// @category:read
AxesDiscretizerHandle UnitSpace_axes(UnitSpaceHandle handle);
// @category:read
DomainHandle UnitSpace_domain(UnitSpaceHandle handle);
// @category:read
FArrayDoubleHandle UnitSpace_space(UnitSpaceHandle handle);
// @category:read
ListIntHandle UnitSpace_shape(UnitSpaceHandle handle);
// @category:read
size_t UnitSpace_dimension(UnitSpaceHandle handle);
// @category:write
void UnitSpace_compile(UnitSpaceHandle handle);
// @category:read
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
// @category:read
bool UnitSpace_equal(UnitSpaceHandle a, UnitSpaceHandle b);
// @category:read
bool UnitSpace_not_equal(UnitSpaceHandle a, UnitSpaceHandle b);
// @category:read
StringHandle UnitSpace_to_json_string(UnitSpaceHandle handle);
// @category:allocation
UnitSpaceHandle UnitSpace_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
