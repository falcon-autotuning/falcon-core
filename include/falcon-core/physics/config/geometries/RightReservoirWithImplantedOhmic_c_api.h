#pragma once
#include "falcon-core/physics/device_structures/Connection_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/generic/String_c_api.h"
typedef void* RightReservoirWithImplantedOhmicHandle;

// @category:allocation
FALCON_CORE_C_API RightReservoirWithImplantedOhmicHandle
RightReservoirWithImplantedOhmic_copy(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:deallocation
FALCON_CORE_C_API void RightReservoirWithImplantedOhmic_destroy(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:read
FALCON_CORE_C_API bool RightReservoirWithImplantedOhmic_equal(
    RightReservoirWithImplantedOhmicHandle handle,
    RightReservoirWithImplantedOhmicHandle other);
// @category:read
FALCON_CORE_C_API bool RightReservoirWithImplantedOhmic_not_equal(
    RightReservoirWithImplantedOhmicHandle handle,
    RightReservoirWithImplantedOhmicHandle other);
// @category:read
FALCON_CORE_C_API StringHandle RightReservoirWithImplantedOhmic_to_json_string(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:allocation
FALCON_CORE_C_API RightReservoirWithImplantedOhmicHandle
RightReservoirWithImplantedOhmic_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API RightReservoirWithImplantedOhmicHandle
RightReservoirWithImplantedOhmic_create(StringHandle     name,
                                        ConnectionHandle left_neighbor,
                                        ConnectionHandle ohmic);
// @category:read
FALCON_CORE_C_API StringHandle RightReservoirWithImplantedOhmic_name(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:read
FALCON_CORE_C_API StringHandle RightReservoirWithImplantedOhmic_type(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle RightReservoirWithImplantedOhmic_ohmic(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle
RightReservoirWithImplantedOhmic_left_neighbor(
    RightReservoirWithImplantedOhmicHandle handle);
#ifdef __cplusplus
}
#endif
