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
  TotalDimensions copy_dims = dimensions ();
  for (const auto &pair : other.dimensions ())
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
  double new_scale = scale_factor () * other.scale_factor ()
                     + scale_factor () * other.offset ()
                     + offset () * other.scale_factor ();

  auto result = Prefix::prefix_multiplication (
      std::string (1, prefix ()), std::string (1, other.prefix ()), new_scale);
  double      &new_mult = result.first;
  std::string &prefix   = result.second;

  return std::make_shared<Unit> (
      copy_dims, new_mult, prefix, offset () * other.offset ());
}

std::shared_ptr<Unit>
Unit::operator/ (const Unit &other) const
{
  TotalDimensions inv_dims = dimensions ();
  for (const auto &pair : other.dimensions ())
    {
      const std::string &dim_ptr   = pair.first;
      const int         &power_ptr = pair.second;
      inv_dims[dim_ptr]            = -power_ptr;
    }
  auto result
      = Prefix::prefix_multiplication (Prefix::get_symbol (-Prefix::get_value (
                                           std::string (1, other.prefix ()))),
                                       SI::UNIT_SYMBOL,
                                       1.0 / other.scale_factor ());
  double      &new_mult = result.first;
  std::string &prefix   = result.second;
  Unit         inverse_unit (inv_dims,
                     new_mult,
                     prefix,
                     -other.offset ()
                         / (other.scale_factor ()
                            * (other.scale_factor () + other.offset ())));
  return (*this) * inverse_unit;
}

std::shared_ptr<Unit>
Unit::operator^ (int power) const
{
  TotalDimensions new_dims;
  for (const auto &pair : dimensions ())
    {
      const std::string &dim_ptr   = pair.first;
      const int         &power_ptr = pair.second;
      new_dims[dim_ptr]            = power_ptr * power;
    }
  double new_scale = std::pow (scale_factor (), power);
  // Assuming _prefix and _offset can be copied directly
  return std::make_shared<Unit> (new_dims, new_scale, offset (), prefix ());
}

std::shared_ptr<Unit>
Unit::with_prefix (const std::string prefix) const
{
  int current_prefix_value
      = Prefix::get_value (std::string (1, this->prefix ()));
  if (!Prefix::is_valid (prefix))
    {
      throw std::invalid_argument ("Invalid prefix: " + prefix);
    }
  int    new_prefix_value = Prefix::get_value (prefix);
  double new_scale_factor
      = scale_factor () * pow (10, new_prefix_value - current_prefix_value);
  return std::make_shared<Unit> (
      dimensions (), new_scale_factor, offset (), prefix);
}

double
Unit::convert_value_to (const double value, const Unit target_unit) const
{
  if (dimensions () != target_unit.dimensions ())
    {
      throw std::invalid_argument (
          "Cannot convert between units with different dimensions.");
    }
  double base_value = (value - offset ()) / scale_factor ();
  return (base_value / target_unit.scale_factor ()) - target_unit.offset ();
}

bool
Unit::is_compatible_with (const Unit other) const
{
  return dimensions () == other.dimensions ();
}

} // namespace falcon_core
