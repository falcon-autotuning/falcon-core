#include "falcon_core/physics/config/core/Adjacency.hpp"

#include <stdexcept>

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
Adjacency::Adjacency(const Adjacency& other) : generic::FArray<int>(other) {
  auto inds = other.indexes();
  if (!inds) {
    throw std::invalid_argument("Adjacency: The indexes cannot be null.");
  }
  _indexes = std::make_shared<device_structures::Connections>(*inds);
}
Adjacency& Adjacency::operator=(const Adjacency& other) {
  if (this != &other) {
    generic::FArray<int>::operator=(other);
    std::unique_lock<std::shared_timed_mutex> lock_indexes(_mu_indexes);
    auto                                      inds = other.indexes();
    if (!inds) {
      throw std::invalid_argument("Adjacency: The indexes cannot be null.");
    }
    _indexes = std::make_shared<device_structures::Connections>(*inds);
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
  if (this == &other) return true;
  return (*indexes() == *other.indexes()) && (FArray::operator==(other));
}
bool Adjacency::operator!=(const Adjacency& other) const {
  return !(*this == other);
}
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
