#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairInstrumentPortPortTransform_c_api.h"
#include <falcon_core/instrument_interfaces/names/InstrumentPort.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_create(InstrumentPortHandle first, PortTransformHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairInstrumentPortPortTransform_create");
                }
                auto first_obj= *static_cast<falcon_core::instrument_interfaces::names::InstrumentPortSP*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairInstrumentPortPortTransform_create");
                }
                auto second_obj= *static_cast<falcon_core::instrument_interfaces::port_transforms::PortTransformSP*>(second);
    return new falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

void PairInstrumentPortPortTransform_destroy(PairInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortPortTransform_destroy");
}
    delete static_cast<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    FALCON_C_API_END()
}

InstrumentPortHandle PairInstrumentPortPortTransform_first(PairInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortPortTransform_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    return new falcon_core::instrument_interfaces::names::InstrumentPortSP(pair->first());
    FALCON_C_API_END(nullptr)
}

PortTransformHandle PairInstrumentPortPortTransform_second(PairInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortPortTransform_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    return new falcon_core::instrument_interfaces::port_transforms::PortTransformSP(pair->second());
    FALCON_C_API_END(nullptr)
}

bool PairInstrumentPortPortTransform_equal(PairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortPortTransform_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(other);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairInstrumentPortPortTransform_not_equal(PairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortPortTransform_not_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(other);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairInstrumentPortPortTransform_to_json_string(PairInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortPortTransform_to_json_string");
}
std::string json = (*static_cast<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairInstrumentPortPortTransform_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>::from_json_string<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>>(json->raw);
  return new falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>(ptr);
    FALCON_C_API_END(nullptr)
}
}
