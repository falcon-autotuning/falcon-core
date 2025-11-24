#pragma once
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* LeftReservoirWithImplantedOhmicHandle;

// Constructors
LeftReservoirWithImplantedOhmicHandle LeftReservoirWithImplantedOhmic_create(
    StringHandle name, ConnectionHandle right_neighbor, ConnectionHandle ohmic);

// Destructor
void LeftReservoirWithImplantedOhmic_destroy(
    LeftReservoirWithImplantedOhmicHandle handle);

// Methods
StringHandle LeftReservoirWithImplantedOhmic_name(
    LeftReservoirWithImplantedOhmicHandle handle);
StringHandle LeftReservoirWithImplantedOhmic_type(
    LeftReservoirWithImplantedOhmicHandle handle);
/* AUTO-DOC from cpp: LeftReservoirWithImplantedOhmic_ohmic | falcon_core::physics::config::geometries::HasImplantedOhmic::ohmic */
/**
 * @brief (from C++: falcon_core::physics::config::geometries::HasImplantedOhmic::ohmic)
 * @brief Returns the ohmic below the gate.
 */
ConnectionHandle LeftReservoirWithImplantedOhmic_ohmic(
    LeftReservoirWithImplantedOhmicHandle handle);
ConnectionHandle LeftReservoirWithImplantedOhmic_right_neighbor(
    LeftReservoirWithImplantedOhmicHandle handle);
bool LeftReservoirWithImplantedOhmic_equal(
    LeftReservoirWithImplantedOhmicHandle a,
    LeftReservoirWithImplantedOhmicHandle b);
bool LeftReservoirWithImplantedOhmic_not_equal(
    LeftReservoirWithImplantedOhmicHandle a,
    LeftReservoirWithImplantedOhmicHandle b);

// Serialization (from Song)
StringHandle LeftReservoirWithImplantedOhmic_to_json_string(
    LeftReservoirWithImplantedOhmicHandle handle);
LeftReservoirWithImplantedOhmicHandle
LeftReservoirWithImplantedOhmic_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
