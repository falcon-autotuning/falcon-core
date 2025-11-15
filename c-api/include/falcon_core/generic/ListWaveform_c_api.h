#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/instrument_interfaces/Waveform_c_api.h"
#include <stddef.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListWaveformHandle;
// Function declarations

ListWaveformHandle ListWaveform_create_empty();

ListWaveformHandle ListWaveform_fill_value(size_t count, WaveformHandle value);
ListWaveformHandle ListWaveform_create(WaveformHandle* data, size_t count);
void ListWaveform_destroy(ListWaveformHandle handle);
void ListWaveform_push_back(ListWaveformHandle handle, WaveformHandle value);
size_t ListWaveform_size(ListWaveformHandle handle);
bool ListWaveform_empty(ListWaveformHandle handle);
void ListWaveform_erase_at(ListWaveformHandle handle, size_t idx);
void ListWaveform_clear(ListWaveformHandle handle);
WaveformHandle ListWaveform_at(ListWaveformHandle handle, size_t idx);
size_t ListWaveform_items(ListWaveformHandle handle, WaveformHandle* out_buffer, size_t buffer_size);
bool ListWaveform_contains(ListWaveformHandle handle, WaveformHandle value);
size_t ListWaveform_index(ListWaveformHandle handle, WaveformHandle value);
ListWaveformHandle ListWaveform_intersection(ListWaveformHandle handle, ListWaveformHandle other);
bool ListWaveform_equal(ListWaveformHandle a, ListWaveformHandle b);
bool ListWaveform_not_equal(ListWaveformHandle a, ListWaveformHandle b);

// Serialization (from Song)
StringHandle      ListWaveform_to_json_string(ListWaveformHandle handle);
ListWaveformHandle ListWaveform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif