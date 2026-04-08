#include "falcon-core/generic/String_c_api.h"

#include <cstdlib>
#include <cstring>

extern "C" {

StringHandle String_create(const char* raw, size_t length) {
  StringHandle out = (StringHandle)malloc(sizeof(struct string));
  out->length      = length;
  out->raw         = (char*)malloc(length + 1);
  memcpy(out->raw, raw, length);
  out->raw[length] = '\0';  // Null-terminate
  return out;
}

StringHandle String_wrap(const char* raw) {
  size_t       length = strlen(raw);
  StringHandle out    = (StringHandle)malloc(sizeof(struct string));
  out->length         = length;
  out->raw            = (char*)malloc(length + 1);
  memcpy(out->raw, raw, length + 1);  // includes null terminator
  return out;
}

void String_destroy(StringHandle handle) {
  if (handle) {
    free(handle->raw);
    free(handle);
  }
}
}
