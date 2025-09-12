#include "falcon_core/physics/config/core/Adjacency.hpp"

namespace falcon_core::physics::config::core {
Adjacency::Adjacency() = default;
Adjacency::Adjacency(const xt::xarray<int> &matrix, const Indexes indexes)
    : _indexes(indexes), generic::FArray<int>(matrix) {}
Adjacency::Indexes               Adjacency::indexes() const { return _indexes; }
std::vector<std::pair<int, int>> Adjacency::get_true_pairs() const {
  std::vector<std::pair<int, int>> true_pairs;
  for (int i = 0; i < this->shape()[0]; ++i) {
    for (int j = i; j < this->shape()[1]; ++j) {
      if ((*this)(i, j) == 1) {
        true_pairs.push_back(std::pair<int, int>(i, j));
      }
    }
  }
  return true_pairs;
}
template <class Archive>
void Adjacency::serialize(Archive &ar) {
  ar(cereal::base_class<generic::FArray<int>>(this), _indexes);
}
}  // namespace falcon_core::physics::config::core
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::Adjacency)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::physics::config::core::Adjacency)
