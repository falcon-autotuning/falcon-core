#include "falcon-core/physics/config/geometries/RightReservoirWithImplantedOhmic_c_api.h"

#include <falcon-core/physics/config/geometries/RightReservoirWithImplantedOhmic.hpp>

#include "falcon-core/Precompiled_c_api.h"

using namespace falcon_core::physics::config::geometries;

extern "C" {
DEFINE_C_API_COPY(RightReservoirWithImplantedOhmic);
DEFINE_C_API_DESTROY(RightReservoirWithImplantedOhmic);
DEFINE_C_API_EQUAL(RightReservoirWithImplantedOhmic);
DEFINE_C_API_NOT_EQUAL(RightReservoirWithImplantedOhmic);
DEFINE_C_API_TO_JSON(RightReservoirWithImplantedOhmic);
DEFINE_C_API_FROM_JSON(RightReservoirWithImplantedOhmic);
RightReservoirWithImplantedOhmicHandle RightReservoirWithImplantedOhmic_create(
    StringHandle     name,
    ConnectionHandle right_neighbor,
    ConnectionHandle ohmic) {
  FALCON_C_API_BEGIN
  if (!name) {
    throw std::invalid_argument(
        "RightReservoirWithImplantedOhmic_create: Name cannot be null");
  }
  if (!right_neighbor) {
    throw std::invalid_argument(
        "RightReservoirWithImplantedOhmic_create: right_neighbor cannot be "
        "null");
  }
  if (!ohmic) {
    throw std::invalid_argument(
        "RightReservoirWithImplantedOhmic_create: ohmic cannot be null");
  }
  std::string real_name(name->raw, name->length);
  falcon_core::physics::device_structures::ConnectionSP right_conn =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          right_neighbor);
  falcon_core::physics::device_structures::ConnectionSP ohmic_conn =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          ohmic);
  return new RightReservoirWithImplantedOhmicSP(
      std::make_shared<RightReservoirWithImplantedOhmic>(
          real_name, right_conn, ohmic_conn));
  FALCON_C_API_END(nullptr)
}

StringHandle RightReservoirWithImplantedOhmic_name(
    RightReservoirWithImplantedOhmicHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "RightReservoirWithImplantedOhmic_name: handle cannot be null");
  }
  RightReservoirWithImplantedOhmicSP self =
      *static_cast<RightReservoirWithImplantedOhmicSP*>(handle);
  return String_create(self->name().c_str(), self->name().size());
  FALCON_C_API_END(nullptr)
}

StringHandle RightReservoirWithImplantedOhmic_type(
    RightReservoirWithImplantedOhmicHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "RightReservoirWithImplantedOhmic_type: handle cannot be null");
  }
  RightReservoirWithImplantedOhmicSP self =
      *static_cast<RightReservoirWithImplantedOhmicSP*>(handle);
  return String_create(self->type().c_str(), self->type().size());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle RightReservoirWithImplantedOhmic_ohmic(
    RightReservoirWithImplantedOhmicHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "RightReservoirWithImplantedOhmic_ohmic: handle cannot be null");
  }
  RightReservoirWithImplantedOhmicSP self =
      *static_cast<RightReservoirWithImplantedOhmicSP*>(handle);
  return new falcon_core::physics::device_structures::ConnectionSP(
      self->ohmic());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle RightReservoirWithImplantedOhmic_left_neighbor(
    RightReservoirWithImplantedOhmicHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "RightReservoirWithImplantedOhmic_left_neighbor: handle cannot be "
        "null");
  }
  RightReservoirWithImplantedOhmicSP self =
      *static_cast<RightReservoirWithImplantedOhmicSP*>(handle);
  return new falcon_core::physics::device_structures::ConnectionSP(
      self->left_neighbor());
  FALCON_C_API_END(nullptr)
}
}
