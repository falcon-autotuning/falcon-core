#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListLabelledDomain_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/Ports_c_api.h"
#include "falcon_core/math/domains/LabelledDomain_c_api.h"
typedef void* CoupledLabelledDomainHandle;

// @category:allocation
CoupledLabelledDomainHandle CoupledLabelledDomain_create_empty();
// @category:allocation
CoupledLabelledDomainHandle CoupledLabelledDomain_create(
    ListLabelledDomainHandle items);
// @category:deallocation
void CoupledLabelledDomain_destroy(CoupledLabelledDomainHandle handle);
// @category:read
ListLabelledDomainHandle CoupledLabelledDomain_domains(
    CoupledLabelledDomainHandle handle);
// @category:read
PortsHandle CoupledLabelledDomain_labels(CoupledLabelledDomainHandle handle);
// @category:read
LabelledDomainHandle CoupledLabelledDomain_get_domain(
    CoupledLabelledDomainHandle handle, InstrumentPortHandle search);
// @category:read
CoupledLabelledDomainHandle CoupledLabelledDomain_intersection(
    CoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle other);
// @category:write
void CoupledLabelledDomain_push_back(CoupledLabelledDomainHandle handle,
                                     LabelledDomainHandle        value);
// @category:read
size_t CoupledLabelledDomain_size(CoupledLabelledDomainHandle handle);
// @category:read
bool CoupledLabelledDomain_empty(CoupledLabelledDomainHandle handle);
// @category:write
void CoupledLabelledDomain_erase_at(CoupledLabelledDomainHandle handle,
                                    size_t                      idx);
// @category:write
void CoupledLabelledDomain_clear(CoupledLabelledDomainHandle handle);
// @category:read
LabelledDomainHandle CoupledLabelledDomain_const_at(
    CoupledLabelledDomainHandle handle, size_t idx);
// @category:read
LabelledDomainHandle CoupledLabelledDomain_at(
    CoupledLabelledDomainHandle handle, size_t idx);
// @category:read
ListLabelledDomainHandle CoupledLabelledDomain_items(
    CoupledLabelledDomainHandle handle);
// @category:read
bool CoupledLabelledDomain_contains(CoupledLabelledDomainHandle handle,
                                    LabelledDomainHandle        value);
// @category:read
size_t CoupledLabelledDomain_index(CoupledLabelledDomainHandle handle,
                                   LabelledDomainHandle        value);
// @category:read
bool CoupledLabelledDomain_equal(CoupledLabelledDomainHandle a,
                                 CoupledLabelledDomainHandle b);
// @category:read
bool CoupledLabelledDomain_not_equal(CoupledLabelledDomainHandle a,
                                     CoupledLabelledDomainHandle b);
// @category:read
StringHandle CoupledLabelledDomain_to_json_string(
    CoupledLabelledDomainHandle handle);
// @category:allocation
CoupledLabelledDomainHandle CoupledLabelledDomain_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
