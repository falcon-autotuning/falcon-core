#pragma once

#include "falcon_core/export.h"
#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
/**
 * @brief Base config functionality for core config classes.
 */
class FALCON_CORE_CPP_API StandardConfigConnections : public generic::Song {
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
  /**
   * @brief Constructs the differet gate types holders.
   * @param screening_gates The screening gates.
   * @param reservoir_gates The reservoir gates.
   * @param plunger_gates The plunger gates.
   * @param barrier_gates The barrier gates.
   * @param ohmics The ohmic contacts.
   */
  StandardConfigConnections(
      const device_structures::ConnectionsSP& screening_gates,
      const device_structures::ConnectionsSP& reservoir_gates,
      const device_structures::ConnectionsSP& plunger_gates,
      const device_structures::ConnectionsSP& barrier_gates,
      const device_structures::ConnectionsSP& ohmics);
  /**
   * @brief The screening gates from the config.
   * @return The screening gates.
   */
  const device_structures::ConnectionsSP& screening_gates() const;
  /**
   * @brief The reservoir gates from the config.
   * @return The reservoir gates.
   */
  const device_structures::ConnectionsSP& reservoir_gates() const;
  /**
   * @brief The plunger gates from the config.
   * @return The plunger gates.
   */
  const device_structures::ConnectionsSP& plunger_gates() const;
  /**
   * @brief The barrier gates from the config.
   * @return The barrier gates.
   */
  const device_structures::ConnectionsSP& barrier_gates() const;
  /**
   * @brief The ohmics from the config.
   * @return The ohmics gates.
   */
  const device_structures::ConnectionsSP& ohmics() const;
  /**
   * @brief Gets the connections of type as supplied.
   * @param conn_type The type of connection to get. The types of supported
   * connections are: Connection, Connection, Connection, Connection,
   * Connection, DotGate, Gate. and Connection
   * @returns the plural form of the connection type. This corresponds to the
   * conn_type
   */
  const device_structures::ConnectionsSP dot_gates() const;
  /**
   * @brief Gets the first ohmic connection.
   */
  const device_structures::ConnectionSP get_ohmic() const;
  /**
   * @brief Gets the first barrier gate connection.
   */
  const device_structures::ConnectionSP get_barrier_gate() const;
  /**
   * @brief Gets the first plunger gate connection.
   */
  const device_structures::ConnectionSP get_plunger_gate() const;
  /**
   * @brief Gets the first reservoir gate connection..
   */
  const device_structures::ConnectionSP get_reservoir_gate() const;
  /**
   * @brief Gets the first screening gate connection.
   */
  const device_structures::ConnectionSP get_screening_gate() const;
  /**
   * @brief Gets the first dot gate connection.
   */
  const device_structures::ConnectionSP get_dot_gate() const;
  /**
   * @brief Gets the first gate connection.
   */
  const device_structures::ConnectionSP get_gate() const;
  /**
   * @brief Gets all of the gates for this collection from the config.
   */
  const device_structures::ConnectionsSP get_all_gates() const;
  /**
   * @brief Gets all of the connections for this collection from the config.
   */
  const device_structures::ConnectionsSP get_all_connections() const;
  /**
   * @brief If this ohmic is a member of this group or not.
   */
  bool has_ohmic(const device_structures::ConnectionSP& ohmic) const;
  /**
   * @brief If this gate is a member of this group or not.
   */
  bool has_gate(const device_structures::ConnectionSP& gate) const;
  /**
   * @brief If this gate is a barriergate of this group or not.
   */
  bool has_barrier_gate(const device_structures::ConnectionSP& gate) const;
  /**
   * @brief If this gate is a plungergate of this group or not.
   */
  bool has_plunger_gate(const device_structures::ConnectionSP& gate) const;
  /**
   * @brief If this gate is a reservoirgate of this group or not.
   */
  bool has_reservoir_gate(const device_structures::ConnectionSP& gate) const;
  /**
   * @brief If this gate is a screeninggate of this group or not.
   */
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
