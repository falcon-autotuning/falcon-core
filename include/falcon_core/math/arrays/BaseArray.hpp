/**
 * @file BaseArray.hpp
 * @brief Defines the BaseArray template for FalconCore.
 */

#pragma once

#include <Eigen/Dense>
#include <cereal/types/eigen.hpp>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

/// @brief Base class for array-like objects using Eigen matrices.
/// @tparam T Element type (e.g., double, float).
template <typename T>
class BaseArray : public generic::Song {
 public:
  using MatrixType = Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>;

  BaseArray(const MatrixType &data);
  BaseArray();

  const MatrixType &data() const;
  MatrixType       &data();

  bool is_1d() const;

 protected:
  MatrixType _data;

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive &ar);
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
