#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"

#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include <string>

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/units/SymbolUnit.hpp"

using namespace falcon_core;
using namespace falcon_core::autotuner_interfaces;
using namespace falcon_core::autotuner_interfaces::interpretations;

InterpretationContextHandle InterpretationContext_create(
    AxesMeasurementContextHandle independant_variables,
    ListMeasurementContextHandle dependant_variables,
    SymbolUnitHandle             unit) {
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
      std::make_shared<math::Axes<contexts::MeasurementContext>>(
          *static_cast<math::Axes<contexts::MeasurementContext>*>(
              independant_variables));
  generic::ListSP<contexts::MeasurementContext> dependant_vars =
      std::make_shared<generic::List<contexts::MeasurementContext>>(
          *static_cast<generic::List<contexts::MeasurementContext>*>(
              dependant_variables));
  physics::units::SymbolUnitSP symbol_unit =
      std::make_shared<physics::units::SymbolUnit>(
          *static_cast<physics::units::SymbolUnit*>(unit));
  return new InterpretationContext(
      InterpretationContext(independant_vars, dependant_vars, symbol_unit));
}

void InterpretationContext_destroy(InterpretationContextHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_destroy");
  }
  delete static_cast<InterpretationContext*>(handle);
}

AxesMeasurementContextHandle InterpretationContext_independent_variables(
    InterpretationContextHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_independant_variables");
  }
  InterpretationContext* context = static_cast<InterpretationContext*>(handle);
  return new math::Axes<contexts::MeasurementContext>(
      *(context->independent_variables()));
}

ListMeasurementContextHandle InterpretationContext_dependent_variables(
    InterpretationContextHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_dependent_variables");
  }
  InterpretationContext* context = static_cast<InterpretationContext*>(handle);
  return new generic::List<contexts::MeasurementContext>(
      *(context->dependent_variables()));
}

SymbolUnitHandle InterpretationContext_unit(
    InterpretationContextHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_unit");
  }
  InterpretationContext* context = static_cast<InterpretationContext*>(handle);
  return new physics::units::SymbolUnit(*(context->unit()));
}

int InterpretationContext_dimension(InterpretationContextHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_dimension");
  }
  InterpretationContext* context = static_cast<InterpretationContext*>(handle);
  return context->dimension();
}

void InterpretationContext_dependent_variable(
    InterpretationContextHandle handle, MeasurementContextHandle variable) {
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
  InterpretationContext* context = static_cast<InterpretationContext*>(handle);
  contexts::MeasurementContextSP var =
      std::make_shared<contexts::MeasurementContext>(
          *static_cast<contexts::MeasurementContext*>(variable));
  context->add_dependent_variable(var);
}

void InterpretationContext_replace_dependent_variable(
    InterpretationContextHandle handle,
    int                         index,
    MeasurementContextHandle    variable) {
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
  InterpretationContext* context = static_cast<InterpretationContext*>(handle);
  contexts::MeasurementContextSP var =
      std::make_shared<contexts::MeasurementContext>(
          *static_cast<contexts::MeasurementContext*>(variable));
  context->replace_dependent_variable(index, var);
}

MeasurementContextHandle InterpretationContext_get_independent_variables(
    InterpretationContextHandle handle, int index) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "InterpretationContext_get_independent_variables");
  }
  InterpretationContext* context = static_cast<InterpretationContext*>(handle);
  contexts::MeasurementContextSP var = context->get_independent_variable(index);
  return new contexts::MeasurementContext(*var);
}

InterpretationContextHandle InterpretationContext_with_unit(
    InterpretationContextHandle handle, SymbolUnitHandle unit) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContext");
  }
  InterpretationContext* context = static_cast<InterpretationContext*>(handle);
  physics::units::SymbolUnitSP symbol_unit =
      std::make_shared<physics::units::SymbolUnit>(
          *static_cast<physics::units::SymbolUnit*>(unit));
  return new InterpretationContext(*context->with_unit(symbol_unit));
}

bool InterpretationContext_equal(InterpretationContextHandle a,
                                 InterpretationContextHandle b) {
  if (!a || !b) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_equal");
  }
  auto context_a = static_cast<InterpretationContext*>(a);
  auto context_b = static_cast<InterpretationContext*>(b);
  return (*context_a == *context_b);
}

bool InterpretationContext_not_equal(InterpretationContextHandle a,
                                     InterpretationContextHandle b) {
  if (!a || !b) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_not_equal");
  }
  auto context_a = static_cast<InterpretationContext*>(a);
  auto context_b = static_cast<InterpretationContext*>(b);
  return (*context_a != *context_b);
}

StringHandle InterpretationContext_to_json_string(
    InterpretationContextHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to InterpretationContext_to_json_string");
  }
  InterpretationContext* context = static_cast<InterpretationContext*>(handle);
  std::string            json    = context->to_json_string();
  return String_create(json.c_str(), json.size());
}

InterpretationContextHandle InterpretationContext_from_json_string(
    StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to "
        "InterpretationContext_from_json_string");
  }
  std::string raw_json(json->raw);
  auto        ptr =
      InterpretationContext::from_json_string<InterpretationContext>(raw_json);
  return new InterpretationContext(*ptr);
}
