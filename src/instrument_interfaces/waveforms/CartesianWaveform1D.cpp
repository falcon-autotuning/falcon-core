#include "falcon_core/instrument_interfaces/waveforms/CartesianWaveform1D.hpp"

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/IdentityTransform.hpp"
namespace falcon_core::instrument_interfaces::waveforms {

CartesianWaveform1D::CartesianWaveform1D() = default;
CartesianWaveform1D::CartesianWaveform1D(
    const math::discrete_spaces::CartesianDiscreteSpace1DSP& space,
    const generic::ListSP<port_transforms::PortTransform>&   transforms)
    : BaseWaveform<
          falcon_core::math::discrete_spaces::CartesianDiscreteSpace1D>(
          space, transforms) {}

const CartesianWaveform1DSP from_division(
    const int&                                             division,
    const falcon_core::math::domains::CoupledKnobDomainSP& shared_domain,
    const generic::MapSP<std::string, bool>&               increasing,
    const generic::ListSP<port_transforms::PortTransform>& transforms,
    const falcon_core::math::domains::DomainSP&            domain) {
  math::discrete_spaces::CartesianDiscreteSpace1DSP space =
      math::discrete_spaces::CartesianDiscreteSpace1D::from_divisions(
          division, shared_domain, increasing, domain);
  return std::make_shared<CartesianWaveform1D>(space, transforms);
}

const CartesianWaveform1DSP setup_identity_everywhere(
    const int&                                             division,
    const falcon_core::math::domains::CoupledKnobDomainSP& shared_domain,
    const generic::MapSP<std::string, bool>&               increasing,
    const falcon_core::math::domains::DomainSP&            domain) {
  math::discrete_spaces::CartesianDiscreteSpace1DSP space =
      math::discrete_spaces::CartesianDiscreteSpace1D::from_divisions(
          division, shared_domain, increasing, domain);
  generic::ListSP<port_transforms::PortTransform> transforms =
      std::make_shared<generic::List<port_transforms::PortTransform>>();
  for (const names::KnobSP& knob : *space->knobs()) {
    transforms->push_back(std::make_shared<port_transforms::IdentityTransform>(
        std::dynamic_pointer_cast<names::InstrumentPort>(knob),
        std::dynamic_pointer_cast<names::Ports<names::InstrumentPort>>(
            space->knobs())));
  }
  return std::make_shared<CartesianWaveform1D>(space, transforms);
}

}  // namespace falcon_core::instrument_interfaces::waveforms

CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::waveforms::CartesianWaveform1D)
CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::waveforms::BaseWaveform<
        falcon_core::math::discrete_spaces::CartesianDiscreteSpace1D>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::instrument_interfaces::waveforms::BaseWaveform<
        falcon_core::math::discrete_spaces::CartesianDiscreteSpace1D>,
    falcon_core::instrument_interfaces::waveforms::CartesianWaveform1D)
