#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContainer.hpp>
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContainerDouble_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>
#include <falcon_core/physics/device_structures/Connections.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>

InterpretationContainerDoubleHandle InterpretationContainerDouble_create(MapInterpretationContextDoubleHandle map) {
    auto real_map= std::shared_ptr<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>>(static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(map), [](falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*) {});
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>(real_map);
}

SymbolUnitHandle InterpretationContainerDouble_unit(
     InterpretationContainerDoubleHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    return new falcon_core::physics::units::SymbolUnit(*that->unit());
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_connection(
    InterpretationContainerDoubleHandle handle, ConnectionHandle connection) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_connection(conn));
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_connections(
                    InterpretationContainerDoubleHandle handle, ConnectionsHandle connections) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto conns = std::shared_ptr<falcon_core::physics::device_structures::Connections>(static_cast<falcon_core::physics::device_structures::Connections*>(connections), [](falcon_core::physics::device_structures::Connections*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_connections(conns->items()));
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_independent_connection(
    InterpretationContainerDoubleHandle handle, ConnectionHandle connection) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_independent_connection(conn));
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_dependent_connection(
    InterpretationContainerDoubleHandle handle, ConnectionHandle connection) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_dependent_connection(conn));
}

ListInterpretationContextHandle InterpretationContainerDouble_select_contexts(
    InterpretationContainerDoubleHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto independents= std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>>(static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(independent_connections), [](falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*) {} );
    auto dependents= std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>>(static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(dependent_connections), [](falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_contexts(independents, dependents));
}

void InterpretationContainerDouble_insert_or_assign(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key,
    const double value) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto context= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto value_obj= value;
    that->insert_or_assign(context, value_obj);
}

void InterpretationContainerDouble_insert(
    InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key,
    const double value) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto context= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto value_obj= value;
    that->insert_or_assign(context, value_obj);
}

double InterpretationContainerDouble_at(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto context= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto out = that->at(context);
    return out;
}

void InterpretationContainerDouble_erase(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto context= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    return that->erase(context);
}

size_t InterpretationContainerDouble_size(InterpretationContainerDoubleHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    return that->size();
}

bool InterpretationContainerDouble_empty(InterpretationContainerDoubleHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    return that->empty();
}

void InterpretationContainerDouble_clear(InterpretationContainerDoubleHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    that->clear();
}

bool InterpretationContainerDouble_contains(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    auto context= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    return that->contains(context);
}

ListInterpretationContextHandle InterpretationContainerDouble_keys(
                    InterpretationContainerDoubleHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->keys());
}

ListDoubleHandle InterpretationContainerDouble_values(InterpretationContainerDoubleHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    return new falcon_core::generic::List<double>(*that->values());
}

ListPairInterpretationContextDoubleHandle InterpretationContainerDouble_items(
                    InterpretationContainerDoubleHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>> items_sp = that->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>>(items_sp);
}

bool InterpretationContainerDouble_equal(InterpretationContainerDoubleHandle a, InterpretationContainerDoubleHandle b) {
    auto listA = static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(a);
    auto listB = static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(b);
    return *listA == *listB;
}

bool InterpretationContainerDouble_not_equal(InterpretationContainerDoubleHandle a, InterpretationContainerDoubleHandle b) {
    return !InterpretationContainerDouble_equal(a, b);
}

StringHandle      InterpretationContainerDouble_to_json_string(InterpretationContainerDoubleHandle handle) {
std::string json = static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
InterpretationContainerDoubleHandle InterpretationContainerDouble_from_json_string(StringHandle json) {
  auto ptr = falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>::from_json_string<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>>(json->raw);
  return new falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<double>(*ptr);
}
