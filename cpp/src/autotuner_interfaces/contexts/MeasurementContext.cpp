#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {
MeasurementContext::MeasurementContext(const MeasurementContext& other)
    : BaseContext(other) {
  std::shared_lock<std::shared_timed_mutex> lock_unit(other._mu_unit);
  _unit = other._unit;
}
MeasurementContext MeasurementContext::operator=(
    const MeasurementContext& other) {
  if (this != &other) {
    std::shared_lock<std::shared_timed_mutex> lock_other_unit(other._mu_unit,
                                                              std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_unit(_mu_unit,
                                                        std::defer_lock);
    std::lock(lock_unit, lock_other_unit);
    BaseContext::operator=(other);
    _unit = other._unit;
  }
  return *this;
}
MeasurementContext::MeasurementContext() = default;
MeasurementContext::MeasurementContext(
    const physics::device_structures::ConnectionSP& connection,
    const instrument_interfaces::names::Instrument& instrument_type)
    : BaseContext(connection, instrument_type) {}
MeasurementContext::MeasurementContext(const BaseContextSP& acquisition_context)
    : BaseContext(acquisition_context->connection(),
                  acquisition_context->instrument_type()) {}

}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::contexts::MeasurementContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::autotuner_interfaces::contexts::BaseContext,
    falcon_core::autotuner_interfaces::contexts::MeasurementContext)
