#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/physics/device_structures/SymbolUnit_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon_core/generic/ListAcquisitionContext_c_api.h"
#include "falcon_core/generic/ListQuantity_c_api.h"
#include "falcon_core/generic/ListPairInterpretationContextQuantity_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* InterpretationContainerQuantityHandle;
// Function declarations

InterpretationContainerQuantityHandle InterpretationContainerQuantity_create(ListInterpretationContextHandle contexts) {
    auto list= std::shared_ptr<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>>(static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>*>(contexts), [](falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>*) {});
    return falcon_core::autotuner_interfaces::containers::InterpretationContainer(list);
}

SymbolUnitHandle InterpretationContainerQuantity_unit(
     InterpretationContainerQuantityHandle handle) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    return new falcon_core::physics::units::SymbolUnit(this->unit());
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connection(
    InterpretationContainerQuantityHandle handle, ConnectionHandle connection) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>(*this->select_by_connection(*conn));
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connections(
                    InterpretationContainerQuantityHandle handle, ConnectionsHandle connections) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto conns = std::shared_ptr<falcon_core::physics::device_structures::Connections>(static_cast<falcon_core::physics::device_structures::Connections*>(connection), [](falcon_core::physics::device_structures::Connections*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>(*this->select_by_connections(*conns));
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_independent_connection(
    InterpretationContainerQuantityHandle handle, ConnectionHandle connection) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>(*this->select_by_independent_connection(*conn));
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_dependent_connection(
    InterpretationContainerQuantityHandle handle, ConnectionHandle connection) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*this->select_by_dependent_connection(*conn));
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_contexts(
    InterpretationContainerQuantityHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto independents= std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(independent_connections), [](falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*) {} );
    auto dependents= std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(dependent_connections), [](falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*this->select_contexts(independents, dependents));
}

void InterpretationContainerQuantity_insert_or_assign(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key,
    const QuantityHandle value) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto context= shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto temp_value = *static_cast<falcon_core::math::Quantity*>(value);
auto value_obj= std::make_shared<falcon_core::math::Quantity>(temp_value);
    this->insert_or_assign(context, value_obj);
}

void InterpretationContainerQuantity_insert(
    InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key,
    const QuantityHandle value) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto context= shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto temp_value = *static_cast<falcon_core::math::Quantity*>(value);
auto value_obj= std::make_shared<falcon_core::math::Quantity>(temp_value);
    this->insert_or_assign(context, value_obj);
}

QuantityHandle InterpretationContainerQuantity_at(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key);
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto context= shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto out = this->at(context);
    return new falcon_core::math::Quantity(out);
}

void InterpretationContainerQuantity_erase(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto context= shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    return this->erase(context);
}

size_t InterpretationContainerQuantity_size(InterpretationContainerQuantityHandle handle) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    this->size();
}

bool InterpretationContainerQuantity_empty(InterpretationContainerQuantityHandle handle) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    this->empty();
}

void InterpretationContainerQuantity_clear(InterpretationContainerQuantityHandle handle) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    this->clear();
}

bool InterpretationContainerQuantity_contains(InterpretationContainerQuantityHandle handle,
    const InterpretationContextHandle   key) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto context= shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    return this->contains(context);
}

ListInterpretationContextHandle InterpretationContainerQuantity_keys(
                    InterpretationContainerQuantityHandle handle) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>(*this->keys());
}

Listfalcon_core::math::QuantitySPHandle InterpretationContainerQuantity_values(InterpretationContainerQuantityHandle handle);
ListPairInterpretationContextfalcon_core::math::QuantitySPHandle InterpretationContainerQuantity_items(
                    InterpretationContainerQuantityHandle handle);
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

// Serialization (from Song)
StringHandle      InterpretationContainerQuantity_to_json_string(InterpretationContainerQuantityHandle handle);
InterpretationContainerQuantityHandle InterpretationContainerQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif