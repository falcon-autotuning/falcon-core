#include "falcon_core/autotuner_interfaces/names/Gname_c_api.h"

#include <falcon_core/autotuner_interfaces/names/Gname.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::autotuner_interfaces::names;

extern "C" {
GnameHandle Gname_create_from_num(int num) {
  FALCON_C_API_BEGIN
  return new falcon_core::autotuner_interfaces::names::Gname(num);
  FALCON_C_API_END(nullptr)
}

GnameHandle Gname_create(StringHandle name) {
  FALCON_C_API_BEGIN
  if (!name) {
    throw std::invalid_argument("Gname_create: name cannot be null");
  }
  return new falcon_core::autotuner_interfaces::names::Gname(
      std::string(name->raw, name->length));
  FALCON_C_API_END(nullptr)
}

void Gname_destroy(GnameHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Gname_destroy: handle cannot be null");
  }
  delete static_cast<Gname*>(handle);
  FALCON_C_API_END()
}

StringHandle Gname_gname(GnameHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Gname_gname: handle cannot be null");
  }
  Gname self = *static_cast<Gname*>(handle);
  return String_create(self.gname().c_str(), self.gname().size());
  FALCON_C_API_END(nullptr)
}

bool Gname_equal(GnameHandle a, GnameHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("Gname_equal: handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Gname_equal: handle cannot be null");
  }
  Gname self_a = *static_cast<Gname*>(a);
  Gname self_b = *static_cast<Gname*>(b);
  return self_a == self_b;
  FALCON_C_API_END(false)
}

bool Gname_not_equal(GnameHandle a, GnameHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("Gname_not_equal: handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Gname_not_equal: handle cannot be null");
  }
  Gname self_a = *static_cast<Gname*>(a);
  Gname self_b = *static_cast<Gname*>(b);
  return self_a != self_b;
  FALCON_C_API_END(false)
}

StringHandle Gname_to_json_string(GnameHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Gname_to_json_string: handle cannot be null");
  }
  Gname       self = *static_cast<Gname*>(handle);
  std::string json = self.to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

GnameHandle Gname_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument("Gname_from_json_string: json cannot be null");
  }
  std::string json_str(json->raw);
  return new Gname(
      *falcon_core::autotuner_interfaces::names::Gname::from_json_string<Gname>(
          json_str));
  FALCON_C_API_END(nullptr)
}
}
