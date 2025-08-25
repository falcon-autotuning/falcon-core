#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/config/core/Adjacency.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {

/**
 * @brief Contains a ready to use voltage constrains matrix and matching limits
 * for each constraint.
 */
class VoltageConstraints : public generic::Song {
  using MatrixType = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>;
  MatrixType              _matrix;
  AdjacencySP             _adjacency;
  std::pair<float, float> _limits;

 public:
  VoltageConstraints(const AdjacencySP         adjacency,
                     double                    max_safe_diff,
                     std::pair<double, double> bounds);
  /**
   * @brief The constraint matrix.
   */
  const MatrixType& matrix() const { return _matrix; }
  /**
   * @brief The constraint matrix.
   */
  MatrixType& matrix() { return _matrix; }
  /**
   * @brief The adjacency matrix used to understand the device layout.
   */
  AdjacencySP adjacency() const { return _adjacency; }
  /**
   * @brief The (min,max) safe voltage limits for each constraint.
   */
  std::pair<float, float> limits() const { return _limits; }
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _matrix, _adjacency, _limits);
  }

 protected:
  VoltageConstraints() = default;
  friend class cereal::access;
};
using VoltageConstraintsSP = std::shared_ptr<VoltageConstraints>;
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::config::core;
CEREAL_REGISTER_TYPE(VoltageConstraints)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     VoltageConstraints)
#endif
