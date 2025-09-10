#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

class Impedance : public generic::Song {
  std::shared_ptr<BaseConnection> _connection;
  double                          _resistance;
  double                          _capacitance;

 public:
  Impedance(std::shared_ptr<BaseConnection> connection,
            double                          resistance,
            double                          capacitance);
  /*
   * @brief Gets the connection leading to the fridge with this impedance
   * @return A shared pointer to the BaseConnection
   */
  BaseConnectionSP connection() const;
  /*
   * @brief Gets the resistance of the impedance
   * @return The resistance in ohms
   */
  double resistance() const;
  /*
   * @brief Gets the capacitance of the impedance
   * @return The capacitance in farads
   */
  double capacitance() const;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       _connection,
       _resistance,
       _capacitance);
  }

 protected:
  Impedance();
  friend class cereal::access;
};
using ImpedanceSP = std::shared_ptr<Impedance>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
