#include <gtest/gtest.h>

#include <xtensor/containers/xarray.hpp>
#include <xtensor/io/xio.hpp>

#include "falcon_core/math/arrays/BaseArray.hpp"
#include "falcon_core/math/arrays/ControlArray1D.hpp"

namespace tests {
using namespace falcon_core::math::arrays;

TEST(BaseArrayTest, ConstructionAndAccess) {
  xt::xarray<double> arr_data = {{1.0, 2.0}, {3.0, 4.0}};
  BaseArray<double>  arr(arr_data);
  EXPECT_EQ(arr.shape()[0], 2);
  EXPECT_EQ(arr.shape()[1], 2);
  EXPECT_DOUBLE_EQ(arr(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(arr(1, 1), 4.0);
}

TEST(BaseArrayTest, BasicOperations) {
  xt::xarray<double> arr1_data = {{1.0, 2.0}, {3.0, 4.0}};
  xt::xarray<double> arr2_data = {{5.0, 6.0}, {7.0, 8.0}};
  BaseArray<double> arr1(arr1_data);
  BaseArray<double> arr2(arr2_data);

  // Test operator+=
  BaseArray<double> arr_sum = arr1;
  arr_sum += arr2;
  EXPECT_DOUBLE_EQ(arr_sum(0, 0), 6.0);
  EXPECT_DOUBLE_EQ(arr_sum(0, 1), 8.0);
  EXPECT_DOUBLE_EQ(arr_sum(1, 0), 10.0);
  EXPECT_DOUBLE_EQ(arr_sum(1, 1), 12.0);

  // Test operator-=
  BaseArray<double> arr_diff = arr1;
  arr_diff -= arr2;
  EXPECT_DOUBLE_EQ(arr_diff(0, 0), -4.0);
  EXPECT_DOUBLE_EQ(arr_diff(0, 1), -4.0);
  EXPECT_DOUBLE_EQ(arr_diff(1, 0), -4.0);
  EXPECT_DOUBLE_EQ(arr_diff(1, 1), -4.0);

  // Test operator*=
  BaseArray<double> arr_prod = arr1;
  arr_prod *= arr2;
  EXPECT_DOUBLE_EQ(arr_prod(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(arr_prod(0, 1), 12.0);
  EXPECT_DOUBLE_EQ(arr_prod(1, 0), 21.0);
  EXPECT_DOUBLE_EQ(arr_prod(1, 1), 32.0);

  // Test operator/=
  BaseArray<double> arr_div = arr2;
  arr_div /= arr1;
  EXPECT_DOUBLE_EQ(arr_div(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(arr_div(0, 1), 3.0);
  EXPECT_DOUBLE_EQ(arr_div(1, 0), 7.0/3.0);
  EXPECT_DOUBLE_EQ(arr_div(1, 1), 2.0);

  // Test comparison
  BaseArray<double> arr3 = arr1;
  EXPECT_TRUE(arr1 == arr3);
  arr3(0, 0) = 42.0;
  EXPECT_FALSE(arr1 == arr3);
}

TEST(ControlArray1DTest, BasicOperations) {
  xt::xarray<double> v1 = {1.0, 2.0, 3.0};
  xt::xarray<double> v2 = {4.0, 5.0, 6.0};
  ControlArray1D arr1d1(v1);
  ControlArray1D arr1d2(v2);

  // Test operator+=
  ControlArray1D sum = arr1d1;
  sum += arr1d2;
  EXPECT_DOUBLE_EQ(sum(0), 5.0);
  EXPECT_DOUBLE_EQ(sum(1), 7.0);
  EXPECT_DOUBLE_EQ(sum(2), 9.0);

  // Test operator-=
  ControlArray1D diff = arr1d1;
  diff -= arr1d2;
  EXPECT_DOUBLE_EQ(diff(0), -3.0);
  EXPECT_DOUBLE_EQ(diff(1), -3.0);
  EXPECT_DOUBLE_EQ(diff(2), -3.0);

  // Test operator*=
  ControlArray1D prod = arr1d1;
  prod *= arr1d2;
  EXPECT_DOUBLE_EQ(prod(0), 4.0);
  EXPECT_DOUBLE_EQ(prod(1), 10.0);
  EXPECT_DOUBLE_EQ(prod(2), 18.0);

  // Test operator/=
  ControlArray1D div = arr1d2;
  div /= arr1d1;
  EXPECT_DOUBLE_EQ(div(0), 4.0);
  EXPECT_DOUBLE_EQ(div(1), 2.5);
  EXPECT_DOUBLE_EQ(div(2), 2.0);

  // Test comparison
  ControlArray1D arr3 = arr1d1;
  EXPECT_TRUE(arr1d1 == arr3);
  arr3(0) = 42.0;
  EXPECT_FALSE(arr1d1 == arr3);
}

TEST(ControlArray1DTest, Construction1D) {
  xt::xarray<double> vec = {1.0, 2.0, 3.0};
  ControlArray1D     arr1d(vec);
  EXPECT_EQ(arr1d.shape()[0], 3);
  EXPECT_EQ(arr1d.dimension(), 1);
  EXPECT_DOUBLE_EQ(arr1d(2), 3.0);
}

TEST(ControlArray1DTest, ThrowsOnNon1D) {
  xt::xarray<double> mat = {{1.0, 2.0}, {3.0, 4.0}};
  EXPECT_THROW({ ControlArray1D arr(mat); }, std::invalid_argument);
}

TEST(BaseArrayTest, SerializationRoundTrip) {
  xt::xarray<double> arr_data = {{1.0, 2.0}, {3.0, 4.0}};
  BaseArray<double>  arr(arr_data);

  // Serialize to JSON using the class helper
  std::string json = arr.to_json_string();
  std::cout << "Serialized JSON:\n" << json << std::endl;

  // Deserialize from JSON using the class helper
  auto arr2 = BaseArray<double>::from_json_string<BaseArray<double>>(json);

  EXPECT_EQ(arr2->shape()[0], 2);
  EXPECT_EQ(arr2->shape()[1], 2);
  EXPECT_DOUBLE_EQ((*arr2)(0, 0), 1.0);
  EXPECT_DOUBLE_EQ((*arr2)(1, 1), 4.0);
}

TEST(ControlArray1DTest, SerializationRoundTrip) {
  xt::xarray<double> vec   = {1.0, 2.0, 3.0};
  auto               arr1d = std::make_shared<ControlArray1D>(vec);

  // Serialize to JSON using the class helper
  std::string json = arr1d->to_json_string();
  std::cout << "Serialized JSON:\n" << json << std::endl;

  // Deserialize from JSON using the class helper
  auto arr1d2 = ControlArray1D::from_json_string<ControlArray1D>(json);

  EXPECT_EQ(arr1d2->shape()[0], 3);
  EXPECT_EQ(arr1d2->dimension(), 1);
  EXPECT_DOUBLE_EQ((*arr1d2)(2), 3.0);
}
}  // namespace tests
