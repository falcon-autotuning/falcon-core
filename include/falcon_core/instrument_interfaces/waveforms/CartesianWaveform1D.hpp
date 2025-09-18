#pragma once

#include "falcon_core/instrument_interfaces/waveforms/BaseWaveform.hpp"
#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace1D.hpp"

/**
 * @brief A 1D measurement on a cartesian domain with any time-dependent
 * phenomena.
 */
namespace falcon_core::instrument_interfaces::waveforms {

class CartesianWaveform1D
    : public BaseWaveform<
          falcon_core::math::discrete_spaces::CartesianDiscreteSpace1D> {
 public:
  /**
   * @brief Construct a Cartesian Waveform.
   * @param space The cartesian measurement space.
   * @param transforms The port transforms.
   */
  CartesianWaveform1D(
      const math::discrete_spaces::CartesianDiscreteSpace1DSP& space,
      const generic::ListSP<port_transforms::PortTransform>&   transforms =
          std::make_shared<generic::List<port_transforms::PortTransform>>());

  /**
   * @brief Create a CartesianWaveform from raw deltas.
   * @param divisions The number of divisions along each axis.
   * @param axes The axes defining the cartesian space.
   * @param domain The base domain of the cartesian space.
   * @param transforms the transforms to apply to the waveform.
   * @param increasing if the array should increase following the domain or not.
   */
  static const std::shared_ptr<CartesianWaveform1D> from_division(
      const int&                                             division,
      const falcon_core::math::domains::CoupledKnobDomainSP& shared_domain,
      const generic::MapSP<std::string, bool>&               increasing,
      const generic::ListSP<port_transforms::PortTransform>& transforms =
          std::make_shared<generic::List<port_transforms::PortTransform>>(),
      const falcon_core::math::domains::DomainSP& domain =
          std::make_shared<falcon_core::math::domains::Domain>(0, 1));

  /**
   * @brief Create a CartesianWaveform with identity transforms.
   * @param divisions The number of divisions along each axis.
   * @param axes The axes defining the cartesian space.
   * @param domain The base domain of the cartesian space.
   * @param increasing if the array should increase following the domain or not.
   */
  static const std::shared_ptr<CartesianWaveform1D> setup_identity_everywhere(
      const int&                                             division,
      const falcon_core::math::domains::CoupledKnobDomainSP& shared_domain,
      const generic::MapSP<std::string, bool>&               increasing,
      const falcon_core::math::domains::DomainSP&            domain =
          std::make_shared<falcon_core::math::domains::Domain>(0, 1));

 protected:
  CartesianWaveform1D();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<
        BaseWaveform<math::discrete_spaces::CartesianDiscreteSpace1D>>(this));
  }
};
using CartesianWaveform1DSP = std::shared_ptr<CartesianWaveform1D>;
}  // namespace falcon_core::instrument_interfaces::waveforms
