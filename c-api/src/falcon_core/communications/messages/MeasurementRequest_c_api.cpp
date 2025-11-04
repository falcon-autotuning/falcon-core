#include "falcon_core/communications/messages/MeasurementRequest_c_api.h"

#include <falcon_core/generic/String_c_api.h>

#include <falcon_core/communications/messages/MeasurementRequest.hpp>
#include <string>

#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"

using namespace falcon_core;
using namespace falcon_core::communications::messages;

MeasurementRequestHandle MeasurementRequest_create(
    StringHandle                         message,
    StringHandle                         measurement_name,
    ListWaveformHandle                   waveforms,
    PortsHandle                          getters,
    MapInstrumentPortPortTransformHandle meter_transforms,
    LabelledDomainHandle                 time_domain) {
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
      std::make_shared<generic::List<instrument_interfaces::Waveform>>(
          *static_cast<generic::List<instrument_interfaces::Waveform>*>(
              waveforms));
  instrument_interfaces::names::PortsSP real_getters =
      std::make_shared<instrument_interfaces::names::Ports>(
          *static_cast<instrument_interfaces::names::Ports*>(getters));
  generic::MapSP<instrument_interfaces::names::InstrumentPort,
                 instrument_interfaces::port_transforms::PortTransform>
      real_meter_transforms = std::make_shared<
          generic::Map<instrument_interfaces::names::InstrumentPort,
                       instrument_interfaces::port_transforms::PortTransform>>(
          *static_cast<generic::Map<
              instrument_interfaces::names::InstrumentPort,
              instrument_interfaces::port_transforms::PortTransform>*>(
              meter_transforms));
  math::domains::LabelledDomainSP real_time_domain =
      std::make_shared<math::domains::LabelledDomain>(
          *static_cast<math::domains::LabelledDomain*>(time_domain));
  return new MeasurementRequest(real_msg,
                                real_measurement_name,
                                real_waveforms,
                                real_getters,
                                real_meter_transforms,
                                real_time_domain);
}

void MeasurementRequest_destroy(MeasurementRequestHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_destroy");
  }
  delete static_cast<MeasurementRequest*>(handle);
}

StringHandle MeasurementRequest_measurement_name(
    MeasurementRequestHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_measurement_name");
  }
  MeasurementRequest* measurement_request =
      static_cast<MeasurementRequest*>(handle);
  std::string name = measurement_request->measurement_name();
  return String_create(name.c_str(), name.size());
}

PortsHandle MeasurementRequest_getters(MeasurementRequestHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_getters");
  }
  MeasurementRequest* measurement_request =
      static_cast<MeasurementRequest*>(handle);
  return new instrument_interfaces::names::Ports(
      *(measurement_request->getters()));
}

ListWaveformHandle MeasurementRequest_waveforms(
    MeasurementRequestHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_waveforms");
  }
  MeasurementRequest* measurement_request =
      static_cast<MeasurementRequest*>(handle);
  return new generic::List<instrument_interfaces::Waveform>(
      *(measurement_request->waveforms()));
}

MapInstrumentPortPortTransformHandle MeasurementRequest_meter_transforms(
    MeasurementRequestHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_meter_transforms");
  }
  MeasurementRequest* measurement_request =
      static_cast<MeasurementRequest*>(handle);
  return new generic::Map<
      instrument_interfaces::names::InstrumentPort,
      instrument_interfaces::port_transforms::PortTransform>(
      *(measurement_request->meter_transforms()));
}

LabelledDomainHandle MeasurementRequest_time_domain(
    MeasurementRequestHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_time_domain");
  }
  MeasurementRequest* measurement_request =
      static_cast<MeasurementRequest*>(handle);
  return new math::domains::LabelledDomain(
      *(measurement_request->time_domain()));
}

StringHandle MeasurementRequest_message(MeasurementRequestHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_message");
  }
  MeasurementRequest* measurement_request =
      static_cast<MeasurementRequest*>(handle);
  std::string message = measurement_request->message();
  return String_create(message.c_str(), message.size());
}

bool MeasurementRequest_equal(MeasurementRequestHandle handle,
                              MeasurementRequestHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_equal: handle");
  }
  if (!other) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_equal: other");
  }
  MeasurementRequest* measurement_request =
      static_cast<MeasurementRequest*>(handle);
  MeasurementRequest* other_request = static_cast<MeasurementRequest*>(other);
  return *measurement_request == *other_request;
}

bool MeasurementRequest_not_equal(MeasurementRequestHandle handle,
                                  MeasurementRequestHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_not_equal: handle");
  }
  if (!other) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_not_equal: other");
  }
  MeasurementRequest* measurement_request =
      static_cast<MeasurementRequest*>(handle);
  MeasurementRequest* other_request = static_cast<MeasurementRequest*>(other);
  return *measurement_request != *other_request;
}

StringHandle MeasurementRequest_to_json_string(
    MeasurementRequestHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_to_json_string");
  }
  MeasurementRequest* measurement_request =
      static_cast<MeasurementRequest*>(handle);
  std::string json = measurement_request->to_json_string();
  return String_create(json.c_str(), json.size());
}

MeasurementRequestHandle MeasurementRequest_from_json_string(
    StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "Null handle passed to MeasurementRequest_from_json_string");
  }
  std::string          json_str = std::string(json->raw, json->length);
  MeasurementRequestSP request =
      MeasurementRequest::from_json_string<MeasurementRequest>(json_str);
  return new MeasurementRequest(*request);
}
