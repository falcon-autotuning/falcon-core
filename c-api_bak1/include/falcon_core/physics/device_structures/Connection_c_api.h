#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* ConnectionHandle;

// Constructors
ConnectionHandle Connection_create_barrier_gate(StringHandle name);
ConnectionHandle Connection_create_plunger_gate(StringHandle name);
ConnectionHandle Connection_create_reservoir_gate(StringHandle name);
ConnectionHandle Connection_create_screening_gate(StringHandle name);
ConnectionHandle Connection_create_ohmic(StringHandle name);

// Destructor
void Connection_destroy(ConnectionHandle handle);

// Methods
/* AUTO-DOC from cpp: Connection_name | falcon_core::physics::device_structures::Connection::name */
/**
 * @brief (from C++: falcon_core::physics::device_structures::Connection::name)
 * @brief The name of the connection.
 * @return The name as a string.
 */
StringHandle Connection_name(ConnectionHandle handle);
/* AUTO-DOC from cpp: Connection_type | falcon_core::physics::device_structures::Connection::type */
/**
 * @brief (from C++: falcon_core::physics::device_structures::Connection::type)
 * @brief The type of the connection.
 * @return The type as a string.
 */
StringHandle Connection_type(ConnectionHandle handle);
/* AUTO-DOC from cpp: Connection_is_dot_gate | falcon_core::physics::device_structures::Connection::is_dot_gate */
/**
 * @brief (from C++: falcon_core::physics::device_structures::Connection::is_dot_gate)
 * @brief Check if the connection is a plungergate or barriergate.
 */
bool         Connection_is_dot_gate(ConnectionHandle handle);
/* AUTO-DOC from cpp: Connection_is_barrier_gate | falcon_core::physics::device_structures::Connection::is_barrier_gate */
/**
 * @brief (from C++: falcon_core::physics::device_structures::Connection::is_barrier_gate)
 * @brief Check if the connection is a barriergate.
 */
bool         Connection_is_barrier_gate(ConnectionHandle handle);
/* AUTO-DOC from cpp: Connection_is_plunger_gate | falcon_core::physics::device_structures::Connection::is_plunger_gate */
/**
 * @brief (from C++: falcon_core::physics::device_structures::Connection::is_plunger_gate)
 * @brief Check if the connection is a plunger gate.
 */
bool         Connection_is_plunger_gate(ConnectionHandle handle);
/* AUTO-DOC from cpp: Connection_is_reservoir_gate | falcon_core::physics::device_structures::Connection::is_reservoir_gate */
/**
 * @brief (from C++: falcon_core::physics::device_structures::Connection::is_reservoir_gate)
 * @brief Check if the connection is a reservoir gate.
 */
bool         Connection_is_reservoir_gate(ConnectionHandle handle);
/* AUTO-DOC from cpp: Connection_is_screening_gate | falcon_core::physics::device_structures::Connection::is_screening_gate */
/**
 * @brief (from C++: falcon_core::physics::device_structures::Connection::is_screening_gate)
 * @brief Check if the connection is a screening gate.
 */
bool         Connection_is_screening_gate(ConnectionHandle handle);
/* AUTO-DOC from cpp: Connection_is_ohmic | falcon_core::physics::device_structures::Connection::is_ohmic */
/**
 * @brief (from C++: falcon_core::physics::device_structures::Connection::is_ohmic)
 * @brief Check if the connection is an ohmic contact.
 */
bool         Connection_is_ohmic(ConnectionHandle handle);
/* AUTO-DOC from cpp: Connection_is_gate | falcon_core::physics::device_structures::Connection::is_gate */
/**
 * @brief (from C++: falcon_core::physics::device_structures::Connection::is_gate)
 * @brief Check if the connection is any type of gate (barrier, plunger,
 * reservoir, screening).
 */
bool         Connection_is_gate(ConnectionHandle handle);
bool         Connection_equal(ConnectionHandle a, ConnectionHandle b);
bool         Connection_not_equal(ConnectionHandle a, ConnectionHandle b);

// Serialization (from Song)
StringHandle     Connection_to_json_string(ConnectionHandle handle);
ConnectionHandle Connection_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
