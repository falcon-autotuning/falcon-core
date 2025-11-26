#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/domains/Domain_c_api.h"
typedef void* DiscretizerHandle;

// @category:allocation
DiscretizerHandle Discretizer_create_cartesian_discretizer(double delta);
// @category:allocation
DiscretizerHandle Discretizer_create_polar_discretizer(double delta);
// @category:deallocation
void Discretizer_destroy(DiscretizerHandle handle);
// @category:read
double Discretizer_delta(DiscretizerHandle handle);
// @category:write
void Discretizer_set_delta(DiscretizerHandle handle, double delta);
// @category:read
DomainHandle Discretizer_domain(DiscretizerHandle handle);
// @category:read
bool Discretizer_is_cartesian(DiscretizerHandle handle);
// @category:read
bool Discretizer_is_polar(DiscretizerHandle handle);
// @category:read
bool Discretizer_equal(DiscretizerHandle a, DiscretizerHandle b);
// @category:read
bool Discretizer_not_equal(DiscretizerHandle a, DiscretizerHandle b);
// @category:read
StringHandle Discretizer_to_json_string(DiscretizerHandle handle);
// @category:allocation
DiscretizerHandle Discretizer_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
