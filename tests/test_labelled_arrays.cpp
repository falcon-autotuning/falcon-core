#include <gtest/gtest.h>

#include <xtensor/containers/xtensor.hpp>
#include <xtensor/io/xio.hpp>

#include "falcon_core/instrument_interfaces/InstrumentTypes.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/arrays/BaseLabelledArrays.hpp"
#include "falcon_core/math/arrays/Is1D.hpp"
#include "falcon_core/math/arrays/IsLabelled.hpp"
#include "falcon_core/math/arrays/LabelledControlArray1D.hpp"
#include "falcon_core/math/arrays/LabelledControlArrays.hpp"
#include "falcon_core/physics/device_structures/PlungerGate.hpp"
#include "falcon_core/physics/units/Units.hpp"
namespace tests {

using namespace falcon_core::math::arrays;

using ArrayType = ControlArray1D;
using LabelType =
    falcon_core::autotuner_interfaces::contexts::AcquisitionContext;
using LabelledArrayType  = LabelledControlArray1D;
using LabelledArraysType = LabelledControlArrays;

TEST(BaseLabelledArraysTest, ConstructionAndAccess) {
  xt::xarray<double> arr1_data = {1.0, 2.0, 3.0};
  xt::xarray<double> arr2_data = {4.0, 5.0, 6.0};
  auto               arr1      = std::make_shared<ControlArray1D>(arr1_data);
  auto               arr2      = std::make_shared<ControlArray1D>(arr2_data);
  auto               label1    = std::make_shared<LabelType>(
      std::make_shared<falcon_core::physics::device_structures::PlungerGate>(
          "P1"),
      falcon_core::instrument_interfaces::InstrumentTypes::VOLTAGE_SOURCE,
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          falcon_core::physics::units::Units::Volt));
  auto label2 = std::make_shared<LabelType>(
      std::make_shared<falcon_core::physics::device_structures::PlungerGate>(
          "P2"),
      falcon_core::instrument_interfaces::InstrumentTypes::VOLTAGE_SOURCE,
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          falcon_core::physics::units::Units::Volt));
  auto labelled1 = std::make_shared<LabelledControlArray1D>(arr1, label1);
  auto labelled2 = std::make_shared<LabelledControlArray1D>(arr2, label2);

  LabelledArraysType labelled_arrays;
  labelled_arrays.push_back(labelled1);
  labelled_arrays.push_back(labelled2);

  EXPECT_EQ(labelled_arrays.items().size(), 2);
  EXPECT_TRUE(xt::allclose(labelled_arrays.items()[0]->xtensor(), arr1_data));
  EXPECT_TRUE(xt::allclose(labelled_arrays.items()[1]->xtensor(), arr2_data));
  EXPECT_EQ(labelled_arrays.items()[0]->label()->port()->default_name(), "P1");
  EXPECT_EQ(labelled_arrays.items()[1]->label()->port()->default_name(), "P2");
}

TEST(BaseLabelledArraysTest, SerializationRoundTrip) {
  xt::xarray<double> arr1_data = {1.0, 2.0, 3.0};
  xt::xarray<double> arr2_data = {4.0, 5.0, 6.0};
  auto               arr1      = std::make_shared<ControlArray1D>(arr1_data);
  auto               arr2      = std::make_shared<ControlArray1D>(arr2_data);
  auto               label1    = std::make_shared<LabelType>(
      std::make_shared<falcon_core::physics::device_structures::PlungerGate>(
          "P1"),
      falcon_core::instrument_interfaces::InstrumentTypes::VOLTAGE_SOURCE,
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          falcon_core::physics::units::Units::Volt));
  auto label2 = std::make_shared<LabelType>(
      std::make_shared<falcon_core::physics::device_structures::PlungerGate>(
          "P2"),
      falcon_core::instrument_interfaces::InstrumentTypes::VOLTAGE_SOURCE,
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          falcon_core::physics::units::Units::Volt));
  auto labelled1 = std::make_shared<LabelledControlArray1D>(arr1, label1);
  auto labelled2 = std::make_shared<LabelledControlArray1D>(arr2, label2);

  LabelledArraysType labelled_arrays;
  labelled_arrays.push_back(labelled1);
  labelled_arrays.push_back(labelled2);

  // Serialize to JSON string
  std::string json = labelled_arrays.to_json_string();

  // Deserialize from JSON string
  auto deserialized =
      falcon_core::generic::Song::from_json_string<LabelledArraysType>(json);

  ASSERT_EQ(deserialized->items().size(), 2);
  EXPECT_TRUE(xt::allclose(deserialized->items()[0]->xtensor(), arr1_data));
  EXPECT_TRUE(xt::allclose(deserialized->items()[1]->xtensor(), arr2_data));
  EXPECT_EQ(deserialized->items()[0]->label()->port()->default_name(), "P1");
  EXPECT_EQ(deserialized->items()[1]->label()->port()->default_name(), "P2");
}

TEST(IsLabelled1DTest, GetStart) {
  xt::xarray<double> arr_data = {10.0, 20.0, 30.0};
  auto               arr      = std::make_shared<ControlArray1D>(arr_data);
  auto               label    = std::make_shared<LabelType>(
      std::make_shared<falcon_core::physics::device_structures::PlungerGate>(
          "P1"),
      falcon_core::instrument_interfaces::InstrumentTypes::VOLTAGE_SOURCE,
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          falcon_core::physics::units::Units::Volt));
  LabelledControlArray1D labelled(arr, label);

  EXPECT_DOUBLE_EQ(labelled.get_start(), 10.0);
}

TEST(IsLabelled1DTest, ThrowsOnNon1D) {
  xt::xarray<double> arr_data = {{1.0, 2.0}, {3.0, 4.0}};
  auto               arr      = std::make_shared<ControlArray1D>(arr_data);
  auto               label    = std::make_shared<LabelType>(
      std::make_shared<falcon_core::physics::device_structures::PlungerGate>(
          "P1"),
      falcon_core::instrument_interfaces::InstrumentTypes::VOLTAGE_SOURCE,
      std::make_shared<falcon_core::physics::units::SymbolUnit>(
          falcon_core::physics::units::Units::Volt));
  // get_start should throw since arr is not 1D
  LabelledControlArray1D labelled(arr, label);
  EXPECT_THROW({ labelled.get_start(); }, std::runtime_error);
}
}  // namespace tests
