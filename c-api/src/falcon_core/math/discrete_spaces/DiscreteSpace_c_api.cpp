#include "falcon_core/math/discrete_spaces/DiscreteSpace_c_api.h"

#include <falcon_core/math/discrete_spaces/DiscreteSpace.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"
using namespace falcon_core::math::discrete_spaces;

extern "C" {
DiscreteSpaceHandle DiscreteSpace_create(UnitSpaceHandle                 space,
                                         AxesCoupledLabelledDomainHandle axes,
                                         AxesMapStringBoolHandle increasing) {
  FALCON_C_API_BEGIN
  if (!space) {
    throw std::invalid_argument("DiscreteSpace_create: space cannot be null");
  }
  if (!axes) {
    throw std::invalid_argument("DiscreteSpace_create: axes cannot be null");
  }
  if (!increasing) {
    throw std::invalid_argument(
        "DiscreteSpace_create: increasing cannot be null");
  }
  falcon_core::math::UnitSpaceSP real_space =
      std::make_shared<falcon_core::math::UnitSpace>(
          *static_cast<falcon_core::math::UnitSpace*>(space));
  falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>
      real_axes = std::make_shared<falcon_core::math::Axes<
          falcon_core::math::domains::CoupledLabelledDomain>>(
          *static_cast<falcon_core::math::Axes<
              falcon_core::math::domains::CoupledLabelledDomain>*>(axes));
  falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>
      real_increasing = std::make_shared<falcon_core::math::Axes<
          falcon_core::generic::Map<std::string, bool>>>(
          *static_cast<falcon_core::math::Axes<
              falcon_core::generic::Map<std::string, bool>>*>(increasing));
  return new DiscreteSpace(real_space, real_axes, real_increasing);
  FALCON_C_API_END(nullptr)
}

DiscreteSpaceHandle DiscreteSpace_create_cartesian_discrete_space(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    DomainHandle                    domain) {
  FALCON_C_API_BEGIN
  if (!divisions) {
    throw std::invalid_argument(
        "DiscreteSpace_create_cartesiandiscretespace: divisions cannot be "
        "null");
  }
  if (!axes) {
    throw std::invalid_argument(
        "DiscreteSpace_create_cartesiandiscretespace: axes cannot be null");
  }
  if (!increasing) {
    throw std::invalid_argument(
        "DiscreteSpace_create_cartesiandiscretespace: increasing cannot be "
        "null");
  }
  falcon_core::math::AxesSP<int> real_divisions =
      std::make_shared<falcon_core::math::Axes<int>>(
          *static_cast<falcon_core::math::Axes<int>*>(divisions));
  falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>
      real_axes = std::make_shared<falcon_core::math::Axes<
          falcon_core::math::domains::CoupledLabelledDomain>>(
          *static_cast<falcon_core::math::Axes<
              falcon_core::math::domains::CoupledLabelledDomain>*>(axes));
  falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>
      real_increasing = std::make_shared<falcon_core::math::Axes<
          falcon_core::generic::Map<std::string, bool>>>(
          *static_cast<falcon_core::math::Axes<
              falcon_core::generic::Map<std::string, bool>>*>(increasing));
  falcon_core::math::domains::DomainSP real_domain =
      std::make_shared<falcon_core::math::domains::Domain>(
          *static_cast<falcon_core::math::domains::Domain*>(domain));
  return new DiscreteSpace(*DiscreteSpace::CartesianDiscreteSpace(
      real_divisions, real_axes, real_increasing, real_domain));
  FALCON_C_API_END(nullptr)
}

DiscreteSpaceHandle DiscreteSpace_create_cartesian_discrete_space_1D(
    int                         division,
    CoupledLabelledDomainHandle shared_domain,
    MapStringBoolHandle         increasing,
    DomainHandle                domain) {
  FALCON_C_API_BEGIN
  if (!shared_domain) {
    throw std::invalid_argument(
        "DiscreteSpace_create_cartesiandiscretespace1D: shared_domain cannot "
        "be null");
  }
  if (!increasing) {
    throw std::invalid_argument(
        "DiscreteSpace_create_cartesiandiscretespace1D: increasing cannot be "
        "null");
  }
  if (!domain) {
    throw std::invalid_argument(
        "DiscreteSpace_create_cartesiandiscretespace1D: domain cannot be null");
  }
  falcon_core::math::domains::CoupledLabelledDomainSP real_shared_domain =
      std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>(
          *static_cast<falcon_core::math::domains::CoupledLabelledDomain*>(
              shared_domain));
  falcon_core::generic::MapSP<std::string, bool> real_increasing =
      std::make_shared<falcon_core::generic::Map<std::string, bool>>(
          *static_cast<falcon_core::generic::Map<std::string, bool>*>(
              increasing));
  falcon_core::math::domains::DomainSP real_domain =
      std::make_shared<falcon_core::math::domains::Domain>(
          *static_cast<falcon_core::math::domains::Domain*>(domain));
  return new DiscreteSpace(*DiscreteSpace::CartesianDiscreteSpace1D(
      division, real_shared_domain, real_increasing, real_domain));
  FALCON_C_API_END(nullptr)
}

void DiscreteSpace_destroy(DiscreteSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("DiscreteSpace_destroy: handle cannot be null");
  }
  delete static_cast<DiscreteSpace*>(handle);
  FALCON_C_API_END()
}

UnitSpaceHandle DiscreteSpace_space(DiscreteSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("DiscreteSpace_space: handle cannot be null");
  }
  DiscreteSpace self = *static_cast<DiscreteSpace*>(handle);
  return new falcon_core::math::UnitSpace(*self.space());
  FALCON_C_API_END(nullptr)
}

AxesCoupledLabelledDomainHandle DiscreteSpace_axes(DiscreteSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("DiscreteSpace_axes: handle cannot be null");
  }
  DiscreteSpace self = *static_cast<DiscreteSpace*>(handle);
  return new falcon_core::math::Axes<
      falcon_core::math::domains::CoupledLabelledDomain>(*self.axes());
  FALCON_C_API_END(nullptr)
}

AxesMapStringBoolHandle DiscreteSpace_increasing(DiscreteSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DiscreteSpace_increasing: handle cannot be null");
  }
  DiscreteSpace self = *static_cast<DiscreteSpace*>(handle);
  return new falcon_core::math::Axes<
      falcon_core::generic::Map<std::string, bool>>(*self.increasing());
  FALCON_C_API_END(nullptr)
}

PortsHandle DiscreteSpace_knobs(DiscreteSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("DiscreteSpace_knobs: handle cannot be null");
  }
  DiscreteSpace self = *static_cast<DiscreteSpace*>(handle);
  return new falcon_core::instrument_interfaces::names::Ports(*(self.knobs()));
  FALCON_C_API_END(nullptr)
}

void DiscreteSpace_validate_unit_space_dimensionality_matches_knobs(
    DiscreteSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DiscreteSpace_validate_unit_space_dimensionality_matches_knobs: "
        "handle cannot be null");
  }
  DiscreteSpace self = *static_cast<DiscreteSpace*>(handle);
  self.validate_unit_space_dimensionality_matches_knobs();
  FALCON_C_API_END()
}

void DiscreteSpace_validate_knob_uniqueness(DiscreteSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DiscreteSpace_validate_knob_uniqueness: handle cannot be null");
  }
  DiscreteSpace self = *static_cast<DiscreteSpace*>(handle);
  self.validate_knob_uniqueness();
  FALCON_C_API_END()
}

int DiscreteSpace_get_axis(DiscreteSpaceHandle  handle,
                           InstrumentPortHandle knob) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DiscreteSpace_get_axis: handle cannot be null");
  }
  if (!knob) {
    throw std::invalid_argument("DiscreteSpace_get_axis: knob cannot be null");
  }
  DiscreteSpace self = *static_cast<DiscreteSpace*>(handle);
  return self.get_axis(std::make_shared<falcon_core::instrument_interfaces::
                                            names::InstrumentPort>(
      *static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(
          knob)));
  FALCON_C_API_END(0)
}

DomainHandle DiscreteSpace_get_domain(DiscreteSpaceHandle  handle,
                                      InstrumentPortHandle knob) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DiscreteSpace_get_domain: handle cannot be null");
  }
  if (!knob) {
    throw std::invalid_argument(
        "DiscreteSpace_get_domain: knob cannot be null");
  }
  DiscreteSpace self = *static_cast<DiscreteSpace*>(handle);
  return new falcon_core::math::domains::Domain(*(self.get_domain(
      std::make_shared<
          falcon_core::instrument_interfaces::names::InstrumentPort>(
          *static_cast<
              falcon_core::instrument_interfaces::names::InstrumentPort*>(
              knob)))));
  FALCON_C_API_END(nullptr)
}

AxesLabelledControlArrayHandle DiscreteSpace_get_projection(
    DiscreteSpaceHandle handle, AxesInstrumentPortHandle projection) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DiscreteSpace_get_projection: handle cannot be null");
  }
  if (!projection) {
    throw std::invalid_argument(
        "DiscreteSpace_get_projection: projection cannot be null");
  }
  DiscreteSpace self = *static_cast<DiscreteSpace*>(handle);
  return new falcon_core::math::Axes<
      falcon_core::math::arrays::LabelledControlArray>(*(self.get_projection(
      std::make_shared<falcon_core::math::Axes<
          falcon_core::instrument_interfaces::names::InstrumentPort>>(
          *static_cast<falcon_core::math::Axes<
              falcon_core::instrument_interfaces::names::InstrumentPort>*>(
              projection)))));
  FALCON_C_API_END(nullptr)
}

bool DiscreteSpace_equal(DiscreteSpaceHandle handle,
                         DiscreteSpaceHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("DiscreteSpace_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("DiscreteSpace_equal: other cannot be null");
  }
  DiscreteSpace self  = *static_cast<DiscreteSpace*>(handle);
  DiscreteSpace oself = *static_cast<DiscreteSpace*>(other);
  return self == oself;
  FALCON_C_API_END(false)
}

bool DiscreteSpace_not_equal(DiscreteSpaceHandle handle,
                             DiscreteSpaceHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DiscreteSpace_not_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DiscreteSpace_not_equal: other cannot be null");
  }
  DiscreteSpace self  = *static_cast<DiscreteSpace*>(handle);
  DiscreteSpace oself = *static_cast<DiscreteSpace*>(other);
  return self != oself;
  FALCON_C_API_END(false)
}

StringHandle DiscreteSpace_to_json_string(DiscreteSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DiscreteSpace_to_json_string: handle cannot be null");
  }
  DiscreteSpace self = *static_cast<DiscreteSpace*>(handle);
  std::string   json = self.to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

DiscreteSpaceHandle DiscreteSpace_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "DiscreteSpace_from_json_string: json cannot be null");
  }
  std::string json_str(json->raw);
  return new DiscreteSpace(
      *DiscreteSpace::from_json_string<DiscreteSpace>(json_str));
  FALCON_C_API_END(nullptr)
}
}
