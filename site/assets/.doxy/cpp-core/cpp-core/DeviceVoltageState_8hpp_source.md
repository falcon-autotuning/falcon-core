

# File DeviceVoltageState.hpp

[**File List**](files.md) **>** [**communications**](dir_b94a6b29f2c7b9c121097afc928ed71e.md) **>** [**voltage\_states**](dir_707a09d08b8cf5ba6e3c2c40da44e9d3.md) **>** [**DeviceVoltageState.hpp**](DeviceVoltageState_8hpp.md)

[Go to the documentation of this file](DeviceVoltageState_8hpp.md)


```C++
#pragma once

#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>

namespace falcon_core {
namespace communications {
namespace voltage_states {

class DeviceVoltageState : public math::Quantity {
  physics::device_structures::ConnectionSP _connection;
  mutable std::shared_timed_mutex          _mu_connection;

 public:
  DeviceVoltageState(const DeviceVoltageState& other);
  DeviceVoltageState& operator=(const DeviceVoltageState& other);
  DeviceVoltageState(const physics::device_structures::ConnectionSP& connection,
                     const double&                                   voltage,
                     const physics::units::SymbolUnitSP&             unit);

  const physics::device_structures::ConnectionSP& connection() const;
  double                                          voltage() const;
  bool operator==(const DeviceVoltageState& other) const;
  bool operator!=(const DeviceVoltageState& other) const;

 protected:
  friend class cereal::access;
  DeviceVoltageState();
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_c(_mu_connection);
    ar(cereal::base_class<math::Quantity>(this), _connection);
  }
};
using DeviceVoltageStateSP = std::shared_ptr<DeviceVoltageState>;
}  // namespace voltage_states
}  // namespace communications
}  // namespace falcon_core
```


