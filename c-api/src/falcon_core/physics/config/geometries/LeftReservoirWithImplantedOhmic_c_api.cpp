#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic_c_api.h"

#include <falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"

using namespace falcon_core::physics::config::geometries;

LeftReservoirWithImplantedOhmicHandle LeftReservoirWithImplantedOhmic_create(
    StringHandle     name,
    ConnectionHandle right_neighbor,
    ConnectionHandle ohmic) {
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
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              right_neighbor));
  falcon_core::physics::device_structures::ConnectionSP ohmic_conn =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              ohmic));
  return new LeftReservoirWithImplantedOhmic(real_name, right_conn, ohmic_conn);
}

void LeftReservoirWithImplantedOhmic_destroy(
    LeftReservoirWithImplantedOhmicHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_destroy: handle cannot be null");
  }
  delete static_cast<LeftReservoirWithImplantedOhmic*>(handle);
}

StringHandle LeftReservoirWithImplantedOhmic_name(
    LeftReservoirWithImplantedOhmicHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_name: handle cannot be null");
  }
  LeftReservoirWithImplantedOhmic self =
      *static_cast<LeftReservoirWithImplantedOhmic*>(handle);
  return String_create(self.name().c_str(), self.name().size());
}

StringHandle LeftReservoirWithImplantedOhmic_type(
    LeftReservoirWithImplantedOhmicHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_type: handle cannot be null");
  }
  LeftReservoirWithImplantedOhmic self =
      *static_cast<LeftReservoirWithImplantedOhmic*>(handle);
  return String_create(self.type().c_str(), self.type().size());
}

ConnectionHandle LeftReservoirWithImplantedOhmic_ohmic(
    LeftReservoirWithImplantedOhmicHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_ohmic: handle cannot be null");
  }
  LeftReservoirWithImplantedOhmic self =
      *static_cast<LeftReservoirWithImplantedOhmic*>(handle);
  return new falcon_core::physics::device_structures::Connection(
      *(self.ohmic()));
}

ConnectionHandle LeftReservoirWithImplantedOhmic_right_neighbor(
    LeftReservoirWithImplantedOhmicHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_right_neighbor: handle cannot be "
        "null");
  }
  LeftReservoirWithImplantedOhmic self =
      *static_cast<LeftReservoirWithImplantedOhmic*>(handle);
  return new falcon_core::physics::device_structures::Connection(
      *(self.right_neighbor()));
}

bool LeftReservoirWithImplantedOhmic_equal(
    LeftReservoirWithImplantedOhmicHandle a,
    LeftReservoirWithImplantedOhmicHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_equal: first handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_equal: second handle cannot be null");
  }
  LeftReservoirWithImplantedOhmic self =
      *static_cast<LeftReservoirWithImplantedOhmic*>(a);
  LeftReservoirWithImplantedOhmic real_other =
      *static_cast<LeftReservoirWithImplantedOhmic*>(b);
  return self == real_other;
}

bool LeftReservoirWithImplantedOhmic_not_equal(
    LeftReservoirWithImplantedOhmicHandle a,
    LeftReservoirWithImplantedOhmicHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_not_equal: first handle cannot be "
        "null");
  }
  if (!b) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_not_equal: second handle cannot be "
        "null");
  }
  LeftReservoirWithImplantedOhmic self =
      *static_cast<LeftReservoirWithImplantedOhmic*>(a);
  LeftReservoirWithImplantedOhmic real_other =
      *static_cast<LeftReservoirWithImplantedOhmic*>(b);
  return self != real_other;
}

StringHandle LeftReservoirWithImplantedOhmic_to_json_string(
    LeftReservoirWithImplantedOhmicHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_to_json_string: handle cannot be "
        "null");
  }
  LeftReservoirWithImplantedOhmic self =
      *static_cast<LeftReservoirWithImplantedOhmic*>(handle);
  return String_create(self.to_json_string().c_str(),
                       self.to_json_string().size());
}

LeftReservoirWithImplantedOhmicHandle
LeftReservoirWithImplantedOhmic_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "LeftReservoirWithImplantedOhmic_from_json_string: json cannot be "
        "null");
  }
  std::string real_json(json->raw, json->length);
  return new LeftReservoirWithImplantedOhmic(
      *LeftReservoirWithImplantedOhmic::from_json_string<
          LeftReservoirWithImplantedOhmic>(real_json));
}
