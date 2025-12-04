#include "falcon_core/communications/HDF5Data_c_api.h"

#include <falcon_core/generic/String_c_api.h>

#include <falcon_core/communications/HDF5Data.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"

using namespace falcon_core;
using namespace falcon_core::communications;

extern "C" {
HDF5DataHandle HDF5Data_create(AxesIntHandle                   shape,
                               AxesControlArrayHandle          unit_domain,
                               AxesCoupledLabelledDomainHandle domain_labels,
                               LabelledArraysLabelledMeasuredArrayHandle ranges,
                               MapStringStringHandle metadata,
                               StringHandle          measurement_title,
                               int                   unique_id,
                               int                   timestamp) {
  FALCON_C_API_BEGIN
  if (!shape) {
    throw std::invalid_argument("Null handle passed to HDF5Data_create: shape");
  }
  if (!unit_domain) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_create: unit_domain");
  }
  if (!domain_labels) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_create: domain_labels");
  }
  if (!ranges) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_create: ranges");
  }
  if (!metadata) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_create: metadata");
  }
  if (!measurement_title) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_create: measurement_title");
  }
  math::AxesSP<int> real_shape =
      std::make_shared<math::Axes<int>>(*static_cast<math::Axes<int>*>(shape));
  math::AxesSP<math::arrays::ControlArray> real_control_arrays =
      std::make_shared<math::Axes<math::arrays::ControlArray>>(
          *static_cast<math::Axes<math::arrays::ControlArray>*>(unit_domain));
  math::AxesSP<math::domains::CoupledLabelledDomain> real_domain_labels =
      std::make_shared<math::Axes<math::domains::CoupledLabelledDomain>>(
          *static_cast<math::Axes<math::domains::CoupledLabelledDomain>*>(
              domain_labels));
  math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray>
      real_ranges = std::make_shared<
          math::arrays::LabelledArrays<math::arrays::LabelledMeasuredArray>>(
          *static_cast<math::arrays::LabelledArrays<
              math::arrays::LabelledMeasuredArray>*>(ranges));
  generic::MapSP<std::string, std::string> real_metadata =
      std::make_shared<generic::Map<std::string, std::string>>(
          *static_cast<generic::Map<std::string, std::string>*>(metadata));
  std::string measurement_title_str =
      std::string(measurement_title->raw, measurement_title->length);
  return new HDF5Data(HDF5Data(real_shape,
                               real_control_arrays,
                               real_domain_labels,
                               real_ranges,
                               real_metadata,
                               measurement_title_str,
                               unique_id,
                               timestamp));
  FALCON_C_API_END(nullptr)
}

HDF5DataHandle HDF5Data_create_from_file(StringHandle path) {
  FALCON_C_API_BEGIN
  if (!path) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_create_from_file: path");
  }
  std::string path_str(path->raw, path->length);
  return new HDF5Data(*HDF5Data::from_file(path_str));
  FALCON_C_API_END(nullptr)
}

HDF5DataHandle HDF5Data_create_from_communications(
    MeasurementRequestHandle  request,
    MeasurementResponseHandle response,
    DeviceVoltageStatesHandle device_voltage_states,
    int8_t                    session_id[16],
    StringHandle              measurement_title,
    int                       unique_id,
    int                       timestamp) {
  FALCON_C_API_BEGIN
  if (!request) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_create_from_communications: request");
  }
  if (!response) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_create_from_communications: response");
  }
  if (!device_voltage_states) {
    throw std::invalid_argument(
        "Null handle passed to "
        "HDF5Data_create_from_communications: "
        "device_voltage_states");
  }
  if (!measurement_title) {
    throw std::invalid_argument(
        "Null handle passed to "
        "HDF5Data_create_from_communications: "
        "measurement_title");
  }
  messages::MeasurementRequestSP real_request =
      std::make_shared<messages::MeasurementRequest>(
          *static_cast<messages::MeasurementRequest*>(request));
  messages::MeasurementResponseSP real_response =
      std::make_shared<messages::MeasurementResponse>(
          *static_cast<messages::MeasurementResponse*>(response));
  voltage_states::DeviceVoltageStatesSP real_device_voltage_states =
      std::make_shared<voltage_states::DeviceVoltageStates>(
          *static_cast<voltage_states::DeviceVoltageStates*>(
              device_voltage_states));
  std::string measurement_title_str =
      std::string(measurement_title->raw, measurement_title->length);
  boost::uuids::uuid session_uuid;
  std::memcpy(&session_uuid.data[0], session_id, 16);
  return new HDF5Data(*HDF5Data::from_communications(real_request,
                                                     real_response,
                                                     real_device_voltage_states,
                                                     session_uuid,
                                                     measurement_title_str,
                                                     unique_id,
                                                     timestamp));
  FALCON_C_API_END(nullptr)
}

void HDF5Data_destroy(HDF5DataHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to HDF5Data_destroy");
  }
  delete static_cast<HDF5Data*>(handle);
  FALCON_C_API_END()
}

void HDF5Data_to_file(HDF5DataHandle handle, StringHandle path) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_to_file: handle");
  }
  if (!path) {
    throw std::invalid_argument("Null handle passed to HDF5Data_to_file: path");
  }
  HDF5Data*   hdf5_data = static_cast<HDF5Data*>(handle);
  std::string path_str(path->raw, path->length);
  hdf5_data->to_file(path_str);
  FALCON_C_API_END()
}

PairMeasurementResponseMeasurementRequestHandle HDF5Data_to_communications(
    HDF5DataHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_to_communications");
  }
  HDF5Data* hdf5_data = static_cast<HDF5Data*>(handle);
  auto      pair      = hdf5_data->to_communications();
  return new generic::Pair<messages::MeasurementResponse,
                           messages::MeasurementRequest>(pair.first,
                                                         pair.second);
  FALCON_C_API_END(nullptr)
}

StringHandle HDF5Data_to_json_string(HDF5DataHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_to_json_string");
  }
  HDF5Data*   hdf5_data = static_cast<HDF5Data*>(handle);
  std::string json_str  = hdf5_data->to_json_string();
  return String_create(json_str.c_str(), json_str.size());
  FALCON_C_API_END(nullptr)
}

HDF5DataHandle HDF5Data_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to HDF5Data_from_json_string");
  }
  std::string raw_json(json->raw);
  auto        ptr = HDF5Data::from_json_string<HDF5Data>(raw_json);
  return new HDF5Data(*ptr);
  FALCON_C_API_END(nullptr)
}

AxesIntHandle HDF5Data_shape(HDF5DataHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to HDF5Data_shape");
  }
  HDF5Data*         hdf5_data = static_cast<HDF5Data*>(handle);
  math::AxesSP<int> shape     = hdf5_data->shape();
  return new math::Axes<int>(*shape);
  FALCON_C_API_END(nullptr)
}

AxesControlArrayHandle HDF5Data_unit_domain(HDF5DataHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to HDF5Data_unit_domain");
  }
  HDF5Data* hdf5_data = static_cast<HDF5Data*>(handle);
  math::AxesSP<math::arrays::ControlArray> unit_domain =
      hdf5_data->unit_domain();
  return new math::Axes<math::arrays::ControlArray>(*unit_domain);
  FALCON_C_API_END(nullptr)
}

AxesCoupledLabelledDomainHandle HDF5Data_domain_labels(HDF5DataHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to HDF5Data_domain_labels");
  }
  HDF5Data* hdf5_data = static_cast<HDF5Data*>(handle);
  math::AxesSP<math::domains::CoupledLabelledDomain> domain_labels =
      hdf5_data->domain_labels();
  return new math::Axes<math::domains::CoupledLabelledDomain>(*domain_labels);
  FALCON_C_API_END(nullptr)
}

LabelledArraysLabelledMeasuredArrayHandle HDF5Data_ranges(
    HDF5DataHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to HDF5Data_ranges");
  }
  HDF5Data* hdf5_data = static_cast<HDF5Data*>(handle);
  auto      ranges    = hdf5_data->ranges();
  return new math::arrays::LabelledArrays<math::arrays::LabelledMeasuredArray>(
      *ranges);
  FALCON_C_API_END(nullptr)
}

MapStringStringHandle HDF5Data_metadata(HDF5DataHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to HDF5Data_metadata");
  }
  HDF5Data* hdf5_data = static_cast<HDF5Data*>(handle);
  auto      metadata  = hdf5_data->metadata();
  return new generic::Map<std::string, std::string>(*metadata);
  FALCON_C_API_END(nullptr)
}

StringHandle HDF5Data_measurement_title(HDF5DataHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_measurement_title");
  }
  HDF5Data*   hdf5_data = static_cast<HDF5Data*>(handle);
  std::string title     = hdf5_data->measurement_title();
  return String_create(title.c_str(), title.size());
  FALCON_C_API_END(nullptr)
}

int HDF5Data_unique_id(HDF5DataHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to HDF5Data_unique_id");
  }
  HDF5Data* hdf5_data = static_cast<HDF5Data*>(handle);
  return hdf5_data->unique_id();
  FALCON_C_API_END(0)
}

int HDF5Data_timestamp(HDF5DataHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to HDF5Data_timestamp");
  }
  HDF5Data* hdf5_data = static_cast<HDF5Data*>(handle);
  return hdf5_data->timestamp();
  FALCON_C_API_END(0)
}

bool HDF5Data_equal(HDF5DataHandle handle, HDF5DataHandle other_handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_equals: handle");
  }
  if (!other_handle) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_equals: other_handle");
  }
  HDF5Data* hdf5_data       = static_cast<HDF5Data*>(handle);
  HDF5Data* other_hdf5_data = static_cast<HDF5Data*>(other_handle);
  return (*hdf5_data == *other_hdf5_data);
  FALCON_C_API_END(false)
}

bool HDF5Data_not_equal(HDF5DataHandle handle, HDF5DataHandle other_handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_not_equals: handle");
  }
  if (!other_handle) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_not_equals: other_handle");
  }
  HDF5Data* hdf5_data       = static_cast<HDF5Data*>(handle);
  HDF5Data* other_hdf5_data = static_cast<HDF5Data*>(other_handle);
  return (*hdf5_data != *other_hdf5_data);
  FALCON_C_API_END(false)
}
}
