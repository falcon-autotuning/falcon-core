#include <falcon_core\autotuner_interfaces\interpretations/InterpretationContainer.hpp>
#include "falcon_core\autotuner_interfaces\interpretations\InterpretationContainerQuantity_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>
#include <falcon_core/physics/device_structures/Connections.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include <falcon_core/math/Quantity.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROInterpretationContainerQuantityHandle= falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>;
DEFINE_C_API_COPY_TEMPLATE(InterpretationContainerQuantity, MACROInterpretationContainerQuantityHandle)
DEFINE_C_API_DESTROY_TEMPLATE(InterpretationContainerQuantity, MACROInterpretationContainerQuantityHandle);
DEFINE_C_API_EQUAL_TEMPLATE(InterpretationContainerQuantity, MACROInterpretationContainerQuantityHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(InterpretationContainerQuantity, MACROInterpretationContainerQuantityHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(InterpretationContainerQuantity, MACROInterpretationContainerQuantityHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(InterpretationContainerQuantity, MACROInterpretationContainerQuantityHandle);
InterpretationContainerQuantityHandle InterpretationContainerQuantity_create(MapInterpretationContextQuantityHandle map) {
    FALCON_C_API_BEGIN
if (!map) {
throw std::invalid_argument("Null map handle passed to InterpretationContainerQuantity_create");
}
    auto real_map = *static_cast<falcon_core::generic::MapSP<
        falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>*>(map);
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>(
        std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<falcon_core::math::Quantity>>(real_map));
    FALCON_C_API_END(nullptr)
}

SymbolUnitHandle InterpretationContainerQuantity_unit(
     InterpretationContainerQuantityHandle handle) {
    FALCON_C_API_BEGIN
     if (!handle) {
     throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_unit");
     }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    return new falcon_core::physics::units::SymbolUnitSP(that->unit());
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connection(
    InterpretationContainerQuantityHandle handle, ConnectionHandle connection) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_select_by_connection");
    }
    if (!connection) {
    throw std::invalid_argument("Null connection handle passed to InterpretationContainerQuantity_select_by_connection");
    }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    auto conn = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(connection);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_connection(conn));
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connections(
                    InterpretationContainerQuantityHandle handle, ConnectionsHandle connections) {
    FALCON_C_API_BEGIN
                    if (!handle) {
                    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_select_by_connections");
                    }
                    if (!connections) {
                    throw std::invalid_argument("Null connections handle passed to InterpretationContainerQuantity_select_by_connections");
                    }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    auto conns = *static_cast<falcon_core::physics::device_structures::ConnectionsSP*>(connections);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_connections(conns->items()));
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_independent_connection(
    InterpretationContainerQuantityHandle handle, ConnectionHandle connection) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_select_by_independent_connection");
    }
    if (!connection) {
    throw std::invalid_argument("Null connection handle passed to InterpretationContainerQuantity_select_by_independent_connection");
    }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    auto conn = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(connection);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_independent_connection(conn));
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_by_dependent_connection(
    InterpretationContainerQuantityHandle handle, ConnectionHandle connection) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_select_by_dependent_connection");
    }
    if (!connection) {
    throw std::invalid_argument("Null connection handle passed to InterpretationContainerQuantity_select_by_dependent_connection");
    }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    auto conn = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(connection);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_dependent_connection(conn));
    FALCON_C_API_END(nullptr)
}

ListInterpretationContextHandle InterpretationContainerQuantity_select_contexts(
    InterpretationContainerQuantityHandle handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_select_contexts");
    }
    if (!independent_connections) {
    throw std::invalid_argument("Null independent connections handle passed to InterpretationContainerQuantity_select_contexts");
    }
    if (!dependent_connections) {
    throw std::invalid_argument("Null dependent connections handle passed to InterpretationContainerQuantity_select_contexts");
    }
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    auto independents = *static_cast<falcon_core::generic::ListSP<
        falcon_core::physics::device_structures::Connection>*>(independent_connections);
    auto dependents = *static_cast<falcon_core::generic::ListSP<
        falcon_core::physics::device_structures::Connection>*>(dependent_connections);
    return new falcon_core::generic::ListSP<
        falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(
        that->select_contexts(independents, dependents));
    FALCON_C_API_END(nullptr)
}

void InterpretationContainerQuantity_insert_or_assign(InterpretationContainerQuantityHandle handle,
     InterpretationContextHandle   key,
     QuantityHandle value) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_insert_or_assign");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerQuantity_insert_or_assign");
    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    auto context= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    
            if (!value) {
            throw std::invalid_argument("Null value passed to InterpretationContainerQuantity_create");
            }
            auto value_obj = *static_cast<falcon_core::math::QuantitySP*>(value);
    that->insert_or_assign(context, value_obj);
    FALCON_C_API_END()
}

void InterpretationContainerQuantity_insert(
    InterpretationContainerQuantityHandle handle,
     InterpretationContextHandle   key,
     QuantityHandle value) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_insert");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerQuantity_insert");
    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    auto context= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    
            if (!value) {
            throw std::invalid_argument("Null value passed to InterpretationContainerQuantity_create");
            }
            auto value_obj = *static_cast<falcon_core::math::QuantitySP*>(value);
    that->insert_or_assign(context, value_obj);
    FALCON_C_API_END()
}

QuantityHandle InterpretationContainerQuantity_at(InterpretationContainerQuantityHandle handle,
     InterpretationContextHandle   key) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_at");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerQuantity_at");
    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    auto context= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    auto out = that->at(context);
    return new falcon_core::math::QuantitySP(out);
    FALCON_C_API_END(nullptr)
}

void InterpretationContainerQuantity_erase(InterpretationContainerQuantityHandle handle,
     InterpretationContextHandle   key) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_erase");
    }
    if (!key) {
    throw std::invalid_argument("Null key passed to InterpretationContainerQuantity_erase");
    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    auto context = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    return that->erase(context);
    FALCON_C_API_END()
}

size_t InterpretationContainerQuantity_size(InterpretationContainerQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_size");
}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    return that->size();
    FALCON_C_API_END(0)
}

bool InterpretationContainerQuantity_empty(InterpretationContainerQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_empty");
}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    return that->empty();
    FALCON_C_API_END(false)
}

void InterpretationContainerQuantity_clear(InterpretationContainerQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_clear");
}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    that->clear();
    FALCON_C_API_END()
}

bool InterpretationContainerQuantity_contains(InterpretationContainerQuantityHandle handle,
     InterpretationContextHandle   key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_contains");
}
if (!key) {
throw std::invalid_argument("Null key passed to InterpretationContainerQuantity_contains");
}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    auto context = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    return that->contains(context);
    FALCON_C_API_END(false)
}

ListInterpretationContextHandle InterpretationContainerQuantity_keys(
                    InterpretationContainerQuantityHandle handle) {
    FALCON_C_API_BEGIN
                    if (!handle) {
                    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_keys");
                    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->keys());
    FALCON_C_API_END(nullptr)
}

ListQuantityHandle InterpretationContainerQuantity_values(InterpretationContainerQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_values");
}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::math::Quantity>(that->values());
    FALCON_C_API_END(nullptr)
}

ListPairInterpretationContextQuantityHandle InterpretationContainerQuantity_items(
                    InterpretationContainerQuantityHandle handle) {
    FALCON_C_API_BEGIN
                    if (!handle) {
                    throw std::invalid_argument("Null handle passed to InterpretationContainerQuantity_items");
                    }
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<falcon_core::math::Quantity>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>>(that->items());
    FALCON_C_API_END(nullptr)
}
}
