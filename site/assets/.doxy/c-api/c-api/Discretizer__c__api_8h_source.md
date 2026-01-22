

# File Discretizer\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**discrete\_spaces**](dir_4135ae89d8b25a1ab40962ee1784aac3.md) **>** [**Discretizer\_c\_api.h**](Discretizer__c__api_8h.md)

[Go to the documentation of this file](Discretizer__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/domains/Domain_c_api.h"
typedef void* DiscretizerHandle;

// @category:allocation
DiscretizerHandle Discretizer_copy(DiscretizerHandle handle);
// @category:deallocation
void Discretizer_destroy(DiscretizerHandle handle);
// @category:read
bool Discretizer_equal(DiscretizerHandle handle, DiscretizerHandle other);
// @category:read
bool Discretizer_not_equal(DiscretizerHandle handle, DiscretizerHandle other);
// @category:read
StringHandle Discretizer_to_json_string(DiscretizerHandle handle);
// @category:allocation
DiscretizerHandle Discretizer_from_json_string(StringHandle json);
// @category:allocation
DiscretizerHandle Discretizer_create_cartesian_discretizer(double delta);
// @category:allocation
DiscretizerHandle Discretizer_create_polar_discretizer(double delta);
// @category:read
double Discretizer_delta(DiscretizerHandle handle);
// @category:write
void Discretizer_set_delta(DiscretizerHandle handle, double delta);
// @category:read
DomainHandle Discretizer_domain(DiscretizerHandle handle);
// @category:read
/* AUTO-DOC from cpp: Discretizer_is_cartesian |
 * falcon_core::math::discrete_spaces::Discretizer::is_cartesian */
bool Discretizer_is_cartesian(DiscretizerHandle handle);
// @category:read
/* AUTO-DOC from cpp: Discretizer_is_polar |
 * falcon_core::math::discrete_spaces::Discretizer::is_polar */
bool Discretizer_is_polar(DiscretizerHandle handle);

#ifdef __cplusplus
}
#endif
```


