#pragma once

#include <memory>
#include "falcon_core/instrument_interfaces/waveforms/BaseWaveform.hpp"
#include "falcon_core/math/discrete_spaces/BaseDiscreteSpace.hpp"

/**
 * @brief A distinct measurement waveform.
 */
namespace falcon_core {
namespace instrument_interfaces {
namespace waveforms {

class Waveform : public BaseWaveform<falcon_core::math::discrete_spaces::BaseDiscreteSpace> {
 public:
  using base_type = BaseWaveform<falcon_core::math::discrete_spaces::BaseDiscreteSpace>;

  Waveform(std::shared_ptr<base_type::space_type> space,
           std::vector<std::shared_ptr<port_transforms::PortTransform>> transforms = {})
      : base_type(space, transforms) {}

  Waveform() : base_type() {}

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<base_type>(this));
  }
};

}  // namespace waveforms
}  // namespace instrument_interfaces
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::waveforms::Waveform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::instrument_interfaces::waveforms::Waveform)
#endif
