#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/ListConnection_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"
#include "falcon-core/physics/device_structures/Connections_c_api.h"
#include "falcon-core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon-core/generic/ListInterpretationContext_c_api.h"
#include "falcon-core/generic/ListDouble_c_api.h"
#include "falcon-core/generic/ListPairInterpretationContextDouble_c_api.h"
#include "falcon-core/generic/MapInterpretationContextDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* InterpretationContainerDoubleHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API InterpretationContainerDoubleHandle InterpretationContainerDouble_create(MapInterpretationContextDoubleHandle contextDoubleMap);
// @category:allocation
FALCON_CORE_C_API InterpretationContainerDoubleHandle InterpretationContainerDouble_copy(InterpretationContainerDoubleHandle handle);
// @category:deallocation
FALCON_CORE_C_API void InterpretationContainerDouble_destroy(InterpretationContainerDoubleHandle handle);
// @category:read
FALCON_CORE_C_API SymbolUnitHandle InterpretationContainerDouble_unit(
     InterpretationContainerDoubleHandle handle);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerDouble_select_by_connection(
    InterpretationContainerDoubleHandle handle, ConnectionHandle connection);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerDouble_select_by_connections(
                    InterpretationContainerDoubleHandle handle, ConnectionsHandle connections);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerDouble_select_by_independent_connection(
                    InterpretationContainerDoubleHandle handle, ConnectionHandle connection);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerDouble_select_by_dependent_connection(
                    InterpretationContainerDoubleHandle handle, ConnectionHandle connection);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerDouble_select_contexts(
    InterpretationContainerDoubleHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections);
// @category:write
FALCON_CORE_C_API void InterpretationContainerDouble_insert_or_assign(InterpretationContainerDoubleHandle handle,
     InterpretationContextHandle   key,
     double value);
// @category:write
FALCON_CORE_C_API void InterpretationContainerDouble_insert(
    InterpretationContainerDoubleHandle handle,
     InterpretationContextHandle   key,
     double value);
// @category:read
FALCON_CORE_C_API double InterpretationContainerDouble_at(InterpretationContainerDoubleHandle handle,
     InterpretationContextHandle   key);
// @category:write
FALCON_CORE_C_API void InterpretationContainerDouble_erase(InterpretationContainerDoubleHandle handle,
     InterpretationContextHandle   key);
// @category:read
FALCON_CORE_C_API size_t InterpretationContainerDouble_size(InterpretationContainerDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool InterpretationContainerDouble_empty(InterpretationContainerDoubleHandle handle);
// @category:write
FALCON_CORE_C_API void InterpretationContainerDouble_clear(InterpretationContainerDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool InterpretationContainerDouble_contains(InterpretationContainerDoubleHandle handle,
     InterpretationContextHandle   key);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerDouble_keys(
                    InterpretationContainerDoubleHandle handle);
// @category:read
FALCON_CORE_C_API ListDoubleHandle InterpretationContainerDouble_values(InterpretationContainerDoubleHandle handle);
// @category:read
FALCON_CORE_C_API ListPairInterpretationContextDoubleHandle InterpretationContainerDouble_items(
                    InterpretationContainerDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool InterpretationContainerDouble_equal(InterpretationContainerDoubleHandle handle,InterpretationContainerDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool InterpretationContainerDouble_not_equal(InterpretationContainerDoubleHandle handle,InterpretationContainerDoubleHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      InterpretationContainerDouble_to_json_string(InterpretationContainerDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API InterpretationContainerDoubleHandle InterpretationContainerDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif