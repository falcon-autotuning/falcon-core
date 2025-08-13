#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"

#include "falcon_core/constants.hpp"

#include <functional>

namespace falcon_core
{

MeasurementContext::MeasurementContext (
    std::shared_ptr<physics::device_structures::BaseConnection> connection,
    std::shared_ptr<physics::units::SymbolUnit>                 unit)
    : _connection (std::move (connection)), _unit (std::move (unit))
{
}

const std::shared_ptr<physics::device_structures::BaseConnection> &
MeasurementContext::connection () const
{
  return _connection;
}

const std::shared_ptr<physics::units::SymbolUnit> &
MeasurementContext::unit () const
{
  return _unit;
}

nlohmann::json
MeasurementContext::to_json () const
{
  nlohmann::json j;
  add_metadata (
      j,
      "falcon_core.autotuner_interfaces.contexts.measurement_context",
      "MeasurementContext");
  j["_connection"] = _connection->to_json ();
  j["_unit"]       = _unit->to_json ();
  return j;
}

size_t
MeasurementContext::hash () const
{
  size_t h1 = _connection ? _connection->hash () : 0;
  size_t h2 = _unit ? _unit->hash () : 0;
  return h1 ^ (h2 << 1);
}

} // namespace falcon_core
