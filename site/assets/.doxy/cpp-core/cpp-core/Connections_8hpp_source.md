

# File Connections.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**physics**](dir_ef8a5933242b0e98f781c5d9eb0e15a8.md) **>** [**device\_structures**](dir_30b06ebaf5519c029f1c8cff468fc8e6.md) **>** [**Connections.hpp**](Connections_8hpp.md)

[Go to the documentation of this file](Connections_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

class Connections : public falcon_core::generic::List<Connection> {
 public:
  Connections();
  Connections(size_t count, const ConnectionSP& value);
  Connections(const std::vector<ConnectionSP>& vec);
  Connections(const generic::ListSP<Connection>& vec);
  bool is_gates() const;
  bool is_ohmics() const;
  bool is_dot_gates() const;
  bool is_plunger_gates() const;
  bool is_barrier_gates() const;
  bool is_reservoir_gates() const;
  bool is_screening_gates() const;
  std::shared_ptr<Connections> intersection(
      const std::shared_ptr<Connections>& other) const;
  bool operator==(const Connections& other) const;
  bool operator!=(const Connections& other) const;
};
using ConnectionsSP = std::shared_ptr<Connections>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
```


