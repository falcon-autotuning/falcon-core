#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContainer.hpp>
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContainerDouble_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>
#include <falcon_core/physics/device_structures/Connections.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>

InterpretationContainerDoubleHandle InterpretationContainerDouble_create(MapInterpretationContextDoubleHandle map) {
if (!map) {
throw std::invalid_argument("Null map handle passed to InterpretationContainerDouble_create");
}
    auto real_map= std::make_shared<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(*static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(map));
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>(real_map);
}

void InterpretationContainerDouble_destroy(InterpretationContainerDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null map handle passed to InterpretationContainerDouble_destroy");
}
    delete static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
}

SymbolUnitHandle InterpretationContainerDouble_unit(
     InterpretationContainerDoubleHandle handle) {
     if (!handle) {
     throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_unit");
     }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    return new falcon_core::physics::units::SymbolUnit(*that->unit());
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_connection(
    InterpretationContainerDoubleHandle handle, ConnectionHandle connection) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_select_by_connection");
    }
    if (!connection) {
    throw std::invalid_argument("Null connection handle passed to InterpretationContainerDouble_select_by_connection");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto conn = std::make_shared<falcon_core::physics::device_structures::Connection>(*static_cast<falcon_core::physics::device_structures::Connection*>(connection));
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_connection(conn));
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_connections(
                    InterpretationContainerDoubleHandle handle, ConnectionsHandle connections) {
                    if (!handle) {
                    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_select_by_connections");
                    }
                    if (!connections) {
                    throw std::invalid_argument("Null connections handle passed to InterpretationContainerDouble_select_by_connections");
                    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto conns = std::make_shared<falcon_core::physics::device_structures::Connections>(*static_cast<falcon_core::physics::device_structures::Connections*>(connections));
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_connections(conns->items()));
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_independent_connection(
    InterpretationContainerDoubleHandle handle, ConnectionHandle connection) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_select_by_independent_connection");
    }
    if (!connection) {
    throw std::invalid_argument("Null connection handle passed to InterpretationContainerDouble_select_by_independent_connection");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto conn = std::make_shared<falcon_core::physics::device_structures::Connection>(*static_cast<falcon_core::physics::device_structures::Connection*>(connection));
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_independent_connection(conn));
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_dependent_connection(
    InterpretationContainerDoubleHandle handle, ConnectionHandle connection) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_select_by_dependent_connection");
    }
    if (!connection) {
    throw std::invalid_argument("Null connection handle passed to InterpretationContainerDouble_select_by_dependent_connection");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto conn = std::make_shared<falcon_core::physics::device_structures::Connection>(*static_cast<falcon_core::physics::device_structures::Connection*>(connection));
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_dependent_connection(conn));
}

ListInterpretationContextHandle InterpretationContainerDouble_select_contexts(
    InterpretationContainerDoubleHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_select_contexts");
    }
    if (!independent_connections) {
    throw std::invalid_argument("Null independent connections handle passed to InterpretationContainerDouble_select_contexts");
    }
    if (!dependent_connections) {
    throw std::invalid_argument("Null dependent connections handle passed to InterpretationContainerDouble_select_contexts");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
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

void InterpretationContainerDouble_insert_or_assign(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key,
    const double value) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_insert_or_assign");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerDouble_insert_or_assign");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto context= std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key)); 
    auto value_obj= value;
    that->insert_or_assign(context, value_obj);
}

void InterpretationContainerDouble_insert(
    InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key,
    const double value) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_insert");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerDouble_insert");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto context= std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key)); 
    auto value_obj= value;
    that->insert_or_assign(context, value_obj);
}

double InterpretationContainerDouble_at(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_at");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerDouble_at");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto context= std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key)); 
    auto out = that->at(context);
    return out;
}

void InterpretationContainerDouble_erase(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_erase");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerDouble_erase");
    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto context= std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key)); 
    return that->erase(context);
}

size_t InterpretationContainerDouble_size(InterpretationContainerDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_size");
}
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    return that->size();
}

bool InterpretationContainerDouble_empty(InterpretationContainerDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_empty");
}
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    return that->empty();
}

void InterpretationContainerDouble_clear(InterpretationContainerDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_clear");
}
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    that->clear();
}

bool InterpretationContainerDouble_contains(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_contains");
}
if (!key) {
throw std::invalid_argument("Null key passed to InterpretationContainerDouble_contains");
}
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto context= std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key)); 
    return that->contains(context);
}

ListInterpretationContextHandle InterpretationContainerDouble_keys(
                    InterpretationContainerDoubleHandle handle) {
                    if (!handle) {
                    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_keys");
                    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->keys());
}

ListDoubleHandle InterpretationContainerDouble_values(InterpretationContainerDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_values");
}
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    return new falcon_core::generic::List<double>(*that->values());
}

ListPairInterpretationContextDoubleHandle InterpretationContainerDouble_items(
                    InterpretationContainerDoubleHandle handle) {
                    if (!handle) {
                    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_items");
                    }
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>> items_sp = that->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>>(items_sp);
}

bool InterpretationContainerDouble_equal(InterpretationContainerDoubleHandle a, InterpretationContainerDoubleHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_equal");
}
    auto listA = static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(a);
    auto listB = static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(b);
    return *listA == *listB;
}

bool InterpretationContainerDouble_not_equal(InterpretationContainerDoubleHandle a, InterpretationContainerDoubleHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_not_equal");
}
    return !InterpretationContainerDouble_equal(a, b);
}

StringHandle      InterpretationContainerDouble_to_json_string(InterpretationContainerDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_to_json_string");
}
std::string json = static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
InterpretationContainerDoubleHandle InterpretationContainerDouble_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to InterpretationContainerDouble_from_json_string");
}
  auto ptr = falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>::from_json_string<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>>(json->raw);
  return new falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>(*ptr);
}
