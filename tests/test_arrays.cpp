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
    // Use a lambda to avoid "most vexing parse" and ensure exception is thrown on construction
    EXPECT_THROW({ ControlArray1D arr(mat); }, std::invalid_argument);
}

#include <cereal/archives/json.hpp>
#include <cereal/types/memory.hpp>
#include <sstream>

TEST(BaseArrayTest, SerializationRoundTrip) {
    Eigen::MatrixXd mat(2, 2);
    mat << 1.0, 2.0, 3.0, 4.0;
    BaseArray<double> arr(mat);

    // Serialize to JSON
    std::stringstream ss;
    {
        cereal::JSONOutputArchive oarchive(ss);
        oarchive(arr);
    }
    std::cout << "Serialized JSON:\n" << ss.str() << std::endl;

    // Deserialize from JSON
    BaseArray<double> arr2;
    {
        cereal::JSONInputArchive iarchive(ss);
        iarchive(arr2);
    }

    EXPECT_EQ(arr2.data().rows(), 2);
    EXPECT_EQ(arr2.data().cols(), 2);
    EXPECT_DOUBLE_EQ(arr2.data()(0, 0), 1.0);
    EXPECT_DOUBLE_EQ(arr2.data()(1, 1), 4.0);
}

TEST(ControlArray1DTest, SerializationRoundTrip) {
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> vec(1, 3);
    vec << 1.0, 2.0, 3.0;
    ControlArray1D arr1d(vec);

    // Serialize to JSON
    std::stringstream ss;
    {
        cereal::JSONOutputArchive oarchive(ss);
        oarchive(arr1d);
    }
    std::cout << "Serialized JSON:\n" << ss.str() << std::endl;

    // Deserialize from JSON
    ControlArray1D arr1d2;
    {
        cereal::JSONInputArchive iarchive(ss);
        iarchive(arr1d2);
    }

    EXPECT_EQ(arr1d2.data().rows(), 1);
    EXPECT_EQ(arr1d2.data().cols(), 3);
    EXPECT_DOUBLE_EQ(arr1d2.data()(0, 2), 3.0);
}
