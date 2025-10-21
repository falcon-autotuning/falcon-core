#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {
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
