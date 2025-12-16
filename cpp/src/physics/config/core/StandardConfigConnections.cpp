#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"

#include <memory>
#include <stdexcept>

#include "falcon_core/physics/device_structures/Connections.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
StandardConfigConnections::StandardConfigConnections(
    const StandardConfigConnections& other) {
  std::unique_lock<std::shared_timed_mutex> lock_screening_gates(
      _mu_screening_gates, std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_reservoir_gates(
      _mu_reservoir_gates, std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_plunger_gates(
      _mu_plunger_gates, std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_barrier_gates(
      _mu_barrier_gates, std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_ohmics(_mu_ohmics,
                                                        std::defer_lock);
  std::lock(lock_screening_gates,
            lock_reservoir_gates,
            lock_plunger_gates,
            lock_barrier_gates,
            lock_ohmics);
  if (!other.screening_gates() || !other.reservoir_gates() ||
      !other.plunger_gates() || !other.barrier_gates() || !other.ohmics()) {
    throw std::invalid_argument(
        "StandardConfigConnections: The screening_gates, reservoir_gates, "
        "plunger_gates, barrier_gates, and ohmics of the other "
        "StandardConfigConnections are not allowed to not be null.");
  }
  _screening_gates = std::make_shared<device_structures::Connections>(
      *other.screening_gates());
  _reservoir_gates = std::make_shared<device_structures::Connections>(
      *other.reservoir_gates());
  _plunger_gates =
      std::make_shared<device_structures::Connections>(*other.plunger_gates());
  _barrier_gates =
      std::make_shared<device_structures::Connections>(*other.barrier_gates());
  _ohmics = std::make_shared<device_structures::Connections>(*other.ohmics());
}
StandardConfigConnections& StandardConfigConnections::operator=(
    const StandardConfigConnections& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_screening_gates(
        _mu_screening_gates, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_reservoir_gates(
        _mu_reservoir_gates, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_plunger_gates(
        _mu_plunger_gates, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_barrier_gates(
        _mu_barrier_gates, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_ohmics(_mu_ohmics,
                                                          std::defer_lock);
    std::lock(lock_screening_gates,
              lock_reservoir_gates,
              lock_plunger_gates,
              lock_barrier_gates,
              lock_ohmics);
    if (!other.screening_gates() || !other.reservoir_gates() ||
        !other.plunger_gates() || !other.barrier_gates() || !other.ohmics()) {
      throw std::invalid_argument(
          "StandardConfigConnections: The screening_gates, reservoir_gates, "
          "plunger_gates, barrier_gates, and ohmics of the other "
          "StandardConfigConnections are not allowed to not be null.");
    }
    _screening_gates = std::make_shared<device_structures::Connections>(
        *other.screening_gates());
    _reservoir_gates = std::make_shared<device_structures::Connections>(
        *other.reservoir_gates());
    _plunger_gates = std::make_shared<device_structures::Connections>(
        *other.plunger_gates());
    _barrier_gates = std::make_shared<device_structures::Connections>(
        *other.barrier_gates());
    _ohmics = std::make_shared<device_structures::Connections>(*other.ohmics());
  }
  return *this;
}
StandardConfigConnections::StandardConfigConnections()
    : _screening_gates(std::make_shared<device_structures::Connections>()),
      _reservoir_gates(std::make_shared<device_structures::Connections>()),
      _plunger_gates(std::make_shared<device_structures::Connections>()),
      _barrier_gates(std::make_shared<device_structures::Connections>()),
      _ohmics(std::make_shared<device_structures::Connections>()) {}
StandardConfigConnections::StandardConfigConnections(
    const device_structures::ConnectionsSP& screening_gates,
    const device_structures::ConnectionsSP& reservoir_gates,
    const device_structures::ConnectionsSP& plunger_gates,
    const device_structures::ConnectionsSP& barrier_gates,
    const device_structures::ConnectionsSP& ohmics)
    : _screening_gates(screening_gates),
      _reservoir_gates(reservoir_gates),
      _plunger_gates(plunger_gates),
      _barrier_gates(barrier_gates),
      _ohmics(ohmics) {
  if (!screening_gates || !reservoir_gates || !plunger_gates ||
      !barrier_gates || !ohmics) {
    throw std::invalid_argument(
        "StandardConfigConnections: The screening_gates, reservoir_gates, "
        "plunger_gates, barrier_gates, and ohmics are not allowed to not be "
        "null.");
  }
  if (!_screening_gates->is_screening_gates()) {
    throw std::runtime_error(
        "StandardConfigConnections: Expected all the gates in the "
        "screening_gates to be screening gates.");
  }
  if (!_reservoir_gates->is_reservoir_gates()) {
    throw std::runtime_error(
        "StandardConfigConnections: Expected all the gates in the "
        "reservoir_gates to be reservoir gates.");
  }
  if (!_plunger_gates->is_plunger_gates()) {
    throw std::runtime_error(
        "StandardConfigConnections: Expected all the gates in the "
        "plunger_gates to be plunger gates.");
  }
  if (!_barrier_gates->is_barrier_gates()) {
    throw std::runtime_error(
        "StandardConfigConnections: Expected all the gates in the "
        "barrier_gates to be barrier gates.");
  }
  if (!_ohmics->is_ohmics()) {
    throw std::runtime_error(
        "StandardConfigConnections: Expected all the connections in the ohmics "
        "to be ohmic.");
  }
}
const device_structures::ConnectionsSP&
StandardConfigConnections::screening_gates() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_screening_gates);
  return _screening_gates;
}
const device_structures::ConnectionsSP&
StandardConfigConnections::reservoir_gates() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_reservoir_gates);
  return _reservoir_gates;
}
const device_structures::ConnectionsSP&
StandardConfigConnections::plunger_gates() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_plunger_gates);
  return _plunger_gates;
}
const device_structures::ConnectionsSP&
StandardConfigConnections::barrier_gates() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_barrier_gates);
  return _barrier_gates;
}
const device_structures::ConnectionsSP& StandardConfigConnections::ohmics()
    const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_ohmics);
  return _ohmics;
}
const device_structures::ConnectionsSP StandardConfigConnections::dot_gates()
    const {
  device_structures::Connections combination = device_structures::Connections();
  auto total_collection = std::vector<device_structures::ConnectionsSP>{
      plunger_gates(), barrier_gates()};
  for (const device_structures::ConnectionsSP& collection : total_collection) {
    for (const device_structures::ConnectionSP& connection : *collection) {
      combination.push_back(connection);
    }
  }
  return std::make_shared<device_structures::Connections>(combination);
}
const device_structures::ConnectionSP StandardConfigConnections::get_ohmic()
    const {
  return ohmics()->at(0);
}
const device_structures::ConnectionSP
StandardConfigConnections::get_barrier_gate() const {
  return barrier_gates()->at(0);
}
const device_structures::ConnectionSP
StandardConfigConnections::get_plunger_gate() const {
  return plunger_gates()->at(0);
}
const device_structures::ConnectionSP
StandardConfigConnections::get_reservoir_gate() const {
  return reservoir_gates()->at(0);
}
const device_structures::ConnectionSP
StandardConfigConnections::get_screening_gate() const {
  return screening_gates()->at(0);
}
const device_structures::ConnectionSP StandardConfigConnections::get_dot_gate()
    const {
  if (plunger_gates()->size() > 0) {
    return plunger_gates()->at(0);
  } else if (barrier_gates()->size() > 0) {
    return barrier_gates()->at(0);
  } else {
    return nullptr;
  }
}
const device_structures::ConnectionSP StandardConfigConnections::get_gate()
    const {
  if (plunger_gates()->size() > 0) {
    return plunger_gates()->at(0);
  } else if (barrier_gates()->size() > 0) {
    return barrier_gates()->at(0);
  } else if (reservoir_gates()->size() > 0) {
    return reservoir_gates()->at(0);
  } else if (screening_gates()->size() > 0) {
    return screening_gates()->at(0);
  } else {
    return nullptr;
  }
}
const device_structures::ConnectionsSP
StandardConfigConnections::get_all_gates() const {
  device_structures::ConnectionsSP combination =
      std::make_shared<device_structures::Connections>();
  auto total_collection = std::vector<device_structures::ConnectionsSP>{
      barrier_gates(), plunger_gates(), screening_gates(), reservoir_gates()};
  for (const auto collection : total_collection) {
    auto coll = *collection;
    for (const device_structures::ConnectionSP& connection : coll) {
      combination->push_back(connection);
    }
  }
  return combination;
}
const device_structures::ConnectionsSP
StandardConfigConnections::get_all_connections() const {
  device_structures::ConnectionsSP combination =
      std::make_shared<device_structures::Connections>();
  auto total_collection =
      std::vector<device_structures::ConnectionsSP>{get_all_gates(), ohmics()};
  for (const auto collection : total_collection) {
    for (const device_structures::ConnectionSP& connection : *collection) {
      combination->push_back(connection);
    }
  }
  return combination;
}
bool StandardConfigConnections::has_ohmic(
    const device_structures::ConnectionSP& ohmic) const {
  if (!ohmic) {
    throw std::invalid_argument(
        "StandardConfigConnections: The ohmic has to not be null.");
  }
  auto ohmics_list = *ohmics();
  for (auto& o : ohmics_list) {
    if (*o == *ohmic) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_gate(
    const device_structures::ConnectionSP& gate) const {
  if (!gate) {
    throw std::invalid_argument(
        "StandardConfigConnections: The gate has to not be null.");
  }
  auto all_gates = get_all_gates();
  for (const device_structures::ConnectionSP& g : *all_gates) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_barrier_gate(
    const device_structures::ConnectionSP& gate) const {
  if (!gate) {
    throw std::invalid_argument(
        "StandardConfigConnections: The gate has to not be null.");
  }
  auto barrier_gates_list = *barrier_gates();
  for (const device_structures::ConnectionSP& g : barrier_gates_list) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_plunger_gate(
    const device_structures::ConnectionSP& gate) const {
  if (!gate) {
    throw std::invalid_argument(
        "StandardConfigConnections: The gate has to not be null.");
  }
  auto plunger_gates_list = *plunger_gates();
  for (const device_structures::ConnectionSP& g : plunger_gates_list) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_reservoir_gate(
    const device_structures::ConnectionSP& gate) const {
  if (!gate) {
    throw std::invalid_argument(
        "StandardConfigConnections: The gate has to not be null.");
  }
  auto reservoir_gates_list = *reservoir_gates();
  for (const device_structures::ConnectionSP& g : reservoir_gates_list) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_screening_gate(
    const device_structures::ConnectionSP& gate) const {
  if (!gate) {
    throw std::invalid_argument(
        "StandardConfigConnections: The gate has to not be null.");
  }
  auto screening_gates_list = *screening_gates();
  for (const device_structures::ConnectionSP& g : screening_gates_list) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::operator==(
    const StandardConfigConnections& other) const {
  if (this == &other) return true;
  return (*screening_gates() == *other.screening_gates()) &&
         (*reservoir_gates() == *other.reservoir_gates()) &&
         (*plunger_gates() == *other.plunger_gates()) &&
         (*barrier_gates() == *other.barrier_gates()) &&
         (*ohmics() == *other.ohmics());
}
bool StandardConfigConnections::operator!=(
    const StandardConfigConnections& other) const {
  return !(*this == other);
}

}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::core::StandardConfigConnections)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::core::StandardConfigConnections)
