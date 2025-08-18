#include "falcon_core/math/Point.hpp"
#include <cereal/types/polymorphic.hpp>
#include "falcon_core/generic/Song.hpp"

CEREAL_REGISTER_TYPE(falcon_core::math::Point)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::math::Point)

namespace falcon_core {
namespace math {

std::shared_ptr<Point> Point::operator+(std::shared_ptr<Point> other) const {
  if (!_unit->is_compatible_with(other->unit())) {
    throw std::runtime_error("Incompatible units for Point addition.");
  }
  auto result = std::make_shared<Point>(_unit);
  // Copy this point's values
  for (const auto& pair : *this) {
    (*result)[pair.first] = pair.second;
  }
  // Add other point's values
  for (const auto& pair : *other) {
    double other_val_converted =
        other->unit()->convert_value_to(pair.second, _unit);
    if (result->count(pair.first)) {
      (*result)[pair.first] += other_val_converted;
    } else {
      (*result)[pair.first] = other_val_converted;
    }
  }
  return result;
}

}  // namespace math
}  // namespace falcon_core
