#pragma once

#include "falcon_core/communications/messages/BaseMessage.hpp"
#include "falcon_core/instrument_interfaces/Waveform.hpp"
#include "falcon_core/math/domains/LabelledDomain.hpp"

namespace falcon_core {
namespace communications {
namespace messages {

// Use the base waveform type for BaseDiscreteSpace

class MeasurementRequest : public BaseMessage {
  std::string                                      _measurement_name;
  generic::ListSP<instrument_interfaces::Waveform> _waveforms;
  instrument_interfaces::names::PortsSP            _getters;
  generic::MapSP<instrument_interfaces::names::InstrumentPort,
                 instrument_interfaces::port_transforms::PortTransform>
                                  _meter_transforms;
  math::domains::LabelledDomainSP _time_domain;
  mutable std::shared_timed_mutex _mu_measurement_name;
  mutable std::shared_timed_mutex _mu_waveforms;
  mutable std::shared_timed_mutex _mu_getters;
  mutable std::shared_timed_mutex _mu_meter_transforms;
  mutable std::shared_timed_mutex _mu_time_domain;

 public:
  MeasurementRequest(const MeasurementRequest& other);
  MeasurementRequest& operator=(const MeasurementRequest& other);
  MeasurementRequest(
      const std::string&                                      message,
      const std::string&                                      measurement_name,
      const generic::ListSP<instrument_interfaces::Waveform>& waveforms,
      const instrument_interfaces::names::PortsSP&            getters,
      const generic::MapSP<
          instrument_interfaces::names::InstrumentPort,
          instrument_interfaces::port_transforms::PortTransform>&
                                             meter_transforms,
      const math::domains::LabelledDomainSP& time_domain);

  const std::string&                           measurement_name() const;
  const instrument_interfaces::names::PortsSP& getters() const;
  const generic::ListSP<instrument_interfaces::Waveform> waveforms() const;
  const generic::MapSP<instrument_interfaces::names::InstrumentPort,
                       instrument_interfaces::port_transforms::PortTransform>&
                                         meter_transforms() const;
  const math::domains::LabelledDomainSP& time_domain() const;

 protected:
  MeasurementRequest();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_mn(_mu_measurement_name,
                                                      std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_wf(_mu_waveforms,
                                                      std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_g(_mu_getters,
                                                     std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_mt(_mu_meter_transforms,
                                                      std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_td(_mu_time_domain,
                                                      std::defer_lock);
    std::lock(lock_mn, lock_wf, lock_g, lock_mt, lock_td);
    ar(cereal::base_class<BaseMessage>(this),
       _measurement_name,
       _waveforms,
       _getters,
       _meter_transforms,
       _time_domain);
  }
};
using MeasurementRequestSP = std::shared_ptr<MeasurementRequest>;
}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
