#pragma once

#include "falcon_core/math/arrays/BaseArray.hpp"

namespace falcon_core
{
namespace math
{
namespace arrays
{

template <typename T> class MeasuredArray : public BaseArray<T>
{
public:
  using BaseArray<T>::BaseArray;

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j;
    this->add_metadata (
        j, "falcon_core.math.arrays.measured_array", "MeasuredArray");
    j["_data"]  = std::vector<T> (this->_data.data (),
                                 this->_data.data () + this->_data.size ());
    j["_shape"] = { this->_data.rows (), this->_data.cols () };
    return j;
  }
};
}
}
} // namespace falcon_core
