#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/domains/CoupledLabelledDomain_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListCoupledLabelledDomainHandle;
// Function declarations

// @category:allocation
ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_create_empty();

// @category:allocation
ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_fill_value(size_t count, CoupledLabelledDomainHandle value);
// @category:allocation
ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_create(CoupledLabelledDomainHandle* data, size_t count);
// @category:deallocation
void ListCoupledLabelledDomain_destroy(ListCoupledLabelledDomainHandle handle);
// @category:write
void ListCoupledLabelledDomain_push_back(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value);
// @category:read
size_t ListCoupledLabelledDomain_size(ListCoupledLabelledDomainHandle handle);
// @category:read
bool ListCoupledLabelledDomain_empty(ListCoupledLabelledDomainHandle handle);
// @category:write
void ListCoupledLabelledDomain_erase_at(ListCoupledLabelledDomainHandle handle, size_t idx);
// @category:write
void ListCoupledLabelledDomain_clear(ListCoupledLabelledDomainHandle handle);
// @category:read
CoupledLabelledDomainHandle ListCoupledLabelledDomain_at(ListCoupledLabelledDomainHandle handle, size_t idx);
// @category:read
size_t ListCoupledLabelledDomain_items(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListCoupledLabelledDomain_contains(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value);
// @category:read
size_t ListCoupledLabelledDomain_index(ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value);
// @category:read
ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_intersection(ListCoupledLabelledDomainHandle handle, ListCoupledLabelledDomainHandle other);
// @category:read
bool ListCoupledLabelledDomain_equal(ListCoupledLabelledDomainHandle a, ListCoupledLabelledDomainHandle b);
// @category:read
bool ListCoupledLabelledDomain_not_equal(ListCoupledLabelledDomainHandle a, ListCoupledLabelledDomainHandle b);

// @category:read
StringHandle      ListCoupledLabelledDomain_to_json_string(ListCoupledLabelledDomainHandle handle);
// @category:allocation
ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif