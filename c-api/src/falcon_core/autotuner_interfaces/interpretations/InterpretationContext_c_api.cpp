#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"

#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include <string>

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/units/SymbolUnit.hpp"

using namespace falcon_core;
using namespace falcon_core::autotuner_interfaces;
using namespace falcon_core::autotuner_interfaces::interpretations;

extern "C" {
InterpretationContextHandle InterpretationContext_create(
    AxesMeasurementContextHandle independant_variables,
    ListMeasurementContextHandle dependant_variables,
    SymbolUnitHandle             unit) {
  FALCON_C_API_BEGIN
  if (!independant_variables) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_create: "
        "independant_variables");
  }
  if (!dependant_variables) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_create: "
        "dependant_variables");
  }
  if (!unit) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_create: unit");
  }
  math::AxesSP<contexts::MeasurementContext> independant_vars =
      *static_cast<math::AxesSP<contexts::MeasurementContext>*>(
          independant_variables);
  generic::ListSP<contexts::MeasurementContext> dependant_vars =
      *static_cast<generic::ListSP<contexts::MeasurementContext>*>(
          dependant_variables);
  physics::units::SymbolUnitSP symbol_unit =
      *static_cast<physics::units::SymbolUnitSP*>(unit);
  return new InterpretationContextSP(std::make_shared<InterpretationContext>(
      independant_vars, dependant_vars, symbol_unit));
  FALCON_C_API_END(nullptr)
}

void InterpretationContext_destroy(InterpretationContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_destroy");
  }
  delete static_cast<InterpretationContextSP*>(handle);
  FALCON_C_API_END()
}

AxesMeasurementContextHandle InterpretationContext_independent_variables(
    InterpretationContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_independant_variables");
  }
  InterpretationContextSP context =
      *static_cast<InterpretationContextSP*>(handle);
  return new math::AxesSP<contexts::MeasurementContext>(
      context->independent_variables());
  FALCON_C_API_END(nullptr)
}

ListMeasurementContextHandle InterpretationContext_dependent_variables(
    InterpretationContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_dependent_variables");
  }
  InterpretationContextSP context =
      *static_cast<InterpretationContextSP*>(handle);
  return new generic::ListSP<contexts::MeasurementContext>(
      context->dependent_variables());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle InterpretationContext_unit(
    InterpretationContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_unit");
  }
  InterpretationContextSP context =
      *static_cast<InterpretationContextSP*>(handle);
  return new physics::units::SymbolUnitSP(context->unit());
  FALCON_C_API_END(nullptr)
}

int InterpretationContext_dimension(InterpretationContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_dimension");
  }
  InterpretationContextSP context =
      *static_cast<InterpretationContextSP*>(handle);
  return context->dimension();
  FALCON_C_API_END(0)
}

void InterpretationContext_add_dependent_variable(
    InterpretationContextHandle handle, MeasurementContextHandle variable) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_dependent_variable: "
        "handle");
  }
  if (!variable) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_dependent_variable: "
        "variable");
  }
  InterpretationContextSP context =
      *static_cast<InterpretationContextSP*>(handle);
  contexts::MeasurementContextSP var =
      *static_cast<contexts::MeasurementContextSP*>(variable);
  context->add_dependent_variable(var);
  FALCON_C_API_END()
}

void InterpretationContext_replace_dependent_variable(
    InterpretationContextHandle handle,
    int                         index,
    MeasurementContextHandle    variable) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "InterpretationContext_replace_dependent_variable: handle");
  }
  if (!variable) {
    throw std::invalid_argument(
        "Null handle passed to "
        "InterpretationContext_replace_dependent_variable: variable");
  }
  InterpretationContextSP context =
      *static_cast<InterpretationContextSP*>(handle);
  contexts::MeasurementContextSP var =
      *static_cast<contexts::MeasurementContextSP*>(variable);
  context->replace_dependent_variable(index, var);
  FALCON_C_API_END()
}

MeasurementContextHandle InterpretationContext_get_independent_variables(
    InterpretationContextHandle handle, int index) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "InterpretationContext_get_independent_variables");
  }
  InterpretationContextSP context =
      *static_cast<InterpretationContextSP*>(handle);
  contexts::MeasurementContextSP var = context->get_independent_variable(index);
  return new contexts::MeasurementContextSP(var);
  FALCON_C_API_END(nullptr)
}

InterpretationContextHandle InterpretationContext_with_unit(
    InterpretationContextHandle handle, SymbolUnitHandle unit) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContext");
  }
  if (!unit) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_with_unit: unit");
  }
  InterpretationContextSP context =
      *static_cast<InterpretationContextSP*>(handle);
  physics::units::SymbolUnitSP symbol_unit =
      *static_cast<physics::units::SymbolUnitSP*>(unit);
  return new InterpretationContextSP(context->with_unit(symbol_unit));
  FALCON_C_API_END(nullptr)
}

bool InterpretationContext_equal(InterpretationContextHandle handle,
                                 InterpretationContextHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_equal");
  }
  auto context_a = *static_cast<InterpretationContextSP*>(handle);
  auto context_b = *static_cast<InterpretationContextSP*>(other);
  return (*context_a == *context_b);
  FALCON_C_API_END(false)
}

bool InterpretationContext_not_equal(InterpretationContextHandle handle,
                                     InterpretationContextHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_not_equal");
  }
  auto context_a = *static_cast<InterpretationContextSP*>(handle);
  auto context_b = *static_cast<InterpretationContextSP*>(other);
  return (*context_a != *context_b);
  FALCON_C_API_END(false)
}

StringHandle InterpretationContext_to_json_string(
    InterpretationContextHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_to_json_string");
  }
  InterpretationContextSP context =
      *static_cast<InterpretationContextSP*>(handle);
  std::string json = context->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

InterpretationContextHandle InterpretationContext_from_json_string(
    StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to "
        "InterpretationContext_from_json_string");
  }
  std::string raw_json(json->raw);
  auto        ptr =
      InterpretationContext::from_json_string<InterpretationContext>(raw_json);
  return new InterpretationContextSP(ptr);
  FALCON_C_API_END(nullptr)
}
}
