

# File Adjacency\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**core**](dir_2d9342c5d4579911ee06a50b57a946ed.md) **>** [**Adjacency\_c\_api.h**](Adjacency__c__api_8h.md)

[Go to the documentation of this file](Adjacency__c__api_8h.md)


```C++
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
bool Adjacency_equal(AdjacencyHandle handle, AdjacencyHandle other);
// @category:read
bool Adjacency_not_equal(AdjacencyHandle handle, AdjacencyHandle other);
// @category:read
StringHandle Adjacency_to_json_string(AdjacencyHandle handle);
// @category:allocation
AdjacencyHandle Adjacency_from_json_string(StringHandle json);
// @category:allocation
AdjacencyHandle Adjacency_create(const int*        data,
                                 const size_t*     shape,
                                 const size_t      ndim,
                                 ConnectionsHandle indexes);
/* AUTO-DOC from cpp: Adjacency_indexes |
 * falcon_core::physics::config::core::Adjacency::indexes */
ConnectionsHandle Adjacency_indexes(AdjacencyHandle handle);
// @category:read
ConnectionsHandle Adjacency_indexes(AdjacencyHandle handle);
// @category:read
/* AUTO-DOC from cpp: Adjacency_get_true_pairs |
 * falcon_core::physics::config::core::Adjacency::get_true_pairs */
ListPairSizeTSizeTHandle Adjacency_get_true_pairs(AdjacencyHandle handle);
// @category:read
size_t Adjacency_size(AdjacencyHandle handle);
// @category:read
size_t Adjacency_dimension(AdjacencyHandle handle);
// @category:read
size_t Adjacency_shape(AdjacencyHandle handle, size_t* out_buffer, size_t ndim);
// @category:read
size_t Adjacency_data(AdjacencyHandle handle, int* out_buffer, size_t numdata);
// @category:write
void Adjacency_times_equals_farray(AdjacencyHandle handle,
                                   FArrayIntHandle other);
// @category:read
AdjacencyHandle Adjacency_times_farray(AdjacencyHandle handle,
                                       FArrayIntHandle other);
// @category:read
int Adjacency_sum(AdjacencyHandle handle);
// @category:read
ListListSizeTHandle Adjacency_where(AdjacencyHandle handle, int value);
// @category:read
AdjacencyHandle Adjacency_flip(AdjacencyHandle handle, size_t axis);

#ifdef __cplusplus
}
#endif
```


