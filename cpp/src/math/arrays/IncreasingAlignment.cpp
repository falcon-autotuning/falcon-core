#include "falcon_core/math/arrays/IncreasingAlignment.hpp"

#include <mutex>

namespace falcon_core {
namespace math {
namespace arrays {
IncreasingAlignment::IncreasingAlignment(const IncreasingAlignment& other) {
  std::unique_lock<std::shared_timed_mutex> lock_o(_mu_alignment);
  _alignment = other.alignment();
}
IncreasingAlignment& IncreasingAlignment::operator=(
    const IncreasingAlignment& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_o(_mu_alignment);
    _alignment = other.alignment();
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
  if (this == &other) return true;
  return alignment() == other.alignment();
}
bool IncreasingAlignment::operator!=(const IncreasingAlignment& other) const {
  return !(*this == other);
}
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
