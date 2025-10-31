#include "falcon_core/math/AnalyticFunction_c_api.h"

#include <falcon_core/math/AnalyticFunction.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::math;

extern "C" {

AnalyticFunctionHandle AnalyticFunction_create(ListStringHandle labels,
                                               StringHandle     expression) {
  std::string expression_str(expression->raw, expression->length);
  falcon_core::generic::ListSP<std::string> labels_list =
      std::make_shared<falcon_core::generic::List<std::string>>(
          static_cast<falcon_core::generic::List<std::string>*>(labels)
              ->items());
  return new AnalyticFunction(labels_list, expression_str);
}

AnalyticFunctionHandle AnalyticFunction_create_identity() {
  return new AnalyticFunction(*AnalyticFunction::Identity());
}

AnalyticFunctionHandle AnalyticFunction_create_constant(double value) {
  return new AnalyticFunction(*AnalyticFunction::Constant(value));
}

void AnalyticFunction_destroy(AnalyticFunctionHandle handle) {
  delete static_cast<AnalyticFunction*>(handle);
}

ListStringHandle AnalyticFunction_labels(AnalyticFunctionHandle handle) {
  AnalyticFunction self = *static_cast<AnalyticFunction*>(handle);
  return new falcon_core::generic::List<std::string>(*self.labels());
}

double AnalyticFunction_evaluate(AnalyticFunctionHandle handle,
                                 MapStringDoubleHandle  args,
                                 double                 time) {
  AnalyticFunction self = *static_cast<AnalyticFunction*>(handle);
  falcon_core::generic::MapSP<std::string, double> args_map =
      std::make_shared<falcon_core::generic::Map<std::string, double>>(
          *static_cast<falcon_core::generic::Map<std::string, double>*>(args));
  return self.evaluate(args_map, time);
}

FArrayDoubleHandle AnalyticFunction_evaluate_arraywise(
    AnalyticFunctionHandle handle,
    MapStringDoubleHandle  args,
    double                 deltaT,
    double                 maxTime) {
  AnalyticFunction self = *static_cast<AnalyticFunction*>(handle);
  falcon_core::generic::MapSP<std::string, double> args_map =
      std::make_shared<falcon_core::generic::Map<std::string, double>>(
          *static_cast<falcon_core::generic::Map<std::string, double>*>(args));
  return new falcon_core::generic::FArray<double>(
      *self.evaluate(args_map, deltaT, maxTime));
}

bool AnalyticFunction_equal(AnalyticFunctionHandle a,
                            AnalyticFunctionHandle b) {
  AnalyticFunction self_a = *static_cast<AnalyticFunction*>(a);
  AnalyticFunction self_b = *static_cast<AnalyticFunction*>(b);
  return self_a == self_b;
}

bool AnalyticFunction_not_equal(AnalyticFunctionHandle a,
                                AnalyticFunctionHandle b) {
  AnalyticFunction self_a = *static_cast<AnalyticFunction*>(a);
  AnalyticFunction self_b = *static_cast<AnalyticFunction*>(b);
  return self_a != self_b;
}

StringHandle AnalyticFunction_to_json_string(AnalyticFunctionHandle handle) {
  AnalyticFunction self = *static_cast<AnalyticFunction*>(handle);
  std::string      json = self.to_json_string();
  return String_create(json.c_str(), json.size());
}

AnalyticFunctionHandle AnalyticFunction_from_json_string(StringHandle json) {
  std::string json_str(json->raw, json->length);
  auto ptr = AnalyticFunction::from_json_string<AnalyticFunction>(json_str);
  return new AnalyticFunction(*ptr);
}

#ifdef __cplusplus
}
#endif
