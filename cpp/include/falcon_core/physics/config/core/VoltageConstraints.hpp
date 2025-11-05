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
  generic::FArray<double> _matrix;
  AdjacencySP             _adjacency;
  generic::FArray<double> _limits;

 public:
  VoltageConstraints(const AdjacencySP         adjacency,
                     double                    max_safe_diff,
                     std::pair<double, double> bounds);
  /**
   * @brief The constraint matrix.
   */
  const generic::FArray<double>& matrix() const;
  /**
   * @brief The constraint matrix.
   */
  const generic::FArray<double>& matrix();
  /**
   * @brief The adjacency matrix used to understand the device layout.
   */
  const AdjacencySP adjacency() const;
  /**
   * @brief The y axis vector safe voltage limits for each constraint.
   */
  const generic::FArray<double>& limits() const;
  bool operator==(const VoltageConstraints& other) const;
  bool operator!=(const VoltageConstraints& other) const;

 protected:
  VoltageConstraints();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _matrix, _adjacency, _limits);
  }
};
using VoltageConstraintsSP = std::shared_ptr<VoltageConstraints>;
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
