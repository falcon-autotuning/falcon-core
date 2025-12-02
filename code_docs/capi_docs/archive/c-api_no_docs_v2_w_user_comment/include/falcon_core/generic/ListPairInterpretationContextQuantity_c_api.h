#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairInterpretationContextQuantity_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairInterpretationContextQuantityHandle;
// Function declarations

// @category:allocation
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_create_empty();

// @category:allocation
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_fill_value(size_t count, PairInterpretationContextQuantityHandle value);
// @category:allocation
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_create(PairInterpretationContextQuantityHandle* data, size_t count);
// @category:deallocation
void ListPairInterpretationContextQuantity_destroy(ListPairInterpretationContextQuantityHandle handle);
// @category:write
void ListPairInterpretationContextQuantity_push_back(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle value);
// @category:read
size_t ListPairInterpretationContextQuantity_size(ListPairInterpretationContextQuantityHandle handle);
// @category:read
bool ListPairInterpretationContextQuantity_empty(ListPairInterpretationContextQuantityHandle handle);
// @category:write
void ListPairInterpretationContextQuantity_erase_at(ListPairInterpretationContextQuantityHandle handle, size_t idx);
// @category:write
void ListPairInterpretationContextQuantity_clear(ListPairInterpretationContextQuantityHandle handle);
// @category:read
PairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_at(ListPairInterpretationContextQuantityHandle handle, size_t idx);
// @category:read
size_t ListPairInterpretationContextQuantity_items(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairInterpretationContextQuantity_contains(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle value);
// @category:read
size_t ListPairInterpretationContextQuantity_index(ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle value);
// @category:read
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_intersection(ListPairInterpretationContextQuantityHandle handle, ListPairInterpretationContextQuantityHandle other);
// @category:read
bool ListPairInterpretationContextQuantity_equal(ListPairInterpretationContextQuantityHandle a, ListPairInterpretationContextQuantityHandle b);
// @category:read
bool ListPairInterpretationContextQuantity_not_equal(ListPairInterpretationContextQuantityHandle a, ListPairInterpretationContextQuantityHandle b);

// @category:read
StringHandle      ListPairInterpretationContextQuantity_to_json_string(ListPairInterpretationContextQuantityHandle handle);
// @category:allocation
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif