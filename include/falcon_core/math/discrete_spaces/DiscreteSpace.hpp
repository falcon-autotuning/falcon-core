#pragma once

#include "falcon_core/generic/Map.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/math/UnitSpace.hpp"
#include "falcon_core/math/arrays/LabelledControlArray.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

class DiscreteSpace : public generic::Song {
  UnitSpaceSP                             _space;
  AxesSP<domains::CoupledLabelledDomain>  _axes;
  AxesSP<generic::Map<std::string, bool>> _increasing;

 public:
  /**
   * @brief Initialize the DiscreteSpace.
   * The order of the Knobs in teh axes are defined to line up with the space.
   * @param space the space taht the decirete values fill
   * @param axes the axes containing the discrete values.
   * @param increasing True if the axes are decreasing with the direction of the
   * domain or against.
   */
  DiscreteSpace(const UnitSpaceSP&                             space,
                const AxesSP<domains::CoupledLabelledDomain>&  axes,
                const AxesSP<generic::Map<std::string, bool>>& increasing);
  /**
   * @brief Create a ND cartesian discrete space.
   * @param divisions the number of divisions for each axis.
   * @param axes the domains for each axis.
   * @param increasing if each dimension is increasing with time or not.
   * @param domain the domain of the space.
   */
  static std::shared_ptr<DiscreteSpace> CartesianDiscreteSpace(
      const AxesSP<int>&                             divisions,
      const AxesSP<domains::CoupledLabelledDomain>&  axes,
      const AxesSP<generic::Map<std::string, bool>>& increasing,
      const domains::DomainSP&                       domain =
          std::make_shared<domains::Domain>(std::pair<double, double>(0, 1)));
  /**
   * @brief Create a ND cartesian discrete space.
   * @param divisions the number of divisions for each axis.
   * @param axes the domains for each axis.
   * @param increasing if each dimension is increasing with time or not.
   * @param domain the domain of the space.
   */
  static std::shared_ptr<DiscreteSpace> CartesianDiscreteSpace1D(
      const int&                               division,
      const domains::CoupledLabelledDomainSP&  shared_domain,
      const generic::MapSP<std::string, bool>& increasing,
      const domains::DomainSP&                 domain =
          std::make_shared<domains::Domain>(std::pair<double, double>(0, 1)));
  /**
   * @brief Return the stored UnitSpace.
   */
  const UnitSpaceSP& space() const;
  /**
   * @brief Return the stored axes.
   */
  const AxesSP<domains::CoupledLabelledDomain>& axes() const;
  /**
   * @brief Return the increasing properties.
   */
  const AxesSP<generic::Map<std::string, bool>>& increasing() const;
  /**
   * @brief Return the knobs.
   */
  const instrument_interfaces::names::PortsSP knobs() const;
  /**
   * @brief Validate that the unit space dimensionality matches the number of
   * knobs.
   */
  void validate_unit_space_dimensionality_matches_knobs() const;
  /**
   * @brief Validate that the knobs are unique.
   */
  void validate_knob_uniqueness() const;
  /**
   * @brief Return the index of the axis containing the given knob.
   * @param knob The knob to search for.
   * @return The index of the axis containing the knob.
   * @throws std::runtime_error if the knob is not found.
   */
  const int get_axis(
      const instrument_interfaces::names::InstrumentPortSP& knob) const;
  /**
   * @brief Return the domain of the given knob.
   * @param knob The knob to search for.
   * @return The domain of the knob.
   */
  const domains::DomainSP get_domain(
      const instrument_interfaces::names::InstrumentPortSP& knob) const;
  /**
   * @brief Return the projection of the unit space onto the given axes.
   * @param projection The axes to project onto.
   * @return The projection of th espace onto the given axes.
   */
  const AxesSP<arrays::LabelledControlArray> get_projection(
      const AxesSP<instrument_interfaces::names::InstrumentPort>& projection)
      const;
  bool operator==(const DiscreteSpace& other) const;
  bool operator!=(const DiscreteSpace& other) const;

 protected:
  DiscreteSpace();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _space, _axes, _increasing);
  }
};
using DiscreteSpaceSP = std::shared_ptr<DiscreteSpace>;
}  // namespace discrete_spaces
}  // namespace math
}  // namespace falcon_core
