#pragma once

#include "falcon_core/instrument_interfaces/waveforms/BaseWaveform.hpp"
#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace.hpp"

/**
 * @brief A 2D measurement on a cartesian domain with any time-dependent
 * phenomena.
 */
namespace falcon_core {
namespace instrument_interfaces {
namespace waveforms {

class CartesianWaveform2D
    : public BaseWaveform<
          falcon_core::math::discrete_spaces::CartesianDiscreteSpace> {
 public:
  using space_type = falcon_core::math::discrete_spaces::CartesianDiscreteSpace;
  using base_type  = BaseWaveform<space_type>;

  CartesianWaveform2D(
      std::shared_ptr<space_type>                     space,
      generic::ListSP<port_transforms::PortTransform> transforms = {})
      : base_type(space, transforms) {}

  CartesianWaveform2D() : base_type() {}

  /**
   * @brief Create a CartesianWaveform2D from raw divisions.
   */
  static const std::shared_ptr<CartesianWaveform2D> from_divisions(
      const math::AxesSP<int>&                                  divisions,
      const math::AxesSP<math::domains::CoupledLabelledDomain>& axes,
      const math::AxesSP<generic::Map<std::string, bool>>&      increasing,
      const generic::ListSP<port_transforms::PortTransform>&    transforms =
          std::make_shared<generic::List<port_transforms::PortTransform>>(),
      const math::domains::DomainSP& domain =
          std::make_shared<math::domains::Domain>(0, 1)) {
    auto space =
        space_type::from_divisions(divisions, axes, increasing, domain);
    return std::make_shared<CartesianWaveform2D>(space, transforms);
  }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<base_type>(this));
  }
};

}  // namespace waveforms
}  // namespace instrument_interfaces
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::waveforms::CartesianWaveform2D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::waveforms::CartesianWaveform2D)
#endif
