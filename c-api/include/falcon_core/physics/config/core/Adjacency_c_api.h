#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/generic/FArrayInt_c_api.h"
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/ListPairSizeTSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"

typedef void* AdjacencyHandle;

// @category:allocation
AdjacencyHandle Adjacency_copy(AdjacencyHandle handle);
// @category:deallocation
void Adjacency_destroy(AdjacencyHandle handle);
// @category:read
FALCON_CORE_C_API bool Adjacency_equal(AdjacencyHandle handle,
                                       AdjacencyHandle other);
// @category:read
FALCON_CORE_C_API bool Adjacency_not_equal(AdjacencyHandle handle,
                                           AdjacencyHandle other);
// @category:read
FALCON_CORE_C_API StringHandle Adjacency_to_json_string(AdjacencyHandle handle);
// @category:allocation
FALCON_CORE_C_API AdjacencyHandle Adjacency_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API AdjacencyHandle Adjacency_create(const int*        data,
                                                   const size_t*     shape,
                                                   const size_t      ndim,
                                                   ConnectionsHandle indexes);
/* AUTO-DOC from cpp: Adjacency_indexes |
 * falcon_core::physics::config::core::Adjacency::indexes */
/**
 * # @brief Returns the indexes of the gates in the order for the adjacency
 *    matrix
 */
FALCON_CORE_C_API ConnectionsHandle Adjacency_indexes(AdjacencyHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionsHandle Adjacency_indexes(AdjacencyHandle handle);
// @category:read
/* AUTO-DOC from cpp: Adjacency_get_true_pairs |
 * falcon_core::physics::config::core::Adjacency::get_true_pairs */
/**
 * @brief Returns the pairs of indexes where the adjacency matrix is true (1)
 */
FALCON_CORE_C_API ListPairSizeTSizeTHandle
Adjacency_get_true_pairs(AdjacencyHandle handle);
// @category:read
FALCON_CORE_C_API size_t Adjacency_size(AdjacencyHandle handle);
// @category:read
FALCON_CORE_C_API size_t Adjacency_dimension(AdjacencyHandle handle);
// @category:read
FALCON_CORE_C_API size_t Adjacency_shape(AdjacencyHandle handle,
                                         size_t*         out_buffer,
                                         size_t          ndim);
// @category:read
FALCON_CORE_C_API size_t Adjacency_data(AdjacencyHandle handle,
                                        int*            out_buffer,
                                        size_t          numdata);
// @category:write
FALCON_CORE_C_API void Adjacency_times_equals_farray(AdjacencyHandle handle,
                                                     FArrayIntHandle other);
// @category:read
FALCON_CORE_C_API AdjacencyHandle Adjacency_times_farray(AdjacencyHandle handle,
                                                         FArrayIntHandle other);
// @category:read
FALCON_CORE_C_API int Adjacency_sum(AdjacencyHandle handle);
// @category:read
FALCON_CORE_C_API ListListSizeTHandle Adjacency_where(AdjacencyHandle handle,
                                                      int             value);
// @category:read
FALCON_CORE_C_API AdjacencyHandle Adjacency_flip(AdjacencyHandle handle,
                                                 size_t          axis);

#ifdef __cplusplus
}
#endif
