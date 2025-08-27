#pragma once

#include <memory>
#include "falcon_core/instrument_interfaces/waveforms/BaseWaveform.hpp"
#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace.hpp"

/**
 * @brief An ND measurement on a cartesian domain with any time-dependent phenomena.
 */
namespace falcon_core {
namespace instrument_interfaces {
namespace waveforms {

class CartesianWaveform : public BaseWaveform<falcon_core::math::discrete_spaces::CartesianDiscreteSpace> {
 public:
  using space_type = falcon_core::math::discrete_spaces::CartesianDiscreteSpace;
  using base_type = BaseWaveform<space_type>;

  CartesianWaveform(std::shared_ptr<space_type> space,
                    std::vector<std::shared_ptr<port_transforms::PortTransform>> transforms = {})
      : base_type(space, transforms) {}

  CartesianWaveform() : base_type() {}

  /**
   * @brief Create a CartesianWaveform from raw divisions.
   */
  static std::shared_ptr<CartesianWaveform> from_divisions(
      std::shared_ptr<falcon_core::math::Axes<int>> divisions,
      std::shared_ptr<falcon_core::math::Axes<std::shared_ptr<falcon_core::math::domains::Domain>>> axes,
      std::shared_ptr<falcon_core::math::Axes<std::map<std::string, bool>>> increasing,
      std::vector<std::shared_ptr<port_transforms::PortTransform>> transforms = {},
      std::shared_ptr<falcon_core::math::domains::Domain> domain = std::make_shared<falcon_core::math::domains::Domain>(0, 1)) {
    auto space = space_type::from_divisions(divisions, axes, domain, increasing);
    return std::make_shared<CartesianWaveform>(space, transforms);
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
CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::waveforms::CartesianWaveform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::instrument_interfaces::waveforms::CartesianWaveform)
#endif
