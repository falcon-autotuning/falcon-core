

# File Domain.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**math**](dir_deeec2dd49335e06d18546a1be264a01.md) **>** [**domains**](dir_0f4cd819bc4c9a3cbf40e528a3341d04.md) **>** [**Domain.hpp**](Domain_8hpp.md)

[Go to the documentation of this file](Domain_8hpp.md)


```C++
#pragma once

#include <mutex>
#include <shared_mutex>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {
namespace domains {

class Domain : public generic::Song {
  double                          _lesser_bound;
  double                          _greater_bound;
  bool                            _lesser_bound_contained;
  bool                            _greater_bound_contained;
  mutable std::shared_timed_mutex _mu_lesser_bound;
  mutable std::shared_timed_mutex _mu_greater_bound;
  mutable std::shared_timed_mutex _mu_lesser_bound_contained;
  mutable std::shared_timed_mutex _mu_greater_bound_contained;

 public:
  Domain(const Domain& other);
  Domain& operator=(const Domain& other);
  Domain(double min_val,
         double max_val,
         bool   lesser_bound_contained  = true,
         bool   greater_bound_contained = true);
  Domain(std::pair<double, double> bounds,
         bool                      lesser_bound_contained  = true,
         bool                      greater_bound_contained = true);
  const double lesser_bound() const;
  const double greater_bound() const;
  const std::pair<double, double> bounds() const;
  const bool lesser_bound_contained() const;
  const bool greater_bound_contained() const;
  const bool in(double value) const;
  const double range() const;
  const double get_center() const;
  const std::shared_ptr<Domain> operator&(
      const std::shared_ptr<Domain>& other) const;
  const std::shared_ptr<Domain> operator|(
      const std::shared_ptr<Domain>& other) const;
  const bool is_empty() const;
  const bool contains_domain(const std::shared_ptr<Domain>& other) const;
  const std::shared_ptr<Domain> shift(double offset) const;
  const std::shared_ptr<Domain> scale(double factor) const;
  const std::pair<double, double> calculate_transform(
      const std::shared_ptr<Domain>& other) const;
  const double transform(const std::shared_ptr<Domain>& other,
                         double                         value) const;
  bool         operator==(const Domain& other) const;
  bool         operator!=(const Domain& other) const;

 protected:
  friend class cereal::access;
  Domain();
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_lesser_bound(
        _mu_lesser_bound, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_greater_bound(
        _mu_greater_bound, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_lesser_bound_contained(
        _mu_lesser_bound_contained, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_greater_bound_contained(
        _mu_greater_bound_contained, std::defer_lock);
    std::lock(lock_lesser_bound,
              lock_greater_bound,
              lock_lesser_bound_contained,
              lock_greater_bound_contained);
    ar(cereal::base_class<falcon_core::generic::Song>(this),
       _lesser_bound,
       _greater_bound,
       _lesser_bound_contained,
       _greater_bound_contained);
  }
};
using DomainSP = std::shared_ptr<Domain>;
}  // namespace domains
}  // namespace math
}  // namespace falcon_core
```


