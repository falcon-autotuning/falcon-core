#include "falcon_core/Unit.hpp"
#include "falcon_core/constants.hpp"
#include <stdexcept>

namespace falcon_core {

Unit::Unit(double factor, Dimension dimension)
    : _factor(factor), _dimension(std::move(dimension)) {}

double Unit::get_factor() const {
    return _factor;
}

const Dimension& Unit::get_dimension() const {
    return _dimension;
}

double Unit::get_conversion_factor(const Unit& target_unit) const {
    if (_dimension != target_unit._dimension) {
        throw std::runtime_error("Unit dimensions do not match for conversion.");
    }
    return _factor / target_unit._factor;
}

nlohmann::json Unit::to_json() const {
    nlohmann::json j;
    j["factor"] = _factor;
    j["dimension"] = _dimension.to_json();
    add_metadata(j, "falcon_core", "Unit");
    return j;
}

size_t Unit::hash() const {
    return std::hash<double>{}(_factor) ^ _dimension.hash();
}

std::shared_ptr<Unit> Unit::operator*(const Unit& other) const {
    return std::make_shared<Unit>(_factor * other._factor, _dimension * other._dimension);
}

std::shared_ptr<Unit> Unit::operator/(const Unit& other) const {
    return std::make_shared<Unit>(_factor / other._factor, _dimension / other._dimension);
}

} // namespace falcon_core
