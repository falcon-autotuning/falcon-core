

# File UnitSpace.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**math**](dir_deeec2dd49335e06d18546a1be264a01.md) **>** [**UnitSpace.hpp**](UnitSpace_8hpp.md)

[Go to the documentation of this file](UnitSpace_8hpp.md)


```C++


#pragma once

#include "falcon_core/math/Axes.hpp"
#include "falcon_core/math/arrays/ControlArray1D.hpp"
#include "falcon_core/math/discrete_spaces/Discretizer.hpp"

namespace falcon_core {
namespace math {

class UnitSpace : public math::Axes<discrete_spaces::Discretizer> {
  domains::DomainSP               _domain;
  AxesSP<arrays::ControlArray1D>  _ranges;
  generic::FArraySP<double>       _space;
  mutable std::shared_timed_mutex _mu_space;
  mutable std::shared_timed_mutex _mu_ranges;
  mutable std::shared_timed_mutex _mu_domain;

  void make_discrete_axes();

 public:
  UnitSpace(const UnitSpace& other);
  UnitSpace& operator=(const UnitSpace& other);
  UnitSpace(const AxesSP<discrete_spaces::Discretizer>& axes,
            const domains::DomainSP&                    domain);
  static std::shared_ptr<UnitSpace> RaySpace(const double&            dr,
                                             const double&            dtheta,
                                             const domains::DomainSP& domain);
  static std::shared_ptr<UnitSpace> CartesianSpace(
      const AxesSP<double>& deltas, const domains::DomainSP& domain);
  static std::shared_ptr<UnitSpace> Cartesian1DSpace(
      const double& delta, const domains::DomainSP& domain);
  static std::shared_ptr<UnitSpace> Cartesian2DSpace(
      const AxesSP<double>& deltas, const domains::DomainSP& domain);
  const AxesSP<discrete_spaces::Discretizer> axes() const;
  const domains::DomainSP& domain() const;
  const generic::FArraySP<double>& space() const;
  const generic::ListSP<int> shape() const;
  const int dimension() const;
  void compile();
  const AxesSP<arrays::ControlArray> create_array(
      const AxesSP<int>& axes) const;
  bool operator==(const UnitSpace& other) const;
  bool operator!=(const UnitSpace& other) const;

 protected:
  friend class cereal::access;
  UnitSpace();
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_domain(_mu_domain,
                                                          std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_ranges(_mu_ranges,
                                                          std::defer_lock);
    std::lock(lock_domain, lock_ranges);
    ar(cereal::base_class<math::Axes<discrete_spaces::Discretizer>>(this),
       _domain,
       _ranges);
  }
};
using UnitSpaceSP = std::shared_ptr<UnitSpace>;
}  // namespace math
}  // namespace falcon_core
```


