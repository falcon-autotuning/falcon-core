#include "falcon-core/physics/config/core/VoltageConstraints.hpp"

#include <stdexcept>

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
VoltageConstraints::VoltageConstraints(const VoltageConstraints& other) {
  std::unique_lock<std::shared_timed_mutex> lock_adjacency(_mu_adjacency,
                                                           std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_matrix(_mu_matrix,
                                                        std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_limits(_mu_limits,
                                                        std::defer_lock);
  std::lock(lock_adjacency, lock_matrix, lock_limits);
  if (!other.adjacency()) {
    throw std::invalid_argument(
        "VoltageConstraints: The adjacency matrix of the other object is "
        "null.");
  }
  _adjacency = std::make_shared<Adjacency>(*other.adjacency());
  _matrix    = *std::make_shared<generic::FArray<double>>(other.matrix());
  _limits    = *std::make_shared<generic::FArray<double>>(other.limits());
}
VoltageConstraints& VoltageConstraints::operator=(
    const VoltageConstraints& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_adjacency(_mu_adjacency,
                                                             std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_matrix(_mu_matrix,
                                                          std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_limits(_mu_limits,
                                                          std::defer_lock);
    std::lock(lock_adjacency, lock_matrix, lock_limits);
    if (!other.adjacency()) {
      throw std::invalid_argument(
          "VoltageConstraints: The adjacency matrix of the other object is "
          "null.");
    }
    _adjacency = std::make_shared<Adjacency>(*other.adjacency());
    _matrix    = *std::make_shared<generic::FArray<double>>(other.matrix());
    _limits    = *std::make_shared<generic::FArray<double>>(other.limits());
  }
  return *this;
}
VoltageConstraints::VoltageConstraints() = default;
VoltageConstraints::VoltageConstraints(const AdjacencySP         adjacency,
                                       double                    max_safe_diff,
                                       std::pair<double, double> bounds)
    : _adjacency(adjacency) {
  if (!adjacency) {
    throw std::invalid_argument(
        "VoltageConstraints: The adjacency matrix needs to not be null.");
  }
  std::vector<std::pair<size_t, size_t>> pairs =
      this->adjacency()->get_true_pairs();
  // So the first n rows are for the identity comparison for each gate.
  // The second n rows are for the negative identity comparison for each gate.
  // The next rows are for the pairs of connected gates, one row for each pair.
  // Since each can be positive or negative
  size_t H      = 2 * adjacency->shape()[0] + 2 * pairs.size();
  size_t W      = adjacency->shape()[0];
  this->_matrix = *generic::FArray<double>::zeros({H, W});
  // Fill identity block
  for (size_t i = 0; i < W; ++i) {
    this->_matrix(i, i)     = 1;
    this->_matrix(W + i, i) = -1;
  }
  // Fill pairMatrix block directly into matrix
  for (size_t i = 0; i < pairs.size(); ++i) {
    size_t row                = 2 * W + 2 * i;
    size_t a                  = pairs[i].first;
    size_t b                  = pairs[i].second;
    this->_matrix(row, a)     = 1;
    this->_matrix(row, b)     = -1;
    this->_matrix(row + 1, a) = -1;
    this->_matrix(row + 1, b) = 1;
  }
  this->_limits = *generic::FArray<double>::zeros({H, 1});
  std::fill(this->_limits.raw_data(),
            this->_limits.raw_data() + adjacency->shape()[0],
            std::abs(bounds.second));
  std::fill(this->_limits.raw_data() + adjacency->shape()[0],
            this->_limits.raw_data() + 2 * adjacency->shape()[0],
            std::abs(bounds.first));
  std::fill(
      this->_limits.raw_data() + 2 * adjacency->shape()[0],
      this->_limits.raw_data() + 2 * adjacency->shape()[0] + 2 * pairs.size(),
      max_safe_diff);
}
const generic::FArray<double>& VoltageConstraints::matrix() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_matrix);
  return _matrix;
}
const generic::FArray<double>& VoltageConstraints::matrix() {
  std::unique_lock<std::shared_timed_mutex> lock(_mu_matrix);
  return _matrix;
}

const AdjacencySP VoltageConstraints::adjacency() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_adjacency);
  return _adjacency;
}

const generic::FArray<double>& VoltageConstraints::limits() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_limits);
  return _limits;
}

bool VoltageConstraints::operator==(const VoltageConstraints& other) const {
  if (this == &other) return true;
  return (limits() == other.limits()) && (*adjacency() == *other.adjacency()) &&
         (matrix() == other.matrix());
}

bool VoltageConstraints::operator!=(const VoltageConstraints& other) const {
  return !(*this == other);
}
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
