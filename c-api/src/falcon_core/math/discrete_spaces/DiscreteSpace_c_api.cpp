#include "falcon_core/math/discrete_spaces/DiscreteSpace_c_api.h"

#include <falcon_core/math/discrete_spaces/DiscreteSpace.hpp>

#include "falcon_core/Precompiled_c_api.h"
using namespace falcon_core::math::discrete_spaces;

extern "C" {
DEFINE_C_API_COPY(DiscreteSpace);
DEFINE_C_API_DESTROY(DiscreteSpace);
DEFINE_C_API_EQUAL(DiscreteSpace);
DEFINE_C_API_NOT_EQUAL(DiscreteSpace);
DEFINE_C_API_TO_JSON(DiscreteSpace);
DEFINE_C_API_FROM_JSON(DiscreteSpace);
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
      *static_cast<falcon_core::math::UnitSpaceSP*>(space);
  falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>
      real_axes = *static_cast<falcon_core::math::AxesSP<
          falcon_core::math::domains::CoupledLabelledDomain>*>(axes);
  falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>
      real_increasing = *static_cast<falcon_core::math::AxesSP<
          falcon_core::generic::Map<std::string, bool>>*>(increasing);
  return new DiscreteSpaceSP(
      std::make_shared<DiscreteSpace>(real_space, real_axes, real_increasing));
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
      *static_cast<falcon_core::math::AxesSP<int>*>(divisions);
  falcon_core::math::AxesSP<falcon_core::math::domains::CoupledLabelledDomain>
      real_axes = *static_cast<falcon_core::math::AxesSP<
          falcon_core::math::domains::CoupledLabelledDomain>*>(axes);
  falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>
      real_increasing = *static_cast<falcon_core::math::AxesSP<
          falcon_core::generic::Map<std::string, bool>>*>(increasing);
  falcon_core::math::domains::DomainSP real_domain =
      *static_cast<falcon_core::math::domains::DomainSP*>(domain);
  return new DiscreteSpaceSP(DiscreteSpace::CartesianDiscreteSpace(
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
      *static_cast<falcon_core::math::domains::CoupledLabelledDomainSP*>(
          shared_domain);
  falcon_core::generic::MapSP<std::string, bool> real_increasing =
      *static_cast<falcon_core::generic::MapSP<std::string, bool>*>(increasing);
  falcon_core::math::domains::DomainSP real_domain =
      *static_cast<falcon_core::math::domains::DomainSP*>(domain);
  return new DiscreteSpaceSP(DiscreteSpace::CartesianDiscreteSpace1D(
      division, real_shared_domain, real_increasing, real_domain));
  FALCON_C_API_END(nullptr)
}

UnitSpaceHandle DiscreteSpace_space(DiscreteSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("DiscreteSpace_space: handle cannot be null");
  }
  DiscreteSpaceSP self = *static_cast<DiscreteSpaceSP*>(handle);
  return new falcon_core::math::UnitSpaceSP(self->space());
  FALCON_C_API_END(nullptr)
}

AxesCoupledLabelledDomainHandle DiscreteSpace_axes(DiscreteSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("DiscreteSpace_axes: handle cannot be null");
  }
  DiscreteSpaceSP self = *static_cast<DiscreteSpaceSP*>(handle);
  return new falcon_core::math::AxesSP<
      falcon_core::math::domains::CoupledLabelledDomain>(self->axes());
  FALCON_C_API_END(nullptr)
}

AxesMapStringBoolHandle DiscreteSpace_increasing(DiscreteSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DiscreteSpace_increasing: handle cannot be null");
  }
  DiscreteSpaceSP self = *static_cast<DiscreteSpaceSP*>(handle);
  return new falcon_core::math::AxesSP<
      falcon_core::generic::Map<std::string, bool>>(self->increasing());
  FALCON_C_API_END(nullptr)
}

PortsHandle DiscreteSpace_knobs(DiscreteSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("DiscreteSpace_knobs: handle cannot be null");
  }
  DiscreteSpaceSP self = *static_cast<DiscreteSpaceSP*>(handle);
  return new falcon_core::instrument_interfaces::names::PortsSP(self->knobs());
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
  DiscreteSpaceSP self = *static_cast<DiscreteSpaceSP*>(handle);
  self->validate_unit_space_dimensionality_matches_knobs();
  FALCON_C_API_END()
}

void DiscreteSpace_validate_knob_uniqueness(DiscreteSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DiscreteSpace_validate_knob_uniqueness: handle cannot be null");
  }
  DiscreteSpaceSP self = *static_cast<DiscreteSpaceSP*>(handle);
  self->validate_knob_uniqueness();
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
  DiscreteSpaceSP self = *static_cast<DiscreteSpaceSP*>(handle);
  return self->get_axis(
      *static_cast<
          falcon_core::instrument_interfaces::names::InstrumentPortSP*>(knob));
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
  DiscreteSpaceSP self = *static_cast<DiscreteSpaceSP*>(handle);
  return new falcon_core::math::domains::DomainSP(self->get_domain(
      *static_cast<
          falcon_core::instrument_interfaces::names::InstrumentPortSP*>(knob)));
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
  DiscreteSpaceSP self = *static_cast<DiscreteSpaceSP*>(handle);
  return new falcon_core::math::AxesSP<
      falcon_core::math::arrays::LabelledControlArray>(self->get_projection(
      *static_cast<falcon_core::math::AxesSP<
          falcon_core::instrument_interfaces::names::InstrumentPort>*>(
          projection)));
  FALCON_C_API_END(nullptr)
}
}
