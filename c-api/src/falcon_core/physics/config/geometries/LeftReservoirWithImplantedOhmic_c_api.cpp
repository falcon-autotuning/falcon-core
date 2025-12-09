#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic_c_api.h"

#include <falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"

using namespace falcon_core::physics::config::geometries;

extern "C" {
LeftReservoirWithImplantedOhmicHandle LeftReservoirWithImplantedOhmic_create(
    StringHandle     name,
    ConnectionHandle right_neighbor,
    ConnectionHandle ohmic) {
  FALCON_C_API_BEGIN
  if (!name) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_create: Name cannot be null");
  }
  if (!right_neighbor) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_create: right_neighbor cannot be "
        "null");
  }
  if (!ohmic) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_create: ohmic cannot be null");
  }
  std::string real_name(name->raw, name->length);
  falcon_core::physics::device_structures::ConnectionSP right_conn =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          right_neighbor);
  falcon_core::physics::device_structures::ConnectionSP ohmic_conn =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          ohmic);
  return new LeftReservoirWithImplantedOhmicSP(
      std::make_shared<LeftReservoirWithImplantedOhmic>(
          real_name, right_conn, ohmic_conn));
  FALCON_C_API_END(nullptr)
}

void LeftReservoirWithImplantedOhmic_destroy(
    LeftReservoirWithImplantedOhmicHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_destroy: handle cannot be null");
  }
  delete static_cast<LeftReservoirWithImplantedOhmicSP*>(handle);
  FALCON_C_API_END()
}

StringHandle LeftReservoirWithImplantedOhmic_name(
    LeftReservoirWithImplantedOhmicHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_name: handle cannot be null");
  }
  LeftReservoirWithImplantedOhmicSP self =
      *static_cast<LeftReservoirWithImplantedOhmicSP*>(handle);
  return String_create(self->name().c_str(), self->name().size());
  FALCON_C_API_END(nullptr)
}

StringHandle LeftReservoirWithImplantedOhmic_type(
    LeftReservoirWithImplantedOhmicHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_type: handle cannot be null");
  }
  LeftReservoirWithImplantedOhmicSP self =
      *static_cast<LeftReservoirWithImplantedOhmicSP*>(handle);
  return String_create(self->type().c_str(), self->type().size());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle LeftReservoirWithImplantedOhmic_ohmic(
    LeftReservoirWithImplantedOhmicHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_ohmic: handle cannot be null");
  }
  LeftReservoirWithImplantedOhmicSP self =
      *static_cast<LeftReservoirWithImplantedOhmicSP*>(handle);
  return new falcon_core::physics::device_structures::ConnectionSP(
      self->ohmic());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle LeftReservoirWithImplantedOhmic_right_neighbor(
    LeftReservoirWithImplantedOhmicHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_right_neighbor: handle cannot be "
        "null");
  }
  LeftReservoirWithImplantedOhmicSP self =
      *static_cast<LeftReservoirWithImplantedOhmicSP*>(handle);
  return new falcon_core::physics::device_structures::ConnectionSP(
      self->right_neighbor());
  FALCON_C_API_END(nullptr)
}

bool LeftReservoirWithImplantedOhmic_equal(
    LeftReservoirWithImplantedOhmicHandle handle,
    LeftReservoirWithImplantedOhmicHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_equal: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_equal: second handle cannot be null");
  }
  LeftReservoirWithImplantedOhmicSP self =
      *static_cast<LeftReservoirWithImplantedOhmicSP*>(handle);
  LeftReservoirWithImplantedOhmicSP real_other =
      *static_cast<LeftReservoirWithImplantedOhmicSP*>(other);
  return *self == *real_other;
  FALCON_C_API_END(false)
}

bool LeftReservoirWithImplantedOhmic_not_equal(
    LeftReservoirWithImplantedOhmicHandle handle,
    LeftReservoirWithImplantedOhmicHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_not_equal: first handle cannot be "
        "null");
  }
  if (!other) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_not_equal: second handle cannot be "
        "null");
  }
  LeftReservoirWithImplantedOhmicSP self =
      *static_cast<LeftReservoirWithImplantedOhmicSP*>(handle);
  LeftReservoirWithImplantedOhmicSP real_other =
      *static_cast<LeftReservoirWithImplantedOhmicSP*>(other);
  return *self != *real_other;
  FALCON_C_API_END(false)
}

StringHandle LeftReservoirWithImplantedOhmic_to_json_string(
    LeftReservoirWithImplantedOhmicHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_to_json_string: handle cannot be "
        "null");
  }
  LeftReservoirWithImplantedOhmicSP self =
      *static_cast<LeftReservoirWithImplantedOhmicSP*>(handle);
  return String_create(self->to_json_string().c_str(),
                       self->to_json_string().size());
  FALCON_C_API_END(nullptr)
}

LeftReservoirWithImplantedOhmicHandle
LeftReservoirWithImplantedOhmic_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_from_json_string: json cannot be "
        "null");
  }
  std::string real_json(json->raw, json->length);
  return new LeftReservoirWithImplantedOhmicSP(
      LeftReservoirWithImplantedOhmic::from_json_string<
          LeftReservoirWithImplantedOhmic>(real_json));
  FALCON_C_API_END(nullptr)
}
}
