#include "falcon_core/physics/units/Dimension.hpp"

#include <algorithm>
#include <sstream>
using namespace falcon_core::physics::units;

bool is_valid(std::string dimension) {
  using namespace falcon_core::SI;
  return std::find_if(std::begin(ALL_DIMENSIONS),
                      std::end(ALL_DIMENSIONS),
                      [&](const char* dim) { return dimension == dim; }) !=
         std::end(ALL_DIMENSIONS);
}

TotalDimensions validate_dimensions(TotalDimensions dimensions) {
  for (const auto& dim : dimensions) {
    if (!is_valid(dim.first)) {
      std::ostringstream oss;
      oss << "Invalid dimension: " << dim.first;
      throw std::invalid_argument(oss.str());
    }
  }
  return dimensions;
}
