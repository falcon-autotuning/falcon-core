#include "falcon_core/physics/units/Dimension.hpp"
#include "falcon_core/constants.hpp"
#include <functional>
#include <map>
#include <sstream>

namespace falcon_core {

// Helper to convert BaseDimension to string
static std::string base_dimension_to_string(BaseDimension dim) {
    switch (dim) {
        case BaseDimension::LENGTH: return "LENGTH";
        case BaseDimension::MASS: return "MASS";
        case BaseDimension::TIME: return "TIME";
        case BaseDimension::CURRENT: return "CURRENT";
        case BaseDimension::TEMPERATURE: return "TEMPERATURE";
        case BaseDimension::LUMINOUS_INTENSITY: return "LUMINOUS_INTENSITY";
        case BaseDimension::AMOUNT_OF_SUBSTANCE: return "AMOUNT_OF_SUBSTANCE";
    }
    return ""; // Should not happen
}

Dimension::Dimension(std::map<BaseDimension, int> dimensions) : _dimensions(std::move(dimensions)) {}

bool Dimension::is_dimensionless() const {
    for (const auto& pair : _dimensions) {
        if (pair.second != 0) {
            return false;
        }
    }
    return true;
}

std::string Dimension::to_string() const {
    std::stringstream ss;
    for(const auto& pair : _dimensions) {
        if(pair.second != 0) {
            ss << base_dimension_to_string(pair.first) << "^" << pair.second << " ";
        }
    }
    std::string result = ss.str();
    // remove trailing space
    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}

nlohmann::json Dimension::to_json() const {
    nlohmann::json j;
    add_metadata(j, "falcon_core.physics.units.dimension", "Dimension");
    nlohmann::json dims_json;
    for (const auto& pair : _dimensions) {
        if (pair.second != 0) {
            dims_json[base_dimension_to_string(pair.first)] = pair.second;
        }
    }
    j["_dimensions"] = dims_json;
    return j;
}

size_t Dimension::hash() const {
    size_t seed = _dimensions.size();
    for (const auto& pair : _dimensions) {
        seed ^= std::hash<int>{}(static_cast<int>(pair.first)) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= std::hash<int>{}(pair.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
}

const std::map<BaseDimension, int>& Dimension::get_dimensions() const {
    return _dimensions;
}

bool Dimension::operator==(const Dimension& other) const {
  return _dimensions == other._dimensions;
}

} // namespace falcon_core
