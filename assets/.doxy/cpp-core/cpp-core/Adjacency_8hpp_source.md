

# File Adjacency.hpp

[**File List**](files.md) **>** [**config**](dir_69d97931c0a02cb6e53f9a12d673b99f.md) **>** [**core**](dir_21a9197520b9e1fed8f7aab3c046d422.md) **>** [**Adjacency.hpp**](Adjacency_8hpp.md)

[Go to the documentation of this file](Adjacency_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
class Adjacency : public generic::FArray<int> {
  using Indexes = physics::device_structures::ConnectionsSP;
  Indexes                         _indexes;
  mutable std::shared_timed_mutex _mu_indexes;

 public:
  Adjacency(const Adjacency& other);
  Adjacency& operator=(const Adjacency& other);
  Adjacency(const xt::xarray<int>& matrix, const Indexes indexes);
  Indexes indexes() const;

  std::vector<std::pair<size_t, size_t>> get_true_pairs() const;
  bool operator==(const Adjacency& other) const;
  bool operator!=(const Adjacency& other) const;

 protected:
  Adjacency();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_indexes(_mu_indexes);
    ar(cereal::base_class<generic::FArray<int>>(this), _indexes);
  }
};
using AdjacencySP = std::shared_ptr<Adjacency>;
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
```


