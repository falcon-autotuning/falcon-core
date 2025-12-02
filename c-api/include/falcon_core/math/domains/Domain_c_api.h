#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* DomainHandle;

// Constructors
DomainHandle Domain_create(double min_val,
                           double max_val,
                           bool   lesser_bound_contained,
                           bool   greater_bound_contained);

// Destructor
void Domain_destroy(DomainHandle handle);

// Methods
/* AUTO-DOC from cpp: Domain_lesser_bound | falcon_core::math::domains::Domain::lesser_bound */
/**
 * @brief Get the lesser bound of the domain.
 * @return The lesser bound.
 */
double       Domain_lesser_bound(DomainHandle handle);
/* AUTO-DOC from cpp: Domain_greater_bound | falcon_core::math::domains::Domain::greater_bound */
/**
 * @brief Get the greater bound of the domain.
 * @return The greater bound.
 */
double       Domain_greater_bound(DomainHandle handle);
/* AUTO-DOC from cpp: Domain_lesser_bound_contained | falcon_core::math::domains::Domain::lesser_bound_contained */
/**
 * @brief Check if the lesser bound is contained in the domain.
 * @return True if the lesser bound is contained, false otherwise.
 */
bool         Domain_lesser_bound_contained(DomainHandle handle);
/* AUTO-DOC from cpp: Domain_greater_bound_contained | falcon_core::math::domains::Domain::greater_bound_contained */
/**
 * @brief Check if the greater bound is contained in the domain.
 * @return True if the greater bound is contained, false otherwise.
 */
bool         Domain_greater_bound_contained(DomainHandle handle);
/* AUTO-DOC from cpp: Domain_in | falcon_core::math::domains::Domain::in */
/**
 * @brief Check if a value is in the domain.
 * @param value The value to check.
 * @return True if the value is in the domain, false otherwise.
 */
bool         Domain_in(DomainHandle handle, double value);
/* AUTO-DOC from cpp: Domain_range | falcon_core::math::domains::Domain::range */
/**
 * @brief Get the size of the domain.
 * @return The size of the domain.
 */
double       Domain_range(DomainHandle handle);
double       Domain_center(DomainHandle handle);
DomainHandle Domain_intersection(DomainHandle handle, DomainHandle other);
DomainHandle Domain_union(DomainHandle handle, DomainHandle other);
/* AUTO-DOC from cpp: Domain_is_empty | falcon_core::math::domains::Domain::is_empty */
/**
 * @brief Check if the domain is empty.
 * @return True if the domain is empty, false otherwise.
 */
bool         Domain_is_empty(DomainHandle handle);
/* AUTO-DOC from cpp: Domain_contains_domain | falcon_core::math::domains::Domain::contains_domain */
/**
 * @brief Check if this domain completely contains another domain.
 * @param other The other domain.
 * @return True if this domain contains the other domain, false otherwise.
 */
bool         Domain_contains_domain(DomainHandle handle, DomainHandle other);
/* AUTO-DOC from cpp: Domain_shift | falcon_core::math::domains::Domain::shift */
/**
 * @brief Shift the domain by an offset.
 * @param offset The offset to shift by.
 * @return A new domain representing the shifted domain.
 */
DomainHandle Domain_shift(DomainHandle handle, double offset);
/* AUTO-DOC from cpp: Domain_scale | falcon_core::math::domains::Domain::scale */
/**
 * @brief Scale the domain by a factor.
 * @param factor The factor to scale by.
 * @return A new domain representing the scaled domain.
 */
DomainHandle Domain_scale(DomainHandle handle, double scale);
/* AUTO-DOC from cpp: Domain_transform | falcon_core::math::domains::Domain::transform */
/**
 * @brief Transform a value from this domain to another domain.
 * @param other The other domain to transform to.
 * @param value The value to transform.
 * @return The transformed value.
 */
double Domain_transform(DomainHandle handle, DomainHandle other, double value);
bool   Domain_equal(DomainHandle handle, DomainHandle other);
bool   Domain_not_equal(DomainHandle handle, DomainHandle other);

// Serialization (from Song)
StringHandle Domain_to_json_string(DomainHandle handle);
DomainHandle Domain_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
