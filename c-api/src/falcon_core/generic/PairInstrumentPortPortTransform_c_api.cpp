#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairInstrumentPortPortTransform_c_api.h"
#include <falcon_core/instrument_interfaces/names/InstrumentPort.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>

PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_create(InstrumentPortHandle first, PortTransformHandle second) {
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairInstrumentPortPortTransform_create");
                }
                auto first_obj= std::make_shared<falcon_core::instrument_interfaces::names::InstrumentPort>(*static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(first));
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairInstrumentPortPortTransform_create");
                }
                auto second_obj= std::make_shared<falcon_core::instrument_interfaces::port_transforms::PortTransform>(*static_cast<falcon_core::instrument_interfaces::port_transforms::PortTransform*>(second));
    return new falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>(first_obj, second_obj);
}

void PairInstrumentPortPortTransform_destroy(PairInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortPortTransform_destroy");
}
    delete static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
}

InstrumentPortHandle PairInstrumentPortPortTransform_first(PairInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortPortTransform_first");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    return new falcon_core::instrument_interfaces::names::InstrumentPort(*pair->first());
}

PortTransformHandle PairInstrumentPortPortTransform_second(PairInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortPortTransform_second");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    return new falcon_core::instrument_interfaces::port_transforms::PortTransform(*pair->second());
}

bool PairInstrumentPortPortTransform_equal(PairInstrumentPortPortTransformHandle a, PairInstrumentPortPortTransformHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortPortTransform_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(b);
    return *pair_a == *pair_b;
}

bool PairInstrumentPortPortTransform_not_equal(PairInstrumentPortPortTransformHandle a, PairInstrumentPortPortTransformHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortPortTransform_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairInstrumentPortPortTransform_to_json_string(PairInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairInstrumentPortPortTransform_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairInstrumentPortPortTransform_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>::from_json_string<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>(*ptr);
}
