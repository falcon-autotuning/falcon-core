#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListImpedance_c_api.h"
typedef void* ImpedancesHandle;

// Constructors
ImpedancesHandle Impedances_create_empty();
ImpedancesHandle Impedances_create(const ListImpedanceHandle items);

// Destructor
void Impedances_destroy(ImpedancesHandle handle);

// Methods
void   Impedances_push_back(ImpedancesHandle handle, ImpedanceHandle value);
size_t Impedances_size(ImpedancesHandle handle);
bool   Impedances_empty(ImpedancesHandle handle);
void   Impedances_erase_at(ImpedancesHandle handle, size_t idx);
void   Impedances_clear(ImpedancesHandle handle);
ImpedanceHandle Impedances_const_at(ImpedancesHandle handle, size_t idx);
ImpedanceHandle Impedances_at(ImpedancesHandle handle, size_t idx);
size_t          Impedances_items(ImpedancesHandle handle,
                                 ImpedanceHandle* out_buffer,
                                 size_t           buffer_size);
bool Impedances_contains(ImpedancesHandle handle, ImpedanceHandle value);
ImpedancesHandle Impedances_intersection(ImpedancesHandle a,
                                         ImpedancesHandle b);
size_t Impedances_index(ImpedancesHandle handle, ImpedanceHandle value);
bool   Impedances_equal(ImpedancesHandle a, ImpedancesHandle b);
bool   Impedances_not_equal(ImpedancesHandle a, ImpedancesHandle b);

// Serialization (from Song)
StringHandle     Impedances_to_json_string(ImpedancesHandle handle);
ImpedancesHandle Impedances_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
