#include "falcon_core/generic/List_c_api.h"

#include <falcon_core/generic/List.hpp>

// Generate implementations
#define X(T, StoredT, NAME)                                                    \
  List##NAME##Handle List##NAME##_create_empty() {                             \
    return new std::shared_ptr<falcon_core::generic::List<T>>(                 \
        std::make_shared<falcon_core::generic::List<T>>());                    \
  }                                                                            \
  List##NAME##Handle List##NAME##_allocate(size_t count) {                     \
    return new std::shared_ptr<falcon_core::generic::List<T>>(                 \
        std::make_shared<falcon_core::generic::List<T>>(count));               \
  }                                                                            \
  List##NAME##Handle List##NAME##_fill_value(size_t        count,              \
                                             const StoredT value) {            \
    return new std::shared_ptr<falcon_core::generic::List<T>>(                 \
        std::make_shared<falcon_core::generic::List<T>>(count, value));        \
  }                                                                            \
  List##NAME##Handle List##NAME##_create(const std::vector<StoredT> vec) {     \
    return new std::shared_ptr<falcon_core::generic::List<T>>(                 \
        std::make_shared<falcon_core::generic::List<T>>(vec));                 \
  }                                                                            \
  void List##NAME##_destroy(List##NAME##Handle handle) {                       \
    delete static_cast<std::shared_ptr<falcon_core::generic::List<T>>*>(       \
        handle);                                                               \
  }                                                                            \
  void List##NAME##_push_back(List##NAME##Handle handle,                       \
                              const StoredT      value) {                           \
    (*static_cast<std::shared_ptr<falcon_core::generic::List<T>>*>(handle))    \
        ->push_back(value);                                                    \
  }                                                                            \
  size_t List##NAME##_size(List##NAME##Handle handle) {                        \
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<T>>*>(     \
                handle))                                                       \
        ->size();                                                              \
  }                                                                            \
  bool List##NAME##_empty(List##NAME##Handle handle) {                         \
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<T>>*>(     \
                handle))                                                       \
        ->empty();                                                             \
  }                                                                            \
  void List##NAME##_erase_at(List##NAME##Handle handle, size_t idx) {          \
    (*static_cast<std::shared_ptr<falcon_core::generic::List<T>>*>(handle))    \
        ->erase_at(idx);                                                       \
  }                                                                            \
  void List##NAME##_clear(List##NAME##Handle handle) {                         \
    (*static_cast<std::shared_ptr<falcon_core::generic::List<T>>*>(handle))    \
        ->clear();                                                             \
  }                                                                            \
  const StoredT List##NAME##_const_at(List##NAME##Handle handle,               \
                                      const size_t       idx) {                      \
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<T>>*>(     \
                handle))                                                       \
        ->at(idx);                                                             \
  }                                                                            \
  StoredT List##NAME##_at(List##NAME##Handle handle, const size_t idx) {       \
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<T>>*>(     \
                handle))                                                       \
        ->at(idx);                                                             \
  }                                                                            \
  size_t List##NAME##_items(                                                   \
      List##NAME##Handle handle, StoredT* out_buffer, size_t buffer_size) {    \
    auto& list =                                                               \
        *static_cast<std::shared_ptr<falcon_core::generic::List<T>>*>(handle); \
    size_t n = std::min(buffer_size, list->items().size());                    \
    std::copy_n(list->items().begin(), n, out_buffer);                         \
    return n;                                                                  \
  }                                                                            \
  bool List##NAME##_contains(List##NAME##Handle handle, const StoredT value) { \
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<T>>*>(     \
                handle))                                                       \
        ->contains(value);                                                     \
  }                                                                            \
  size_t List##NAME##_index(List##NAME##Handle handle, const StoredT value) {  \
    return (*static_cast<std::shared_ptr<falcon_core::generic::List<T>>*>(     \
                handle))                                                       \
        ->index(value);                                                        \
  }                                                                            \
  List##NAME##Handle List##NAME##_intersection(List##NAME##Handle handle,      \
                                               List##NAME##Handle other) {     \
    auto& listA =                                                              \
        *static_cast<std::shared_ptr<falcon_core::generic::List<T>>*>(handle); \
    auto& listB =                                                              \
        *static_cast<std::shared_ptr<falcon_core::generic::List<T>>*>(other);  \
    auto result = listA->intersection(listB);                                  \
    return new std::shared_ptr<falcon_core::generic::List<T>>(result);         \
  }                                                                            \
  bool List##NAME##_equal(List##NAME##Handle a, List##NAME##Handle b) {        \
    auto& listA =                                                              \
        *static_cast<std::shared_ptr<falcon_core::generic::List<T>>*>(a);      \
    auto& listB =                                                              \
        *static_cast<std::shared_ptr<falcon_core::generic::List<T>>*>(b);      \
    return *listA == *listB;                                                   \
  }                                                                            \
  bool List##NAME##_not_equal(List##NAME##Handle a, List##NAME##Handle b) {    \
    return !List##NAME##_equal(a, b);                                          \
  }

LIST_TYPES
#undef X
