#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/physics/device_structures/SymbolUnit_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon_core/generic/ListAcquisitionContext_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/ListPairInterpretationContextString_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* InterpretationContainerStringHandle;
// Function declarations

InterpretationContainerStringHandle InterpretationContainerString_create(ListInterpretationContextHandle contexts) {
    auto list= std::shared_ptr<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>>(static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>*>(contexts), [](falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>*) {});
    return falcon_core::autotuner_interfaces::containers::InterpretationContainer(list);
}

SymbolUnitHandle InterpretationContainerString_unit(
     InterpretationContainerStringHandle handle) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    return new falcon_core::physics::units::SymbolUnit(this->unit());
}

ListInterpretationContextHandle InterpretationContainerString_select_by_connection(
    InterpretationContainerStringHandle handle, ConnectionHandle connection) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>(*this->select_by_connection(*conn));
}

ListInterpretationContextHandle InterpretationContainerString_select_by_connections(
                    InterpretationContainerStringHandle handle, ConnectionsHandle connections) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto conns = std::shared_ptr<falcon_core::physics::device_structures::Connections>(static_cast<falcon_core::physics::device_structures::Connections*>(connection), [](falcon_core::physics::device_structures::Connections*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>(*this->select_by_connections(*conns));
}

ListInterpretationContextHandle InterpretationContainerString_select_by_independent_connection(
    InterpretationContainerStringHandle handle, ConnectionHandle connection) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>(*this->select_by_independent_connection(*conn));
}

ListInterpretationContextHandle InterpretationContainerString_select_by_dependent_connection(
    InterpretationContainerStringHandle handle, ConnectionHandle connection) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*this->select_by_dependent_connection(*conn));
}

ListInterpretationContextHandle InterpretationContainerString_select_contexts(
    InterpretationContainerStringHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto independents= std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(independent_connections), [](falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*) {} );
    auto dependents= std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(dependent_connections), [](falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*this->select_contexts(independents, dependents));
}

void InterpretationContainerString_insert_or_assign(InterpretationContainerStringHandle handle,
    const InterpretationContextHandle   key,
    const StringHandle value) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto context= shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto value_obj= std::string(value->raw, value->length);
    this->insert_or_assign(context, value_obj);
}

void InterpretationContainerString_insert(
    InterpretationContainerStringHandle handle,
    const InterpretationContextHandle   key,
    const StringHandle value) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto context= shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto value_obj= std::string(value->raw, value->length);
    this->insert_or_assign(context, value_obj);
}

StringHandle InterpretationContainerString_at(InterpretationContainerStringHandle handle,
    const InterpretationContextHandle   key);
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto context= shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto out = this->at(context);
    return String_create(out.data(), out.size());
}

void InterpretationContainerString_erase(InterpretationContainerStringHandle handle,
    const InterpretationContextHandle   key) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto context= shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    return this->erase(context);
}

size_t InterpretationContainerString_size(InterpretationContainerStringHandle handle) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    this->size();
}

bool InterpretationContainerString_empty(InterpretationContainerStringHandle handle) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    this->empty();
}

void InterpretationContainerString_clear(InterpretationContainerStringHandle handle) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    this->clear();
}

bool InterpretationContainerString_contains(InterpretationContainerStringHandle handle,
    const InterpretationContextHandle   key) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto context= shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    return this->contains(context);
}

ListInterpretationContextHandle InterpretationContainerString_keys(
                    InterpretationContainerStringHandle handle) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>(*this->keys());
}

Liststd::stringHandle InterpretationContainerString_values(InterpretationContainerStringHandle handle);
ListPairInterpretationContextstd::stringHandle InterpretationContainerString_items(
                    InterpretationContainerStringHandle handle);
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

// Serialization (from Song)
StringHandle      InterpretationContainerString_to_json_string(InterpretationContainerStringHandle handle);
InterpretationContainerStringHandle InterpretationContainerString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif