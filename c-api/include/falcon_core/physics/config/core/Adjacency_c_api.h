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
AdjacencyHandle Adjacency_create(const int*        data,
                                 const size_t*     shape,
                                 const size_t      ndim,
                                 ConnectionsHandle indexes);
// @category:deallocation
void              Adjacency_destroy(AdjacencyHandle handle);
ConnectionsHandle Adjacency_indexes(AdjacencyHandle handle);
// @category:read
ConnectionsHandle Adjacency_indexes(AdjacencyHandle handle);
// @category:read
ListPairSizeTSizeTHandle Adjacency_get_true_pairs(AdjacencyHandle handle);
// @category:read
size_t Adjacency_size(AdjacencyHandle handle);
// @category:read
size_t Adjacency_dimension(AdjacencyHandle handle);
// @category:read
size_t Adjacency_shape(AdjacencyHandle handle,
                       const size_t*   out_buffer,
                       size_t          ndim);
// @category:read
size_t Adjacency_data(AdjacencyHandle handle,
                      const int*      out_buffer,
                      size_t          numdata);
// @category:write
void Adjacency_timesequals_farray(AdjacencyHandle handle,
                                  FArrayIntHandle other);
// @category:read
AdjacencyHandle Adjacency_times_farray(AdjacencyHandle handle,
                                       FArrayIntHandle other);
// @category:read
bool Adjacency_equality(AdjacencyHandle handle, AdjacencyHandle other);
// @category:read
bool Adjacency_notequality(AdjacencyHandle handle, AdjacencyHandle other);
// @category:read
int Adjacency_sum(AdjacencyHandle handle);
// @category:read
ListListSizeTHandle Adjacency_where(AdjacencyHandle handle, int value);
// @category:read
AdjacencyHandle Adjacency_flip(AdjacencyHandle handle, size_t axis);
// @category:read
StringHandle Adjacency_to_json_string(AdjacencyHandle handle);
// @category:allocation
AdjacencyHandle Adjacency_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
