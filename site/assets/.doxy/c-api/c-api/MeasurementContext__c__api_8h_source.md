

# File MeasurementContext\_c\_api.h

[**File List**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**contexts**](dir_ab40c3cabb8cb545690339f76b9d4949.md) **>** [**MeasurementContext\_c\_api.h**](MeasurementContext__c__api_8h.md)

[Go to the documentation of this file](MeasurementContext__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
typedef void* MeasurementContextHandle;

// @category:allocation
MeasurementContextHandle MeasurementContext_copy(
    MeasurementContextHandle handle);
// @category:deallocation
void MeasurementContext_destroy(MeasurementContextHandle handle);
// @category:read
bool MeasurementContext_equal(MeasurementContextHandle handle,
                              MeasurementContextHandle other);
// @category:read
bool MeasurementContext_not_equal(MeasurementContextHandle handle,
                                  MeasurementContextHandle other);
// @category:read
StringHandle MeasurementContext_to_json_string(MeasurementContextHandle handle);
// @category:allocation
MeasurementContextHandle MeasurementContext_from_json_string(StringHandle json);
// @category:allocation
MeasurementContextHandle MeasurementContext_create(
    ConnectionHandle connection, StringHandle instrument_type);
// @category:allocation
MeasurementContextHandle MeasurementContext_create_from_port(
    InstrumentPortHandle port);
// @category:read
ConnectionHandle MeasurementContext_connection(MeasurementContextHandle handle);
// @category:read
StringHandle MeasurementContext_instrument_type(
    MeasurementContextHandle handle);

#ifdef __cplusplus
}
#endif
```


