#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContainer.hpp>
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContainerString_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>
#include <falcon_core/physics/device_structures/Connections.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>

InterpretationContainerStringHandle InterpretationContainerString_create(MapInterpretationContextStringHandle map) {
    auto real_map= std::shared_ptr<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>>(static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(map), [](falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*) {});
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>(real_map);
}

SymbolUnitHandle InterpretationContainerString_unit(
     InterpretationContainerStringHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    return new falcon_core::physics::units::SymbolUnit(*that->unit());
}

ListInterpretationContextHandle InterpretationContainerString_select_by_connection(
    InterpretationContainerStringHandle handle, ConnectionHandle connection) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_connection(conn));
}

ListInterpretationContextHandle InterpretationContainerString_select_by_connections(
                    InterpretationContainerStringHandle handle, ConnectionsHandle connections) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    auto conns = std::shared_ptr<falcon_core::physics::device_structures::Connections>(static_cast<falcon_core::physics::device_structures::Connections*>(connections), [](falcon_core::physics::device_structures::Connections*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_connections(conns->items()));
}

ListInterpretationContextHandle InterpretationContainerString_select_by_independent_connection(
    InterpretationContainerStringHandle handle, ConnectionHandle connection) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_independent_connection(conn));
}

ListInterpretationContextHandle InterpretationContainerString_select_by_dependent_connection(
    InterpretationContainerStringHandle handle, ConnectionHandle connection) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_dependent_connection(conn));
}

ListInterpretationContextHandle InterpretationContainerString_select_contexts(
    InterpretationContainerStringHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    auto independents= std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>>(static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(independent_connections), [](falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*) {} );
    auto dependents= std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>>(static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(dependent_connections), [](falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_contexts(independents, dependents));
}

void InterpretationContainerString_insert_or_assign(InterpretationContainerStringHandle handle,
    const InterpretationContextHandle   key,
    const StringHandle value) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    auto context= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto value_obj= std::string(value->raw, value->length);
    that->insert_or_assign(context, value_obj);
}

void InterpretationContainerString_insert(
    InterpretationContainerStringHandle handle,
    const InterpretationContextHandle   key,
    const StringHandle value) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    auto context= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto value_obj= std::string(value->raw, value->length);
    that->insert_or_assign(context, value_obj);
}

StringHandle InterpretationContainerString_at(InterpretationContainerStringHandle handle,
    const InterpretationContextHandle   key) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    auto context= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto out = that->at(context);
    return String_create(out.data(), out.size());
}

void InterpretationContainerString_erase(InterpretationContainerStringHandle handle,
    const InterpretationContextHandle   key) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    auto context= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    return that->erase(context);
}

size_t InterpretationContainerString_size(InterpretationContainerStringHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    return that->size();
}

bool InterpretationContainerString_empty(InterpretationContainerStringHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    return that->empty();
}

void InterpretationContainerString_clear(InterpretationContainerStringHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    that->clear();
}

bool InterpretationContainerString_contains(InterpretationContainerStringHandle handle,
    const InterpretationContextHandle   key) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    auto context= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    return that->contains(context);
}

ListInterpretationContextHandle InterpretationContainerString_keys(
                    InterpretationContainerStringHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->keys());
}

ListStringHandle InterpretationContainerString_values(InterpretationContainerStringHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    return new falcon_core::generic::List<std::string>(*that->values());
}

ListPairInterpretationContextStringHandle InterpretationContainerString_items(
                    InterpretationContainerStringHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>> items_sp = that->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>>(items_sp);
}

bool InterpretationContainerString_equal(InterpretationContainerStringHandle a, InterpretationContainerStringHandle b) {
    auto listA = static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(a);
    auto listB = static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(b);
    return *listA == *listB;
}

bool InterpretationContainerString_not_equal(InterpretationContainerStringHandle a, InterpretationContainerStringHandle b) {
    return !InterpretationContainerString_equal(a, b);
}

StringHandle      InterpretationContainerString_to_json_string(InterpretationContainerStringHandle handle) {
std::string json = static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
InterpretationContainerStringHandle InterpretationContainerString_from_json_string(StringHandle json) {
  auto ptr = falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>::from_json_string<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>>(json->raw);
  return new falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>(*ptr);
}
