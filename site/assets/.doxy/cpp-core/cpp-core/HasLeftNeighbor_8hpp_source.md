

# File HasLeftNeighbor.hpp

[**File List**](files.md) **>** [**config**](dir_69d97931c0a02cb6e53f9a12d673b99f.md) **>** [**geometries**](dir_72dc7e7ae643f254d20835947b356af7.md) **>** [**HasLeftNeighbor.hpp**](HasLeftNeighbor_8hpp.md)

[Go to the documentation of this file](HasLeftNeighbor_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

class HasLeftNeighbor : public virtual generic::Song {
  device_structures::ConnectionSP _left_neighbor;
  mutable std::shared_timed_mutex _mu_left_neighbor;

 public:
  HasLeftNeighbor(const HasLeftNeighbor& other);
  HasLeftNeighbor& operator=(const HasLeftNeighbor& other);
  HasLeftNeighbor(device_structures::ConnectionSP left_neighbor);

  device_structures::ConnectionSP left_neighbor() const;

 protected:
  HasLeftNeighbor();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_left_neighbor(
        _mu_left_neighbor);
    ar(cereal::base_class<generic::Song>(this), _left_neighbor);
  }
};
using HasLeftNeighborSP = std::shared_ptr<HasLeftNeighbor>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
```


