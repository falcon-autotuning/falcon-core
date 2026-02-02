#include <falcon_core\generic/Pair.hpp>
#include "falcon_core\generic\PairInstrumentPortPortTransform_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/instrument_interfaces/names/InstrumentPort.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairInstrumentPortHandlePortTransformHandle = falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>;
DEFINE_C_API_COPY_TEMPLATE(PairInstrumentPortPortTransform, MACROPairInstrumentPortHandlePortTransformHandle)
DEFINE_C_API_DESTROY_TEMPLATE(PairInstrumentPortPortTransform, MACROPairInstrumentPortHandlePortTransformHandle);
DEFINE_C_API_EQUAL_TEMPLATE(PairInstrumentPortPortTransform, MACROPairInstrumentPortHandlePortTransformHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairInstrumentPortPortTransform, MACROPairInstrumentPortHandlePortTransformHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(PairInstrumentPortPortTransform, MACROPairInstrumentPortHandlePortTransformHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairInstrumentPortPortTransform, MACROPairInstrumentPortHandlePortTransformHandle);
PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_create(InstrumentPortHandle first, PortTransformHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairInstrumentPortPortTransform_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairInstrumentPortPortTransform_create");
                }
                auto second_obj= *static_cast<std::shared_ptr<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(second);
    return new falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

InstrumentPortHandle PairInstrumentPortPortTransform_first(PairInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortPortTransform_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    return new std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(pair->first());
    FALCON_C_API_END(nullptr)
}

PortTransformHandle PairInstrumentPortPortTransform_second(PairInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortPortTransform_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    return new std::shared_ptr<falcon_core::instrument_interfaces::port_transforms::PortTransform>(pair->second());
    FALCON_C_API_END(nullptr)
}
}
