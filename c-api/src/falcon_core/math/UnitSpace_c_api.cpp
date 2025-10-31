#include "falcon_core/math/UnitSpace_c_api.h"

#include <falcon_core/math/UnitSpace.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::math;

extern "C" {

UnitSpaceHandle UnitSpace_create(AxesDiscretizerHandle axes,
                                 DomainHandle          domain) {
  if (!axes) {
    throw std::invalid_argument("UnitSpace_create: axes cannot be null");
  }
  if (!domain) {
    throw std::invalid_argument("UnitSpace_create: domain cannot be null");
  }
  AxesSP<falcon_core::math::discrete_spaces::Discretizer> real_axes =
      std::make_shared<Axes<falcon_core::math::discrete_spaces::Discretizer>>(
          *static_cast<Axes<falcon_core::math::discrete_spaces::Discretizer>*>(
              axes));
  falcon_core::math::domains::DomainSP real_domain =
      std::make_shared<falcon_core::math::domains::Domain>(
          *static_cast<falcon_core::math::domains::Domain*>(domain));
  return new UnitSpace(real_axes, real_domain);
}

UnitSpaceHandle UnitSpace_create_rayspace(double       dr,
                                          double       dtheta,
                                          DomainHandle domain) {
  if (!domain) {
    throw std::invalid_argument(
        "UnitSpace_create_rayspace: domain cannot be null");
  }
  falcon_core::math::domains::DomainSP real_domain =
      std::make_shared<falcon_core::math::domains::Domain>(
          *static_cast<falcon_core::math::domains::Domain*>(domain));
  return new UnitSpace(*UnitSpace::RaySpace(dr, dtheta, real_domain));
}

UnitSpaceHandle UnitSpace_create_cartesianspace(AxesDoubleHandle deltas,
                                                DomainHandle     domain) {
  if (!domain) {
    throw std::invalid_argument(
        "UnitSpace_create_cartesianspace: domain cannot be null");
  }
  if (!deltas) {
    throw std::invalid_argument(
        "UnitSpace_create_cartesianspace: deltas cannot be null");
  }
  AxesSP<double> real_deltas =
      std::make_shared<Axes<double>>(*static_cast<Axes<double>*>(deltas));
  falcon_core::math::domains::DomainSP real_domain =
      std::make_shared<falcon_core::math::domains::Domain>(
          *static_cast<falcon_core::math::domains::Domain*>(domain));
  return new UnitSpace(*UnitSpace::CartesianSpace(real_deltas, real_domain));
}

UnitSpaceHandle UnitSpace_create_cartesian1Dspace(double       delta,
                                                  DomainHandle domain) {
  if (!domain) {
    throw std::invalid_argument(
        "UnitSpace_create_cartesian1Dspace: domain cannot be null");
  }
  AxesSP<double> real_deltas =
      std::make_shared<Axes<double>>(Axes<double>(std::vector<double>{delta}));
  falcon_core::math::domains::DomainSP real_domain =
      std::make_shared<falcon_core::math::domains::Domain>(
          *static_cast<falcon_core::math::domains::Domain*>(domain));
  return new UnitSpace(*UnitSpace::CartesianSpace(real_deltas, real_domain));
}

UnitSpaceHandle UnitSpace_create_cartesian2Dspace(AxesDoubleHandle deltas,
                                                  DomainHandle     domain) {
  if (!domain) {
    throw std::invalid_argument(
        "UnitSpace_create_cartesian2Dspace: domain cannot be null");
  }
  AxesSP<double> real_deltas =
      std::make_shared<Axes<double>>(*static_cast<Axes<double>*>(deltas));
  falcon_core::math::domains::DomainSP real_domain =
      std::make_shared<falcon_core::math::domains::Domain>(
          *static_cast<falcon_core::math::domains::Domain*>(domain));
  return new UnitSpace(*UnitSpace::CartesianSpace(real_deltas, real_domain));
}

void UnitSpace_destroy(UnitSpaceHandle handle) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_destroy: handle cannot be null");
  }
  delete static_cast<UnitSpace*>(handle);
}

AxesDiscretizerHandle UnitSpace_axes(UnitSpaceHandle handle) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_axes: handle cannot be null");
  }
  UnitSpace self = *static_cast<UnitSpace*>(handle);
  return new Axes<falcon_core::math::discrete_spaces::Discretizer>(
      *self.axes());
}

DomainHandle UnitSpace_domain(UnitSpaceHandle handle) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_domain: handle cannot be null");
  }
  UnitSpace self = *static_cast<UnitSpace*>(handle);
  return new falcon_core::math::domains::Domain(*self.domain());
}

FArrayDoubleHandle UnitSpace_space(UnitSpaceHandle handle) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_space: handle cannot be null");
  }
  UnitSpace self = *static_cast<UnitSpace*>(handle);
  return new falcon_core::generic::FArray<double>(*self.space());
}

ListIntHandle UnitSpace_shape(UnitSpaceHandle handle) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_shape: handle cannot be null");
  }
  UnitSpace self = *static_cast<UnitSpace*>(handle);
  return new falcon_core::generic::List<int>(*self.shape());
}

size_t UnitSpace_dimension(UnitSpaceHandle handle) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_dimension: handle cannot be null");
  }
  UnitSpace self = *static_cast<UnitSpace*>(handle);
  return self.dimension();
}

void UnitSpace_compile(UnitSpaceHandle handle) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_compile: handle cannot be null");
  }
  UnitSpace self = *static_cast<UnitSpace*>(handle);
  self.compile();
}

AxesControlArrayHandle UnitSpace_create_array(UnitSpaceHandle handle,
                                              AxesIntHandle   axes) {
  if (!handle) {
    throw std::invalid_argument(
        "UnitSpace_create_array: handle cannot be null");
  }
  if (!axes) {
    throw std::invalid_argument("UnitSpace_create_array: axes cannot be null");
  }
  UnitSpace   self = *static_cast<UnitSpace*>(handle);
  AxesSP<int> real_axes =
      std::make_shared<Axes<int>>(*static_cast<Axes<int>*>(axes));
  return new Axes<falcon_core::math::arrays::ControlArray>(
      *self.create_array(real_axes));
}

void UnitSpace_push_back(UnitSpaceHandle handle, DiscretizerHandle value) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_push_back: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("UnitSpace_push_back: value cannot be null");
  }
  UnitSpace self = *static_cast<UnitSpace*>(handle);
  falcon_core::math::discrete_spaces::DiscretizerSP real_value =
      std::make_shared<falcon_core::math::discrete_spaces::Discretizer>(
          *static_cast<falcon_core::math::discrete_spaces::Discretizer*>(
              value));
  self.push_back(real_value);
}

size_t UnitSpace_size(UnitSpaceHandle handle) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_size: handle cannot be null");
  }
  UnitSpace self = *static_cast<UnitSpace*>(handle);
  return self.size();
}

bool UnitSpace_empty(UnitSpaceHandle handle) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_empty: handle cannot be null");
  }
  UnitSpace self = *static_cast<UnitSpace*>(handle);
  return self.empty();
}

void UnitSpace_erase_at(UnitSpaceHandle handle, size_t idx) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_erase_at: handle cannot be null");
  }
  UnitSpace self = *static_cast<UnitSpace*>(handle);
  self.erase_at(idx);
}

void UnitSpace_clear(UnitSpaceHandle handle) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_clear: handle cannot be null");
  }
  UnitSpace self = *static_cast<UnitSpace*>(handle);
  self.clear();
}

DiscretizerHandle UnitSpace_at(UnitSpaceHandle handle, size_t idx) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_at: handle cannot be null");
  }
  UnitSpace self = *static_cast<UnitSpace*>(handle);
  falcon_core::math::discrete_spaces::DiscretizerSP result = self.at(idx);
  return new falcon_core::math::discrete_spaces::Discretizer(*result);
}

size_t UnitSpace_items(UnitSpaceHandle    handle,
                       DiscretizerHandle* out_buffer,
                       size_t             buffer_size) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_items: handle cannot be null");
  }
  if (!out_buffer) {
    throw std::invalid_argument("UnitSpace_items: out_buffer cannot be null");
  }
  UnitSpace self = *static_cast<UnitSpace*>(handle);
  if (self.size() > buffer_size) {
    throw std::runtime_error(
        "Trying to store more datapoints than buffer allocated.");
  }
  for (size_t i = 0; i < self.size(); ++i) {
    falcon_core::math::discrete_spaces::DiscretizerSP result = self.items()[i];
    out_buffer[i] =
        new falcon_core::math::discrete_spaces::Discretizer(*result);
  }
  return self.size();
}

bool UnitSpace_contains(UnitSpaceHandle handle, DiscretizerHandle value) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_contains: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("UnitSpace_contains: value cannot be null");
  }
  UnitSpace self = *static_cast<UnitSpace*>(handle);
  falcon_core::math::discrete_spaces::DiscretizerSP real_value =
      std::make_shared<falcon_core::math::discrete_spaces::Discretizer>(
          *static_cast<falcon_core::math::discrete_spaces::Discretizer*>(
              value));
  return self.contains(real_value);
}

size_t UnitSpace_index(UnitSpaceHandle handle, DiscretizerHandle value) {
  if (!handle) {
    throw std::invalid_argument("UnitSpace_index: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("UnitSpace_index: value cannot be null");
  }
  UnitSpace self = *static_cast<UnitSpace*>(handle);
  falcon_core::math::discrete_spaces::DiscretizerSP real_value =
      std::make_shared<falcon_core::math::discrete_spaces::Discretizer>(
          *static_cast<falcon_core::math::discrete_spaces::Discretizer*>(
              value));
  return self.index(real_value);
}

UnitSpaceHandle UnitSpace_intersection(UnitSpaceHandle handle,
                                       UnitSpaceHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "UnitSpace_intersection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("UnitSpace_intersection: other cannot be null");
  }
  UnitSpace self  = *static_cast<UnitSpace*>(handle);
  UnitSpace oself = *static_cast<UnitSpace*>(other);
  falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>
      result = self.intersection(std::make_shared<UnitSpace>(oself));
  return new UnitSpace(
      std::make_shared<Axes<falcon_core::math::discrete_spaces::Discretizer>>(
          result),
      self.domain());
}

bool UnitSpace_equal(UnitSpaceHandle a, UnitSpaceHandle b) {
  if (!a) {
    throw std::invalid_argument("UnitSpace_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("UnitSpace_equal: b cannot be null");
  }
  UnitSpace self_a = *static_cast<UnitSpace*>(a);
  UnitSpace self_b = *static_cast<UnitSpace*>(b);
  return self_a == self_b;
}

bool UnitSpace_not_equal(UnitSpaceHandle a, UnitSpaceHandle b) {
  if (!a) {
    throw std::invalid_argument("UnitSpace_not_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("UnitSpace_not_equal: b cannot be null");
  }
  UnitSpace self_a = *static_cast<UnitSpace*>(a);
  UnitSpace self_b = *static_cast<UnitSpace*>(b);
  return self_a != self_b;
}

StringHandle UnitSpace_to_json_string(UnitSpaceHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "UnitSpace_to_json_string: handle cannot be null");
  }
  UnitSpace   self = *static_cast<UnitSpace*>(handle);
  std::string json = self.to_json_string();
  return String_create(json.c_str(), json.size());
}

UnitSpaceHandle UnitSpace_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "UnitSpace_from_json_string: json cannot be null");
  }
  std::string json_str = json->raw;
  return new UnitSpace(*UnitSpace::from_json_string<UnitSpace>(json_str));
}

#ifdef __cplusplus
}
#endif
