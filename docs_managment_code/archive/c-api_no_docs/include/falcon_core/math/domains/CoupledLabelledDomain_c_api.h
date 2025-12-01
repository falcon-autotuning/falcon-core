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

// Constructors
CoupledLabelledDomainHandle CoupledLabelledDomain_create_empty();
CoupledLabelledDomainHandle CoupledLabelledDomain_create(
    const ListLabelledDomainHandle items);

// Destructor
void CoupledLabelledDomain_destroy(CoupledLabelledDomainHandle handle);

// Methods
ListLabelledDomainHandle CoupledLabelledDomain_domains(
    CoupledLabelledDomainHandle handle);
PortsHandle CoupledLabelledDomain_labels(CoupledLabelledDomainHandle handle);
LabelledDomainHandle CoupledLabelledDomain_get_domain(
    CoupledLabelledDomainHandle handle, InstrumentPortHandle search);
CoupledLabelledDomainHandle CoupledLabelledDomain_intersection(
    CoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle other);
void   CoupledLabelledDomain_push_back(CoupledLabelledDomainHandle handle,
                                       LabelledDomainHandle        value);
size_t CoupledLabelledDomain_size(CoupledLabelledDomainHandle handle);
bool   CoupledLabelledDomain_empty(CoupledLabelledDomainHandle handle);
void   CoupledLabelledDomain_erase_at(CoupledLabelledDomainHandle handle,
                                      size_t                      idx);
void   CoupledLabelledDomain_clear(CoupledLabelledDomainHandle handle);
LabelledDomainHandle CoupledLabelledDomain_const_at(
    CoupledLabelledDomainHandle handle, size_t idx);
LabelledDomainHandle CoupledLabelledDomain_at(
    CoupledLabelledDomainHandle handle, size_t idx);
ListLabelledDomainHandle CoupledLabelledDomain_items(
    CoupledLabelledDomainHandle handle);
bool   CoupledLabelledDomain_contains(CoupledLabelledDomainHandle handle,
                                      LabelledDomainHandle        value);
size_t CoupledLabelledDomain_index(CoupledLabelledDomainHandle handle,
                                   LabelledDomainHandle        value);
bool   CoupledLabelledDomain_equal(CoupledLabelledDomainHandle a,
                                   CoupledLabelledDomainHandle b);
bool   CoupledLabelledDomain_not_equal(CoupledLabelledDomainHandle a,
                                       CoupledLabelledDomainHandle b);

// Serialization (from Song)
StringHandle CoupledLabelledDomain_to_json_string(
    CoupledLabelledDomainHandle handle);
CoupledLabelledDomainHandle CoupledLabelledDomain_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
