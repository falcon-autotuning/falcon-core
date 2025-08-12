#pragma once

#include "falcon_core/Jsonable.hpp"
#include "falcon_core/SymbolUnit.hpp"
#include <functional>
#include <memory>
#include <nlohmann/json.hpp>

namespace falcon_core {

template <typename T> class Quantity : public Jsonable {
public:
  Quantity(T value, std::shared_ptr<SymbolUnit> unit)
      : _value(value), _unit(std::move(unit)) {}

  T value() const { return _value; }
  const std::shared_ptr<SymbolUnit> &unit() const { return _unit; }

  nlohmann::json to_json() const override;
  size_t hash() const override;

private:
  T _value;
  std::shared_ptr<SymbolUnit> _unit;
};

template <typename T> nlohmann::json Quantity<T>::to_json() const {
  nlohmann::json j;
  add_metadata(j, "falcon_core.math.quantity", "Quantity");
  j["_value"] = _value;
  j["_unit"] = _unit->to_json();
  return j;
}

template <typename T> size_t Quantity<T>::hash() const {
  size_t h1 = std::hash<T>{}(_value);
  size_t h2 = _unit ? _unit->hash() : 0;
  return h1 ^ (h2 << 1);
}

} // namespace falcon_core
