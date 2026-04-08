#include <gtest/gtest.h>

#include "falcon-core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon-core/communications/messages/MeasurementResponse.hpp"
#include "falcon-core/math/arrays/LabelledArrays.hpp"
#include "falcon-core/math/arrays/LabelledMeasuredArray.hpp"

namespace {
using namespace falcon_core::communications::messages;
using namespace falcon_core::math::arrays;
using namespace falcon_core::autotuner_interfaces::contexts;

class MeasurementResponseTest : public ::testing::Test {
 protected:
  LabelledArraysSP<LabelledMeasuredArray> arrays;
  LabelledMeasuredArraySP                 measured_array;
  AcquisitionContextSP                    label;

  void SetUp() override {
    // Create a dummy MeasuredArray with shape [2]
    auto base_array = falcon_core::generic::FArray<double>::zeros({2});
    // Create a dummy InstrumentPort for AcquisitionContext
    auto port = std::make_shared<
        falcon_core::instrument_interfaces::names::InstrumentPort>(
        "Vg1",
        falcon_core::physics::device_structures::Connection::PlungerGate("P1"));
    label          = std::make_shared<AcquisitionContext>(port);
    measured_array = std::make_shared<LabelledMeasuredArray>(base_array, label);
    arrays = LabelledArrays<LabelledMeasuredArray>::LabelledMeasuredArrays(
        {measured_array});
  }
};

TEST_F(MeasurementResponseTest, ConstructorWorks) {
  MeasurementResponse resp(arrays);
  EXPECT_EQ(resp.arrays(), arrays);
}

TEST_F(MeasurementResponseTest, ThrowsOnNullArrays) {
  EXPECT_THROW(MeasurementResponse(nullptr), std::invalid_argument);
}

TEST_F(MeasurementResponseTest, ArraysGetterWorks) {
  MeasurementResponse resp(arrays);
  EXPECT_EQ(resp.arrays(), arrays);
}

TEST_F(MeasurementResponseTest, EqualityOperators) {
  MeasurementResponse resp1(arrays);
  MeasurementResponse resp2(arrays);
  EXPECT_TRUE(resp1 == resp2);
  EXPECT_FALSE(resp1 != resp2);
}

TEST_F(MeasurementResponseTest, SerializationRoundTrip) {
  MeasurementResponse resp(arrays);
  auto                string = resp.to_json_string();
  auto                loaded =
      MeasurementResponse::from_json_string<MeasurementResponse>(string);
  EXPECT_EQ(resp, *loaded);
}
}  // namespace
