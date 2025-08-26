#pragma once

#include <memory>

#include "falcon_core/physics/config/geometries/BarrierGateWithNeighbors.hpp"
#include "falcon_core/physics/config/geometries/BaseDotGateWithNeighbors.hpp"
#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic.hpp"
#include "falcon_core/physics/config/geometries/RightReservoirWithImplantedOhmic.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/device_structures/DotGates.hpp"
#include "falcon_core/physics/device_structures/Ohmics.hpp"
#include "falcon_core/physics/device_structures/PlungerGate.hpp"
#include "falcon_core/physics/device_structures/ReservoirGate.hpp"
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
  using CentralDotGates = DotGates<BaseDotGateWithNeighbors>;
  CentralDotGates                         _central_dot_gates;
  DotGates<DotGate>                       _raw_central_gates;
  ScreeningGatesSP                        _screening_gates;
  BaseConnectionsSP<BaseConnection>       _lineararray;
  std::unordered_map<std::string, GateSP> _gate_name_map;

 public:
  /**
   * @brief Starts the geometry of the gates.
   * @param lineararray A linear array of gates and ohmics in the order left to
   * right in the channel.
   * @param screening_gates A collection of two screening gates.
   * @throws std::invalid_argument if the input does not conform to the expected
   * structure.
   */
  GateGeometryArray1D(BaseConnectionsSP<BaseConnection> lineararray,
                      ScreeningGatesSP                  screening_gates);
  using iterator = typename BaseConnections<BaseConnection>::iterator;
  using const_iterator =
      typename BaseConnections<BaseConnection>::const_iterator;
  iterator       begin() { return _lineararray->begin(); }
  iterator       end() { return _lineararray->end(); }
  const_iterator begin() const { return _lineararray->begin(); }
  const_iterator end() const { return _lineararray->end(); }

  /**
   * @brief Appends a central gate to the geometry.
   * @param gate The gate to append.
   */
  void append_central_gate(const DotGateSP& left_neighbor,
                           const DotGateSP& selected_gate,
                           const DotGateSP& right_neighbor);

  /**
   * @brief Gets all of the dot gates in the geometry
   * @return A collection of all dot gates in the array with localities.
   */
  std::shared_ptr<DotGates<BaseDotGateWithNeighbors>> all_dot_gates() const;

  /**
   * @brief Queries the neighbors of a gate
   * @param gate The gate to query neighbors for
   * @return The collection of neighboring gates
   */
  GatesSP<Gate> query_neighbors(const GateSP& gate) const;

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
  BarrierGateWithNeighborsSP<ReservoirGate, PlungerGate> left_barrier() const;
  /**
   * @brief Gets the rightmost barrier gate in the array.
   * @return The rightmost barrier gate.
   */
  BarrierGateWithNeighborsSP<PlungerGate, ReservoirGate> right_barrier() const;
  /**
   * @brief Gets the linear array of connections.
   * @return The linear array of connections.
   */
  BaseConnectionsSP<BaseConnection> lineararray() const { return _lineararray; }
  /**
   * @brief Gets the screening gates in the geometry.
   * @return The screening gates in the geometry.
   */
  ScreeningGatesSP screening_gates() const { return _screening_gates; }
  /**
   * @brief Gets the central gates without localities.
   * @return The central gates without localities.
   */
  DotGates<DotGate> raw_central_gates() const { return _raw_central_gates; }
  /**
   * @brief Gets the central gates with localities.
   * @return The central gates with localities.
   */
  CentralDotGates central_dot_gates() const { return _central_dot_gates; }
  /**
   * @brief Gets the ohmics attached the the quantum dot geometry.
   * @return The ohmics attached to the quantum dot geometry.
   */
  OhmicsSP ohmics() const;

 protected:
  GateGeometryArray1D() = default;
  friend class cereal::access;
};
using GateGeometryArray1DSP = std::shared_ptr<GateGeometryArray1D>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::config::geometries;
CEREAL_REGISTER_TYPE(GateGeometryArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     GateGeometryArray1D)
#endif
