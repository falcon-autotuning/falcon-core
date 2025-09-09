#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {

AcquisitionContext::AcquisitionContext() = default;

AcquisitionContext::AcquisitionContext(
    physics::device_structures::BaseConnectionSP connection,
    instrument_interfaces::Instrument instrument_type,
    physics::units::SymbolUnitSP units)
    : BaseContext(connection, instrument_type), _units(units) {}

AcquisitionContext::AcquisitionContext(
    instrument_interfaces::names::InstrumentPortSP port)
    : BaseContext(port) {}

AcquisitionContext::AcquisitionContext(BaseContextSP measurement_context,
                                       physics::units::SymbolUnitSP unit)
    : BaseContext(measurement_context->connection(),
                  measurement_context->instrument_type()),
      _units(unit) {}

physics::units::SymbolUnitSP AcquisitionContext::units() const {
  return _units;
}

AcquisitionContextSP AcquisitionContext::operator/(
    const physics::units::SymbolUnitSP& other) const {
  return std::make_shared<AcquisitionContext>(
      connection(), instrument_type(), *units() / other);
}

AcquisitionContextSP AcquisitionContext::operator/(
    const std::shared_ptr<AcquisitionContext>& other) const {
  return std::make_shared<AcquisitionContext>(
      connection(), instrument_type(), *units() / other->units());
}

bool AcquisitionContext::match_connection(
    physics::device_structures::BaseConnectionSP other) const {
  return connection() == other;
}

bool AcquisitionContext::match_instrument_type(
    instrument_interfaces::Instrument other) const {
  return instrument_type() == other;
}

template <class Archive>
void AcquisitionContext::serialize(Archive& ar) {
  ar(cereal::base_class<BaseContext>(this), _units);
}

// Explicit template instantiations for cereal
template void AcquisitionContext::serialize<cereal::JSONOutputArchive>(cereal::JSONOutputArchive& ar);
template void AcquisitionContext::serialize<cereal::JSONInputArchive>(cereal::JSONInputArchive& ar);
template void AcquisitionContext::serialize<cereal::BinaryOutputArchive>(cereal::BinaryOutputArchive& ar);
template void AcquisitionContext::serialize<cereal::BinaryInputArchive>(cereal::BinaryInputArchive& ar);

}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::contexts::AcquisitionContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::autotuner_interfaces::contexts::BaseContext,
    falcon_core::autotuner_interfaces::contexts::AcquisitionContext)
