

# File VoltageConstraints.hpp

[**File List**](files.md) **>** [**config**](dir_69d97931c0a02cb6e53f9a12d673b99f.md) **>** [**core**](dir_21a9197520b9e1fed8f7aab3c046d422.md) **>** [**VoltageConstraints.hpp**](VoltageConstraints_8hpp.md)

[Go to the documentation of this file](VoltageConstraints_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/config/core/Adjacency.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {

class VoltageConstraints : public generic::Song {
  generic::FArray<double>         _matrix;
  AdjacencySP                     _adjacency;
  generic::FArray<double>         _limits;
  mutable std::shared_timed_mutex _mu_matrix;
  mutable std::shared_timed_mutex _mu_adjacency;
  mutable std::shared_timed_mutex _mu_limits;

 public:
  VoltageConstraints(const VoltageConstraints& other);
  VoltageConstraints& operator=(const VoltageConstraints& other);
  VoltageConstraints(const AdjacencySP         adjacency,
                     double                    max_safe_diff,
                     std::pair<double, double> bounds);
  const generic::FArray<double>& matrix() const;
  const generic::FArray<double>& matrix();
  const AdjacencySP adjacency() const;
  const generic::FArray<double>& limits() const;
  bool operator==(const VoltageConstraints& other) const;
  bool operator!=(const VoltageConstraints& other) const;

 protected:
  VoltageConstraints();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_matrix(_mu_matrix,
                                                          std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_adjacency(_mu_adjacency,
                                                             std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_limits(_mu_limits,
                                                          std::defer_lock);
    std::lock(lock_matrix, lock_adjacency, lock_limits);
    ar(cereal::base_class<generic::Song>(this), _matrix, _adjacency, _limits);
  }
};
using VoltageConstraintsSP = std::shared_ptr<VoltageConstraints>;
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
```


