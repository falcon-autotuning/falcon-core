#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/math/domains/Domain_c_api.h"
typedef void* DiscretizerHandle;

// @category:allocation
FALCON_CORE_C_API DiscretizerHandle Discretizer_copy(DiscretizerHandle handle);
// @category:deallocation
FALCON_CORE_C_API void Discretizer_destroy(DiscretizerHandle handle);
// @category:read
FALCON_CORE_C_API bool Discretizer_equal(DiscretizerHandle handle,
                                         DiscretizerHandle other);
// @category:read
FALCON_CORE_C_API bool Discretizer_not_equal(DiscretizerHandle handle,
                                             DiscretizerHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
Discretizer_to_json_string(DiscretizerHandle handle);
// @category:allocation
FALCON_CORE_C_API DiscretizerHandle
Discretizer_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API DiscretizerHandle
Discretizer_create_cartesian_discretizer(double delta);
// @category:allocation
FALCON_CORE_C_API DiscretizerHandle
Discretizer_create_polar_discretizer(double delta);
// @category:read
FALCON_CORE_C_API double Discretizer_delta(DiscretizerHandle handle);
// @category:write
FALCON_CORE_C_API void Discretizer_set_delta(DiscretizerHandle handle,
                                             double            delta);
// @category:read
FALCON_CORE_C_API DomainHandle Discretizer_domain(DiscretizerHandle handle);
// @category:read
/* AUTO-DOC from cpp: Discretizer_is_cartesian |
 * falcon_core::math::discrete_spaces::Discretizer::is_cartesian */
/**
 * @brief Checks if the current Discretizer is Cartesian.
 */
FALCON_CORE_C_API bool Discretizer_is_cartesian(DiscretizerHandle handle);
// @category:read
/* AUTO-DOC from cpp: Discretizer_is_polar |
 * falcon_core::math::discrete_spaces::Discretizer::is_polar */
/**
 * @brief Checks if the current Discretizer is Polar.
 */
FALCON_CORE_C_API bool Discretizer_is_polar(DiscretizerHandle handle);

#ifdef __cplusplus
}
#endif
