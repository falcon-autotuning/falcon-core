#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
typedef void* DomainHandle;

// Constructors
DomainHandle Domain_create(double min_val,
                           double max_val,
                           bool   lesser_bound_contained  = true,
                           bool   greater_bound_contained = true);

// Destructor
void Domain_destroy(DomainHandle handle);

// Methods
double       Domain_lesser_bound(DomainHandle handle);
double       Domain_greater_bound(DomainHandle handle);
bool         Domain_lesser_bound_contained(DomainHandle handle);
bool         Domain_greater_bound_contained(DomainHandle handle);
bool         Domain_in(DomainHandle handle, double value);
double       Domain_range(DomainHandle handle);
double       Domain_center(DomainHandle handle);
DomainHandle Domain_intersection(DomainHandle handle, DomainHandle other);
DomainHandle Domain_union(DomainHandle handle, DomainHandle other);
bool         Domain_is_empty(DomainHandle handle);
bool         Domain_contains_domain(DomainHandle handle, DomainHandle other);
DomainHandle Domain_shift(DomainHandle handle, double offset);
DomainHandle Domain_scale(DomainHandle handle, double scale);
double Domain_transform(DomainHandle handle, DomainHandle other, double value);
bool   Domain_equal(DomainHandle handle, DomainHandle other);
bool   Domain_not_equal(DomainHandle handle, DomainHandle other);

// Serialization (from Song)
const char*  Domain_to_json_string(DomainHandle handle);
DomainHandle Domain_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif
