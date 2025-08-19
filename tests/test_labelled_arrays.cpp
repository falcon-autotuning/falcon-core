#include <gtest/gtest.h>

#include <Eigen/Dense>

#include "falcon_core/math/arrays/BaseArray.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"
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

using ArrayType          = BaseArray<double>;
using LabelType          = int;
using LabelledArrayType  = BaseLabelledArray<ArrayType, LabelType>;
using LabelledArraysType = BaseLabelledArrays<LabelledArrayType>;

TEST(BaseLabelledArraysTest, ConstructionAndAccess) {
  Eigen::MatrixXd mat1(1, 3);
  mat1 << 1.0, 2.0, 3.0;
  Eigen::MatrixXd mat2(1, 3);
  mat2 << 4.0, 5.0, 6.0;
  auto arr1      = std::make_shared<ArrayType>(mat1);
  auto arr2      = std::make_shared<ArrayType>(mat2);
  auto labelled1 = std::make_shared<LabelledArrayType>(
      arr1, std::make_shared<LabelType>(42));
  auto labelled2 = std::make_shared<LabelledArrayType>(
      arr2, std::make_shared<LabelType>(43));

  LabelledArraysType labelled_arrays;
  labelled_arrays.append(labelled1);
  labelled_arrays.append(labelled2);

  EXPECT_EQ(labelled_arrays.get_arrays().size(), 2);
  EXPECT_TRUE(labelled_arrays.get_arrays()[0]->array()->data().isApprox(mat1));
  EXPECT_TRUE(labelled_arrays.get_arrays()[1]->array()->data().isApprox(mat2));
  EXPECT_EQ(*labelled_arrays.get_arrays()[0]->label(), 42);
  EXPECT_EQ(*labelled_arrays.get_arrays()[1]->label(), 43);
}

TEST(BaseLabelledArraysTest, SerializationRoundTrip) {
  Eigen::MatrixXd mat1(1, 3);
  mat1 << 1.0, 2.0, 3.0;
  Eigen::MatrixXd mat2(1, 3);
  mat2 << 4.0, 5.0, 6.0;
  auto arr1      = std::make_shared<ArrayType>(mat1);
  auto arr2      = std::make_shared<ArrayType>(mat2);
  auto labelled1 = std::make_shared<LabelledArrayType>(
      arr1, std::make_shared<LabelType>(42));
  auto labelled2 = std::make_shared<LabelledArrayType>(
      arr2, std::make_shared<LabelType>(43));

  LabelledArraysType labelled_arrays;
  labelled_arrays.append(labelled1);
  labelled_arrays.append(labelled2);

  // Serialize to JSON string
  std::string json = labelled_arrays.to_json_string();

  // Deserialize from JSON string
  auto deserialized =
      falcon_core::generic::Song::from_json_string<LabelledArraysType>(json);

  ASSERT_EQ(deserialized->get_arrays().size(), 2);
  EXPECT_TRUE(deserialized->get_arrays()[0]->array()->data().isApprox(mat1));
  EXPECT_TRUE(deserialized->get_arrays()[1]->array()->data().isApprox(mat2));
  EXPECT_EQ(*deserialized->get_arrays()[0]->label(), 42);
  EXPECT_EQ(*deserialized->get_arrays()[1]->label(), 43);
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
