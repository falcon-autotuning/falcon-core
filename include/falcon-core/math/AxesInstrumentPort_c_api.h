#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon-core/generic/ListInstrumentPort_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesInstrumentPortHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API AxesInstrumentPortHandle AxesInstrumentPort_create_empty();
// @category:allocation
FALCON_CORE_C_API AxesInstrumentPortHandle AxesInstrumentPort_copy(AxesInstrumentPortHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesInstrumentPortHandle AxesInstrumentPort_create(ListInstrumentPortHandle data);
// @category:deallocation
FALCON_CORE_C_API void AxesInstrumentPort_destroy(AxesInstrumentPortHandle handle);
// @category:write
FALCON_CORE_C_API void AxesInstrumentPort_push_back(AxesInstrumentPortHandle handle, InstrumentPortHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesInstrumentPort_size(AxesInstrumentPortHandle handle);
// @category:read
FALCON_CORE_C_API bool AxesInstrumentPort_empty(AxesInstrumentPortHandle handle);
// @category:write
FALCON_CORE_C_API void AxesInstrumentPort_erase_at(AxesInstrumentPortHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void AxesInstrumentPort_clear(AxesInstrumentPortHandle handle);
// @category:read
FALCON_CORE_C_API InstrumentPortHandle AxesInstrumentPort_at(AxesInstrumentPortHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t AxesInstrumentPort_items(AxesInstrumentPortHandle handle, InstrumentPortHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool AxesInstrumentPort_contains(AxesInstrumentPortHandle handle, InstrumentPortHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesInstrumentPort_index(AxesInstrumentPortHandle handle, InstrumentPortHandle value);
// @category:read
FALCON_CORE_C_API AxesInstrumentPortHandle AxesInstrumentPort_intersection(AxesInstrumentPortHandle handle, AxesInstrumentPortHandle other);
// @category:read
FALCON_CORE_C_API bool AxesInstrumentPort_equal(AxesInstrumentPortHandle handle, AxesInstrumentPortHandle other);
// @category:read
FALCON_CORE_C_API bool AxesInstrumentPort_not_equal(AxesInstrumentPortHandle handle, AxesInstrumentPortHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      AxesInstrumentPort_to_json_string(AxesInstrumentPortHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesInstrumentPortHandle AxesInstrumentPort_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif