#include <gtest/gtest.h>
#include <Eigen/Dense>
#include "falcon_core/math/arrays/BaseArray.hpp"
#include "falcon_core/math/arrays/ControlArray1D.hpp"

using namespace falcon_core::math::arrays;

TEST(BaseArrayTest, ConstructionAndAccess) {
    Eigen::MatrixXd mat(2, 2);
    mat << 1.0, 2.0, 3.0, 4.0;
    BaseArray<double> arr(mat);
    EXPECT_EQ(arr.data().rows(), 2);
    EXPECT_EQ(arr.data().cols(), 2);
    EXPECT_DOUBLE_EQ(arr.data()(0, 0), 1.0);
    EXPECT_DOUBLE_EQ(arr.data()(1, 1), 4.0);
}

TEST(ControlArray1DTest, Construction1D) {
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> vec(1, 3);
    vec << 1.0, 2.0, 3.0;
    ControlArray1D arr1d(vec);
    EXPECT_EQ(arr1d.data().rows(), 1);
    EXPECT_EQ(arr1d.data().cols(), 3);
    EXPECT_DOUBLE_EQ(arr1d.data()(0, 2), 3.0);
}

TEST(ControlArray1DTest, ThrowsOnNon1D) {
    Eigen::MatrixXd mat(2, 2);
    mat << 1.0, 2.0, 3.0, 4.0;
    EXPECT_THROW(ControlArray1D arr(mat), std::invalid_argument);
}
