#include <falcon_core/communications/messages/MeasurementRequest.hpp>
#include <stdexcept>

#include "falcon_core/instrument_interfaces/Waveform.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

namespace falcon_core {
namespace communications {
namespace messages {
MeasurementRequest::MeasurementRequest(const MeasurementRequest& other)
    : BaseMessage(other) {
  std::shared_lock<std::shared_timed_mutex> lock_measurement_name(
      other._mu_measurement_name, std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_waveforms(other._mu_waveforms,
                                                           std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_getters(other._mu_getters,
                                                         std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_meter_transforms(
      other._mu_meter_transforms, std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_time_domain(
      other._mu_time_domain, std::defer_lock);
  std::lock(lock_measurement_name,
            lock_waveforms,
            lock_getters,
            lock_meter_transforms,
            lock_time_domain);
  _measurement_name = other._measurement_name;
  _waveforms        = other._waveforms;
  _getters          = other._getters;
  _meter_transforms = other._meter_transforms;
  _time_domain      = other._time_domain;
}
MeasurementRequest MeasurementRequest::operator=(
    const MeasurementRequest& other) {
  if (this != &other) {
    BaseMessage::                             operator=(other);
    std::shared_lock<std::shared_timed_mutex> lock_other_measurement_name(
        other._mu_measurement_name, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_other_waveforms(
        other._mu_waveforms, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_other_getters(
        other._mu_getters, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_other_meter_transforms(
        other._mu_meter_transforms, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_other_time_domain(
        other._mu_time_domain, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_measurement_name(
        _mu_measurement_name, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_waveforms(_mu_waveforms,
                                                             std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_getters(_mu_getters,
                                                           std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_meter_transforms(
        _mu_meter_transforms, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_time_domain(_mu_time_domain,
                                                               std::defer_lock);
    std::lock(lock_measurement_name,
              lock_waveforms,
              lock_getters,
              lock_meter_transforms,
              lock_time_domain,
              lock_other_measurement_name,
              lock_other_waveforms,
              lock_other_getters,
              lock_other_time_domain,
              lock_other_meter_transforms);
    _measurement_name = other._measurement_name;
    _waveforms        = other._waveforms;
    _getters          = other._getters;
    _meter_transforms = other._meter_transforms;
  }
  return *this;
}
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
      _time_domain(time_domain) {
  if (!waveforms || !getters || !meter_transforms || !time_domain) {
    throw std::invalid_argument(
        "MeasurementRequest: The waveforms, getters, and meter transforms "
        "must "
        "not be null.");
  }
}

const std::string& MeasurementRequest::measurement_name() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_measurement_name);
  return _measurement_name;
}
const instrument_interfaces::names::PortsSP& MeasurementRequest::getters()
    const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_getters);
  return _getters;
}
const generic::ListSP<instrument_interfaces::Waveform>&
MeasurementRequest::waveforms() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_waveforms);
  return _waveforms;
}
const generic::MapSP<instrument_interfaces::names::InstrumentPort,
                     instrument_interfaces::port_transforms::PortTransform>&
MeasurementRequest::meter_transforms() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_meter_transforms);
  return _meter_transforms;
}
const math::domains::LabelledDomainSP& MeasurementRequest::time_domain() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_time_domain);
  return _time_domain;
}

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::MeasurementRequest)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::MeasurementRequest)
