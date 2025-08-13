#include "falcon_core/physics/units/Dimension.hpp"

#include <sstream>

using namespace falcon_core::physics::units;

bool
is_valid (std::string dimension)
{
  return std::find (std::begin (falcon_core::SI::ALL_DIMENSIONS),
                    std::end (falcon_core::SI::ALL_DIMENSIONS),
                    dimension)
         != std::end (falcon_core::SI::ALL_DIMENSIONS);
}

TotalDimensions
validate_dimensions (TotalDimensions dimensions)
{
  for (const auto &dim : dimensions)
    {
      if (!is_valid (dim.first))
        {
          std::ostringstream oss;
          oss << "Invalid dimension: " << dim.first;
          throw std::invalid_argument (oss.str ());
        }
    }
  return dimensions;
}
