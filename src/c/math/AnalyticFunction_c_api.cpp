#include "falcon-core/math/AnalyticFunction_c_api.h"

#include <falcon-core/math/AnalyticFunction.hpp>

#include "falcon-core/Precompiled_c_api.h"

using namespace falcon_core::math;

extern "C" {
DEFINE_C_API_COPY(AnalyticFunction);
DEFINE_C_API_DESTROY(AnalyticFunction);
DEFINE_C_API_EQUAL(AnalyticFunction);
DEFINE_C_API_NOT_EQUAL(AnalyticFunction);
DEFINE_C_API_TO_JSON(AnalyticFunction);
DEFINE_C_API_FROM_JSON(AnalyticFunction);
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
          (*static_cast<falcon_core::generic::ListSP<std::string>*>(labels))
              ->items());
  return new AnalyticFunctionSP(
      std::make_shared<AnalyticFunction>(labels_list, expression_str));
  FALCON_C_API_END(nullptr)
}

AnalyticFunctionHandle AnalyticFunction_create_identity() {
  FALCON_C_API_BEGIN
  return new AnalyticFunctionSP(AnalyticFunction::Identity());
  FALCON_C_API_END(nullptr)
}

AnalyticFunctionHandle AnalyticFunction_create_constant(double value) {
  FALCON_C_API_BEGIN
  return new AnalyticFunctionSP(AnalyticFunction::Constant(value));
  FALCON_C_API_END(nullptr)
}

ListStringHandle AnalyticFunction_labels(AnalyticFunctionHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "AnalyticFunction_labels: handle cannot be null");
  }
  AnalyticFunctionSP self = *static_cast<AnalyticFunctionSP*>(handle);
  return new falcon_core::generic::ListSP<std::string>(self->labels());
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
  AnalyticFunctionSP self = *static_cast<AnalyticFunctionSP*>(handle);
  falcon_core::generic::MapSP<std::string, double> args_map =
      *static_cast<falcon_core::generic::MapSP<std::string, double>*>(args);
  return self->evaluate(args_map, time);
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
  AnalyticFunctionSP self = *static_cast<AnalyticFunctionSP*>(handle);
  falcon_core::generic::MapSP<std::string, double> args_map =
      *static_cast<falcon_core::generic::MapSP<std::string, double>*>(args);
  return new falcon_core::generic::FArraySP<double>(
      self->evaluate(args_map, deltaT, maxTime));
  FALCON_C_API_END(nullptr)
}
}
