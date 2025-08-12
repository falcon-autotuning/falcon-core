#include "falcon_core/Dimension.hpp"
#include "falcon_core/constants.hpp"
#include <functional>
#include <map>

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

nlohmann::json Dimension::to_json() const {
    nlohmann::json j;
    add_metadata(j, "falcon_core.physics.units.dimension", "Dimension");
    // In a real implementation, we would serialize the map.
    // For now, returning a placeholder.
    j["dimensions"] = "serialized_dimensions_placeholder";
    return j;
}

size_t Dimension::hash() const {
    // A proper hash would iterate over elements. This is a placeholder.
    return _dimensions.size();
}

const std::map<BaseDimension, int>& Dimension::get_dimensions() const {
    return _dimensions;
}

bool Dimension::operator==(const Dimension& other) const {
  return _dimensions == other._dimensions;
}

} // namespace falcon_core
