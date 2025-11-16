#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairMeasurementResponseMeasurementRequest_c_api.h"
#include <falcon_core/communications/messages/MeasurementResponse.hpp>
#include <falcon_core/communications/messages/MeasurementRequest.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_create(MeasurementResponseHandle first, MeasurementRequestHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairMeasurementResponseMeasurementRequest_create");
                }
                auto first_obj= std::make_shared<falcon_core::communications::messages::MeasurementResponse>(*static_cast<falcon_core::communications::messages::MeasurementResponse*>(first));
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairMeasurementResponseMeasurementRequest_create");
                }
                auto second_obj= std::make_shared<falcon_core::communications::messages::MeasurementRequest>(*static_cast<falcon_core::communications::messages::MeasurementRequest*>(second));
    return new falcon_core::generic::Pair<falcon_core::communications::messages::MeasurementResponse, falcon_core::communications::messages::MeasurementRequest>(first_obj, second_obj);
    FALCON_C_API_END(nullptr)
}

void PairMeasurementResponseMeasurementRequest_destroy(PairMeasurementResponseMeasurementRequestHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairMeasurementResponseMeasurementRequest_destroy");
}
    delete static_cast<falcon_core::generic::Pair<falcon_core::communications::messages::MeasurementResponse, falcon_core::communications::messages::MeasurementRequest>*>(handle);
    FALCON_C_API_END()
}

MeasurementResponseHandle PairMeasurementResponseMeasurementRequest_first(PairMeasurementResponseMeasurementRequestHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairMeasurementResponseMeasurementRequest_first");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::communications::messages::MeasurementResponse, falcon_core::communications::messages::MeasurementRequest>*>(handle);
    return new falcon_core::communications::messages::MeasurementResponse(*pair->first());
    FALCON_C_API_END(nullptr)
}

MeasurementRequestHandle PairMeasurementResponseMeasurementRequest_second(PairMeasurementResponseMeasurementRequestHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairMeasurementResponseMeasurementRequest_second");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::communications::messages::MeasurementResponse, falcon_core::communications::messages::MeasurementRequest>*>(handle);
    return new falcon_core::communications::messages::MeasurementRequest(*pair->second());
    FALCON_C_API_END(nullptr)
}

bool PairMeasurementResponseMeasurementRequest_equal(PairMeasurementResponseMeasurementRequestHandle a, PairMeasurementResponseMeasurementRequestHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairMeasurementResponseMeasurementRequest_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::communications::messages::MeasurementResponse, falcon_core::communications::messages::MeasurementRequest>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::communications::messages::MeasurementResponse, falcon_core::communications::messages::MeasurementRequest>*>(b);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairMeasurementResponseMeasurementRequest_not_equal(PairMeasurementResponseMeasurementRequestHandle a, PairMeasurementResponseMeasurementRequestHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairMeasurementResponseMeasurementRequest_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::communications::messages::MeasurementResponse, falcon_core::communications::messages::MeasurementRequest>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::communications::messages::MeasurementResponse, falcon_core::communications::messages::MeasurementRequest>*>(b);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairMeasurementResponseMeasurementRequest_to_json_string(PairMeasurementResponseMeasurementRequestHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairMeasurementResponseMeasurementRequest_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::communications::messages::MeasurementResponse,falcon_core::communications::messages::MeasurementRequest>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairMeasurementResponseMeasurementRequest_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::communications::messages::MeasurementResponse,falcon_core::communications::messages::MeasurementRequest>::from_json_string<falcon_core::generic::Pair<falcon_core::communications::messages::MeasurementResponse,falcon_core::communications::messages::MeasurementRequest>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::communications::messages::MeasurementResponse,falcon_core::communications::messages::MeasurementRequest>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
