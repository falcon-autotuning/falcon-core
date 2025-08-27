#include "falcon_core/physics/config/core/VoltageConstraints.hpp"

using namespace falcon_core::physics::config::core;

VoltageConstraints::VoltageConstraints(const AdjacencySP         adjacency,
                                       double                    max_safe_diff,
                                       std::pair<double, double> bounds)
    : _adjacency(adjacency) {
  std::vector<std::pair<int, int>> pairs = this->adjacency()->get_true_pairs();
  // So the first n rows are for the identity comparison for each gate.
  // The second n rows are for the negative identity comparison for each gate.
  // The next rows are for the pairs of connected gates, one row for each pair.
  // Since each can be positive or negative
  int        H = 2 * adjacency->size() + 2 * pairs.size();
  int        W = adjacency->size();
  MatrixType matrix(H, W);
  MatrixType Imatrix =
      Eigen::MatrixXd::Identity(adjacency->size(), adjacency->size());
  MatrixType invImatrix =
      -1 * Eigen::MatrixXd::Identity(adjacency->size(), adjacency->size());
  MatrixType pairMatrix = MatrixType::Zero(2 * pairs.size(), W);
  // Creates pairs of constraint equations for every set of connected gates
  for (int i = 0; i < pairs.size(); i++) {
    int a = pairs[i].first;
    int b = pairs[i].second;
    if (a < 0 || a >= W || b < 0 || b >= W) {
      std::cerr << "Invalid pair index: (" << a << ", " << b << "), W=" << W
                << std::endl;
      continue;  // or throw/assert
    }
    pairMatrix(2 * i, a)     = 1;
    pairMatrix(2 * i, b)     = -1;
    pairMatrix(2 * i + 1, a) = -1;
    pairMatrix(2 * i + 1, b) = 1;
  }
  matrix << Imatrix, invImatrix, pairMatrix;

  MatrixType limits(H, 1);
  std::fill(
      limits.data(), limits.data() + 2 * adjacency->size(), bounds.second);
  std::fill(limits.data() + 2 * adjacency->size(),
            limits.data() + 2 * adjacency->size() + pairs.size(),
            max_safe_diff);
}
