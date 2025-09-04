#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>
#include <falcon_core/instrument_interfaces/names/Meters.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransforms.hpp>
#include <falcon_core/instrument_interfaces/waveforms/BaseWaveform.hpp>
#include <falcon_core/math/discrete_spaces/BaseDiscreteSpace.hpp>
#include <falcon_core/math/domains/KnobDomain.hpp>
#include <falcon_core/physics/units/Units.hpp>
#include <memory>
#include <string>
#include <map>
#include <vector>

namespace falcon_core {
namespace communications {
namespace messages {

class MeasurementRequest : public BaseMessage {
 public:
  MeasurementRequest();
  MeasurementRequest(
      const std::string& message,
      const std::string& measurement_name,
      const std::vector<std::shared_ptr<instrument_interfaces::waveforms::BaseWaveform>>& waveforms,
      const std::shared_ptr<instrument_interfaces::names::Meters>& getters,
      const std::map<std::shared_ptr<instrument_interfaces::names::Meter>, std::shared_ptr<instrument_interfaces::port_transforms::PortTransform>>& meter_transforms,
      const std::shared_ptr<math::domains::KnobDomain>& time_domain);

  const std::string& measurement_name() const;
  const std::shared_ptr<instrument_interfaces::names::Meters>& getters() const;
  const std::vector<std::shared_ptr<instrument_interfaces::waveforms::BaseWaveform>>& waveforms() const;
  const std::map<std::shared_ptr<instrument_interfaces::names::Meter>, std::shared_ptr<instrument_interfaces::port_transforms::PortTransform>>& meter_transforms() const;
  const std::shared_ptr<math::domains::KnobDomain>& time_domain() const;

 private:
  std::string _measurement_name;
  std::vector<std::shared_ptr<instrument_interfaces::waveforms::BaseWaveform>> _waveforms;
  std::shared_ptr<instrument_interfaces::names::Meters> _getters;
  std::map<std::shared_ptr<instrument_interfaces::names::Meter>, std::shared_ptr<instrument_interfaces::port_transforms::PortTransform>> _meter_transforms;
  std::shared_ptr<math::domains::KnobDomain> _time_domain;

  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
