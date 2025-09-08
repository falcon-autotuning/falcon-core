#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"

#include "falcon_core/autotuner_interfaces/contexts/BaseContext.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {
MeasurementContext::MeasurementContext() = default;
MeasurementContext::MeasurementContext(
    physics::device_structures::BaseConnectionSP connection,
    instrument_interfaces::Instrument            instrument_type)
    : BaseContext(connection, instrument_type) {}
MeasurementContext::MeasurementContext(BaseContextSP acquisition_context)
    : BaseContext(acquisition_context->connection(),
                  acquisition_context->instrument_type()) {}

template <class Archive>
void MeasurementContext::serialize(Archive& ar) {
  ar(cereal::base_class<BaseContext>(this));
}
}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::contexts::MeasurementContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::autotuner_interfaces::contexts::BaseContext,
    falcon_core::autotuner_interfaces::contexts::MeasurementContext)
