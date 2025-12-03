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

/**
 * @brief A 1D array of quantum dots with left and right reservoirs, barrier
 *gates, plunger gates, ohmics, and screening gates. This contains the geometry
 *of the 1D array.
 */
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
  GateGeometryArray1D operator=(const GateGeometryArray1D& other);
  /**
   * @brief Starts the geometry of the gates.
   * @param lineararray A linear array of gates and ohmics in the order left to
   * right in the channel.
   * @param screening_gates A collection of two screening gates.
   * @throws std::invalid_argument if the input does not conform to the expected
   * structure.
   */
  GateGeometryArray1D(device_structures::ConnectionsSP lineararray,
                      device_structures::ConnectionsSP screening_gates);
  iterator       begin();
  iterator       end();
  const_iterator begin() const;
  const_iterator end() const;

  /**
   * @brief Appends a central gate to the geometry.
   * @param gate The gate to append.
   */
  void append_central_gate(
      const device_structures::ConnectionSP& left_neighbor,
      const device_structures::ConnectionSP& selected_gate,
      const device_structures::ConnectionSP& right_neighbor);

  /**
   * @brief Gets all of the dot gates in the geometry
   * @return A collection of all dot gates in the array with localities.
   */
  DotGatesWithNeighborsSP all_dot_gates() const;

  /**
   * @brief Queries the neighbors of a gate
   * @param gate The gate to query neighbors for
   * @return The collection of neighboring gates
   */
  device_structures::ConnectionsSP query_neighbors(
      const device_structures::ConnectionSP& gate) const;

  /**
   * @brief Gets the left reservoir with implanted ohmic contact.
   * @return The left reservoir with implanted ohmic contact.
   */
  LeftReservoirWithImplantedOhmicSP left_reservoir() const;

  /**
   * @brief Gets the right reservoir with implanted ohmic contact.
   * @return The right reservoir with implanted ohmic contact.
   */
  RightReservoirWithImplantedOhmicSP right_reservoir() const;

  /**
   * @brief Gets the leftmost barrier gate in the array.
   * @return The leftmost barrier gate.
   */
  DotGateWithNeighborsSP left_barrier() const;
  /**
   * @brief Gets the rightmost barrier gate in the array.
   * @return The rightmost barrier gate.
   */
  DotGateWithNeighborsSP right_barrier() const;
  /**
   * @brief Gets the linear array of connections.
   * @return The linear array of connections.
   */
  const device_structures::ConnectionsSP& lineararray() const;
  /**
   * @brief Gets the screening gates in the geometry.
   * @return The screening gates in the geometry.
   */
  const device_structures::ConnectionsSP& screening_gates() const;
  /**
   * @brief Gets the central gates without localities.
   * @return The central gates without localities.
   */
  device_structures::ConnectionsSP raw_central_gates() const;
  /**
   * @brief Gets the central gates with localities.
   * @return The central gates with localities.
   */
  DotGatesWithNeighborsSP central_dot_gates() const;
  /**
   * @brief Gets the ohmics attached the the quantum dot geometry.
   * @return The ohmics attached to the quantum dot geometry.
   */
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
