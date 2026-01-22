

# File InstrumentTypes\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**instrument\_interfaces**](dir_9a3e3629c63b09e0e53088699a1e2284.md) **>** [**names**](dir_fb9004cf3d6d1aecbf7000576bf4839c.md) **>** [**InstrumentTypes\_c\_api.h**](InstrumentTypes__c__api_8h.md)

[Go to the documentation of this file](InstrumentTypes__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include "falcon_core/generic/String_c_api.h"

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
```


