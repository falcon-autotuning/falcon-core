#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
enum class DeviceFeature {
  BarrierGate,
  PlungerGate,
  ReservoirGate,
  ScreeningGate,
  Ohmic
};
class Connection : public virtual generic::Song {
  std::string   _name;
  DeviceFeature _type;

 public:
  bool operator<(const Connection& other) const;
  /**
   * @brief Construct a Connection with a name and type.
   * @param name The name of the connection.
   * @param type The type of the connection (DeviceFeature).
   */
  Connection(const std::string& name, const DeviceFeature& type);
  /**
   * @brief Construct a BarrierGate with a name.
   * @param name The name of the connection.
   */
  static std::shared_ptr<Connection> BarrierGate(const std::string& name);
  /**
   * @brief Construct a PlungerGate with a name.
   * @param name The name of the connection.
   */
  static std::shared_ptr<Connection> PlungerGate(const std::string& name);
  /**
   * @brief Construct a ReservoirGate with a name.
   * @param name The name of the connection.
   */
  static std::shared_ptr<Connection> ReservoirGate(const std::string& name);
  /**
   * @brief Construct a ScreeningGate with a name.
   * @param name The name of the connection.
   */
  static std::shared_ptr<Connection> ScreeningGate(const std::string& name);
  /**
   * @brief Construct a Ohmic with a name.
   * @param name The name of the connection.
   */
  static std::shared_ptr<Connection> Ohmic(const std::string& name);
  /**
   * @brief The name of the connection.
   * @return The name as a string.
   */
  const std::string& name() const;
  /**
   * @brief The type of the connection.
   * @return The type as a string.
   */
  const std::string type() const;
  /**
   * @brief Check if the connection is a plungergate or barriergate.
   */
  bool is_dot_gate() const;
  /**
   * @brief Check if the connection is a barriergate.
   */
  bool is_barrier_gate() const;
  /**
   * @brief Check if the connection is a plunger gate.
   */
  bool is_plunger_gate() const;
  /**
   * @brief Check if the connection is a reservoir gate.
   */
  bool is_reservoir_gate() const;
  /**
   * @brief Check if the connection is a screening gate.
   */
  bool is_screening_gate() const;
  /**
   * @brief Check if the connection is an ohmic contact.
   */
  bool is_ohmic() const;
  /**
   * @brief Check if the connection is any type of gate (barrier, plunger,
   * reservoir, screening).
   */
  bool is_gate() const;
  bool operator==(const Connection& other) const;
  bool operator!=(const Connection& other) const;

 protected:
  friend class cereal::access;
  Connection();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<falcon_core::generic::Song>(this), _name, _type);
  }
};
using ConnectionSP = std::shared_ptr<Connection>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
