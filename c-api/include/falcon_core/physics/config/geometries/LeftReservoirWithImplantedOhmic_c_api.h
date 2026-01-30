#pragma once
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* LeftReservoirWithImplantedOhmicHandle;

// @category:allocation
FALCON_CORE_C_API LeftReservoirWithImplantedOhmicHandle
LeftReservoirWithImplantedOhmic_copy(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:deallocation
FALCON_CORE_C_API void LeftReservoirWithImplantedOhmic_destroy(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:read
FALCON_CORE_C_API bool LeftReservoirWithImplantedOhmic_equal(
    LeftReservoirWithImplantedOhmicHandle handle,
    LeftReservoirWithImplantedOhmicHandle other);
// @category:read
FALCON_CORE_C_API bool LeftReservoirWithImplantedOhmic_not_equal(
    LeftReservoirWithImplantedOhmicHandle handle,
    LeftReservoirWithImplantedOhmicHandle other);
// @category:read
FALCON_CORE_C_API StringHandle LeftReservoirWithImplantedOhmic_to_json_string(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:allocation
FALCON_CORE_C_API LeftReservoirWithImplantedOhmicHandle
LeftReservoirWithImplantedOhmic_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API LeftReservoirWithImplantedOhmicHandle
LeftReservoirWithImplantedOhmic_create(StringHandle     name,
                                       ConnectionHandle right_neighbor,
                                       ConnectionHandle ohmic);
// @category:read
FALCON_CORE_C_API StringHandle LeftReservoirWithImplantedOhmic_name(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:read
FALCON_CORE_C_API StringHandle LeftReservoirWithImplantedOhmic_type(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle LeftReservoirWithImplantedOhmic_ohmic(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle
LeftReservoirWithImplantedOhmic_right_neighbor(
    LeftReservoirWithImplantedOhmicHandle handle);
#ifdef __cplusplus
}
#endif
