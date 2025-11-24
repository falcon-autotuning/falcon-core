#include "falcon_core/communications/messages/MeasurementResponse_c_api.h"

#include <falcon_core/generic/String_c_api.h>

#include <falcon_core/communications/messages/MeasurementResponse.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"

using namespace falcon_core;
using namespace falcon_core::communications::messages;

extern "C" {
MeasurementResponseHandle MeasurementResponse_create(
    LabelledArraysLabelledMeasuredArrayHandle arrays) {
  FALCON_C_API_BEGIN
  if (!arrays) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_create");
  }
  math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray>
      real_arrays = std::make_shared<
          math::arrays::LabelledArrays<math::arrays::LabelledMeasuredArray>>(
          *static_cast<math::arrays::LabelledArrays<
              math::arrays::LabelledMeasuredArray>*>(arrays));
  return new MeasurementResponse(real_arrays);
  FALCON_C_API_END(nullptr)
}

void MeasurementResponse_destroy(MeasurementResponseHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_destroy");
  }
  delete static_cast<MeasurementResponse*>(handle);
  FALCON_C_API_END()
}

LabelledArraysLabelledMeasuredArrayHandle MeasurementResponse_arrays(
    MeasurementResponseHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_arrays");
  }
  MeasurementResponse* measurement_response =
      static_cast<MeasurementResponse*>(handle);
  return new math::arrays::LabelledArrays<math::arrays::LabelledMeasuredArray>(
      *(measurement_response->arrays()));
  FALCON_C_API_END(nullptr)
}

StringHandle MeasurementResponse_message(MeasurementResponseHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_message");
  }
  MeasurementResponse* measurement_response =
      static_cast<MeasurementResponse*>(handle);
  std::string message = measurement_response->message();
  return String_create(message.c_str(), message.size());
  FALCON_C_API_END(nullptr)
}

bool MeasurementResponse_equal(MeasurementResponseHandle handle,
                               MeasurementResponseHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_equal");
  }
  if (!other) {
    throw std::invalid_argument(
        "Null other handle passed to MeasurementResponse_equal");
  }
  return *(static_cast<MeasurementResponse*>(handle)) ==
         *(static_cast<MeasurementResponse*>(other));
  FALCON_C_API_END(false)
}

bool MeasurementResponse_not_equal(MeasurementResponseHandle handle,
                                   MeasurementResponseHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_not_equal");
  }
  if (!other) {
    throw std::invalid_argument(
        "Null other handle passed to MeasurementResponse_not_equal");
  }
  return *(static_cast<MeasurementResponse*>(handle)) !=
         *(static_cast<MeasurementResponse*>(other));
  FALCON_C_API_END(false)
}

StringHandle MeasurementResponse_to_json_string(
    MeasurementResponseHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_to_json_string");
  }
  MeasurementResponse* measurement_response =
      static_cast<MeasurementResponse*>(handle);
  std::string json_str = measurement_response->to_json_string();
  return String_create(json_str.c_str(), json_str.size());
  FALCON_C_API_END(nullptr)
}

MeasurementResponseHandle MeasurementResponse_from_json_string(
    StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_from_json_string");
  }
  std::string           json_str = std::string(json->raw, json->length);
  MeasurementResponseSP measurement_response =
      MeasurementResponse::from_json_string<MeasurementResponse>(json_str);
  return new MeasurementResponse(*measurement_response);
  FALCON_C_API_END(nullptr)
}
}
