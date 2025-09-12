#include "falcon_core/communications/hdf5/HDF5Data.hpp"

namespace falcon_core::communications::hdf5 {
HDF5Data::HDF5Data() = default;
HDF5Data::HDF5Data(const AxesSP<int>&                            shape,
                   const AxesSP<math::arrays::ControlArray>&     unit_domain,
                   const AxesSP<CoupledKnobDomain>&              domain_labels,
                   const math::arrays::LabelledMeasuredArraysSP& ranges,
                   const std::shared_ptr<HDF5Data::Metadata>&    metadata,
                   const std::string measurement_title,
                   const int         unique_id,
                   const int         timestamp)
    : _unique_id(unique_id),
      _measurement_title(measurement_title),
      _timestamp(timestamp),
      _metadata(metadata) {
  // Dimensions
  for (size_t i = 0; i < shape->size(); ++i) {
    _dimensions->insert("dim" + std::to_string(i), (*shape)[i]);
  }

  // Domains
  for (size_t i = 0; i < shape->size(); ++i) {
    std::map<std::string, std::map<std::string, double>> labels;
    for (const auto& domain : (*domain_labels)[i]->domains()) {
      std::string label_key = domain->label()->_pseudo_name
                                  ? domain->label()->_pseudo_name->name()
                                  : domain->label()->instrument_type();
      labels[label_key]     = {
          {"unit", domain->label()->units()->symbol()},
          {"start", static_cast<double>(domain->domain.bounds[0])},
          {"stop", static_cast<double>(domain->domain.bounds[1])}};
    }
    std::ostringstream data_stream;
    const auto&        arr = (*unit_domain)[i].data;
    for (size_t j = 0; j < arr.size(); ++j) {
      if (j > 0) data_stream << ",";
      data_stream << arr[j];
    }
    _domains["dim" + std::to_string(i)] = {{"labels", labels},
                                           {"data", data_stream.str()}};
  }

  // Ranges
  for (const auto& range : ranges->arrays()) {
    std::string        key = range->connection() ? range->connection()->name()
                                                 : range->instrument_type();
    std::ostringstream data_stream;
    const auto&        arr = range->data();
    for (size_t j = 0; j < arr.size(); ++j) {
      if (j > 0) data_stream << ",";
      data_stream << arr[j];
    }
    _ranges[key] = {{"unit", range.units.symbol}, {"data", data_stream.str()}};
  }
}
const std::shared_ptr<HDF5Data> HDF5Data::from_file(const std::string& path);
const std::shared_ptr<HDF5Data> HDF5Data::from_communications(
    const messages::MeasurementResponseSP&     request,
    const messages::MeasurementResponse&       response,
    const voltage_states::DeviceVoltageStates& device_voltage_states,
    const boost::uuids::uuid&                  session_id,
    const std::string&                         measurement_title,
    const int                                  unique_id,
    const int                                  timestamp);
void HDF5Data::to_file(const std::string& path) const;
const std::pair<math::arrays::LabelledMeasuredArraysSP, HDF5Data::Metadata>
HDF5Data::to_communications() const;
}  // namespace falcon_core::communications::hdf5

CEREAL_REGISTER_TYPE(falcon_core::communications::hdf5::HDF5Data)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::communications::hdf5::HDF5Data)
