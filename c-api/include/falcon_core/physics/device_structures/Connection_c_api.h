#pragma once
#ifdef __cplusplus
extern "C" {
#endif

typedef void* ConnectionHandle;

typedef enum {
  DEVICE_FEATURE_BARRIER_GATE,
  DEVICE_FEATURE_PLUNGER_GATE,
  DEVICE_FEATURE_RESERVOIR_GATE,
  DEVICE_FEATURE_SCREENING_GATE,
  DEVICE_FEATURE_OHMIC
} DeviceFeatureC;

// Constructors
ConnectionHandle Connection_create(const char* name, DeviceFeatureC type);
ConnectionHandle Connection_create_barrier_gate(const char* name);
ConnectionHandle Connection_create_plunger_gate(const char* name);
ConnectionHandle Connection_create_reservoir_gate(const char* name);
ConnectionHandle Connection_create_screening_gate(const char* name);
ConnectionHandle Connection_create_ohmic(const char* name);

// Destructor
void Connection_destroy(ConnectionHandle handle);

// Methods
const char* Connection_get_name(ConnectionHandle handle);
const char* Connection_get_type(ConnectionHandle handle);
int         Connection_is_dot_gate(ConnectionHandle handle);
int         Connection_is_barrier_gate(ConnectionHandle handle);
int         Connection_is_plunger_gate(ConnectionHandle handle);
int         Connection_is_reservoir_gate(ConnectionHandle handle);
int         Connection_is_screening_gate(ConnectionHandle handle);
int         Connection_is_ohmic(ConnectionHandle handle);
int         Connection_is_gate(ConnectionHandle handle);

// Serialization (from Song)
const char*      Connection_to_json_string(ConnectionHandle handle);
ConnectionHandle Connection_from_json_string(const char* json);

int Connection_equal(ConnectionHandle a, ConnectionHandle b);
int Connection_not_equal(ConnectionHandle a, ConnectionHandle b);

#ifdef __cplusplus
}
#endif
