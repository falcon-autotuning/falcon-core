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

InterpretationContainerStringHandle InterpretationContainerString_create(MapInterpretationContextStringHandle map);
void InterpretationContainerString_destroy(InterpretationContainerStringHandle handle);
/* AUTO-DOC from cpp: InterpretationContainerString_unit | falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::unit */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::unit)
 * @brief Returns the unit that all contexts in this constainer must have.
 */
SymbolUnitHandle InterpretationContainerString_unit(
     InterpretationContainerStringHandle handle);
/* AUTO-DOC from cpp: InterpretationContainerString_select_by_connection | falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::select_by_connection */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::select_by_connection)
 * @brief Select contexts that involve a specific connection.
 * @param connection The connection to search for.
 * @returns A list of contexts that involve the specified connection in either
 * independant or dependant variables.
 */
ListInterpretationContextHandle InterpretationContainerString_select_by_connection(
    InterpretationContainerStringHandle handle, ConnectionHandle connection);
/* AUTO-DOC from cpp: InterpretationContainerString_select_by_connections | falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::select_by_connections */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::select_by_connections)
 * @brief Select contexts that involve all of the specified connections.
 * @param connections List of connections to search for.
 * @returns A list of contexts that involve all specified connections.
 */
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