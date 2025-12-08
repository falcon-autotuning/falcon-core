#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContainer.hpp>
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContainerDouble_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>
#include <falcon_core/physics/device_structures/Connections.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
InterpretationContainerDoubleHandle InterpretationContainerDouble_create(MapInterpretationContextDoubleHandle map) {
    FALCON_C_API_BEGIN
if (!map) {
throw std::invalid_argument("Null map handle passed to InterpretationContainerDouble_create");
}
    auto real_map = *static_cast<falcon_core::generic::MapSP<
        falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(map);
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>(
        std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>>(real_map));
    FALCON_C_API_END(nullptr)
}

void InterpretationContainerDouble_destroy(InterpretationContainerDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null map handle passed to InterpretationContainerDouble_destroy");
}
    delete static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    FALCON_C_API_END()
}

SymbolUnitHandle InterpretationContainerDouble_unit(
     InterpretationContainerDoubleHandle handle) {
    FALCON_C_API_BEGIN
     if (!handle) {
     throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_unit");
     }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    return new falcon_core::physics::units::SymbolUnitSP(that->unit());
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_connection(
    InterpretationContainerDoubleHandle handle, ConnectionHandle connection) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_select_by_connection");
    }
    if (!connection) {
    throw std::invalid_argument("Null connection handle passed to InterpretationContainerDouble_select_by_connection");
    }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    auto conn = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(connection);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_connection(conn));
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_connections(
                    InterpretationContainerDoubleHandle handle, ConnectionsHandle connections) {
    FALCON_C_API_BEGIN
                    if (!handle) {
                    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_select_by_connections");
                    }
                    if (!connections) {
                    throw std::invalid_argument("Null connections handle passed to InterpretationContainerDouble_select_by_connections");
                    }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    auto conns = *static_cast<falcon_core::physics::device_structures::ConnectionsSP*>(connections);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_connections(conns->items()));
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_independent_connection(
    InterpretationContainerDoubleHandle handle, ConnectionHandle connection) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_select_by_independent_connection");
    }
    if (!connection) {
    throw std::invalid_argument("Null connection handle passed to InterpretationContainerDouble_select_by_independent_connection");
    }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    auto conn = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(connection);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_independent_connection(conn));
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_dependent_connection(
    InterpretationContainerDoubleHandle handle, ConnectionHandle connection) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_select_by_dependent_connection");
    }
    if (!connection) {
    throw std::invalid_argument("Null connection handle passed to InterpretationContainerDouble_select_by_dependent_connection");
    }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    auto conn = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(connection);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_dependent_connection(conn));
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle InterpretationContainerDouble_select_contexts(
    InterpretationContainerDoubleHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_select_contexts");
    }
    if (!independent_connections) {
    throw std::invalid_argument("Null independent connections handle passed to InterpretationContainerDouble_select_contexts");
    }
    if (!dependent_connections) {
    throw std::invalid_argument("Null dependent connections handle passed to InterpretationContainerDouble_select_contexts");
    }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    auto independents = *static_cast<falcon_core::generic::ListSP<
        falcon_core::physics::device_structures::Connection>*>(independent_connections);
    auto dependents = *static_cast<falcon_core::generic::ListSP<
        falcon_core::physics::device_structures::Connection>*>(dependent_connections);
    return new falcon_core::generic::ListSP<
        falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(
        that->select_contexts(independents, dependents));
    FALCON_C_API_END(nullptr)
}

void InterpretationContainerDouble_insert_or_assign(InterpretationContainerDoubleHandle handle,
     InterpretationContextHandle   key,
     double value) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_insert_or_assign");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerDouble_insert_or_assign");
    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    auto context= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    auto value_obj= value;
    that->insert_or_assign(context, value_obj);
    FALCON_C_API_END()
}

void InterpretationContainerDouble_insert(
    InterpretationContainerDoubleHandle handle,
     InterpretationContextHandle   key,
     double value) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_insert");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerDouble_insert");
    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    auto context= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    auto value_obj= value;
    that->insert_or_assign(context, value_obj);
    FALCON_C_API_END()
}

double InterpretationContainerDouble_at(InterpretationContainerDoubleHandle handle,
     InterpretationContextHandle   key) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_at");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerDouble_at");
    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    auto context= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    auto out = that->at(context);
    return out;
    FALCON_C_API_END(0.0)
}

void InterpretationContainerDouble_erase(InterpretationContainerDoubleHandle handle,
     InterpretationContextHandle   key) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_erase");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerDouble_erase");
    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    auto context = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    return that->erase(context);
    FALCON_C_API_END()
}

size_t InterpretationContainerDouble_size(InterpretationContainerDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_size");
}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    return that->size();
    FALCON_C_API_END(0)
}

bool InterpretationContainerDouble_empty(InterpretationContainerDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_empty");
}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    return that->empty();
    FALCON_C_API_END(false)
}

void InterpretationContainerDouble_clear(InterpretationContainerDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_clear");
}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    that->clear();
    FALCON_C_API_END()
}

bool InterpretationContainerDouble_contains(InterpretationContainerDoubleHandle handle,
     InterpretationContextHandle   key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_contains");
}
if (!key) {
throw std::invalid_argument("Null key passed to InterpretationContainerDouble_contains");
}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    auto context = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    return that->contains(context);
    FALCON_C_API_END(false)
}

ListInterpretationContextHandle InterpretationContainerDouble_keys(
                    InterpretationContainerDoubleHandle handle) {
    FALCON_C_API_BEGIN
                    if (!handle) {
                    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_keys");
                    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->keys());
    FALCON_C_API_END(nullptr)
}

ListDoubleHandle InterpretationContainerDouble_values(InterpretationContainerDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_values");
}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    return new falcon_core::generic::ListSP<double>(that->values());
    FALCON_C_API_END(nullptr)
}

ListPairInterpretationContextDoubleHandle InterpretationContainerDouble_items(
                    InterpretationContainerDoubleHandle handle) {
    FALCON_C_API_BEGIN
                    if (!handle) {
                    throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_items");
                    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>>(that->items());
    FALCON_C_API_END(nullptr)
}

bool InterpretationContainerDouble_equal(InterpretationContainerDoubleHandle handle, InterpretationContainerDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_equal");
}
    auto listA = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    auto listB = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool InterpretationContainerDouble_not_equal(InterpretationContainerDoubleHandle handle, InterpretationContainerDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_not_equal");
}
    auto listA = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle);
    auto listB = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

StringHandle      InterpretationContainerDouble_to_json_string(InterpretationContainerDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerDouble_to_json_string");
}
std::string json = (*static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

InterpretationContainerDoubleHandle InterpretationContainerDouble_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to InterpretationContainerDouble_from_json_string");
}
  auto ptr = falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>::from_json_string<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>>(json->raw);
  return new falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<double>(ptr);
    FALCON_C_API_END(nullptr)
}
}
