#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

#include <memory>

namespace falcon_core
{
namespace autotuner_interfaces
{
namespace contexts
{

class MeasurementContext : public generic::Song
{
public:
  MeasurementContext (
      std::shared_ptr<physics::device_structures::BaseConnection> connection,
      std::shared_ptr<physics::units::SymbolUnit>                 unit);

  const std::shared_ptr<physics::device_structures::BaseConnection>                                                    &
  connection () const;
  const std::shared_ptr<physics::units::SymbolUnit> &unit () const;

  nlohmann::json to_json () const override;
  size_t         hash () const override;

private:
  std::shared_ptr<physics::device_structures::BaseConnection> _connection;
  std::shared_ptr<physics::units::SymbolUnit>                 _unit;
};
}
}
} // namespace falcon_core
