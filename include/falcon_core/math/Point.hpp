#pragma once

#include <cereal/types/map.hpp>
#include <cereal/types/memory.hpp>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace math {
class Point
    : public std::map<physics::device_structures::BaseConnection, double>,
      public generic::Song {
 public:
  using BaseMap = std::map<physics::device_structures::BaseConnection, double>;
  using UnitPtr = std::shared_ptr<physics::units::SymbolUnit>;

  // Inherit all std::map constructors
  using BaseMap::BaseMap;

  // Add constructors that take a unit
  template <typename... Args>
  Point(UnitPtr unit, Args&&... args)
      : BaseMap(std::forward<Args>(args)...), _unit(unit) {}

  // Unit accessor
  UnitPtr unit() const { return _unit; }

  // Example operator+
  std::shared_ptr<Point> operator+(std::shared_ptr<Point> other) const;

 private:
  UnitPtr _unit;

  friend class cereal::access;  // cereal can access private members
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       cereal::base_class<BaseMap>(this),
       _unit);
  }

 protected:
  Point() = default;  // for cereal access
};
}  // namespace math
}  // namespace falcon_core
