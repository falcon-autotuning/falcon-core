#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* IncreasingAlignmentHandle;

// @category:allocation
IncreasingAlignmentHandle IncreasingAlignment_create_empty();
// @category:allocation
IncreasingAlignmentHandle IncreasingAlignment_create(bool alignment);

// @category:deallocation
void IncreasingAlignment_destroy(IncreasingAlignmentHandle handle);

// @category:read
/* AUTO-DOC from cpp: IncreasingAlignment_alignment | falcon_core::math::arrays::IncreasingAlignment::alignment */
/**
 * @brief Return the alignment of the domain.
 */
int IncreasingAlignment_alignment(IncreasingAlignmentHandle handle);
// @category:read
bool IncreasingAlignment_equal(IncreasingAlignmentHandle a,
                               IncreasingAlignmentHandle b);
// @category:read
bool IncreasingAlignment_not_equal(IncreasingAlignmentHandle a,
                                   IncreasingAlignmentHandle b);
// @category:read
StringHandle IncreasingAlignment_to_json_string(
    IncreasingAlignmentHandle handle);
// @category:allocation
IncreasingAlignmentHandle IncreasingAlignment_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
