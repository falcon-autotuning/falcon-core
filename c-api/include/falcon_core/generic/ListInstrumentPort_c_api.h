#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include <stddef.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListInstrumentPortHandle;
// Function declarations

ListInstrumentPortHandle ListInstrumentPort_create_empty();

ListInstrumentPortHandle ListInstrumentPort_fill_value(size_t count, InstrumentPortHandle value);
ListInstrumentPortHandle ListInstrumentPort_create(InstrumentPortHandle* data, size_t count);
void ListInstrumentPort_destroy(ListInstrumentPortHandle handle);
void ListInstrumentPort_push_back(ListInstrumentPortHandle handle, InstrumentPortHandle value);
size_t ListInstrumentPort_size(ListInstrumentPortHandle handle);
bool ListInstrumentPort_empty(ListInstrumentPortHandle handle);
void ListInstrumentPort_erase_at(ListInstrumentPortHandle handle, size_t idx);
void ListInstrumentPort_clear(ListInstrumentPortHandle handle);
InstrumentPortHandle ListInstrumentPort_at(ListInstrumentPortHandle handle, size_t idx);
size_t ListInstrumentPort_items(ListInstrumentPortHandle handle, InstrumentPortHandle* out_buffer, size_t buffer_size);
bool ListInstrumentPort_contains(ListInstrumentPortHandle handle, InstrumentPortHandle value);
size_t ListInstrumentPort_index(ListInstrumentPortHandle handle, InstrumentPortHandle value);
ListInstrumentPortHandle ListInstrumentPort_intersection(ListInstrumentPortHandle handle, ListInstrumentPortHandle other);
bool ListInstrumentPort_equal(ListInstrumentPortHandle a, ListInstrumentPortHandle b);
bool ListInstrumentPort_not_equal(ListInstrumentPortHandle a, ListInstrumentPortHandle b);

// Serialization (from Song)
StringHandle      ListInstrumentPort_to_json_string(ListInstrumentPortHandle handle);
ListInstrumentPortHandle ListInstrumentPort_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif