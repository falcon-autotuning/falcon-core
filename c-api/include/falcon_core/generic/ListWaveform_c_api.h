#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/instrument_interfaces/Waveform_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListWaveformHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListWaveformHandle ListWaveform_create_empty();
// @category:allocation
FALCON_CORE_C_API ListWaveformHandle ListWaveform_copy(ListWaveformHandle handle);

// @category:allocation
FALCON_CORE_C_API ListWaveformHandle ListWaveform_fill_value(size_t count, WaveformHandle value);
// @category:allocation
FALCON_CORE_C_API ListWaveformHandle ListWaveform_create(WaveformHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListWaveform_destroy(ListWaveformHandle handle);
// @category:write
FALCON_CORE_C_API void ListWaveform_push_back(ListWaveformHandle handle, WaveformHandle value);
// @category:read
FALCON_CORE_C_API size_t ListWaveform_size(ListWaveformHandle handle);
// @category:read
FALCON_CORE_C_API bool ListWaveform_empty(ListWaveformHandle handle);
// @category:write
FALCON_CORE_C_API void ListWaveform_erase_at(ListWaveformHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListWaveform_clear(ListWaveformHandle handle);
// @category:read
FALCON_CORE_C_API WaveformHandle ListWaveform_at(ListWaveformHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListWaveform_items(ListWaveformHandle handle, WaveformHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListWaveform_contains(ListWaveformHandle handle, WaveformHandle value);
// @category:read
FALCON_CORE_C_API size_t ListWaveform_index(ListWaveformHandle handle, WaveformHandle value);
// @category:read
FALCON_CORE_C_API ListWaveformHandle ListWaveform_intersection(ListWaveformHandle handle, ListWaveformHandle other);
// @category:read
FALCON_CORE_C_API bool ListWaveform_equal(ListWaveformHandle handle, ListWaveformHandle other);
// @category:read
FALCON_CORE_C_API bool ListWaveform_not_equal(ListWaveformHandle handle, ListWaveformHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListWaveform_to_json_string(ListWaveformHandle handle);
// @category:allocation
FALCON_CORE_C_API ListWaveformHandle ListWaveform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif