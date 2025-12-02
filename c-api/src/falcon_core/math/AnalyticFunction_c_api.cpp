#include "falcon_core/math/AnalyticFunction_c_api.h"

#include <falcon_core/math/AnalyticFunction.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::math;

extern "C" {
AnalyticFunctionHandle AnalyticFunction_create(ListStringHandle labels,
                                               StringHandle     expression) {
  FALCON_C_API_BEGIN
  if (!labels) {
    throw std::invalid_argument(
        "AnalyticFunction_create: labels cannot be null");
  }
  if (!expression) {
    throw std::invalid_argument(
        "AnalyticFunction_create: expression cannot be null");
  }
  std::string expression_str(expression->raw, expression->length);
  falcon_core::generic::ListSP<std::string> labels_list =
      std::make_shared<falcon_core::generic::List<std::string>>(
          static_cast<falcon_core::generic::List<std::string>*>(labels)
              ->items());
  return new AnalyticFunction(labels_list, expression_str);
  FALCON_C_API_END(nullptr)
}

AnalyticFunctionHandle AnalyticFunction_create_identity() {
  FALCON_C_API_BEGIN
  return new AnalyticFunction(*AnalyticFunction::Identity());
  FALCON_C_API_END(nullptr)
}

AnalyticFunctionHandle AnalyticFunction_create_constant(double value) {
  FALCON_C_API_BEGIN
  return new AnalyticFunction(*AnalyticFunction::Constant(value));
  FALCON_C_API_END(nullptr)
}

void AnalyticFunction_destroy(AnalyticFunctionHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AnalyticFunction_destroy: handle cannot be null");
  }
  delete static_cast<AnalyticFunction*>(handle);
  FALCON_C_API_END()
}

ListStringHandle AnalyticFunction_labels(AnalyticFunctionHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AnalyticFunction_labels: handle cannot be null");
  }
  AnalyticFunction self = *static_cast<AnalyticFunction*>(handle);
  return new falcon_core::generic::List<std::string>(*self.labels());
  FALCON_C_API_END(nullptr)
}

double AnalyticFunction_evaluate(AnalyticFunctionHandle handle,
                                 MapStringDoubleHandle  args,
                                 double                 time) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AnalyticFunction_evaluate: handle cannot be null");
  }
  if (!args) {
    throw std::invalid_argument(
        "AnalyticFunction_evaluate: args cannot be null");
  }
  AnalyticFunction self = *static_cast<AnalyticFunction*>(handle);
  falcon_core::generic::MapSP<std::string, double> args_map =
      std::make_shared<falcon_core::generic::Map<std::string, double>>(
          *static_cast<falcon_core::generic::Map<std::string, double>*>(args));
  return self.evaluate(args_map, time);
  FALCON_C_API_END(0.0)
}

FArrayDoubleHandle AnalyticFunction_evaluate_arraywise(
    AnalyticFunctionHandle handle,
    MapStringDoubleHandle  args,
    double                 deltaT,
    double                 maxTime) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AnalyticFunction_evaluate_arraywise: handle cannot be null");
  }
  if (!args) {
    throw std::invalid_argument(
        "AnalyticFunction_evaluate_arraywise: args cannot be null");
  }
  AnalyticFunction self = *static_cast<AnalyticFunction*>(handle);
  falcon_core::generic::MapSP<std::string, double> args_map =
      std::make_shared<falcon_core::generic::Map<std::string, double>>(
          *static_cast<falcon_core::generic::Map<std::string, double>*>(args));
  return new falcon_core::generic::FArray<double>(
      *self.evaluate(args_map, deltaT, maxTime));
  FALCON_C_API_END(nullptr)
}

bool AnalyticFunction_equal(AnalyticFunctionHandle a,
                            AnalyticFunctionHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("AnalyticFunction_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("AnalyticFunction_equal: b cannot be null");
  }
  AnalyticFunction self_a = *static_cast<AnalyticFunction*>(a);
  AnalyticFunction self_b = *static_cast<AnalyticFunction*>(b);
  return self_a == self_b;
  FALCON_C_API_END(false)
}

bool AnalyticFunction_not_equal(AnalyticFunctionHandle a,
                                AnalyticFunctionHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("AnalyticFunction_not_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("AnalyticFunction_not_equal: b cannot be null");
  }
  AnalyticFunction self_a = *static_cast<AnalyticFunction*>(a);
  AnalyticFunction self_b = *static_cast<AnalyticFunction*>(b);
  return self_a != self_b;
  FALCON_C_API_END(false)
}

StringHandle AnalyticFunction_to_json_string(AnalyticFunctionHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AnalyticFunction_to_json_string: handle cannot be null");
  }
  AnalyticFunction self = *static_cast<AnalyticFunction*>(handle);
  std::string      json = self.to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

AnalyticFunctionHandle AnalyticFunction_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "AnalyticFunction_from_json_string: json cannot be null");
  }
  std::string json_str(json->raw, json->length);
  auto ptr = AnalyticFunction::from_json_string<AnalyticFunction>(json_str);
  return new AnalyticFunction(*ptr);
  FALCON_C_API_END(nullptr)
}
}
