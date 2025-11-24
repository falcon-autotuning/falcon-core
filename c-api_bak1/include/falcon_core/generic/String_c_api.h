#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>
struct string {
  char*  raw;
  size_t length;
};

typedef struct string* StringHandle;
// Constructors
/* AUTO-DOC from cpp: String_create | falcon_core::generic::Pair::create */
/**
 * @brief (from C++: falcon_core::generic::Pair::create)
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
StringHandle String_create(const char* raw, size_t length);
StringHandle String_wrap(const char* raw);

// Destructor
void String_destroy(StringHandle handle);
#ifdef __cplusplus
}
#endif
