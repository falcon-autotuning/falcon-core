

# File InterpretationContainerString\_c\_api.h

[**File List**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**interpretations**](dir_13f1f114359a7e6b19216040e0da6abc.md) **>** [**InterpretationContainerString\_c\_api.h**](InterpretationContainerString__c__api_8h.md)

[Go to the documentation of this file](InterpretationContainerString__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon_core/generic/ListInterpretationContext_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/ListPairInterpretationContextString_c_api.h"
#include "falcon_core/generic/MapInterpretationContextString_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* InterpretationContainerStringHandle;
// Function declarations

// @category:allocation
InterpretationContainerStringHandle InterpretationContainerString_create(MapInterpretationContextStringHandle contextDoubleMap);
// @category:allocation
InterpretationContainerStringHandle InterpretationContainerString_copy(InterpretationContainerStringHandle handle);
// @category:deallocation
void InterpretationContainerString_destroy(InterpretationContainerStringHandle handle);
// @category:read
SymbolUnitHandle InterpretationContainerString_unit(
     InterpretationContainerStringHandle handle);
// @category:read
ListInterpretationContextHandle InterpretationContainerString_select_by_connection(
    InterpretationContainerStringHandle handle, ConnectionHandle connection);
// @category:read
ListInterpretationContextHandle InterpretationContainerString_select_by_connections(
                    InterpretationContainerStringHandle handle, ConnectionsHandle connections);
// @category:read
ListInterpretationContextHandle InterpretationContainerString_select_by_independent_connection(
                    InterpretationContainerStringHandle handle, ConnectionHandle connection);
// @category:read
ListInterpretationContextHandle InterpretationContainerString_select_by_dependent_connection(
                    InterpretationContainerStringHandle handle, ConnectionHandle connection);
// @category:read
ListInterpretationContextHandle InterpretationContainerString_select_contexts(
    InterpretationContainerStringHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections);
// @category:write
void InterpretationContainerString_insert_or_assign(InterpretationContainerStringHandle handle,
     InterpretationContextHandle   key,
     StringHandle value);
// @category:write
void InterpretationContainerString_insert(
    InterpretationContainerStringHandle handle,
     InterpretationContextHandle   key,
     StringHandle value);
// @category:read
StringHandle InterpretationContainerString_at(InterpretationContainerStringHandle handle,
     InterpretationContextHandle   key);
// @category:write
void InterpretationContainerString_erase(InterpretationContainerStringHandle handle,
     InterpretationContextHandle   key);
// @category:read
size_t InterpretationContainerString_size(InterpretationContainerStringHandle handle);
// @category:read
bool InterpretationContainerString_empty(InterpretationContainerStringHandle handle);
// @category:write
void InterpretationContainerString_clear(InterpretationContainerStringHandle handle);
// @category:read
bool InterpretationContainerString_contains(InterpretationContainerStringHandle handle,
     InterpretationContextHandle   key);
// @category:read
ListInterpretationContextHandle InterpretationContainerString_keys(
                    InterpretationContainerStringHandle handle);
// @category:read
ListStringHandle InterpretationContainerString_values(InterpretationContainerStringHandle handle);
// @category:read
ListPairInterpretationContextStringHandle InterpretationContainerString_items(
                    InterpretationContainerStringHandle handle);
// @category:read
bool InterpretationContainerString_equal(InterpretationContainerStringHandle handle,InterpretationContainerStringHandle other);
// @category:read
bool InterpretationContainerString_not_equal(InterpretationContainerStringHandle handle,InterpretationContainerStringHandle other);

// @category:read
StringHandle      InterpretationContainerString_to_json_string(InterpretationContainerStringHandle handle);
// @category:allocation
InterpretationContainerStringHandle InterpretationContainerString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


