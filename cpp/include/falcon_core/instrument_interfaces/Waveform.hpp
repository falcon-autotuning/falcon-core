#pragma once
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransforms.hpp"
#include "falcon_core/math/discrete_spaces/DiscreteSpace.hpp"

/**
 * @brief Base class for a measurement waveform, consisting of a measurement
 * domain and any time-dependent phenomena.
 * @tparam T The discrete space type.
 */
namespace falcon_core {
namespace instrument_interfaces {

class Waveform : public port_transforms::PortTransforms {
  math::discrete_spaces::DiscreteSpaceSP _space;

 public:
  /**
   * @brief Construct a Waveform.
   * @param space The measurement space.
   * @param transforms The port transforms.
   */
  Waveform(
      const math::discrete_spaces::DiscreteSpaceSP&          space,
      const generic::ListSP<port_transforms::PortTransform>& transforms =
          std::make_shared<generic::List<port_transforms::PortTransform>>());
  /**
   * @brief Create a ND CartesianWaveform from raw deltas.
   * @param divisions The number of divisions along each axis.
   * @param axes The axes defining the cartesian space.
   * @param domain The base domain of the cartesian space.
   * @param transforms the transforms to apply to the waveform.
   * @param increasing if the array should increase following the domain or not.
   */
  static const std::shared_ptr<Waveform> CartesianWaveform(
      const math::AxesSP<int>&                                  divisions,
      const math::AxesSP<math::domains::CoupledLabelledDomain>& axes,
      const math::AxesSP<generic::Map<std::string, bool>>&      increasing,
      const generic::ListSP<port_transforms::PortTransform>&    transforms =
          std::make_shared<generic::List<port_transforms::PortTransform>>(),
      const math::domains::DomainSP& domain =
          std::make_shared<math::domains::Domain>(0, 1));
  /**
   * @brief Create a ND CartesianWaveform with identity transforms.
   * @param divisions The number of divisions along each axis.
   * @param axes The axes defining the cartesian space.
   * @param domain The base domain of the cartesian space.
   * @param increasing if the array should increase following the domain or not.
   */
  static const std::shared_ptr<Waveform> CartesianIdentityWaveform(
      const math::AxesSP<int>&                                  divisions,
      const math::AxesSP<math::domains::CoupledLabelledDomain>& axes,
      const math::AxesSP<generic::Map<std::string, bool>>&      increasing,
      const math::domains::DomainSP&                            domain =
          std::make_shared<math::domains::Domain>(0, 1));
  /**
   * @brief Create a 2D CartesianWaveform from raw deltas.
   * @param divisions The number of divisions along each axis.
   * @param axes The axes defining the cartesian space.
   * @param domain The base domain of the cartesian space.
   * @param transforms the transforms to apply to the waveform.
   * @param increasing if the array should increase following the domain or not.
   */
  static const std::shared_ptr<Waveform> CartesianWaveform2D(
      const math::AxesSP<int>&                                  divisions,
      const math::AxesSP<math::domains::CoupledLabelledDomain>& axes,
      const math::AxesSP<generic::Map<std::string, bool>>&      increasing,
      const generic::ListSP<port_transforms::PortTransform>&    transforms =
          std::make_shared<generic::List<port_transforms::PortTransform>>(),
      const math::domains::DomainSP& domain =
          std::make_shared<math::domains::Domain>(0, 1));
  /**
   * @brief Create a 2D CartesianWaveform with identity transforms.
   * @param divisions The number of divisions along each axis.
   * @param axes The axes defining the cartesian space.
   * @param domain The base domain of the cartesian space.
   * @param increasing if the array should increase following the domain or not.
   */
  static const std::shared_ptr<Waveform> CartesianIdentityWaveform2D(
      const math::AxesSP<int>&                                  divisions,
      const math::AxesSP<math::domains::CoupledLabelledDomain>& axes,
      const math::AxesSP<generic::Map<std::string, bool>>&      increasing,
      const math::domains::DomainSP&                            domain =
          std::make_shared<math::domains::Domain>(0, 1));
  /**
   * @brief Create a 1D CartesianWaveform from raw deltas.
   * @param divisions The number of divisions along each axis.
   * @param axes The axes defining the cartesian space.
   * @param domain The base domain of the cartesian space.
   * @param transforms the transforms to apply to the waveform.
   * @param increasing if the array should increase following the domain or not.
   */
  static const std::shared_ptr<Waveform> CartesianWaveform1D(
      const int&                                                 division,
      const falcon_core::math::domains::CoupledLabelledDomainSP& shared_domain,
      const generic::MapSP<std::string, bool>&                   increasing,
      const generic::ListSP<port_transforms::PortTransform>&     transforms =
          std::make_shared<generic::List<port_transforms::PortTransform>>(),
      const falcon_core::math::domains::DomainSP& domain =
          std::make_shared<falcon_core::math::domains::Domain>(0, 1));

  /**
   * @brief Create a 1D CartesianWaveform with identity transforms.
   * @param divisions The number of divisions along each axis.
   * @param axes The axes defining the cartesian space.
   * @param domain The base domain of the cartesian space.
   * @param increasing if the array should increase following the domain or not.
   */
  static const std::shared_ptr<Waveform> CartesianIdentityWaveform1D(
      const int&                                                 division,
      const falcon_core::math::domains::CoupledLabelledDomainSP& shared_domain,
      const generic::MapSP<std::string, bool>&                   increasing,
      const falcon_core::math::domains::DomainSP&                domain =
          std::make_shared<falcon_core::math::domains::Domain>(0, 1));
  /**
   * @brief Get the measurement space.
   */
  const math::discrete_spaces::DiscreteSpaceSP& space() const;

  /**
   * @brief Confirm that all function knobs are in the discrete space.
   * @throws std::runtime_error if any function knob is not in the discrete
   * space.
   */
  void confirm_knobs_match() const;
  bool operator==(const Waveform& other) const;
  bool operator!=(const Waveform& other) const;

 protected:
  friend class cereal::access;
  Waveform();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<port_transforms::PortTransforms>(this), _space);
  }
};
using WaveformSP = std::shared_ptr<Waveform>;
}  // namespace instrument_interfaces
}  // namespace falcon_core
