#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContainer.hpp>
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContainerQuantity_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>
#include <falcon_core/physics/device_structures/Connections.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include <falcon_core/math/Quantity.hpp>

InterpretationContainerQuantityHandle InterpretationContainerQuantity_create(MapInterpretationContextQuantityHandle map) {
    auto real_map= std::shared_ptr<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(map), [](falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*) {});
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>(real_map);
}

SymbolUnitHandle InterpretationContainerQuantity_unit(
     InterpretationContainerQuantityHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    return new falcon_core::physics::units::SymbolUnit(*that->unit());
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connection(
    InterpretationContainerQuantityHandle handle, ConnectionHandle connection) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_connection(conn));
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connections(
                    InterpretationContainerQuantityHandle handle, ConnectionsHandle connections) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto conns = std::shared_ptr<falcon_core::physics::device_structures::Connections>(static_cast<falcon_core::physics::device_structures::Connections*>(connections), [](falcon_core::physics::device_structures::Connections*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_connections(conns->items()));
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_independent_connection(
    InterpretationContainerQuantityHandle handle, ConnectionHandle connection) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_independent_connection(conn));
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_dependent_connection(
    InterpretationContainerQuantityHandle handle, ConnectionHandle connection) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_by_dependent_connection(conn));
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_contexts(
    InterpretationContainerQuantityHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto independents= std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>>(static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(independent_connections), [](falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*) {} );
    auto dependents= std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>>(static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(dependent_connections), [](falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->select_contexts(independents, dependents));
}

void InterpretationContainerQuantity_insert_or_assign(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key,
    const QuantityHandle value) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto context= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto temp_value = *static_cast<falcon_core::math::Quantity*>(value);
auto value_obj= std::make_shared<falcon_core::math::Quantity>(temp_value);
    that->insert_or_assign(context, value_obj);
}

void InterpretationContainerQuantity_insert(
    InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key,
    const QuantityHandle value) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto context= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto temp_value = *static_cast<falcon_core::math::Quantity*>(value);
auto value_obj= std::make_shared<falcon_core::math::Quantity>(temp_value);
    that->insert_or_assign(context, value_obj);
}

QuantityHandle InterpretationContainerQuantity_at(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto context= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto out = that->at(context);
    return new falcon_core::math::Quantity(*out);
}

void InterpretationContainerQuantity_erase(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto context= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    return that->erase(context);
}

size_t InterpretationContainerQuantity_size(InterpretationContainerQuantityHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    return that->size();
}

bool InterpretationContainerQuantity_empty(InterpretationContainerQuantityHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    return that->empty();
}

void InterpretationContainerQuantity_clear(InterpretationContainerQuantityHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    that->clear();
}

bool InterpretationContainerQuantity_contains(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    auto context= std::shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContext*>(key), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    return that->contains(context);
}

ListInterpretationContextHandle InterpretationContainerQuantity_keys(
                    InterpretationContainerQuantityHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*that->keys());
}

ListQuantityHandle InterpretationContainerQuantity_values(InterpretationContainerQuantityHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    return new falcon_core::generic::List<falcon_core::math::Quantity>(*that->values());
}

ListPairInterpretationContextQuantityHandle InterpretationContainerQuantity_items(
                    InterpretationContainerQuantityHandle handle) {
    auto that= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>> items_sp = that->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>>(items_sp);
}

bool InterpretationContainerQuantity_equal(InterpretationContainerQuantityHandle a, InterpretationContainerQuantityHandle b) {
    auto listA = static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(a);
    auto listB = static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(b);
    return *listA == *listB;
}

bool InterpretationContainerQuantity_not_equal(InterpretationContainerQuantityHandle a, InterpretationContainerQuantityHandle b) {
    return !InterpretationContainerQuantity_equal(a, b);
}

StringHandle      InterpretationContainerQuantity_to_json_string(InterpretationContainerQuantityHandle handle) {
std::string json = static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
InterpretationContainerQuantityHandle InterpretationContainerQuantity_from_json_string(StringHandle json) {
  auto ptr = falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>::from_json_string<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>>(json->raw);
  return new falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>(*ptr);
}
