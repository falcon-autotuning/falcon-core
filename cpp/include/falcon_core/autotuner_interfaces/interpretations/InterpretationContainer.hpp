#pragma once

#include <stdexcept>

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp"
#include "falcon_core/export.h"
#include "falcon_core/generic/CategoryTags.hpp"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Map.hpp"
#include "falcon_core/generic/Pair.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace interpretations {

template <typename Value>
class InterpretationContainer
    : public generic::Map<InterpretationContext, Value> {
  physics::units::SymbolUnitSP    _unit;
  mutable std::shared_timed_mutex _mu_unit;

 protected:
  InterpretationContainer() = default;
  friend class cereal::access;
  template <class Archive>
  inline void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_u(_mu_unit);
    ar(cereal::base_class<generic::Map<InterpretationContext, Value>>(this),
       _unit);
  }

 public:
  InterpretationContainer(const InterpretationContainer<Value>& other)
      : generic::Map<InterpretationContext, Value>(other) {
    std::shared_lock<std::shared_timed_mutex> lock_o(other._mu_unit,
                                                     std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_u(_mu_unit, std::defer_lock);
    std::lock(lock_o, lock_u);
    if (!other._unit) {
      throw std::invalid_argument(
          "InterpretationContainer copy constructor: Other "
          "InterpretationContainer "
          "contains null shared pointer.");
    }
    _unit = std::make_shared<physics::units::SymbolUnit>(*other._unit);
  }
  inline InterpretationContainer<Value>& operator=(
      const InterpretationContainer<Value>& other) {
    if (this != &other) {
      std::shared_lock<std::shared_timed_mutex> lock_o(other._mu_unit,
                                                       std::defer_lock);
      std::unique_lock<std::shared_timed_mutex> lock_u(_mu_unit,
                                                       std::defer_lock);
      std::lock(lock_o, lock_u);
      if (!other._unit) {
        throw std::invalid_argument(
            "InterpretationContainer copy constructor: Other "
            "InterpretationContainer "
            "contains null shared pointer.");
      }
      _unit = std::make_shared<physics::units::SymbolUnit>(*other._unit);
      generic::Map<InterpretationContext, Value>::operator=(other);
    }
    return *this;
  }
  /**
   * @brief A container for interpretations of the contents.
   * @param contexts The list of contexts.
   * @throws std::invalid_argument if contexts have different units.
   */
  InterpretationContainer(
      const generic::MapSP<InterpretationContext, Value>& map)
      : generic::Map<InterpretationContext, Value>(), _unit(nullptr) {
    if (!map) {
      throw std::invalid_argument("The map needs to not be null.");
    }
    InterpretationContextSP first_key                   = map->keys()->at(0);
    _unit                                               = first_key->unit();
    generic::Map<InterpretationContext, Value> real_map = *map;
    for (const generic::PairSP<InterpretationContext, Value>& pair : real_map) {
      if (*this->_unit != *pair->first()->unit()) {
        throw std::invalid_argument(
            "All contexts must have the same unit in InterpretationContainer");
      }
      this->insert(pair->first(), pair->second());
    }
  }
  /**
   * @brief Returns the unit that all contexts in this constainer must have.
   */
  inline const physics::units::SymbolUnitSP unit() const {
    std::shared_lock<std::shared_timed_mutex> lock_u(_mu_unit);
    return _unit;
  }
  /**
   * @brief Select contexts that involve a specific connection.
   * @param connection The connection to search for.
   * @returns A list of contexts that involve the specified connection in either
   * independant or dependant variables.
   */
  inline const generic::ListSP<InterpretationContext> select_by_connection(
      const physics::device_structures::ConnectionSP& connection) const {
    if (!connection) {
      throw std::invalid_argument("The connection needs to not be null.");
    }
    generic::ListSP<InterpretationContext> results =
        std::make_shared<generic::List<InterpretationContext>>();
    generic::List<InterpretationContext> keys = *this->keys();
    for (const InterpretationContextSP& context : keys) {
      // Check independent variables
      if (!context) {
        continue;
      }
      generic::List<contexts::MeasurementContext> deps =
          *context->dependent_variables();
      for (size_t i = 0; i < context->dimension(); ++i) {
        contexts::MeasurementContextSP indep_var =
            context->get_independent_variable(i);
        if (*indep_var->connection() == *connection) {
          results->push_back(context);
          goto next_context;
        }
      }
      // Check dependent variables
      for (const auto& dep_var : deps) {
        if (*dep_var->connection() == *connection) {
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
  inline const generic::ListSP<InterpretationContext> select_by_connections(
      const std::vector<physics::device_structures::ConnectionSP>& connections)
      const {
    std::vector<InterpretationContextSP> matching_contexts;
    for (const auto& pair_sp : *this) {
      if (!pair_sp) {
        throw std::invalid_argument(
            "Each connection must not be null in teh vector.");
      }
      matching_contexts.push_back(pair_sp->first());
    }
    for (const auto& connection : connections) {
      auto contexts_with_connection = select_by_connection(connection)->items();
      std::vector<InterpretationContextSP> intersection;
      for (const auto& ctx : matching_contexts) {
        auto it = std::find_if(contexts_with_connection.begin(),
                               contexts_with_connection.end(),
                               [&](const InterpretationContextSP& other) {
                                 return *ctx == *other;
                               });
        if (it != contexts_with_connection.end()) {
          intersection.push_back(ctx);
        }
      }
      matching_contexts = std::move(intersection);
      if (matching_contexts.empty()) {
        return std::make_shared<generic::List<InterpretationContext>>();
      }
    }
    return std::make_shared<generic::List<InterpretationContext>>(
        matching_contexts);
  }
  inline const generic::ListSP<InterpretationContext>
  select_by_independent_connection(
      const physics::device_structures::ConnectionSP& connection) {
    if (!connection) {
      throw std::invalid_argument("The connection must not be null.");
    }
    generic::ListSP<InterpretationContext> results =
        std::make_shared<generic::List<InterpretationContext>>();
    generic::List<InterpretationContext> keys = *this->keys();
    for (const InterpretationContextSP& context : keys) {
      // Check independent variables
      for (int i = 0; i < context->dimension(); ++i) {
        auto indep_var = context->get_independent_variable(i);
        if (*indep_var->connection() == *connection) {
          results->push_back(context);
          break;
        }
      }
    }
    return results;
  }
  inline const generic::ListSP<InterpretationContext>
  select_by_dependent_connection(
      const physics::device_structures::ConnectionSP& connection) {
    if (!connection) {
      throw std::invalid_argument("The connection must not be null.");
    }
    generic::ListSP<InterpretationContext> results =
        std::make_shared<generic::List<InterpretationContext>>();
    generic::List<InterpretationContext> keys = *this->keys();
    for (const InterpretationContextSP& context : keys) {
      for (const auto& dep_var : *context->dependent_variables()) {
        if (*dep_var->connection() == *connection) {
          results->push_back(context);
          break;
        }
      }
    }
    return results;
  }
  inline const generic::ListSP<InterpretationContext> select_contexts(
      const generic::ListSP<physics::device_structures::Connection>&
          independent_connections,
      const generic::ListSP<physics::device_structures::Connection>&
          dependent_connections) {
    if (!independent_connections) {
      throw std::invalid_argument(
          "The independent connections must not be null.");
    }
    if (!dependent_connections) {
      throw std::invalid_argument(
          "The dependent connections must not be null.");
    }
    // Start with all contexts
    std::vector<InterpretationContextSP> matching_contexts =
        std::vector<InterpretationContextSP>();
    generic::List<generic::Pair<InterpretationContext, Value>> items =
        *this->items();
    for (generic::PairSP<InterpretationContext, Value>& kv : items) {
      matching_contexts.push_back(kv->first());
    }

    // Process independent connections
    if (independent_connections && !independent_connections->empty()) {
      generic::List<physics::device_structures::Connection> inds =
          *independent_connections;
      for (auto& connection : inds) {
        auto list_ptr = select_by_independent_connection(connection);
        auto items    = list_ptr->items();
        std::vector<InterpretationContextSP> intersection;
        for (const auto& ctx : matching_contexts) {
          auto it = std::find_if(items.begin(),
                                 items.end(),
                                 [&](const InterpretationContextSP& other) {
                                   return *ctx == *other;
                                 });
          if (it != items.end()) {
            intersection.push_back(ctx);
          }
        }
        matching_contexts = std::move(intersection);
        // Early exit if no matches
        if (matching_contexts.empty()) {
          return std::make_shared<generic::List<InterpretationContext>>();
        }
      }
    }

    // Process dependent connections
    if (dependent_connections && !dependent_connections->empty()) {
      generic::List<physics::device_structures::Connection> deps =
          *dependent_connections;
      for (auto& connection : deps) {
        auto list_ptr = select_by_dependent_connection(connection);
        auto items    = list_ptr->items();
        std::vector<InterpretationContextSP> intersection;
        for (const auto& ctx : matching_contexts) {
          auto it = std::find_if(items.begin(),
                                 items.end(),
                                 [&](const InterpretationContextSP& other) {
                                   return *ctx == *other;
                                 });
          if (it != items.end()) {
            intersection.push_back(ctx);
          }
        }
        matching_contexts = std::move(intersection);
        // Early exit if no matches
        if (matching_contexts.empty()) {
          return std::make_shared<generic::List<InterpretationContext>>();
        }
      }
    }

    // Convert vector to ListSP
    auto result = std::make_shared<generic::List<InterpretationContext>>(
        matching_contexts);
    return result;
  }
  inline bool operator==(const InterpretationContainer<Value>& other) const {
    if (this->size() != other.size()) return false;
    std::vector<size_t> unmatched_indexes(this->size());
    for (size_t i = 0; i < this->size(); ++i) {
      unmatched_indexes[i] = i;
    }
    auto our_items   = this->items();
    auto other_items = other.items();
    for (size_t i = 0; i < our_items->size(); ++i) {
      const auto& our_pair = our_items->at(i);
      bool        matched  = false;
      for (size_t j = 0; j < other_items->size(); ++j) {
        if (std::find(unmatched_indexes.begin(), unmatched_indexes.end(), j) ==
            unmatched_indexes.end()) {
          continue;
        }
        const auto& other_pair = other_items->at(j);
        if (*our_pair->first() == *other_pair->first()) {
          if (!compare_value(our_pair->second(),
                             other_pair->second(),
                             generic::category::is_shared_ptr<
                                 typename std::remove_reference<
                                     decltype(our_pair->second())>::type>())) {
            return false;
          }
          matched = true;
          unmatched_indexes.erase(
              std::remove(
                  unmatched_indexes.begin(), unmatched_indexes.end(), j),
              unmatched_indexes.end());
          break;
        }
      }
      if (!matched) {
        return false;
      }
    }
    return true;
  }
  inline bool operator!=(const InterpretationContainer<Value>& other) const {
    return !(*this == other);
  }
};
template <typename Value>
using InterpretationContainerSP =
    std::shared_ptr<InterpretationContainer<Value>>;
}  // namespace interpretations
}  // namespace autotuner_interfaces
}  // namespace falcon_core

// -----------------------------------------------------------------------------
// Optional extern template declarations
//
// Define FALCON_CORE_USE_EXTERN_TEMPLATES in consumer builds (tests) that link
// against the compiled falcon_core library which explicitly instantiates the
// same InterpretationContainer<T> specializations. This prevents consumers from
// instantiating the templates again (avoids duplicate-symbol link errors on
// Windows).
// -----------------------------------------------------------------------------

#ifdef FALCON_CORE_USE_EXTERN_TEMPLATES

// forward declarations for concrete project types (used below)
namespace falcon_core {
namespace math {
class Quantity;
}
}  // namespace falcon_core
//
extern template class FALCON_CORE_CPP_API falcon_core::autotuner_interfaces::
    interpretations::InterpretationContainer<double>;
extern template class FALCON_CORE_CPP_API falcon_core::autotuner_interfaces::
    interpretations::InterpretationContainer<std::string>;
extern template class FALCON_CORE_CPP_API falcon_core::autotuner_interfaces::
    interpretations::InterpretationContainer<falcon_core::math::Quantity>;

#endif  // FALCON_CORE_USE_EXTERN_TEMPLATES
