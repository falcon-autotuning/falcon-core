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

InterpretationContainerQuantityHandle InterpretationContainerQuantity_create(MapInterpretationContextQuantityHandle map);
void InterpretationContainerQuantity_destroy(InterpretationContainerQuantityHandle handle);
SymbolUnitHandle InterpretationContainerQuantity_unit(
     InterpretationContainerQuantityHandle handle);
ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connection(
    InterpretationContainerQuantityHandle handle, ConnectionHandle connection);
ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connections(
                    InterpretationContainerQuantityHandle handle, ConnectionsHandle connections);
ListInterpretationContextHandle InterpretationContainerQuantity_select_by_independent_connection(
                    InterpretationContainerQuantityHandle handle, ConnectionHandle connection);
ListInterpretationContextHandle InterpretationContainerQuantity_select_by_dependent_connection(
                    InterpretationContainerQuantityHandle handle, ConnectionHandle connection);
ListInterpretationContextHandle InterpretationContainerQuantity_select_contexts(
    InterpretationContainerQuantityHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections);
void InterpretationContainerQuantity_insert_or_assign(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key,
    const QuantityHandle value);
void InterpretationContainerQuantity_insert(
    InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key,
    const QuantityHandle value);
QuantityHandle InterpretationContainerQuantity_at(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key);
void InterpretationContainerQuantity_erase(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key);
size_t InterpretationContainerQuantity_size(InterpretationContainerQuantityHandle handle);
bool InterpretationContainerQuantity_empty(InterpretationContainerQuantityHandle handle);
void InterpretationContainerQuantity_clear(InterpretationContainerQuantityHandle handle);
bool InterpretationContainerQuantity_contains(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key);
ListInterpretationContextHandle InterpretationContainerQuantity_keys(
                    InterpretationContainerQuantityHandle handle);
ListQuantityHandle InterpretationContainerQuantity_values(InterpretationContainerQuantityHandle handle);
ListPairInterpretationContextQuantityHandle InterpretationContainerQuantity_items(
                    InterpretationContainerQuantityHandle handle);
bool InterpretationContainerQuantity_equal(InterpretationContainerQuantityHandle handle,InterpretationContainerQuantityHandle other);
bool InterpretationContainerQuantity_not_equal(InterpretationContainerQuantityHandle handle,InterpretationContainerQuantityHandle other);

// Serialization (from Song)
StringHandle      InterpretationContainerQuantity_to_json_string(InterpretationContainerQuantityHandle handle);
InterpretationContainerQuantityHandle InterpretationContainerQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif