#pragma once

#include "falcon_core/generic/Map.hpp"
#include "falcon_core/math/domains/CoupledKnobDomain.hpp"
#include "falcon_core/math/spaces/UnitSpace.hpp"

namespace falcon_core::math::discrete_spaces {

class BaseDiscreteSpace : public generic::Song {
  spaces::UnitSpaceSP                     _space;
  AxesSP<domains::CoupledKnobDomain>      _axes;
  AxesSP<generic::Map<std::string, bool>> _increasing;

 public:
  BaseDiscreteSpace(const spaces::UnitSpaceSP&                     space,
                    const AxesSP<domains::CoupledKnobDomain>&      axes,
                    const AxesSP<generic::Map<std::string, bool>>& increasing);
  const spaces::UnitSpaceSP&                     space() const;
  const AxesSP<domains::CoupledKnobDomain>&      axes() const;
  const AxesSP<generic::Map<std::string, bool>>& increasing() const;
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
  const int get_axis(const instrument_interfaces::names::KnobSP& knob) const;
  /**
   * @brief Return the domain of the given knob.
   * @param knob The knob to search for.
   * @return The domain of the knob.
   */
  const domains::DomainSP get_domain(
      const instrument_interfaces::names::KnobSP& knob) const;
  /**
   * @brief Return the projection of the unit space onto the given axes.
   * @param projection The axes to project onto.
   * @return The projection of th espace onto the given axes.
   */
  const AxesSP<double> get_projection(
      const AxesSP<instrument_interfaces::names::Knob>& projection) const;

 protected:
  BaseDiscreteSpace();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _space, _axes, _increasing);
  }
};

}  // namespace falcon_core::math::discrete_spaces
