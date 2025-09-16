#pragma once

#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/physics/device_structures/BaseConnection.hpp>

namespace falcon_core::communications::voltage_states {

class DeviceVoltageState : public math::Quantity {
  physics::device_structures::BaseConnectionSP _connection;

 public:
  DeviceVoltageState(physics::device_structures::BaseConnectionSP connection,
                     double                                       voltage,
                     physics::units::SymbolUnitSP                 unit);

  std::shared_ptr<physics::device_structures::BaseConnection> connection()
      const;
  double voltage() const;

 protected:
  DeviceVoltageState();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<math::Quantity>(this), _connection);
  }
};
using DeviceVoltageStateSP = std::shared_ptr<DeviceVoltageState>;
}  // namespace falcon_core::communications::voltage_states
