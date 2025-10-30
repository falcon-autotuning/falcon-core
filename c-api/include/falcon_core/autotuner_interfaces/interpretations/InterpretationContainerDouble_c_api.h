#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/physics/device_structures/SymbolUnit_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon_core/generic/ListAcquisitionContext_c_api.h"
#include "falcon_core/generic/ListDouble_c_api.h"
#include "falcon_core/generic/ListPairInterpretationContextDouble_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* InterpretationContainerDoubleHandle;
// Function declarations

InterpretationContainerDoubleHandle InterpretationContainerDouble_create(ListInterpretationContextHandle contexts) {
    auto list= std::shared_ptr<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>>(static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>*>(contexts), [](falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>*) {});
    return falcon_core::autotuner_interfaces::containers::InterpretationContainer(list);
}

SymbolUnitHandle InterpretationContainerDouble_unit(
     InterpretationContainerDoubleHandle handle) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    return new falcon_core::physics::units::SymbolUnit(this->unit());
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_connection(
    InterpretationContainerDoubleHandle handle, ConnectionHandle connection) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>(*this->select_by_connection(*conn));
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_connections(
                    InterpretationContainerDoubleHandle handle, ConnectionsHandle connections) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto conns = std::shared_ptr<falcon_core::physics::device_structures::Connections>(static_cast<falcon_core::physics::device_structures::Connections*>(connection), [](falcon_core::physics::device_structures::Connections*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>(*this->select_by_connections(*conns));
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_independent_connection(
    InterpretationContainerDoubleHandle handle, ConnectionHandle connection) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>(*this->select_by_independent_connection(*conn));
}

ListInterpretationContextHandle InterpretationContainerDouble_select_by_dependent_connection(
    InterpretationContainerDoubleHandle handle, ConnectionHandle connection) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto conn = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(connection), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*this->select_by_dependent_connection(*conn));
}

ListInterpretationContextHandle InterpretationContainerDouble_select_contexts(
    InterpretationContainerDoubleHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto independents= std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(independent_connections), [](falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*) {} );
    auto dependents= std::shared_ptr<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(dependent_connections), [](falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(*this->select_contexts(independents, dependents));
}

void InterpretationContainerDouble_insert_or_assign(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key,
    const double value) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto context= shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto value_obj= value;
    this->insert_or_assign(context, value_obj);
}

void InterpretationContainerDouble_insert(
    InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key,
    const double value) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto context= shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto value_obj= value;
    this->insert_or_assign(context, value_obj);
}

double InterpretationContainerDouble_at(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key);
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto context= shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    auto out = this->at(context);
    return out;
}

void InterpretationContainerDouble_erase(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto context= shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    return this->erase(context);
}

size_t InterpretationContainerDouble_size(InterpretationContainerDoubleHandle handle) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    this->size();
}

bool InterpretationContainerDouble_empty(InterpretationContainerDoubleHandle handle) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    this->empty();
}

void InterpretationContainerDouble_clear(InterpretationContainerDoubleHandle handle) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    this->clear();
}

bool InterpretationContainerDouble_contains(InterpretationContainerDoubleHandle handle,
    const InterpretationContextHandle   key) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    auto context= shared_ptr<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle), [](falcon_core::autotuner_interfaces::interpretations::InterpretationContext*) {} );
    return this->contains(context);
}

ListInterpretationContextHandle InterpretationContainerDouble_keys(
                    InterpretationContainerDoubleHandle handle) {
    auto this= static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer*>(handle);
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::InterpretationContext>(*this->keys());
}

ListdoubleHandle InterpretationContainerDouble_values(InterpretationContainerDoubleHandle handle);
ListPairInterpretationContextdoubleHandle InterpretationContainerDouble_items(
                    InterpretationContainerDoubleHandle handle);
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

// Serialization (from Song)
StringHandle      InterpretationContainerDouble_to_json_string(InterpretationContainerDoubleHandle handle);
InterpretationContainerDoubleHandle InterpretationContainerDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif