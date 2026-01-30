#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/domains/CoupledLabelledDomain_c_api.h"
#include "falcon_core/generic/ListCoupledLabelledDomain_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesCoupledLabelledDomainHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create_empty();
// @category:allocation
FALCON_CORE_C_API AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_copy(AxesCoupledLabelledDomainHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create(ListCoupledLabelledDomainHandle data);
// @category:deallocation
FALCON_CORE_C_API void AxesCoupledLabelledDomain_destroy(AxesCoupledLabelledDomainHandle handle);
// @category:write
FALCON_CORE_C_API void AxesCoupledLabelledDomain_push_back(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesCoupledLabelledDomain_size(AxesCoupledLabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API bool AxesCoupledLabelledDomain_empty(AxesCoupledLabelledDomainHandle handle);
// @category:write
FALCON_CORE_C_API void AxesCoupledLabelledDomain_erase_at(AxesCoupledLabelledDomainHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void AxesCoupledLabelledDomain_clear(AxesCoupledLabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API CoupledLabelledDomainHandle AxesCoupledLabelledDomain_at(AxesCoupledLabelledDomainHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t AxesCoupledLabelledDomain_items(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool AxesCoupledLabelledDomain_contains(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesCoupledLabelledDomain_index(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value);
// @category:read
FALCON_CORE_C_API AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_intersection(AxesCoupledLabelledDomainHandle handle, AxesCoupledLabelledDomainHandle other);
// @category:read
FALCON_CORE_C_API bool AxesCoupledLabelledDomain_equal(AxesCoupledLabelledDomainHandle handle, AxesCoupledLabelledDomainHandle other);
// @category:read
FALCON_CORE_C_API bool AxesCoupledLabelledDomain_not_equal(AxesCoupledLabelledDomainHandle handle, AxesCoupledLabelledDomainHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      AxesCoupledLabelledDomain_to_json_string(AxesCoupledLabelledDomainHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif