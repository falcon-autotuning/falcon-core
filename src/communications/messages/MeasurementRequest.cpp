#include <falcon_core/communications/messages/MeasurementRequest.hpp>

namespace falcon_core::communications::messages {

using waveform_type =
    falcon_core::instrument_interfaces::waveforms::BaseWaveform<
        falcon_core::math::discrete_spaces::BaseDiscreteSpace>;

MeasurementRequest::MeasurementRequest() = default;

MeasurementRequest::MeasurementRequest(
    const std::string&                            message,
    const std::string&                            measurement_name,
    const generic::ListSP<waveform_type>&         waveforms,
    const instrument_interfaces::names::MetersSP& getters,
    const generic::MapSP<instrument_interfaces::names::Meter,
                         instrument_interfaces::port_transforms::PortTransform>&
                                       meter_transforms,
    const math::domains::KnobDomainSP& time_domain)
    : BaseMessage(message),
      _measurement_name(measurement_name),
      _waveforms(waveforms),
      _getters(getters),
      _meter_transforms(meter_transforms),
      _time_domain(time_domain) {}

const std::string& MeasurementRequest::measurement_name() const {
  return _measurement_name;
}
const instrument_interfaces::names::MetersSP& MeasurementRequest::getters()
    const {
  return _getters;
}
const generic::ListSP<waveform_type>& MeasurementRequest::waveforms() const {
  return _waveforms;
}
const generic::MapSP<instrument_interfaces::names::Meter,
                     instrument_interfaces::port_transforms::PortTransform>&
MeasurementRequest::meter_transforms() const {
  return _meter_transforms;
}
const math::domains::KnobDomainSP& MeasurementRequest::time_domain() const {
  return _time_domain;
}

}  // namespace falcon_core::communications::messages

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::MeasurementRequest)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::MeasurementRequest)
