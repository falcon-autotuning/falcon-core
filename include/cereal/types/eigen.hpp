#pragma once

#include <cereal/cereal.hpp>
#include <Eigen/Dense>

namespace cereal
{
  //! Saving for Eigen::Matrix
  template <class Archive, class _Scalar, int _Rows, int _Cols, int _Options, int _MaxRows, int _MaxCols> inline
  void save(Archive & ar, Eigen::Matrix<_Scalar, _Rows, _Cols, _Options, _MaxRows, _MaxCols> const & m)
  {
    int32_t rows = m.rows();
    int32_t cols = m.cols();
    ar(rows);
    ar(cols);
    ar(binary_data(m.data(), rows * cols * sizeof(_Scalar)));
  }

  //! Loading for Eigen::Matrix
  template <class Archive, class _Scalar, int _Rows, int _Cols, int _Options, int _MaxRows, int _MaxCols> inline
  void load(Archive & ar, Eigen::Matrix<_Scalar, _Rows, _Cols, _Options, _MaxRows, _MaxCols> & m)
  {
    int32_t rows;
    int32_t cols;
    ar(rows);
    ar(cols);

    m.resize(rows, cols);

    ar(binary_data(m.data(), static_cast<std::size_t>(rows) * static_cast<std::size_t>(cols) * sizeof(_Scalar)));
  }
}
