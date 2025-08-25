#include "falcon_core/math/Point.hpp"

namespace falcon_core {
namespace math {

std::shared_ptr<Point> Point::operator+(const Point& other) const {
  if (!_unit->is_compatible_with(other.unit())) {
    throw std::runtime_error("Incompatible units for Point addition.");
  }
  auto result = std::make_shared<Point>(_unit);
  // Copy this point's values
  for (const auto& pair : _coords) {
    result->_coords[pair.first] = pair.second;
  }
  // Add other point's values
  for (const auto& pair : other._coords) {
    double other_val_converted =
        other.unit()->convert_value_to(pair.second, _unit);
    if (result->_coords.count(pair.first)) {
      result->_coords[pair.first] += other_val_converted;
    } else {
      result->_coords[pair.first] = other_val_converted;
    }
  }
  return result;
}

}  // namespace math
}  // namespace falcon_core

using namespace falcon_core;
using namespace falcon_core::math;
