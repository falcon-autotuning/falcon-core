#include <falcon_core\generic/Pair.hpp>
#include "falcon_core\generic\PairMeasurementResponseMeasurementRequest_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/communications/messages/MeasurementResponse.hpp>
#include <falcon_core/communications/messages/MeasurementRequest.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairMeasurementResponseHandleMeasurementRequestHandle = falcon_core::generic::Pair<falcon_core::communications::messages::MeasurementResponse, falcon_core::communications::messages::MeasurementRequest>;
DEFINE_C_API_COPY_TEMPLATE(PairMeasurementResponseMeasurementRequest, MACROPairMeasurementResponseHandleMeasurementRequestHandle)
DEFINE_C_API_DESTROY_TEMPLATE(PairMeasurementResponseMeasurementRequest, MACROPairMeasurementResponseHandleMeasurementRequestHandle);
DEFINE_C_API_EQUAL_TEMPLATE(PairMeasurementResponseMeasurementRequest, MACROPairMeasurementResponseHandleMeasurementRequestHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairMeasurementResponseMeasurementRequest, MACROPairMeasurementResponseHandleMeasurementRequestHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(PairMeasurementResponseMeasurementRequest, MACROPairMeasurementResponseHandleMeasurementRequestHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairMeasurementResponseMeasurementRequest, MACROPairMeasurementResponseHandleMeasurementRequestHandle);
PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_create(MeasurementResponseHandle first, MeasurementRequestHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairMeasurementResponseMeasurementRequest_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::communications::messages::MeasurementResponse>*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairMeasurementResponseMeasurementRequest_create");
                }
                auto second_obj= *static_cast<std::shared_ptr<falcon_core::communications::messages::MeasurementRequest>*>(second);
    return new falcon_core::generic::PairSP<falcon_core::communications::messages::MeasurementResponse, falcon_core::communications::messages::MeasurementRequest>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::communications::messages::MeasurementResponse, falcon_core::communications::messages::MeasurementRequest>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

MeasurementResponseHandle PairMeasurementResponseMeasurementRequest_first(PairMeasurementResponseMeasurementRequestHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairMeasurementResponseMeasurementRequest_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::communications::messages::MeasurementResponse, falcon_core::communications::messages::MeasurementRequest>*>(handle);
    return new std::shared_ptr<falcon_core::communications::messages::MeasurementResponse>(pair->first());
    FALCON_C_API_END(nullptr)
}

MeasurementRequestHandle PairMeasurementResponseMeasurementRequest_second(PairMeasurementResponseMeasurementRequestHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairMeasurementResponseMeasurementRequest_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::communications::messages::MeasurementResponse, falcon_core::communications::messages::MeasurementRequest>*>(handle);
    return new std::shared_ptr<falcon_core::communications::messages::MeasurementRequest>(pair->second());
    FALCON_C_API_END(nullptr)
}
}
