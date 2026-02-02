#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContainer.hpp>
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContainerString_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>
#include <falcon_core/physics/device_structures/Connections.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROInterpretationContainerStringHandle= falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>;
DEFINE_C_API_COPY_TEMPLATE(InterpretationContainerString, MACROInterpretationContainerStringHandle)
DEFINE_C_API_DESTROY_TEMPLATE(InterpretationContainerString, MACROInterpretationContainerStringHandle);
DEFINE_C_API_EQUAL_TEMPLATE(InterpretationContainerString, MACROInterpretationContainerStringHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(InterpretationContainerString, MACROInterpretationContainerStringHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(InterpretationContainerString, MACROInterpretationContainerStringHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(InterpretationContainerString, MACROInterpretationContainerStringHandle);
InterpretationContainerStringHandle InterpretationContainerString_create(MapInterpretationContextStringHandle map) {
    FALCON_C_API_BEGIN
if (!map) {
throw std::invalid_argument("Null map handle passed to InterpretationContainerString_create");
}
    auto real_map = *static_cast<falcon_core::generic::MapSP<
        falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>*>(map);
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>(
        std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<std::string>>(real_map));
    FALCON_C_API_END(nullptr)
}

SymbolUnitHandle InterpretationContainerString_unit(
     InterpretationContainerStringHandle handle) {
    FALCON_C_API_BEGIN
     if (!handle) {
     throw std::invalid_argument("Null handle passed to InterpretationContainerString_unit");
     }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    return new falcon_core::physics::units::SymbolUnitSP(that->unit());
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle InterpretationContainerString_select_by_connection(
    InterpretationContainerStringHandle handle, ConnectionHandle connection) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerString_select_by_connection");
    }
    if (!connection) {
    throw std::invalid_argument("Null connection handle passed to InterpretationContainerString_select_by_connection");
    }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    auto conn = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(connection);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_connection(conn));
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle InterpretationContainerString_select_by_connections(
                    InterpretationContainerStringHandle handle, ConnectionsHandle connections) {
    FALCON_C_API_BEGIN
                    if (!handle) {
                    throw std::invalid_argument("Null handle passed to InterpretationContainerString_select_by_connections");
                    }
                    if (!connections) {
                    throw std::invalid_argument("Null connections handle passed to InterpretationContainerString_select_by_connections");
                    }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    auto conns = *static_cast<falcon_core::physics::device_structures::ConnectionsSP*>(connections);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_connections(conns->items()));
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle InterpretationContainerString_select_by_independent_connection(
    InterpretationContainerStringHandle handle, ConnectionHandle connection) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerString_select_by_independent_connection");
    }
    if (!connection) {
    throw std::invalid_argument("Null connection handle passed to InterpretationContainerString_select_by_independent_connection");
    }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    auto conn = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(connection);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_independent_connection(conn));
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle InterpretationContainerString_select_by_dependent_connection(
    InterpretationContainerStringHandle handle, ConnectionHandle connection) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerString_select_by_dependent_connection");
    }
    if (!connection) {
    throw std::invalid_argument("Null connection handle passed to InterpretationContainerString_select_by_dependent_connection");
    }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    auto conn = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(connection);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_dependent_connection(conn));
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle InterpretationContainerString_select_contexts(
    InterpretationContainerStringHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerString_select_contexts");
    }
    if (!independent_connections) {
    throw std::invalid_argument("Null independent connections handle passed to InterpretationContainerString_select_contexts");
    }
    if (!dependent_connections) {
    throw std::invalid_argument("Null dependent connections handle passed to InterpretationContainerString_select_contexts");
    }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    auto independents = *static_cast<falcon_core::generic::ListSP<
        falcon_core::physics::device_structures::Connection>*>(independent_connections);
    auto dependents = *static_cast<falcon_core::generic::ListSP<
        falcon_core::physics::device_structures::Connection>*>(dependent_connections);
    return new falcon_core::generic::ListSP<
        falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(
        that->select_contexts(independents, dependents));
    FALCON_C_API_END(nullptr)
}

void InterpretationContainerString_insert_or_assign(InterpretationContainerStringHandle handle,
     InterpretationContextHandle   key,
     StringHandle value) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerString_insert_or_assign");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerString_insert_or_assign");
    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    auto context= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    
            if (!value) {
            throw std::invalid_argument("Null string handle passed to InterpretationContainerString_create");
                                        }
            auto value_obj= std::string(value->raw, value->length);
    that->insert_or_assign(context, value_obj);
    FALCON_C_API_END()
}

void InterpretationContainerString_insert(
    InterpretationContainerStringHandle handle,
     InterpretationContextHandle   key,
     StringHandle value) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerString_insert");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerString_insert");
    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    auto context= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    
            if (!value) {
            throw std::invalid_argument("Null string handle passed to InterpretationContainerString_create");
                                        }
            auto value_obj= std::string(value->raw, value->length);
    that->insert_or_assign(context, value_obj);
    FALCON_C_API_END()
}

StringHandle InterpretationContainerString_at(InterpretationContainerStringHandle handle,
     InterpretationContextHandle   key) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerString_at");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerString_at");
    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    auto context= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    auto out = that->at(context);
    return String_create(out.data(), out.size());
    FALCON_C_API_END(nullptr)
}

void InterpretationContainerString_erase(InterpretationContainerStringHandle handle,
     InterpretationContextHandle   key) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerString_erase");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerString_erase");
    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    auto context = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    return that->erase(context);
    FALCON_C_API_END()
}

size_t InterpretationContainerString_size(InterpretationContainerStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerString_size");
}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    return that->size();
    FALCON_C_API_END(0)
}

bool InterpretationContainerString_empty(InterpretationContainerStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerString_empty");
}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    return that->empty();
    FALCON_C_API_END(false)
}

void InterpretationContainerString_clear(InterpretationContainerStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerString_clear");
}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    that->clear();
    FALCON_C_API_END()
}

bool InterpretationContainerString_contains(InterpretationContainerStringHandle handle,
     InterpretationContextHandle   key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerString_contains");
}
if (!key) {
throw std::invalid_argument("Null key passed to InterpretationContainerString_contains");
}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    auto context = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    return that->contains(context);
    FALCON_C_API_END(false)
}

ListInterpretationContextHandle InterpretationContainerString_keys(
                    InterpretationContainerStringHandle handle) {
    FALCON_C_API_BEGIN
                    if (!handle) {
                    throw std::invalid_argument("Null handle passed to InterpretationContainerString_keys");
                    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->keys());
    FALCON_C_API_END(nullptr)
}

ListStringHandle InterpretationContainerString_values(InterpretationContainerStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerString_values");
}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    return new falcon_core::generic::ListSP<std::string>(that->values());
    FALCON_C_API_END(nullptr)
}

ListPairInterpretationContextStringHandle InterpretationContainerString_items(
                    InterpretationContainerStringHandle handle) {
    FALCON_C_API_BEGIN
                    if (!handle) {
                    throw std::invalid_argument("Null handle passed to InterpretationContainerString_items");
                    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<std::string>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,std::string>>(that->items());
    FALCON_C_API_END(nullptr)
}
}
