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

// Forward declarations for opaque handles
typedef void* AdjacencyHandle;
// Function declarations

// Constructors
AdjacencyHandle Adjacency_create(const int*        data,
                                 const size_t*     shape,
                                 size_t            ndim,
                                 ConnectionsHandle indexes);

// Destructor
void Adjacency_destroy(AdjacencyHandle handle);

// Methods
ConnectionsHandle        Adjacency_indexes(AdjacencyHandle handle);
ListPairSizeTSizeTHandle Adjacency_get_true_pairs(AdjacencyHandle handle);
size_t                   Adjacency_size(AdjacencyHandle handle);
size_t                   Adjacency_dimension(AdjacencyHandle handle);
size_t Adjacency_shape(AdjacencyHandle handle, size_t* out_buffer, size_t ndim);
size_t Adjacency_data(AdjacencyHandle handle, int* out_buffer, size_t numdata);
void   Adjacency_timesequals_farray(AdjacencyHandle handle,
                                    FArrayIntHandle other);
AdjacencyHandle Adjacency_times_farray(AdjacencyHandle handle,
                                       FArrayIntHandle other);
bool Adjacency_equality(AdjacencyHandle handle, AdjacencyHandle other);
bool Adjacency_notequality(AdjacencyHandle handle, AdjacencyHandle other);
int  Adjacency_sum(AdjacencyHandle handle);
ListListSizeTHandle Adjacency_where(AdjacencyHandle handle, const int value);
AdjacencyHandle     Adjacency_flip(AdjacencyHandle handle, size_t axis);

// Serialization (from Song)
StringHandle    Adjacency_to_json_string(AdjacencyHandle handle);
AdjacencyHandle Adjacency_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
