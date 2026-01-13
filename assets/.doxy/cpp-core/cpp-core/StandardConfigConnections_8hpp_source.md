

# File StandardConfigConnections.hpp

[**File List**](files.md) **>** [**config**](dir_69d97931c0a02cb6e53f9a12d673b99f.md) **>** [**core**](dir_21a9197520b9e1fed8f7aab3c046d422.md) **>** [**StandardConfigConnections.hpp**](StandardConfigConnections_8hpp.md)

[Go to the documentation of this file](StandardConfigConnections_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
class StandardConfigConnections : public generic::Song {
  device_structures::ConnectionsSP _screening_gates;
  device_structures::ConnectionsSP _reservoir_gates;
  device_structures::ConnectionsSP _plunger_gates;
  device_structures::ConnectionsSP _barrier_gates;
  device_structures::ConnectionsSP _ohmics;
  mutable std::shared_timed_mutex  _mu_screening_gates;
  mutable std::shared_timed_mutex  _mu_reservoir_gates;
  mutable std::shared_timed_mutex  _mu_plunger_gates;
  mutable std::shared_timed_mutex  _mu_barrier_gates;
  mutable std::shared_timed_mutex  _mu_ohmics;

 public:
  StandardConfigConnections(const StandardConfigConnections& other);
  StandardConfigConnections& operator=(const StandardConfigConnections& other);
  StandardConfigConnections(
      const device_structures::ConnectionsSP& screening_gates,
      const device_structures::ConnectionsSP& reservoir_gates,
      const device_structures::ConnectionsSP& plunger_gates,
      const device_structures::ConnectionsSP& barrier_gates,
      const device_structures::ConnectionsSP& ohmics);
  const device_structures::ConnectionsSP& screening_gates() const;
  const device_structures::ConnectionsSP& reservoir_gates() const;
  const device_structures::ConnectionsSP& plunger_gates() const;
  const device_structures::ConnectionsSP& barrier_gates() const;
  const device_structures::ConnectionsSP& ohmics() const;
  const device_structures::ConnectionsSP dot_gates() const;
  const device_structures::ConnectionSP get_ohmic() const;
  const device_structures::ConnectionSP get_barrier_gate() const;
  const device_structures::ConnectionSP get_plunger_gate() const;
  const device_structures::ConnectionSP get_reservoir_gate() const;
  const device_structures::ConnectionSP get_screening_gate() const;
  const device_structures::ConnectionSP get_dot_gate() const;
  const device_structures::ConnectionSP get_gate() const;
  const device_structures::ConnectionsSP get_all_gates() const;
  const device_structures::ConnectionsSP get_all_connections() const;
  bool has_ohmic(const device_structures::ConnectionSP& ohmic) const;
  bool has_gate(const device_structures::ConnectionSP& gate) const;
  bool has_barrier_gate(const device_structures::ConnectionSP& gate) const;
  bool has_plunger_gate(const device_structures::ConnectionSP& gate) const;
  bool has_reservoir_gate(const device_structures::ConnectionSP& gate) const;
  bool has_screening_gate(const device_structures::ConnectionSP& gate) const;

  bool operator==(const StandardConfigConnections& other) const;
  bool operator!=(const StandardConfigConnections& other) const;

 protected:
  StandardConfigConnections();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_screening_gates(
        _mu_screening_gates, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_reservoir_gates(
        _mu_reservoir_gates, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_plunger_gates(
        _mu_plunger_gates, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_barrier_gates(
        _mu_barrier_gates, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_ohmics(_mu_ohmics,
                                                          std::defer_lock);
    std::lock(lock_screening_gates,
              lock_reservoir_gates,
              lock_plunger_gates,
              lock_barrier_gates,
              lock_ohmics);
    ar(cereal::base_class<generic::Song>(this),
       _screening_gates,
       _reservoir_gates,
       _plunger_gates,
       _barrier_gates,
       _ohmics);
  }
};
using StandardConfigConnectionsSP = std::shared_ptr<StandardConfigConnections>;
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
```


