#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* ConnectionHandle;

// @category:allocation
ConnectionHandle Connection_create_barrier_gate(StringHandle name);
// @category:allocation
ConnectionHandle Connection_create_plunger_gate(StringHandle name);
// @category:allocation
ConnectionHandle Connection_create_reservoir_gate(StringHandle name);
// @category:allocation
ConnectionHandle Connection_create_screening_gate(StringHandle name);
// @category:allocation
ConnectionHandle Connection_create_ohmic(StringHandle name);
// @category:deallocation
void Connection_destroy(ConnectionHandle handle);
// @category:read
StringHandle Connection_name(ConnectionHandle handle);
// @category:read
StringHandle Connection_type(ConnectionHandle handle);
// @category:read
bool Connection_is_dot_gate(ConnectionHandle handle);
// @category:read
bool Connection_is_barrier_gate(ConnectionHandle handle);
// @category:read
bool Connection_is_plunger_gate(ConnectionHandle handle);
// @category:read
bool Connection_is_reservoir_gate(ConnectionHandle handle);
// @category:read
bool Connection_is_screening_gate(ConnectionHandle handle);
// @category:read
bool Connection_is_ohmic(ConnectionHandle handle);
// @category:read
bool Connection_is_gate(ConnectionHandle handle);
// @category:read
bool Connection_equal(ConnectionHandle handle, ConnectionHandle other);
// @category:read
bool Connection_not_equal(ConnectionHandle handle, ConnectionHandle other);
// @category:read
StringHandle Connection_to_json_string(ConnectionHandle handle);
// @category:allocation
ConnectionHandle Connection_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
