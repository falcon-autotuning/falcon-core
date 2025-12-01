#pragma once
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* RightReservoirWithImplantedOhmicHandle;

// Constructors
RightReservoirWithImplantedOhmicHandle RightReservoirWithImplantedOhmic_create(
    StringHandle name, ConnectionHandle left_neighbor, ConnectionHandle ohmic);

// Destructor
void RightReservoirWithImplantedOhmic_destroy(
    RightReservoirWithImplantedOhmicHandle handle);

// Methods
StringHandle RightReservoirWithImplantedOhmic_name(
    RightReservoirWithImplantedOhmicHandle handle);
StringHandle RightReservoirWithImplantedOhmic_type(
    RightReservoirWithImplantedOhmicHandle handle);
ConnectionHandle RightReservoirWithImplantedOhmic_ohmic(
    RightReservoirWithImplantedOhmicHandle handle);
ConnectionHandle RightReservoirWithImplantedOhmic_left_neighbor(
    RightReservoirWithImplantedOhmicHandle handle);
bool RightReservoirWithImplantedOhmic_equal(
    RightReservoirWithImplantedOhmicHandle a,
    RightReservoirWithImplantedOhmicHandle b);
bool RightReservoirWithImplantedOhmic_not_equal(
    RightReservoirWithImplantedOhmicHandle a,
    RightReservoirWithImplantedOhmicHandle b);

// Serialization (from Song)
StringHandle RightReservoirWithImplantedOhmic_to_json_string(
    RightReservoirWithImplantedOhmicHandle handle);
RightReservoirWithImplantedOhmicHandle
RightReservoirWithImplantedOhmic_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
