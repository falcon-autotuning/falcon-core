#include <falcon-core/generic/Pair.hpp>
#include "falcon-core/generic/PairInstrumentPortQuantity_c_api.h"
#include "falcon-core/Precompiled_c_api.h"
#include "falcon-core/export_c_api.h"
#include <falcon-core/instrument_interfaces/names/InstrumentPort.hpp>
#include <falcon-core/math/Quantity.hpp>
#include "falcon-core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairInstrumentPortHandleQuantityHandle = falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>;
DEFINE_C_API_COPY_TEMPLATE(PairInstrumentPortQuantity, MACROPairInstrumentPortHandleQuantityHandle)
DEFINE_C_API_DESTROY_TEMPLATE(PairInstrumentPortQuantity, MACROPairInstrumentPortHandleQuantityHandle);
DEFINE_C_API_EQUAL_TEMPLATE(PairInstrumentPortQuantity, MACROPairInstrumentPortHandleQuantityHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairInstrumentPortQuantity, MACROPairInstrumentPortHandleQuantityHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(PairInstrumentPortQuantity, MACROPairInstrumentPortHandleQuantityHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairInstrumentPortQuantity, MACROPairInstrumentPortHandleQuantityHandle);
PairInstrumentPortQuantityHandle PairInstrumentPortQuantity_create(InstrumentPortHandle first, QuantityHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairInstrumentPortQuantity_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairInstrumentPortQuantity_create");
                }
                auto second_obj= *static_cast<std::shared_ptr<falcon_core::math::Quantity>*>(second);
    return new falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

InstrumentPortHandle PairInstrumentPortQuantity_first(PairInstrumentPortQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortQuantity_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>*>(handle);
    return new std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(pair->first());
    FALCON_C_API_END(nullptr)
}

QuantityHandle PairInstrumentPortQuantity_second(PairInstrumentPortQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortQuantity_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>*>(handle);
    return new std::shared_ptr<falcon_core::math::Quantity>(pair->second());
    FALCON_C_API_END(nullptr)
}
}
