#pragma once

#include <Eigen/Dense>
#include <cereal/cereal.hpp>
#include <cereal/types/vector.hpp>

namespace cereal {
//! Saving for Eigen::Matrix
template <class Archive,
          class _Scalar,
          int _Rows,
          int _Cols,
          int _Options,
          int _MaxRows,
          int _MaxCols>
inline void save(
    Archive& ar,
    Eigen::Matrix<_Scalar, _Rows, _Cols, _Options, _MaxRows, _MaxCols> const&
        m) {
  ar(m.rows(), m.cols(), std::vector<_Scalar>(m.data(), m.data() + m.size()));
}

//! Loading for Eigen::Matrix
template <class Archive,
          class _Scalar,
          int _Rows,
          int _Cols,
          int _Options,
          int _MaxRows,
          int _MaxCols>
inline void load(
    Archive&                                                            ar,
    Eigen::Matrix<_Scalar, _Rows, _Cols, _Options, _MaxRows, _MaxCols>& m) {
  Eigen::Index         rows, cols;
  std::vector<_Scalar> data;
  ar(rows, cols, data);
  m = Eigen::Map<const Eigen::Matrix<_Scalar, Eigen::Dynamic, Eigen::Dynamic>,
                 Eigen::Unaligned>(data.data(), rows, cols);
}
}  // namespace cereal
