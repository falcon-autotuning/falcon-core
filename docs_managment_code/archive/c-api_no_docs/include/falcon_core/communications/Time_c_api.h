#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* TimeHandle;

// Constructors
TimeHandle Time_create_now();
TimeHandle Time_create_at(long long micro_seconds_since_epoch);

// Destructor
void Time_destroy(TimeHandle handle);

// Methods
long long    Time_micro_seconds_since_epoch(TimeHandle handle);
long long    Time_time(TimeHandle handle);
StringHandle Time_to_string(TimeHandle handle);
bool         Time_equal(TimeHandle a, TimeHandle b);
bool         Time_not_equal(TimeHandle a, TimeHandle b);

// Serialization (from Song)
StringHandle Time_to_json_string(TimeHandle handle);
TimeHandle   Time_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
