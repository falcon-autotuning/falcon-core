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
ListWaveformHandle ListWaveform_create_empty();

// @category:allocation
ListWaveformHandle ListWaveform_fill_value(size_t count, WaveformHandle value);
// @category:allocation
ListWaveformHandle ListWaveform_create(WaveformHandle* data, size_t count);
// @category:deallocation
void ListWaveform_destroy(ListWaveformHandle handle);
// @category:write
void ListWaveform_push_back(ListWaveformHandle handle, WaveformHandle value);
// @category:read
size_t ListWaveform_size(ListWaveformHandle handle);
// @category:read
bool ListWaveform_empty(ListWaveformHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListWaveform_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListWaveform_erase_at(ListWaveformHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListWaveform_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListWaveform_clear(ListWaveformHandle handle);
// @category:read
WaveformHandle ListWaveform_at(ListWaveformHandle handle, size_t idx);
// @category:read
size_t ListWaveform_items(ListWaveformHandle handle, WaveformHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListWaveform_contains(ListWaveformHandle handle, WaveformHandle value);
// @category:read
size_t ListWaveform_index(ListWaveformHandle handle, WaveformHandle value);
// @category:read
/* AUTO-DOC from cpp: ListWaveform_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListWaveformHandle ListWaveform_intersection(ListWaveformHandle handle, ListWaveformHandle other);
// @category:read
bool ListWaveform_equal(ListWaveformHandle a, ListWaveformHandle b);
// @category:read
bool ListWaveform_not_equal(ListWaveformHandle a, ListWaveformHandle b);

// @category:read
StringHandle      ListWaveform_to_json_string(ListWaveformHandle handle);
// @category:allocation
ListWaveformHandle ListWaveform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif