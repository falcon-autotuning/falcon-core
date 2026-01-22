

# File DeviceVoltageStates.hpp

[**File List**](files.md) **>** [**communications**](dir_b94a6b29f2c7b9c121097afc928ed71e.md) **>** [**voltage\_states**](dir_707a09d08b8cf5ba6e3c2c40da44e9d3.md) **>** [**DeviceVoltageStates.hpp**](DeviceVoltageStates_8hpp.md)

[Go to the documentation of this file](DeviceVoltageStates_8hpp.md)


```C++
#pragma once

#include "falcon_core/communications/voltage_states/DeviceVoltageState.hpp"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/math/Point.hpp"
namespace falcon_core {
namespace communications {
namespace voltage_states {

class DeviceVoltageStates : public generic::List<DeviceVoltageState> {
 public:
  DeviceVoltageStates();
  DeviceVoltageStates(const generic::ListSP<DeviceVoltageState>& states);
  const generic::ListSP<DeviceVoltageState> states() const;
  void add_state(const DeviceVoltageStateSP& state);
  const DeviceVoltageStateSP find_state(
      const physics::device_structures::ConnectionSP& connection) const;
  const math::PointSP to_point() const;
};
using DeviceVoltageStatesSP = std::shared_ptr<DeviceVoltageStates>;
}  // namespace voltage_states
}  // namespace communications
}  // namespace falcon_core
```


