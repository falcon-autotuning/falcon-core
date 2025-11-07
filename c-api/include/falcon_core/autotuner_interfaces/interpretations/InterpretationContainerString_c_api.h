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
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* InterpretationContainerStringHandle;
// Function declarations

InterpretationContainerStringHandle InterpretationContainerString_create(MapInterpretationContextStringHandle map);
void InterpretationContainerString_destroy(InterpretationContainerStringHandle handle);
SymbolUnitHandle InterpretationContainerString_unit(
     InterpretationContainerStringHandle handle);
ListInterpretationContextHandle InterpretationContainerString_select_by_connection(
    InterpretationContainerStringHandle handle, ConnectionHandle connection);
ListInterpretationContextHandle InterpretationContainerString_select_by_connections(
                    InterpretationContainerStringHandle handle, ConnectionsHandle connections);
ListInterpretationContextHandle InterpretationContainerString_select_by_independent_connection(
                    InterpretationContainerStringHandle handle, ConnectionHandle connection);
ListInterpretationContextHandle InterpretationContainerString_select_by_dependent_connection(
                    InterpretationContainerStringHandle handle, ConnectionHandle connection);
ListInterpretationContextHandle InterpretationContainerString_select_contexts(
    InterpretationContainerStringHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections);
void InterpretationContainerString_insert_or_assign(InterpretationContainerStringHandle handle,
    const InterpretationContextHandle   key,
    const StringHandle value);
void InterpretationContainerString_insert(
    InterpretationContainerStringHandle handle,
    const InterpretationContextHandle   key,
    const StringHandle value);
StringHandle InterpretationContainerString_at(InterpretationContainerStringHandle handle,
    const InterpretationContextHandle   key);
void InterpretationContainerString_erase(InterpretationContainerStringHandle handle,
    const InterpretationContextHandle   key);
size_t InterpretationContainerString_size(InterpretationContainerStringHandle handle);
bool InterpretationContainerString_empty(InterpretationContainerStringHandle handle);
void InterpretationContainerString_clear(InterpretationContainerStringHandle handle);
bool InterpretationContainerString_contains(InterpretationContainerStringHandle handle,
    const InterpretationContextHandle   key);
ListInterpretationContextHandle InterpretationContainerString_keys(
                    InterpretationContainerStringHandle handle);
ListStringHandle InterpretationContainerString_values(InterpretationContainerStringHandle handle);
ListPairInterpretationContextStringHandle InterpretationContainerString_items(
                    InterpretationContainerStringHandle handle);
bool InterpretationContainerString_equal(InterpretationContainerStringHandle handle,InterpretationContainerStringHandle other);
bool InterpretationContainerString_not_equal(InterpretationContainerStringHandle handle,InterpretationContainerStringHandle other);

// Serialization (from Song)
StringHandle      InterpretationContainerString_to_json_string(InterpretationContainerStringHandle handle);
InterpretationContainerStringHandle InterpretationContainerString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif