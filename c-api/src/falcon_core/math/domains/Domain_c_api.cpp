#include "falcon_core/math/domains/Domain_c_api.h"

#include <falcon_core/math/domains/Domain.hpp>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core::math::domains;

extern "C" {
DEFINE_C_API_COPY(Domain);
DEFINE_C_API_DESTROY(Domain);
DEFINE_C_API_EQUAL(Domain);
DEFINE_C_API_NOT_EQUAL(Domain);
DEFINE_C_API_TO_JSON(Domain);
DEFINE_C_API_FROM_JSON(Domain);
DomainHandle Domain_create(double min_val,
                           double max_val,
                           bool   lesser_bound_contained,
                           bool   greater_bound_contained) {
  FALCON_C_API_BEGIN
  return new DomainSP(std::make_shared<Domain>(
      min_val, max_val, lesser_bound_contained, greater_bound_contained));
  FALCON_C_API_END(nullptr)
}

double Domain_lesser_bound(DomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Domain_lesser_bound: handle cannot be null");
  }
  DomainSP self = *static_cast<DomainSP*>(handle);
  return self->lesser_bound();
  FALCON_C_API_END(0.0)
}

double Domain_greater_bound(DomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Domain_greater_bound: handle cannot be null");
  }
  DomainSP self = *static_cast<DomainSP*>(handle);
  return self->greater_bound();
  FALCON_C_API_END(0.0)
}

bool Domain_lesser_bound_contained(DomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Domain_lesser_bound_contained: handle cannot be null");
  }
  DomainSP self = *static_cast<DomainSP*>(handle);
  return self->lesser_bound_contained();
  FALCON_C_API_END(false)
}

bool Domain_greater_bound_contained(DomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Domain_greater_bound_contained: handle cannot be null");
  }
  DomainSP self = *static_cast<DomainSP*>(handle);
  return self->greater_bound_contained();
  FALCON_C_API_END(false)
}

bool Domain_in(DomainHandle handle, double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Domain_in: handle cannot be null");
  }
  DomainSP self = *static_cast<DomainSP*>(handle);
  return self->in(value);
  FALCON_C_API_END(false)
}

double Domain_range(DomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Domain_range: handle cannot be null");
  }
  DomainSP self = *static_cast<DomainSP*>(handle);
  return self->range();
  FALCON_C_API_END(0.0)
}

double Domain_center(DomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Domain_center: handle cannot be null");
  }
  DomainSP self = *static_cast<DomainSP*>(handle);
  return self->get_center();
  FALCON_C_API_END(0.0)
}

DomainHandle Domain_intersection(DomainHandle handle, DomainHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Domain_intersection: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Domain_intersection: second handle cannot be null");
  }
  DomainSP self       = *static_cast<DomainSP*>(handle);
  DomainSP real_other = *static_cast<DomainSP*>(other);
  DomainSP result     = *self & real_other;
  return new DomainSP(result);
  FALCON_C_API_END(nullptr)
}

DomainHandle Domain_union(DomainHandle handle, DomainHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Domain_union: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Domain_union: second handle cannot be null");
  }
  DomainSP self       = *static_cast<DomainSP*>(handle);
  DomainSP real_other = *static_cast<DomainSP*>(other);
  DomainSP result     = *self | real_other;
  return new DomainSP(result);
  FALCON_C_API_END(nullptr)
}

bool Domain_is_empty(DomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Domain_is_empty: handle cannot be null");
  }
  DomainSP self = *static_cast<DomainSP*>(handle);
  return self->is_empty();
  FALCON_C_API_END(false)
}

bool Domain_contains_domain(DomainHandle handle, DomainHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Domain_contains_domain: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Domain_contains_domain: second handle cannot be null");
  }
  DomainSP self       = *static_cast<DomainSP*>(handle);
  DomainSP real_other = *static_cast<DomainSP*>(other);
  return self->contains_domain(real_other);
  FALCON_C_API_END(false)
}

DomainHandle Domain_shift(DomainHandle handle, double offset) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Domain_shift: handle cannot be null");
  }
  DomainSP self = *static_cast<DomainSP*>(handle);
  return new DomainSP(self->shift(offset));
  FALCON_C_API_END(nullptr)
}

DomainHandle Domain_scale(DomainHandle handle, double scale) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Domain_scale: handle cannot be null");
  }
  DomainSP self = *static_cast<DomainSP*>(handle);
  return new DomainSP(self->scale(scale));
  FALCON_C_API_END(nullptr)
}

double Domain_transform(DomainHandle handle, DomainHandle other, double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Domain_transform: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Domain_transform: second handle cannot be null");
  }
  DomainSP self       = *static_cast<DomainSP*>(handle);
  DomainSP real_other = *static_cast<DomainSP*>(other);
  return self->transform(real_other, value);
  FALCON_C_API_END(0.0)
}
}
