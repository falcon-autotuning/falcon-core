#include "falcon_core/math/domains/Domain.hpp"

namespace falcon_core {
namespace math {
namespace domains {

Domain::Domain(double min_val, double max_val) : _min(min_val), _max(max_val) {
  if (_min > _max) {
    throw std::invalid_argument("min cannot be greater than max");
  }
}

double Domain::min() const { return _min; }
double Domain::max() const { return _max; }
double Domain::range() const { return _max - _min; }

Domain::Domain() : _min(0), _max(0) {}

template <class Archive>
void Domain::serialize(Archive& ar) {
  ar(cereal::base_class<generic::Song>(this), _min, _max);
}

}  // namespace domains
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::domains::Domain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::domains::Domain)
