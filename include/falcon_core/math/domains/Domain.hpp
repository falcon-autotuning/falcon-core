#pragma once

#include <stdexcept>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {
namespace domains {
class Domain : public generic::Song {
 public:
  Domain(double min_val, double max_val) : _min(min_val), _max(max_val) {
    if (_min > _max) {
      throw std::invalid_argument("min cannot be greater than max");
    }
  }

  double min() const { return _min; }
  double max() const { return _max; }
  double range() const { return _max - _min; }

protected:
  double _min;
  double _max;

  friend class cereal::access;
  Domain() : _min(0), _max(0) {}
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _min, _max);
  }
};
}  // namespace domains
}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math::domains;
CEREAL_REGISTER_TYPE(falcon_core::math::domains::Domain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::domains::Domain)
