

# File DotGateWithNeighbors.hpp

[**File List**](files.md) **>** [**config**](dir_69d97931c0a02cb6e53f9a12d673b99f.md) **>** [**geometries**](dir_72dc7e7ae643f254d20835947b356af7.md) **>** [**DotGateWithNeighbors.hpp**](DotGateWithNeighbors_8hpp.md)

[Go to the documentation of this file](DotGateWithNeighbors_8hpp.md)


```C++
#pragma once

#include "falcon_core/physics/config/geometries/HasLeftNeighbor.hpp"
#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

class DotGateWithNeighbors : public device_structures::Connection,
                             public HasLeftNeighbor,
                             public HasRightNeighbor {
 public:
  DotGateWithNeighbors(const DotGateWithNeighbors& other);
  DotGateWithNeighbors& operator=(const DotGateWithNeighbors& other);
  DotGateWithNeighbors(std::string                      name,
                       device_structures::DeviceFeature type,
                       device_structures::ConnectionSP  left_neighbor,
                       device_structures::ConnectionSP  right_neighbor);
  static std::shared_ptr<DotGateWithNeighbors> PlungerGateWithNeighbors(
      std::string                     name,
      device_structures::ConnectionSP left_neighbor,
      device_structures::ConnectionSP right_neighbor);
  static std::shared_ptr<DotGateWithNeighbors> BarrierGateWithNeighbors(
      std::string                     name,
      device_structures::ConnectionSP left_neighbor,
      device_structures::ConnectionSP right_neighbor);
  bool operator==(const DotGateWithNeighbors& other) const;
  bool operator!=(const DotGateWithNeighbors& other) const;

 protected:
  DotGateWithNeighbors();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Connection>(this));
    ar(cereal::base_class<HasLeftNeighbor>(this));
    ar(cereal::base_class<HasRightNeighbor>(this));
  }
};
using DotGateWithNeighborsSP = std::shared_ptr<DotGateWithNeighbors>;

}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
```


