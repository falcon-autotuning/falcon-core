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
/* AUTO-DOC from cpp: UnitSpace_axes | falcon_core::math::UnitSpace::axes */
/**
 * @brief Return the axes of the space.
 */
AxesDiscretizerHandle  UnitSpace_axes(UnitSpaceHandle handle);
/* AUTO-DOC from cpp: UnitSpace_domain | falcon_core::math::UnitSpace::domain */
/**
 * @brief Return the domain of the space
 */
DomainHandle           UnitSpace_domain(UnitSpaceHandle handle);
/* AUTO-DOC from cpp: UnitSpace_space | falcon_core::math::UnitSpace::space */
/**
 * @brief Return the stored space.
 */
FArrayDoubleHandle     UnitSpace_space(UnitSpaceHandle handle);
/* AUTO-DOC from cpp: UnitSpace_shape | falcon_core::math::UnitSpace::shape */
/**
 * @brief Return the shape of the unit space.
 */
ListIntHandle          UnitSpace_shape(UnitSpaceHandle handle);
/* AUTO-DOC from cpp: UnitSpace_dimension | falcon_core::math::UnitSpace::dimension */
/**
 * @brief Return the number of dimensions in the space.
 */
size_t                 UnitSpace_dimension(UnitSpaceHandle handle);
/* AUTO-DOC from cpp: UnitSpace_compile | falcon_core::math::UnitSpace::compile */
/**
 * @brief Compile the unit space into a space.
 */
void                   UnitSpace_compile(UnitSpaceHandle handle);
/* AUTO-DOC from cpp: UnitSpace_create_array | falcon_core::math::UnitSpace::create_array */
/**
 * @brief Return the projection of the space onto the given axes.
 * The projection contains the indexes of the axes to project onto.
 * @param axes The axes to project onto.
 * @return A set of proper Control Arrays
 */
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
