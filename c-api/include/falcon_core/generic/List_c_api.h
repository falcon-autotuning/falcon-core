#include <cstddef>
#include <vector>
#ifdef __cplusplus
extern "C" {
#endif

// Define all the type pairs you need
// 1 the actual type
// 2 the stored type of the primitive in the list
// 3 the name append to the "List"
#define LIST_TYPES       \
  X(int, int, Int)       \
  X(float, float, Float) \
  /* Add more as needed */

// Generate typedefs
#define X(T, StoredT, NAME) typedef void* List##NAME##Handle;
LIST_TYPES
#undef X

// Generate function declarations
#define X(T, StoredT, NAME)                                                       \
  List##NAME##Handle List##NAME##_create_empty();                                 \
  List##NAME##Handle List##NAME##_allocate(size_t count);                         \
  List##NAME##Handle List##NAME##_fill_value(size_t        count,                 \
                                             const StoredT value);                \
  List##NAME##Handle List##NAME##_create(const std::vector<StoredT> count);       \
  void   List##NAME##_push_back(List##NAME##Handle handle, const StoredT value);  \
  size_t List##NAME##_size(List##NAME##Handle handle);                            \
  bool   List##NAME##_empty(List##NAME##Handle handle);                           \
  void   List##NAME##_erase_at(List##NAME##Handle handle, size_t idx);            \
  void   List##NAME##_clear(List##NAME##Handle handle);                           \
  const StoredT List##NAME##_const_at(List##NAME##Handle handle,                  \
                                      const size_t       idx);                          \
  StoredT       List##NAME##_at(List##NAME##Handle handle, const size_t idx);     \
  size_t        List##NAME##_items(                                               \
      List##NAME##Handle handle, StoredT* out_buffer, size_t buffer_size); \
  bool   List##NAME##_contains(List##NAME##Handle handle, const StoredT value);   \
  size_t List##NAME##_index(List##NAME##Handle handle, const StoredT value);      \
  List##NAME##Handle List##NAME##_intersection(List##NAME##Handle handle,         \
                                               List##NAME##Handle other);         \
  bool List##NAME##_equal(List##NAME##Handle a, List##NAME##Handle b);            \
  bool List##NAME##_not_equal(List##NAME##Handle a, List##NAME##Handle b);
LIST_TYPES
#undef X

#ifdef __cplusplus
}
#endif
