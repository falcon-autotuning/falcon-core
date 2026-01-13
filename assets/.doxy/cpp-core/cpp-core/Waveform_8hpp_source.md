

# File Waveform.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**instrument\_interfaces**](dir_1d63ba24e228ec3f87efddb1c2728844.md) **>** [**Waveform.hpp**](Waveform_8hpp.md)

[Go to the documentation of this file](Waveform_8hpp.md)


```C++
#pragma once
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransforms.hpp"
#include "falcon_core/math/discrete_spaces/DiscreteSpace.hpp"

namespace falcon_core {
namespace instrument_interfaces {

class Waveform : public port_transforms::PortTransforms {
  math::discrete_spaces::DiscreteSpaceSP _space;
  mutable std::shared_timed_mutex        _mu_dspace;

 public:
  Waveform(const Waveform& other);
  Waveform& operator=(const Waveform& other);
  Waveform(
      const math::discrete_spaces::DiscreteSpaceSP&          space,
      const generic::ListSP<port_transforms::PortTransform>& transforms =
          std::make_shared<generic::List<port_transforms::PortTransform>>());
  static const std::shared_ptr<Waveform> CartesianWaveform(
      const math::AxesSP<int>&                                  divisions,
      const math::AxesSP<math::domains::CoupledLabelledDomain>& axes,
      const math::AxesSP<generic::Map<std::string, bool>>&      increasing,
      const generic::ListSP<port_transforms::PortTransform>&    transforms =
          std::make_shared<generic::List<port_transforms::PortTransform>>(),
      const math::domains::DomainSP& domain =
          std::make_shared<math::domains::Domain>(0, 1));
  static const std::shared_ptr<Waveform> CartesianIdentityWaveform(
      const math::AxesSP<int>&                                  divisions,
      const math::AxesSP<math::domains::CoupledLabelledDomain>& axes,
      const math::AxesSP<generic::Map<std::string, bool>>&      increasing,
      const math::domains::DomainSP&                            domain =
          std::make_shared<math::domains::Domain>(0, 1));
  static const std::shared_ptr<Waveform> CartesianWaveform2D(
      const math::AxesSP<int>&                                  divisions,
      const math::AxesSP<math::domains::CoupledLabelledDomain>& axes,
      const math::AxesSP<generic::Map<std::string, bool>>&      increasing,
      const generic::ListSP<port_transforms::PortTransform>&    transforms =
          std::make_shared<generic::List<port_transforms::PortTransform>>(),
      const math::domains::DomainSP& domain =
          std::make_shared<math::domains::Domain>(0, 1));
  static const std::shared_ptr<Waveform> CartesianIdentityWaveform2D(
      const math::AxesSP<int>&                                  divisions,
      const math::AxesSP<math::domains::CoupledLabelledDomain>& axes,
      const math::AxesSP<generic::Map<std::string, bool>>&      increasing,
      const math::domains::DomainSP&                            domain =
          std::make_shared<math::domains::Domain>(0, 1));
  static const std::shared_ptr<Waveform> CartesianWaveform1D(
      const int&                                                 division,
      const falcon_core::math::domains::CoupledLabelledDomainSP& shared_domain,
      const generic::MapSP<std::string, bool>&                   increasing,
      const generic::ListSP<port_transforms::PortTransform>&     transforms =
          std::make_shared<generic::List<port_transforms::PortTransform>>(),
      const falcon_core::math::domains::DomainSP& domain =
          std::make_shared<falcon_core::math::domains::Domain>(0, 1));

  static const std::shared_ptr<Waveform> CartesianIdentityWaveform1D(
      const int&                                                 division,
      const falcon_core::math::domains::CoupledLabelledDomainSP& shared_domain,
      const generic::MapSP<std::string, bool>&                   increasing,
      const falcon_core::math::domains::DomainSP&                domain =
          std::make_shared<falcon_core::math::domains::Domain>(0, 1));
  const math::discrete_spaces::DiscreteSpaceSP& space() const;

  void confirm_knobs_match() const;
  bool operator==(const Waveform& other) const;
  bool operator!=(const Waveform& other) const;

 protected:
  friend class cereal::access;
  Waveform();
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_space(_mu_dspace);
    ar(cereal::base_class<port_transforms::PortTransforms>(this), _space);
  }
};
using WaveformSP = std::shared_ptr<Waveform>;
}  // namespace instrument_interfaces
}  // namespace falcon_core
```


