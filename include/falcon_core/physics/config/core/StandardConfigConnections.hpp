#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BarrierGates.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
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
  device_structures::ScreeningGatesSP _screening_gates;
  device_structures::ReservoirGatesSP _reservoir_gates;
  device_structures::PlungerGatesSP   _plunger_gates;
  device_structures::BarrierGatesSP   _barrier_gates;
  device_structures::OhmicsSP         _ohmics;

 public:
  /**
   * @brief Constructs the differet gate types holders.
   * @param screening_gates The screening gates.
   * @param reservoir_gates The reservoir gates.
   * @param plunger_gates The plunger gates.
   * @param barrier_gates The barrier gates.
   * @param ohmics The ohmic contacts.
   */
  StandardConfigConnections(
      const device_structures::ScreeningGatesSP& screening_gates,
      const device_structures::ReservoirGatesSP& reservoir_gates,
      const device_structures::PlungerGatesSP&   plunger_gates,
      const device_structures::BarrierGatesSP&   barrier_gates,
      const device_structures::OhmicsSP&         ohmics);
  /**
   * @brief The screening gates from the config.
   * @return The screening gates.
   */
  device_structures::ScreeningGatesSP screening_gates() const;
  /**
   * @brief The reservoir gates from the config.
   * @return The reservoir gates.
   */
  device_structures::ReservoirGatesSP reservoir_gates() const;
  /**
   * @brief The plunger gates from the config.
   * @return The plunger gates.
   */
  device_structures::PlungerGatesSP plunger_gates() const;
  /**
   * @brief The barrier gates from the config.
   * @return The barrier gates.
   */
  device_structures::BarrierGatesSP barrier_gates() const;
  /**
   * @brief The ohmics from the config.
   * @return The ohmics gates.
   */
  device_structures::OhmicsSP ohmics() const;
  /**
   * @brief Gets the connections of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Ohmic, BarrierGate, PlungerGate, ReservoirGate,
   * ScreeningGate, DotGate, Gate. and Ohmic
   * @returns the plural form of the connection type. This corresponds to the
   * conn_type
   */
  device_structures::BaseConnectionsSP dot_gates() const;
  /**
   * @brief Gets the first ohmic connection.
   */
  device_structures::OhmicSP get_ohmic() const;
  /**
   * @brief Gets the first barrier gate connection.
   */
  device_structures::BarrierGateSP get_barrier_gate() const;
  /**
   * @brief Gets the first plunger gate connection.
   */
  device_structures::PlungerGateSP get_plunger_gate() const;
  /**
   * @brief Gets the first reservoir gate connection..
   */
  device_structures::ReservoirGateSP get_reservoir_gate() const;
  /**
   * @brief Gets the first screening gate connection.
   */
  device_structures::ScreeningGateSP get_screening_gate() const;
  /**
   * @brief Gets the first dot gate connection.
   */
  device_structures::BaseConnectionSP get_dot_gate() const;
  /**
   * @brief Gets the first gate connection.
   */
  device_structures::BaseConnectionSP get_gate() const;
  /**
   * @brief Gets all of the gates for this collection from the config.
   */
  device_structures::BaseConnectionsSP get_all_gates() const;
  /**
   * @brief Gets all of the ohmics for this collection from the config.
   */
  device_structures::OhmicsSP get_all_ohmics() const;
  /**
   * @brief Gets all of the connections for this collection from the config.
   */
  device_structures::BaseConnectionsSP get_all_connections() const;
  /**
   * @brief If this ohmic is a member of this group or not.
   */
  bool has_ohmic(const device_structures::OhmicSP& ohmic) const;
  /**
   * @brief If this gate is a member of this group or not.
   */
  bool has_gate(const device_structures::BaseConnectionSP& gate) const;
  template <class Archive>
  void serialize(Archive& ar);

 protected:
  StandardConfigConnections();
  friend class cereal::access;
};
using StandardConfigConnectionsSP = std::shared_ptr<StandardConfigConnections>;
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
