#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* TimeHandle;

// @category:allocation
TimeHandle Time_create_now();
// @category:allocation
TimeHandle Time_create_at(long long micro_seconds_since_epoch);
// @category:deallocation
void Time_destroy(TimeHandle handle);
// @category:read
long long Time_micro_seconds_since_epoch(TimeHandle handle);
// @category:read
long long Time_time(TimeHandle handle);
// @category:read
StringHandle Time_to_string(TimeHandle handle);
// @category:read
bool Time_equal(TimeHandle a, TimeHandle b);
// @category:read
bool Time_not_equal(TimeHandle a, TimeHandle b);
// @category:read
StringHandle Time_to_json_string(TimeHandle handle);
// @category:allocation
TimeHandle Time_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
