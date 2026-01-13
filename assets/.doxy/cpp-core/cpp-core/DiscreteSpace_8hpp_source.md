

# File DiscreteSpace.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**math**](dir_deeec2dd49335e06d18546a1be264a01.md) **>** [**discrete\_spaces**](dir_71966f80191a0917307a068cf22a319b.md) **>** [**DiscreteSpace.hpp**](DiscreteSpace_8hpp.md)

[Go to the documentation of this file](DiscreteSpace_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/Map.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/math/UnitSpace.hpp"
#include "falcon_core/math/arrays/LabelledControlArray.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

class DiscreteSpace : public generic::Song {
  UnitSpaceSP                             _space;
  AxesSP<domains::CoupledLabelledDomain>  _axes;
  AxesSP<generic::Map<std::string, bool>> _increasing;
  mutable std::shared_timed_mutex         _mu_space;
  mutable std::shared_timed_mutex         _mu_axes;
  mutable std::shared_timed_mutex         _mu_increasing;

 public:
  DiscreteSpace(const DiscreteSpace& other);
  DiscreteSpace& operator=(const DiscreteSpace& other);
  DiscreteSpace(const UnitSpaceSP&                             space,
                const AxesSP<domains::CoupledLabelledDomain>&  axes,
                const AxesSP<generic::Map<std::string, bool>>& increasing);
  static std::shared_ptr<DiscreteSpace> CartesianDiscreteSpace(
      const AxesSP<int>&                             divisions,
      const AxesSP<domains::CoupledLabelledDomain>&  axes,
      const AxesSP<generic::Map<std::string, bool>>& increasing,
      const domains::DomainSP&                       domain =
          std::make_shared<domains::Domain>(std::pair<double, double>(0, 1)));
  static std::shared_ptr<DiscreteSpace> CartesianDiscreteSpace1D(
      const int&                               division,
      const domains::CoupledLabelledDomainSP&  shared_domain,
      const generic::MapSP<std::string, bool>& increasing,
      const domains::DomainSP&                 domain =
          std::make_shared<domains::Domain>(std::pair<double, double>(0, 1)));
  const UnitSpaceSP& space() const;
  const AxesSP<domains::CoupledLabelledDomain>& axes() const;
  const AxesSP<generic::Map<std::string, bool>>& increasing() const;
  const instrument_interfaces::names::PortsSP knobs() const;
  void validate_unit_space_dimensionality_matches_knobs() const;
  void validate_knob_uniqueness() const;
  const int get_axis(
      const instrument_interfaces::names::InstrumentPortSP& knob) const;
  const domains::DomainSP get_domain(
      const instrument_interfaces::names::InstrumentPortSP& knob) const;
  const AxesSP<arrays::LabelledControlArray> get_projection(
      const AxesSP<instrument_interfaces::names::InstrumentPort>& projection)
      const;
  bool operator==(const DiscreteSpace& other) const;
  bool operator!=(const DiscreteSpace& other) const;

 protected:
  DiscreteSpace();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_space(_mu_space,
                                                         std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_axes(_mu_axes,
                                                        std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_increasing(_mu_increasing,
                                                              std::defer_lock);
    std::lock(lock_space, lock_axes, lock_increasing);
    ar(cereal::base_class<generic::Song>(this), _space, _axes, _increasing);
  }
};
using DiscreteSpaceSP = std::shared_ptr<DiscreteSpace>;
}  // namespace discrete_spaces
}  // namespace math
}  // namespace falcon_core
```


