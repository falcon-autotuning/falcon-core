#pragma once
#include "falcon_core/generic/String_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

StringHandle InstrumentTypes_dc_voltage_source();
StringHandle InstrumentTypes_amnmeter();
StringHandle InstrumentTypes_magnet();
StringHandle InstrumentTypes_lockin();
StringHandle InstrumentTypes_voltage_source();
StringHandle InstrumentTypes_current_source();
StringHandle InstrumentTypes_hf_voltage_source();
StringHandle InstrumentTypes_dc_current_source();
StringHandle InstrumentTypes_hf_current_source();
StringHandle InstrumentTypes_thermometer();
StringHandle InstrumentTypes_voltmeter();
StringHandle InstrumentTypes_fpga();
StringHandle InstrumentTypes_clock();
StringHandle InstrumentTypes_discrete();

#ifdef __cplusplus
}
#endif
