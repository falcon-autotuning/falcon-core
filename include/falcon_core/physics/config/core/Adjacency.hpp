#pragma once

#include <Eigen/Dense>
#include <cereal/types/eigen.hpp>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {

class Adjacency : public generic::Song {
  using MatrixType = Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic>;
  std::vector<device_structures::Gate> _indexes;
  MatrixType                           _matrix;

 public:
  Adjacency(const MatrixType                                   &matrix,
            const std::vector<physics::device_structures::Gate> indexes)
      : _matrix(matrix), _indexes(indexes) {}
  /**
   * @brief Returns the matrix containing the device layout adjacency
   */
  MatrixType matrix() const { return _matrix; }
  /**
   # @brief Returns the indexes of the gates in the order for the adjacency
   matrix
  */
  std::vector<device_structures::Gate> indexes() const { return _indexes; }
  int                                  size() const { return _indexes.size(); }

  /**
   * @brief Returns the pairs of indexes where the adjacency matrix is true (1)
   */
  std::vector<std::pair<int, int>> get_true_pairs() const;
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<generic::Song>(this), _matrix, _indexes);
  }

 protected:
  Adjacency() = default;
  friend class cereal::access;
};
using AdjacencySP = std::shared_ptr<Adjacency>;
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::config::core;
CEREAL_REGISTER_TYPE(Adjacency)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, Adjacency)
#endif
