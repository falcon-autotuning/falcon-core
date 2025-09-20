#include "falcon_core/instrument_interfaces/waveforms/CartesianWaveform.hpp"

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/IdentityTransform.hpp"

namespace falcon_core::instrument_interfaces::waveforms {
CartesianWaveform::CartesianWaveform() : BaseWaveform() {}
CartesianWaveform::CartesianWaveform(
    math::discrete_spaces::CartesianDiscreteSpaceSP       space,
    const generic::ListSP<port_transforms::PortTransform> transforms)
    : BaseWaveform<falcon_core::math::discrete_spaces::CartesianDiscreteSpace>(
          space, transforms) {}

const CartesianWaveformSP CartesianWaveform::from_divisions(
    const falcon_core::math::AxesSP<int>& divisions,
    const falcon_core::math::AxesSP<
        falcon_core::math::domains::CoupledLabelledDomain>& axes,
    const falcon_core::math::AxesSP<generic::Map<std::string, bool>>&
                                                           increasing,
    const generic::ListSP<port_transforms::PortTransform>& transforms,
    const falcon_core::math::domains::DomainSP&            domain) {
  math::discrete_spaces::CartesianDiscreteSpaceSP space =
      math::discrete_spaces::CartesianDiscreteSpace::from_divisions(
          divisions, axes, increasing, domain);
  return std::make_shared<CartesianWaveform>(space, transforms);
}
const std::shared_ptr<CartesianWaveform>
CartesianWaveform::setup_identity_everywhere(
    const falcon_core::math::AxesSP<int>& divisions,
    const falcon_core::math::AxesSP<
        falcon_core::math::domains::CoupledLabelledDomain>& axes,
    const falcon_core::math::AxesSP<generic::Map<std::string, bool>>&
                                                increasing,
    const falcon_core::math::domains::DomainSP& domain) {
  math::discrete_spaces::CartesianDiscreteSpaceSP space =
      math::discrete_spaces::CartesianDiscreteSpace::from_divisions(
          divisions, axes, increasing, domain);
  generic::ListSP<port_transforms::PortTransform> transforms =
      std::make_shared<generic::List<port_transforms::PortTransform>>();
  for (const math::domains::CoupledLabelledDomainSP& knobDomain :
       *space->axes()) {
    for (const names::InstrumentPortSP& knob : *knobDomain->labels()) {
      transforms->push_back(
          std::make_shared<port_transforms::IdentityTransform>(
              std::dynamic_pointer_cast<names::InstrumentPort>(knob),
              std::dynamic_pointer_cast<names::Ports>(space->knobs())));
    }
  }
  return std::make_shared<CartesianWaveform>(space, transforms);
}
}  // namespace falcon_core::instrument_interfaces::waveforms

CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::waveforms::CartesianWaveform)
CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::waveforms::BaseWaveform<
        falcon_core::math::discrete_spaces::CartesianDiscreteSpace>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::instrument_interfaces::waveforms::BaseWaveform<
        falcon_core::math::discrete_spaces::CartesianDiscreteSpace>,
    falcon_core::instrument_interfaces::waveforms::CartesianWaveform)
