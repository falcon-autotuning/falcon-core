#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/generic/MapInstrumentPortQuantity_c_api.h"
#include "falcon-core/generic/String_c_api.h"

typedef void *SettingResponseHandle;

// @category:allocation
FALCON_CORE_C_API SettingResponseHandle
SettingResponse_copy(SettingResponseHandle handle);

// @category:deallocation
FALCON_CORE_C_API void SettingResponse_destroy(SettingResponseHandle handle);

// @category:read
FALCON_CORE_C_API bool SettingResponse_equal(SettingResponseHandle handle,
                                             SettingResponseHandle other);

// @category:read
FALCON_CORE_C_API bool SettingResponse_not_equal(SettingResponseHandle handle,
                                                 SettingResponseHandle other);

// @category:read
FALCON_CORE_C_API StringHandle
SettingResponse_to_json_string(SettingResponseHandle handle);

// @category:allocation
FALCON_CORE_C_API SettingResponseHandle
SettingResponse_from_json_string(StringHandle json);

// @category:allocation
FALCON_CORE_C_API SettingResponseHandle SettingResponse_create(
    StringHandle message, MapInstrumentPortQuantityHandle getters);

// @category:read
FALCON_CORE_C_API MapInstrumentPortQuantityHandle
SettingResponse_getters(SettingResponseHandle handle);

// @category:read
FALCON_CORE_C_API StringHandle
SettingResponse_message(SettingResponseHandle handle);

#ifdef __cplusplus
}
#endif
