

# File Discretizer.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**math**](dir_deeec2dd49335e06d18546a1be264a01.md) **>** [**discrete\_spaces**](dir_71966f80191a0917307a068cf22a319b.md) **>** [**Discretizer.hpp**](Discretizer_8hpp.md)

[Go to the documentation of this file](Discretizer_8hpp.md)


```C++


#pragma once

#include "falcon_core/math/domains/Domain.hpp"

enum class Dividers {
  Cartesian,
  Polar,
};
namespace falcon_core {
namespace math {
namespace discrete_spaces {

class Discretizer : public generic::Song {
  double                          _delta;
  domains::DomainSP               _delta_domain;
  Dividers                        _type;
  mutable std::shared_timed_mutex _mu_delta;
  mutable std::shared_timed_mutex _mu_delta_domain;
  mutable std::shared_timed_mutex _mu_type;

 public:
  Discretizer(const Discretizer& other);
  Discretizer& operator=(const Discretizer& other);
  Discretizer(const double&            delta,
              const domains::DomainSP& delta_domain,
              const Dividers&          type);
  static std::shared_ptr<Discretizer> CartesianDiscretizer(const double& delta);
  static std::shared_ptr<Discretizer> PolarDiscretizer(const double& delta);
  double                              delta() const;
  void                                set_delta(double delta);
  const domains::DomainSP&            domain() const;
  const bool is_cartesian() const;
  const bool is_polar() const;
  bool       operator==(const Discretizer& other) const;
  bool       operator!=(const Discretizer& other) const;

 protected:
  friend class cereal::access;
  Discretizer();
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_delta(_mu_delta,
                                                         std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_delta_domain(
        _mu_delta_domain, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_type(_mu_type,
                                                        std::defer_lock);
    std::lock(lock_delta, lock_delta_domain, lock_type);
    ar(cereal::base_class<generic::Song>(this), _delta, _delta_domain, _type);
  }
};
using DiscretizerSP = std::shared_ptr<Discretizer>;
}  // namespace discrete_spaces
}  // namespace math
}  // namespace falcon_core
```


