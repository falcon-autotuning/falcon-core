#pragma once

#include "falcon_core/Constants.hpp"
#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/units/TotalDimensions.hpp"

#include <map>
#include <string>

namespace falcon_core
{
namespace physics
{
namespace units
{

class Dimension
{
public:
  const char *LENGTH      = SI::DIMENSION_LENGTH;
  const char *MASS        = SI::DIMENSION_MASS;
  const char *TIME        = SI::DIMENSION_TIME;
  const char *CURRENT     = SI::DIMENSION_CURRENT;
  const char *TEMPERATURE = SI::DIMENSION_TEMPERATURE;
  const char *LUMINOSITY  = SI::DIMENSION_LUMINOSITY;
  const char *AMOUNT      = SI::DIMENSION_AMOUNT;
  /*
   * @brief Check if a dimension is valid.
   * @param dimension The dimension to check.
   * @return True if the dimension is valid, false otherwise.
   */
  bool is_valid (std::string dimension);
  /*
   * @brief Validate a dicrtionary of dimensions.
   * @param dimensions The dimensions to validate.
   * @return the validated dimensions.
   * @throws std::invalid_argument if the dimensions are invalid.
   */
  TotalDimensions validate_dimensions (TotalDimensions dimensions);
};
}
}
} // namespace falcon_core
