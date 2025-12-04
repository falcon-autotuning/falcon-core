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
/* AUTO-DOC from cpp: Time_micro_seconds_since_epoch |
 * falcon_core::communications::Time::micro_seconds_since_epoch */
/**
 * @brief Get the time in microseconds since epoch.
 * @return The time in microseconds since epoch.
 */
long long Time_micro_seconds_since_epoch(TimeHandle handle);
// @category:read
/* AUTO-DOC from cpp: Time_time | falcon_core::communications::Time::time */
/**
 * @brief Get the time in seconds since epoch.
 * @return The time in seconds since epoch.
 */
long long Time_time(TimeHandle handle);
// @category:read
/* AUTO-DOC from cpp: Time_to_string |
 * falcon_core::communications::Time::to_string */
/**
 * @brief Convert the Time to a human-readable string.
 * @return A string representation of the Time.
 */
StringHandle Time_to_string(TimeHandle handle);
// @category:read
bool Time_equal(TimeHandle a, TimeHandle b);
// @category:read
bool Time_not_equal(TimeHandle a, TimeHandle b);
// @category:read
StringHandle Time_to_json_string(TimeHandle handle);
// @category:allocation
TimeHandle Time_from_json_string(StringHandle json);
bool       Time_equal(TimeHandle a, TimeHandle b);
bool       Time_not_equal(TimeHandle a, TimeHandle b);

#ifdef __cplusplus
}
#endif
