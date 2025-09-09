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
