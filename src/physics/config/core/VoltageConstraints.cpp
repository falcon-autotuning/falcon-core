#include "falcon_core/physics/config/core/VoltageConstraints.hpp"

#include <stdexcept>

namespace falcon_core::physics::config::core {
VoltageConstraints::VoltageConstraints() = default;
VoltageConstraints::VoltageConstraints(const AdjacencySP         adjacency,
                                       double                    max_safe_diff,
                                       std::pair<double, double> bounds)
    : _adjacency(adjacency), _limits(bounds) {
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
  size_t                  H      = 2 * adjacency->size() + 2 * pairs.size();
  size_t                  W      = adjacency->size();
  generic::FArray<double> matrix = *generic::FArray<double>::zeros({H, W});
  generic::FArray<double> Imatrix =
      generic::FArray<double>(xt::eye(adjacency->size()));
  generic::FArray<double> invImatrix =
      generic::FArray<double>(-xt::eye(adjacency->size()));
  generic::FArray<double> pairMatrix =
      *generic::FArray<double>::zeros({2 * pairs.size(), W});
  // Creates pairs of constraint equations for every set of connected gates
  for (size_t i = 0; i < pairs.size(); i++) {
    size_t a = pairs[i].first;
    size_t b = pairs[i].second;
    // a && b < W always
    pairMatrix(2 * i, a)     = 1;
    pairMatrix(2 * i, b)     = -1;
    pairMatrix(2 * i + 1, a) = -1;
    pairMatrix(2 * i + 1, b) = 1;
  }
  matrix = generic::FArray<double>(xt::vstack(xt::xtuple(
      Imatrix.xtensor(), invImatrix.xtensor(), pairMatrix.xtensor())));

  generic::FArray<double> limits = *generic::FArray<double>::zeros({H, 1});
  std::fill(
      limits.data(), limits.data() + 2 * adjacency->size(), bounds.second);
  std::fill(limits.data() + 2 * adjacency->size(),
            limits.data() + 2 * adjacency->size() + pairs.size(),
            max_safe_diff);
}
const generic::FArray<double>& VoltageConstraints::matrix() const {
  return _matrix;
}
/**
 * @brief The constraint matrix.
 */
generic::FArray<double>& VoltageConstraints::matrix() { return _matrix; }
/**
 * @brief The adjacency matrix used to understand the device layout.
 */
AdjacencySP VoltageConstraints::adjacency() const { return _adjacency; }
/**
 * @brief The (min,max) safe voltage limits for each constraint.
 */
std::pair<float, float> VoltageConstraints::limits() const { return _limits; }
}  // namespace falcon_core::physics::config::core
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::VoltageConstraints)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::core::VoltageConstraints)
