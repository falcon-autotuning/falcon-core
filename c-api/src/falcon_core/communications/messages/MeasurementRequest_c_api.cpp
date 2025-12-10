#include "falcon_core/communications/messages/MeasurementRequest_c_api.h"

#include <falcon_core/communications/messages/MeasurementRequest.hpp>
#include <string>

#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"

using namespace falcon_core;
using namespace falcon_core::communications::messages;

extern "C" {
DEFINE_C_API_COPY(MeasurementRequest);
DEFINE_C_API_DESTROY(MeasurementRequest);
DEFINE_C_API_EQUAL(MeasurementRequest);
DEFINE_C_API_NOT_EQUAL(MeasurementRequest);
DEFINE_C_API_TO_JSON(MeasurementRequest);
DEFINE_C_API_FROM_JSON(MeasurementRequest);
MeasurementRequestHandle MeasurementRequest_create(
    StringHandle                         message,
    StringHandle                         measurement_name,
    ListWaveformHandle                   waveforms,
    PortsHandle                          getters,
    MapInstrumentPortPortTransformHandle meter_transforms,
    LabelledDomainHandle                 time_domain) {
  FALCON_C_API_BEGIN
  if (!message) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_create: message");
  }
  if (!measurement_name) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_create: measurement_name");
  }
  if (!waveforms) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_create: waveforms");
  }
  if (!getters) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_create: getters");
  }
  if (!meter_transforms) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_create: meter_transforms");
  }
  if (!time_domain) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_create: time_domain");
  }
  std::string real_msg = std::string(message->raw, message->length);
  std::string real_measurement_name =
      std::string(measurement_name->raw, measurement_name->length);
  generic::ListSP<instrument_interfaces::Waveform> real_waveforms =
      *static_cast<generic::ListSP<instrument_interfaces::Waveform>*>(
          waveforms);
  instrument_interfaces::names::PortsSP real_getters =
      *static_cast<instrument_interfaces::names::PortsSP*>(getters);
  generic::MapSP<instrument_interfaces::names::InstrumentPort,
                 instrument_interfaces::port_transforms::PortTransform>
      real_meter_transforms = *static_cast<generic::MapSP<
          instrument_interfaces::names::InstrumentPort,
          instrument_interfaces::port_transforms::PortTransform>*>(
          meter_transforms);
  math::domains::LabelledDomainSP real_time_domain =
      *static_cast<math::domains::LabelledDomainSP*>(time_domain);
  return new MeasurementRequestSP(
      std::make_shared<MeasurementRequest>(real_msg,
                                           real_measurement_name,
                                           real_waveforms,
                                           real_getters,
                                           real_meter_transforms,
                                           real_time_domain));
  FALCON_C_API_END(nullptr)
}

StringHandle MeasurementRequest_measurement_name(
    MeasurementRequestHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_measurement_name");
  }
  MeasurementRequestSP measurement_request =
      *static_cast<MeasurementRequestSP*>(handle);
  std::string name = measurement_request->measurement_name();
  return String_create(name.c_str(), name.size());
  FALCON_C_API_END(nullptr)
}

PortsHandle MeasurementRequest_getters(MeasurementRequestHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_getters");
  }
  MeasurementRequestSP measurement_request =
      *static_cast<MeasurementRequestSP*>(handle);
  return new instrument_interfaces::names::PortsSP(
      measurement_request->getters());
  FALCON_C_API_END(nullptr)
}

ListWaveformHandle MeasurementRequest_waveforms(
    MeasurementRequestHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_waveforms");
  }
  MeasurementRequestSP measurement_request =
      *static_cast<MeasurementRequestSP*>(handle);
  return new generic::ListSP<instrument_interfaces::Waveform>(
      measurement_request->waveforms());
  FALCON_C_API_END(nullptr)
}

MapInstrumentPortPortTransformHandle MeasurementRequest_meter_transforms(
    MeasurementRequestHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_meter_transforms");
  }
  MeasurementRequestSP measurement_request =
      *static_cast<MeasurementRequestSP*>(handle);
  return new generic::MapSP<
      instrument_interfaces::names::InstrumentPort,
      instrument_interfaces::port_transforms::PortTransform>(
      measurement_request->meter_transforms());
  FALCON_C_API_END(nullptr)
}

LabelledDomainHandle MeasurementRequest_time_domain(
    MeasurementRequestHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_time_domain");
  }
  MeasurementRequestSP measurement_request =
      *static_cast<MeasurementRequestSP*>(handle);
  return new math::domains::LabelledDomainSP(
      (measurement_request->time_domain()));
  FALCON_C_API_END(nullptr)
}

StringHandle MeasurementRequest_message(MeasurementRequestHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_message");
  }
  MeasurementRequestSP measurement_request =
      *static_cast<MeasurementRequestSP*>(handle);
  std::string message = measurement_request->message();
  return String_create(message.c_str(), message.size());
  FALCON_C_API_END(nullptr)
}
}
