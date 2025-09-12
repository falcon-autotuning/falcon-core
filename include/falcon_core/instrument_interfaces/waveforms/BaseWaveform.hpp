#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransforms.hpp"
#include "falcon_core/math/discrete_spaces/BaseDiscreteSpace.hpp"

/**
 * @brief Base class for a measurement waveform, consisting of a measurement
 * domain and any time-dependent phenomena.
 * @tparam T The discrete space type.
 */
namespace falcon_core {
namespace instrument_interfaces {
namespace waveforms {

template <typename T>
class BaseWaveform : public port_transforms::PortTransforms {
 public:
  using space_type = T;

  /**
   * @brief Construct a BaseWaveform.
   * @param space The measurement space.
   * @param transforms The port transforms.
   */
  BaseWaveform(std::shared_ptr<space_type> space,
               std::vector<std::shared_ptr<port_transforms::PortTransform>>
                   transforms = {})
      : port_transforms::PortTransforms(), _space(std::move(space)) {
    for (auto& t : transforms) this->append(t);
    confirm_knobs_match();
  }

  /**
   * @brief Default constructor for serialization.
   */
  BaseWaveform() : port_transforms::PortTransforms(), _space(nullptr) {}

  /**
   * @brief Get the measurement space.
   */
  const std::shared_ptr<space_type>& space() const { return _space; }

  /**
   * @brief Confirm that all function knobs are in the discrete space.
   * This should check that all transform ports are present in the space's axes.
   * (Implementation is a placeholder.)
   */
  void confirm_knobs_match() const {
    // TODO: Implement knob matching logic if space_type exposes axes/knobs.
    // Example:
    // std::set<KnobType> discrete_knobs = ...;
    // std::set<KnobType> function_knobs = ...;
    // assert(function_knobs ⊆ discrete_knobs);
  }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<port_transforms::PortTransforms>(this), _space);
  }

 protected:
  std::shared_ptr<space_type> _space;
};

}  // namespace waveforms
}  // namespace instrument_interfaces
}  // namespace falcon_core

#ifndef SWIG
// Example registration for a specific space type; add more as needed.
CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::waveforms::BaseWaveform<
        falcon_core::math::discrete_spaces::BaseDiscreteSpace>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::waveforms::BaseWaveform<
        falcon_core::math::discrete_spaces::BaseDiscreteSpace>)
#endif
