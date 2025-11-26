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
// @category:allocation
StringHandle String_create(const char* raw, size_t length);
// @category:allocation
StringHandle String_wrap(const char* raw);
// @category:deallocation
void String_destroy(StringHandle handle);
#ifdef __cplusplus
}
#endif
