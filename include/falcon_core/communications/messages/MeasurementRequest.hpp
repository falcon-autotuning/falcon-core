#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>
#include <falcon_core/instrument_interfaces/Waveform.hpp>
#include <falcon_core/instrument_interfaces/names/Ports.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransforms.hpp>
#include <falcon_core/math/discrete_spaces/DiscreteSpace.hpp>
#include <falcon_core/math/domains/LabelledDomain.hpp>

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

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

 public:
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
  const generic::ListSP<instrument_interfaces::Waveform>& waveforms() const;
  const generic::MapSP<instrument_interfaces::names::InstrumentPort,
                       instrument_interfaces::port_transforms::PortTransform>&
                                         meter_transforms() const;
  const math::domains::LabelledDomainSP& time_domain() const;

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
}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
