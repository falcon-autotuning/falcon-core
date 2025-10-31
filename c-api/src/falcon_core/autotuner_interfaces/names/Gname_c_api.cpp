#include "falcon_core/autotuner_interfaces/names/Gname_c_api.h"

#include <falcon_core/autotuner_interfaces/names/Gname.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::autotuner_interfaces::names;

extern "C" {

GnameHandle Gname_create_from_num(int num) {
  return new falcon_core::autotuner_interfaces::names::Gname(num);
}

GnameHandle Gname_create(StringHandle name) {
  return new falcon_core::autotuner_interfaces::names::Gname(
      std::string(name->raw, name->length));
}

void Gname_destroy(GnameHandle handle) { delete static_cast<Gname*>(handle); }

StringHandle Gname_gname(GnameHandle handle) {
  Gname self = *static_cast<Gname*>(handle);
  return String_create(self.gname().c_str(), self.gname().size());
}

bool Gname_equal(GnameHandle a, GnameHandle b) {
  Gname self_a = *static_cast<Gname*>(a);
  Gname self_b = *static_cast<Gname*>(b);
  return self_a == self_b;
}

bool Gname_not_equal(GnameHandle a, GnameHandle b) {
  Gname self_a = *static_cast<Gname*>(a);
  Gname self_b = *static_cast<Gname*>(b);
  return self_a != self_b;
}

StringHandle Gname_to_json_string(GnameHandle handle) {
  Gname       self = *static_cast<Gname*>(handle);
  std::string json = self.to_json_string();
  return String_create(json.c_str(), json.size());
}

GnameHandle Gname_from_json_string(StringHandle json) {
  std::string json_str(json->raw);
  return new Gname(
      *falcon_core::autotuner_interfaces::names::Gname::from_json_string<Gname>(
          json_str));
}

#ifdef __cplusplus
}
#endif
