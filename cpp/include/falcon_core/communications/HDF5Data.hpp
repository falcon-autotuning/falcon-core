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
  std::string _measurement_title;
  int         _unique_id;
  int         _timestamp;

 protected:
  friend class cereal::access;
  HDF5Data();
  template <class Archive>
  void serialize(Archive& ar) {
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
   * @brief Convert from an HDF5Data object to a MeasurementResponse and a
   * Metadata.
   * @return A pair of MeasurementResponse and MeasurementRequest.
   */
  const std::pair<communications::messages::MeasurementResponseSP,
                  communications::messages::MeasurementRequestSP>
  to_communications() const;
};
using HDF5DataSP = std::shared_ptr<HDF5Data>;
}  // namespace communications
}  // namespace falcon_core
