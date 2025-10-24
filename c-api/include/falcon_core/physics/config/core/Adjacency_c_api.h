#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <cstddef>

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
void Adjacency_plusequals_farray(AdjacencyHandle handle, FArrayIntHandle other);
void Adjacency_plusequals_double(AdjacencyHandle handle, const double other);
void Adjacency_plusequals_int(AdjacencyHandle handle, const int other);
AdjacencyHandle Adjacency_plus_farray(AdjacencyHandle handle,
                                      FArrayIntHandle other);
AdjacencyHandle Adjacency_plus_double(AdjacencyHandle handle,
                                      const double    other);
AdjacencyHandle Adjacency_plus_int(AdjacencyHandle handle, const int other);
void            Adjacency_minusequals_farray(AdjacencyHandle handle,
                                             FArrayIntHandle other);
void Adjacency_minusequals_double(AdjacencyHandle handle, const double other);
void Adjacency_minusequals_int(AdjacencyHandle handle, const int other);
AdjacencyHandle Adjacency_minus_farray(AdjacencyHandle handle,
                                       FArrayIntHandle other);
AdjacencyHandle Adjacency_minus_double(AdjacencyHandle handle,
                                       const double    other);
AdjacencyHandle Adjacency_minus_int(AdjacencyHandle handle, const int other);
AdjacencyHandle Adjacency_negation(AdjacencyHandle handle);
void            Adjacency_timesequals_farray(AdjacencyHandle handle,
                                             FArrayIntHandle other);
void Adjacency_timesequals_double(AdjacencyHandle handle, const double other);
void Adjacency_timesequals_int(AdjacencyHandle handle, const int other);
AdjacencyHandle Adjacency_times_farray(AdjacencyHandle handle,
                                       FArrayIntHandle other);
AdjacencyHandle Adjacency_times_double(AdjacencyHandle handle,
                                       const double    other);
AdjacencyHandle Adjacency_times_int(AdjacencyHandle handle, const int other);
void            Adjacency_dividesequals_farray(AdjacencyHandle handle,
                                               FArrayIntHandle other);
void Adjacency_dividesequals_double(AdjacencyHandle handle, const double other);
void Adjacency_dividesequals_int(AdjacencyHandle handle, const int other);
AdjacencyHandle Adjacency_divides_farray(AdjacencyHandle handle,
                                         FArrayIntHandle other);
AdjacencyHandle Adjacency_divides_double(AdjacencyHandle handle,
                                         const double    other);
AdjacencyHandle Adjacency_divides_int(AdjacencyHandle handle, const int other);
AdjacencyHandle Adjacency_pow(AdjacencyHandle handle, const double other);
AdjacencyHandle Adjacency_abs(AdjacencyHandle handle);
AdjacencyHandle Adjacency_min(AdjacencyHandle handle);
AdjacencyHandle Adjacency_min_arraywise(AdjacencyHandle handle,
                                        FArrayIntHandle other);
AdjacencyHandle Adjacency_max(AdjacencyHandle handle);
AdjacencyHandle Adjacency_max_arraywise(AdjacencyHandle handle,
                                        FArrayIntHandle other);
bool Adjacency_equality(AdjacencyHandle handle, AdjacencyHandle other);
bool Adjacency_notequality(AdjacencyHandle handle, AdjacencyHandle other);
bool Adjacency_greaterthan(AdjacencyHandle handle, const int value);
bool Adjacency_lessthan(AdjacencyHandle handle, const int value);
void Adjacency_remove_offset(AdjacencyHandle handle, const int offset);
int  Adjacency_sum(AdjacencyHandle handle);
AdjacencyHandle     Adjacency_reshape(AdjacencyHandle handle,
                                      const size_t*   shape,
                                      size_t          ndims);
ListListSizeTHandle Adjacency_where(AdjacencyHandle handle, const int value);
AdjacencyHandle     Adjacency_flip(AdjacencyHandle handle, size_t axis);
size_t              Adjacency_full_gradient(AdjacencyHandle  handle,
                                            FArrayIntHandle* out_buffer,
                                            size_t           buffer_size);
AdjacencyHandle     Adjacency_gradient(AdjacencyHandle handle, size_t axis);
double              Adjacency_get_sum_of_squares(AdjacencyHandle handle);
double Adjacency_get_summed_diff_int_of_squares(AdjacencyHandle handle,
                                                const int       other);
double Adjacency_get_summed_diff_double_of_squares(AdjacencyHandle handle,
                                                   const double    other);
double Adjacency_get_summed_diff_array_of_squares(AdjacencyHandle handle,
                                                  FArrayIntHandle other);
// Serialization (from Song)
StringHandle    Adjacency_to_json_string(AdjacencyHandle handle);
AdjacencyHandle Adjacency_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
