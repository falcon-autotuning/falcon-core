#include "falcon_core/Dimension.hpp"
#include "falcon_core/constants.hpp"
#include <sstream>

namespace falcon_core {

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
            ss << static_cast<int>(pair.first) << "^" << pair.second << " ";
        }
    }
    return ss.str();
}

nlohmann::json Dimension::to_json() const {
    nlohmann::json j;
    j["dimensions"] = _dimensions;
    add_metadata(j, "falcon_core", "Dimension");
    return j;
}

size_t Dimension::hash() const {
    size_t seed = 0;
    for (const auto& pair : _dimensions) {
        seed ^= std::hash<int>{}(static_cast<int>(pair.first)) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= std::hash<int>{}(pair.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
}

Dimension Dimension::operator*(const Dimension& other) const {
    std::map<BaseDimension, int> new_dims = _dimensions;
    for (const auto& pair : other._dimensions) {
        new_dims[pair.first] += pair.second;
    }
    return Dimension(new_dims);
}

Dimension Dimension::operator/(const Dimension& other) const {
    std::map<BaseDimension, int> new_dims = _dimensions;
    for (const auto& pair : other._dimensions) {
        new_dims[pair.first] -= pair.second;
    }
    return Dimension(new_dims);
}

bool Dimension::operator==(const Dimension& other) const {
    return _dimensions == other._dimensions;
}

const std::map<BaseDimension, int>& Dimension::get_dimensions() const {
    return _dimensions;
}

} // namespace falcon_core
