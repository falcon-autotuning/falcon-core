#include "falcon_core/physics/units/Unit.hpp"

#include "falcon_core/Dimension.hpp"
#include "falcon_core/physics/units/TotalDimensions.hpp"

#include <stdexcept>

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
      const std::string *dim_ptr   = &pair.first;
      const int         *power_ptr = &pair.second;
      if (copy_dims.count (*dim_ptr))
        {
          copy_dims[*dim_ptr] += *power_ptr;
          if (copy_dims[*dim_ptr] == 0)
            {
              copy_dims.erase (*dim_ptr);
            }
        }
      else
        {
          copy_dims[*dim_ptr] = *power_ptr;
        }
    }
  double new_scale = _scale_factor * other._scale_factor
                     + _scale_factor * other._offset
                     + _offset * other._scale_factor;

  // new_mult, prefix = Prefix.prefix_multiplication(
  //     first_prefix=self.prefix,
  //     second_prefix=other.prefix,
  //     scale_factor=new_scale,
  // )

  return std::make_shared<Unit> (
      copy_dims, new_mult, prefix, _offset * other._offset);
}

std::shared_ptr<Unit>
Unit::operator/ (const Unit &other) const
{
  double                     new_factor = this->_factor / other._factor;
  std::map<std::string, int> new_dims   = this->_dimensions;
  for (const auto &pair : other._dimensions)
    {
      new_dims[pair.first] -= pair.second;
    }
  return std::make_shared<Unit> (new_factor, new_dims);
}

} // namespace falcon_core
