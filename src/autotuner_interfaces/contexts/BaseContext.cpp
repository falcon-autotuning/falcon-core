#include "falcon_core/autotuner_interfaces/contexts/BaseContext.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {
BaseContext::BaseContext() = default;
BaseContext::BaseContext(
    std::shared_ptr<physics::device_structures::BaseConnection> connection,
    instrument_interfaces::Instrument                           instrument_type)
    : _connection(connection), _instrument_type(instrument_type) {}
BaseContext::BaseContext(instrument_interfaces::names::InstrumentPortSP port)
    : _connection(port->pseudo_name()),
      _instrument_type(port->instrument_type()) {}
physics::device_structures::BaseConnectionSP BaseContext::connection() const {
  return _connection;
}
instrument_interfaces::Instrument BaseContext::instrument_type() const {
  return _instrument_type;
}
template <class Archive>
void BaseContext::serialize(Archive& ar) {
  ar(cereal::base_class<falcon_core::generic::Song>(this),
     _connection,
     _instrument_type);
}
}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::contexts::BaseContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::contexts::BaseContext)
