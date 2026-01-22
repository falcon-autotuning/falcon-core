

# File Group.hpp

[**File List**](files.md) **>** [**config**](dir_69d97931c0a02cb6e53f9a12d673b99f.md) **>** [**core**](dir_21a9197520b9e1fed8f7aab3c046d422.md) **>** [**Group.hpp**](Group_8hpp.md)

[Go to the documentation of this file](Group_8hpp.md)


```C++
#pragma once

#include "falcon_core/autotuner_interfaces/names/Channel.hpp"
#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/config/geometries/GateGeometryArray1D.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
namespace falcon_core {
namespace physics {
namespace config {
namespace core {
class Group : public StandardConfigConnections {
  autotuner_interfaces::names::ChannelSP _name;
  int                                    _num_dots;
  geometries::GateGeometryArray1DSP      _order;
  mutable std::shared_timed_mutex        _mu_name;
  mutable std::shared_timed_mutex        _mu_num_dots;
  mutable std::shared_timed_mutex        _mu_order;

 public:
  Group(const Group& other);
  Group& operator=(const Group& other);
  Group(const autotuner_interfaces::names::ChannelSP& name,
        const int&                                    num_dots,
        const device_structures::ConnectionsSP&       screening_gates,
        const device_structures::ConnectionsSP&       reservoir_gates,
        const device_structures::ConnectionsSP&       plunger_gates,
        const device_structures::ConnectionsSP&       barrier_gates,
        const device_structures::ConnectionsSP&       order);
  const device_structures::ConnectionsSP ohmics() const;
  const autotuner_interfaces::names::ChannelSP& name() const;
  const int& num_dots() const;
  const geometries::GateGeometryArray1DSP& order() const;
  bool has_channel(const autotuner_interfaces::names::ChannelSP& channel) const;
  bool is_charge_sensor() const;
  device_structures::ConnectionsSP get_all_channel_gates(
      const autotuner_interfaces::names::ChannelSP& channel) const;

  bool operator==(const Group& other) const;
  bool operator!=(const Group& other) const;

 protected:
  Group();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_name(_mu_name,
                                                        std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_num_dots(_mu_num_dots,
                                                            std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_order(_mu_order,
                                                         std::defer_lock);
    std::lock(lock_name, lock_num_dots, lock_order);
    ar(cereal::base_class<StandardConfigConnections>(this),
       _name,
       _num_dots,
       _order);
  }
};
using GroupSP = std::shared_ptr<Group>;
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
```


