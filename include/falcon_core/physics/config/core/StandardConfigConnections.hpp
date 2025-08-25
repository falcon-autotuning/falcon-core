#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BarrierGates.hpp"
#include "falcon_core/physics/device_structures/DotGates.hpp"
#include "falcon_core/physics/device_structures/Gates.hpp"
#include "falcon_core/physics/device_structures/Ohmics.hpp"
#include "falcon_core/physics/device_structures/PlungerGates.hpp"
#include "falcon_core/physics/device_structures/ReservoirGates.hpp"
#include "falcon_core/physics/device_structures/ScreeningGates.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
/**
 * @brief Base config functionality for core config classes.
 */
class StandardConfigConnections : public generic::Song {
  ScreeningGatesSP _screening_gates;
  ReservoirGatesSP _reservoir_gates;
  PlungerGatesSP   _plunger_gates;
  BarrierGatesSP   _barrier_gates;
  OhmicsSP         _ohmics;

 public:
  /**
   * @brief Constructs the differet gate types holders.
   * @param screening_gates The screening gates.
   * @param reservoir_gates The reservoir gates.
   * @param plunger_gates The plunger gates.
   * @param barrier_gates The barrier gates.
   * @param ohmics The ohmic contacts.
   */
  StandardConfigConnections(ScreeningGatesSP screening_gates,
                            ReservoirGatesSP reservoir_gates,
                            PlungerGatesSP   plunger_gates,
                            BarrierGatesSP   barrier_gates,
                            OhmicsSP         ohmics)
      : _screening_gates(screening_gates),
        _reservoir_gates(reservoir_gates),
        _plunger_gates(plunger_gates),
        _barrier_gates(barrier_gates),
        _ohmics(ohmics) {}
  /**
   * @brief The screening gates from the config.
   * @return The screening gates.
   */
  ScreeningGatesSP screening_gates() const { return _screening_gates; }
  /**
   * @brief The reservoir gates from the config.
   * @return The reservoir gates.
   */
  ReservoirGatesSP reservoir_gates() const { return _reservoir_gates; }
  /**
   * @brief The plunger gates from the config.
   * @return The plunger gates.
   */
  PlungerGatesSP plunger_gates() const { return _plunger_gates; }
  /**
   * @brief The barrier gates from the config.
   * @return The barrier gates.
   */
  BarrierGatesSP barrier_gates() const { return _barrier_gates; }
  /**
   * @brief The ohmics from the config.
   * @return The ohmics gates.
   */
  OhmicsSP ohmics() const { return _ohmics; }
  /**
   * @brief Gets the connections of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Ohmic, BarrierGate, PlungerGate, ReservoirGate,
   * ScreeningGate, DotGate, Gate. and Ohmic
   * @returns the plural form of the connection type. This corresponds to the
   * conn_type
   */
  OhmicsSP get_connections(OhmicSP conn_type) const;
  /**
   * @brief Gets the connections of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Ohmic, BarrierGate, PlungerGate, ReservoirGate,
   * ScreeningGate, DotGate, Gate. and Ohmic
   * @returns the plural form of the connection type. This corresponds to the
   * conn_type
   */
  BarrierGatesSP get_connections(BarrierGateSP conn_type) const;
  /**
   * @brief Gets the connections of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Ohmic, BarrierGate, PlungerGate, ReservoirGate,
   * ScreeningGate, DotGate, Gate. and Ohmic
   * @returns the plural form of the connection type. This corresponds to the
   * conn_type
   */
  PlungerGatesSP get_connections(PlungerGateSP conn_type) const;
  /**
   * @brief Gets the connections of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Ohmic, BarrierGate, PlungerGate, ReservoirGate,
   * ScreeningGate, DotGate, Gate. and Ohmic
   * @returns the plural form of the connection type. This corresponds to the
   * conn_type
   */
  ReservoirGatesSP get_connections(ReservoirGateSP conn_type) const;
  /**
   * @brief Gets the connections of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Ohmic, BarrierGate, PlungerGate, ReservoirGate,
   * ScreeningGate, DotGate, Gate. and Ohmic
   * @returns the plural form of the connection type. This corresponds to the
   * conn_type
   */
  ScreeningGatesSP get_connections(ScreeningGateSP conn_type) const;
  /**
   * @brief Gets the connections of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Ohmic, BarrierGate, PlungerGate, ReservoirGate,
   * ScreeningGate, DotGate, Gate. and Ohmic
   * @returns the plural form of the connection type. This corresponds to the
   * conn_type
   */
  DotGatesSP<DotGate> get_connections(DotGateSP conn_type) const;
  /**
   * @brief Gets the connections of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Ohmic, BarrierGate, PlungerGate, ReservoirGate,
   * ScreeningGate, DotGate, Gate. and Ohmic
   * @returns the plural form of the connection type. This corresponds to the
   * conn_type
   */
  GatesSP<Gate> get_connections(GateSP conn_type) const;
  /**
   * @brief Gets the first connection of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Ohmic, BarrierGate, PlungerGate, ReservoirGate,
   * ScreeningGate, DotGate, Gate. and Ohmic
   * @returns the first of the connection type found. This corresponds to the
   * conn_type
   */
  OhmicSP get_connection(OhmicSP conn_type) const;
  /**
   * @brief Gets the first connection of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Ohmic, BarrierGate, PlungerGate, ReservoirGate,
   * ScreeningGate, DotGate, Gate. and Ohmic
   * @returns the first of the connection type found. This corresponds to the
   * conn_type
   */
  BarrierGateSP get_connection(BarrierGateSP conn_type) const;
  /**
   * @brief Gets the first connection of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Ohmic, BarrierGate, PlungerGate, ReservoirGate,
   * ScreeningGate, DotGate, Gate. and Ohmic
   * @returns the first of the connection type found. This corresponds to the
   * conn_type
   */
  PlungerGateSP get_connection(PlungerGateSP conn_type) const;
  /**
   * @brief Gets the first connection of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Ohmic, BarrierGate, PlungerGate, ReservoirGate,
   * ScreeningGate, DotGate, Gate. and Ohmic
   * @returns the first of the connection type found. This corresponds to the
   * conn_type
   */
  ReservoirGateSP get_connection(ReservoirGateSP conn_type) const;
  /**
   * @brief Gets the first connection of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Ohmic, BarrierGate, PlungerGate, ReservoirGate,
   * ScreeningGate, DotGate, Gate. and Ohmic
   * @returns the first of the connection type found. This corresponds to the
   * conn_type
   */
  ScreeningGateSP get_connection(ScreeningGateSP conn_type) const;
  /**
   * @brief Gets the first connection of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Ohmic, BarrierGate, PlungerGate, ReservoirGate,
   * ScreeningGate, DotGate, Gate. and Ohmic
   * @returns the first of the connection type found. This corresponds to the
   * conn_type
   */
  DotGateSP get_connection(DotGateSP conn_type) const;
  /**
   * @brief Gets the first connection of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Ohmic, BarrierGate, PlungerGate, ReservoirGate,
   * ScreeningGate, DotGate, Gate. and Ohmic
   * @returns the first of the connection type found. This corresponds to the
   * conn_type
   */
  GateSP get_connection(GateSP conn_type) const;
  /**
   * @brief Gets all of the gates for this collection from the config.
   */
  GatesSP<Gate> get_all_gates() const;
  /**
   * @brief Gets all of the ohmics for this collection from the config.
   */
  OhmicsSP get_all_ohmics() const;
  /**
   * @brief Gets all of the connections for this collection from the config.
   */
  BaseConnectionsSP<BaseConnection> get_all_connections() const;
  /**
   * @brief If this ohmic is a member of this group or not.
   */
  bool has_ohmic(OhmicSP ohmic) const;
  /**
   * @brief If this gate is a member of this group or not.
   */
  bool has_gate(GateSP gate) const;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       _screening_gates,
       _reservoir_gates,
       _plunger_gates,
       _barrier_gates,
       _ohmics);
  }

 protected:
  friend class cereal::access;
};
using StandardConfigConnectionsSP = std::shared_ptr<StandardConfigConnections>;
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::config::core;
CEREAL_REGISTER_TYPE(StandardConfigConnections)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     StandardConfigConnections)
#endif
