#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core::physics::device_structures {
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
  static std::shared_ptr<Connection> BarrierGate(const std::string& name);
  static std::shared_ptr<Connection> PlungerGate(const std::string& name);
  static std::shared_ptr<Connection> ReservoirGate(const std::string& name);
  static std::shared_ptr<Connection> ScreeningGate(const std::string& name);
  static std::shared_ptr<Connection> Ohmic(const std::string& name);
  /**
   * @brief The name of the connection.
   * @return The name as a string.
   */
  std::string name() const;
  /**
   * @brief The type of the connection.
   * @return The type as a string.
   */
  std::string type() const;
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

 protected:
  friend class cereal::access;
  Connection();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<falcon_core::generic::Song>(this), _name, _type);
  }
};
using ConnectionSP = std::shared_ptr<Connection>;
}  // namespace falcon_core::physics::device_structures
