#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"

#include <falcon_core/math/discrete_spaces/Discretizer.hpp>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core::math::discrete_spaces;

extern "C" {
DEFINE_C_API_COPY(Discretizer);
DEFINE_C_API_DESTROY(Discretizer);
DEFINE_C_API_EQUAL(Discretizer);
DEFINE_C_API_NOT_EQUAL(Discretizer);
DEFINE_C_API_TO_JSON(Discretizer);
DEFINE_C_API_FROM_JSON(Discretizer);
DiscretizerHandle Discretizer_create_cartesian_discretizer(double delta) {
  FALCON_C_API_BEGIN
  return new DiscretizerSP(Discretizer::CartesianDiscretizer(delta));
  FALCON_C_API_END(nullptr)
}

DiscretizerHandle Discretizer_create_polar_discretizer(double delta) {
  FALCON_C_API_BEGIN
  return new DiscretizerSP(Discretizer::PolarDiscretizer(delta));
  FALCON_C_API_END(nullptr)
}

double Discretizer_delta(DiscretizerHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Discretizer_delta: handle cannot be null");
  }
  DiscretizerSP self = *static_cast<DiscretizerSP*>(handle);
  return self->delta();
  FALCON_C_API_END(0.0)
}

void Discretizer_set_delta(DiscretizerHandle handle, double delta) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Discretizer_set_delta: handle cannot be null");
  }
  DiscretizerSP self = *static_cast<DiscretizerSP*>(handle);
  self->set_delta(delta);
  FALCON_C_API_END()
}

DomainHandle Discretizer_domain(DiscretizerHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Discretizer_domain: handle cannot be null");
  }
  DiscretizerSP self = *static_cast<DiscretizerSP*>(handle);
  return new falcon_core::math::domains::DomainSP(self->domain());
  FALCON_C_API_END(nullptr)
}

bool Discretizer_is_cartesian(DiscretizerHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Discretizer_is_cartesian: handle cannot be null");
  }
  return (*static_cast<DiscretizerSP*>(handle))->is_cartesian();
  FALCON_C_API_END(false)
}

bool Discretizer_is_polar(DiscretizerHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Discretizer_is_polar: handle cannot be null");
  }
  return (*static_cast<DiscretizerSP*>(handle))->is_polar();
  FALCON_C_API_END(false)
}
}
