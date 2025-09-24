#include <falcon_core/communications/messages/MeasurementRequest.hpp>

#include "falcon_core/instrument_interfaces/Waveform.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

namespace falcon_core::communications::messages {

MeasurementRequest::MeasurementRequest() = default;

MeasurementRequest::MeasurementRequest(
    const std::string&                                      message,
    const std::string&                                      measurement_name,
    const generic::ListSP<instrument_interfaces::Waveform>& waveforms,
    const instrument_interfaces::names::PortsSP&            getters,
    const generic::MapSP<instrument_interfaces::names::InstrumentPort,
                         instrument_interfaces::port_transforms::PortTransform>&
                                           meter_transforms,
    const math::domains::LabelledDomainSP& time_domain)
    : BaseMessage(message),
      _measurement_name(measurement_name),
      _waveforms(waveforms),
      _getters(getters),
      _meter_transforms(meter_transforms),
      _time_domain(time_domain) {}

const std::string& MeasurementRequest::measurement_name() const {
  return _measurement_name;
}
const instrument_interfaces::names::PortsSP& MeasurementRequest::getters()
    const {
  return _getters;
}
const generic::ListSP<instrument_interfaces::Waveform>&
MeasurementRequest::waveforms() const {
  return _waveforms;
}
const generic::MapSP<instrument_interfaces::names::InstrumentPort,
                     instrument_interfaces::port_transforms::PortTransform>&
MeasurementRequest::meter_transforms() const {
  return _meter_transforms;
}
const math::domains::LabelledDomainSP& MeasurementRequest::time_domain() const {
  return _time_domain;
}

}  // namespace falcon_core::communications::messages

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::MeasurementRequest)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::MeasurementRequest)
