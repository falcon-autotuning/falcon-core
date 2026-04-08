#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListInstrumentPortHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListInstrumentPortHandle ListInstrumentPort_create_empty();
// @category:allocation
FALCON_CORE_C_API ListInstrumentPortHandle ListInstrumentPort_copy(ListInstrumentPortHandle handle);

// @category:allocation
FALCON_CORE_C_API ListInstrumentPortHandle ListInstrumentPort_fill_value(size_t count, InstrumentPortHandle value);
// @category:allocation
FALCON_CORE_C_API ListInstrumentPortHandle ListInstrumentPort_create(InstrumentPortHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListInstrumentPort_destroy(ListInstrumentPortHandle handle);
// @category:write
FALCON_CORE_C_API void ListInstrumentPort_push_back(ListInstrumentPortHandle handle, InstrumentPortHandle value);
// @category:read
FALCON_CORE_C_API size_t ListInstrumentPort_size(ListInstrumentPortHandle handle);
// @category:read
FALCON_CORE_C_API bool ListInstrumentPort_empty(ListInstrumentPortHandle handle);
// @category:write
FALCON_CORE_C_API void ListInstrumentPort_erase_at(ListInstrumentPortHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListInstrumentPort_clear(ListInstrumentPortHandle handle);
// @category:read
FALCON_CORE_C_API InstrumentPortHandle ListInstrumentPort_at(ListInstrumentPortHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListInstrumentPort_items(ListInstrumentPortHandle handle, InstrumentPortHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListInstrumentPort_contains(ListInstrumentPortHandle handle, InstrumentPortHandle value);
// @category:read
FALCON_CORE_C_API size_t ListInstrumentPort_index(ListInstrumentPortHandle handle, InstrumentPortHandle value);
// @category:read
FALCON_CORE_C_API ListInstrumentPortHandle ListInstrumentPort_intersection(ListInstrumentPortHandle handle, ListInstrumentPortHandle other);
// @category:read
FALCON_CORE_C_API bool ListInstrumentPort_equal(ListInstrumentPortHandle handle, ListInstrumentPortHandle other);
// @category:read
FALCON_CORE_C_API bool ListInstrumentPort_not_equal(ListInstrumentPortHandle handle, ListInstrumentPortHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListInstrumentPort_to_json_string(ListInstrumentPortHandle handle);
// @category:allocation
FALCON_CORE_C_API ListInstrumentPortHandle ListInstrumentPort_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif