#include "falcon_core/physics/units/Unit.hpp"

#include "falcon_core/Constants.hpp"
#include "falcon_core/Dimension.hpp"
#include "falcon_core/physics/units/Prefix.hpp"
#include "falcon_core/physics/units/TotalDimensions.hpp"

#include <stdexcept>
#include <string>

namespace falcon_core
{

Unit::Unit (TotalDimensions dimensions,
            double          scale_factor,
            double          offset,
            char            prefix)
    : _scale_factor (scale_factor), _dimensions (dimensions), _offset (offset),
      _prefix (prefix)
{
}

std::shared_ptr<Unit>
Unit::operator* (const Unit &other) const
{
  TotalDimensions copy_dims = _dimensions;
  for (const auto &pair : other._dimensions)
    {
      const std::string &dim_ptr   = pair.first;
      const int         &power_ptr = pair.second;
      if (copy_dims.count (dim_ptr))
        {
          copy_dims[dim_ptr] += power_ptr;
          if (copy_dims[dim_ptr] == 0)
            {
              copy_dims.erase (dim_ptr);
            }
        }
      else
        {
          copy_dims[dim_ptr] = power_ptr;
        }
    }
  double new_scale = _scale_factor * other._scale_factor
                     + _scale_factor * other._offset
                     + _offset * other._scale_factor;

  auto result = Prefix::prefix_multiplication (
      std::string (1, _prefix), std::string (1, other._prefix), new_scale);
  double      &new_mult = result.first;
  std::string &prefix   = result.second;

  return std::make_shared<Unit> (
      copy_dims, new_mult, prefix, _offset * other._offset);
}

std::shared_ptr<Unit>
Unit::operator/ (const Unit &other) const
{
  TotalDimensions inv_dims = _dimensions;
  for (const auto &pair : other._dimensions)
    {
      const std::string &dim_ptr   = pair.first;
      const int         &power_ptr = pair.second;
      inv_dims[dim_ptr]            = -power_ptr;
    }
  auto result = Prefix::prefix_multiplication (
      Prefix::get_symbol (-Prefix::get_value (std::string (1, other._prefix))),
      SI::UNIT_SYMBOL,
      1.0 / other._scale_factor);
  double      &new_mult = result.first;
  std::string &prefix   = result.second;
  Unit         inverse_unit (
      inv_dims,
      new_mult,
      prefix,
      -other._offset
          / (other._scale_factor * (other._scale_factor + other._offset)));
  return (*this) * inverse_unit;
}

} // namespace falcon_core
