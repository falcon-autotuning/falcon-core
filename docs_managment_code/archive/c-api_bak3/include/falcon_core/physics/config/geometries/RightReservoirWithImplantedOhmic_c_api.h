#pragma once
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* RightReservoirWithImplantedOhmicHandle;

// @category:allocation
RightReservoirWithImplantedOhmicHandle RightReservoirWithImplantedOhmic_create(
    StringHandle name, ConnectionHandle left_neighbor, ConnectionHandle ohmic);
// @category:deallocation
void RightReservoirWithImplantedOhmic_destroy(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:read
StringHandle RightReservoirWithImplantedOhmic_name(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:read
StringHandle RightReservoirWithImplantedOhmic_type(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:read
ConnectionHandle RightReservoirWithImplantedOhmic_ohmic(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:read
ConnectionHandle RightReservoirWithImplantedOhmic_left_neighbor(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:read
bool RightReservoirWithImplantedOhmic_equal(
    RightReservoirWithImplantedOhmicHandle handle,
    RightReservoirWithImplantedOhmicHandle other);
// @category:read
bool RightReservoirWithImplantedOhmic_not_equal(
    RightReservoirWithImplantedOhmicHandle a,
    RightReservoirWithImplantedOhmicHandle b);
// @category:read
StringHandle RightReservoirWithImplantedOhmic_to_json_string(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:allocation
RightReservoirWithImplantedOhmicHandle
RightReservoirWithImplantedOhmic_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
