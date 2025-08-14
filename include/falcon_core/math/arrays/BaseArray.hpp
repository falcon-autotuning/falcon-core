#pragma once

#include <Eigen/Dense>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

template <typename T>
class BaseArray : public generic::Song {
 public:
  using MatrixType = Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>;

  BaseArray(const MatrixType &data) : _data(data) {}
  BaseArray() = default;

  const MatrixType &data() const { return _data; }
  MatrixType       &data() { return _data; }

  bool is_1d() const { return _data.rows() == 1 || _data.cols() == 1; }

 protected:
  MatrixType _data;
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
