#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"

#include <functional>

#include "falcon_core/physics/device_structures/BaseConnection.hpp"
using namespace falcon_core;
using namespace falcon_core::autotuner_interfaces::contexts;
using physics::device_structures::BaseConnection;
using physics::units::SymbolUnit;

MeasurementContext::MeasurementContext(
    std::shared_ptr<BaseConnection> connection,
    std::shared_ptr<SymbolUnit>     unit)
    : _connection(std::move(connection)), _unit(std::move(unit)) {}

const std::shared_ptr<BaseConnection>& MeasurementContext::connection() const {
  return _connection;
}

const std::shared_ptr<SymbolUnit>& MeasurementContext::unit() const {
  return _unit;
}
