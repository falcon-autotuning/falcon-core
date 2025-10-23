#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
typedef void* GnameHandle;

// Constructors
GnameHandle Gname_create_from_num(int num);
GnameHandle Gname_create(const char* name);

// Destructor
void Gname_destroy(GnameHandle handle);

// Methods
const char* Gname_gname(GnameHandle handle);
bool        Gname_equal(GnameHandle a, GnameHandle b);
bool        Gname_not_equal(GnameHandle a, GnameHandle b);

// Serialization (from Song)
const char* Gname_to_json_string(GnameHandle handle);
GnameHandle Gname_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif
