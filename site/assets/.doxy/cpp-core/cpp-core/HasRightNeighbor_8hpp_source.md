

# File HasRightNeighbor.hpp

[**File List**](files.md) **>** [**config**](dir_69d97931c0a02cb6e53f9a12d673b99f.md) **>** [**geometries**](dir_72dc7e7ae643f254d20835947b356af7.md) **>** [**HasRightNeighbor.hpp**](HasRightNeighbor_8hpp.md)

[Go to the documentation of this file](HasRightNeighbor_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

class HasRightNeighbor : public virtual generic::Song {
  device_structures::ConnectionSP _right_neighbor;
  mutable std::shared_timed_mutex _mu_right_neighbor;

 public:
  HasRightNeighbor(const HasRightNeighbor& other);
  HasRightNeighbor& operator=(const HasRightNeighbor& other);
  HasRightNeighbor(device_structures::ConnectionSP right_neighbor);

  device_structures::ConnectionSP right_neighbor() const;

 protected:
  HasRightNeighbor();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_right_neighbor(
        _mu_right_neighbor);
    ar(cereal::base_class<generic::Song>(this), _right_neighbor);
  }
};
using HasRightNeighborSP = std::shared_ptr<HasRightNeighbor>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
```


