#pragma once

#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"

namespace falcon_core::physics::config::core {

class Adjacency : public generic::FArray<int> {
  using Indexes = physics::device_structures::BaseConnectionsSP;
  Indexes _indexes;

 public:
  Adjacency(const xt::xarray<int> &matrix, const Indexes indexes);
  /**
   # @brief Returns the indexes of the gates in the order for the adjacency
   matrix
  */
  Indexes indexes() const;

  /**
   * @brief Returns the pairs of indexes where the adjacency matrix is true (1)
   */
  std::vector<std::pair<int, int>> get_true_pairs() const;

 protected:
  Adjacency();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<generic::FArray<int>>(this), _indexes);
  }
};
using AdjacencySP = std::shared_ptr<Adjacency>;
}  // namespace falcon_core::physics::config::core
