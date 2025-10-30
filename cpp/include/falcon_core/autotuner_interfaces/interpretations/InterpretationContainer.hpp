#pragma once

#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Map.hpp"
#include "falcon_core/generic/Pair.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace interpretations {

template <typename Value>
class InterpretationContainer
    : public generic::Map<InterpretationContext, Value> {
  physics::units::SymbolUnitSP _unit;

 protected:
  InterpretationContainer() = default;
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Map<InterpretationContext, Value>>(this),
       _unit);
  }

 public:
  /**
   * @brief A container for interpretations of the contents.
   * @param contexts The list of contexts.
   * @throws std::invalid_argument if contexts have different units.
   */
  InterpretationContainer(
      const generic::MapSP<InterpretationContext, Value>& map) {
    for (const generic::PairSP<InterpretationContext, Value>& context : *map) {
      if (!this->_unit) {
        this->_unit = context->first()->unit();
      } else if (*this->_unit != *context->first()->unit()) {
        throw std::invalid_argument(
            "All contexts must have the same unit in InterpretationContainer");
      }
      this->insert(context->first(), context->second());
    }
  }
  /**
   * @brief Returns the unit that all contexts in this constainer must have.
   */
  const physics::units::SymbolUnitSP unit() const { return _unit; }
  /**
   * @brief Select contexts that involve a specific connection.
   * @param connection The connection to search for.
   * @returns A list of contexts that involve the specified connection in either
   * independant or dependant variables.
   */
  const generic::ListSP<InterpretationContext> select_by_connection(
      const physics::device_structures::ConnectionSP& connection) const {
    auto results = std::make_shared<generic::List<InterpretationContext>>();
    for (const generic::PairSP<InterpretationContext, Value>& pair :
         this->items().items()) {
      // Check independent variables
      InterpretationContextSP context = pair->first();
      for (size_t i = 0; i < context->dimension(); ++i) {
        auto indep_var = context->get_independent_variable(i);
        if (indep_var->connection() == connection) {
          results->push_back(context);
          goto next_context;
        }
      }
      // Check dependent variables
      for (const auto& dep_var : *context->dependent_variables()) {
        if (dep_var->connection() == connection) {
          results->push_back(context);
          break;
        }
      }
    next_context:;
    }
    return results;
  }

  /**
   * @brief Select contexts that involve all of the specified connections.
   * @param connections List of connections to search for.
   * @returns A list of contexts that involve all specified connections.
   */
  const generic::ListSP<InterpretationContext> select_by_connections(
      const std::vector<physics::device_structures::ConnectionSP>& connections)
      const {
    auto matching_contexts =
        std::set<InterpretationContextSP>(this->begin(), this->end());
    for (const auto& connection : connections) {
      auto contexts_with_connection = std::set<InterpretationContextSP>(
          select_by_connection(connection)->items().begin(),
          select_by_connection(connection)->items().end());
      // Keep only contexts that match all connections so far
      std::set<InterpretationContextSP> intersection;
      std::set_intersection(matching_contexts.begin(),
                            matching_contexts.end(),
                            contexts_with_connection.begin(),
                            contexts_with_connection.end(),
                            std::inserter(intersection, intersection.begin()));
      matching_contexts = std::move(intersection);
      if (matching_contexts.empty()) {
        return std::make_shared<generic::List<InterpretationContext>>();
      }
    }
    return std::make_shared<generic::List<InterpretationContext>>(
        std::vector<InterpretationContextSP>(matching_contexts.begin(),
                                             matching_contexts.end()));
  }
  const generic::ListSP<InterpretationContext> select_by_independent_connection(
      const physics::device_structures::ConnectionSP& connection) {
    for (const generic::PairSP<InterpretationContext, Value>& pair :
         this->items().items()) {
      // Check independent variables
      InterpretationContextSP context = pair->first();
      for (int i = 0; i < context->dimension(); ++i) {
        auto indep_var = context->get_independent_variable(i);
        if (*indep_var->connection() == *connection) {
          return std::make_shared<generic::List<InterpretationContext>>(
              std::vector<InterpretationContextSP>{context});
        }
      }
    }
  }
  const generic::ListSP<InterpretationContext> select_by_dependent_connection(
      const physics::device_structures::ConnectionSP& connection) {
    for (const generic::PairSP<InterpretationContext, Value>& pair :
         this->items().items()) {
      // Check independent variables
      InterpretationContextSP context = pair->first();
      for (const auto& dep_var : *context->dependent_variables()) {
        if (*dep_var->connection() == *connection) {
          return std::make_shared<generic::List<InterpretationContext>>(
              std::vector<InterpretationContextSP>{context});
        }
      }
    }
  }
  const generic::ListSP<InterpretationContext> select_contexts(
      const generic::ListSP<physics::device_structures::Connection>&
          independent_connections,
      const generic::ListSP<physics::device_structures::Connection>&
          dependent_connections) {
    // Start with all contexts
    std::set<InterpretationContext*> matching_contexts;
    for (generic::PairSP<InterpretationContext, Value>& kv : this->items()) {
      matching_contexts.insert(kv->first);
    }

    // Process independent connections
    if (independent_connections && !independent_connections->empty()) {
      for (auto& connection : *independent_connections) {
        std::set<InterpretationContext*> contexts =
            select_by_independent_connection(connection);
        std::set<InterpretationContext*> intersection;
        std::set_intersection(
            matching_contexts.begin(),
            matching_contexts.end(),
            contexts.begin(),
            contexts.end(),
            std::inserter(intersection, intersection.begin()));
        matching_contexts = std::move(intersection);

        // Early exit if no matches
        if (matching_contexts.empty()) {
          return generic::ListSP<InterpretationContext>();
        }
      }
    }

    // Process dependent connections
    if (dependent_connections && !dependent_connections->empty()) {
      for (auto& connection : *dependent_connections) {
        std::set<InterpretationContext*> contexts =
            select_by_dependent_connection(connection);
        std::set<InterpretationContext*> intersection;
        std::set_intersection(
            matching_contexts.begin(),
            matching_contexts.end(),
            contexts.begin(),
            contexts.end(),
            std::inserter(intersection, intersection.begin()));
        matching_contexts = std::move(intersection);

        // Early exit if no matches
        if (matching_contexts.empty()) {
          return generic::ListSP<InterpretationContext>();
        }
      }
    }

    // Convert set to ListSP
    auto result = std::make_shared<generic::List<InterpretationContext>>(
        matching_contexts.begin(), matching_contexts.end());
    return result;
  }
};
template <typename Value>
using InterpretationContainerSP =
    std::shared_ptr<InterpretationContainer<Value>>;
}  // namespace interpretations
}  // namespace autotuner_interfaces
}  // namespace falcon_core
