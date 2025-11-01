#include "falcon_core/instrument_interfaces/Waveform_c_api.h"

#include <falcon_core/instrument_interfaces/Waveform.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/discrete_spaces/DiscreteSpace.hpp"
using namespace falcon_core;
using namespace instrument_interfaces;
using namespace names;

WaveformHandle Waveform_create(DiscreteSpaceHandle     space,
                               ListPortTransformHandle transforms) {
  if (!space) {
    throw std::invalid_argument("Waveform_create: space cannot be null");
  }
  if (!transforms) {
    throw std::invalid_argument("Waveform_create: transforms cannot be null");
  }
  math::discrete_spaces::DiscreteSpaceSP self_space =
      std::make_shared<math::discrete_spaces::DiscreteSpace>(
          *static_cast<math::discrete_spaces::DiscreteSpace*>(space));
  generic::ListSP<port_transforms::PortTransform> self_transforms =
      std::make_shared<generic::List<port_transforms::PortTransform>>(
          *static_cast<generic::List<port_transforms::PortTransform>*>(
              transforms));
  return new Waveform(self_space, self_transforms);
}

WaveformHandle Waveform_create_cartesianwaveform(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    ListPortTransformHandle         transforms,
    DomainHandle                    domain) {
  if (!divisions) {
    throw std::invalid_argument(
        "Waveform_create_cartesianwaveform: divisions "
        "cannot be null");
  }
  if (!axes) {
    throw std::invalid_argument(
        "Waveform_create_cartesianwaveform: axes cannot "
        "be null");
  }
  if (!increasing) {
    throw std::invalid_argument(
        "Waveform_create_cartesianwaveform: increasing cannot be null");
  }
  if (!transforms) {
    throw std::invalid_argument(
        "Waveform_create_cartesianwaveform: transforms "
        "cannot be null");
  }
  math::AxesSP<int> self_divisions = std::make_shared<math::Axes<int>>(
      *static_cast<math::Axes<int>*>(divisions));
  math::AxesSP<math::domains::CoupledLabelledDomain> self_axes =
      std::make_shared<math::Axes<math::domains::CoupledLabelledDomain>>(
          *static_cast<math::Axes<math::domains::CoupledLabelledDomain>*>(
              axes));
  math::AxesSP<generic::Map<std::string, bool>> self_increasing =
      std::make_shared<math::Axes<generic::Map<std::string, bool>>>(
          *static_cast<math::Axes<generic::Map<std::string, bool>>*>(
              increasing));
  generic::ListSP<port_transforms::PortTransform> self_transforms =
      std::make_shared<generic::List<port_transforms::PortTransform>>(
          *static_cast<generic::List<port_transforms::PortTransform>*>(
              transforms));
  math::domains::DomainSP self_domain = std::make_shared<math::domains::Domain>(
      *static_cast<math::domains::Domain*>(domain));
  return new Waveform(*Waveform::CartesianWaveform(self_divisions,
                                                   self_axes,
                                                   self_increasing,
                                                   self_transforms,
                                                   self_domain));
}
WaveformHandle Waveform_create_cartesianidentitywaveform(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    DomainHandle                    domain) {
  if (!divisions) {
    throw std::invalid_argument(
        "Waveform_create_cartesianidentitywaveform: divisions "
        "cannot be null");
  }
  if (!axes) {
    throw std::invalid_argument(
        "Waveform_create_cartesianidentitywaveform: axes cannot "
        "be null");
  }
  if (!increasing) {
    throw std::invalid_argument(
        "Waveform_create_cartesianidentitywaveform: increasing cannot be null");
  }
  math::AxesSP<int> self_divisions = std::make_shared<math::Axes<int>>(
      *static_cast<math::Axes<int>*>(divisions));
  math::AxesSP<math::domains::CoupledLabelledDomain> self_axes =
      std::make_shared<math::Axes<math::domains::CoupledLabelledDomain>>(
          *static_cast<math::Axes<math::domains::CoupledLabelledDomain>*>(
              axes));
  math::AxesSP<generic::Map<std::string, bool>> self_increasing =
      std::make_shared<math::Axes<generic::Map<std::string, bool>>>(
          *static_cast<math::Axes<generic::Map<std::string, bool>>*>(
              increasing));
  math::domains::DomainSP self_domain = std::make_shared<math::domains::Domain>(
      *static_cast<math::domains::Domain*>(domain));
  return new Waveform(*Waveform::CartesianIdentityWaveform(
      self_divisions, self_axes, self_increasing, self_domain));
}

WaveformHandle Waveform_create_cartesianwaveform2D(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    ListPortTransformHandle         transforms,
    DomainHandle                    domain) {
  if (!divisions) {
    throw std::invalid_argument(
        "Waveform_create_cartesianwaveform2D: divisions "
        "cannot be null");
  }
  if (!axes) {
    throw std::invalid_argument(
        "Waveform_create_cartesianwaveform2D: axes cannot "
        "be null");
  }
  if (!increasing) {
    throw std::invalid_argument(
        "Waveform_create_cartesianwaveform2D: increasing cannot be null");
  }
  if (!transforms) {
    throw std::invalid_argument(
        "Waveform_create_cartesianwaveform2D: transforms "
        "cannot be null");
  }
  math::AxesSP<int> self_divisions = std::make_shared<math::Axes<int>>(
      *static_cast<math::Axes<int>*>(divisions));
  math::AxesSP<math::domains::CoupledLabelledDomain> self_axes =
      std::make_shared<math::Axes<math::domains::CoupledLabelledDomain>>(
          *static_cast<math::Axes<math::domains::CoupledLabelledDomain>*>(
              axes));
  math::AxesSP<generic::Map<std::string, bool>> self_increasing =
      std::make_shared<math::Axes<generic::Map<std::string, bool>>>(
          *static_cast<math::Axes<generic::Map<std::string, bool>>*>(
              increasing));
  math::domains::DomainSP self_domain = std::make_shared<math::domains::Domain>(
      *static_cast<math::domains::Domain*>(domain));
  generic::ListSP<port_transforms::PortTransform> self_transforms =
      std::make_shared<generic::List<port_transforms::PortTransform>>(
          *static_cast<generic::List<port_transforms::PortTransform>*>(
              transforms));
  return new Waveform(*Waveform::CartesianWaveform2D(self_divisions,
                                                     self_axes,
                                                     self_increasing,
                                                     self_transforms,
                                                     self_domain));
}

WaveformHandle Waveform_create_cartesianidentitywaveform2D(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    DomainHandle                    domain) {
  if (!divisions) {
    throw std::invalid_argument(
        "Waveform_create_cartesianidentitywaveform2D: divisions "
        "cannot be null");
  }
  if (!axes) {
    throw std::invalid_argument(
        "Waveform_create_cartesianidentitywaveform2D: axes cannot "
        "be null");
  }
  if (!increasing) {
    throw std::invalid_argument(
        "Waveform_create_cartesianidentitywaveform2D: increasing cannot be "
        "null");
  }
  math::AxesSP<int> self_divisions = std::make_shared<math::Axes<int>>(
      *static_cast<math::Axes<int>*>(divisions));
  math::AxesSP<math::domains::CoupledLabelledDomain> self_axes =
      std::make_shared<math::Axes<math::domains::CoupledLabelledDomain>>(
          *static_cast<math::Axes<math::domains::CoupledLabelledDomain>*>(
              axes));
  math::AxesSP<generic::Map<std::string, bool>> self_increasing =
      std::make_shared<math::Axes<generic::Map<std::string, bool>>>(
          *static_cast<math::Axes<generic::Map<std::string, bool>>*>(
              increasing));
  math::domains::DomainSP self_domain = std::make_shared<math::domains::Domain>(
      *static_cast<math::domains::Domain*>(domain));
  return new Waveform(*Waveform::CartesianIdentityWaveform2D(
      self_divisions, self_axes, self_increasing, self_domain));
}

WaveformHandle Waveform_create_cartesianwaveform1D(
    int                         division,
    CoupledLabelledDomainHandle shared_domain,
    MapStringBoolHandle         increasing,
    ListPortTransformHandle     transforms,
    DomainHandle                domain) {
  if (!shared_domain) {
    throw std::invalid_argument(
        "Waveform_create_cartesianwaveform1D: shared_domain cannot be null");
  }
  if (!increasing) {
    throw std::invalid_argument(
        "Waveform_create_cartesianwaveform1D: increasing cannot be null");
  }
  if (!transforms) {
    throw std::invalid_argument(
        "Waveform_create_cartesianwaveform1D: transforms cannot be null");
  }
  math::domains::CoupledLabelledDomainSP self_shared_domain =
      std::make_shared<math::domains::CoupledLabelledDomain>(
          *static_cast<math::domains::CoupledLabelledDomain*>(shared_domain));
  generic::MapSP<std::string, bool> self_increasing =
      std::make_shared<generic::Map<std::string, bool>>(
          *static_cast<generic::Map<std::string, bool>*>(increasing));
  generic::ListSP<port_transforms::PortTransform> self_transforms =
      std::make_shared<generic::List<port_transforms::PortTransform>>(
          *static_cast<generic::List<port_transforms::PortTransform>*>(
              transforms));
  math::domains::DomainSP self_domain = std::make_shared<math::domains::Domain>(
      *static_cast<math::domains::Domain*>(domain));
  return new Waveform(*Waveform::CartesianWaveform1D(division,
                                                     self_shared_domain,
                                                     self_increasing,
                                                     self_transforms,
                                                     self_domain));
}

WaveformHandle Waveform_create_cartesianidentitywaveform1D(
    int                         division,
    CoupledLabelledDomainHandle shared_domain,
    MapStringBoolHandle         increasing,
    DomainHandle                domain) {
  if (!shared_domain) {
    throw std::invalid_argument(
        "Waveform_create_cartesianidentitywaveform1D: shared_domain cannot be "
        "null");
  }
  if (!increasing) {
    throw std::invalid_argument(
        "Waveform_create_cartesianidentitywaveform1D: increasing cannot be "
        "null");
  }
  math::domains::CoupledLabelledDomainSP self_shared_domain =
      std::make_shared<math::domains::CoupledLabelledDomain>(
          *static_cast<math::domains::CoupledLabelledDomain*>(shared_domain));
  generic::MapSP<std::string, bool> self_increasing =
      std::make_shared<generic::Map<std::string, bool>>(
          *static_cast<generic::Map<std::string, bool>*>(increasing));
  math::domains::DomainSP self_domain = std::make_shared<math::domains::Domain>(
      *static_cast<math::domains::Domain*>(domain));
  return new Waveform(*Waveform::CartesianIdentityWaveform1D(
      division, self_shared_domain, self_increasing, self_domain));
}

void Waveform_destroy(WaveformHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Waveform_destroy: handle cannot be null");
  }
  delete static_cast<Waveform*>(handle);
}

DiscreteSpaceHandle Waveform_space(WaveformHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Waveform_space: handle cannot be null");
  }
  Waveform self = *static_cast<Waveform*>(handle);
  return new math::discrete_spaces::DiscreteSpace(*self.space());
}

ListPortTransformHandle Waveform_transforms(WaveformHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Waveform_transforms: handle cannot be null");
  }
  return new generic::List<port_transforms::PortTransform>(
      *static_cast<Waveform*>(handle)->transforms());
}

void Waveform_push_back(WaveformHandle handle, PortTransformHandle value) {
  if (!handle) {
    throw std::invalid_argument("Waveform_push_back: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Waveform_push_back: value cannot be null");
  }
  static_cast<Waveform*>(handle)->push_back(
      std::make_shared<port_transforms::PortTransform>(
          *static_cast<port_transforms::PortTransform*>(value)));
}

size_t Waveform_size(WaveformHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Waveform_size: handle cannot be null");
  }
  Waveform self = *static_cast<Waveform*>(handle);
  return self.size();
}

bool Waveform_empty(WaveformHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Waveform_empty: handle cannot be null");
  }
  Waveform self = *static_cast<Waveform*>(handle);
  return self.empty();
}

void Waveform_erase_at(WaveformHandle handle, size_t idx) {
  if (!handle) {
    throw std::invalid_argument("Waveform_erase_at: handle cannot be null");
  }
  Waveform* self = static_cast<Waveform*>(handle);
  self->erase_at(idx);
}

void Waveform_clear(WaveformHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Waveform_clear: handle cannot be null");
  }
  Waveform* self = static_cast<Waveform*>(handle);
  self->clear();
}

PortTransformHandle Waveform_at(WaveformHandle handle, size_t idx) {
  if (!handle) {
    throw std::invalid_argument("Waveform_at: handle cannot be null");
  }
  Waveform self = *static_cast<Waveform*>(handle);
  return new port_transforms::PortTransform(*self.at(idx));
}

ListPortTransformHandle Waveform_items(WaveformHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Waveform_items: handle cannot be null");
  }
  Waveform self = *static_cast<Waveform*>(handle);
  return new generic::List<port_transforms::PortTransform>(self.items());
}

bool Waveform_contains(WaveformHandle handle, PortTransformHandle value) {
  if (!handle) {
    throw std::invalid_argument("Waveform_contains: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Waveform_contains: value cannot be null");
  }
  Waveform                         self = *static_cast<Waveform*>(handle);
  port_transforms::PortTransformSP real_value =
      std::make_shared<port_transforms::PortTransform>(
          *static_cast<port_transforms::PortTransform*>(value));
  return self.contains(real_value);
}

size_t Waveform_index(WaveformHandle handle, PortTransformHandle value) {
  if (!handle) {
    throw std::invalid_argument("Waveform_index: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Waveform_index: value cannot be null");
  }
  Waveform                         self = *static_cast<Waveform*>(handle);
  port_transforms::PortTransformSP real_value =
      std::make_shared<port_transforms::PortTransform>(
          *static_cast<port_transforms::PortTransform*>(value));
  return self.index(real_value);
}

WaveformHandle Waveform_intersection(WaveformHandle handle,
                                     WaveformHandle other) {
  if (!handle) {
    throw std::invalid_argument("Waveform_intersection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Waveform_intersection: other cannot be null");
  }
  Waveform   self = *static_cast<Waveform*>(handle);
  WaveformSP real_other =
      std::make_shared<Waveform>(*static_cast<Waveform*>(other));
  generic::ListSP<port_transforms::PortTransform> result =
      self.intersection(real_other);
  return new Waveform(self.space(), result);
}

bool Waveform_equal(WaveformHandle handle, WaveformHandle other) {
  if (!handle) {
    throw std::invalid_argument("Waveform_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Waveform_equal: other cannot be null");
  }
  return *(static_cast<Waveform*>(handle)) == *(static_cast<Waveform*>(other));
}

bool Waveform_not_equal(WaveformHandle handle, WaveformHandle other) {
  if (!handle) {
    throw std::invalid_argument("Waveform_not_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Waveform_not_equal: other cannot be null");
  }
  return *(static_cast<Waveform*>(handle)) != *(static_cast<Waveform*>(other));
}

StringHandle Waveform_to_json_string(WaveformHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Waveform_to_json_string: handle cannot be null");
  }
  Waveform self = *static_cast<Waveform*>(handle);
  return String_create(self.to_json_string().c_str(),
                       self.to_json_string().size());
}

WaveformHandle Waveform_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "PortTransform_from_json_string: json cannot be null");
  }
  std::string real_json(json->raw, json->length);
  WaveformSP  real_waveform = Waveform::from_json_string<Waveform>(real_json);
  return new Waveform(*real_waveform);
}
