#include <gtest/gtest.h>

#include <falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>
#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include <falcon_core/math/arrays/LabelledControlArray.hpp>
#include <falcon_core/math/arrays/LabelledMeasuredArray.hpp>
#include <stdexcept>
#include <string>
#include <xtensor/xarray.hpp>
namespace {
using namespace falcon_core::math::arrays;
using falcon_core::autotuner_interfaces::contexts::AcquisitionContext;
using falcon_core::autotuner_interfaces::contexts::AcquisitionContextSP;
using namespace falcon_core;
using namespace generic;
using namespace autotuner_interfaces;
using namespace contexts;
using namespace math::arrays;
using falcon_core::instrument_interfaces::names::InstrumentPort;
using falcon_core::instrument_interfaces::names::InstrumentPortSP;

class LabelledArraysTest : public ::testing::Test {
 protected:
  xt::xarray<double>      arr1 = {1.0, 2.0};
  xt::xarray<double>      arr2 = {3.0, 4.0};
  AcquisitionContextSP    labelA;
  AcquisitionContextSP    labelB;
  InstrumentPortSP        portA;
  InstrumentPortSP        portB;
  LabelledMeasuredArraySP lma1;
  LabelledMeasuredArraySP lma2;
  LabelledControlArraySP  lca1;
  LabelledControlArraySP  lca2;
  void                    SetUp() override {
    portA = InstrumentPort::Knob(
        "A", physics::device_structures::Connection::PlungerGate("PA"));
    labelA = std::make_shared<AcquisitionContext>(portA);
    portB  = InstrumentPort::Knob(
        "B", physics::device_structures::Connection::PlungerGate("PB"));
    labelB = std::make_shared<AcquisitionContext>(portB);
    lma1   = std::make_shared<LabelledMeasuredArray>(
        std::make_shared<MeasuredArray>(arr1), labelA);
    lma2 = std::make_shared<LabelledMeasuredArray>(
        std::make_shared<MeasuredArray>(arr2), labelB);
    lca1 = std::make_shared<LabelledControlArray>(
        std::make_shared<ControlArray>(arr1), labelA);
    lca2 = std::make_shared<LabelledControlArray>(
        std::make_shared<ControlArray>(arr2), labelB);
  }
};

TEST_F(LabelledArraysTest, DefaultConstructorMeasured) {
  LabelledArrays<LabelledMeasuredArray> arrs;
  EXPECT_EQ(arrs.size(), 0);
}

TEST_F(LabelledArraysTest, DefaultConstructorControl) {
  LabelledArrays<LabelledControlArray> arrs;
  EXPECT_EQ(arrs.size(), 0);
}

TEST_F(LabelledArraysTest, ItemsConstructorMeasured) {
  std::vector<LabelledMeasuredArraySP>  vec{lma1, lma2};
  LabelledArrays<LabelledMeasuredArray> arrs(vec);
  EXPECT_EQ(arrs.size(), 2);
  EXPECT_EQ(arrs.arrays().size(), 2);
  EXPECT_EQ(arrs.labels()->size(), 2);
  EXPECT_EQ(*arrs.labels()->at(0), *labelA);
  EXPECT_EQ(*arrs.labels()->at(1), *labelB);
}

TEST_F(LabelledArraysTest, ItemsConstructorControl) {
  std::vector<LabelledControlArraySP>  vec{lca1, lca2};
  LabelledArrays<LabelledControlArray> arrs(vec);
  EXPECT_EQ(arrs.size(), 2);
  EXPECT_EQ(arrs.arrays().size(), 2);
  EXPECT_EQ(arrs.labels()->size(), 2);
  EXPECT_EQ(*arrs.labels()->at(0), *labelA);
  EXPECT_EQ(*arrs.labels()->at(1), *labelB);
}

TEST_F(LabelledArraysTest, UniqueLabelCheckThrows) {
  std::vector<LabelledMeasuredArraySP> vec{lma1, lma1};
  EXPECT_THROW(LabelledArrays<LabelledMeasuredArray> arrs(vec),
               std::runtime_error);
}

TEST_F(LabelledArraysTest, IsControlArraysAndIsMeasuredArrays) {
  std::vector<LabelledControlArraySP>   cvec{lca1, lca2};
  std::vector<LabelledMeasuredArraySP>  mvec{lma1, lma2};
  LabelledArrays<LabelledControlArray>  carrs(cvec);
  LabelledArrays<LabelledMeasuredArray> marrs(mvec);
  EXPECT_TRUE(carrs.is_control_arrays());
  EXPECT_FALSE(carrs.is_measured_arrays());
  EXPECT_TRUE(marrs.is_measured_arrays());
  EXPECT_FALSE(marrs.is_control_arrays());
}

TEST_F(LabelledArraysTest, SerializationRoundTripMeasured) {
  std::vector<LabelledMeasuredArraySP>  vec{lma1, lma2};
  LabelledArrays<LabelledMeasuredArray> arrs(vec);
  auto                                  json = arrs.to_json_string();
  auto arrs2 = LabelledArrays<LabelledMeasuredArray>::from_json_string<
      LabelledArrays<LabelledMeasuredArray>>(json);
  EXPECT_EQ(arrs.size(), arrs2->size());
  EXPECT_EQ(*arrs.labels()->at(0), *arrs2->labels()->at(0));
  EXPECT_EQ(*arrs.labels()->at(1), *arrs2->labels()->at(1));
}

TEST_F(LabelledArraysTest, SerializationRoundTripControl) {
  std::vector<LabelledControlArraySP>  vec{lca1, lca2};
  LabelledArrays<LabelledControlArray> arrs(vec);
  auto                                 json = arrs.to_json_string();
  auto arrs2 = LabelledArrays<LabelledControlArray>::from_json_string<
      LabelledArrays<LabelledControlArray>>(json);
  EXPECT_EQ(arrs, *arrs2);
}

TEST_F(LabelledArraysTest, StaticConstructorsMeasured) {
  auto arrs_empty =
      LabelledArrays<LabelledMeasuredArray>::LabelledMeasuredArrays();
  EXPECT_EQ(arrs_empty->size(), 0);

  std::vector<LabelledMeasuredArraySP> vec{lma1, lma2};
  auto                                 arrs_vec =
      LabelledArrays<LabelledMeasuredArray>::LabelledMeasuredArrays(vec);
  EXPECT_EQ(arrs_vec->size(), 2);
}

TEST_F(LabelledArraysTest, StaticConstructorsControl) {
  auto arrs_empty =
      LabelledArrays<LabelledControlArray>::LabelledControlArrays();
  EXPECT_EQ(arrs_empty->size(), 0);

  std::vector<LabelledControlArraySP> vec{lca1, lca2};
  auto                                arrs_vec =
      LabelledArrays<LabelledControlArray>::LabelledControlArrays(vec);
  EXPECT_EQ(arrs_vec->size(), 2);
}

TEST_F(LabelledArraysTest, ArraysGetterMeasured) {
  std::vector<LabelledMeasuredArraySP>  vec{lma1, lma2};
  LabelledArrays<LabelledMeasuredArray> arrs(vec);
  auto&                                 arrays_ref = arrs.arrays();
  EXPECT_EQ(arrays_ref.size(), 2);
  EXPECT_EQ(arrays_ref[0], lma1);
}

TEST_F(LabelledArraysTest, ArraysGetterControl) {
  std::vector<LabelledControlArraySP>  vec{lca1, lca2};
  LabelledArrays<LabelledControlArray> arrs(vec);
  auto&                                arrays_ref = arrs.arrays();
  EXPECT_EQ(arrays_ref.size(), 2);
  EXPECT_EQ(arrays_ref[0], lca1);
}

TEST_F(LabelledArraysTest, LabelsGetterMeasured) {
  std::vector<LabelledMeasuredArraySP>  vec{lma1, lma2};
  LabelledArrays<LabelledMeasuredArray> arrs(vec);
  auto                                  labels = arrs.labels();
  EXPECT_EQ(labels->size(), 2);
  EXPECT_EQ(*labels->at(0), *labelA);
}

TEST_F(LabelledArraysTest, LabelsGetterControl) {
  std::vector<LabelledControlArraySP>  vec{lca1, lca2};
  LabelledArrays<LabelledControlArray> arrs(vec);
  auto                                 labels = arrs.labels();
  EXPECT_EQ(labels->size(), 2);
  EXPECT_EQ(*labels->at(0), *labelA);
}

TEST_F(LabelledArraysTest, CheckArrayLabelsControlThrows) {
  std::vector<LabelledControlArraySP> vec{lca1, lca1};
  EXPECT_THROW(LabelledArrays<LabelledControlArray> arrs(vec),
               std::runtime_error);
}

TEST_F(LabelledArraysTest, IsControlArraysHandlesNullptr) {
  std::vector<LabelledControlArraySP> vec{lca1, nullptr};
  EXPECT_THROW(LabelledArrays<LabelledControlArray> arrs(vec),
               std::invalid_argument);
}

TEST_F(LabelledArraysTest, IsMeasuredArraysHandlesNullptr) {
  std::vector<LabelledMeasuredArraySP> vec{lma1, nullptr};
  EXPECT_THROW(LabelledArrays<LabelledMeasuredArray> arrs(vec),
               std::invalid_argument);
}
}  // namespace
