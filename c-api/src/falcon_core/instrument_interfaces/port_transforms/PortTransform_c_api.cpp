#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"

#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core;
using namespace instrument_interfaces;
using namespace port_transforms;
using namespace names;

extern "C" {
PortTransformHandle PortTransform_create(InstrumentPortHandle   port,
                                         AnalyticFunctionHandle transform) {
  FALCON_C_API_BEGIN
  if (!port) {
    throw std::invalid_argument("PortTransform_create: port cannot be null");
  }
  if (!transform) {
    throw std::invalid_argument(
        "PortTransform_create: transform cannot be null");
  }
  InstrumentPortSP         real_port = *static_cast<InstrumentPortSP*>(port);
  math::AnalyticFunctionSP real_transform =
      *static_cast<math::AnalyticFunctionSP*>(transform);
  return new PortTransformSP(
      std::make_shared<PortTransform>(real_port, real_transform));
  FALCON_C_API_END(nullptr)
}

PortTransformHandle PortTransform_create_constant_transform(
    InstrumentPortHandle port, double value) {
  FALCON_C_API_BEGIN
  if (!port) {
    throw std::invalid_argument(
        "PortTransform_create_constant_transform: port cannot be null");
  }
  InstrumentPortSP real_port = *static_cast<InstrumentPortSP*>(port);
  return new PortTransformSP(std::make_shared<PortTransform>(
      real_port, math::AnalyticFunction::Constant(value)));
  FALCON_C_API_END(nullptr)
}

PortTransformHandle PortTransform_create_identity_transform(
    InstrumentPortHandle port) {
  FALCON_C_API_BEGIN
  if (!port) {
    throw std::invalid_argument(
        "PortTransform_create_identity_transform: port cannot be null");
  }
  InstrumentPortSP real_port = *static_cast<InstrumentPortSP*>(port);
  return new PortTransformSP(std::make_shared<PortTransform>(
      real_port, math::AnalyticFunction::Identity()));
  FALCON_C_API_END(nullptr)
}

void PortTransform_destroy(PortTransformHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("PortTransform_destroy: handle cannot be null");
  }
  delete static_cast<PortTransformSP*>(handle);
  FALCON_C_API_END()
}

InstrumentPortHandle PortTransform_port(PortTransformHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("PortTransform_port: handle cannot be null");
  }
  const auto port = (*static_cast<PortTransformSP*>(handle))->port();
  return new InstrumentPortSP(port);
  FALCON_C_API_END(nullptr)
}

ListStringHandle PortTransform_labels(PortTransformHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("PortTransform_labels: handle cannot be null");
  }
  PortTransformSP self = *static_cast<PortTransformSP*>(handle);
  return new generic::ListSP<std::string>(self->labels());
  FALCON_C_API_END(nullptr)
}

double PortTransform_evaluate(PortTransformHandle   handle,
                              MapStringDoubleHandle args,
                              double                time) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "PortTransform_evaluate: handle cannot be null");
  }
  if (!args) {
    throw std::invalid_argument("PortTransform_evaluate: args cannot be null");
  }
  PortTransformSP self = *static_cast<PortTransformSP*>(handle);
  generic::MapSP<std::string, double> real_args =
      *static_cast<generic::MapSP<std::string, double>*>(args);
  return self->evaluate(real_args, time);
  FALCON_C_API_END(0.0)
}

FArrayDoubleHandle PortTransform_evaluate_arraywise(PortTransformHandle handle,
                                                    MapStringDoubleHandle args,
                                                    double deltaT,
                                                    double maxTime) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "PortTransform_evaluate_arraywise: handle cannot be null");
  }
  if (!args) {
    throw std::invalid_argument(
        "PortTransform_evaluate_arraywise: args cannot be null");
  }
  PortTransformSP self = *static_cast<PortTransformSP*>(handle);
  generic::MapSP<std::string, double> real_args =
      *static_cast<generic::MapSP<std::string, double>*>(args);
  return new generic::FArraySP<double>(
      self->evaluate(real_args, deltaT, maxTime));
  FALCON_C_API_END(nullptr)
}

bool PortTransform_equal(PortTransformHandle handle,
                         PortTransformHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "PortTransform_equal: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "PortTransform_equal: second handle cannot be null");
  }
  PortTransformSP self       = *static_cast<PortTransformSP*>(handle);
  PortTransformSP real_other = *static_cast<PortTransformSP*>(other);
  return *self == *real_other;
  FALCON_C_API_END(false)
}

bool PortTransform_not_equal(PortTransformHandle handle,
                             PortTransformHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "PortTransform_not_equal: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "PortTransform_not_equal: second handle cannot be null");
  }
  PortTransformSP self       = *static_cast<PortTransformSP*>(handle);
  PortTransformSP real_other = *static_cast<PortTransformSP*>(other);
  return *self != *real_other;
  FALCON_C_API_END(false)
}

StringHandle PortTransform_to_json_string(PortTransformHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "PortTransform_to_json_string: handle cannot be null");
  }
  PortTransformSP self = *static_cast<PortTransformSP*>(handle);
  std::string     json = self->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

PortTransformHandle PortTransform_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "PortTransform_from_json_string: json cannot be null");
  }
  std::string     real_json(json->raw, json->length);
  PortTransformSP real_port_transform =
      PortTransform::from_json_string<PortTransform>(real_json);
  return new PortTransformSP(real_port_transform);
  FALCON_C_API_END(nullptr)
}
}
