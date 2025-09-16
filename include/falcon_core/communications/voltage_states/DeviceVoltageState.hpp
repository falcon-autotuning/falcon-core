#pragma once

#include <falcon_core/generic/Song.hpp>
#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/physics/device_structures/BaseConnection.hpp>
#include <falcon_core/physics/units/SymbolUnit.hpp>

namespace falcon_core::communications::voltage_states {

class DeviceVoltageState : public math::Quantity {
 public:
  DeviceVoltageState(
      std::shared_ptr<physics::device_structures::BaseConnection> connection,
      double                                                      voltage,
      std::shared_ptr<physics::units::SymbolUnit>                 unit);

  DeviceVoltageState();

  std::shared_ptr<physics::device_structures::BaseConnection> connection()
      const;
  double voltage() const;

 private:
  std::shared_ptr<physics::device_structures::BaseConnection> _connection;

  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};
using DeviceVoltageStateSP = std::shared_ptr<DeviceVoltageState>;
}  // namespace falcon_core::communications::voltage_states
