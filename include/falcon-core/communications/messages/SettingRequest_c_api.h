#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/generic/MapInstrumentPortQuantity_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/Ports_c_api.h"

typedef void *SettingRequestHandle;

// @category:allocation
FALCON_CORE_C_API SettingRequestHandle
SettingRequest_copy(SettingRequestHandle handle);

// @category:deallocation
FALCON_CORE_C_API void SettingRequest_destroy(SettingRequestHandle handle);

// @category:read
FALCON_CORE_C_API bool SettingRequest_equal(SettingRequestHandle handle,
                                            SettingRequestHandle other);

// @category:read
FALCON_CORE_C_API bool SettingRequest_not_equal(SettingRequestHandle handle,
                                                SettingRequestHandle other);

// @category:read
FALCON_CORE_C_API StringHandle
SettingRequest_to_json_string(SettingRequestHandle handle);

// @category:allocation
FALCON_CORE_C_API SettingRequestHandle
SettingRequest_from_json_string(StringHandle json);

// @category:allocation
FALCON_CORE_C_API SettingRequestHandle
SettingRequest_create(StringHandle message, PortsHandle getters,
                      MapInstrumentPortQuantityHandle setters);

// @category:read
FALCON_CORE_C_API PortsHandle
SettingRequest_getters(SettingRequestHandle handle);

// @category:read
FALCON_CORE_C_API MapInstrumentPortQuantityHandle
SettingRequest_setters(SettingRequestHandle handle);

// @category:read
FALCON_CORE_C_API StringHandle
SettingRequest_message(SettingRequestHandle handle);

#ifdef __cplusplus
}
#endif
