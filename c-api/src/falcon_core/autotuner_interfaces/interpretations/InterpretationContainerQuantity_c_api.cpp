#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContainer.hpp>
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContainerQuantity_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>
#include <falcon_core/physics/device_structures/Connections.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include <falcon_core/math/Quantity.hpp>

InterpretationContainerQuantityHandle InterpretationContainerQuantity_create(MapInterpretationContextQuantityHandle map) {
if (!map) {
throw std::invalid_argument("Null map handle passed to InterpretationContainerQuantity_create");
}
    auto real_map= std::make_shared<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(*static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(map));
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>(real_map);
}

void InterpretationContainerQuantity_destroy(InterpretationContainerQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null map handle passed to InterpretationContainerQuantity_destroy");
}
    delete static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
}

SymbolUnitHandle InterpretationContainerQuantity_unit(
     InterpretationContainerQuantityHandle handle) {
     if (!handle) {
     throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_unit");
     }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    return new falcon_core::physics::units::SymbolUnit(*that->unit());
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connection(
    InterpretationContainerQuantityHandle handle, ConnectionHandle connection) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_select_by_connection");
    }
    if (!connection) {
    throw std::invalid_argument("Null connection handle passed to InterpretationContainerQuantity_select_by_connection");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto conn = std::make_shared<falcon_core::physics::device_structures::Connection>(*static_cast<falcon_core::physics::device_structures::Connection*>(connection));
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_connection(conn));
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connections(
                    InterpretationContainerQuantityHandle handle, ConnectionsHandle connections) {
                    if (!handle) {
                    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_select_by_connections");
                    }
                    if (!connections) {
                    throw std::invalid_argument("Null connections handle passed to InterpretationContainerQuantity_select_by_connections");
                    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto conns = std::make_shared<falcon_core::physics::device_structures::Connections>(*static_cast<falcon_core::physics::device_structures::Connections*>(connections));
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_connections(conns->items()));
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_independent_connection(
    InterpretationContainerQuantityHandle handle, ConnectionHandle connection) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_select_by_independent_connection");
    }
    if (!connection) {
    throw std::invalid_argument("Null connection handle passed to InterpretationContainerQuantity_select_by_independent_connection");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto conn = std::make_shared<falcon_core::physics::device_structures::Connection>(*static_cast<falcon_core::physics::device_structures::Connection*>(connection));
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_independent_connection(conn));
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_dependent_connection(
    InterpretationContainerQuantityHandle handle, ConnectionHandle connection) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_select_by_dependent_connection");
    }
    if (!connection) {
    throw std::invalid_argument("Null connection handle passed to InterpretationContainerQuantity_select_by_dependent_connection");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto conn = std::make_shared<falcon_core::physics::device_structures::Connection>(*static_cast<falcon_core::physics::device_structures::Connection*>(connection));
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_dependent_connection(conn));
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_contexts(
    InterpretationContainerQuantityHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_select_contexts");
    }
    if (!independent_connections) {
    throw std::invalid_argument("Null independent connections handle passed to InterpretationContainerQuantity_select_contexts");
    }
    if (!dependent_connections) {
    throw std::invalid_argument("Null dependent connections handle passed to InterpretationContainerQuantity_select_contexts");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
  auto independents = std::make_shared<falcon_core::generic::List<
      falcon_core::physics::device_structures::Connection>>(
      *static_cast<falcon_core::generic::List<
          falcon_core::physics::device_structures::Connection>*>(
          independent_connections));
  auto dependents = std::make_shared<falcon_core::generic::List<
      falcon_core::physics::device_structures::Connection>>(
      *static_cast<falcon_core::generic::List<
          falcon_core::physics::device_structures::Connection>*>(
          dependent_connections));
  return new falcon_core::generic::List<
      falcon_core::autotuner_interfaces::interpretations::
          InterpretationContext>(
      that->select_contexts(independents, dependents)->items());
}

void InterpretationContainerQuantity_insert_or_assign(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key,
    const QuantityHandle value) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_insert_or_assign");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerQuantity_insert_or_assign");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto context= std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key)); 
    
            if (!value) {
            throw std::invalid_argument("Null value passed to InterpretationContainerQuantity_create");
            }
            auto temp_value = *static_cast<falcon_core::math::Quantity*>(value);
auto value_obj= std::make_shared<falcon_core::math::Quantity>(temp_value);
    that->insert_or_assign(context, value_obj);
}

void InterpretationContainerQuantity_insert(
    InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key,
    const QuantityHandle value) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_insert");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerQuantity_insert");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto context= std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key)); 
    
            if (!value) {
            throw std::invalid_argument("Null value passed to InterpretationContainerQuantity_create");
            }
            auto temp_value = *static_cast<falcon_core::math::Quantity*>(value);
auto value_obj= std::make_shared<falcon_core::math::Quantity>(temp_value);
    that->insert_or_assign(context, value_obj);
}

QuantityHandle InterpretationContainerQuantity_at(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_at");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerQuantity_at");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto context= std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key)); 
    auto out = that->at(context);
    return new falcon_core::math::Quantity(*out);
}

void InterpretationContainerQuantity_erase(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_erase");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerQuantity_erase");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto context= std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key)); 
    return that->erase(context);
}

size_t InterpretationContainerQuantity_size(InterpretationContainerQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_size");
}
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    return that->size();
}

bool InterpretationContainerQuantity_empty(InterpretationContainerQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_empty");
}
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    return that->empty();
}

void InterpretationContainerQuantity_clear(InterpretationContainerQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_clear");
}
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    that->clear();
}

bool InterpretationContainerQuantity_contains(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_contains");
}
if (!key) {
throw std::invalid_argument("Null key passed to InterpretationContainerQuantity_contains");
}
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto context= std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key)); 
    return that->contains(context);
}

ListInterpretationContextHandle InterpretationContainerQuantity_keys(
                    InterpretationContainerQuantityHandle handle) {
                    if (!handle) {
                    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_keys");
                    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->keys());
}

ListQuantityHandle InterpretationContainerQuantity_values(InterpretationContainerQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_values");
}
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    return new falcon_core::generic::List<falcon_core::math::Quantity>(*that->values());
}

ListPairInterpretationContextQuantityHandle InterpretationContainerQuantity_items(
                    InterpretationContainerQuantityHandle handle) {
                    if (!handle) {
                    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_items");
                    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>> items_sp = that->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>>(items_sp);
}

bool InterpretationContainerQuantity_equal(InterpretationContainerQuantityHandle a, InterpretationContainerQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_equal");
}
    auto listA = static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(a);
    auto listB = static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(b);
    return *listA == *listB;
}

bool InterpretationContainerQuantity_not_equal(InterpretationContainerQuantityHandle a, InterpretationContainerQuantityHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_not_equal");
}
    return !InterpretationContainerQuantity_equal(a, b);
}

StringHandle      InterpretationContainerQuantity_to_json_string(InterpretationContainerQuantityHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_to_json_string");
}
std::string json = static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
InterpretationContainerQuantityHandle InterpretationContainerQuantity_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to InterpretationContainerQuantity_from_json_string");
}
  auto ptr = falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>::from_json_string<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>>(json->raw);
  return new falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>(*ptr);
}
