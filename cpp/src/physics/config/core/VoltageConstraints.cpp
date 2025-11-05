#include "falcon_core/physics/config/core/VoltageConstraints.hpp"

#include <stdexcept>

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
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
  std::fill(this->_limits.data(),
            this->_limits.data() + adjacency->shape()[0],
            std::abs(bounds.second));
  std::fill(this->_limits.data() + adjacency->shape()[0],
            this->_limits.data() + 2 * adjacency->shape()[0],
            std::abs(bounds.first));
  std::fill(this->_limits.data() + 2 * adjacency->shape()[0],
            this->_limits.data() + 2 * adjacency->shape()[0] + 2 * pairs.size(),
            max_safe_diff);
}
const generic::FArray<double>& VoltageConstraints::matrix() const {
  return _matrix;
}
const generic::FArray<double>& VoltageConstraints::matrix() { return _matrix; }

const AdjacencySP VoltageConstraints::adjacency() const { return _adjacency; }

const generic::FArray<double>& VoltageConstraints::limits() const {
  return _limits;
}

bool VoltageConstraints::operator==(const VoltageConstraints& other) const {
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
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::VoltageConstraints)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::core::VoltageConstraints)
