#include "falcon_core/physics/config/core/Adjacency.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
Adjacency::Adjacency() = default;
Adjacency::Adjacency(const MatrixType &matrix, const Indexes indexes)
    : _matrix(matrix), _indexes(indexes) {}
Adjacency::MatrixType Adjacency::matrix() const { return _matrix; }
Adjacency::Indexes    Adjacency::indexes() const { return _indexes; }
int                   Adjacency::size() const { return _indexes->size(); }
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
template <class Archive>
void Adjacency::serialize(Archive &ar) {
  ar(cereal::base_class<generic::Song>(this), _matrix, _indexes);
}
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::Adjacency)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::physics::config::core::Adjacency)
