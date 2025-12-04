#pragma once

#include <H5Cpp.h>

#include <boost/uuid/uuid.hpp>

#include "falcon_core/communications/messages/MeasurementRequest.hpp"
#include "falcon_core/communications/messages/MeasurementResponse.hpp"
#include "falcon_core/communications/voltage_states/DeviceVoltageStates.hpp"
#include "falcon_core/generic/Map.hpp"
#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/Axes.hpp"
#include "falcon_core/math/arrays/ControlArray.hpp"
#include "falcon_core/math/arrays/LabelledArrays.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"
namespace falcon_core {
namespace communications {
class HDF5Data : public generic::Song {
  using Metadata = generic::Map<std::string, std::string>;
  math::AxesSP<int>                                  _shape;
  math::AxesSP<math::arrays::ControlArray>           _unit_domain;
  math::AxesSP<math::domains::CoupledLabelledDomain> _domain_labels;
  math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray> _ranges;
  std::shared_ptr<Metadata>                                           _metadata;
  std::string                     _measurement_title;
  int                             _unique_id;
  int                             _timestamp;
  mutable std::shared_timed_mutex _mu_metadata;
  mutable std::shared_timed_mutex _mu_ranges;
  mutable std::shared_timed_mutex _mu_unit_domain;
  mutable std::shared_timed_mutex _mu_domain_labels;
  mutable std::shared_timed_mutex _mu_shape;
  mutable std::shared_timed_mutex _mu_measurement_title;
  mutable std::shared_timed_mutex _mu_unique_id;
  mutable std::shared_timed_mutex _mu_timestamp;

 protected:
  friend class cereal::access;
  HDF5Data();
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_m(_mu_metadata,
                                                     std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_r(_mu_ranges,
                                                     std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_ud(_mu_unit_domain,
                                                      std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_dl(_mu_domain_labels,
                                                      std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_s(_mu_shape,
                                                     std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_mt(_mu_measurement_title,
                                                      std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_uid(_mu_unique_id,
                                                       std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_ts(_mu_timestamp,
                                                      std::defer_lock);
    std::lock(
        lock_m, lock_r, lock_ud, lock_dl, lock_s, lock_mt, lock_uid, lock_ts);
    ar(cereal::base_class<generic::Song>(this),
       _shape,
       _unit_domain,
       _domain_labels,
       _ranges,
       _metadata,
       _unique_id,
       _measurement_title,
       _timestamp);
  }

 public:
  HDF5Data(const HDF5Data& other);
  HDF5Data& operator=(const HDF5Data& other);
  /**
   * @brief Construct the protable data for database storage.
   * @param shape The shape of the data array.
   * @param unit_domain The unit domain for each axis.
   * @param domain_labels The domain labels for each axis.
   * @param ranges The ranges for each axis.
   * @param metadata The metadata for the measurement.
   * @param measurement_title The title of the measurement.
   * @param unique_id A unique id for the measurement.
   * @param timestamp A timestamp for the measurement.
   */
  HDF5Data(
      const math::AxesSP<int>&                                  shape,
      const math::AxesSP<math::arrays::ControlArray>&           unit_domain,
      const math::AxesSP<math::domains::CoupledLabelledDomain>& domain_labels,
      const math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray>&
                                       ranges,
      const std::shared_ptr<Metadata>& metadata,
      const std::string&               measurement_title,
      const int&                       unique_id,
      const int&                       timestamp);
  /**
   * @brief Convert from a file to an HDF5Data object.
   * @param path The path to the HDF5 file.
   * @return A HDF5Data object.
   */
  static const std::shared_ptr<HDF5Data> from_file(const std::string& path);
  /**
   * @brief Load the data from a MeasurementResponse and MeasurementResponse.
   * @param request The MeasurementRequest from falcon.
   * @param response The MeasurementResponse from the instrument server.
   * @param device_votlage_states The current state of the device voltages.
   * @param session_id The name of the session from the instrument server.
   * @param measurement_title The title of the measurement.
   * @param unique_id A unique id for the measurement.
   * @param timestamp The time the measurement was taken.
   * @return A HDF5Data object.
   */
  static const std::shared_ptr<HDF5Data> from_communications(
      const messages::MeasurementRequestSP&        request,
      const messages::MeasurementResponseSP&       response,
      const voltage_states::DeviceVoltageStatesSP& device_voltage_states,
      const boost::uuids::uuid&                    session_id,
      const std::string&                           measurement_title,
      const int&                                   unique_id,
      const int&                                   timestamp);
  /**
   * @brief Convert from an HDF5Data object to a file.
   * @param path The path to write the HDF5 file at.
   */
  void to_file(const std::string& path) const;
  /**
   * @brief Get the shape of the data array.
   * @return The shape of the data array.
   */
  math::AxesSP<int> shape() const;
  /**
   * @brief Get the unit domain for each axis.
   * @return The unit domain for each axis.
   */
  math::AxesSP<math::arrays::ControlArray> unit_domain() const;
  /**
   * @brief Get the domain labels for each axis.
   * @return The domain labels for each axis.
   */
  math::AxesSP<math::domains::CoupledLabelledDomain> domain_labels() const;
  /**
   * @brief Get the ranges for each axis.
   * @return The ranges for each axis.
   */
  math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray> ranges()
      const;
  /**
   * @brief Get the metadata for the measurement.
   * @return The metadata for the measurement.
   */
  std::shared_ptr<Metadata> metadata() const;
  /**
   * @brief Get the measurement title.
   * @return The measurement title.
   */
  std::string measurement_title() const;
  /**
   * @brief Get the unique id for the measurement.
   * @return The unique id for the measurement.
   */
  int unique_id() const;
  /**
   * @brief Get the timestamp for the measurement.
   * @return The timestamp for the measurement.
   */
  int timestamp() const;
  /**
   * @brief Convert from an HDF5Data object to a MeasurementResponse and a
   * Metadata.
   * @return A pair of MeasurementResponse and MeasurementRequest.
   */
  const std::pair<communications::messages::MeasurementResponseSP,
                  communications::messages::MeasurementRequestSP>
  to_communications() const;

  bool operator==(const HDF5Data& other);
  bool operator!=(const HDF5Data& other);
};
using HDF5DataSP = std::shared_ptr<HDF5Data>;
}  // namespace communications
}  // namespace falcon_core
