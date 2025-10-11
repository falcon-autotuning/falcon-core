#include "falcon_core/autotuner_interfaces/contexts/BaseContext.hpp"

#include <stdexcept>

namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {
BaseContext::BaseContext() = default;
BaseContext::BaseContext(
    const physics::device_structures::ConnectionSP& connection,
    const instrument_interfaces::names::Instrument& instrument_type)
    : _connection(connection), _instrument_type(instrument_type) {
  if (!connection) {
    throw std::invalid_argument(
        "BaseContext: The connection must not be null.");
  }
}
BaseContext::BaseContext(
    const instrument_interfaces::names::InstrumentPortSP& port) {
  if (!port) {
    throw std::invalid_argument("BaseContext: The port must not be null.");
  }
  _connection      = port->pseudo_name();
  _instrument_type = port->instrument_type();
}
const physics::device_structures::ConnectionSP BaseContext::connection() const {
  return _connection;
}
const instrument_interfaces::names::Instrument BaseContext::instrument_type()
    const {
  return _instrument_type;
}
}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::contexts::BaseContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::contexts::BaseContext)
