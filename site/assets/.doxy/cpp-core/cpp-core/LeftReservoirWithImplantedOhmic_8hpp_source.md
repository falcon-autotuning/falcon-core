

# File LeftReservoirWithImplantedOhmic.hpp

[**File List**](files.md) **>** [**config**](dir_69d97931c0a02cb6e53f9a12d673b99f.md) **>** [**geometries**](dir_72dc7e7ae643f254d20835947b356af7.md) **>** [**LeftReservoirWithImplantedOhmic.hpp**](LeftReservoirWithImplantedOhmic_8hpp.md)

[Go to the documentation of this file](LeftReservoirWithImplantedOhmic_8hpp.md)


```C++
#pragma once

#include "falcon_core/physics/config/geometries/HasImplantedOhmic.hpp"
#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
class LeftReservoirWithImplantedOhmic : public device_structures::Connection,
                                        public HasImplantedOhmic,
                                        public HasRightNeighbor {
 public:
  LeftReservoirWithImplantedOhmic(
      std::string                     name,
      device_structures::ConnectionSP right_neighbor,
      device_structures::ConnectionSP ohmic);

 protected:
  LeftReservoirWithImplantedOhmic();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Connection>(this),
       cereal::base_class<HasImplantedOhmic>(this),
       cereal::base_class<HasRightNeighbor>(this));
  }
};
using LeftReservoirWithImplantedOhmicSP =
    std::shared_ptr<LeftReservoirWithImplantedOhmic>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
```


