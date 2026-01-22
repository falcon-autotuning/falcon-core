

# File InstrumentTypes.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**instrument\_interfaces**](dir_1d63ba24e228ec3f87efddb1c2728844.md) **>** [**names**](dir_a1bb891a070db74bff5519c1e6868927.md) **>** [**InstrumentTypes.hpp**](InstrumentTypes_8hpp.md)

[Go to the documentation of this file](InstrumentTypes_8hpp.md)


```C++
#pragma once
#include "falcon_core/instrument_interfaces/names/Instrument.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {
struct InstrumentTypes {
  static const Instrument DC_VOLTAGE_SOURCE;
  static const Instrument AMNMETER;
  static const Instrument MAGNET;
  static const Instrument LOCKIN;
  static const Instrument VOLTAGE_SOURCE;
  static const Instrument CURRENT_SOURCE;
  static const Instrument HF_VOLTAGE_SOURCE;
  static const Instrument DC_CURRENT_SOURCE;
  static const Instrument HF_CURRENT_SOURCE;
  static const Instrument THERMOMETER;
  static const Instrument VOLTMETER;
  static const Instrument FPGA;
  static const Instrument CLOCK;
  static const Instrument DISCRETE;
};
}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core
```


