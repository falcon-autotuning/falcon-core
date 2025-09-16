#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>
#include <falcon_core/instrument_interfaces/names/Meters.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransforms.hpp>
#include <falcon_core/instrument_interfaces/waveforms/BaseWaveform.hpp>
#include <falcon_core/math/discrete_spaces/BaseDiscreteSpace.hpp>
#include <falcon_core/math/domains/KnobDomain.hpp>
#include <falcon_core/physics/units/Units.hpp>

namespace falcon_core::communications::messages {

// Use the base waveform type for BaseDiscreteSpace

class MeasurementRequest : public BaseMessage {
  using waveform_type =
      falcon_core::instrument_interfaces::waveforms::BaseWaveform<
          falcon_core::math::discrete_spaces::BaseDiscreteSpace>;
  std::string                            _measurement_name;
  generic::ListSP<waveform_type>         _waveforms;
  instrument_interfaces::names::MetersSP _getters;
  generic::MapSP<instrument_interfaces::names::Meter,
                 instrument_interfaces::port_transforms::PortTransform>
                              _meter_transforms;
  math::domains::KnobDomainSP _time_domain;

 public:
  MeasurementRequest(const std::string&                    message,
                     const std::string&                    measurement_name,
                     const generic::ListSP<waveform_type>& waveforms,
                     const instrument_interfaces::names::MetersSP& getters,
                     const generic::MapSP<
                         instrument_interfaces::names::Meter,
                         instrument_interfaces::port_transforms::PortTransform>&
                                                        meter_transforms,
                     const math::domains::KnobDomainSP& time_domain);

  const std::string&                            measurement_name() const;
  const instrument_interfaces::names::MetersSP& getters() const;
  const generic::ListSP<waveform_type>&         waveforms() const;
  const generic::MapSP<instrument_interfaces::names::Meter,
                       instrument_interfaces::port_transforms::PortTransform>&
                                     meter_transforms() const;
  const math::domains::KnobDomainSP& time_domain() const;

 protected:
  MeasurementRequest();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseMessage>(this),
       _measurement_name,
       _waveforms,
       _getters,
       _meter_transforms,
       _time_domain);
  }
};
using MeasurementRequestSP = std::shared_ptr<MeasurementRequest>;
}  // namespace falcon_core::communications::messages
