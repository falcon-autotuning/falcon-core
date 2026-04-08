#include <gtest/gtest.h>

#include "falcon-core/generic/List.hpp"
#include "falcon-core/generic/Map.hpp"
#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon-core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon-core/math/AnalyticFunction.hpp"

namespace {
using namespace falcon_core::instrument_interfaces::port_transforms;
using namespace falcon_core::instrument_interfaces::names;
using namespace falcon_core::math;
using namespace falcon_core::generic;

class PortTransformTest : public ::testing::Test {
 protected:
  InstrumentPortSP portA = std::make_shared<InstrumentPort>("A");

  // x[0]*t^2 + x[1]
  ListSP<VariableName> labels = std::make_shared<List<VariableName>>(
      std::vector<VariableName>{"x0", "x1"});
  std::string        expr = "x[0]*t^2 + x[1]";
  AnalyticFunctionSP quadratic =
      std::make_shared<AnalyticFunction>(labels, expr);

  // Identity: x[0]
  AnalyticFunctionSP identity = AnalyticFunction::Identity();

  // Constant: 42.0
  AnalyticFunctionSP constant = AnalyticFunction::Constant(42.0);
};

TEST_F(PortTransformTest, ConstructorThrowsOnNullPort) {
  EXPECT_THROW(PortTransform(nullptr, quadratic), std::invalid_argument);
}

TEST_F(PortTransformTest, ConstructorThrowsOnNullTransform) {
  EXPECT_THROW(PortTransform(portA, nullptr), std::invalid_argument);
}

TEST_F(PortTransformTest, ConstructorSucceeds) {
  EXPECT_NO_THROW(PortTransform(portA, quadratic));
  PortTransform t(portA, quadratic);
  EXPECT_EQ(t.port(), portA);
}

TEST_F(PortTransformTest, ConstantTransformFactory) {
  auto pt = PortTransform::ConstantTransform(portA, 42.0);
  ASSERT_NE(pt, nullptr);
  EXPECT_EQ(pt->port(), portA);
  auto args = std::make_shared<Map<VariableName, double>>();
  EXPECT_DOUBLE_EQ(pt->evaluate(args, 0.0), 42.0);
}

TEST_F(PortTransformTest, IdentityTransformFactory) {
  auto pt = PortTransform::IdentityTransform(portA);
  ASSERT_NE(pt, nullptr);
  EXPECT_EQ(pt->port(), portA);
  auto args = std::make_shared<Map<VariableName, double>>();
  args->insert("x", 7.0);
  EXPECT_DOUBLE_EQ(pt->evaluate(args, 0.0), 7.0);
}

TEST_F(PortTransformTest, QuadraticTransformEvaluation) {
  PortTransform pt(portA, quadratic);
  auto          args = std::make_shared<Map<VariableName, double>>();
  args->insert("x0", 2.0);
  args->insert("x1", 3.0);
  EXPECT_DOUBLE_EQ(pt.evaluate(args, 5.0), 2.0 * 25.0 + 3.0);  // 2*25+3 = 53
}

TEST_F(PortTransformTest, EqualityOperators) {
  auto pt1 = PortTransform::ConstantTransform(portA, 1.0);
  auto pt2 = PortTransform::ConstantTransform(portA, 1.0);
  auto pt3 = PortTransform::ConstantTransform(portA, 2.0);
  EXPECT_TRUE(*pt1 == *pt2);
  EXPECT_FALSE(*pt1 != *pt2);
  EXPECT_FALSE(*pt1 == *pt3);
  EXPECT_TRUE(*pt1 != *pt3);
}

TEST_F(PortTransformTest, SerializationRoundTrip) {
  auto pt           = PortTransform::ConstantTransform(portA, 123.45);
  auto string       = pt->to_json_string();
  auto deserialized = PortTransform::from_json_string<PortTransform>(string);
  EXPECT_EQ(*pt, *deserialized);
}

TEST_F(PortTransformTest, ConstantTransformThrowsOnNullPort) {
  EXPECT_THROW(PortTransform::ConstantTransform(nullptr, 42.0),
               std::invalid_argument);
}

TEST_F(PortTransformTest, IdentityTransformThrowsOnNullPort) {
  EXPECT_THROW(PortTransform::IdentityTransform(nullptr),
               std::invalid_argument);
}

}  // namespace
