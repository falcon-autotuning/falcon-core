#include <falcon_core/communications/messages/MeasurementRequest.hpp>

namespace falcon_core {
namespace communications {
namespace messages {

MeasurementRequest::MeasurementRequest() = default;

MeasurementRequest::MeasurementRequest(
    const std::string& message,
    const std::string& measurement_name,
    const std::vector<std::shared_ptr<instrument_interfaces::waveforms::BaseWaveform>>& waveforms,
    const std::shared_ptr<instrument_interfaces::names::Meters>& getters,
    const std::map<std::shared_ptr<instrument_interfaces::names::Meter>, std::shared_ptr<instrument_interfaces::port_transforms::PortTransform>>& meter_transforms,
    const std::shared_ptr<math::domains::KnobDomain>& time_domain)
    : BaseMessage(message),
      _measurement_name(measurement_name),
      _waveforms(waveforms),
      _getters(getters),
      _meter_transforms(meter_transforms),
      _time_domain(time_domain) {}

const std::string& MeasurementRequest::measurement_name() const { return _measurement_name; }
const std::shared_ptr<instrument_interfaces::names::Meters>& MeasurementRequest::getters() const { return _getters; }
const std::vector<std::shared_ptr<instrument_interfaces::waveforms::BaseWaveform>>& MeasurementRequest::waveforms() const { return _waveforms; }
const std::map<std::shared_ptr<instrument_interfaces::names::Meter>, std::shared_ptr<instrument_interfaces::port_transforms::PortTransform>>& MeasurementRequest::meter_transforms() const { return _meter_transforms; }
const std::shared_ptr<math::domains::KnobDomain>& MeasurementRequest::time_domain() const { return _time_domain; }

template <class Archive>
void MeasurementRequest::serialize(Archive& ar) {
  ar(cereal::base_class<BaseMessage>(this),
     _measurement_name,
     _waveforms,
     _getters,
     _meter_transforms,
     _time_domain);
}

template void MeasurementRequest::serialize<cereal::JSONOutputArchive>(cereal::JSONOutputArchive& ar);
template void MeasurementRequest::serialize<cereal::JSONInputArchive>(cereal::JSONInputArchive& ar);

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::MeasurementRequest)
