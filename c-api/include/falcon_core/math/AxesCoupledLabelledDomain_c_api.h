#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/domains/CoupledLabelledDomain_c_api.h"
#include "falcon_core/generic/ListCoupledLabelledDomain_c_api.h"
#include <stddef.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesCoupledLabelledDomainHandle;
// Function declarations

AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create_empty();
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create_raw(const CoupledLabelledDomainHandle* data, size_t count);
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create(ListCoupledLabelledDomainHandle data);
void AxesCoupledLabelledDomain_destroy(AxesCoupledLabelledDomainHandle handle);
void AxesCoupledLabelledDomain_push_back(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value);
size_t AxesCoupledLabelledDomain_size(AxesCoupledLabelledDomainHandle handle);
bool AxesCoupledLabelledDomain_empty(AxesCoupledLabelledDomainHandle handle);
void AxesCoupledLabelledDomain_erase_at(AxesCoupledLabelledDomainHandle handle, size_t idx);
void AxesCoupledLabelledDomain_clear(AxesCoupledLabelledDomainHandle handle);
CoupledLabelledDomainHandle AxesCoupledLabelledDomain_at(AxesCoupledLabelledDomainHandle handle, size_t idx);
size_t AxesCoupledLabelledDomain_items(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle* out_buffer, size_t buffer_size);
bool AxesCoupledLabelledDomain_contains(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value);
size_t AxesCoupledLabelledDomain_index(AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value);
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_intersection(AxesCoupledLabelledDomainHandle handle, AxesCoupledLabelledDomainHandle other);
bool AxesCoupledLabelledDomain_equal(AxesCoupledLabelledDomainHandle a, AxesCoupledLabelledDomainHandle b);
bool AxesCoupledLabelledDomain_not_equal(AxesCoupledLabelledDomainHandle a, AxesCoupledLabelledDomainHandle b);

// Serialization (from Song)
StringHandle      AxesCoupledLabelledDomain_to_json_string(AxesCoupledLabelledDomainHandle handle);
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif