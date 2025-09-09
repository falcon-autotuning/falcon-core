#include <gtest/gtest.h>
#include <sstream>
#include <cereal/archives/json.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include "falcon_core/generic/FArray.hpp"

using falcon_core::math::arrays::FArray;

TEST(FArrayTest, BasicOperations) {
    std::vector<size_t> shape = {2, 2};
    FArray<double> arr1 = FArray<double>::zeros(shape);
    FArray<double> arr2 = FArray<double>::empty(shape);

    // Fill arr2 with values
    arr2(0,0) = 1.0;
    arr2(0,1) = 2.0;
    arr2(1,0) = 3.0;
    arr2(1,1) = 4.0;

    // Test operator+=
    arr1 += arr2;
    EXPECT_DOUBLE_EQ(arr1(0,0), 1.0);
    EXPECT_DOUBLE_EQ(arr1(0,1), 2.0);
    EXPECT_DOUBLE_EQ(arr1(1,0), 3.0);
    EXPECT_DOUBLE_EQ(arr1(1,1), 4.0);

    // Test operator*=
    arr1 *= arr2;
    EXPECT_DOUBLE_EQ(arr1(0,0), 1.0);
    EXPECT_DOUBLE_EQ(arr1(0,1), 4.0);
    EXPECT_DOUBLE_EQ(arr1(1,0), 9.0);
    EXPECT_DOUBLE_EQ(arr1(1,1), 16.0);

    // Test operator-=
    arr1 -= arr2;
    EXPECT_DOUBLE_EQ(arr1(0,0), 0.0);
    EXPECT_DOUBLE_EQ(arr1(0,1), 2.0);
    EXPECT_DOUBLE_EQ(arr1(1,0), 6.0);
    EXPECT_DOUBLE_EQ(arr1(1,1), 12.0);

    // Test operator/=
    arr1 /= arr2;
    EXPECT_DOUBLE_EQ(arr1(0,0), 0.0);
    EXPECT_DOUBLE_EQ(arr1(0,1), 1.0);
    EXPECT_DOUBLE_EQ(arr1(1,0), 2.0);
    EXPECT_DOUBLE_EQ(arr1(1,1), 3.0);

    // Test comparison
    FArray<double> arr3 = arr1;
    EXPECT_TRUE(arr1 == arr3);
    arr3(0,0) = 42.0;
    EXPECT_FALSE(arr1 == arr3);
}

TEST(FArrayTest, SerializationRoundTrip) {
    std::vector<size_t> shape = {2, 3};
    FArray<double> arr(shape);
    arr(0,0) = 1.1;
    arr(0,1) = 2.2;
    arr(0,2) = 3.3;
    arr(1,0) = 4.4;
    arr(1,1) = 5.5;
    arr(1,2) = 6.6;

    // Serialize to JSON
    std::stringstream ss;
    {
        cereal::JSONOutputArchive oarchive(ss);
        oarchive(arr);
    }

    // Deserialize from JSON
    FArray<double> arr2;
    {
        cereal::JSONInputArchive iarchive(ss);
        iarchive(arr2);
    }

    ASSERT_EQ(arr.shape(), arr2.shape());
    for (size_t i = 0; i < arr.shape()[0]; ++i) {
        for (size_t j = 0; j < arr.shape()[1]; ++j) {
            EXPECT_DOUBLE_EQ(arr(i, j), arr2(i, j));
        }
    }
}
