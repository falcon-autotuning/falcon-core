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
StringHandle String_create(const char* raw, size_t length);
StringHandle String_wrap(const char* raw);

// Destructor
void String_destroy(StringHandle handle);
#ifdef __cplusplus
}
#endif
