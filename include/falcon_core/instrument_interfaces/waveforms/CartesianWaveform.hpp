#pragma once

#include "falcon_core/instrument_interfaces/waveforms/BaseWaveform.hpp"
#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace.hpp"

/**
 * @brief An ND measurement on a cartesian domain with any time-dependent
 * phenomena.
 */
namespace falcon_core::instrument_interfaces::waveforms {

class CartesianWaveform
    : public BaseWaveform<
          falcon_core::math::discrete_spaces::CartesianDiscreteSpace> {
 public:
  /**
   * @brief Construct a Cartesian Waveform.
   * @param space The cartesian measurement space.
   * @param transforms The port transforms.
   */
  CartesianWaveform(
      math::discrete_spaces::CartesianDiscreteSpaceSP       space,
      const generic::ListSP<port_transforms::PortTransform> transforms =
          std::make_shared<generic::List<port_transforms::PortTransform>>());

  /**
   * @brief Create a CartesianWaveform from raw deltas.
   * @param divisions The number of divisions along each axis.
   * @param axes The axes defining the cartesian space.
   * @param domain The base domain of the cartesian space.
   * @param transforms the transforms to apply to the waveform.
   * @param increasing if the array should increase following the domain or not.
   */
  static const std::shared_ptr<CartesianWaveform> from_divisions(
      const math::AxesSP<int>&                                  divisions,
      const math::AxesSP<math::domains::CoupledLabelledDomain>& axes,
      const math::AxesSP<generic::Map<std::string, bool>>&      increasing,
      const generic::ListSP<port_transforms::PortTransform>&    transforms =
          std::make_shared<generic::List<port_transforms::PortTransform>>(),
      const math::domains::DomainSP& domain =
          std::make_shared<math::domains::Domain>(0, 1));

  /**
   * @brief Create a CartesianWaveform with identity transforms.
   * @param divisions The number of divisions along each axis.
   * @param axes The axes defining the cartesian space.
   * @param domain The base domain of the cartesian space.
   * @param increasing if the array should increase following the domain or not.
   */
  static const std::shared_ptr<CartesianWaveform> setup_identity_everywhere(
      const math::AxesSP<int>&                                  divisions,
      const math::AxesSP<math::domains::CoupledLabelledDomain>& axes,
      const math::AxesSP<generic::Map<std::string, bool>>&      increasing,
      const math::domains::DomainSP&                            domain =
          std::make_shared<math::domains::Domain>(0, 1));

 protected:
  CartesianWaveform();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<
        BaseWaveform<math::discrete_spaces::CartesianDiscreteSpace>>(this));
  }
};
using CartesianWaveformSP = std::shared_ptr<CartesianWaveform>;
}  // namespace falcon_core::instrument_interfaces::waveforms
