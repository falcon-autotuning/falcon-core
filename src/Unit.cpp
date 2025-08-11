#include "falcon_core/Unit.hpp"
#include "falcon_core/Prefix.hpp"
#include <stdexcept>
#include <functional>

namespace falcon_core {

Unit::Unit(double scale, Dimension dimension) : _scale(scale), _dimension(std::move(dimension)) {}

const Dimension& Unit::dimension() const { return _dimension; }
double Unit::scale() const { return _scale; }

bool Unit::is_compatible(const Unit& other) const {
    return _dimension.is_compatible(other._dimension);
}

double Unit::get_conversion_factor(const Unit& target_unit) const {
    if (!is_compatible(target_unit)) {
        throw std::runtime_error("Incompatible units for conversion.");
    }
    return _scale / target_unit._scale;
}

double Unit::convert_value_to(double value, const Unit& target_unit) const {
    return value * get_conversion_factor(target_unit);
}

std::shared_ptr<Unit> Unit::operator*(const Unit& other) const {
    return std::make_shared<Unit>(_scale * other._scale, _dimension * other._dimension);
}

std::shared_ptr<Unit> Unit::operator/(const Unit& other) const {
    return std::make_shared<Unit>(_scale / other._scale, _dimension / other._dimension);
}

std::shared_ptr<Unit> Unit::with_prefix(const std::string& prefix_symbol) const {
    double prefix_value = Prefix::get_value(prefix_symbol);
    return std::make_shared<Unit>(_scale * prefix_value, _dimension);
}

nlohmann::json Unit::to_json() const {
    nlohmann::json j;
    j["scale"] = _scale;
    j["dimension_hash"] = _dimension.hash(); // Simplified serialization for now
    add_metadata(j, "falcon_core.physics.units.unit", "Unit");
    return j;
}

size_t Unit::hash() const {
    size_t h1 = std::hash<double>{}(_scale);
    size_t h2 = _dimension.hash();
    return h1 ^ (h2 << 1);
}

} // namespace falcon_core
