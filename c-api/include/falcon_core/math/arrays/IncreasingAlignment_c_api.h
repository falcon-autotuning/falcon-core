#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* IncreasingAlignmentHandle;

// Constructors
IncreasingAlignmentHandle IncreasingAlignment_create_empty();
IncreasingAlignmentHandle IncreasingAlignment_create(bool alignment);

// Destructor
void IncreasingAlignment_destroy(IncreasingAlignmentHandle handle);

// Methods
/* AUTO-DOC from cpp: IncreasingAlignment_alignment | falcon_core::math::arrays::IncreasingAlignment::alignment */
/**
 * @brief Return the alignment of the domain.
 */
int  IncreasingAlignment_alignment(IncreasingAlignmentHandle handle);
bool IncreasingAlignment_equal(IncreasingAlignmentHandle a,
                               IncreasingAlignmentHandle b);
bool IncreasingAlignment_not_equal(IncreasingAlignmentHandle a,
                                   IncreasingAlignmentHandle b);

// Serialization (from Song)
StringHandle IncreasingAlignment_to_json_string(
    IncreasingAlignmentHandle handle);
IncreasingAlignmentHandle IncreasingAlignment_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
