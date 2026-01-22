

# File DotGatesWithNeighbors.hpp

[**File List**](files.md) **>** [**config**](dir_69d97931c0a02cb6e53f9a12d673b99f.md) **>** [**geometries**](dir_72dc7e7ae643f254d20835947b356af7.md) **>** [**DotGatesWithNeighbors.hpp**](DotGatesWithNeighbors_8hpp.md)

[Go to the documentation of this file](DotGatesWithNeighbors_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"
namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

class DotGatesWithNeighbors
    : public falcon_core::generic::List<DotGateWithNeighbors> {
 public:
  DotGatesWithNeighbors();
  DotGatesWithNeighbors(const std::vector<DotGateWithNeighborsSP>& vec);
  bool is_plunger_gates() const;
  bool is_barrier_gates() const;
  bool operator==(const DotGatesWithNeighbors& other) const;
  bool operator!=(const DotGatesWithNeighbors& other) const;
};
using DotGatesWithNeighborsSP = std::shared_ptr<DotGatesWithNeighbors>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
```


