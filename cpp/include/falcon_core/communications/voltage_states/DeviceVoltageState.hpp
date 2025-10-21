#pragma once

#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>

namespace falcon_core {
namespace communications {
namespace voltage_states {

class DeviceVoltageState : public math::Quantity {
  physics::device_structures::ConnectionSP _connection;

 public:
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
    ar(cereal::base_class<math::Quantity>(this), _connection);
  }
};
using DeviceVoltageStateSP = std::shared_ptr<DeviceVoltageState>;
}  // namespace voltage_states
}  // namespace communications
}  // namespace falcon_core
