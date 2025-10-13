// #pragma once
// #ifdef __cplusplus
// extern "C" {
// #endif
//
// #define DECLARE_PAIR_TYPE(NAME, T1, T2)                    \
//   typedef void* NAME##Handle;                              \
//   /* Constructors */                                       \
//   NAME##Handle NAME##_create(T1 first, T2 second);         \
//   /* Destructor */                                         \
//   void NAME##_destroy(NAME##Handle handle);                \
//   /* Methods */                                            \
//   T1   NAME##_first(NAME##Handle handle);                  \
//   T2   NAME##_second(NAME##Handle handle);                 \
//   bool NAME##_equal(NAME##Handle a, NAME##Handle b);       \
//   bool NAME##_not_equal(NAME##Handle a, NAME##Handle b);   \
//   /* Serialization (from Song) */                          \
//   const char*  NAME##_to_json_string(NAME##Handle handle); \
//   NAME##Handle NAME##_from_json_string(const char* json);
//
// #ifdef __cplusplus
// }
// #endif
//
// Pair_template.h
#ifdef __cplusplus
extern "C" {
#endif
#ifndef PAIR_TEMPLATE_HEADER_H
#define PAIR_TEMPLATE_HEADER_H

#include <stdbool.h>

#include <falcon_core/generic/Pair.hpp>

#endif  // PAIR_TEMPLATE_HEADER_H

#ifndef PAIR_T1
#error "PAIR_T1 must be defined"
#endif
#ifndef PAIR_T2
#error "PAIR_T2 must be defined"
#endif
#ifndef PAIR_HANDLE
#define PAIR_HANDLE pair_##PAIR_T1##_##PAIR_T2
#endif
#ifndef PAIR_PREFIX
#define PAIR_PREFIX PAIR_HANDLE##_
#endif

typedef void* PAIR_HANDLE;

// Constructors
#define PAIR_create PAIR_PREFIX##create
PAIR_HANDLE PAIR_create(PAIR_T1 first, PAIR_T2 second) {
  return new Pair<T1, T2>(first, second);
}

// Destructor
#define PAIR_destroy PAIR_PREFIX##destroy
void PAIR_destroy(PAIR_HANDLE handle) {
  delete static_cast<Pair<T1, T2>*>(handle);
}

// Methods
#define PAIR_first PAIR_PREFIX##first
PAIR_T1 PAIR_first(PAIR_HANDLE handle) {
  return static_cast<Pair<T1, T2>*>(handle)->first();
}
#define PAIR_second PAIR_PREFIX##second
PAIR_T1 PAIR_second(PAIR_HANDLE handle) {
  return static_cast<Pair<T1, T2>*>(handle)->second();
}
#define PAIR_equal PAIR_PREFIX##equal
bool PAIR_equal(PAIR_HANDLE a, PAIR_HANDLE b) {
  return *(static_cast<Pair<T1, T2>*>(a)) == *(static_cast<Pair<T1, T2>*>(b));
}
#define PAIR_not_equal PAIR_PREFIX##not_equal
bool PAIR_not_equal(PAIR_HANDLE a, PAIR_HANDLE b) {
  return *(static_cast<Pair<T1, T2>*>(a)) == *(static_cast<Pair<T1, T2>*>(b));
}
#endif

#undef PAIR_T1
#undef PAIR_T2
#undef PAIR_HANDLE
#undef PAIR_PREFIX
#undef PAIR_create
#undef PAIR_destroy
#undef PAIR_first
#undef PAIR_second
#undef PAIR_equal
#undef PAIR_not_equal
#endif
#ifdef __cplusplus
}
#endif
