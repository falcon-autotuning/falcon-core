#include "falcon_core/generic/Pair_c_api.h"

#include <falcon_core/generic/Pair.hpp>

// Generate implementations
#define X(T1, T2, NAME)                                                        \
  Pair##NAME##Handle Pair##NAME##_create(T1 first, T2 second) {                \
    return new falcon_core::generic::Pair<T1, T2>(first, second);              \
  }                                                                            \
  void Pair##NAME##_destroy(Pair##NAME##Handle handle) {                       \
    delete static_cast<falcon_core::generic::Pair<T1, T2>*>(handle);           \
  }                                                                            \
  T1 Pair##NAME##_first(Pair##NAME##Handle handle) {                           \
    return static_cast<falcon_core::generic::Pair<T1, T2>*>(handle)->first();  \
  }                                                                            \
  T2 Pair##NAME##_second(Pair##NAME##Handle handle) {                          \
    return static_cast<falcon_core::generic::Pair<T1, T2>*>(handle)->second(); \
  }                                                                            \
  bool Pair##NAME##_equal(Pair##NAME##Handle a, Pair##NAME##Handle b) {        \
    return *(static_cast<falcon_core::generic::Pair<T1, T2>*>(a)) ==           \
           *(static_cast<falcon_core::generic::Pair<T1, T2>*>(b));             \
  }                                                                            \
  bool Pair##NAME##_not_equal(Pair##NAME##Handle a, Pair##NAME##Handle b) {    \
    return !Pair##NAME##_equal(a, b);                                          \
  }

PAIR_TYPES
#undef X
