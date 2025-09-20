#pragma once
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransforms.hpp"
#include "falcon_core/math/discrete_spaces/BaseDiscreteSpace.hpp"

/**
 * @brief Base class for a measurement waveform, consisting of a measurement
 * domain and any time-dependent phenomena.
 * @tparam T The discrete space type.
 */
namespace falcon_core::instrument_interfaces::waveforms {

template <typename T>
class BaseWaveform : public port_transforms::PortTransforms {
  static_assert(
      std::is_base_of<math::discrete_spaces::BaseDiscreteSpace, T>::value,
      "T must be derived from BaseDiscreteSpace");
  std::shared_ptr<T> _space;

 public:
  /**
   * @brief Construct a BaseWaveform.
   * @param space The measurement space.
   * @param transforms The port transforms.
   */
  BaseWaveform(
      const std::shared_ptr<T>                              space,
      const generic::ListSP<port_transforms::PortTransform> transforms =
          std::make_shared<generic::List<port_transforms::PortTransform>>())
      : port_transforms::PortTransforms(transforms), _space(std::move(space)) {
    confirm_knobs_match();
  }

  /**
   * @brief Get the measurement space.
   */
  const std::shared_ptr<T>& space() const { return _space; }

  /**
   * @brief Confirm that all function knobs are in the discrete space.
   * @throws std::runtime_error if any function knob is not in the discrete
   * space.
   */
  void confirm_knobs_match() const {
    names::PortsSP discreteKnobs;
    for (const math::domains::CoupledLabelledDomainSP& axis :
         _space->axes()->items()) {
      for (const names::InstrumentPortSP& knob : *axis->labels()) {
        discreteKnobs->push_back(knob);
      }
    }
    names::PortsSP functionKnobs;
    for (const port_transforms::PortTransformSP& transform : *transforms()) {
      functionKnobs->push_back(transform->port());
    }
    for (const names::InstrumentPortSP& knob : functionKnobs->items()) {
      if (!discreteKnobs->contains(knob)) {
        throw std::runtime_error("Function knob " + knob->default_name() +
                                 " not found in discrete space axes.");
      }
    }
  }

 protected:
  friend class cereal::access;
  BaseWaveform() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<port_transforms::PortTransforms>(this), _space);
  }
};
template <typename T>
using BaseWaveformSP = std::shared_ptr<BaseWaveform<T>>;
}  // namespace falcon_core::instrument_interfaces::waveforms
