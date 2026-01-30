#include "falcon_core/instrument_interfaces/Waveform.hpp"

#include <stdexcept>

#include "falcon_core/generic/Map.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransforms.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"

namespace falcon_core {
namespace instrument_interfaces {
Waveform::Waveform(const Waveform& other)
    : port_transforms::PortTransforms(other) {
  // Only lock other._mu_dspace if needed
  std::shared_lock<std::shared_timed_mutex> lock_other_space(other._mu_dspace);
  if (!other._space) {
    throw std::invalid_argument(
        "Waveform copy constructor: Other Waveform contains null shared "
        "pointer for space.");
  }
  _space =
      std::make_shared<math::discrete_spaces::DiscreteSpace>(*other._space);
}
Waveform& Waveform::operator=(const Waveform& other) {
  if (this != &other) {
    port_transforms::PortTransforms::operator=(other);
    std::unique_lock<std::shared_timed_mutex> lock_o(_mu_dspace);
    if (!other._space) {
      throw std::invalid_argument(
          "Waveform copy constructor: Other Waveform contains null shared "
          "pointer for space.");
    }
    _space =
        std::make_shared<math::discrete_spaces::DiscreteSpace>(*other._space);
  }
  return *this;
}

const generic::ListSP<port_transforms::PortTransform>& wave_check_and_deref(
    const generic::ListSP<port_transforms::PortTransform>& transforms) {
  if (!transforms)
    throw std::invalid_argument("Waveform: The transforms must not be null.");
  return transforms;
}
Waveform::Waveform() : PortTransforms(), _space(nullptr) {}
Waveform::Waveform(
    const math::discrete_spaces::DiscreteSpaceSP&          space,
    const generic::ListSP<port_transforms::PortTransform>& transforms)
    : port_transforms::PortTransforms(wave_check_and_deref(transforms)),
      _space(space) {
  if (!space || !transforms) {
    throw std::invalid_argument(
        "Waveform: The space and transforms must not be null.");
  }
  if (transforms->empty()) {
    throw std::invalid_argument("Waveform: The transforms must not be empty.");
  }
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
  if (!axes) {
    throw std::invalid_argument("Waveform: The axes cannot be null.");
  }
  generic::ListSP<port_transforms::PortTransform> transforms =
      std::make_shared<generic::List<port_transforms::PortTransform>>();
  for (const math::domains::CoupledLabelledDomainSP& knobDomain : *axes) {
    auto knobs = *knobDomain->labels();
    for (const names::InstrumentPortSP& knob : knobs) {
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
  if (!divisions || !axes || !increasing) {
    throw std::invalid_argument(
        "Waveform: The divisions, axes, and increasing cannot be null.");
  }
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
  if (!divisions || !axes || !increasing) {
    throw std::invalid_argument(
        "Waveform: The divisions, axes, and increasing cannot be null.");
  }
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
    const int&                                             division,
    const math::domains::CoupledLabelledDomainSP&          shared_domain,
    const generic::MapSP<std::string, bool>&               increasing,
    const generic::ListSP<port_transforms::PortTransform>& transforms,
    const falcon_core::math::domains::DomainSP&            domain) {
  return Waveform::CartesianWaveform(
      std::make_shared<math::Axes<int>>(std::vector<int>{division}),
      std::make_shared<math::Axes<math::domains::CoupledLabelledDomain>>(
          std::vector<math::domains::CoupledLabelledDomainSP>{shared_domain}),
      std::make_shared<math::Axes<generic::Map<std::string, bool>>>(
          std::vector<generic::MapSP<std::string, bool>>{increasing}),
      transforms,
      domain);
}

const WaveformSP Waveform::CartesianIdentityWaveform1D(
    const int&                                                 division,
    const falcon_core::math::domains::CoupledLabelledDomainSP& shared_domain,
    const generic::MapSP<std::string, bool>&                   increasing,
    const falcon_core::math::domains::DomainSP&                domain) {
  return Waveform::CartesianIdentityWaveform(
      std::make_shared<math::Axes<int>>(std::vector<int>{division}),
      std::make_shared<math::Axes<math::domains::CoupledLabelledDomain>>(
          std::vector<math::domains::CoupledLabelledDomainSP>{shared_domain}),
      std::make_shared<math::Axes<generic::Map<std::string, bool>>>(
          std::vector<generic::MapSP<std::string, bool>>{increasing}),
      domain);
}
const math::discrete_spaces::DiscreteSpaceSP& Waveform::space() const {
  std::shared_lock<std::shared_timed_mutex> lock_s(_mu_dspace);
  return _space;
}
void Waveform::confirm_knobs_match() const {
  names::PortsSP discreteKnobs = std::make_shared<names::Ports>();
  auto           all_axes      = space()->axes()->items();
  for (const math::domains::CoupledLabelledDomainSP& axis : all_axes) {
    auto axis_labels = *axis->labels();
    for (const names::InstrumentPortSP& knob : axis_labels) {
      discreteKnobs->push_back(knob);
    }
  }
  names::PortsSP functionKnobs           = std::make_shared<names::Ports>();
  auto           dereferenced_transforms = *transforms();
  for (const port_transforms::PortTransformSP& transform :
       dereferenced_transforms) {
    functionKnobs->push_back(transform->port());
  }
  auto knobs = functionKnobs->items();
  for (const names::InstrumentPortSP& knob : knobs) {
    if (!discreteKnobs->contains(knob)) {
      throw std::runtime_error("Function knob " + knob->default_name() +
                               " not found in discrete space axes.");
    }
  }
}
bool Waveform::operator==(const Waveform& other) const {
  if (this == &other) return true;
  return (*space() == *other.space()) &&
         port_transforms::PortTransforms::operator==(other);
}
bool Waveform::operator!=(const Waveform& other) const {
  return !(*this == other);
}

}  // namespace instrument_interfaces
}  // namespace falcon_core
