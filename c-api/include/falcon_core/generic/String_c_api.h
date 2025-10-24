#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <cstddef>
struct string {
  char*  raw;
  size_t length;
};

typedef struct string* StringHandle;
// Constructors
StringHandle String_create(const char* raw, size_t length);

// Destructor
void String_destroy(StringHandle handle);
#ifdef __cplusplus
}
#endif
