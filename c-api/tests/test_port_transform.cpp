#include <gtest/gtest.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"
#include "falcon_core/math/AnalyticFunction_c_api.h"

class PortTransformTest : public ::testing::Test {
 protected:
  void SetUp() override {
    port   = InstrumentPort_create_port(String_wrap("P1"));
    labels = ListString_create_empty();
    ListString_push_back(labels, String_wrap("x"));
    transform = AnalyticFunction_create(labels, String_wrap("2x[0] +1"));
    pt        = PortTransform_create(port, transform);
    pt2       = PortTransform_create_constant_transform(port, 5.0);
  }
  void TearDown() override {
    ListString_destroy(labels);
    PortTransform_destroy(pt);
    PortTransform_destroy(pt2);
    InstrumentPort_destroy(port);
    AnalyticFunction_destroy(transform);
  }
  InstrumentPortHandle   port;
  ListStringHandle       labels;
  AnalyticFunctionHandle transform;
  PortTransformHandle    pt;
  PortTransformHandle    pt2;
};

TEST_F(PortTransformTest, CreateDestroy) {
  auto p = PortTransform_create(port, transform);
  PortTransform_destroy(p);

  auto c = PortTransform_create_constant_transform(port, 3.0);
  PortTransform_destroy(c);

  auto i = PortTransform_create_identity_transform(port);
  PortTransform_destroy(i);

  EXPECT_THROW(PortTransform_create(nullptr, transform), std::invalid_argument);
  EXPECT_THROW(PortTransform_create(port, nullptr), std::invalid_argument);
  EXPECT_THROW(PortTransform_create_constant_transform(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(PortTransform_create_identity_transform(nullptr),
               std::invalid_argument);
  EXPECT_THROW(PortTransform_destroy(nullptr), std::invalid_argument);
}

TEST_F(PortTransformTest, Accessors) {
  auto p = PortTransform_port(pt);
  EXPECT_NE(p, nullptr);
  InstrumentPort_destroy(p);

  auto labels = PortTransform_labels(pt);
  EXPECT_NE(labels, nullptr);
  ListString_destroy(labels);

  EXPECT_THROW(PortTransform_port(nullptr), std::invalid_argument);
  EXPECT_THROW(PortTransform_labels(nullptr), std::invalid_argument);
}

TEST_F(PortTransformTest, Evaluate) {
  auto args = MapStringDouble_create_empty();
  MapStringDouble_insert(args, String_wrap("x"), 2.0);

  double result = PortTransform_evaluate(pt, args, 0.0);
  EXPECT_DOUBLE_EQ(result, 2.0 * 2.0 + 1.0);  // f(x) = 2x + 1

  auto arr = PortTransform_evaluate_arraywise(pt, args, 1.0, 3.0);
  EXPECT_NE(arr, nullptr);
  EXPECT_EQ(FArrayDouble_size(arr), 3);

  FArrayDouble_destroy(arr);
  MapStringDouble_destroy(args);

  EXPECT_THROW(PortTransform_evaluate(nullptr, args, 0.0),
               std::invalid_argument);
  EXPECT_THROW(PortTransform_evaluate(pt, nullptr, 0.0), std::invalid_argument);
  EXPECT_THROW(PortTransform_evaluate_arraywise(nullptr, args, 1.0, 3.0),
               std::invalid_argument);
  EXPECT_THROW(PortTransform_evaluate_arraywise(pt, nullptr, 1.0, 3.0),
               std::invalid_argument);
}

TEST_F(PortTransformTest, Equality) {
  EXPECT_FALSE(PortTransform_equal(pt, pt2));
  EXPECT_TRUE(PortTransform_not_equal(pt, pt2));

  EXPECT_THROW(PortTransform_equal(nullptr, pt2), std::invalid_argument);
  EXPECT_THROW(PortTransform_equal(pt, nullptr), std::invalid_argument);
  EXPECT_THROW(PortTransform_not_equal(nullptr, pt2), std::invalid_argument);
  EXPECT_THROW(PortTransform_not_equal(pt, nullptr), std::invalid_argument);
}

TEST_F(PortTransformTest, ToJsonFromJson) {
  auto json = PortTransform_to_json_string(pt);
  EXPECT_NE(json, nullptr);

  auto pt3 = PortTransform_from_json_string(json);
  EXPECT_TRUE(PortTransform_equal(pt, pt3));

  PortTransform_destroy(pt3);
  String_destroy(json);

  EXPECT_THROW(PortTransform_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(PortTransform_from_json_string(nullptr), std::invalid_argument);
}
