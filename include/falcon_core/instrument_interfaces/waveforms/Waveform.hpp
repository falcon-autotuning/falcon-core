#pragma once

#include "falcon_core/instrument_interfaces/waveforms/BaseWaveform.hpp"
#include "falcon_core/math/discrete_spaces/BaseDiscreteSpace.hpp"

/**
 * @brief A distinct measurement waveform.
 */
namespace falcon_core::instrument_interfaces::waveforms {

class Waveform : public BaseWaveform<
                     falcon_core::math::discrete_spaces::BaseDiscreteSpace> {
 public:
  /**
   * @brief Construct a Waveform.
   * @param space The measurement space.
   * @param transforms The port transforms.
   */
  Waveform(
      const math::discrete_spaces::BaseDiscreteSpaceSP      space,
      const generic::ListSP<port_transforms::PortTransform> transforms =
          std::make_shared<generic::List<port_transforms::PortTransform>>());

 protected:
  friend class cereal::access;
  Waveform();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<
        BaseWaveform<falcon_core::math::discrete_spaces::BaseDiscreteSpace>>(
        this));
  }
};

}  // namespace falcon_core::instrument_interfaces::waveforms
