

# File GateGeometryArray1D.hpp

[**File List**](files.md) **>** [**config**](dir_69d97931c0a02cb6e53f9a12d673b99f.md) **>** [**geometries**](dir_72dc7e7ae643f254d20835947b356af7.md) **>** [**GateGeometryArray1D.hpp**](GateGeometryArray1D_8hpp.md)

[Go to the documentation of this file](GateGeometryArray1D_8hpp.md)


```C++
#pragma once

#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"
#include "falcon_core/physics/config/geometries/DotGatesWithNeighbors.hpp"
#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic.hpp"
#include "falcon_core/physics/config/geometries/RightReservoirWithImplantedOhmic.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

class GateGeometryArray1D : public generic::Song {
  DotGatesWithNeighborsSP          _central_dot_gates;
  device_structures::Connections   _raw_central_gates;
  device_structures::ConnectionsSP _screening_gates;
  device_structures::ConnectionsSP _linear_array;
  std::unordered_map<std::string, device_structures::ConnectionSP>
                                  _gate_name_map;
  mutable std::shared_timed_mutex _mu_central_dot_gates;
  mutable std::shared_timed_mutex _mu_raw_central_gates;
  mutable std::shared_timed_mutex _mu_screening_gates;
  mutable std::shared_timed_mutex _mu_linear_array;
  mutable std::shared_timed_mutex _mu_gate_name_map;

 public:
  using iterator = typename device_structures::Connections::iterator;
  using const_iterator =
      typename device_structures::Connections::const_iterator;
  GateGeometryArray1D(const GateGeometryArray1D& other);
  GateGeometryArray1D& operator=(const GateGeometryArray1D& other);
  GateGeometryArray1D(device_structures::ConnectionsSP lineararray,
                      device_structures::ConnectionsSP screening_gates);
  iterator       begin();
  iterator       end();
  const_iterator begin() const;
  const_iterator end() const;

  void append_central_gate(
      const device_structures::ConnectionSP& left_neighbor,
      const device_structures::ConnectionSP& selected_gate,
      const device_structures::ConnectionSP& right_neighbor);

  DotGatesWithNeighborsSP all_dot_gates() const;

  device_structures::ConnectionsSP query_neighbors(
      const device_structures::ConnectionSP& gate) const;

  LeftReservoirWithImplantedOhmicSP left_reservoir() const;

  RightReservoirWithImplantedOhmicSP right_reservoir() const;

  DotGateWithNeighborsSP left_barrier() const;
  DotGateWithNeighborsSP right_barrier() const;
  const device_structures::ConnectionsSP& lineararray() const;
  const device_structures::ConnectionsSP& screening_gates() const;
  device_structures::ConnectionsSP raw_central_gates() const;
  DotGatesWithNeighborsSP central_dot_gates() const;
  device_structures::ConnectionsSP ohmics() const;

  bool operator==(const GateGeometryArray1D& other) const;
  bool operator!=(const GateGeometryArray1D& other) const;

 protected:
  GateGeometryArray1D();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_central_dot_gates(
        _mu_central_dot_gates, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_raw_central_gates(
        _mu_raw_central_gates, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_screening_gates(
        _mu_screening_gates, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_linear_array(
        _mu_linear_array, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_gate_name_map(
        _mu_gate_name_map, std::defer_lock);
    std::lock(lock_central_dot_gates,
              lock_raw_central_gates,
              lock_screening_gates,
              lock_linear_array,
              lock_gate_name_map);
    ar(cereal::base_class<Song>(this),
       _raw_central_gates,
       _central_dot_gates,
       _screening_gates,
       _linear_array,
       _gate_name_map);
  }
};
using GateGeometryArray1DSP = std::shared_ptr<GateGeometryArray1D>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
```


