#pragma once

#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Map.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace interpretations {

template <typename Value>
class InterpretationContainer
    : public generic::Map<InterpretationContext, Value> {
  physics::units::SymbolUnitSP _unit;

 public:
  InterpretationContainer() = default;
  /**
   * @brief A container for interpretations of the contents.
   * @param contexts The list of contexts.
   * @throws std::invalid_argument if contexts have different units.
   */
  InterpretationContainer(generic::List<InterpretationContext> contexts) {
    for (const auto& context : contexts) {
      if (!this->_unit) {
        this->_unit = context->unit();
      } else if (*this->_unit != *context->unit()) {
        throw std::invalid_argument(
            "All contexts must have the same unit in InterpretationContainer");
      }
      this->insert({context, Value()});
    }
  }
  /**
   * @brief Returns the unit that all contexts in this constainer must have.
   */
  physics::units::SymbolUnitSP unit() const;

 private:
  container_type _container;
};
}  // namespace interpretations
}  // namespace autotuner_interfaces
}  // namespace falcon_core
