#pragma once

#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>

#include "falcon_core/export.h"

namespace falcon_core {
namespace communications {
namespace voltage_states {

class FALCON_CORE_CPP_API DeviceVoltageState : public math::Quantity {
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
  inline void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_c(_mu_connection);
    ar(cereal::base_class<math::Quantity>(this), _connection);
  }
};
using DeviceVoltageStateSP = std::shared_ptr<DeviceVoltageState>;
}  // namespace voltage_states
}  // namespace communications
}  // namespace falcon_core
