#pragma once

#include <Eigen/Dense>
#include <cereal/types/eigen.hpp>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {

class Adjacency : public generic::Song {
  using MatrixType = Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic>;
  using Indexes    = physics::device_structures::BaseConnectionsSP;
  Indexes    _indexes;
  MatrixType _matrix;

 public:
  Adjacency(const MatrixType &matrix, const Indexes indexes);
  /**
   * @brief Returns the matrix containing the device layout adjacency
   */
  MatrixType matrix() const;
  /**
   # @brief Returns the indexes of the gates in the order for the adjacency
   matrix
  */
  Indexes indexes() const;
  int     size() const;

  /**
   * @brief Returns the pairs of indexes where the adjacency matrix is true (1)
   */
  std::vector<std::pair<int, int>> get_true_pairs() const;
  template <class Archive>
  void serialize(Archive &ar);

 protected:
  Adjacency();
  friend class cereal::access;
};
using AdjacencySP = std::shared_ptr<Adjacency>;
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
