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
FALCON_CORE_C_API InterpretationContainerQuantityHandle InterpretationContainerQuantity_create(MapInterpretationContextQuantityHandle contextDoubleMap);
// @category:allocation
InterpretationContainerQuantityHandle InterpretationContainerQuantity_copy(InterpretationContainerQuantityHandle handle);
// @category:deallocation
FALCON_CORE_C_API void InterpretationContainerQuantity_destroy(InterpretationContainerQuantityHandle handle);
// @category:read
FALCON_CORE_C_API SymbolUnitHandle InterpretationContainerQuantity_unit(
     InterpretationContainerQuantityHandle handle);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connection(
    InterpretationContainerQuantityHandle handle, ConnectionHandle connection);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connections(
                    InterpretationContainerQuantityHandle handle, ConnectionsHandle connections);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerQuantity_select_by_independent_connection(
                    InterpretationContainerQuantityHandle handle, ConnectionHandle connection);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerQuantity_select_by_dependent_connection(
                    InterpretationContainerQuantityHandle handle, ConnectionHandle connection);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerQuantity_select_contexts(
    InterpretationContainerQuantityHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections);
// @category:write
FALCON_CORE_C_API void InterpretationContainerQuantity_insert_or_assign(InterpretationContainerQuantityHandle handle,
     InterpretationContextHandle   key,
     QuantityHandle value);
// @category:write
FALCON_CORE_C_API void InterpretationContainerQuantity_insert(
    InterpretationContainerQuantityHandle handle,
     InterpretationContextHandle   key,
     QuantityHandle value);
// @category:read
FALCON_CORE_C_API QuantityHandle InterpretationContainerQuantity_at(InterpretationContainerQuantityHandle handle,
     InterpretationContextHandle   key);
// @category:write
FALCON_CORE_C_API void InterpretationContainerQuantity_erase(InterpretationContainerQuantityHandle handle,
     InterpretationContextHandle   key);
// @category:read
FALCON_CORE_C_API size_t InterpretationContainerQuantity_size(InterpretationContainerQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool InterpretationContainerQuantity_empty(InterpretationContainerQuantityHandle handle);
// @category:write
FALCON_CORE_C_API void InterpretationContainerQuantity_clear(InterpretationContainerQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool InterpretationContainerQuantity_contains(InterpretationContainerQuantityHandle handle,
     InterpretationContextHandle   key);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle InterpretationContainerQuantity_keys(
                    InterpretationContainerQuantityHandle handle);
// @category:read
FALCON_CORE_C_API ListQuantityHandle InterpretationContainerQuantity_values(InterpretationContainerQuantityHandle handle);
// @category:read
FALCON_CORE_C_API ListPairInterpretationContextQuantityHandle InterpretationContainerQuantity_items(
                    InterpretationContainerQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool InterpretationContainerQuantity_equal(InterpretationContainerQuantityHandle handle,InterpretationContainerQuantityHandle other);
// @category:read
FALCON_CORE_C_API bool InterpretationContainerQuantity_not_equal(InterpretationContainerQuantityHandle handle,InterpretationContainerQuantityHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      InterpretationContainerQuantity_to_json_string(InterpretationContainerQuantityHandle handle);
// @category:allocation
FALCON_CORE_C_API InterpretationContainerQuantityHandle InterpretationContainerQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif