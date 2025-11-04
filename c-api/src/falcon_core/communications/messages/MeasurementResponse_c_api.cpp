#include "falcon_core/communications/messages/MeasurementResponse_c_api.h"

#include <falcon_core/generic/String_c_api.h>

#include <falcon_core/communications/messages/MeasurementResponse.hpp>
#include <string>

#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"

using namespace falcon_core;
using namespace falcon_core::communications::messages;

MeasurementResponseHandle MeasurementResponse_create(
    LabelledArraysLabelledMeasuredArrayHandle arrays) {
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
}

void MeasurementResponse_destroy(MeasurementResponseHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_destroy");
  }
  delete static_cast<MeasurementResponse*>(handle);
}

LabelledArraysLabelledMeasuredArrayHandle MeasurementResponse_arrays(
    MeasurementResponseHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_arrays");
  }
  MeasurementResponse* measurement_response =
      static_cast<MeasurementResponse*>(handle);
  return new math::arrays::LabelledArrays<math::arrays::LabelledMeasuredArray>(
      *(measurement_response->arrays()));
}

StringHandle MeasurementResponse_message(MeasurementResponseHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_message");
  }
  MeasurementResponse* measurement_response =
      static_cast<MeasurementResponse*>(handle);
  std::string message = measurement_response->message();
  return String_create(message.c_str(), message.size());
}

bool MeasurementResponse_equal(MeasurementResponseHandle handle,
                               MeasurementResponseHandle other) {
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
}

bool MeasurementResponse_not_equal(MeasurementResponseHandle handle,
                                   MeasurementResponseHandle other) {
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
}

StringHandle MeasurementResponse_to_json_string(
    MeasurementResponseHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_to_json_string");
  }
  MeasurementResponse* measurement_response =
      static_cast<MeasurementResponse*>(handle);
  std::string json_str = measurement_response->to_json_string();
  return String_create(json_str.c_str(), json_str.size());
}

MeasurementResponseHandle MeasurementResponse_from_json_string(
    StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_from_json_string");
  }
  std::string           json_str = std::string(json->raw, json->length);
  MeasurementResponseSP measurement_response =
      MeasurementResponse::from_json_string<MeasurementResponse>(json_str);
  return new MeasurementResponse(*measurement_response);
}
