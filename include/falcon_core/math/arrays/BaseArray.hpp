#pragma once

#include "falcon_core/generic/Jsonable.hpp"

#include <Eigen/Dense>
#include <nlohmann/json.hpp>

namespace falcon_core
{

template <typename T> class BaseArray : public Jsonable
{
public:
  using MatrixType = Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>;

  BaseArray (const MatrixType &data) : _data (data) {}
  BaseArray () = default;

  const MatrixType &
  data () const
  {
    return _data;
  }
  MatrixType &
  data ()
  {
    return _data;
  }

  bool
  is_1d () const
  {
    return _data.rows () == 1 || _data.cols () == 1;
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j;
    add_metadata (j, "falcon_core.math.arrays.base_array", "BaseArray");
    // A simple serialization; a real implementation might need more detail
    // or a binary format for efficiency.
    j["_data"] = std::vector<T> (_data.data (), _data.data () + _data.size ());
    j["_shape"] = { _data.rows (), _data.cols () };
    return j;
  }

  size_t
  hash () const override
  {
    // A proper hash would iterate over elements. This is a placeholder.
    return _data.size ();
  }

protected:
  MatrixType _data;
};

} // namespace falcon_core
