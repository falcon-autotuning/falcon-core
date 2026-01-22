

# File GateRelations.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**physics**](dir_ef8a5933242b0e98f781c5d9eb0e15a8.md) **>** [**device\_structures**](dir_30b06ebaf5519c029f1c8cff468fc8e6.md) **>** [**GateRelations.hpp**](GateRelations_8hpp.md)

[Go to the documentation of this file](GateRelations_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/Map.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

class GateRelations : public generic::Map<Connection, Connections> {
 public:
  GateRelations();
  GateRelations(std::vector<std::pair<ConnectionSP, ConnectionsSP>> init);
  void insert_or_assign(const ConnectionSP& key, const ConnectionsSP& value);
  std::pair<generic::List<generic::Pair<Connection, Connections>>::iterator,
            bool>
       insert(const ConnectionSP& key, const ConnectionsSP& value);
  bool operator==(const GateRelations& other) const;
  bool operator!=(const GateRelations& other) const;
};
using GateRelationsSP = std::shared_ptr<GateRelations>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
```


