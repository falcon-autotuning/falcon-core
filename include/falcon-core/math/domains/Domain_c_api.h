#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon-core/generic/String_c_api.h"
typedef void* DomainHandle;

// @category:allocation
FALCON_CORE_C_API DomainHandle Domain_copy(DomainHandle handle);
// @category:deallocation
FALCON_CORE_C_API void Domain_destroy(DomainHandle handle);
// @category:read
FALCON_CORE_C_API bool Domain_equal(DomainHandle handle, DomainHandle other);
// @category:read
FALCON_CORE_C_API bool Domain_not_equal(DomainHandle handle,
                                        DomainHandle other);
// @category:read
FALCON_CORE_C_API StringHandle Domain_to_json_string(DomainHandle handle);
// @category:allocation
FALCON_CORE_C_API DomainHandle Domain_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API DomainHandle Domain_create(double min_val,
                                             double max_val,
                                             bool   lesser_bound_contained,
                                             bool   greater_bound_contained);
// @category:read
/* AUTO-DOC from cpp: Domain_lesser_bound |
 * falcon_core::math::domains::Domain::lesser_bound */
/**
 * @brief Get the lesser bound of the domain.
 * @return The lesser bound.
 */
FALCON_CORE_C_API double Domain_lesser_bound(DomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: Domain_greater_bound |
 * falcon_core::math::domains::Domain::greater_bound */
/**
 * @brief Get the greater bound of the domain.
 * @return The greater bound.
 */
FALCON_CORE_C_API double Domain_greater_bound(DomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: Domain_lesser_bound_contained |
 * falcon_core::math::domains::Domain::lesser_bound_contained */
/**
 * @brief Check if the lesser bound is contained in the domain.
 * @return True if the lesser bound is contained, false otherwise.
 */
FALCON_CORE_C_API bool Domain_lesser_bound_contained(DomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: Domain_greater_bound_contained |
 * falcon_core::math::domains::Domain::greater_bound_contained */
/**
 * @brief Check if the greater bound is contained in the domain.
 * @return True if the greater bound is contained, false otherwise.
 */
FALCON_CORE_C_API bool Domain_greater_bound_contained(DomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: Domain_in | falcon_core::math::domains::Domain::in */
/**
 * @brief Check if a value is in the domain.
 * @param value The value to check.
 * @return True if the value is in the domain, false otherwise.
 */
FALCON_CORE_C_API bool Domain_in(DomainHandle handle, double value);
// @category:read
/* AUTO-DOC from cpp: Domain_range | falcon_core::math::domains::Domain::range
 */
/**
 * @brief Get the size of the domain.
 * @return The size of the domain.
 */
FALCON_CORE_C_API double Domain_range(DomainHandle handle);
// @category:read
FALCON_CORE_C_API double Domain_center(DomainHandle handle);
// @category:read
FALCON_CORE_C_API DomainHandle Domain_intersection(DomainHandle handle,
                                                   DomainHandle other);
// @category:read
FALCON_CORE_C_API DomainHandle Domain_union(DomainHandle handle,
                                            DomainHandle other);
// @category:read
/* AUTO-DOC from cpp: Domain_is_empty |
 * falcon_core::math::domains::Domain::is_empty */
/**
 * @brief Check if the domain is empty.
 * @return True if the domain is empty, false otherwise.
 */
FALCON_CORE_C_API bool Domain_is_empty(DomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: Domain_contains_domain |
 * falcon_core::math::domains::Domain::contains_domain */
/**
 * @brief Check if this domain completely contains another domain.
 * @param other The other domain.
 * @return True if this domain contains the other domain, false otherwise.
 */
FALCON_CORE_C_API bool Domain_contains_domain(DomainHandle handle,
                                              DomainHandle other);
// @category:read
/* AUTO-DOC from cpp: Domain_shift | falcon_core::math::domains::Domain::shift
 */
/**
 * @brief Shift the domain by an offset.
 * @param offset The offset to shift by.
 * @return A new domain representing the shifted domain.
 */
FALCON_CORE_C_API DomainHandle Domain_shift(DomainHandle handle, double offset);
// @category:read
/* AUTO-DOC from cpp: Domain_scale | falcon_core::math::domains::Domain::scale
 */
/**
 * @brief Scale the domain by a factor.
 * @param factor The factor to scale by.
 * @return A new domain representing the scaled domain.
 */
FALCON_CORE_C_API DomainHandle Domain_scale(DomainHandle handle, double scale);
// @category:read
/* AUTO-DOC from cpp: Domain_transform |
 * falcon_core::math::domains::Domain::transform */
/**
 * @brief Transform a value from this domain to another domain.
 * @param other The other domain to transform to.
 * @param value The value to transform.
 * @return The transformed value.
 */
FALCON_CORE_C_API double Domain_transform(DomainHandle handle,
                                          DomainHandle other,
                                          double       value);

#ifdef __cplusplus
}
#endif
