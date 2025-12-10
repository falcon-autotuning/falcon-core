#include "falcon_core/autotuner_interfaces/names/Gname_c_api.h"

#include <falcon_core/autotuner_interfaces/names/Gname.hpp>
#include <string>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core::autotuner_interfaces::names;

extern "C" {
DEFINE_C_API_COPY(Gname);
DEFINE_C_API_DESTROY(Gname);
DEFINE_C_API_EQUAL(Gname);
DEFINE_C_API_NOT_EQUAL(Gname);
DEFINE_C_API_TO_JSON(Gname);
DEFINE_C_API_FROM_JSON(Gname);
GnameHandle Gname_create_from_num(int num) {
  FALCON_C_API_BEGIN
  return new GnameSP(std::make_shared<Gname>(num));
  FALCON_C_API_END(nullptr)
}

GnameHandle Gname_create(StringHandle name) {
  FALCON_C_API_BEGIN
  if (!name) {
    throw std::invalid_argument("Gname_create: name cannot be null");
  }
  return new falcon_core::autotuner_interfaces::names::GnameSP(
      std::make_shared<Gname>(std::string(name->raw, name->length)));
  FALCON_C_API_END(nullptr)
}

StringHandle Gname_gname(GnameHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Gname_gname: handle cannot be null");
  }
  GnameSP self = *static_cast<GnameSP*>(handle);
  return String_create(self->gname().c_str(), self->gname().size());
  FALCON_C_API_END(nullptr)
}
}
