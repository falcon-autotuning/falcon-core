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
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* InterpretationContainerDoubleHandle;
// Function declarations

InterpretationContainerDoubleHandle InterpretationContainerDouble_create(MapInterpretationContextDoubleHandle map);
SymbolUnitHandle InterpretationContainerDouble_unit(
     InterpretationContainerDoubleHandle handle);
ListInterpretationContextHandle InterpretationContainerDouble_select_by_connection(
    InterpretationContainerDoubleHandle handle, ConnectionHandle connection);
ListInterpretationContextHandle InterpretationContainerDouble_select_by_connections(
                    InterpretationContainerDoubleHandle handle, ConnectionsHandle connections);
ListInterpretationContextHandle InterpretationContainerDouble_select_by_independent_connection(
                    InterpretationContainerDoubleHandle handle, ConnectionHandle connection);
ListInterpretationContextHandle InterpretationContainerDouble_select_by_dependent_connection(
                    InterpretationContainerDoubleHandle handle, ConnectionHandle connection);
ListInterpretationContextHandle InterpretationContainerDouble_select_contexts(
    InterpretationContainerDoubleHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections);
void InterpretationContainerDouble_insert_or_assign(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key,
    const double value);
void InterpretationContainerDouble_insert(
    InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key,
    const double value);
double InterpretationContainerDouble_at(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key);
void InterpretationContainerDouble_erase(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key);
size_t InterpretationContainerDouble_size(InterpretationContainerDoubleHandle handle);
bool InterpretationContainerDouble_empty(InterpretationContainerDoubleHandle handle);
void InterpretationContainerDouble_clear(InterpretationContainerDoubleHandle handle);
bool InterpretationContainerDouble_contains(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key);
ListInterpretationContextHandle InterpretationContainerDouble_keys(
                    InterpretationContainerDoubleHandle handle);
ListDoubleHandle InterpretationContainerDouble_values(InterpretationContainerDoubleHandle handle);
ListPairInterpretationContextDoubleHandle InterpretationContainerDouble_items(
                    InterpretationContainerDoubleHandle handle);
bool InterpretationContainerDouble_equal(InterpretationContainerDoubleHandle handle,InterpretationContainerDoubleHandle other);
bool InterpretationContainerDouble_not_equal(InterpretationContainerDoubleHandle handle,InterpretationContainerDoubleHandle other);

// Serialization (from Song)
StringHandle      InterpretationContainerDouble_to_json_string(InterpretationContainerDoubleHandle handle);
InterpretationContainerDoubleHandle InterpretationContainerDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif