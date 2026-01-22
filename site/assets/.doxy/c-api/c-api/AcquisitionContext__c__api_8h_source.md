

# File AcquisitionContext\_c\_api.h

[**File List**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**contexts**](dir_ab40c3cabb8cb545690339f76b9d4949.md) **>** [**AcquisitionContext\_c\_api.h**](AcquisitionContext__c__api_8h.md)

[Go to the documentation of this file](AcquisitionContext__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
typedef void* AcquisitionContextHandle;

// @category:allocation
AcquisitionContextHandle AcquisitionContext_copy(
    AcquisitionContextHandle handle);
// @category:deallocation
void AcquisitionContext_destroy(AcquisitionContextHandle handle);
// @category:read
bool AcquisitionContext_equal(AcquisitionContextHandle handle,
                              AcquisitionContextHandle other);
// @category:read
bool AcquisitionContext_not_equal(AcquisitionContextHandle handle,
                                  AcquisitionContextHandle other);
// @category:read
StringHandle AcquisitionContext_to_json_string(AcquisitionContextHandle handle);
// @category:allocation
AcquisitionContextHandle AcquisitionContext_from_json_string(StringHandle json);
// @category:allocation
AcquisitionContextHandle AcquisitionContext_create(ConnectionHandle connection,
                                                   StringHandle instrument_type,
                                                   SymbolUnitHandle units);
// @category:allocation
AcquisitionContextHandle AcquisitionContext_create_from_port(
    InstrumentPortHandle port);
// @category:read
ConnectionHandle AcquisitionContext_connection(AcquisitionContextHandle handle);
// @category:read
StringHandle AcquisitionContext_instrument_type(
    AcquisitionContextHandle handle);
// @category:read
/* AUTO-DOC from cpp: AcquisitionContext_units |
 * falcon_core::autotuner_interfaces::contexts::AcquisitionContext::units */
SymbolUnitHandle AcquisitionContext_units(AcquisitionContextHandle handle);
// @category:read
AcquisitionContextHandle AcquisitionContext_division_unit(
    AcquisitionContextHandle handle, SymbolUnitHandle other);
// @category:read
AcquisitionContextHandle AcquisitionContext_division(
    AcquisitionContextHandle handle, AcquisitionContextHandle other);
// @category:read
/* AUTO-DOC from cpp: AcquisitionContext_match_connection |
 * falcon_core::autotuner_interfaces::contexts::AcquisitionContext::match_connection
 */
bool AcquisitionContext_match_connection(AcquisitionContextHandle handle,
                                         ConnectionHandle         other);
// @category:read
/* AUTO-DOC from cpp: AcquisitionContext_match_instrument_type |
 * falcon_core::autotuner_interfaces::contexts::AcquisitionContext::match_instrument_type
 */
bool AcquisitionContext_match_instrument_type(AcquisitionContextHandle handle,
                                              StringHandle             other);

#ifdef __cplusplus
}
#endif
```


