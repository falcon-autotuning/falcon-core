

# File AnalyticFunction\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AnalyticFunction\_c\_api.h**](AnalyticFunction__c__api_8h.md)

[Go to the documentation of this file](AnalyticFunction__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/MapStringDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
typedef void* AnalyticFunctionHandle;

// @category:allocation
AnalyticFunctionHandle AnalyticFunction_copy(AnalyticFunctionHandle handle);
// @category:deallocation
void AnalyticFunction_destroy(AnalyticFunctionHandle handle);
// @category:read
bool AnalyticFunction_equal(AnalyticFunctionHandle handle,
                            AnalyticFunctionHandle other);
// @category:read
bool AnalyticFunction_not_equal(AnalyticFunctionHandle handle,
                                AnalyticFunctionHandle other);
// @category:read
StringHandle AnalyticFunction_to_json_string(AnalyticFunctionHandle handle);
// @category:allocation
AnalyticFunctionHandle AnalyticFunction_from_json_string(StringHandle json);
// @category:allocation
AnalyticFunctionHandle AnalyticFunction_create(ListStringHandle labels,
                                               StringHandle     expression);
// @category:allocation
AnalyticFunctionHandle AnalyticFunction_create_identity();
// @category:allocation
AnalyticFunctionHandle AnalyticFunction_create_constant(double value);
// @category:read
/* AUTO-DOC from cpp: AnalyticFunction_labels |
 * falcon_core::math::AnalyticFunction::labels */
ListStringHandle AnalyticFunction_labels(AnalyticFunctionHandle handle);
// @category:read
/* AUTO-DOC from cpp: AnalyticFunction_evaluate |
 * falcon_core::math::AnalyticFunction::evaluate */
double AnalyticFunction_evaluate(AnalyticFunctionHandle handle,
                                 MapStringDoubleHandle  args,
                                 double                 time);
// @category:read
FArrayDoubleHandle AnalyticFunction_evaluate_arraywise(
    AnalyticFunctionHandle handle,
    MapStringDoubleHandle  args,
    double                 deltaT,
    double                 maxTime);

#ifdef __cplusplus
}
#endif
```


