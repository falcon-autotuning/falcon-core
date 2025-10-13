#include <cstddef>
#ifdef __cplusplus
extern "C" {
#endif

#include "falcon_core/generic/Pair_c_api.h"
// Define all the type pairs you need
// 1 the stored type of the key in the map
// 2 the stored type of the value in the map
// 3 the name append to the "Map"
#define MAP_TYPES             \
  X(int, int, IntInt)         \
  X(float, float, FloatFloat) \
  /* Add more as needed */

// Generate typedefs
#define X(StoredKey, StoredValue, NAME) typedef void* Map##NAME##Handle;
MAP_TYPES
#undef X

// Generate function declarations
#define X(StoredKey, StoredValue, NAME)                                          \
  Map##NAME##Handle Map##NAME##_create_empty();                                  \
  Map##NAME##Handle Map##NAME##_create(const List##Pair##NAME##Handle* data,     \
                                       size_t                          count);                            \
  void   Map##NAME##_push_back(Map##NAME##Handle handle, const StoredT value);   \
  size_t Map##NAME##_size(Map##NAME##Handle handle);                             \
  bool   Map##NAME##_empty(Map##NAME##Handle handle);                            \
  void   Map##NAME##_erase_at(Map##NAME##Handle handle, size_t idx);             \
  void   Map##NAME##_clear(Map##NAME##Handle handle);                            \
  const StoredT Map##NAME##_const_at(Map##NAME##Handle handle,                   \
                                     const size_t      idx);                          \
  StoredT       Map##NAME##_at(Map##NAME##Handle handle, const size_t idx);      \
  size_t        Map##NAME##_items(                                               \
      Map##NAME##Handle handle, StoredT* out_buffer, size_t buffer_size); \
  bool   Map##NAME##_contains(Map##NAME##Handle handle, const StoredT value);    \
  size_t Map##NAME##_index(Map##NAME##Handle handle, const StoredT value);       \
  Map##NAME##Handle Map##NAME##_intersection(Map##NAME##Handle handle,           \
                                             Map##NAME##Handle other);           \
  bool              Map##NAME##_equal(Map##NAME##Handle a, Map##NAME##Handle b); \
  bool Map##NAME##_not_equal(Map##NAME##Handle a, Map##NAME##Handle b);
MAP_TYPES
#undef X

#ifdef __cplusplus
}
#endif
