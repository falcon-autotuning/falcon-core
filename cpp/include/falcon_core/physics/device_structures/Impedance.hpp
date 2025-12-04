#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

class Impedance : public generic::Song {
  std::shared_ptr<Connection>     _connection;
  double                          _resistance;
  double                          _capacitance;
  mutable std::shared_timed_mutex _mu_connection;
  mutable std::shared_timed_mutex _mu_resistance;
  mutable std::shared_timed_mutex _mu_capacitance;

 public:
  Impedance(const Impedance& other);
  Impedance& operator=(const Impedance& other);
  Impedance(std::shared_ptr<Connection> connection,
            double                      resistance,
            double                      capacitance);
  static std::shared_ptr<Impedance> create(const ConnectionSP connection,
                                           const double       resistance,
                                           const double       capacitance);
  /**
   * @brief Gets the connection leading to the fridge with this impedance
   * @return A shared pointer to the BaseConnection
   */
  ConnectionSP connection() const;
  /**
   * @brief Gets the resistance of the impedance
   * @return The resistance in ohms
   */
  double resistance() const;
  /**
   * @brief Gets the capacitance of the impedance
   * @return The capacitance in farads
   */
  double capacitance() const;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_connection(_mu_connection,
                                                              std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_resistance(_mu_resistance,
                                                              std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_capacitance(_mu_capacitance,
                                                               std::defer_lock);
    std::lock(lock_connection, lock_resistance, lock_capacitance);
    ar(cereal::base_class<generic::Song>(this),
       _connection,
       _resistance,
       _capacitance);
  }
  bool operator==(const Impedance& other) const;
  bool operator!=(const Impedance& other) const;

 protected:
  Impedance();
  friend class cereal::access;
};
using ImpedanceSP = std::shared_ptr<Impedance>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
