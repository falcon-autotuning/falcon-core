#pragma once

#include "falcon_core/math/arrays/ControlArray.hpp"

#include <stdexcept>

namespace falcon_core
{
namespace math
{
namespace arrays
{

class ControlArray1D : public ControlArray<double>
{
public:
  using ControlArray<double>::ControlArray;

  ControlArray1D (const typename ControlArray<double>::MatrixType &data)
      : ControlArray<double> (data)
  {
    if (!is_1d ())
      {
        throw std::invalid_argument (
            "Data for ControlArray1D must be 1-dimensional.");
      }
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j;
    add_metadata (
        j, "falcon_core.math.arrays.control_array_1D", "ControlArray1D");
    j["_data"]
        = std::vector<double> (_data.data (), _data.data () + _data.size ());
    j["_shape"] = { _data.rows (), _data.cols () };
    return j;
  }
};
}
}
}
