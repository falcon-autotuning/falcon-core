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
  /// @brief Type alias for the underlying Eigen matrix.
  using MatrixType = Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>;

  /// @brief Construct from Eigen matrix data.
  BaseArray(const MatrixType &data) : _data(data) {}
  /// @brief Default constructor.
  BaseArray() = default;

  /// @brief Get the underlying data (const).
  const MatrixType &data() const { return _data; }
  /// @brief Get the underlying data (mutable).
  MatrixType       &data() { return _data; }

  /// @brief Check if the array is 1-dimensional.
  bool is_1d() const { return _data.rows() == 1 || _data.cols() == 1; }

 protected:
  MatrixType _data;

 private:
  friend class cereal::access;
  /// @brief Serialization method for cereal.
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<generic::Song>(this), _data);
  }
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math::arrays;
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::BaseArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::arrays::BaseArray<double>)
#endif
