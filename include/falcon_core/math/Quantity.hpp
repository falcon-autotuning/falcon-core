#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

#include <complex>
#include <functional>
#include <memory>
#include <nlohmann/json.hpp>

namespace nlohmann
{
template <typename T> struct adl_serializer<std::complex<T>>
{
  static void
  to_json (json &j, const std::complex<T> &c)
  {
    j = { { "real", c.real () }, { "imag", c.imag () } };
  }
};
} // namespace nlohmann

namespace std
{
template <typename T> struct hash<std::complex<T>>
{
  size_t
  operator() (const std::complex<T> &c) const
  {
    size_t h1 = std::hash<T>{}(c.real ());
    size_t h2 = std::hash<T>{}(c.imag ());
    // A simple way to combine hashes.
    // See boost::hash_combine for a more robust implementation.
    return h1 ^ (h2 << 1);
  }
};
} // namespace std

namespace falcon_core
{
namespace math
{

template <typename T> class Quantity : public generic::Song
{
public:
  Quantity (T value, std::shared_ptr<physics::units::SymbolUnit> unit)
      : _value (value), _unit (std::move (unit))
  {
  }

  T
  value () const
  {
    return _value;
  }
  const std::shared_ptr<physics::units::SymbolUnit> &
  unit () const
  {
    return _unit;
  }

  nlohmann::json to_json () const override;
  size_t         hash () const override;

private:
  T                                           _value;
  std::shared_ptr<physics::units::SymbolUnit> _unit;
};

template <typename T>
nlohmann::json
Quantity<T>::to_json () const
{
  nlohmann::json j;
  add_metadata (j, "falcon_core.math.quantity", "Quantity");
  j["_value"] = _value;
  j["_unit"]  = _unit->to_json ();
  return j;
}

template <typename T>
size_t
Quantity<T>::hash () const
{
  size_t h1 = std::hash<T>{}(_value);
  size_t h2 = _unit ? _unit->hash () : 0;
  return h1 ^ (h2 << 1);
}
}
} // namespace falcon_core
