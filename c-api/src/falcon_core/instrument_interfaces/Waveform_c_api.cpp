#include "falcon_core/instrument_interfaces/Waveform_c_api.h"

#include <falcon_core/instrument_interfaces/Waveform.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/discrete_spaces/DiscreteSpace.hpp"
using namespace falcon_core;
using namespace instrument_interfaces;
using namespace names;

extern "C" {
WaveformHandle Waveform_create(DiscreteSpaceHandle     space,
                               ListPortTransformHandle transforms) {
  FALCON_C_API_BEGIN
  if (!space) {
    throw std::invalid_argument("Waveform_create: space cannot be null");
  }
  if (!transforms) {
    throw std::invalid_argument("Waveform_create: transforms cannot be null");
  }
  math::discrete_spaces::DiscreteSpaceSP self_space =
      *static_cast<math::discrete_spaces::DiscreteSpaceSP*>(space);
  generic::ListSP<port_transforms::PortTransform> self_transforms =
      *static_cast<generic::ListSP<port_transforms::PortTransform>*>(
          transforms);
  return new WaveformSP(
      std::make_shared<Waveform>(self_space, self_transforms));
  FALCON_C_API_END(nullptr)
}

WaveformHandle Waveform_create_cartesian_waveform(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    ListPortTransformHandle         transforms,
    DomainHandle                    domain) {
  FALCON_C_API_BEGIN
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
  if (!domain) {
    throw std::invalid_argument(
        "Waveform_create_cartesianwaveform: domain cannot be null");
  }
  math::AxesSP<int> self_divisions =
      *static_cast<math::AxesSP<int>*>(divisions);
  math::AxesSP<math::domains::CoupledLabelledDomain> self_axes =
      *static_cast<math::AxesSP<math::domains::CoupledLabelledDomain>*>(axes);
  math::AxesSP<generic::Map<std::string, bool>> self_increasing =
      *static_cast<math::AxesSP<generic::Map<std::string, bool>>*>(increasing);
  generic::ListSP<port_transforms::PortTransform> self_transforms =
      *static_cast<generic::ListSP<port_transforms::PortTransform>*>(
          transforms);
  math::domains::DomainSP self_domain =
      *static_cast<math::domains::DomainSP*>(domain);
  return new WaveformSP(Waveform::CartesianWaveform(self_divisions,
                                                    self_axes,
                                                    self_increasing,
                                                    self_transforms,
                                                    self_domain));
  FALCON_C_API_END(nullptr)
}
WaveformHandle Waveform_create_cartesian_identity_waveform(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    DomainHandle                    domain) {
  FALCON_C_API_BEGIN
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
  math::AxesSP<int> self_divisions =
      *static_cast<math::AxesSP<int>*>(divisions);
  math::AxesSP<math::domains::CoupledLabelledDomain> self_axes =
      *static_cast<math::AxesSP<math::domains::CoupledLabelledDomain>*>(axes);
  math::AxesSP<generic::Map<std::string, bool>> self_increasing =
      *static_cast<math::AxesSP<generic::Map<std::string, bool>>*>(increasing);
  math::domains::DomainSP self_domain =
      *static_cast<math::domains::DomainSP*>(domain);
  return new WaveformSP(Waveform::CartesianIdentityWaveform(
      self_divisions, self_axes, self_increasing, self_domain));
  FALCON_C_API_END(nullptr)
}

WaveformHandle Waveform_create_cartesian_waveform_2D(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    ListPortTransformHandle         transforms,
    DomainHandle                    domain) {
  FALCON_C_API_BEGIN
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
  if (!domain) {
    throw std::invalid_argument(
        "Waveform_create_cartesianwaveform2D: domain cannot be null");
  }
  math::AxesSP<int> self_divisions =
      *static_cast<math::AxesSP<int>*>(divisions);
  math::AxesSP<math::domains::CoupledLabelledDomain> self_axes =
      *static_cast<math::AxesSP<math::domains::CoupledLabelledDomain>*>(axes);
  math::AxesSP<generic::Map<std::string, bool>> self_increasing =
      *static_cast<math::AxesSP<generic::Map<std::string, bool>>*>(increasing);
  math::domains::DomainSP self_domain =
      *static_cast<math::domains::DomainSP*>(domain);
  generic::ListSP<port_transforms::PortTransform> self_transforms =
      *static_cast<generic::ListSP<port_transforms::PortTransform>*>(
          transforms);
  return new WaveformSP(Waveform::CartesianWaveform2D(self_divisions,
                                                      self_axes,
                                                      self_increasing,
                                                      self_transforms,
                                                      self_domain));
  FALCON_C_API_END(nullptr)
}

WaveformHandle Waveform_create_cartesian_identity_waveform_2D(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    DomainHandle                    domain) {
  FALCON_C_API_BEGIN
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
  if (!domain) {
    throw std::invalid_argument(
        "Waveform_create_cartesianidentitywaveform2D: domain cannot be null");
  }
  math::AxesSP<int> self_divisions =
      *static_cast<math::AxesSP<int>*>(divisions);
  math::AxesSP<math::domains::CoupledLabelledDomain> self_axes =
      *static_cast<math::AxesSP<math::domains::CoupledLabelledDomain>*>(axes);
  math::AxesSP<generic::Map<std::string, bool>> self_increasing =
      *static_cast<math::AxesSP<generic::Map<std::string, bool>>*>(increasing);
  math::domains::DomainSP self_domain =
      *static_cast<math::domains::DomainSP*>(domain);
  return new WaveformSP(Waveform::CartesianIdentityWaveform2D(
      self_divisions, self_axes, self_increasing, self_domain));
  FALCON_C_API_END(nullptr)
}

WaveformHandle Waveform_create_cartesian_waveform_1D(
    int                         division,
    CoupledLabelledDomainHandle shared_domain,
    MapStringBoolHandle         increasing,
    ListPortTransformHandle     transforms,
    DomainHandle                domain) {
  FALCON_C_API_BEGIN
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
  if (!domain) {
    throw std::invalid_argument(
        "Waveform_create_cartesianwaveform1D: domain cannot be null");
  }
  math::domains::CoupledLabelledDomainSP self_shared_domain =
      *static_cast<math::domains::CoupledLabelledDomainSP*>(shared_domain);
  generic::MapSP<std::string, bool> self_increasing =
      *static_cast<generic::MapSP<std::string, bool>*>(increasing);
  generic::ListSP<port_transforms::PortTransform> self_transforms =
      *static_cast<generic::ListSP<port_transforms::PortTransform>*>(
          transforms);
  math::domains::DomainSP self_domain =
      *static_cast<math::domains::DomainSP*>(domain);
  return new WaveformSP(Waveform::CartesianWaveform1D(division,
                                                      self_shared_domain,
                                                      self_increasing,
                                                      self_transforms,
                                                      self_domain));
  FALCON_C_API_END(nullptr)
}

WaveformHandle Waveform_create_cartesian_identity_waveform_1D(
    int                         division,
    CoupledLabelledDomainHandle shared_domain,
    MapStringBoolHandle         increasing,
    DomainHandle                domain) {
  FALCON_C_API_BEGIN
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
  if (!domain) {
    throw std::invalid_argument(
        "Waveform_create_cartesianidentitywaveform1D: domain cannot be null");
  }
  math::domains::CoupledLabelledDomainSP self_shared_domain =
      *static_cast<math::domains::CoupledLabelledDomainSP*>(shared_domain);
  generic::MapSP<std::string, bool> self_increasing =
      *static_cast<generic::MapSP<std::string, bool>*>(increasing);
  math::domains::DomainSP self_domain =
      *static_cast<math::domains::DomainSP*>(domain);
  return new WaveformSP(Waveform::CartesianIdentityWaveform1D(
      division, self_shared_domain, self_increasing, self_domain));
  FALCON_C_API_END(nullptr)
}

void Waveform_destroy(WaveformHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Waveform_destroy: handle cannot be null");
  }
  delete static_cast<WaveformSP*>(handle);
  FALCON_C_API_END()
}

DiscreteSpaceHandle Waveform_space(WaveformHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Waveform_space: handle cannot be null");
  }
  WaveformSP self = *static_cast<WaveformSP*>(handle);
  return new math::discrete_spaces::DiscreteSpaceSP(self->space());
  FALCON_C_API_END(nullptr)
}

ListPortTransformHandle Waveform_transforms(WaveformHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Waveform_transforms: handle cannot be null");
  }
  return new generic::ListSP<port_transforms::PortTransform>(
      (*static_cast<WaveformSP*>(handle))->transforms());
  FALCON_C_API_END(nullptr)
}

void Waveform_push_back(WaveformHandle handle, PortTransformHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Waveform_push_back: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Waveform_push_back: value cannot be null");
  }
  (*static_cast<WaveformSP*>(handle))
      ->push_back(*static_cast<port_transforms::PortTransformSP*>(value));
  FALCON_C_API_END()
}

size_t Waveform_size(WaveformHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Waveform_size: handle cannot be null");
  }
  WaveformSP self = *static_cast<WaveformSP*>(handle);
  return self->size();
  FALCON_C_API_END(0)
}

bool Waveform_empty(WaveformHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Waveform_empty: handle cannot be null");
  }
  WaveformSP self = *static_cast<WaveformSP*>(handle);
  return self->empty();
  FALCON_C_API_END(false)
}

void Waveform_erase_at(WaveformHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Waveform_erase_at: handle cannot be null");
  }
  WaveformSP self = *static_cast<WaveformSP*>(handle);
  self->erase_at(idx);
  FALCON_C_API_END()
}

void Waveform_clear(WaveformHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Waveform_clear: handle cannot be null");
  }
  WaveformSP self = *static_cast<WaveformSP*>(handle);
  self->clear();
  FALCON_C_API_END()
}

PortTransformHandle Waveform_at(WaveformHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Waveform_at: handle cannot be null");
  }
  WaveformSP self = *static_cast<WaveformSP*>(handle);
  return new port_transforms::PortTransformSP(self->at(idx));
  FALCON_C_API_END(nullptr)
}

ListPortTransformHandle Waveform_items(WaveformHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Waveform_items: handle cannot be null");
  }
  WaveformSP self = *static_cast<WaveformSP*>(handle);
  return new generic::ListSP<port_transforms::PortTransform>(
      std::make_shared<generic::List<port_transforms::PortTransform>>(
          self->items()));
  FALCON_C_API_END(nullptr)
}

bool Waveform_contains(WaveformHandle handle, PortTransformHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Waveform_contains: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Waveform_contains: value cannot be null");
  }
  WaveformSP                       self = *static_cast<WaveformSP*>(handle);
  port_transforms::PortTransformSP real_value =
      *static_cast<port_transforms::PortTransformSP*>(value);
  return self->contains(real_value);
  FALCON_C_API_END(false)
}

size_t Waveform_index(WaveformHandle handle, PortTransformHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Waveform_index: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Waveform_index: value cannot be null");
  }
  WaveformSP                       self = *static_cast<WaveformSP*>(handle);
  port_transforms::PortTransformSP real_value =
      *static_cast<port_transforms::PortTransformSP*>(value);
  return self->index(real_value);
  FALCON_C_API_END(0)
}

WaveformHandle Waveform_intersection(WaveformHandle handle,
                                     WaveformHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Waveform_intersection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Waveform_intersection: other cannot be null");
  }
  WaveformSP self       = *static_cast<WaveformSP*>(handle);
  WaveformSP real_other = *static_cast<WaveformSP*>(other);
  generic::ListSP<port_transforms::PortTransform> result =
      self->intersection(real_other);
  return new WaveformSP(std::make_shared<Waveform>(self->space(), result));
  FALCON_C_API_END(nullptr)
}

bool Waveform_equal(WaveformHandle handle, WaveformHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Waveform_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Waveform_equal: other cannot be null");
  }
  return *(*static_cast<WaveformSP*>(handle)) ==
         *(*static_cast<WaveformSP*>(other));
  FALCON_C_API_END(false)
}

bool Waveform_not_equal(WaveformHandle handle, WaveformHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Waveform_not_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Waveform_not_equal: other cannot be null");
  }
  return *(*static_cast<WaveformSP*>(handle)) !=
         *(*static_cast<WaveformSP*>(other));
  FALCON_C_API_END(false)
}

StringHandle Waveform_to_json_string(WaveformHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Waveform_to_json_string: handle cannot be null");
  }
  std::string json = (*static_cast<WaveformSP*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

WaveformHandle Waveform_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "PortTransform_from_json_string: json cannot be null");
  }
  std::string real_json(json->raw, json->length);
  WaveformSP  real_waveform = Waveform::from_json_string<Waveform>(real_json);
  return new WaveformSP(real_waveform);
  FALCON_C_API_END(nullptr)
}
}
