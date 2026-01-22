

# File HasImplantedOhmic.hpp

[**File List**](files.md) **>** [**config**](dir_69d97931c0a02cb6e53f9a12d673b99f.md) **>** [**geometries**](dir_72dc7e7ae643f254d20835947b356af7.md) **>** [**HasImplantedOhmic.hpp**](HasImplantedOhmic_8hpp.md)

[Go to the documentation of this file](HasImplantedOhmic_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
class HasImplantedOhmic : public virtual generic::Song {
  device_structures::ConnectionSP _ohmic;
  mutable std::shared_timed_mutex _mu_ohmic;

 public:
  HasImplantedOhmic(const HasImplantedOhmic& other);
  HasImplantedOhmic& operator=(const HasImplantedOhmic& other);
  HasImplantedOhmic(device_structures::ConnectionSP ohmic);
  device_structures::ConnectionSP ohmic() const;

 protected:
  HasImplantedOhmic();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_ohmic(_mu_ohmic);
    ar(cereal::base_class<Song>(this), _ohmic);
  }
};
using HasImplantedOhmicSP = std::shared_ptr<HasImplantedOhmic>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
```


