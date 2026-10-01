#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/PairInstrumentPortQuantity_c_api.h"
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairInstrumentPortQuantityHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListPairInstrumentPortQuantityHandle ListPairInstrumentPortQuantity_create_empty();
// @category:allocation
FALCON_CORE_C_API ListPairInstrumentPortQuantityHandle ListPairInstrumentPortQuantity_copy(ListPairInstrumentPortQuantityHandle handle);

// @category:allocation
FALCON_CORE_C_API ListPairInstrumentPortQuantityHandle ListPairInstrumentPortQuantity_fill_value(size_t count, PairInstrumentPortQuantityHandle value);
// @category:allocation
FALCON_CORE_C_API ListPairInstrumentPortQuantityHandle ListPairInstrumentPortQuantity_create(PairInstrumentPortQuantityHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListPairInstrumentPortQuantity_destroy(ListPairInstrumentPortQuantityHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairInstrumentPortQuantity_push_back(ListPairInstrumentPortQuantityHandle handle, PairInstrumentPortQuantityHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairInstrumentPortQuantity_size(ListPairInstrumentPortQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool ListPairInstrumentPortQuantity_empty(ListPairInstrumentPortQuantityHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairInstrumentPortQuantity_erase_at(ListPairInstrumentPortQuantityHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListPairInstrumentPortQuantity_clear(ListPairInstrumentPortQuantityHandle handle);
// @category:read
FALCON_CORE_C_API PairInstrumentPortQuantityHandle ListPairInstrumentPortQuantity_at(ListPairInstrumentPortQuantityHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListPairInstrumentPortQuantity_items(ListPairInstrumentPortQuantityHandle handle, PairInstrumentPortQuantityHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListPairInstrumentPortQuantity_contains(ListPairInstrumentPortQuantityHandle handle, PairInstrumentPortQuantityHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairInstrumentPortQuantity_index(ListPairInstrumentPortQuantityHandle handle, PairInstrumentPortQuantityHandle value);
// @category:read
FALCON_CORE_C_API ListPairInstrumentPortQuantityHandle ListPairInstrumentPortQuantity_intersection(ListPairInstrumentPortQuantityHandle handle, ListPairInstrumentPortQuantityHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairInstrumentPortQuantity_equal(ListPairInstrumentPortQuantityHandle handle, ListPairInstrumentPortQuantityHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairInstrumentPortQuantity_not_equal(ListPairInstrumentPortQuantityHandle handle, ListPairInstrumentPortQuantityHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListPairInstrumentPortQuantity_to_json_string(ListPairInstrumentPortQuantityHandle handle);
// @category:allocation
FALCON_CORE_C_API ListPairInstrumentPortQuantityHandle ListPairInstrumentPortQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif