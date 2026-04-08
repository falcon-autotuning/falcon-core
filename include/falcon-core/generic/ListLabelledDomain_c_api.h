#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/math/domains/LabelledDomain_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListLabelledDomainHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListLabelledDomainHandle ListLabelledDomain_create_empty();
// @category:allocation
FALCON_CORE_C_API ListLabelledDomainHandle ListLabelledDomain_copy(ListLabelledDomainHandle handle);

// @category:allocation
FALCON_CORE_C_API ListLabelledDomainHandle ListLabelledDomain_fill_value(size_t count, LabelledDomainHandle value);
// @category:allocation
FALCON_CORE_C_API ListLabelledDomainHandle ListLabelledDomain_create(LabelledDomainHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListLabelledDomain_destroy(ListLabelledDomainHandle handle);
// @category:write
FALCON_CORE_C_API void ListLabelledDomain_push_back(ListLabelledDomainHandle handle, LabelledDomainHandle value);
// @category:read
FALCON_CORE_C_API size_t ListLabelledDomain_size(ListLabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API bool ListLabelledDomain_empty(ListLabelledDomainHandle handle);
// @category:write
FALCON_CORE_C_API void ListLabelledDomain_erase_at(ListLabelledDomainHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListLabelledDomain_clear(ListLabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API LabelledDomainHandle ListLabelledDomain_at(ListLabelledDomainHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListLabelledDomain_items(ListLabelledDomainHandle handle, LabelledDomainHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListLabelledDomain_contains(ListLabelledDomainHandle handle, LabelledDomainHandle value);
// @category:read
FALCON_CORE_C_API size_t ListLabelledDomain_index(ListLabelledDomainHandle handle, LabelledDomainHandle value);
// @category:read
FALCON_CORE_C_API ListLabelledDomainHandle ListLabelledDomain_intersection(ListLabelledDomainHandle handle, ListLabelledDomainHandle other);
// @category:read
FALCON_CORE_C_API bool ListLabelledDomain_equal(ListLabelledDomainHandle handle, ListLabelledDomainHandle other);
// @category:read
FALCON_CORE_C_API bool ListLabelledDomain_not_equal(ListLabelledDomainHandle handle, ListLabelledDomainHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListLabelledDomain_to_json_string(ListLabelledDomainHandle handle);
// @category:allocation
FALCON_CORE_C_API ListLabelledDomainHandle ListLabelledDomain_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif