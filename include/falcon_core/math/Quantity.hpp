#pragma once

#include <complex>
#include <functional>
#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace std {
template <typename T>
struct hash<std::complex<T>> {
  size_t operator()(const std::complex<T> &c) const {
    size_t h1 = std::hash<T>{}(c.real());
    size_t h2 = std::hash<T>{}(c.imag());
    // A simple way to combine hashes.
    // See boost::hash_combine for a more robust implementation.
    return h1 ^ (h2 << 1);
  }
};
}  // namespace std

namespace falcon_core {
namespace math {

template <typename T>
class Quantity : public generic::Song {
 public:
  Quantity(T value, std::shared_ptr<physics::units::SymbolUnit> unit)
      : _value(value), _unit(std::move(unit)) {}

  T value() const { return _value; }
  const std::shared_ptr<physics::units::SymbolUnit> &unit() const {
    return _unit;
  }

 private:
  T                                           _value;
  std::shared_ptr<physics::units::SymbolUnit> _unit;
};

}  // namespace math
}  // namespace falcon_core
