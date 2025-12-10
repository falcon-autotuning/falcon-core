#include "falcon_core/communications/messages/MeasurementResponse_c_api.h"

#include <falcon_core/communications/messages/MeasurementResponse.hpp>
#include <string>

#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"

using namespace falcon_core;
using namespace falcon_core::communications::messages;

extern "C" {
DEFINE_C_API_COPY(MeasurementResponse);
DEFINE_C_API_DESTROY(MeasurementResponse);
DEFINE_C_API_EQUAL(MeasurementResponse);
DEFINE_C_API_NOT_EQUAL(MeasurementResponse);
DEFINE_C_API_TO_JSON(MeasurementResponse);
DEFINE_C_API_FROM_JSON(MeasurementResponse);
MeasurementResponseHandle MeasurementResponse_create(
    LabelledArraysLabelledMeasuredArrayHandle arrays) {
  FALCON_C_API_BEGIN
  if (!arrays) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_create");
  }
  math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray>
      real_arrays = *static_cast<
          math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray>*>(
          arrays);
  return new MeasurementResponseSP(
      std::make_shared<MeasurementResponse>(real_arrays));
  FALCON_C_API_END(nullptr)
}

LabelledArraysLabelledMeasuredArrayHandle MeasurementResponse_arrays(
    MeasurementResponseHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_arrays");
  }
  MeasurementResponseSP measurement_response =
      *static_cast<MeasurementResponseSP*>(handle);
  return new math::arrays::LabelledArraysSP<
      math::arrays::LabelledMeasuredArray>(measurement_response->arrays());
  FALCON_C_API_END(nullptr)
}

StringHandle MeasurementResponse_message(MeasurementResponseHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementResponse_message");
  }
  MeasurementResponseSP measurement_response =
      *static_cast<MeasurementResponseSP*>(handle);
  std::string message = measurement_response->message();
  return String_create(message.c_str(), message.size());
  FALCON_C_API_END(nullptr)
}
}
