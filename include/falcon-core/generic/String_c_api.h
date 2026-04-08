#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon-core/export_c_api.h"
struct string {
  char*  raw;
  size_t length;
};

typedef struct string* StringHandle;
// @category:allocation
FALCON_CORE_C_API StringHandle String_create(const char* raw, size_t length);
// @category:allocation
FALCON_CORE_C_API StringHandle String_wrap(const char* raw);
// @category:deallocation
FALCON_CORE_C_API void String_destroy(StringHandle handle);
#ifdef __cplusplus
}
#endif
