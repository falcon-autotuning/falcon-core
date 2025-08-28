#include "falcon_core/math/arrays/IncreasingAlignment.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

IncreasingAlignment::IncreasingAlignment() = default;

template <class Archive>
void IncreasingAlignment::serialize(Archive& ar) {
  ar(cereal::base_class<generic::Song>(this));
}

}  // namespace arrays
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::IncreasingAlignment)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::arrays::IncreasingAlignment)
