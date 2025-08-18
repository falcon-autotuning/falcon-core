#include <gtest/gtest.h>

#include <Eigen/Dense>

#include "falcon_core/math/arrays/BaseArray.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"
#include "falcon_core/math/labelled_arrays/IsLabelled1D.hpp"

using namespace falcon_core::math::labelled_arrays;
using namespace falcon_core::math::arrays;

// Dummy class to test IsLabelled1D
class DummyLabelled1D : public IsLabelled1D<DummyLabelled1D> {
 public:
  DummyLabelled1D(const BaseArray<double>& arr) : _array(arr) {}
  const BaseArray<double>& get_array() const { return _array; }

 private:
  BaseArray<double> _array;
};

TEST(BaseLabelledArraysTest, ConstructionAndAccess) {
  Eigen::MatrixXd mat1(1, 3);
  mat1 << 1.0, 2.0, 3.0;
  Eigen::MatrixXd mat2(1, 3);
  mat2 << 4.0, 5.0, 6.0;
  auto arr1 = std::make_shared<BaseArray<double>>(mat1);
  auto arr2 = std::make_shared<BaseArray<double>>(mat2);

  BaseLabelledArrays<BaseArray<double>> labelled_arrays;
  labelled_arrays.append(arr1);
  labelled_arrays.append(arr2);

  EXPECT_EQ(labelled_arrays.get_arrays().size(), 2);
  EXPECT_DOUBLE_EQ(labelled_arrays.get_arrays()[0]->data()(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(labelled_arrays.get_arrays()[1]->data()(0, 2), 6.0);
}

TEST(IsLabelled1DTest, GetStart) {
  Eigen::MatrixXd mat(1, 3);
  mat << 10.0, 20.0, 30.0;
  BaseArray<double> arr(mat);
  DummyLabelled1D   labelled(arr);

  EXPECT_DOUBLE_EQ(labelled.get_start(), 10.0);
}

TEST(IsLabelled1DTest, ThrowsOnNon1D) {
  Eigen::MatrixXd mat(2, 2);
  mat << 1.0, 2.0, 3.0, 4.0;
  BaseArray<double> arr(mat);
  // get_start should throw since arr is not 1D
  DummyLabelled1D labelled(arr);
  EXPECT_THROW({ labelled.get_start(); }, std::runtime_error);
}
