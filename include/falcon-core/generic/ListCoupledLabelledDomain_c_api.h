#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/math/domains/CoupledLabelledDomain_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListCoupledLabelledDomainHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_create_empty();
// @category:allocation
FALCON_CORE_C_API ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_copy(ListCoupledLabelledDomainHandle handle);

// @category:allocation
FALCON_CORE_C_API ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_fill_value(size_t count, CoupledLabelledDomainHandle value);
// @category:allocation
FALCON_CORE_C_API ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_create(CoupledLabelledDomainHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListCoupledLabelledDomain_destroy(ListCoupledLabelledDomainHandle handle);
// @category:write
FALCON_CORE_C_API void ListCoupledLabelledDomain_push_back(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value);
// @category:read
FALCON_CORE_C_API size_t ListCoupledLabelledDomain_size(ListCoupledLabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API bool ListCoupledLabelledDomain_empty(ListCoupledLabelledDomainHandle handle);
// @category:write
FALCON_CORE_C_API void ListCoupledLabelledDomain_erase_at(ListCoupledLabelledDomainHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListCoupledLabelledDomain_clear(ListCoupledLabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API CoupledLabelledDomainHandle ListCoupledLabelledDomain_at(ListCoupledLabelledDomainHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListCoupledLabelledDomain_items(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListCoupledLabelledDomain_contains(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value);
// @category:read
FALCON_CORE_C_API size_t ListCoupledLabelledDomain_index(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value);
// @category:read
FALCON_CORE_C_API ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_intersection(ListCoupledLabelledDomainHandle handle, ListCoupledLabelledDomainHandle other);
// @category:read
FALCON_CORE_C_API bool ListCoupledLabelledDomain_equal(ListCoupledLabelledDomainHandle handle, ListCoupledLabelledDomainHandle other);
// @category:read
FALCON_CORE_C_API bool ListCoupledLabelledDomain_not_equal(ListCoupledLabelledDomainHandle handle, ListCoupledLabelledDomainHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListCoupledLabelledDomain_to_json_string(ListCoupledLabelledDomainHandle handle);
// @category:allocation
FALCON_CORE_C_API ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif