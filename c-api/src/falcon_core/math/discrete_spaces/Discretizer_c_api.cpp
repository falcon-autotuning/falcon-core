#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"

#include <falcon_core/math/discrete_spaces/Discretizer.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::math::discrete_spaces;

extern "C" {
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

void Discretizer_destroy(DiscretizerHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Discretizer_destroy: handle cannot be null");
  }
  delete static_cast<DiscretizerSP*>(handle);
  FALCON_C_API_END()
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

bool Discretizer_equal(DiscretizerHandle handle, DiscretizerHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Discretizer_equal: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Discretizer_equal: second handle cannot be null");
  }
  return *(static_cast<DiscretizerSP*>(handle)) ==
         *(static_cast<DiscretizerSP*>(other));
  FALCON_C_API_END(false)
}

bool Discretizer_not_equal(DiscretizerHandle handle, DiscretizerHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Discretizer_not_equal: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Discretizer_not_equal: second handle cannot be null");
  }
  return *(static_cast<DiscretizerSP*>(handle)) !=
         *(static_cast<DiscretizerSP*>(other));
  FALCON_C_API_END(false)
}

StringHandle Discretizer_to_json_string(DiscretizerHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Discretizer_to_json_string: handle cannot be null");
  }
  DiscretizerSP self = *static_cast<DiscretizerSP*>(handle);
  std::string   json = self->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

DiscretizerHandle Discretizer_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Discretizer_from_json_string: json cannot be null");
  }
  std::string json_str(json->raw, json->length);
  return new DiscretizerSP(
      Discretizer::from_json_string<Discretizer>(json_str));
  FALCON_C_API_END(nullptr)
}
}
