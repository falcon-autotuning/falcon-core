#include "falcon_core/communications/HDF5Data.hpp"

#include <H5Attribute.h>

#include <boost/uuid.hpp>
#include <xtensor-io/xhighfive.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/communications/messages/MeasurementResponse.hpp"
#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/instrument_interfaces/Waveform.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"

namespace falcon_core {
namespace communications {
HDF5Data::HDF5Data(const HDF5Data& other) {
  std::unique_lock<std::shared_timed_mutex> lock_metadata(_mu_metadata,
                                                          std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_shape(_mu_shape,
                                                       std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_unit_domain(_mu_unit_domain,
                                                             std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_domain_labels(
      _mu_domain_labels, std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_ranges(_mu_ranges,
                                                        std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_measurement_title(
      _mu_measurement_title, std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_unique_id(_mu_unique_id,
                                                           std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_timestamp(_mu_timestamp,
                                                           std::defer_lock);
  std::lock(lock_metadata,
            lock_shape,
            lock_unit_domain,
            lock_domain_labels,
            lock_ranges,
            lock_measurement_title,
            lock_unique_id,
            lock_timestamp);
  if (!other.metadata() || !other.shape() || !other.unit_domain() ||
      !other.domain_labels() || !other.ranges()) {
    throw std::invalid_argument(
        "HDF5Data copy constructor: Other HDF5Data contains null shared "
        "pointers.");
  }
  _metadata    = std::make_shared<Metadata>(*other.metadata());
  _shape       = std::make_shared<math::Axes<int>>(*other.shape());
  _unit_domain = std::make_shared<math::Axes<math::arrays::ControlArray>>(
      *other.unit_domain());
  _domain_labels =
      std::make_shared<math::Axes<math::domains::CoupledLabelledDomain>>(
          *other.domain_labels());
  _ranges = std::make_shared<
      math::arrays::LabelledArrays<math::arrays::LabelledMeasuredArray>>(
      *other.ranges());
  _measurement_title = other.measurement_title();
  _unique_id         = other.unique_id();
  _timestamp         = other.timestamp();
}
HDF5Data& HDF5Data::operator=(const HDF5Data& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_metadata(_mu_metadata,
                                                            std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_shape(_mu_shape,
                                                         std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_unit_domain(_mu_unit_domain,
                                                               std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_domain_labels(
        _mu_domain_labels, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_ranges(_mu_ranges,
                                                          std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_measurement_title(
        _mu_measurement_title, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_unique_id(_mu_unique_id,
                                                             std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_timestamp(_mu_timestamp,
                                                             std::defer_lock);
    std::lock(lock_metadata,
              lock_shape,
              lock_unit_domain,
              lock_domain_labels,
              lock_ranges,
              lock_measurement_title,
              lock_unique_id,
              lock_timestamp);
    if (!other.metadata() || !other.shape() || !other.unit_domain() ||
        !other.domain_labels() || !other.ranges()) {
      throw std::invalid_argument(
          "HDF5Data copy constructor: Other HDF5Data contains null shared "
          "pointers.");
    }
    _metadata    = std::make_shared<Metadata>(*other.metadata());
    _shape       = std::make_shared<math::Axes<int>>(*other.shape());
    _unit_domain = std::make_shared<math::Axes<math::arrays::ControlArray>>(
        *other.unit_domain());
    _domain_labels =
        std::make_shared<math::Axes<math::domains::CoupledLabelledDomain>>(
            *other.domain_labels());
    _ranges = std::make_shared<
        math::arrays::LabelledArrays<math::arrays::LabelledMeasuredArray>>(
        *other.ranges());
    _measurement_title = other.measurement_title();
    _unique_id         = other.unique_id();
    _timestamp         = other.timestamp();
  }
  return *this;
}
HDF5Data::HDF5Data() = default;
HDF5Data::HDF5Data(
    const math::AxesSP<int>&                                  shape,
    const math::AxesSP<math::arrays::ControlArray>&           unit_domain,
    const math::AxesSP<math::domains::CoupledLabelledDomain>& domain_labels,
    const math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray>&
                                     ranges,
    const std::shared_ptr<Metadata>& metadata,
    const std::string&               measurement_title,
    const int&                       unique_id,
    const int&                       timestamp)
    : _shape(shape),
      _unit_domain(unit_domain),
      _domain_labels(domain_labels),
      _ranges(ranges),
      _metadata(metadata),
      _measurement_title(measurement_title),
      _unique_id(unique_id),
      _timestamp(timestamp) {}
math::AxesSP<int> HDF5Data::shape() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_shape);
  return _shape;
}
math::AxesSP<math::arrays::ControlArray> HDF5Data::unit_domain() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_unit_domain);
  return _unit_domain;
}
math::AxesSP<math::domains::CoupledLabelledDomain> HDF5Data::domain_labels()
    const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_domain_labels);
  return _domain_labels;
}
math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray>
HDF5Data::ranges() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_ranges);
  return _ranges;
}
std::shared_ptr<HDF5Data::Metadata> HDF5Data::metadata() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_metadata);
  return _metadata;
}
std::string HDF5Data::measurement_title() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_measurement_title);
  return _measurement_title;
}
int HDF5Data::unique_id() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_unique_id);
  return _unique_id;
}
int HDF5Data::timestamp() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_timestamp);
  return _timestamp;
}

void HDF5Data::to_file(const std::string& path) const {
  H5::H5File file(path, H5F_ACC_TRUNC);

  // Dimensions
  H5::Group dimensions_group = file.createGroup("/dimensions");
  for (size_t i = 0; i < shape()->size(); ++i) {
    std::string   dim_name = "dim" + std::to_string(i);
    int64_t       value    = static_cast<int64_t>((*shape())[i]);
    hsize_t       dims[1]  = {1};
    H5::DataSpace dataspace(1, dims);
    H5::DataSet   dataset = dimensions_group.createDataSet(
        dim_name, H5::PredType::NATIVE_INT64, dataspace);
    dataset.write(&value, H5::PredType::NATIVE_INT64);
  }

  // Domains
  H5::Group              domains_group = file.createGroup("/domains");
  std::vector<H5::Group> sub_domains;
  for (size_t i = 0; i < shape()->size(); ++i) {
    std::string dim_name         = "dim" + std::to_string(i);
    H5::Group   sub_domain_group = domains_group.createGroup(dim_name);

    // Data
    const auto& arr          = (*unit_domain())[i] -> data();
    std::string dataset_path = "/domains/dim" + std::to_string(i) + "/data";
    xt::dump_hdf5(file.getFileName(), dataset_path, arr);
    // prepare string dataspace/type for labels
    hsize_t       data_dims[1] = {1};
    H5::DataSpace data_space(1, data_dims);
    H5::StrType   str_type(H5::PredType::C_S1, H5T_VARIABLE);

    // Labels
    const auto& domains   = (*domain_labels())[i] -> domains();
    size_t      label_idx = 0;
    for (const auto& domain : domains) {
      std::string label_name = domain->port()->instrument_facing_name();
      H5::Group   label_group =
          sub_domain_group.createGroup("label" + std::to_string(label_idx));
      // label
      H5::DataSet label_ds =
          label_group.createDataSet("label", str_type, data_space);
      label_ds.write(label_name, str_type);
      // instrument
      std::string instrument = domain->port()->instrument_type();
      H5::DataSet ins_name_ds =
          label_group.createDataSet("instrument_type", str_type, data_space);
      ins_name_ds.write(instrument, str_type);
      // unit
      std::string unit = domain->port()->units()->symbol();
      H5::DataSet unit_ds =
          label_group.createDataSet("unit", str_type, data_space);
      unit_ds.write(unit, str_type);
      // start
      double      start    = static_cast<double>(domain->bounds().first);
      H5::DataSet start_ds = label_group.createDataSet(
          "start", H5::PredType::NATIVE_DOUBLE, data_space);
      start_ds.write(&start, H5::PredType::NATIVE_DOUBLE);
      // stop
      double      stop    = static_cast<double>(domain->bounds().second);
      H5::DataSet stop_ds = label_group.createDataSet(
          "stop", H5::PredType::NATIVE_DOUBLE, data_space);
      stop_ds.write(&stop, H5::PredType::NATIVE_DOUBLE);
      // knob
      std::string knob = domain->port()->to_json_string();
      H5::DataSet knob_ds =
          label_group.createDataSet("knob", str_type, data_space);
      knob_ds.write(knob, str_type);

      ++label_idx;
    }
    sub_domains.push_back(sub_domain_group);
  }

  // Ranges
  H5::Group ranges_group = file.createGroup("/ranges");
  size_t    range_idx    = 0;
  for (const math::arrays::LabelledMeasuredArraySP& range :
       ranges()->arrays()) {
    std::string key = range->connection() ? range->connection()->name()
                                          : range->instrument_type();
    const auto& arr = range->data();
    std::string dataset_path =
        "/ranges/range" + std::to_string(range_idx) + "/data";
    xt::dump_hdf5(file.getFileName(), dataset_path, arr);
    H5::DataSet range_ds =
        ranges_group.openDataSet("range" + std::to_string(range_idx) + "/data");

    hsize_t       data_dims[1] = {1};
    H5::DataSpace data_space(1, data_dims);
    H5::StrType   str_type(H5::PredType::C_S1, H5T_VARIABLE);
    H5::DataSpace attr_dataspace(H5S_SCALAR);
    H5::Attribute label_attr =
        range_ds.createAttribute("label", str_type, data_space);
    label_attr.write(str_type, key);
    std::string   unit = range->units()->symbol();
    H5::Attribute unit_attr =
        range_ds.createAttribute("unit", str_type, data_space);
    unit_attr.write(str_type, unit);
    std::string   context = range->label()->to_json_string();
    H5::Attribute context_attr =
        range_ds.createAttribute("context", str_type, data_space);
    context_attr.write(str_type, context);
    ++range_idx;
  }

  // Metadata
  H5::Group   metadata_group = file.createGroup("/metadata");
  H5::StrType str_type(H5::PredType::C_S1, H5T_VARIABLE);
  for (const auto& pair : *metadata()) {
    hsize_t       md_dims[1] = {1};
    H5::DataSpace md_space(1, md_dims);
    H5::DataSet   md_ds =
        metadata_group.createDataSet(pair->first(), str_type, md_space);
    md_ds.write(pair->second(), str_type);
  }
  H5::Attribute timestamp_attr = metadata_group.createAttribute(
      "timestamp", H5::PredType::NATIVE_INT, H5::DataSpace());
  int tsamp = timestamp();
  timestamp_attr.write(H5::PredType::NATIVE_INT, &tsamp);
  H5::Attribute unique_id_attr = metadata_group.createAttribute(
      "unique_id", H5::PredType::NATIVE_INT, H5::DataSpace());
  int uid = unique_id();
  unique_id_attr.write(H5::PredType::NATIVE_INT, &uid);
  H5::Attribute measurement_title_attr = metadata_group.createAttribute(
      "measurement_title", str_type, H5::DataSpace());
  measurement_title_attr.write(str_type, _measurement_title);
}

const std::shared_ptr<HDF5Data> HDF5Data::from_file(const std::string& path) {
  H5::H5File file(path, H5F_ACC_RDONLY);

  // Dimensions
  H5::Group        dimensions_group = file.openGroup("/dimensions");
  std::vector<int> shape;
  hsize_t          num_dims = dimensions_group.getNumObjs();
  for (hsize_t i = 0; i < num_dims; ++i) {
    std::string dim_name = dimensions_group.getObjnameByIdx(i);
    H5::DataSet ds       = dimensions_group.openDataSet(dim_name);
    int64_t     value;
    ds.read(&value, H5::PredType::NATIVE_INT64);
    shape.push_back(value);
  }
  auto shape_axes = std::make_shared<math::Axes<int>>(shape);

  // Domains
  H5::Group domains_group = file.openGroup("/domains");
  std::vector<math::arrays::ControlArraySP>           unit_domain_vec;
  std::vector<math::domains::CoupledLabelledDomainSP> domain_labels_vec;
  hsize_t     num_domains = domains_group.getNumObjs();
  H5::StrType str_type(H5::PredType::C_S1, H5T_VARIABLE);
  for (hsize_t i = 0; i < num_domains; ++i) {
    std::string dim_name     = domains_group.getObjnameByIdx(i);
    std::string dataset_path = "/domains/" + dim_name + "/data";
    // Use xtensor-io to load the array

    xt::xarray<double> arr =
        xt::load_hdf5<xt::xarray<double>>(path, dataset_path);
    // Construct your ControlArray from xtensor (adapt to your API)
    math::arrays::ControlArraySP control_array =
        std::make_shared<math::arrays::ControlArray>(arr);
    unit_domain_vec.push_back(control_array);

    // Labels
    std::vector<math::domains::LabelledDomainSP> labels_vec;
    H5::Group sub_domain_group = domains_group.openGroup(dim_name);
    hsize_t   num_labels = sub_domain_group.getNumObjs() - 1;  // minus "data"
    for (hsize_t j = 0; j < num_labels; ++j) {
      std::string label_name  = "label" + std::to_string(j);
      H5::Group   label_group = sub_domain_group.openGroup(label_name);

      // label
      H5::DataSet knob_ds = label_group.openDataSet("knob");
      std::string rawKnob;
      knob_ds.read(rawKnob, str_type);

      // start
      H5::DataSet start_ds = label_group.openDataSet("start");
      double      start;
      start_ds.read(&start, H5::PredType::NATIVE_DOUBLE);

      // stop
      H5::DataSet stop_ds = label_group.openDataSet("stop");
      double      stop;
      stop_ds.read(&stop, H5::PredType::NATIVE_DOUBLE);

      // Construct DomainLabel (implement this for your type)
      instrument_interfaces::names::InstrumentPortSP knob =
          instrument_interfaces::names::InstrumentPort::from_json_string<
              instrument_interfaces::names::InstrumentPort>(rawKnob);
      auto domain_label = math::domains::LabelledDomain::from_port(
          std::make_pair(start, stop), knob);

      labels_vec.push_back(domain_label);
    }
    // Construct CoupledKnobDomain (implement this for your type)
    auto coupled_domain =
        std::make_shared<math::domains::CoupledLabelledDomain>(labels_vec);
    domain_labels_vec.push_back(coupled_domain);
  }
  auto unit_domain_axes =
      std::make_shared<math::Axes<math::arrays::ControlArray>>(unit_domain_vec);
  auto domain_labels_axes =
      std::make_shared<math::Axes<math::domains::CoupledLabelledDomain>>(
          domain_labels_vec);

  // Ranges
  H5::Group ranges_group = file.openGroup("/ranges");
  std::vector<math::arrays::LabelledMeasuredArraySP> ranges_vec;
  hsize_t num_ranges = ranges_group.getNumObjs();
  for (hsize_t i = 0; i < num_ranges; ++i) {
    std::string range_name   = "range" + std::to_string(i);
    std::string dataset_path = "/ranges/" + range_name + "/data";
    // Load the array from HDF5
    generic::FArraySP<double> arr = std::make_shared<generic::FArray<double>>(
        xt::load_hdf5<xt::xarray<double>>(path, dataset_path));

    // Read attributes
    H5::DataSet   range_ds = ranges_group.openDataSet(range_name + "/data");
    H5::StrType   str_type(H5::PredType::C_S1, H5T_VARIABLE);
    H5::Attribute label_attr = range_ds.openAttribute("label");
    std::string   label;
    label_attr.read(str_type, label);
    H5::Attribute unit_attr = range_ds.openAttribute("unit");
    std::string   unit;
    unit_attr.read(str_type, unit);
    H5::Attribute context_attr = range_ds.openAttribute("context");
    std::string   rawContext;
    context_attr.read(str_type, rawContext);
    autotuner_interfaces::contexts::AcquisitionContextSP context =
        autotuner_interfaces::contexts::AcquisitionContext::from_json_string<
            autotuner_interfaces::contexts::AcquisitionContext>(rawContext);

    // Construct LabelledMeasuredArray from xtensor array
    math::arrays::LabelledMeasuredArraySP measured_array =
        std::make_shared<math::arrays::LabelledMeasuredArray>(arr, context);
    ranges_vec.push_back(measured_array);
  }
  math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray> ranges =
      std::make_shared<
          math::arrays::LabelledArrays<math::arrays::LabelledMeasuredArray>>(
          ranges_vec);

  // Metadata
  H5::Group     metadata_group = file.openGroup("/metadata");
  int           timestamp, unique_id;
  std::string   measurement_title;
  H5::Attribute timestamp_attr = metadata_group.openAttribute("timestamp");
  timestamp_attr.read(H5::PredType::NATIVE_INT, &timestamp);
  H5::Attribute unique_id_attr = metadata_group.openAttribute("unique_id");
  unique_id_attr.read(H5::PredType::NATIVE_INT, &unique_id);
  H5::Attribute title_attr = metadata_group.openAttribute("measurement_title");
  title_attr.read(str_type, measurement_title);

  std::vector<std::pair<std::string, std::string>> metadata_map;
  hsize_t num_md = metadata_group.getNumObjs();
  for (hsize_t i = 0; i < num_md; ++i) {
    std::string key   = metadata_group.getObjnameByIdx(i);
    H5::DataSet md_ds = metadata_group.openDataSet(key);
    std::string value;
    md_ds.read(value, str_type);
    metadata_map.emplace_back(std::move(key), std::move(value));
  }
  auto metadata = std::make_shared<HDF5Data::Metadata>(metadata_map);

  return std::make_shared<HDF5Data>(shape_axes,
                                    unit_domain_axes,
                                    domain_labels_axes,
                                    ranges,
                                    metadata,
                                    measurement_title,
                                    unique_id,
                                    timestamp);
}
const std::shared_ptr<HDF5Data> HDF5Data::from_communications(
    const messages::MeasurementRequestSP&        request,
    const messages::MeasurementResponseSP&       response,
    const voltage_states::DeviceVoltageStatesSP& device_voltage_states,
    const boost::uuids::uuid&                    session_id,
    const std::string&                           measurement_title,
    const int&                                   unique_id,
    const int&                                   timestamp) {
  // Compile all waveforms in the request
  generic::List<instrument_interfaces::Waveform> waveforms =
      *request->waveforms();
  for (const instrument_interfaces::WaveformSP& wave : waveforms) {
    wave->space()->space()->compile();
  }

  // Find a valid waveform
  instrument_interfaces::WaveformSP valid_waveform;
  for (const instrument_interfaces::WaveformSP& waveform : waveforms) {
    // std::cout
    //     << std::string("The space shape is ") +
    //            std::to_string(waveform->space()->space()->space()->shape()[0])
    //            +
    //            "," +
    //            std::to_string(waveform->space()->space()->space()->shape()[1])
    //     << std::endl;
    // std::cout << std::string("The axes size is ") +
    //                  std::to_string(waveform->space()->axes()->size())
    //           << std::endl;
    if (waveform->space()->space()->space()->shape()[1] ==
        waveform->space()->axes()->size()) {
      valid_waveform = waveform;
      goto found_waveform;
    }
  }
  throw std::runtime_error("No valid waveform found in request.");
found_waveform:

  // Build axes
  int              count = valid_waveform->space()->axes()->size();
  std::vector<int> axes_vec(count);
  std::iota(axes_vec.begin(), axes_vec.end(), 0);
  math::AxesSP<int> axes = std::make_shared<math::Axes<int>>(axes_vec);

  // Build unit_domain
  math::AxesSP<math::arrays::ControlArray> unit_domain =
      valid_waveform->space()->space()->create_array(axes);

  // Build shape
  const auto&      shape_sz = unit_domain->at(0)->shape();
  std::vector<int> shape(shape_sz.begin(), shape_sz.end());
  auto             shape_axes = std::make_shared<math::Axes<int>>(shape);

  // Domain labels
  auto domain_labels = valid_waveform->space()->axes();

  // Ranges from response
  auto ranges = response->arrays();

  // Metadata
  // TODO: remove internal stored compiled wavefrom to reduce hdf5 file size
  auto metadata = std::make_shared<HDF5Data::Metadata>(
      std::vector<std::pair<std::string, std::string>>{
          {"song_request", request->to_json_string()},
          {"song_response", response->to_json_string()},
          {"device_voltage_states", device_voltage_states->to_json_string()},
          {"session_id", boost::uuids::to_string(session_id)}});

  return std::make_shared<HDF5Data>(shape_axes,
                                    unit_domain,
                                    domain_labels,
                                    ranges,
                                    metadata,
                                    measurement_title,
                                    unique_id,
                                    timestamp);
}
// TODO: add in internal stored compiled wavefrom to reduce hdf5 file size
const std::pair<communications::messages::MeasurementResponseSP,
                communications::messages::MeasurementRequestSP>
HDF5Data::to_communications() const {
  std::shared_lock<std::shared_timed_mutex> lock_a_metadata(_mu_metadata);
  messages::MeasurementResponseSP           response =
      messages::MeasurementResponse::from_json_string<
          messages::MeasurementResponse>(
          std::string(_metadata->at("song_response")));
  messages::MeasurementRequestSP request =
      messages::MeasurementRequest::from_json_string<
          messages::MeasurementRequest>(
          std::string(_metadata->at("song_request")));
  return std::make_pair(response, request);
}
bool HDF5Data::operator==(const HDF5Data& other) {
  return (*shape() == *other.shape() &&
          *unit_domain() == *other.unit_domain() &&
          *domain_labels() == *other.domain_labels() &&
          *ranges() == *other.ranges() && *metadata() == *other.metadata() &&
          measurement_title() == other.measurement_title() &&
          unique_id() == other.unique_id() && timestamp() == other.timestamp());
}
bool HDF5Data::operator!=(const HDF5Data& other) { return !(*this == other); }
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::communications::HDF5Data)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::communications::HDF5Data)
