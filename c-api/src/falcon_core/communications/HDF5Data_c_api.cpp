#include "falcon_core/communications/HDF5Data_c_api.h"

#include <falcon_core/generic/String_c_api.h>

#include <falcon_core/communications/HDF5Data.hpp>
#include <string>

using namespace falcon_core;
using namespace falcon_core::communications;

HDF5DataHandle HDF5Data_create(AxesIntHandle                   shape,
                               AxesControlArrayHandle          unit_domain,
                               AxesCoupledLabelledDomainHandle domain_labels,
                               LabelledArraysLabelledMeasuredArrayHandle ranges,
                               MapStringStringHandle metadata,
                               StringHandle          measurement_title,
                               int                   unique_id,
                               int                   timestamp) {
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
}

HDF5DataHandle HDF5Data_create_from_file(StringHandle path) {
  if (!path) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_create_from_file: path");
  }
  std::string path_str(path->raw, path->length);
  return new HDF5Data(*HDF5Data::from_file(path_str));
}

void HDF5Data_destroy(HDF5DataHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to HDF5Data_destroy");
  }
  delete static_cast<HDF5Data*>(handle);
}

void HDF5Data_to_file(HDF5DataHandle handle, StringHandle path) {
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
}

PairMeasurementResponseMeasurementRequestHandle HDF5Data_to_communications(
    HDF5DataHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_to_communications");
  }
  HDF5Data* hdf5_data = static_cast<HDF5Data*>(handle);
  auto      pair      = hdf5_data->to_communications();
  return new generic::Pair<messages::MeasurementResponse,
                           messages::MeasurementRequest>(pair.first,
                                                         pair.second);
}

bool HDF5Data_equal(HDF5DataHandle handle, HDF5DataHandle other) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to HDF5Data_equal: handle");
  }
  if (!other) {
    throw std::invalid_argument("Null handle passed to HDF5Data_equal: other");
  }
  HDF5Data* hdf5_data = static_cast<HDF5Data*>(handle);
  HDF5Data* odata     = static_cast<HDF5Data*>(other);
  return (*hdf5_data) == (*odata);
}

bool HDF5Data_not_equal(HDF5DataHandle handle, HDF5DataHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_not_equal: handle");
  }
  if (!other) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_not_equal: other");
  }
  HDF5Data* hdf5_data = static_cast<HDF5Data*>(handle);
  HDF5Data* odata     = static_cast<HDF5Data*>(other);
  return (*hdf5_data) != (*odata);
}

StringHandle HDF5Data_to_json_string(HDF5DataHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to HDF5Data_to_json_string");
  }
  HDF5Data*   hdf5_data = static_cast<HDF5Data*>(handle);
  std::string json_str  = hdf5_data->to_json_string();
  return String_create(json_str.c_str(), json_str.size());
}

HDF5DataHandle HDF5Data_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to HDF5Data_from_json_string");
  }
  std::string raw_json(json->raw);
  auto        ptr = HDF5Data::from_json_string<HDF5Data>(raw_json);
  return new HDF5Data(*ptr);
}
