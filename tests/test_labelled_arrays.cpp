#include <gtest/gtest.h>

#include <xtensor/containers/xtensor.hpp>
#include <xtensor/io/xio.hpp>

#include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"
#include "falcon_core/math/labelled_arrays/IsLabelled1D.hpp"
#include <gtest/gtest.h>

#include <xtensor/containers/xtensor.hpp>
#include <xtensor/io/xio.hpp>

#include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"
#include "falcon_core/math/labelled_arrays/IsLabelled1D.hpp"
#include "falcon_core/math/labelled_arrays/LabelledControlArray1D.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

namespace tests {
using namespace falcon_core::math::labelled_arrays;
using namespace falcon_core::math::arrays;
using falcon_core::instrument_interfaces::names::InstrumentPort;

// Dummy class to test IsLabelled1D
class DummyLabelled1D : public IsLabelled1D<DummyLabelled1D> {
 public:
  DummyLabelled1D(const std::shared_ptr<ControlArray1D>& arr) : _array(arr) {}
  const ControlArray1D& get_array() const { return *_array; }

 private:
  std::shared_ptr<ControlArray1D> _array;
};

using ArrayType          = ControlArray1D;
using LabelType          = InstrumentPort;
using LabelledArrayType  = LabelledControlArray1D;
using LabelledArraysType = BaseLabelledArrays<LabelledArrayType>;

TEST(BaseLabelledArraysTest, ConstructionAndAccess) {
  xt::xarray<double> arr1_data = {1.0, 2.0, 3.0};
  xt::xarray<double> arr2_data = {4.0, 5.0, 6.0};
  auto arr1 = std::make_shared<ControlArray1D>(arr1_data);
  auto arr2 = std::make_shared<ControlArray1D>(arr2_data);
  auto label1 = std::make_shared<LabelType>("dummy1");
  auto label2 = std::make_shared<LabelType>("dummy2");
  auto labelled1 = std::make_shared<LabelledControlArray1D>(arr1, label1);
  auto labelled2 = std::make_shared<LabelledControlArray1D>(arr2, label2);

  LabelledArraysType labelled_arrays;
  labelled_arrays.append(labelled1);
  labelled_arrays.append(labelled2);

  EXPECT_EQ(labelled_arrays.get_arrays().size(), 2);
  EXPECT_TRUE(xt::allclose(labelled_arrays.get_arrays()[0]->array()->xtensor(),
                           arr1_data));
  EXPECT_TRUE(xt::allclose(labelled_arrays.get_arrays()[1]->array()->xtensor(),
                           arr2_data));
  EXPECT_EQ(labelled_arrays.get_arrays()[0]->label()->default_name(), "dummy1");
  EXPECT_EQ(labelled_arrays.get_arrays()[1]->label()->default_name(), "dummy2");
}

TEST(BaseLabelledArraysTest, SerializationRoundTrip) {
  xt::xarray<double> arr1_data = {1.0, 2.0, 3.0};
  xt::xarray<double> arr2_data = {4.0, 5.0, 6.0};
  auto arr1 = std::make_shared<ControlArray1D>(arr1_data);
  auto arr2 = std::make_shared<ControlArray1D>(arr2_data);
  auto label1 = std::make_shared<LabelType>("dummy1");
  auto label2 = std::make_shared<LabelType>("dummy2");
  auto labelled1 = std::make_shared<LabelledControlArray1D>(arr1, label1);
  auto labelled2 = std::make_shared<LabelledControlArray1D>(arr2, label2);

  LabelledArraysType labelled_arrays;
  labelled_arrays.append(labelled1);
  labelled_arrays.append(labelled2);

  // Serialize to JSON string
  std::string json = labelled_arrays.to_json_string();

  // Deserialize from JSON string
  auto deserialized =
      falcon_core::generic::Song::from_json_string<LabelledArraysType>(json);

  ASSERT_EQ(deserialized->get_arrays().size(), 2);
  EXPECT_TRUE(xt::allclose(deserialized->get_arrays()[0]->array()->xtensor(),
                           arr1_data));
  EXPECT_TRUE(xt::allclose(deserialized->get_arrays()[1]->array()->xtensor(),
                           arr2_data));
  EXPECT_EQ(deserialized->get_arrays()[0]->label()->default_name(), "dummy1");
  EXPECT_EQ(deserialized->get_arrays()[1]->label()->default_name(), "dummy2");
}

TEST(IsLabelled1DTest, GetStart) {
  xt::xarray<double> arr_data = {10.0, 20.0, 30.0};
  auto arr = std::make_shared<ControlArray1D>(arr_data);
  DummyLabelled1D labelled(arr);

  EXPECT_DOUBLE_EQ(labelled.get_start(), 10.0);
}

TEST(IsLabelled1DTest, ThrowsOnNon1D) {
  xt::xarray<double> arr_data = {{1.0, 2.0}, {3.0, 4.0}};
  auto arr = std::make_shared<ControlArray1D>(arr_data);
  // get_start should throw since arr is not 1D
  DummyLabelled1D labelled(arr);
  EXPECT_THROW({ labelled.get_start(); }, std::runtime_error);
}
}  // namespace tests
