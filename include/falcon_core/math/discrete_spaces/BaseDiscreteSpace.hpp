#pragma once

#include "falcon_core/generic/Map.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/math/arrays/LabelledControlArray.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"
#include "falcon_core/math/spaces/UnitSpace.hpp"

namespace falcon_core::math::discrete_spaces {

class BaseDiscreteSpace : public generic::Song {
  spaces::UnitSpaceSP                     _space;
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
  BaseDiscreteSpace(const spaces::UnitSpaceSP&                     space,
                    const AxesSP<domains::CoupledLabelledDomain>&  axes,
                    const AxesSP<generic::Map<std::string, bool>>& increasing);
  const spaces::UnitSpaceSP&                     space() const;
  const AxesSP<domains::CoupledLabelledDomain>&  axes() const;
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

 protected:
  BaseDiscreteSpace();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _space, _axes, _increasing);
  }
};
using BaseDiscreteSpaceSP = std::shared_ptr<BaseDiscreteSpace>;
}  // namespace falcon_core::math::discrete_spaces
