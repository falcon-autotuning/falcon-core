#pragma once

#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>

namespace falcon_core::communications::voltage_states {

class DeviceVoltageState : public math::Quantity {
  physics::device_structures::ConnectionSP _connection;

 public:
  DeviceVoltageState(const physics::device_structures::ConnectionSP& connection,
                     const double&                                   voltage,
                     const physics::units::SymbolUnitSP&             unit);

  std::shared_ptr<physics::device_structures::Connection> connection() const;
  double                                                  voltage() const;

 protected:
  friend class cereal::access;
  DeviceVoltageState();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<math::Quantity>(this), _connection);
  }
};
using DeviceVoltageStateSP = std::shared_ptr<DeviceVoltageState>;
}  // namespace falcon_core::communications::voltage_states
