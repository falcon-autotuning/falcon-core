

# File Impedance.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**physics**](dir_ef8a5933242b0e98f781c5d9eb0e15a8.md) **>** [**device\_structures**](dir_30b06ebaf5519c029f1c8cff468fc8e6.md) **>** [**Impedance.hpp**](Impedance_8hpp.md)

[Go to the documentation of this file](Impedance_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

class Impedance : public generic::Song {
  std::shared_ptr<Connection>     _connection;
  double                          _resistance;
  double                          _capacitance;
  mutable std::shared_timed_mutex _mu_connection;
  mutable std::shared_timed_mutex _mu_resistance;
  mutable std::shared_timed_mutex _mu_capacitance;

 public:
  Impedance(const Impedance& other);
  Impedance& operator=(const Impedance& other);
  Impedance(std::shared_ptr<Connection> connection,
            double                      resistance,
            double                      capacitance);
  static std::shared_ptr<Impedance> create(const ConnectionSP connection,
                                           const double       resistance,
                                           const double       capacitance);
  ConnectionSP connection() const;
  double resistance() const;
  double capacitance() const;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_connection(_mu_connection,
                                                              std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_resistance(_mu_resistance,
                                                              std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_capacitance(_mu_capacitance,
                                                               std::defer_lock);
    std::lock(lock_connection, lock_resistance, lock_capacitance);
    ar(cereal::base_class<generic::Song>(this),
       _connection,
       _resistance,
       _capacitance);
  }
  bool operator==(const Impedance& other) const;
  bool operator!=(const Impedance& other) const;

 protected:
  Impedance();
  friend class cereal::access;
};
using ImpedanceSP = std::shared_ptr<Impedance>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
```


