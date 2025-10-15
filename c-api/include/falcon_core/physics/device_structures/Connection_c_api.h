#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
typedef void* ConnectionHandle;

// Constructors
ConnectionHandle Connection_create_barrier_gate(const char* name);
ConnectionHandle Connection_create_plunger_gate(const char* name);
ConnectionHandle Connection_create_reservoir_gate(const char* name);
ConnectionHandle Connection_create_screening_gate(const char* name);
ConnectionHandle Connection_create_ohmic(const char* name);

// Destructor
void Connection_destroy(ConnectionHandle handle);

// Methods
const char* Connection_name(ConnectionHandle handle);
const char* Connection_type(ConnectionHandle handle);
bool        Connection_is_dot_gate(ConnectionHandle handle);
bool        Connection_is_barrier_gate(ConnectionHandle handle);
bool        Connection_is_plunger_gate(ConnectionHandle handle);
bool        Connection_is_reservoir_gate(ConnectionHandle handle);
bool        Connection_is_screening_gate(ConnectionHandle handle);
bool        Connection_is_ohmic(ConnectionHandle handle);
bool        Connection_is_gate(ConnectionHandle handle);
bool        Connection_equal(ConnectionHandle a, ConnectionHandle b);
bool        Connection_not_equal(ConnectionHandle a, ConnectionHandle b);

// Serialization (from Song)
const char*      Connection_to_json_string(ConnectionHandle handle);
ConnectionHandle Connection_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif
