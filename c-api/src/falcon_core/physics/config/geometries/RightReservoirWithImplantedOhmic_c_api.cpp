#include "falcon_core/physics/config/geometries/RightReservoirWithImplantedOhmic_c_api.h"

#include <falcon_core/physics/config/geometries/RightReservoirWithImplantedOhmic.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"

using namespace falcon_core::physics::config::geometries;

extern "C" {

RightReservoirWithImplantedOhmicHandle RightReservoirWithImplantedOhmic_create(
    StringHandle     name,
    ConnectionHandle right_neighbor,
    ConnectionHandle ohmic) {
  std::string real_name(name->raw, name->length);
  falcon_core::physics::device_structures::ConnectionSP right_conn =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              right_neighbor));
  falcon_core::physics::device_structures::ConnectionSP ohmic_conn =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              ohmic));
  return new RightReservoirWithImplantedOhmic(
      real_name, right_conn, ohmic_conn);
}

void RightReservoirWithImplantedOhmic_destroy(
    RightReservoirWithImplantedOhmicHandle handle) {
  delete static_cast<RightReservoirWithImplantedOhmic*>(handle);
}

StringHandle RightReservoirWithImplantedOhmic_name(
    RightReservoirWithImplantedOhmicHandle handle) {
  RightReservoirWithImplantedOhmic self =
      *static_cast<RightReservoirWithImplantedOhmic*>(handle);
  return String_create(self.name().c_str(), self.name().size());
}

StringHandle RightReservoirWithImplantedOhmic_type(
    RightReservoirWithImplantedOhmicHandle handle) {
  RightReservoirWithImplantedOhmic self =
      *static_cast<RightReservoirWithImplantedOhmic*>(handle);
  return String_create(self.type().c_str(), self.type().size());
}

ConnectionHandle RightReservoirWithImplantedOhmic_ohmic(
    RightReservoirWithImplantedOhmicHandle handle) {
  RightReservoirWithImplantedOhmic self =
      *static_cast<RightReservoirWithImplantedOhmic*>(handle);
  return new falcon_core::physics::device_structures::Connection(
      *(self.ohmic()));
}

ConnectionHandle RightReservoirWithImplantedOhmic_left_neighbor(
    RightReservoirWithImplantedOhmicHandle handle) {
  RightReservoirWithImplantedOhmic self =
      *static_cast<RightReservoirWithImplantedOhmic*>(handle);
  return new falcon_core::physics::device_structures::Connection(
      *(self.left_neighbor()));
}

bool RightReservoirWithImplantedOhmic_equal(
    RightReservoirWithImplantedOhmicHandle a,
    RightReservoirWithImplantedOhmicHandle b) {
  RightReservoirWithImplantedOhmic self =
      *static_cast<RightReservoirWithImplantedOhmic*>(a);
  RightReservoirWithImplantedOhmic real_other =
      *static_cast<RightReservoirWithImplantedOhmic*>(b);
  return self == real_other;
}

bool RightReservoirWithImplantedOhmic_not_equal(
    RightReservoirWithImplantedOhmicHandle a,
    RightReservoirWithImplantedOhmicHandle b) {
  RightReservoirWithImplantedOhmic self =
      *static_cast<RightReservoirWithImplantedOhmic*>(a);
  RightReservoirWithImplantedOhmic real_other =
      *static_cast<RightReservoirWithImplantedOhmic*>(b);
  return self != real_other;
}

StringHandle RightReservoirWithImplantedOhmic_to_json_string(
    RightReservoirWithImplantedOhmicHandle handle) {
  RightReservoirWithImplantedOhmic self =
      *static_cast<RightReservoirWithImplantedOhmic*>(handle);
  return String_create(self.to_json_string().c_str(),
                       self.to_json_string().size());
}

RightReservoirWithImplantedOhmicHandle
RightReservoirWithImplantedOhmic_from_json_string(StringHandle json) {
  std::string real_json(json->raw, json->length);
  return new RightReservoirWithImplantedOhmic(
      *RightReservoirWithImplantedOhmic::from_json_string<
          RightReservoirWithImplantedOhmic>(real_json));
}

#ifdef __cplusplus
}
#endif
