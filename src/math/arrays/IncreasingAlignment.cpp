#include "falcon_core/math/arrays/IncreasingAlignment.hpp"

namespace falcon_core::math::arrays {

IncreasingAlignment::IncreasingAlignment() : _alignment(0) {}
IncreasingAlignment::IncreasingAlignment(const bool alignment)
    : _alignment(alignment ? 1 : -1) {}
int IncreasingAlignment::alignment() const { return _alignment; }
}  // namespace falcon_core::math::arrays

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::IncreasingAlignment)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::arrays::IncreasingAlignment)
