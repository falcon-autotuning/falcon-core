#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"

#include <falcon_core/math/discrete_spaces/Discretizer.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::math::discrete_spaces;

DiscretizerHandle Discretizer_create_cartesian_discretizer(double delta) {
  return new Discretizer(*Discretizer::CartesianDiscretizer(delta));
}

DiscretizerHandle Discretizer_create_polar_discretizer(double delta) {
  return new Discretizer(*Discretizer::PolarDiscretizer(delta));
}

void Discretizer_destroy(DiscretizerHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Discretizer_destroy: handle cannot be null");
  }
  delete static_cast<Discretizer*>(handle);
}

double Discretizer_delta(DiscretizerHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Discretizer_delta: handle cannot be null");
  }
  Discretizer self = *static_cast<Discretizer*>(handle);
  return self.delta();
}

void Discretizer_set_delta(DiscretizerHandle handle, double delta) {
  if (!handle) {
    throw std::invalid_argument("Discretizer_set_delta: handle cannot be null");
  }
  Discretizer* self = static_cast<Discretizer*>(handle);
  self->set_delta(delta);
}

DomainHandle Discretizer_domain(DiscretizerHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Discretizer_domain: handle cannot be null");
  }
  Discretizer self = *static_cast<Discretizer*>(handle);
  return new falcon_core::math::domains::Domain(*(self.domain()));
}

bool Discretizer_is_cartesian(DiscretizerHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Discretizer_is_cartesian: handle cannot be null");
  }
  return static_cast<Discretizer*>(handle)->is_cartesian();
}

bool Discretizer_is_polar(DiscretizerHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Discretizer_is_polar: handle cannot be null");
  }
  return static_cast<Discretizer*>(handle)->is_polar();
}

bool Discretizer_equal(DiscretizerHandle a, DiscretizerHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "Discretizer_equal: first handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "Discretizer_equal: second handle cannot be null");
  }
  return *(static_cast<Discretizer*>(a)) == *(static_cast<Discretizer*>(b));
}

bool Discretizer_not_equal(DiscretizerHandle a, DiscretizerHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "Discretizer_not_equal: first handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "Discretizer_not_equal: second handle cannot be null");
  }
  return *(static_cast<Discretizer*>(a)) != *(static_cast<Discretizer*>(b));
}

StringHandle Discretizer_to_json_string(DiscretizerHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Discretizer_to_json_string: handle cannot be null");
  }
  Discretizer self = *static_cast<Discretizer*>(handle);
  std::string json = self.to_json_string();
  return String_create(json.c_str(), json.size());
}

DiscretizerHandle Discretizer_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "Discretizer_from_json_string: json cannot be null");
  }
  std::string json_str(json->raw, json->length);
  return new Discretizer(*Discretizer::from_json_string<Discretizer>(json_str));
}
