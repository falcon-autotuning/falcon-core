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

// Forward declarations for opaque handles
typedef void* UnitSpaceHandle;
// Function declarations

// Constructors
UnitSpaceHandle UnitSpace_create(AxesDiscretizerHandle axes,
                                 DomainHandle          domain);
UnitSpaceHandle UnitSpace_create_rayspace(double       dr,
                                          double       dtheta,
                                          DomainHandle domain);
UnitSpaceHandle UnitSpace_create_cartesianspace(AxesDoubleHandle deltas,
                                                DomainHandle     domain);
UnitSpaceHandle UnitSpace_create_cartesian1Dspace(double       delta,
                                                  DomainHandle domain);
UnitSpaceHandle UnitSpace_create_cartesian2Dspace(AxesDoubleHandle deltas,
                                                  DomainHandle     domain);

// Destuctor
void UnitSpace_destroy(UnitSpaceHandle handle);

// Methods
AxesDiscretizerHandle  UnitSpace_axes(UnitSpaceHandle handle);
DomainHandle           UnitSpace_domain(UnitSpaceHandle handle);
FArrayDoubleHandle     UnitSpace_space(UnitSpaceHandle handle);
ListIntHandle          UnitSpace_shape(UnitSpaceHandle handle);
size_t                 UnitSpace_dimension(UnitSpaceHandle handle);
void                   UnitSpace_compile(UnitSpaceHandle handle);
AxesControlArrayHandle UnitSpace_create_array(UnitSpaceHandle handle,
                                              AxesIntHandle   axes);
void   UnitSpace_push_back(UnitSpaceHandle handle, DiscretizerHandle value);
size_t UnitSpace_size(UnitSpaceHandle handle);
bool   UnitSpace_empty(UnitSpaceHandle handle);
void   UnitSpace_erase_at(UnitSpaceHandle handle, size_t idx);
void   UnitSpace_clear(UnitSpaceHandle handle);
DiscretizerHandle UnitSpace_at(UnitSpaceHandle handle, size_t idx);
size_t            UnitSpace_items(UnitSpaceHandle    handle,
                                  DiscretizerHandle* out_buffer,
                                  size_t             buffer_size);
bool   UnitSpace_contains(UnitSpaceHandle handle, DiscretizerHandle value);
size_t UnitSpace_index(UnitSpaceHandle handle, DiscretizerHandle value);
UnitSpaceHandle UnitSpace_intersection(UnitSpaceHandle handle,
                                       UnitSpaceHandle other);
bool            UnitSpace_equal(UnitSpaceHandle a, UnitSpaceHandle b);
bool            UnitSpace_not_equal(UnitSpaceHandle a, UnitSpaceHandle b);

// Serialization (from Song)
StringHandle    UnitSpace_to_json_string(UnitSpaceHandle handle);
UnitSpaceHandle UnitSpace_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
