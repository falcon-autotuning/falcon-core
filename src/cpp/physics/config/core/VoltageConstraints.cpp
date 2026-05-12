#include "falcon-core/physics/config/core/VoltageConstraints.hpp"

#include <list>
#include <stdexcept>

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
VoltageConstraints::VoltageConstraints(const VoltageConstraints &other) {
  std::unique_lock<std::shared_timed_mutex> lock_adjacency(_mu_adjacency,
                                                           std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_max_safe_diff(
      _mu_max_safe_diff, std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_min_bound(_mu_min_bound,
                                                           std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_max_bound(_mu_max_bound,
                                                           std::defer_lock);
  std::lock(lock_adjacency, lock_max_safe_diff, lock_min_bound, lock_max_bound);
  if (!other.adjacency()) {
    throw std::invalid_argument(
        "VoltageConstraints: The adjacency matrix of the other object is "
        "null.");
  }
  _adjacency = std::make_shared<Adjacency>(*other.adjacency());
  _max_safe_diff = other._max_safe_diff;
  _min_bound = other._min_bound;
  _max_bound = other._max_bound;
}
VoltageConstraints &
VoltageConstraints::operator=(const VoltageConstraints &other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_adjacency(_mu_adjacency,
                                                             std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_max_safe_diff(
        _mu_max_safe_diff, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_min_bound(_mu_min_bound,
                                                             std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_max_bound(_mu_max_bound,
                                                             std::defer_lock);
    std::lock(lock_adjacency, lock_max_safe_diff, lock_min_bound,
              lock_max_bound);
    if (!other.adjacency()) {
      throw std::invalid_argument(
          "VoltageConstraints: The adjacency matrix of the other object is "
          "null.");
    }
    _adjacency = std::make_shared<Adjacency>(*other.adjacency());
    _max_safe_diff = other._max_safe_diff;
    _min_bound = other._min_bound;
    _max_bound = other._max_bound;
  }
  return *this;
}
VoltageConstraints::VoltageConstraints() = default;
VoltageConstraints::VoltageConstraints(const AdjacencySP adjacency,
                                       double max_safe_diff,
                                       std::pair<double, double> bounds)
    : _adjacency(adjacency), _max_safe_diff(max_safe_diff),
      _min_bound(bounds.first), _max_bound(bounds.second) {
  if (!adjacency) {
    throw std::invalid_argument(
        "VoltageConstraints: The adjacency matrix cannot be null.");
  }
}

const AdjacencySP VoltageConstraints::adjacency() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_adjacency);
  return _adjacency;
}

const double VoltageConstraints::max_safe_diff() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_max_safe_diff);
  return _max_safe_diff;
}

const double VoltageConstraints::min_bound() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_min_bound);
  return _min_bound;
}

const double VoltageConstraints::max_bound() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_max_bound);
  return _max_bound;
}

math::domains::CoupledLabelledDomainSP
VoltageConstraints::compute_maximal_domain(
    const instrument_interfaces::names::PortsSP search_domain,
    const communications::voltage_states::DeviceVoltageStatesSP current_state)
    const {
  if (!search_domain || !current_state) {
    throw std::invalid_argument("VoltageConstraints: The search domain and "
                                "current state cannot be null.");
  }
  auto search_domain_deref = *search_domain;
  std::vector<math::domains::LabelledDomainSP> result_domains;
  const auto indexes = _adjacency->indexes();
  std::vector<std::pair<size_t, size_t>> true_pairs =
      _adjacency->get_true_pairs();
  std::list<std::pair<size_t, size_t>> pairs(true_pairs.begin(),
                                             true_pairs.end());
  auto search_domain_psuedo_names = search_domain->get_pseudo_names();
  for (const auto &port : search_domain_deref) {
    double max_val = _max_bound;
    double min_val = _min_bound;
    for (auto it = pairs.begin(); it != pairs.end();) {
      int port_index = indexes->index(port->pseudo_name());
      if ((it->first != port_index) && (it->second != port_index)) {
        ++it;
        continue;
      }
      device_structures::ConnectionSP neighbor;
      if (it->first == port_index) {
        neighbor = indexes->at(it->second);
      } else {
        neighbor = indexes->at(it->first);
      }
      if (!search_domain_psuedo_names->contains(neighbor)) {
        double upper_bound =
            current_state->find_state(neighbor)->voltage() + _max_safe_diff;
        if (upper_bound < max_val) {
          max_val = upper_bound;
        }
        double lower_bound =
            current_state->find_state(neighbor)->voltage() - _max_safe_diff;
        if (lower_bound > min_val) {
          min_val = lower_bound;
        }
      }
      // erase current and advance iterator
      it = pairs.erase(it);
    }
    // Construct the domain for this connection and add it to the result
    // domains
    falcon_core::math::domains::DomainSP domain =
        std::make_shared<math::domains::Domain>(min_val, max_val);
    result_domains.push_back(
        math::domains::LabelledDomain::from_port_and_domain(port, domain));
  }
  return std::make_shared<math::domains::CoupledLabelledDomain>(result_domains);
}

bool VoltageConstraints::validate_voltage_state(
    const math::PointSP voltage_state) const {
  if (!voltage_state) {
    throw std::invalid_argument(
        "VoltageConstraints: The voltage state to validate cannot be null.");
  }
  // First reject any voltage states that are outside the absolute bounds of
  // the device
  auto voltage_state_items = *voltage_state->items();
  for (const generic::PairSP<device_structures::Connection, math::Quantity>
           &item : voltage_state_items) {
    device_structures::ConnectionSP connection = item->first();
    double value = item->second()->value();
    if (value < _min_bound || value > _max_bound) {
      return false;
    }
  }
  auto indexes = _adjacency->indexes();
  std::vector<std::pair<size_t, size_t>> true_pairs =
      _adjacency->get_true_pairs();
  std::list<std::pair<size_t, size_t>> pairs(true_pairs.begin(),
                                             true_pairs.end());
  for (const generic::PairSP<device_structures::Connection, math::Quantity>
           &item : voltage_state_items) {
    device_structures::ConnectionSP connection = item->first();
    double value = item->second()->value();
    for (auto it = pairs.begin(); it != pairs.end();) {
      int port_index = indexes->index(connection);
      if ((it->first != port_index) && (it->second != port_index)) {
        ++it;
        continue;
      }
      device_structures::ConnectionSP neighbor;
      if (it->first == port_index) {
        neighbor = indexes->at(it->second);
      } else {
        neighbor = indexes->at(it->first);
      }
      double neighbor_value = voltage_state->at(neighbor)->value();
      if (std::abs(value - neighbor_value) > _max_safe_diff) {
        return false;
      }
      // erase current and advance iterator
      it = pairs.erase(it);
    }
  }
  return true;
}

bool VoltageConstraints::operator==(const VoltageConstraints &other) const {
  if (this == &other)
    return true;
  return (*adjacency() == *other.adjacency() &&
          max_safe_diff() == other.max_safe_diff() &&
          min_bound() == other.min_bound() && max_bound() == other.max_bound());
}

bool VoltageConstraints::operator!=(const VoltageConstraints &other) const {
  return !(*this == other);
}
} // namespace core
} // namespace config
} // namespace physics
} // namespace falcon_core
