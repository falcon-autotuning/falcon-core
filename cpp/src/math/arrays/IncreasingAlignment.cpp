#include "falcon_core/math/arrays/IncreasingAlignment.hpp"

namespace falcon_core {
namespace math {
namespace arrays {
IncreasingAlignment::IncreasingAlignment(const IncreasingAlignment& other) {
  std::shared_lock<std::shared_timed_mutex> lock_o(other._mu_alignment);
  _alignment = other._alignment;
}
IncreasingAlignment IncreasingAlignment::operator=(
    const IncreasingAlignment& other) {
  if (this != &other) {
    std::shared_lock<std::shared_timed_mutex> lock_a(_mu_alignment);
    std::shared_lock<std::shared_timed_mutex> lock_o(other._mu_alignment);
    _alignment = other._alignment;
  }
  return *this;
}
IncreasingAlignment::IncreasingAlignment() : _alignment(0) {}
IncreasingAlignment::IncreasingAlignment(const bool alignment)
    : _alignment(alignment ? 1 : -1) {}
int IncreasingAlignment::alignment() const {
  std::shared_lock<std::shared_timed_mutex> lock_a(_mu_alignment);
  return _alignment;
}
bool IncreasingAlignment::operator==(const IncreasingAlignment& other) const {
  return alignment() == other.alignment();
}
bool IncreasingAlignment::operator!=(const IncreasingAlignment& other) const {
  return !(*this == other);
}
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::IncreasingAlignment)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::arrays::IncreasingAlignment)
