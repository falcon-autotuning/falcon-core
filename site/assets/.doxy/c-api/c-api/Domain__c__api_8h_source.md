

# File Domain\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**domains**](dir_f5c6b653fd63ad902756e04c4af35f80.md) **>** [**Domain\_c\_api.h**](Domain__c__api_8h.md)

[Go to the documentation of this file](Domain__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* DomainHandle;

// @category:allocation
DomainHandle Domain_copy(DomainHandle handle);
// @category:deallocation
void Domain_destroy(DomainHandle handle);
// @category:read
bool Domain_equal(DomainHandle handle, DomainHandle other);
// @category:read
bool Domain_not_equal(DomainHandle handle, DomainHandle other);
// @category:read
StringHandle Domain_to_json_string(DomainHandle handle);
// @category:allocation
DomainHandle Domain_from_json_string(StringHandle json);
// @category:allocation
DomainHandle Domain_create(double min_val,
                           double max_val,
                           bool   lesser_bound_contained,
                           bool   greater_bound_contained);
// @category:read
/* AUTO-DOC from cpp: Domain_lesser_bound |
 * falcon_core::math::domains::Domain::lesser_bound */
double Domain_lesser_bound(DomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: Domain_greater_bound |
 * falcon_core::math::domains::Domain::greater_bound */
double Domain_greater_bound(DomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: Domain_lesser_bound_contained |
 * falcon_core::math::domains::Domain::lesser_bound_contained */
bool Domain_lesser_bound_contained(DomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: Domain_greater_bound_contained |
 * falcon_core::math::domains::Domain::greater_bound_contained */
bool Domain_greater_bound_contained(DomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: Domain_in | falcon_core::math::domains::Domain::in */
bool Domain_in(DomainHandle handle, double value);
// @category:read
/* AUTO-DOC from cpp: Domain_range | falcon_core::math::domains::Domain::range
 */
double Domain_range(DomainHandle handle);
// @category:read
double Domain_center(DomainHandle handle);
// @category:read
DomainHandle Domain_intersection(DomainHandle handle, DomainHandle other);
// @category:read
DomainHandle Domain_union(DomainHandle handle, DomainHandle other);
// @category:read
/* AUTO-DOC from cpp: Domain_is_empty |
 * falcon_core::math::domains::Domain::is_empty */
bool Domain_is_empty(DomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: Domain_contains_domain |
 * falcon_core::math::domains::Domain::contains_domain */
bool Domain_contains_domain(DomainHandle handle, DomainHandle other);
// @category:read
/* AUTO-DOC from cpp: Domain_shift | falcon_core::math::domains::Domain::shift
 */
DomainHandle Domain_shift(DomainHandle handle, double offset);
// @category:read
/* AUTO-DOC from cpp: Domain_scale | falcon_core::math::domains::Domain::scale
 */
DomainHandle Domain_scale(DomainHandle handle, double scale);
// @category:read
/* AUTO-DOC from cpp: Domain_transform |
 * falcon_core::math::domains::Domain::transform */
double Domain_transform(DomainHandle handle, DomainHandle other, double value);

#ifdef __cplusplus
}
#endif
```


