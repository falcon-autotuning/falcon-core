

# File InterpretationContainerQuantity\_c\_api.h

[**File List**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**interpretations**](dir_13f1f114359a7e6b19216040e0da6abc.md) **>** [**InterpretationContainerQuantity\_c\_api.h**](InterpretationContainerQuantity__c__api_8h.md)

[Go to the documentation of this file](InterpretationContainerQuantity__c__api_8h.md)


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
#include "falcon_core/generic/ListQuantity_c_api.h"
#include "falcon_core/generic/ListPairInterpretationContextQuantity_c_api.h"
#include "falcon_core/generic/MapInterpretationContextQuantity_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* InterpretationContainerQuantityHandle;
// Function declarations

// @category:allocation
InterpretationContainerQuantityHandle InterpretationContainerQuantity_create(MapInterpretationContextQuantityHandle contextDoubleMap);
// @category:allocation
InterpretationContainerQuantityHandle InterpretationContainerQuantity_copy(InterpretationContainerQuantityHandle handle);
// @category:deallocation
void InterpretationContainerQuantity_destroy(InterpretationContainerQuantityHandle handle);
// @category:read
SymbolUnitHandle InterpretationContainerQuantity_unit(
     InterpretationContainerQuantityHandle handle);
// @category:read
ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connection(
    InterpretationContainerQuantityHandle handle, ConnectionHandle connection);
// @category:read
ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connections(
                    InterpretationContainerQuantityHandle handle, ConnectionsHandle connections);
// @category:read
ListInterpretationContextHandle InterpretationContainerQuantity_select_by_independent_connection(
                    InterpretationContainerQuantityHandle handle, ConnectionHandle connection);
// @category:read
ListInterpretationContextHandle InterpretationContainerQuantity_select_by_dependent_connection(
                    InterpretationContainerQuantityHandle handle, ConnectionHandle connection);
// @category:read
ListInterpretationContextHandle InterpretationContainerQuantity_select_contexts(
    InterpretationContainerQuantityHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections);
// @category:write
void InterpretationContainerQuantity_insert_or_assign(InterpretationContainerQuantityHandle handle,
     InterpretationContextHandle   key,
     QuantityHandle value);
// @category:write
void InterpretationContainerQuantity_insert(
    InterpretationContainerQuantityHandle handle,
     InterpretationContextHandle   key,
     QuantityHandle value);
// @category:read
QuantityHandle InterpretationContainerQuantity_at(InterpretationContainerQuantityHandle handle,
     InterpretationContextHandle   key);
// @category:write
void InterpretationContainerQuantity_erase(InterpretationContainerQuantityHandle handle,
     InterpretationContextHandle   key);
// @category:read
size_t InterpretationContainerQuantity_size(InterpretationContainerQuantityHandle handle);
// @category:read
bool InterpretationContainerQuantity_empty(InterpretationContainerQuantityHandle handle);
// @category:write
void InterpretationContainerQuantity_clear(InterpretationContainerQuantityHandle handle);
// @category:read
bool InterpretationContainerQuantity_contains(InterpretationContainerQuantityHandle handle,
     InterpretationContextHandle   key);
// @category:read
ListInterpretationContextHandle InterpretationContainerQuantity_keys(
                    InterpretationContainerQuantityHandle handle);
// @category:read
ListQuantityHandle InterpretationContainerQuantity_values(InterpretationContainerQuantityHandle handle);
// @category:read
ListPairInterpretationContextQuantityHandle InterpretationContainerQuantity_items(
                    InterpretationContainerQuantityHandle handle);
// @category:read
bool InterpretationContainerQuantity_equal(InterpretationContainerQuantityHandle handle,InterpretationContainerQuantityHandle other);
// @category:read
bool InterpretationContainerQuantity_not_equal(InterpretationContainerQuantityHandle handle,InterpretationContainerQuantityHandle other);

// @category:read
StringHandle      InterpretationContainerQuantity_to_json_string(InterpretationContainerQuantityHandle handle);
// @category:allocation
InterpretationContainerQuantityHandle InterpretationContainerQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


