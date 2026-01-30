#include <falcon_core/communications/messages/MeasurementRequest.hpp>
#include <stdexcept>
#include <xtensor/xslice.hpp>

#include "falcon_core/instrument_interfaces/Waveform.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

namespace falcon_core {
namespace communications {
namespace messages {
MeasurementRequest::MeasurementRequest(const MeasurementRequest& other)
    : BaseMessage(other) {
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
            lock_time_domain);
  if (!other.waveforms() || !other.getters() || !other.meter_transforms() ||
      !other.time_domain()) {
    throw std::invalid_argument(
        "MeasurementRequest copy constructor: Other MeasurementRequest "
        "contains null shared pointers.");
  }
  _measurement_name = other.measurement_name();
  _waveforms = std::make_shared<generic::List<instrument_interfaces::Waveform>>(
      *other.waveforms());
  _getters =
      std::make_shared<instrument_interfaces::names::Ports>(*other.getters());
  _meter_transforms = std::make_shared<
      generic::Map<instrument_interfaces::names::InstrumentPort,
                   instrument_interfaces::port_transforms::PortTransform>>(
      *other.meter_transforms());
  _time_domain =
      std::make_shared<math::domains::LabelledDomain>(*other.time_domain());
}
MeasurementRequest& MeasurementRequest::operator=(
    const MeasurementRequest& other) {
  if (this != &other) {
    BaseMessage::operator=(other);
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
              lock_time_domain);
    if (!other.waveforms() || !other.getters() || !other.meter_transforms() ||
        !other.time_domain()) {
      throw std::invalid_argument(
          "MeasurementRequest copy constructor: Other MeasurementRequest "
          "contains null shared pointers.");
    }
    _measurement_name = other.measurement_name();
    _waveforms =
        std::make_shared<generic::List<instrument_interfaces::Waveform>>(
            *other.waveforms());
    _getters =
        std::make_shared<instrument_interfaces::names::Ports>(*other.getters());
    _meter_transforms = std::make_shared<
        generic::Map<instrument_interfaces::names::InstrumentPort,
                     instrument_interfaces::port_transforms::PortTransform>>(
        *other.meter_transforms());
    _time_domain =
        std::make_shared<math::domains::LabelledDomain>(*other.time_domain());
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
const generic::ListSP<instrument_interfaces::Waveform>
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
bool MeasurementRequest::operator==(const MeasurementRequest& other) const {
  if (this == &other) return true;
  return (measurement_name() == other.measurement_name()) &&
         (*waveforms() == *other.waveforms()) &&
         (*getters() == *other.getters()) &&
         (*meter_transforms() == *other.meter_transforms()) &&
         (*time_domain() == *other.time_domain()) &&
         BaseMessage::operator==(other);
}

bool MeasurementRequest::operator!=(const MeasurementRequest& other) const {
  return !(*this == other);
}

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
