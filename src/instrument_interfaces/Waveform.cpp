#include "falcon_core/instrument_interfaces/Waveform.hpp"

namespace falcon_core::instrument_interfaces {

Waveform::Waveform() : PortTransforms(), _space(nullptr) {}
Waveform::Waveform(
    const math::discrete_spaces::DiscreteSpaceSP&          space,
    const generic::ListSP<port_transforms::PortTransform>& transforms)
    : port_transforms::PortTransforms(transforms), _space(std::move(space)) {
  confirm_knobs_match();
}
const WaveformSP Waveform::CartesianWaveform(
    const math::AxesSP<int>&                                  divisions,
    const math::AxesSP<math::domains::CoupledLabelledDomain>& axes,
    const math::AxesSP<generic::Map<std::string, bool>>&      increasing,
    const generic::ListSP<port_transforms::PortTransform>&    transforms,
    const math::domains::DomainSP&                            domain) {
  math::discrete_spaces::DiscreteSpaceSP space =
      math::discrete_spaces::DiscreteSpace::CartesianDiscreteSpace(
          divisions, axes, increasing, domain);
  return std::make_shared<Waveform>(space, transforms);
}
const WaveformSP Waveform::CartesianIdentityWaveform(
    const math::AxesSP<int>&                                  divisions,
    const math::AxesSP<math::domains::CoupledLabelledDomain>& axes,
    const math::AxesSP<generic::Map<std::string, bool>>&      increasing,
    const math::domains::DomainSP&                            domain) {
  generic::ListSP<port_transforms::PortTransform> transforms =
      std::make_shared<generic::List<port_transforms::PortTransform>>();
  for (const math::domains::CoupledLabelledDomainSP& knobDomain : *axes) {
    for (const names::InstrumentPortSP& knob : *knobDomain->labels()) {
      transforms->push_back(
          port_transforms::PortTransform::IdentityTransform(knob));
    }
  }
  return Waveform::CartesianWaveform(
      divisions, axes, increasing, transforms, domain);
}
const WaveformSP Waveform::CartesianWaveform2D(
    const math::AxesSP<int>&                                  divisions,
    const math::AxesSP<math::domains::CoupledLabelledDomain>& axes,
    const math::AxesSP<generic::Map<std::string, bool>>&      increasing,
    const generic::ListSP<port_transforms::PortTransform>&    transforms,
    const math::domains::DomainSP&                            domain) {
  if (!(divisions->size() == 2)) {
    throw std::runtime_error("Expected the divisions to be size 2, but got " +
                             std::to_string(divisions->size()) + " instead");
  }
  if (!(axes->size() == 2)) {
    throw std::runtime_error("Expected the axes to be size 2, but got " +
                             std::to_string(divisions->size()) + " instead");
  }
  if (!(increasing->size() == 2)) {
    throw std::runtime_error("Expected the increasing to be size 2, but got " +
                             std::to_string(divisions->size()) + " instead");
  }
  return Waveform::CartesianWaveform(
      divisions, axes, increasing, transforms, domain);
}
const WaveformSP Waveform::CartesianIdentityWaveform2D(
    const math::AxesSP<int>&                                  divisions,
    const math::AxesSP<math::domains::CoupledLabelledDomain>& axes,
    const math::AxesSP<generic::Map<std::string, bool>>&      increasing,
    const math::domains::DomainSP&                            domain) {
  if (!(divisions->size() == 2)) {
    throw std::runtime_error("Expected the divisions to be size 2, but got " +
                             std::to_string(divisions->size()) + " instead");
  }
  if (!(axes->size() == 2)) {
    throw std::runtime_error("Expected the axes to be size 2, but got " +
                             std::to_string(divisions->size()) + " instead");
  }
  if (!(increasing->size() == 2)) {
    throw std::runtime_error("Expected the increasing to be size 2, but got " +
                             std::to_string(divisions->size()) + " instead");
  }
  return Waveform::CartesianIdentityWaveform(
      divisions, axes, increasing, domain);
}
const WaveformSP Waveform::CartesianWaveform1D(
    const int&                                                 division,
    const falcon_core::math::domains::CoupledLabelledDomainSP& shared_domain,
    const generic::MapSP<std::string, bool>&                   increasing,
    const generic::ListSP<port_transforms::PortTransform>&     transforms,
    const falcon_core::math::domains::DomainSP&                domain) {
  return Waveform::CartesianWaveform(
      std::make_shared<math::Axes<int>>(std::vector{division}),
      std::make_shared<math::Axes<math::domains::CoupledLabelledDomain>>(
          std::vector{shared_domain}),
      std::make_shared<math::Axes<generic::Map<std::string, bool>>>(
          std::vector{increasing}),
      transforms,
      domain);
}

const WaveformSP Waveform::CartesianIdentityWaveform1D(
    const int&                                                 division,
    const falcon_core::math::domains::CoupledLabelledDomainSP& shared_domain,
    const generic::MapSP<std::string, bool>&                   increasing,
    const falcon_core::math::domains::DomainSP&                domain) {
  return Waveform::CartesianIdentityWaveform(
      std::make_shared<math::Axes<int>>(std::vector{division}),
      std::make_shared<math::Axes<math::domains::CoupledLabelledDomain>>(
          std::vector{shared_domain}),
      std::make_shared<math::Axes<generic::Map<std::string, bool>>>(
          std::vector{increasing}),
      domain);
}
const math::discrete_spaces::DiscreteSpaceSP& Waveform::space() const {
  return _space;
}
void Waveform::confirm_knobs_match() const {
  names::PortsSP discreteKnobs;
  for (const math::domains::CoupledLabelledDomainSP& axis :
       _space->axes()->items()) {
    for (const names::InstrumentPortSP& knob : *axis->labels()) {
      discreteKnobs->push_back(knob);
    }
  }
  names::PortsSP functionKnobs;
  for (const port_transforms::PortTransformSP& transform : *transforms()) {
    functionKnobs->push_back(transform->port());
  }
  for (const names::InstrumentPortSP& knob : functionKnobs->items()) {
    if (!discreteKnobs->contains(knob)) {
      throw std::runtime_error("Function knob " + knob->default_name() +
                               " not found in discrete space axes.");
    }
  }
}

}  // namespace falcon_core::instrument_interfaces
CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::Waveform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::instrument_interfaces::port_transforms::PortTransforms,
    falcon_core::instrument_interfaces::Waveform)
