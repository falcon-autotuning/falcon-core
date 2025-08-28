#include "falcon_core/math/Point.hpp"

#include <memory>
#include <stdexcept>

namespace falcon_core {
namespace math {

Point::Point(UnitPtr unit) : _unit(unit) {}

Point::Point(std::initializer_list<std::pair<BaseConnectionSP, double>> init,
             UnitPtr                                                    unit)
    : _unit(unit), Map<BaseConnection, double, Point>(init) {}

Point::Point() = default;

Point::UnitPtr Point::unit() const { return _unit; }

std::shared_ptr<Point> Point::operator+(const Point& other) const {
  std::shared_ptr<Point> result = clone();
  for (const auto& kv : other.items()) {
    auto it = result->find(kv.first);
    if (it != result->end()) {
      it->second += kv.second;
    } else {
      result->insert_or_assign(kv.first, kv.second);
    }
  }
  return result;
}

std::shared_ptr<Point> Point::operator-(const Point& other) const {
  std::shared_ptr<Point> result = clone();
  for (const auto& kv : other.items()) {
    auto it = result->find(kv.first);
    if (it != result->end()) {
      it->second -= kv.second;
    } else {
      result->insert_or_assign(kv.first, kv.second);
    }
  }
  return result;
}

std::shared_ptr<Point> Point::operator*(double scalar) const {
  std::shared_ptr<Point> result = clone();
  for (auto& kv : result->items()) {
    kv.second = kv.second * scalar;
  }
  return result;
}

std::shared_ptr<Point> Point::operator/(double scalar) const {
  std::shared_ptr<Point> result = clone();
  for (auto& kv : result->items()) {
    kv.second = kv.second / scalar;
  }
  return result;
}

std::shared_ptr<Point> Point::operator-() const {
  std::shared_ptr<Point> result = clone();
  for (auto& kv : result->items()) {
    kv.second = -kv.second;
  }
  return result;
}

void Point::set_unit(UnitPtr unit) { _unit = unit; }

template <class Archive>
void Point::serialize(Archive& ar) {
  ar(cereal::base_class<generic::Map<BaseConnection, double, Point>>(this),
     _unit);
}

// Cereal registration

}  // namespace math
}  // namespace falcon_core
//
#include "falcon_core/generic/Map.hpp"
using MapP = falcon_core::generic::
    Map<falcon_core::physics::device_structures::BaseConnection, double>;
CEREAL_REGISTER_TYPE(MapP)
CEREAL_REGISTER_TYPE(falcon_core::math::Point)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MapP)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::Point)
