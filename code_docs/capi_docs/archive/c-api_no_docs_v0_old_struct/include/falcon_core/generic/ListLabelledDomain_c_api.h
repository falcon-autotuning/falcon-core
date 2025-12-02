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

ListLabelledDomainHandle ListLabelledDomain_create_empty();

ListLabelledDomainHandle ListLabelledDomain_fill_value(size_t count, LabelledDomainHandle value);
ListLabelledDomainHandle ListLabelledDomain_create(LabelledDomainHandle* data, size_t count);
void ListLabelledDomain_destroy(ListLabelledDomainHandle handle);
void ListLabelledDomain_push_back(ListLabelledDomainHandle handle, LabelledDomainHandle value);
size_t ListLabelledDomain_size(ListLabelledDomainHandle handle);
bool ListLabelledDomain_empty(ListLabelledDomainHandle handle);
void ListLabelledDomain_erase_at(ListLabelledDomainHandle handle, size_t idx);
void ListLabelledDomain_clear(ListLabelledDomainHandle handle);
LabelledDomainHandle ListLabelledDomain_at(ListLabelledDomainHandle handle, size_t idx);
size_t ListLabelledDomain_items(ListLabelledDomainHandle handle, LabelledDomainHandle* out_buffer, size_t buffer_size);
bool ListLabelledDomain_contains(ListLabelledDomainHandle handle, LabelledDomainHandle value);
size_t ListLabelledDomain_index(ListLabelledDomainHandle handle, LabelledDomainHandle value);
ListLabelledDomainHandle ListLabelledDomain_intersection(ListLabelledDomainHandle handle, ListLabelledDomainHandle other);
bool ListLabelledDomain_equal(ListLabelledDomainHandle a, ListLabelledDomainHandle b);
bool ListLabelledDomain_not_equal(ListLabelledDomainHandle a, ListLabelledDomainHandle b);

// Serialization (from Song)
StringHandle      ListLabelledDomain_to_json_string(ListLabelledDomainHandle handle);
ListLabelledDomainHandle ListLabelledDomain_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif