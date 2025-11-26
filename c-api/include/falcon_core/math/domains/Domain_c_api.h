#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* DomainHandle;

// @category:allocation
DomainHandle Domain_create(double min_val,
                           double max_val,
                           bool   lesser_bound_contained,
                           bool   greater_bound_contained);
// @category:deallocation
void Domain_destroy(DomainHandle handle);
// @category:read
double Domain_lesser_bound(DomainHandle handle);
// @category:read
double Domain_greater_bound(DomainHandle handle);
// @category:read
bool Domain_lesser_bound_contained(DomainHandle handle);
// @category:read
bool Domain_greater_bound_contained(DomainHandle handle);
// @category:read
bool Domain_in(DomainHandle handle, double value);
// @category:read
double Domain_range(DomainHandle handle);
// @category:read
double Domain_center(DomainHandle handle);
// @category:read
DomainHandle Domain_intersection(DomainHandle handle, DomainHandle other);
// @category:read
DomainHandle Domain_union(DomainHandle handle, DomainHandle other);
// @category:read
bool Domain_is_empty(DomainHandle handle);
// @category:read
bool Domain_contains_domain(DomainHandle handle, DomainHandle other);
// @category:read
DomainHandle Domain_shift(DomainHandle handle, double offset);
// @category:read
DomainHandle Domain_scale(DomainHandle handle, double scale);
// @category:read
double Domain_transform(DomainHandle handle, DomainHandle other, double value);
// @category:read
bool Domain_equal(DomainHandle handle, DomainHandle other);
// @category:read
bool Domain_not_equal(DomainHandle handle, DomainHandle other);
// @category:read
StringHandle Domain_to_json_string(DomainHandle handle);
// @category:allocation
DomainHandle Domain_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
