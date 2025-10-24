#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/generic/ListInstrumentPort_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesInstrumentPortHandle;
// Function declarations

AxesInstrumentPortHandle AxesInstrumentPort_create_empty();
AxesInstrumentPortHandle AxesInstrumentPort_create_raw(const InstrumentPortHandle* data, size_t count);
AxesInstrumentPortHandle AxesInstrumentPort_create(ListInstrumentPortHandle data);
void AxesInstrumentPort_destroy(AxesInstrumentPortHandle handle);
void AxesInstrumentPort_push_back(AxesInstrumentPortHandle handle, InstrumentPortHandle value);
size_t AxesInstrumentPort_size(AxesInstrumentPortHandle handle);
bool AxesInstrumentPort_empty(AxesInstrumentPortHandle handle);
void AxesInstrumentPort_erase_at(AxesInstrumentPortHandle handle, size_t idx);
void AxesInstrumentPort_clear(AxesInstrumentPortHandle handle);
InstrumentPortHandle AxesInstrumentPort_at(AxesInstrumentPortHandle handle, size_t idx);
size_t AxesInstrumentPort_items(AxesInstrumentPortHandle handle, InstrumentPortHandle* out_buffer, size_t buffer_size);
bool AxesInstrumentPort_contains(AxesInstrumentPortHandle handle, InstrumentPortHandle value);
size_t AxesInstrumentPort_index(AxesInstrumentPortHandle handle, InstrumentPortHandle value);
AxesInstrumentPortHandle AxesInstrumentPort_intersection(AxesInstrumentPortHandle handle, AxesInstrumentPortHandle other);
bool AxesInstrumentPort_equal(AxesInstrumentPortHandle a, AxesInstrumentPortHandle b);
bool AxesInstrumentPort_not_equal(AxesInstrumentPortHandle a, AxesInstrumentPortHandle b);

// Serialization (from Song)
StringHandle      AxesInstrumentPort_to_json_string(AxesInstrumentPortHandle handle);
AxesInstrumentPortHandle AxesInstrumentPort_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif