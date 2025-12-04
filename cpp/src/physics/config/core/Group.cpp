#include "falcon_core/physics/config/core/Group.hpp"

#include <stdexcept>

#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {

namespace {
device_structures::ConnectionsSP extract_ohmics(
    const device_structures::ConnectionsSP& order) {
  if (!order) {
    return std::make_shared<device_structures::Connections>();
  }
  auto ohmics = std::make_shared<device_structures::Connections>();
  for (const auto& conn : *order) {
    if (conn->is_ohmic()) {
      ohmics->push_back(conn);
    }
  }
  return ohmics;
}
}  // namespace
Group::Group(const Group& other) : StandardConfigConnections(other) {
  std::unique_lock<std::shared_timed_mutex> lock_name(_mu_name,
                                                      std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_num_dots(_mu_num_dots,
                                                          std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_order(_mu_order,
                                                       std::defer_lock);
  std::lock(lock_name, lock_num_dots, lock_order);
  if (!other.name()) {
    throw std::invalid_argument("Group: the channel must not be null.");
  }
  _name = std::make_shared<autotuner_interfaces::names::Channel>(*other.name());
  _num_dots = other.num_dots();
  if (!other.order()) {
    throw std::invalid_argument("Group: the order must not be null.");
  }
  _order = std::make_shared<geometries::GateGeometryArray1D>(*other.order());
}
Group Group::operator=(const Group& other) {
  if (this != &other) {
    StandardConfigConnections::               operator=(other);
    std::unique_lock<std::shared_timed_mutex> lock_name(_mu_name,
                                                        std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_num_dots(_mu_num_dots,
                                                            std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_order(_mu_order,
                                                         std::defer_lock);
    std::lock(lock_name, lock_num_dots, lock_order);
    if (!other.name()) {
      throw std::invalid_argument("Group: the channel must not be null.");
    }
    _name =
        std::make_shared<autotuner_interfaces::names::Channel>(*other.name());
    _num_dots = other.num_dots();
    if (!other.order()) {
      throw std::invalid_argument("Group: the order must not be null.");
    }
    _order = std::make_shared<geometries::GateGeometryArray1D>(*other.order());
  }
  return *this;
}

Group::Group() = default;
Group::Group(const autotuner_interfaces::names::ChannelSP& name,
             const int&                                    num_dots,
             const device_structures::ConnectionsSP&       screening_gates,
             const device_structures::ConnectionsSP&       reservoir_gates,
             const device_structures::ConnectionsSP&       plunger_gates,
             const device_structures::ConnectionsSP&       barrier_gates,
             const device_structures::ConnectionsSP&       order)
    : StandardConfigConnections(screening_gates,
                                reservoir_gates,
                                plunger_gates,
                                barrier_gates,
                                extract_ohmics(order)),
      _name(name),
      _num_dots(num_dots),
      _order(std::make_shared<geometries::GateGeometryArray1D>(
          order, screening_gates)) {
  if (!name) {
    throw std::invalid_argument("Group: the channel must not be null.");
  }
}
const device_structures::ConnectionsSP Group::ohmics() const {
  return StandardConfigConnections::ohmics();
}
const autotuner_interfaces::names::ChannelSP& Group::name() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_name);
  return _name;
}
const int& Group::num_dots() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_num_dots);
  return _num_dots;
}
const geometries::GateGeometryArray1DSP& Group::order() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_order);
  return _order;
}
bool Group::has_channel(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (!channel) {
    throw std::invalid_argument("Group: The channel must not be null.");
  }
  return *name() == *channel;
}
bool Group::is_charge_sensor() const { return num_dots() == 1; }
device_structures::ConnectionsSP Group::get_all_channel_gates(
    const autotuner_interfaces::names::ChannelSP& channel) const {
  if (has_channel(channel)) {
    return get_all_gates();
  }
  return std::make_shared<device_structures::Connections>();
}
bool Group::operator==(const Group& other) const {
  return (*name() == *other.name()) && (num_dots() == other.num_dots()) &&
         (*order() == *other.order()) &&
         (*screening_gates() == *other.screening_gates()) &&
         (*reservoir_gates() == *other.reservoir_gates()) &&
         (*plunger_gates() == *other.plunger_gates()) &&
         (*barrier_gates() == *other.barrier_gates());
}

bool Group::operator!=(const Group& other) const { return !(*this == other); }
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::Group)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::core::StandardConfigConnections,
    falcon_core::physics::config::core::Group)
