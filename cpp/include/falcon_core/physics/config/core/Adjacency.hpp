#pragma once

#include "falcon_core/export.h"
#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
/**
 * @brief This a graph representation of the connections between gates in a
 * quantum dot device.
 **/
class FALCON_CORE_CPP_API Adjacency : public generic::FArray<int> {
  using Indexes = physics::device_structures::ConnectionsSP;
  Indexes                         _indexes;
  mutable std::shared_timed_mutex _mu_indexes;

 public:
  Adjacency(const Adjacency& other);
  Adjacency& operator=(const Adjacency& other);
  Adjacency(const xt::xarray<int>& matrix, const Indexes indexes);
  /**
   # @brief Returns the indexes of the gates in the order for the adjacency
   matrix
  */
  Indexes indexes() const;

  /**
   * @brief Returns the pairs of indexes where the adjacency matrix is true (1)
   */
  std::vector<std::pair<size_t, size_t>> get_true_pairs() const;
  bool operator==(const Adjacency& other) const;
  bool operator!=(const Adjacency& other) const;

 protected:
  Adjacency();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_indexes(_mu_indexes);
    ar(cereal::base_class<generic::FArray<int>>(this), _indexes);
  }
};
using AdjacencySP = std::shared_ptr<Adjacency>;
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
