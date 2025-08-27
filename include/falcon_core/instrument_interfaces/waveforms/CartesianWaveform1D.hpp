#pragma once

#include <memory>

#include "falcon_core/instrument_interfaces/waveforms/BaseWaveform.hpp"
#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace1D.hpp"

/**
 * @brief A 1D measurement on a cartesian domain with any time-dependent
 * phenomena.
 */
namespace falcon_core {
namespace instrument_interfaces {
namespace waveforms {

class CartesianWaveform1D
    : public BaseWaveform<
          falcon_core::math::discrete_spaces::CartesianDiscreteSpace1D> {
 public:
  using space_type =
      falcon_core::math::discrete_spaces::CartesianDiscreteSpace1D;
  using base_type = BaseWaveform<space_type>;

  CartesianWaveform1D(
      std::shared_ptr<space_type>                                  space,
      std::vector<std::shared_ptr<port_transforms::PortTransform>> transforms =
          {})
      : base_type(space, transforms) {}

  CartesianWaveform1D() : base_type() {}

  /**
   * @brief Create a CartesianWaveform1D from raw division.
   */
  static std::shared_ptr<CartesianWaveform1D> from_division(
      int division,
      std::shared_ptr<falcon_core::math::domains::CoupledKnobDomain>
          shared_domain,
      std::shared_ptr<falcon_core::math::Axes<std::map<std::string, bool>>>
                                                                   increasing,
      std::vector<std::shared_ptr<port_transforms::PortTransform>> transforms =
          {},
      std::shared_ptr<falcon_core::math::domains::Domain> domain =
          std::make_shared<falcon_core::math::domains::Domain>(0, 1)) {
    auto space = space_type::from_division(division, shared_domain, domain);
    return std::make_shared<CartesianWaveform1D>(space, transforms);
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
    falcon_core::instrument_interfaces::waveforms::CartesianWaveform1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::waveforms::CartesianWaveform1D)
#endif
