#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/domains/LabelledDomain_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListLabelledDomainHandle;
// Function declarations

// @category:allocation
ListLabelledDomainHandle ListLabelledDomain_create_empty();

// @category:allocation
ListLabelledDomainHandle ListLabelledDomain_fill_value(size_t count, LabelledDomainHandle value);
// @category:allocation
ListLabelledDomainHandle ListLabelledDomain_create(LabelledDomainHandle* data, size_t count);
// @category:deallocation
void ListLabelledDomain_destroy(ListLabelledDomainHandle handle);
// @category:write
void ListLabelledDomain_push_back(ListLabelledDomainHandle handle, LabelledDomainHandle value);
// @category:read
size_t ListLabelledDomain_size(ListLabelledDomainHandle handle);
// @category:read
bool ListLabelledDomain_empty(ListLabelledDomainHandle handle);
// @category:write
void ListLabelledDomain_erase_at(ListLabelledDomainHandle handle, size_t idx);
// @category:write
void ListLabelledDomain_clear(ListLabelledDomainHandle handle);
// @category:read
LabelledDomainHandle ListLabelledDomain_at(ListLabelledDomainHandle handle, size_t idx);
// @category:read
size_t ListLabelledDomain_items(ListLabelledDomainHandle handle, LabelledDomainHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListLabelledDomain_contains(ListLabelledDomainHandle handle, LabelledDomainHandle value);
// @category:read
size_t ListLabelledDomain_index(ListLabelledDomainHandle handle, LabelledDomainHandle value);
// @category:read
ListLabelledDomainHandle ListLabelledDomain_intersection(ListLabelledDomainHandle handle, ListLabelledDomainHandle other);
// @category:read
bool ListLabelledDomain_equal(ListLabelledDomainHandle a, ListLabelledDomainHandle b);
// @category:read
bool ListLabelledDomain_not_equal(ListLabelledDomainHandle a, ListLabelledDomainHandle b);

// @category:read
StringHandle      ListLabelledDomain_to_json_string(ListLabelledDomainHandle handle);
// @category:allocation
ListLabelledDomainHandle ListLabelledDomain_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif