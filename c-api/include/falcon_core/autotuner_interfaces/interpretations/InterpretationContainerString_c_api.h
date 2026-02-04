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
FALCON_CORE_C_API InterpretationContainerStringHandle InterpretationContainerString_create(MapInterpretationContextStringHandle contextDoubleMap);
// @category:allocation
InterpretationContainerStringHandle InterpretationContainerString_copy(InterpretationContainerStringHandle handle);
// @category:deallocation
FALCON_CORE_C_API void InterpretationContainerString_destroy(InterpretationContainerStringHandle handle);
// @category:read
FALCON_CORE_C_API SymbolUnitHandle InterpretationContainerString_unit(
     InterpretationContainerStringHandle handle);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerString_select_by_connection(
    InterpretationContainerStringHandle handle, ConnectionHandle connection);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerString_select_by_connections(
                    InterpretationContainerStringHandle handle, ConnectionsHandle connections);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerString_select_by_independent_connection(
                    InterpretationContainerStringHandle handle, ConnectionHandle connection);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerString_select_by_dependent_connection(
                    InterpretationContainerStringHandle handle, ConnectionHandle connection);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerString_select_contexts(
    InterpretationContainerStringHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections);
// @category:write
FALCON_CORE_C_API void InterpretationContainerString_insert_or_assign(InterpretationContainerStringHandle handle,
     InterpretationContextHandle   key,
     StringHandle value);
// @category:write
FALCON_CORE_C_API void InterpretationContainerString_insert(
    InterpretationContainerStringHandle handle,
     InterpretationContextHandle   key,
     StringHandle value);
// @category:read
FALCON_CORE_C_API StringHandle InterpretationContainerString_at(InterpretationContainerStringHandle handle,
     InterpretationContextHandle   key);
// @category:write
FALCON_CORE_C_API void InterpretationContainerString_erase(InterpretationContainerStringHandle handle,
     InterpretationContextHandle   key);
// @category:read
FALCON_CORE_C_API size_t InterpretationContainerString_size(InterpretationContainerStringHandle handle);
// @category:read
FALCON_CORE_C_API bool InterpretationContainerString_empty(InterpretationContainerStringHandle handle);
// @category:write
FALCON_CORE_C_API void InterpretationContainerString_clear(InterpretationContainerStringHandle handle);
// @category:read
FALCON_CORE_C_API bool InterpretationContainerString_contains(InterpretationContainerStringHandle handle,
     InterpretationContextHandle   key);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerString_keys(
                    InterpretationContainerStringHandle handle);
// @category:read
FALCON_CORE_C_API ListStringHandle InterpretationContainerString_values(InterpretationContainerStringHandle handle);
// @category:read
FALCON_CORE_C_API ListPairInterpretationContextStringHandle InterpretationContainerString_items(
                    InterpretationContainerStringHandle handle);
// @category:read
FALCON_CORE_C_API bool InterpretationContainerString_equal(InterpretationContainerStringHandle handle,InterpretationContainerStringHandle other);
// @category:read
FALCON_CORE_C_API bool InterpretationContainerString_not_equal(InterpretationContainerStringHandle handle,InterpretationContainerStringHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      InterpretationContainerString_to_json_string(InterpretationContainerStringHandle handle);
// @category:allocation
FALCON_CORE_C_API InterpretationContainerStringHandle InterpretationContainerString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif