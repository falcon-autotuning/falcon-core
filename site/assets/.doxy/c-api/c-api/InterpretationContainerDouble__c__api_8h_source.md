

# File InterpretationContainerDouble\_c\_api.h

[**File List**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**interpretations**](dir_13f1f114359a7e6b19216040e0da6abc.md) **>** [**InterpretationContainerDouble\_c\_api.h**](InterpretationContainerDouble__c__api_8h.md)

[Go to the documentation of this file](InterpretationContainerDouble__c__api_8h.md)


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
#include "falcon_core/generic/ListDouble_c_api.h"
#include "falcon_core/generic/ListPairInterpretationContextDouble_c_api.h"
#include "falcon_core/generic/MapInterpretationContextDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* InterpretationContainerDoubleHandle;
// Function declarations

// @category:allocation
InterpretationContainerDoubleHandle InterpretationContainerDouble_create(MapInterpretationContextDoubleHandle contextDoubleMap);
// @category:allocation
InterpretationContainerDoubleHandle InterpretationContainerDouble_copy(InterpretationContainerDoubleHandle handle);
// @category:deallocation
void InterpretationContainerDouble_destroy(InterpretationContainerDoubleHandle handle);
// @category:read
SymbolUnitHandle InterpretationContainerDouble_unit(
     InterpretationContainerDoubleHandle handle);
// @category:read
ListInterpretationContextHandle InterpretationContainerDouble_select_by_connection(
    InterpretationContainerDoubleHandle handle, ConnectionHandle connection);
// @category:read
ListInterpretationContextHandle InterpretationContainerDouble_select_by_connections(
                    InterpretationContainerDoubleHandle handle, ConnectionsHandle connections);
// @category:read
ListInterpretationContextHandle InterpretationContainerDouble_select_by_independent_connection(
                    InterpretationContainerDoubleHandle handle, ConnectionHandle connection);
// @category:read
ListInterpretationContextHandle InterpretationContainerDouble_select_by_dependent_connection(
                    InterpretationContainerDoubleHandle handle, ConnectionHandle connection);
// @category:read
ListInterpretationContextHandle InterpretationContainerDouble_select_contexts(
    InterpretationContainerDoubleHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections);
// @category:write
void InterpretationContainerDouble_insert_or_assign(InterpretationContainerDoubleHandle handle,
     InterpretationContextHandle   key,
     double value);
// @category:write
void InterpretationContainerDouble_insert(
    InterpretationContainerDoubleHandle handle,
     InterpretationContextHandle   key,
     double value);
// @category:read
double InterpretationContainerDouble_at(InterpretationContainerDoubleHandle handle,
     InterpretationContextHandle   key);
// @category:write
void InterpretationContainerDouble_erase(InterpretationContainerDoubleHandle handle,
     InterpretationContextHandle   key);
// @category:read
size_t InterpretationContainerDouble_size(InterpretationContainerDoubleHandle handle);
// @category:read
bool InterpretationContainerDouble_empty(InterpretationContainerDoubleHandle handle);
// @category:write
void InterpretationContainerDouble_clear(InterpretationContainerDoubleHandle handle);
// @category:read
bool InterpretationContainerDouble_contains(InterpretationContainerDoubleHandle handle,
     InterpretationContextHandle   key);
// @category:read
ListInterpretationContextHandle InterpretationContainerDouble_keys(
                    InterpretationContainerDoubleHandle handle);
// @category:read
ListDoubleHandle InterpretationContainerDouble_values(InterpretationContainerDoubleHandle handle);
// @category:read
ListPairInterpretationContextDoubleHandle InterpretationContainerDouble_items(
                    InterpretationContainerDoubleHandle handle);
// @category:read
bool InterpretationContainerDouble_equal(InterpretationContainerDoubleHandle handle,InterpretationContainerDoubleHandle other);
// @category:read
bool InterpretationContainerDouble_not_equal(InterpretationContainerDoubleHandle handle,InterpretationContainerDoubleHandle other);

// @category:read
StringHandle      InterpretationContainerDouble_to_json_string(InterpretationContainerDoubleHandle handle);
// @category:allocation
InterpretationContainerDoubleHandle InterpretationContainerDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


