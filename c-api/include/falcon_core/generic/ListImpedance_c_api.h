#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Impedance_c_api.h"
#include <cstddef>

// Forward declarations for opaque handles
typedef void* ListImpedanceHandle;
// Function declarations

ListImpedanceHandle ListImpedance_create_empty();
ListImpedanceHandle ListImpedance_allocate(size_t count);
ListImpedanceHandle ListImpedance_fill_value(size_t count, ImpedanceHandle value);
ListImpedanceHandle ListImpedance_create(const ImpedanceHandle* data, size_t count);
void ListImpedance_destroy(ListImpedanceHandle handle);
void ListImpedance_push_back(ListImpedanceHandle handle, ImpedanceHandle value);
size_t ListImpedance_size(ListImpedanceHandle handle);
bool ListImpedance_empty(ListImpedanceHandle handle);
void ListImpedance_erase_at(ListImpedanceHandle handle, size_t idx);
void ListImpedance_clear(ListImpedanceHandle handle);
ImpedanceHandle ListImpedance_at(ListImpedanceHandle handle, size_t idx);
size_t ListImpedance_items(ListImpedanceHandle handle, ImpedanceHandle* out_buffer, size_t buffer_size);
bool ListImpedance_contains(ListImpedanceHandle handle, ImpedanceHandle value);
size_t ListImpedance_index(ListImpedanceHandle handle, ImpedanceHandle value);
ListImpedanceHandle ListImpedance_intersection(ListImpedanceHandle handle, ListImpedanceHandle other);
bool ListImpedance_equal(ListImpedanceHandle a, ListImpedanceHandle b);
bool ListImpedance_not_equal(ListImpedanceHandle a, ListImpedanceHandle b);
#ifdef __cplusplus
}
#endif