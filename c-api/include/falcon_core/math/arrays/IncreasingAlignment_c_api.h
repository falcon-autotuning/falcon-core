#pragma once
#include "ControlArray_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/export.h"
#include "falcon_core/generic/String_c_api.h"
typedef void* IncreasingAlignmentHandle;

// @category:allocation
FALCON_CORE_C_API IncreasingAlignmentHandle
IncreasingAlignment_copy(IncreasingAlignmentHandle handle);
// @category:deallocation
FALCON_CORE_C_API void IncreasingAlignment_destroy(
    IncreasingAlignmentHandle handle);
// @category:read
FALCON_CORE_C_API bool IncreasingAlignment_equal(
    IncreasingAlignmentHandle handle, IncreasingAlignmentHandle other);
// @category:read
FALCON_CORE_C_API bool IncreasingAlignment_not_equal(
    IncreasingAlignmentHandle handle, IncreasingAlignmentHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
IncreasingAlignment_to_json_string(IncreasingAlignmentHandle handle);
// @category:allocation
FALCON_CORE_C_API IncreasingAlignmentHandle
IncreasingAlignment_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API IncreasingAlignmentHandle IncreasingAlignment_create_empty();
// @category:allocation
FALCON_CORE_C_API IncreasingAlignmentHandle
IncreasingAlignment_create(bool alignment);

// @category:read
/* AUTO-DOC from cpp: IncreasingAlignment_alignment |
 * falcon_core::math::arrays::IncreasingAlignment::alignment */
/**
 * @brief Return the alignment of the domain.
 */
FALCON_CORE_C_API int IncreasingAlignment_alignment(
    IncreasingAlignmentHandle handle);

#ifdef __cplusplus
}
#endif
