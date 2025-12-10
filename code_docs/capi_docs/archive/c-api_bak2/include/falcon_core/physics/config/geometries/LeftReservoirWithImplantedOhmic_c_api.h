#pragma once
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* LeftReservoirWithImplantedOhmicHandle;

// @category:allocation
LeftReservoirWithImplantedOhmicHandle LeftReservoirWithImplantedOhmic_copy(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:deallocation
void LeftReservoirWithImplantedOhmic_destroy(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:read
bool LeftReservoirWithImplantedOhmic_equal(
    LeftReservoirWithImplantedOhmicHandle handle,
    LeftReservoirWithImplantedOhmicHandle other);
// @category:read
bool LeftReservoirWithImplantedOhmic_not_equal(
    LeftReservoirWithImplantedOhmicHandle handle,
    LeftReservoirWithImplantedOhmicHandle other);
// @category:read
StringHandle LeftReservoirWithImplantedOhmic_to_json_string(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:allocation
LeftReservoirWithImplantedOhmicHandle
LeftReservoirWithImplantedOhmic_from_json_string(StringHandle json);
// @category:allocation
LeftReservoirWithImplantedOhmicHandle LeftReservoirWithImplantedOhmic_create(
    StringHandle name, ConnectionHandle right_neighbor, ConnectionHandle ohmic);
// @category:read
StringHandle LeftReservoirWithImplantedOhmic_name(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:read
StringHandle LeftReservoirWithImplantedOhmic_type(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:read
ConnectionHandle LeftReservoirWithImplantedOhmic_ohmic(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:read
ConnectionHandle LeftReservoirWithImplantedOhmic_right_neighbor(
    LeftReservoirWithImplantedOhmicHandle handle);
#ifdef __cplusplus
}
#endif
