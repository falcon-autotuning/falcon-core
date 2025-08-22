#pragma once

#include "falcon_core/math/spaces/CartesianSpace.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

class Cartesian2DSpace : public CartesianSpace {
 public:
  Cartesian2DSpace(const std::vector<double>&       deltas,
                   std::shared_ptr<domains::Domain> domain)
      : CartesianSpace(deltas, domain) {
    if (deltas.size() != 2) {
      throw std::invalid_argument("A 2D space must have two deltas.");
    }
  }

 protected:
  friend class cereal::access;
  Cartesian2DSpace() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<CartesianSpace>(this));
  }
};

}  // namespace spaces
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::spaces::Cartesian2DSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::spaces::Cartesian2DSpace)
#endif
