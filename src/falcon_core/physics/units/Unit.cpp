#include "falcon_core/physics/units/Unit.hpp"

#include "falcon_core/Dimension.hpp"
#include "falcon_core/physics/units/TotalDimensions.hpp"

#include <stdexcept>

namespace falcon_core
{

falcon_core::Unit::Unit (TotalDimensions dimensions,
                         double          scale_factor,
                         double          offset,
                         char            prefix)
    : _scale_factor (scale_factor), _dimensions (dimensions), _offset (offset),
      _prefix (prefix)
{
}

double
Unit::get_factor () const
{
  return _factor;
}

const std::map<std::string, int> &
Unit::dimensions () const
{
  return _dimensions;
}

double
Unit::get_conversion_factor (const Unit &target_unit) const
{
  if (this->_dimensions != target_unit._dimensions)
    {
      throw std::runtime_error (
          "Incompatible dimensions for unit conversion.");
    }
  return this->_factor / target_unit._factor;
}

nlohmann::json
Unit::to_json () const
{
  nlohmann::json j;
  add_metadata (j, "falcon_core.physics.units.unit", "Unit");
  j["_factor"] = _factor;
  // A real implementation would serialize dimensions map
  return j;
}

size_t
Unit::hash () const
{
  // A proper hash would iterate over elements. This is a placeholder.
  return std::hash<double>{}(_factor);
}

std::shared_ptr<Unit>
Unit::operator* (const Unit &other) const
{
  double                     new_factor = this->_factor * other._factor;
  std::map<std::string, int> new_dims   = this->_dimensions;
  for (const auto &pair : other._dimensions)
    {
      new_dims[pair.first] += pair.second;
    }
  return std::make_shared<Unit> (new_factor, new_dims);
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
