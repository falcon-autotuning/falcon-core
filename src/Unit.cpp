#include "falcon_core/Unit.hpp"
#include "falcon_core/Jsonable.hpp"
#include "falcon_core/constants.hpp"
#include <map>
#include <nlohmann/json.hpp>
#include <stdexcept>
#include <string>

namespace falcon_core {

Unit::Unit(double factor, std::map<std::string, int> dimensions)
    : _factor(factor), _dimensions(std::move(dimensions)) {}

double Unit::get_factor() const { return _factor; }

const std::map<std::string, int> &Unit::dimensions() const {
  return _dimensions;
}

double Unit::get_conversion_factor(const Unit &target_unit) const {
  if (_dimensions != target_unit._dimensions) {
    throw std::runtime_error("Unit dimensions do not match for conversion.");
  }
  return _factor / target_unit._factor;
}

nlohmann::json Unit::to_json() const {
<<<<<<< HEAD
  nlohmann::json j;
  j["factor"] = _factor;
  j["dimension"] = _dimensions;
  add_metadata(j, "falcon_core", "Unit");
  return j;
}
=======
    nlohmann::json j;
    j["factor"] = _factor;
    j["dimension"] = _dimension.to_json();
    add_metadata(j, "falcon_core", "Unit");
    return j;
}

size_t Unit::hash() const {
    return std::hash<double>{}(_factor) ^ _dimension.hash();
}

// std::shared_ptr<Unit> Unit::operator*(const Unit& other) const {
//     return std::make_shared<Unit>(_factor * other._factor, _dimension * other._dimension);
// }

// std::shared_ptr<Unit> Unit::operator/(const Unit& other) const {
//     return std::make_shared<Unit>(_factor / other._factor, _dimension / other._dimension);
// }
>>>>>>> a0c46a44b586bc31633613c401acb75a9215aa05

} // namespace falcon_core
