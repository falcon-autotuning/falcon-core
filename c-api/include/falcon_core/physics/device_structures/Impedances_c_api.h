#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListImpedance_c_api.h"
typedef void* ImpedancesHandle;

// @category:allocation
FALCON_CORE_C_API ImpedancesHandle Impedances_copy(ImpedancesHandle handle);
// @category:deallocation
FALCON_CORE_C_API void Impedances_destroy(ImpedancesHandle handle);
// @category:read
FALCON_CORE_C_API bool Impedances_equal(ImpedancesHandle handle,
                                        ImpedancesHandle other);
// @category:read
FALCON_CORE_C_API bool Impedances_not_equal(ImpedancesHandle handle,
                                            ImpedancesHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
Impedances_to_json_string(ImpedancesHandle handle);
// @category:allocation
FALCON_CORE_C_API ImpedancesHandle
Impedances_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API ImpedancesHandle Impedances_create_empty();
// @category:allocation
FALCON_CORE_C_API ImpedancesHandle Impedances_create(ListImpedanceHandle items);
// @category:write
FALCON_CORE_C_API void Impedances_push_back(ImpedancesHandle handle,
                                            ImpedanceHandle  value);
// @category:read
FALCON_CORE_C_API size_t Impedances_size(ImpedancesHandle handle);
// @category:read
FALCON_CORE_C_API bool Impedances_empty(ImpedancesHandle handle);
// @category:write
FALCON_CORE_C_API void Impedances_erase_at(ImpedancesHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void Impedances_clear(ImpedancesHandle handle);
// @category:read
FALCON_CORE_C_API ImpedanceHandle Impedances_at(ImpedancesHandle handle,
                                                size_t           idx);
// @category:read
FALCON_CORE_C_API ListImpedanceHandle Impedances_items(ImpedancesHandle handle);
// @category:read
FALCON_CORE_C_API bool Impedances_contains(ImpedancesHandle handle,
                                           ImpedanceHandle  value);
// @category:read
FALCON_CORE_C_API ImpedancesHandle
Impedances_intersection(ImpedancesHandle handle, ImpedancesHandle other);
// @category:read
FALCON_CORE_C_API size_t Impedances_index(ImpedancesHandle handle,
                                          ImpedanceHandle  value);

#ifdef __cplusplus
}
#endif
