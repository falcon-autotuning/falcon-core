#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include "falcon-core/generic/String_c_api.h"

FALCON_CORE_C_API StringHandle InstrumentTypes_dc_voltage_source();
FALCON_CORE_C_API StringHandle InstrumentTypes_amnmeter();
FALCON_CORE_C_API StringHandle InstrumentTypes_magnet();
FALCON_CORE_C_API StringHandle InstrumentTypes_lockin();
FALCON_CORE_C_API StringHandle InstrumentTypes_voltage_source();
FALCON_CORE_C_API StringHandle InstrumentTypes_current_source();
FALCON_CORE_C_API StringHandle InstrumentTypes_hf_voltage_source();
FALCON_CORE_C_API StringHandle InstrumentTypes_dc_current_source();
FALCON_CORE_C_API StringHandle InstrumentTypes_hf_current_source();
FALCON_CORE_C_API StringHandle InstrumentTypes_thermometer();
FALCON_CORE_C_API StringHandle InstrumentTypes_voltmeter();
FALCON_CORE_C_API StringHandle InstrumentTypes_fpga();
FALCON_CORE_C_API StringHandle InstrumentTypes_clock();
FALCON_CORE_C_API StringHandle InstrumentTypes_discrete();

#ifdef __cplusplus
}
#endif
