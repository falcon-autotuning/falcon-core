#pragma once

#include "falcon_core/physics/config/geometries/BarrierGateWithNeighbors.hpp"
#include "falcon_core/physics/config/geometries/DotGatesWithNeighbors.hpp"
#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic.hpp"
#include "falcon_core/physics/config/geometries/RightReservoirWithImplantedOhmic.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/device_structures/Ohmics.hpp"
#include "falcon_core/physics/device_structures/ScreeningGates.hpp"

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
  DotGatesWithNeighborsSP              _central_dot_gates;
  device_structures::BaseConnections   _raw_central_gates;
  device_structures::ScreeningGatesSP  _screening_gates;
  device_structures::BaseConnectionsSP _lineararray;
  std::unordered_map<std::string, device_structures::BaseConnectionSP>
      _gate_name_map;

 public:
  using iterator = typename device_structures::BaseConnections::iterator;
  using const_iterator =
      typename device_structures::BaseConnections::const_iterator;
  /**
   * @brief Starts the geometry of the gates.
   * @param lineararray A linear array of gates and ohmics in the order left to
   * right in the channel.
   * @param screening_gates A collection of two screening gates.
   * @throws std::invalid_argument if the input does not conform to the expected
   * structure.
   */
  GateGeometryArray1D(device_structures::BaseConnectionsSP lineararray,
                      device_structures::ScreeningGatesSP  screening_gates);
  iterator       begin();
  iterator       end();
  const_iterator begin() const;
  const_iterator end() const;

  /**
   * @brief Appends a central gate to the geometry.
   * @param gate The gate to append.
   */
  void append_central_gate(
      const device_structures::BaseConnectionSP& left_neighbor,
      const device_structures::BaseConnectionSP& selected_gate,
      const device_structures::BaseConnectionSP& right_neighbor);

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
  device_structures::BaseConnectionsSP query_neighbors(
      const device_structures::BaseConnectionSP& gate) const;

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
  BarrierGateWithNeighborsSP left_barrier() const;
  /**
   * @brief Gets the rightmost barrier gate in the array.
   * @return The rightmost barrier gate.
   */
  BarrierGateWithNeighborsSP right_barrier() const;
  /**
   * @brief Gets the linear array of connections.
   * @return The linear array of connections.
   */
  device_structures::BaseConnectionsSP lineararray() const;
  /**
   * @brief Gets the screening gates in the geometry.
   * @return The screening gates in the geometry.
   */
  device_structures::ScreeningGatesSP screening_gates() const;
  /**
   * @brief Gets the central gates without localities.
   * @return The central gates without localities.
   */
  device_structures::BaseConnectionsSP raw_central_gates() const;
  /**
   * @brief Gets the central gates with localities.
   * @return The central gates with localities.
   */
  DotGatesWithNeighborsSP central_dot_gates() const;
  /**
   * @brief Gets the ohmics attached the the quantum dot geometry.
   * @return The ohmics attached to the quantum dot geometry.
   */
  device_structures::OhmicsSP ohmics() const;

 protected:
  GateGeometryArray1D();
  friend class cereal::access;
};
using GateGeometryArray1DSP = std::shared_ptr<GateGeometryArray1D>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
