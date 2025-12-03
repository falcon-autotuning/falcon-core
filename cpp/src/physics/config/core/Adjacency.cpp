#include "falcon_core/physics/config/core/Adjacency.hpp"

#include <stdexcept>

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
Adjacency::Adjacency(const Adjacency& other) {
  std::shared_lock<std::shared_timed_mutex> lock_indexes(other._mu_indexes);
  _indexes = other._indexes;
  generic::FArray<int>::operator=(other);
}
Adjacency Adjacency::operator=(const Adjacency& other) {
  if (this != &other) {
    std::shared_lock<std::shared_timed_mutex> lock_other_indexes(
        other._mu_indexes, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_indexes(_mu_indexes,
                                                           std::defer_lock);
    std::lock(lock_indexes, lock_other_indexes);
    _indexes = other._indexes;
    generic::FArray<int>::operator=(other);
  }
  return *this;
}
Adjacency::Adjacency() = default;
Adjacency::Adjacency(const xt::xarray<int>& matrix, const Indexes indexes)
    : _indexes(indexes), generic::FArray<int>(matrix) {
  if (!indexes) {
    throw std::invalid_argument("Adjacency: The indexes cannot be null.");
  }
}
Adjacency::Indexes Adjacency::indexes() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_indexes);
  return _indexes;
}
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
bool Adjacency::operator==(const Adjacency& other) const {
  return (*indexes() == *other.indexes()) && (FArray::operator==(other));
}
bool Adjacency::operator!=(const Adjacency& other) const {
  return !(*this == other);
}
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::Adjacency)
CEREAL_REGISTER_TYPE(falcon_core::generic::FArray<int>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::FArray<int>,
    falcon_core::physics::config::core::Adjacency)
