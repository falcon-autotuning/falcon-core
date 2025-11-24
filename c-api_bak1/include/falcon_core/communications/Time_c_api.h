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
/* AUTO-DOC from cpp: Time_micro_seconds_since_epoch | falcon_core::communications::Time::micro_seconds_since_epoch */
/**
 * @brief (from C++: falcon_core::communications::Time::micro_seconds_since_epoch)
 * @brief Get the time in microseconds since epoch.
 * @return The time in microseconds since epoch.
 */
long long    Time_micro_seconds_since_epoch(TimeHandle handle);
/* AUTO-DOC from cpp: Time_time | falcon_core::communications::Time::time */
/**
 * @brief (from C++: falcon_core::communications::Time::time)
 * @brief Get the time in seconds since epoch.
 * @return The time in seconds since epoch.
 */
long long    Time_time(TimeHandle handle);
/* AUTO-DOC from cpp: Time_to_string | falcon_core::communications::Time::to_string */
/**
 * @brief (from C++: falcon_core::communications::Time::to_string)
 * @brief Convert the Time to a human-readable string.
 * @return A string representation of the Time.
 */
StringHandle Time_to_string(TimeHandle handle);
bool         Time_equal(TimeHandle a, TimeHandle b);
bool         Time_not_equal(TimeHandle a, TimeHandle b);

// Serialization (from Song)
StringHandle Time_to_json_string(TimeHandle handle);
TimeHandle   Time_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
