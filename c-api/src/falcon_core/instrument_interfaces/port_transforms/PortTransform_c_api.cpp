#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"

#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core;
using namespace instrument_interfaces;
using namespace port_transforms;
using namespace names;

PortTransformHandle PortTransform_create(InstrumentPortHandle   port,
                                         AnalyticFunctionHandle transform) {
  if (!port) {
    throw std::invalid_argument("PortTransform_create: port cannot be null");
  }
  if (!transform) {
    throw std::invalid_argument(
        "PortTransform_create: transform cannot be null");
  }
  InstrumentPortSP real_port =
      std::make_shared<InstrumentPort>(*static_cast<InstrumentPort*>(port));
  math::AnalyticFunctionSP real_transform =
      std::make_shared<math::AnalyticFunction>(
          *static_cast<math::AnalyticFunction*>(transform));
  return new PortTransform(real_port, real_transform);
}

PortTransformHandle PortTransform_create_constant_transform(
    InstrumentPortHandle port, double value) {
  if (!port) {
    throw std::invalid_argument(
        "PortTransform_create_constant_transform: port cannot be null");
  }
  InstrumentPortSP real_port =
      std::make_shared<InstrumentPort>(*static_cast<InstrumentPort*>(port));
  return new PortTransform(real_port, math::AnalyticFunction::Constant(value));
}

PortTransformHandle PortTransform_create_identity_transform(
    InstrumentPortHandle port) {
  if (!port) {
    throw std::invalid_argument(
        "PortTransform_create_identity_transform: port cannot be null");
  }
  InstrumentPortSP real_port =
      std::make_shared<InstrumentPort>(*static_cast<InstrumentPort*>(port));
  return new PortTransform(real_port, math::AnalyticFunction::Identity());
}

void PortTransform_destroy(PortTransformHandle handle) {
  if (!handle) {
    throw std::invalid_argument("PortTransform_destroy: handle cannot be null");
  }
  delete static_cast<PortTransform*>(handle);
}

InstrumentPortHandle PortTransform_port(PortTransformHandle handle) {
  if (!handle) {
    throw std::invalid_argument("PortTransform_port: handle cannot be null");
  }
  const auto port = static_cast<PortTransform*>(handle)->port();
  return new InstrumentPort(*port);
}

ListStringHandle PortTransform_labels(PortTransformHandle handle) {
  if (!handle) {
    throw std::invalid_argument("PortTransform_labels: handle cannot be null");
  }
  PortTransform self = *static_cast<PortTransform*>(handle);
  return new generic::List<std::string>(*self.labels());
}

double PortTransform_evaluate(PortTransformHandle   handle,
                              MapStringDoubleHandle args,
                              double                time) {
  if (!handle) {
    throw std::invalid_argument(
        "PortTransform_evaluate: handle cannot be null");
  }
  if (!args) {
    throw std::invalid_argument("PortTransform_evaluate: args cannot be null");
  }
  PortTransform self = *static_cast<PortTransform*>(handle);
  generic::MapSP<std::string, double> real_args =
      std::make_shared<generic::Map<std::string, double>>(
          *static_cast<generic::Map<std::string, double>*>(args));
  return self.evaluate(real_args, time);
}

FArrayDoubleHandle PortTransform_evaluate_arraywise(PortTransformHandle handle,
                                                    MapStringDoubleHandle args,
                                                    double deltaT,
                                                    double maxTime) {
  if (!handle) {
    throw std::invalid_argument(
        "PortTransform_evaluate_arraywise: handle cannot be null");
  }
  if (!args) {
    throw std::invalid_argument(
        "PortTransform_evaluate_arraywise: args cannot be null");
  }
  PortTransform self = *static_cast<PortTransform*>(handle);
  generic::MapSP<std::string, double> real_args =
      std::make_shared<generic::Map<std::string, double>>(
          *static_cast<generic::Map<std::string, double>*>(args));
  return new generic::FArray<double>(
      *self.evaluate(real_args, deltaT, maxTime));
}

bool PortTransform_equal(PortTransformHandle a, PortTransformHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "PortTransform_equal: first handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "PortTransform_equal: second handle cannot be null");
  }
  PortTransform self       = *static_cast<PortTransform*>(a);
  PortTransform real_other = *static_cast<PortTransform*>(b);
  return self == real_other;
}

bool PortTransform_not_equal(PortTransformHandle a, PortTransformHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "PortTransform_not_equal: first handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "PortTransform_not_equal: second handle cannot be null");
  }
  PortTransform self       = *static_cast<PortTransform*>(a);
  PortTransform real_other = *static_cast<PortTransform*>(b);
  return self != real_other;
}

StringHandle PortTransform_to_json_string(PortTransformHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "PortTransform_to_json_string: handle cannot be null");
  }
  PortTransform self = *static_cast<PortTransform*>(handle);
  std::string   json = self.to_json_string();
  return String_create(json.c_str(), json.size());
}

PortTransformHandle PortTransform_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "PortTransform_from_json_string: json cannot be null");
  }
  std::string     real_json(json->raw, json->length);
  PortTransformSP real_port_transform =
      PortTransform::from_json_string<PortTransform>(real_json);
  return new PortTransform(*real_port_transform);
}
