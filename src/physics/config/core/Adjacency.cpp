#include "falcon_core/physics/config/core/Adjacency.hpp"

#include <stdexcept>

namespace falcon_core::physics::config::core {
Adjacency::Adjacency() = default;
Adjacency::Adjacency(const xt::xarray<int>& matrix, const Indexes indexes)
    : _indexes(indexes), generic::FArray<int>(matrix) {
  if (!indexes) {
    throw std::invalid_argument("Adjacency: The indexes cannot be null.");
  }
}
Adjacency::Indexes Adjacency::indexes() const { return _indexes; }
std::vector<std::pair<size_t, size_t>> Adjacency::get_true_pairs() const {
  std::vector<std::pair<size_t, size_t>> true_pairs;
  for (int i = 0; i < this->shape()[0]; ++i) {
    for (int j = i; j < this->shape()[1]; ++j) {
      if ((*this)(i, j) == 1) {
        true_pairs.push_back(std::pair<size_t, size_t>(i, j));
      }
    }
  }
  return true_pairs;
}
}  // namespace falcon_core::physics::config::core
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::Adjacency)
CEREAL_REGISTER_TYPE(falcon_core::generic::FArray<int>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::FArray<int>,
    falcon_core::physics::config::core::Adjacency)
