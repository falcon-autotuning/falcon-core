#include "falcon_core/math/UnitSpace_c_api.h"

#include <falcon_core/math/UnitSpace.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::math;

extern "C" {
UnitSpaceHandle UnitSpace_create(AxesDiscretizerHandle axes,
                                 DomainHandle          domain) {
  FALCON_C_API_BEGIN
  if (!axes) {
    throw std::invalid_argument("UnitSpace_create: axes cannot be null");
  }
  if (!domain) {
    throw std::invalid_argument("UnitSpace_create: domain cannot be null");
  }
  AxesSP<falcon_core::math::discrete_spaces::Discretizer> real_axes =
      *static_cast<AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(
          axes);
  falcon_core::math::domains::DomainSP real_domain =
      *static_cast<falcon_core::math::domains::DomainSP*>(domain);
  return new UnitSpaceSP(std::make_shared<UnitSpace>(real_axes, real_domain));
  FALCON_C_API_END(nullptr)
}

UnitSpaceHandle UnitSpace_create_ray_space(double       dr,
                                           double       dtheta,
                                           DomainHandle domain) {
  FALCON_C_API_BEGIN
  if (!domain) {
    throw std::invalid_argument(
        "UnitSpace_create_rayspace: domain cannot be null");
  }
  falcon_core::math::domains::DomainSP real_domain =
      *static_cast<falcon_core::math::domains::DomainSP*>(domain);
  return new UnitSpaceSP(UnitSpace::RaySpace(dr, dtheta, real_domain));
  FALCON_C_API_END(nullptr)
}

UnitSpaceHandle UnitSpace_create_cartesian_space(AxesDoubleHandle deltas,
                                                 DomainHandle     domain) {
  FALCON_C_API_BEGIN
  if (!domain) {
    throw std::invalid_argument(
        "UnitSpace_create_cartesianspace: domain cannot be null");
  }
  if (!deltas) {
    throw std::invalid_argument(
        "UnitSpace_create_cartesianspace: deltas cannot be null");
  }
  AxesSP<double> real_deltas = *static_cast<AxesSP<double>*>(deltas);
  falcon_core::math::domains::DomainSP real_domain =
      *static_cast<falcon_core::math::domains::DomainSP*>(domain);
  return new UnitSpaceSP(UnitSpace::CartesianSpace(real_deltas, real_domain));
  FALCON_C_API_END(nullptr)
}

UnitSpaceHandle UnitSpace_create_cartesian_1D_space(double       delta,
                                                    DomainHandle domain) {
  FALCON_C_API_BEGIN
  if (!domain) {
    throw std::invalid_argument(
        "UnitSpace_create_cartesian1Dspace: domain cannot be null");
  }
  AxesSP<double> real_deltas =
      std::make_shared<Axes<double>>(Axes<double>(std::vector<double>{delta}));
  falcon_core::math::domains::DomainSP real_domain =
      *static_cast<falcon_core::math::domains::DomainSP*>(domain);
  return new UnitSpaceSP(UnitSpace::CartesianSpace(real_deltas, real_domain));
  FALCON_C_API_END(nullptr)
}

UnitSpaceHandle UnitSpace_create_cartesian_2D_space(AxesDoubleHandle deltas,
                                                    DomainHandle     domain) {
  FALCON_C_API_BEGIN
  if (!domain) {
    throw std::invalid_argument(
        "UnitSpace_create_cartesian2Dspace: domain cannot be null");
  }
  if (!deltas) {
    throw std::invalid_argument(
        "UnitSpace_create_cartesian2Dspace: deltas cannot be null");
  }
  AxesSP<double> real_deltas = *static_cast<AxesSP<double>*>(deltas);
  falcon_core::math::domains::DomainSP real_domain =
      *static_cast<falcon_core::math::domains::DomainSP*>(domain);
  return new UnitSpaceSP(UnitSpace::CartesianSpace(real_deltas, real_domain));
  FALCON_C_API_END(nullptr)
}

void UnitSpace_destroy(UnitSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_destroy: handle cannot be null");
  }
  delete static_cast<UnitSpaceSP*>(handle);
  FALCON_C_API_END()
}

AxesDiscretizerHandle UnitSpace_axes(UnitSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_axes: handle cannot be null");
  }
  UnitSpaceSP self = *static_cast<UnitSpaceSP*>(handle);
  return new AxesSP<falcon_core::math::discrete_spaces::Discretizer>(
      self->axes());
  FALCON_C_API_END(nullptr)
}

DomainHandle UnitSpace_domain(UnitSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_domain: handle cannot be null");
  }
  UnitSpaceSP self = *static_cast<UnitSpaceSP*>(handle);
  return new falcon_core::math::domains::DomainSP(self->domain());
  FALCON_C_API_END(nullptr)
}

UnitSpaceHandle UnitSpace_space(UnitSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_space: handle cannot be null");
  }
  UnitSpaceSP self      = *static_cast<UnitSpaceSP*>(handle);
  auto        space_ptr = self->space();
  if (!space_ptr) {
    throw std::runtime_error("UnitSpace_space: space() returned nullptr");
  }
  return new falcon_core::generic::FArraySP<double>(space_ptr);
  FALCON_C_API_END(nullptr)
}

ListIntHandle UnitSpace_shape(UnitSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_shape: handle cannot be null");
  }
  UnitSpaceSP self = *static_cast<UnitSpaceSP*>(handle);
  return new falcon_core::generic::ListSP<int>(self->shape());
  FALCON_C_API_END(nullptr)
}

size_t UnitSpace_dimension(UnitSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_dimension: handle cannot be null");
  }
  UnitSpaceSP self = *static_cast<UnitSpaceSP*>(handle);
  return self->dimension();
  FALCON_C_API_END(0)
}

void UnitSpace_compile(UnitSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_compile: handle cannot be null");
  }
  UnitSpaceSP self = *static_cast<UnitSpaceSP*>(handle);
  self->compile();
  FALCON_C_API_END()
}

AxesControlArrayHandle UnitSpace_create_array(UnitSpaceHandle handle,
                                              AxesIntHandle   axes) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "UnitSpace_create_array: handle cannot be null");
  }
  if (!axes) {
    throw std::invalid_argument("UnitSpace_create_array: axes cannot be null");
  }
  UnitSpaceSP self      = *static_cast<UnitSpaceSP*>(handle);
  AxesSP<int> real_axes = *static_cast<AxesSP<int>*>(axes);
  return new AxesSP<falcon_core::math::arrays::ControlArray>(
      self->create_array(real_axes));
  FALCON_C_API_END(nullptr)
}

void UnitSpace_push_back(UnitSpaceHandle handle, DiscretizerHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_push_back: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("UnitSpace_push_back: value cannot be null");
  }
  UnitSpaceSP self = *static_cast<UnitSpaceSP*>(handle);
  falcon_core::math::discrete_spaces::DiscretizerSP real_value =
      *static_cast<falcon_core::math::discrete_spaces::DiscretizerSP*>(value);
  self->push_back(real_value);
  FALCON_C_API_END()
}

size_t UnitSpace_size(UnitSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_size: handle cannot be null");
  }
  UnitSpaceSP self = *static_cast<UnitSpaceSP*>(handle);
  return self->size();
  FALCON_C_API_END(0)
}

bool UnitSpace_empty(UnitSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_empty: handle cannot be null");
  }
  UnitSpaceSP self = *static_cast<UnitSpaceSP*>(handle);
  return self->empty();
  FALCON_C_API_END(false)
}

void UnitSpace_erase_at(UnitSpaceHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_erase_at: handle cannot be null");
  }
  UnitSpaceSP self = *static_cast<UnitSpaceSP*>(handle);
  self->erase_at(idx);
  FALCON_C_API_END()
}

void UnitSpace_clear(UnitSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_clear: handle cannot be null");
  }
  UnitSpaceSP self = *static_cast<UnitSpaceSP*>(handle);
  self->clear();
  FALCON_C_API_END()
}

DiscretizerHandle UnitSpace_at(UnitSpaceHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_at: handle cannot be null");
  }
  UnitSpaceSP self = *static_cast<UnitSpaceSP*>(handle);
  falcon_core::math::discrete_spaces::DiscretizerSP result = self->at(idx);
  return new falcon_core::math::discrete_spaces::DiscretizerSP(result);
  FALCON_C_API_END(nullptr)
}

size_t UnitSpace_items(UnitSpaceHandle    handle,
                       DiscretizerHandle* out_buffer,
                       size_t             buffer_size) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_items: handle cannot be null");
  }
  if (!out_buffer) {
    throw std::invalid_argument("UnitSpace_items: out_buffer cannot be null");
  }
  UnitSpaceSP self = *static_cast<UnitSpaceSP*>(handle);
  if (self->size() > buffer_size) {
    throw std::runtime_error(
        "Trying to store more datapoints than buffer allocated.");
  }
  for (size_t i = 0; i < self->size(); ++i) {
    out_buffer[i] =
        new falcon_core::math::discrete_spaces::DiscretizerSP(self->items()[i]);
  }
  return self->size();
  FALCON_C_API_END(0)
}

bool UnitSpace_contains(UnitSpaceHandle handle, DiscretizerHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_contains: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("UnitSpace_contains: value cannot be null");
  }
  UnitSpaceSP self = *static_cast<UnitSpaceSP*>(handle);
  falcon_core::math::discrete_spaces::DiscretizerSP real_value =
      *static_cast<falcon_core::math::discrete_spaces::DiscretizerSP*>(value);
  return self->contains(real_value);
  FALCON_C_API_END(false)
}

size_t UnitSpace_index(UnitSpaceHandle handle, DiscretizerHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_index: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("UnitSpace_index: value cannot be null");
  }
  UnitSpaceSP self = *static_cast<UnitSpaceSP*>(handle);
  falcon_core::math::discrete_spaces::DiscretizerSP real_value =
      *static_cast<falcon_core::math::discrete_spaces::DiscretizerSP*>(value);
  return self->index(real_value);
  FALCON_C_API_END(0)
}

UnitSpaceHandle UnitSpace_intersection(UnitSpaceHandle handle,
                                       UnitSpaceHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "UnitSpace_intersection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("UnitSpace_intersection: other cannot be null");
  }
  UnitSpaceSP self  = *static_cast<UnitSpaceSP*>(handle);
  UnitSpaceSP oself = *static_cast<UnitSpaceSP*>(other);
  falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>
      result = self->intersection(oself);
  return new UnitSpaceSP(std::make_shared<UnitSpace>(
      std::make_shared<Axes<falcon_core::math::discrete_spaces::Discretizer>>(
          result),
      self->domain()));
  FALCON_C_API_END(nullptr)
}

bool UnitSpace_equal(UnitSpaceHandle handle, UnitSpaceHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_equal: a cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("UnitSpace_equal: b cannot be null");
  }
  UnitSpaceSP self_a = *static_cast<UnitSpaceSP*>(handle);
  UnitSpaceSP self_b = *static_cast<UnitSpaceSP*>(other);
  return *self_a == *self_b;
  FALCON_C_API_END(false)
}

bool UnitSpace_not_equal(UnitSpaceHandle handle, UnitSpaceHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("UnitSpace_not_equal: a cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("UnitSpace_not_equal: b cannot be null");
  }
  UnitSpaceSP self_a = *static_cast<UnitSpaceSP*>(handle);
  UnitSpaceSP self_b = *static_cast<UnitSpaceSP*>(other);
  return *self_a != *self_b;
  FALCON_C_API_END(false)
}

StringHandle UnitSpace_to_json_string(UnitSpaceHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "UnitSpace_to_json_string: handle cannot be null");
  }
  UnitSpaceSP self = *static_cast<UnitSpaceSP*>(handle);
  std::string json = self->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

UnitSpaceHandle UnitSpace_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "UnitSpace_from_json_string: json cannot be null");
  }
  std::string json_str = json->raw;
  return new UnitSpaceSP(UnitSpace::from_json_string<UnitSpace>(json_str));
  FALCON_C_API_END(nullptr)
}
}
