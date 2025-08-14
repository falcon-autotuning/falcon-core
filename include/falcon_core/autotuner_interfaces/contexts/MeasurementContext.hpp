#pragma once

#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {

class MeasurementContext : public generic::Song {
 public:
  MeasurementContext(
      std::shared_ptr<physics::device_structures::BaseConnection> connection,
      std::shared_ptr<physics::units::SymbolUnit>                 unit);

  const std::shared_ptr<physics::device_structures::BaseConnection>                                                    &
  connection() const;
  const std::shared_ptr<physics::units::SymbolUnit> &unit() const;

 private:
  std::shared_ptr<physics::device_structures::BaseConnection> _connection;
  std::shared_ptr<physics::units::SymbolUnit>                 _unit;
};
}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
