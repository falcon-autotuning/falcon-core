#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/generic/ListLabelledDomain_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/Ports_c_api.h"
#include "falcon-core/math/domains/LabelledDomain_c_api.h"
typedef void* CoupledLabelledDomainHandle;

// @category:allocation
FALCON_CORE_C_API CoupledLabelledDomainHandle
CoupledLabelledDomain_copy(CoupledLabelledDomainHandle handle);
// @category:deallocation
FALCON_CORE_C_API void CoupledLabelledDomain_destroy(
    CoupledLabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API bool CoupledLabelledDomain_equal(
    CoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle other);
// @category:read
FALCON_CORE_C_API bool CoupledLabelledDomain_not_equal(
    CoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
CoupledLabelledDomain_to_json_string(CoupledLabelledDomainHandle handle);
// @category:allocation
FALCON_CORE_C_API CoupledLabelledDomainHandle
CoupledLabelledDomain_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API CoupledLabelledDomainHandle
CoupledLabelledDomain_create_empty();
// @category:allocation
FALCON_CORE_C_API CoupledLabelledDomainHandle
CoupledLabelledDomain_create(ListLabelledDomainHandle items);
// @category:read
/* AUTO-DOC from cpp: CoupledLabelledDomain_domains |
 * falcon_core::math::domains::CoupledLabelledDomain::domains */
/**
 * @brief Get all domains.
 */
FALCON_CORE_C_API ListLabelledDomainHandle
CoupledLabelledDomain_domains(CoupledLabelledDomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: CoupledLabelledDomain_labels |
 * falcon_core::math::domains::CoupledLabelledDomain::labels */
/**
 * @brief Get all labels.
 * @return Vector of shared pointers to labels.
 */
FALCON_CORE_C_API PortsHandle
CoupledLabelledDomain_labels(CoupledLabelledDomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: CoupledLabelledDomain_get_domain |
 * falcon_core::math::domains::CoupledLabelledDomain::get_domain */
/**
 * @brief Get domain by label.
 * @param search Shared pointer to label to search for.
 * @return Shared pointer to the matching domain.
 * @throws std::runtime_error if not found.
 */
FALCON_CORE_C_API LabelledDomainHandle CoupledLabelledDomain_get_domain(
    CoupledLabelledDomainHandle handle, InstrumentPortHandle search);
// @category:read
FALCON_CORE_C_API CoupledLabelledDomainHandle
CoupledLabelledDomain_intersection(CoupledLabelledDomainHandle handle,
                                   CoupledLabelledDomainHandle other);
// @category:write
FALCON_CORE_C_API void CoupledLabelledDomain_push_back(
    CoupledLabelledDomainHandle handle, LabelledDomainHandle value);
// @category:read
FALCON_CORE_C_API size_t
CoupledLabelledDomain_size(CoupledLabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API bool CoupledLabelledDomain_empty(
    CoupledLabelledDomainHandle handle);
// @category:write
FALCON_CORE_C_API void CoupledLabelledDomain_erase_at(
    CoupledLabelledDomainHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void CoupledLabelledDomain_clear(
    CoupledLabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API LabelledDomainHandle
CoupledLabelledDomain_const_at(CoupledLabelledDomainHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API LabelledDomainHandle
CoupledLabelledDomain_at(CoupledLabelledDomainHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API ListLabelledDomainHandle
CoupledLabelledDomain_items(CoupledLabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API bool CoupledLabelledDomain_contains(
    CoupledLabelledDomainHandle handle, LabelledDomainHandle value);
// @category:read
FALCON_CORE_C_API size_t CoupledLabelledDomain_index(
    CoupledLabelledDomainHandle handle, LabelledDomainHandle value);

#ifdef __cplusplus
}
#endif
