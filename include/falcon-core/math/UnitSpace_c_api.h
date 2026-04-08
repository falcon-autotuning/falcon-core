#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon-core/generic/FArrayDouble_c_api.h"
#include "falcon-core/generic/ListInt_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/math/AxesControlArray_c_api.h"
#include "falcon-core/math/AxesDiscretizer_c_api.h"
#include "falcon-core/math/AxesDouble_c_api.h"
#include "falcon-core/math/AxesInt_c_api.h"
#include "falcon-core/math/discrete_spaces/Discretizer_c_api.h"

typedef void* UnitSpaceHandle;

// @category:allocation
FALCON_CORE_C_API UnitSpaceHandle UnitSpace_copy(UnitSpaceHandle handle);
// @category:deallocation
FALCON_CORE_C_API void UnitSpace_destroy(UnitSpaceHandle handle);
// @category:read
FALCON_CORE_C_API bool UnitSpace_equal(UnitSpaceHandle handle,
                                       UnitSpaceHandle other);
// @category:read
FALCON_CORE_C_API bool UnitSpace_not_equal(UnitSpaceHandle handle,
                                           UnitSpaceHandle other);
// @category:read
FALCON_CORE_C_API StringHandle UnitSpace_to_json_string(UnitSpaceHandle handle);
// @category:allocation
FALCON_CORE_C_API UnitSpaceHandle UnitSpace_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API UnitSpaceHandle UnitSpace_create(AxesDiscretizerHandle axes,
                                                   DomainHandle domain);
// @category:allocation
FALCON_CORE_C_API UnitSpaceHandle
UnitSpace_create_ray_space(double dr, double dtheta, DomainHandle domain);
// @category:allocation
FALCON_CORE_C_API UnitSpaceHandle
UnitSpace_create_cartesian_space(AxesDoubleHandle deltas, DomainHandle domain);
// @category:allocation
FALCON_CORE_C_API UnitSpaceHandle
UnitSpace_create_cartesian_1D_space(double delta, DomainHandle domain);
// @category:allocation
FALCON_CORE_C_API UnitSpaceHandle UnitSpace_create_cartesian_2D_space(
    AxesDoubleHandle deltas, DomainHandle domain);
// @category:read
/* AUTO-DOC from cpp: UnitSpace_axes | falcon_core::math::UnitSpace::axes */
/**
 * @brief Return the axes of the space.
 */
FALCON_CORE_C_API AxesDiscretizerHandle UnitSpace_axes(UnitSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: UnitSpace_domain | falcon_core::math::UnitSpace::domain */
/**
 * @brief Return the domain of the space
 */
FALCON_CORE_C_API DomainHandle UnitSpace_domain(UnitSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: UnitSpace_space | falcon_core::math::UnitSpace::space */
/**
 * @brief Return the stored space.
 */
FALCON_CORE_C_API FArrayDoubleHandle UnitSpace_space(UnitSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: UnitSpace_shape | falcon_core::math::UnitSpace::shape */
/**
 * @brief Return the shape of the unit space.
 */
FALCON_CORE_C_API ListIntHandle UnitSpace_shape(UnitSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: UnitSpace_dimension |
 * falcon_core::math::UnitSpace::dimension */
/**
 * @brief Return the number of dimensions in the space.
 */
FALCON_CORE_C_API size_t UnitSpace_dimension(UnitSpaceHandle handle);
// @category:write
/* AUTO-DOC from cpp: UnitSpace_compile | falcon_core::math::UnitSpace::compile
 */
/**
 * @brief Compile the unit space into a space.
 */
FALCON_CORE_C_API void UnitSpace_compile(UnitSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: UnitSpace_create_array |
 * falcon_core::math::UnitSpace::create_array */
/**
 * @brief Return the projection of the space onto the given axes.
 * The projection contains the indexes of the axes to project onto.
 * @param axes The axes to project onto.
 * @return A set of proper Control Arrays
 */
FALCON_CORE_C_API AxesControlArrayHandle
UnitSpace_create_array(UnitSpaceHandle handle, AxesIntHandle axes);
// @category:write
FALCON_CORE_C_API void UnitSpace_push_back(UnitSpaceHandle   handle,
                                           DiscretizerHandle value);
// @category:read
FALCON_CORE_C_API size_t UnitSpace_size(UnitSpaceHandle handle);
// @category:read
FALCON_CORE_C_API bool UnitSpace_empty(UnitSpaceHandle handle);
// @category:write
FALCON_CORE_C_API void UnitSpace_erase_at(UnitSpaceHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void UnitSpace_clear(UnitSpaceHandle handle);
// @category:read
FALCON_CORE_C_API DiscretizerHandle UnitSpace_at(UnitSpaceHandle handle,
                                                 size_t          idx);
// @category:read
FALCON_CORE_C_API size_t UnitSpace_items(UnitSpaceHandle    handle,
                                         DiscretizerHandle* out_buffer,
                                         size_t             buffer_size);
// @category:read
FALCON_CORE_C_API bool UnitSpace_contains(UnitSpaceHandle   handle,
                                          DiscretizerHandle value);
// @category:read
FALCON_CORE_C_API size_t UnitSpace_index(UnitSpaceHandle   handle,
                                         DiscretizerHandle value);
// @category:read
FALCON_CORE_C_API UnitSpaceHandle UnitSpace_intersection(UnitSpaceHandle handle,
                                                         UnitSpaceHandle other);

#ifdef __cplusplus
}
#endif
