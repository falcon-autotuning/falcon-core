#pragma once

#include "falcon_core/math/spaces/UnitSpace.hpp"
#include "falcon_core/math/discretizers/CartesianDiscretizer.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

class CartesianSpace : public UnitSpace {
 public:
  CartesianSpace(const std::vector<double>& deltas,
                 std::shared_ptr<domains::Domain> domain)
      : UnitSpace(make_axes(deltas), domain) {}

  static Axes<discretizers::BaseDiscretizer>
  make_axes(const std::vector<double>& deltas) {
    std::vector<std::shared_ptr<discretizers::BaseDiscretizer>> axes;
    for (double delta : deltas) {
      axes.push_back(std::make_shared<discretizers::CartesianDiscretizer>(delta));
    }
    return Axes<discretizers::BaseDiscretizer>(axes);
  }

 protected:
  friend class cereal::access;
  CartesianSpace() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<UnitSpace>(this));
  }
};

}  // namespace spaces
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::spaces::CartesianSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::spaces::CartesianSpace)
#endif
