#include "falcon_core/autotuner_interfaces/contexts/BaseContext.hpp"

namespace falcon_core::autotuner_interfaces::contexts {
BaseContext::BaseContext() = default;
BaseContext::BaseContext(
    const physics::device_structures::BaseConnectionSP& connection,
    const instrument_interfaces::Instrument&            instrument_type)
    : _connection(connection), _instrument_type(instrument_type) {}
BaseContext::BaseContext(
    const instrument_interfaces::names::InstrumentPortSP& port)
    : _connection(port->pseudo_name()),
      _instrument_type(port->instrument_type()) {}
const physics::device_structures::BaseConnectionSP BaseContext::connection()
    const {
  return _connection;
}
const instrument_interfaces::Instrument BaseContext::instrument_type() const {
  return _instrument_type;
}
}  // namespace falcon_core::autotuner_interfaces::contexts
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::contexts::BaseContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::contexts::BaseContext)
