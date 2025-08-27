#include "falcon_core/physics/config/core/Adjacency.hpp"

using namespace falcon_core::physics::config::core;

std::vector<std::pair<int, int>> Adjacency::get_true_pairs() const {
  std::vector<std::pair<int, int>> true_pairs;
  for (int i = 0; i < _matrix.rows(); ++i) {
    for (int j = i; j < _matrix.cols(); ++j) {
      if (_matrix(i, j) == 1) {
        true_pairs.push_back(std::pair<int, int>(i, j));
      }
    }
  }
  return true_pairs;
}
