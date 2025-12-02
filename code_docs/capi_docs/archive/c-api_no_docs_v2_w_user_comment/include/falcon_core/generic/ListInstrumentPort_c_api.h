#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListInstrumentPortHandle;
// Function declarations

// @category:allocation
ListInstrumentPortHandle ListInstrumentPort_create_empty();

// @category:allocation
ListInstrumentPortHandle ListInstrumentPort_fill_value(size_t count, InstrumentPortHandle value);
// @category:allocation
ListInstrumentPortHandle ListInstrumentPort_create(InstrumentPortHandle* data, size_t count);
// @category:deallocation
void ListInstrumentPort_destroy(ListInstrumentPortHandle handle);
// @category:write
void ListInstrumentPort_push_back(ListInstrumentPortHandle handle, InstrumentPortHandle value);
// @category:read
size_t ListInstrumentPort_size(ListInstrumentPortHandle handle);
// @category:read
bool ListInstrumentPort_empty(ListInstrumentPortHandle handle);
// @category:write
void ListInstrumentPort_erase_at(ListInstrumentPortHandle handle, size_t idx);
// @category:write
void ListInstrumentPort_clear(ListInstrumentPortHandle handle);
// @category:read
InstrumentPortHandle ListInstrumentPort_at(ListInstrumentPortHandle handle, size_t idx);
// @category:read
size_t ListInstrumentPort_items(ListInstrumentPortHandle handle, InstrumentPortHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListInstrumentPort_contains(ListInstrumentPortHandle handle, InstrumentPortHandle value);
// @category:read
size_t ListInstrumentPort_index(ListInstrumentPortHandle handle, InstrumentPortHandle value);
// @category:read
ListInstrumentPortHandle ListInstrumentPort_intersection(ListInstrumentPortHandle handle, ListInstrumentPortHandle other);
// @category:read
bool ListInstrumentPort_equal(ListInstrumentPortHandle a, ListInstrumentPortHandle b);
// @category:read
bool ListInstrumentPort_not_equal(ListInstrumentPortHandle a, ListInstrumentPortHandle b);

// @category:read
StringHandle      ListInstrumentPort_to_json_string(ListInstrumentPortHandle handle);
// @category:allocation
ListInstrumentPortHandle ListInstrumentPort_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif