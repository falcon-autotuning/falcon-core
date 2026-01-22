

# File PortTransform\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**instrument\_interfaces**](dir_9a3e3629c63b09e0e53088699a1e2284.md) **>** [**port\_transforms**](dir_d9b7dfc8594864a30460f4237d4753dd.md) **>** [**PortTransform\_c\_api.h**](PortTransform__c__api_8h.md)

[Go to the documentation of this file](PortTransform__c__api_8h.md)


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
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/math/AnalyticFunction_c_api.h"
typedef void* PortTransformHandle;

// @category:allocation
PortTransformHandle PortTransform_copy(PortTransformHandle handle);
// @category:deallocation
void PortTransform_destroy(PortTransformHandle handle);
// @category:read
bool PortTransform_equal(PortTransformHandle handle, PortTransformHandle other);
// @category:read
bool PortTransform_not_equal(PortTransformHandle handle,
                             PortTransformHandle other);
// @category:read
StringHandle PortTransform_to_json_string(PortTransformHandle handle);
// @category:allocation
PortTransformHandle PortTransform_from_json_string(StringHandle json);
// @category:allocation
PortTransformHandle PortTransform_create(InstrumentPortHandle   port,
                                         AnalyticFunctionHandle transform);
// @category:allocation
PortTransformHandle PortTransform_create_constant_transform(
    InstrumentPortHandle port, double value);
// @category:allocation
PortTransformHandle PortTransform_create_identity_transform(
    InstrumentPortHandle port);
// @category:read
/* AUTO-DOC from cpp: PortTransform_port |
 * falcon_core::instrument_interfaces::port_transforms::PortTransform::port */
InstrumentPortHandle PortTransform_port(PortTransformHandle handle);
// @category:read
ListStringHandle PortTransform_labels(PortTransformHandle handle);
// @category:read
double PortTransform_evaluate(PortTransformHandle   handle,
                              MapStringDoubleHandle args,
                              double                time);
// @category:read
FArrayDoubleHandle PortTransform_evaluate_arraywise(PortTransformHandle handle,
                                                    MapStringDoubleHandle args,
                                                    double deltaT,
                                                    double maxTime);

#ifdef __cplusplus
}
#endif
```


