#include "falcon_core/Dimension.hpp"
#include <functional>
#include <utility>

namespace falcon_core {

Dimension::Dimension(std::map<BaseDimension, int> dims) : _dims(std::move(dims)) {}

bool Dimension::is_dimensionless() const {
    for (const auto& pair : _dims) {
        if (pair.second != 0) {
            return false;
        }
    }
    return true;
}

bool Dimension::is_compatible(const Dimension& other) const {
    return _dims == other._dims;
}

Dimension Dimension::operator*(const Dimension& other) const {
    std::map<BaseDimension, int> new_dims = _dims;
    for (const auto& pair : other._dims) {
        new_dims[pair.first] += pair.second;
        if (new_dims[pair.first] == 0) {
            new_dims.erase(pair.first);
        }
    }
    return Dimension(new_dims);
}

Dimension Dimension::operator/(const Dimension& other) const {
    std::map<BaseDimension, int> new_dims = _dims;
    for (const auto& pair : other._dims) {
        new_dims[pair.first] -= pair.second;
        if (new_dims[pair.first] == 0) {
            new_dims.erase(pair.first);
        }
    }
    return Dimension(new_dims);
}

Dimension Dimension::pow(int power) const {
    std::map<BaseDimension, int> new_dims;
    for (const auto& pair : _dims) {
        if (pair.second != 0) {
            new_dims[pair.first] = pair.second * power;
        }
    }
    return Dimension(new_dims);
}

bool Dimension::operator==(const Dimension& other) const {
    return _dims == other._dims;
}

const std::map<BaseDimension, int>& Dimension::get_dims() const {
    return _dims;
}

size_t Dimension::hash() const {
    size_t seed = _dims.size();
    for(const auto& pair : _dims) {
        seed ^= static_cast<size_t>(pair.first) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= static_cast<size_t>(pair.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
}

} // namespace falcon_core
