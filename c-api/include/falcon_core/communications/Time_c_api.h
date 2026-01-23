#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/export_c_api.h"
#include "falcon_core/generic/String_c_api.h"
typedef void* TimeHandle;

// @category:allocation
FALCON_CORE_C_API TimeHandle Time_copy(TimeHandle handle);
// @category:deallocation
FALCON_CORE_C_API void Time_destroy(TimeHandle handle);
// @category:read
FALCON_CORE_C_API bool Time_equal(TimeHandle handle, TimeHandle other);
// @category:read
FALCON_CORE_C_API bool Time_not_equal(TimeHandle handle, TimeHandle other);
// @category:read
FALCON_CORE_C_API StringHandle Time_to_json_string(TimeHandle handle);
// @category:allocation
FALCON_CORE_C_API TimeHandle Time_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API TimeHandle Time_create_now();
// @category:allocation
FALCON_CORE_C_API TimeHandle
Time_create_at(long long micro_seconds_since_epoch);
// @category:read
/* AUTO-DOC from cpp: Time_micro_seconds_since_epoch |
 * falcon_core::communications::Time::micro_seconds_since_epoch */
/**
 * @brief Get the time in microseconds since epoch.
 * @return The time in microseconds since epoch.
 */
FALCON_CORE_C_API long long Time_micro_seconds_since_epoch(TimeHandle handle);
// @category:read
/* AUTO-DOC from cpp: Time_time | falcon_core::communications::Time::time */
/**
 * @brief Get the time in seconds since epoch.
 * @return The time in seconds since epoch.
 */
FALCON_CORE_C_API long long Time_time(TimeHandle handle);
// @category:read
/* AUTO-DOC from cpp: Time_to_string |
 * falcon_core::communications::Time::to_string */
/**
 * @brief Convert the Time to a human-readable string.
 * @return A string representation of the Time.
 */
FALCON_CORE_C_API StringHandle Time_to_string(TimeHandle handle);

#ifdef __cplusplus
}
#endif
