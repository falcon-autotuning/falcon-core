#pragma once

#include "falcon_core/generic/Song.hpp"

#include <nlohmann/json.hpp>
#include <stdexcept>

namespace falcon_core
{
namespace math
{
namespace domains
{
class Domain : public generic::Song
{
public:
  Domain (double min_val, double max_val) : _min (min_val), _max (max_val)
  {
    if (_min > _max)
      {
        throw std::invalid_argument ("min cannot be greater than max");
      }
  }

  double
  min () const
  {
    return _min;
  }
  double
  max () const
  {
    return _max;
  }
  double
  range () const
  {
    return _max - _min;
  }

  nlohmann::json to_json () const override;
  size_t         hash () const override;

private:
  double _min;
  double _max;
};
}
}
} // namespace falcon_core
