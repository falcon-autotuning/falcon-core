#include <gtest/gtest.h>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentTypes_c_api.h"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransforms_c_api.h"
#include "falcon_core/math/AnalyticFunction_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class PortTransformsTest : public ::testing::Test {
 protected:
  void SetUp() override {
    port   = InstrumentPort_create_port(String_wrap("P1"),
                                      NULL,
                                      InstrumentTypes_voltmeter(),
                                      SymbolUnit_create_volt(),
                                      String_wrap(""));
    labels = ListString_create_empty();
    ListString_push_back(labels, String_wrap("x"));
    transform  = AnalyticFunction_create(labels, String_wrap("2x[0] +1"));
    pt         = PortTransform_create(port, transform);
    pt2        = PortTransform_create_constant_transform(port, 5.0);
    transforms = PortTransforms_create_empty();
    PortTransforms_push_back(transforms, pt);
    PortTransforms_push_back(transforms, pt2);
  }
  void TearDown() override {
    PortTransforms_destroy(transforms);
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
  PortTransformsHandle   transforms;
};

TEST_F(PortTransformsTest, CreateDestroy) {
  auto t = PortTransforms_create_empty();
  PortTransforms_destroy(t);

  PortTransformHandle arr[2] = {pt, pt2};
  auto                t2     = PortTransforms_create_raw(arr, 2);
  PortTransforms_destroy(t2);

  auto list = PortTransforms_items(transforms);
  auto t3   = PortTransforms_create(list);
  PortTransforms_destroy(t3);
  ListPortTransform_destroy(list);

  set_last_error(0, nullptr);
  PortTransforms_create_raw(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PortTransformsTest, Accessors) {
  EXPECT_EQ(PortTransforms_size(transforms), 2);
  EXPECT_FALSE(PortTransforms_empty(transforms));

  auto items = PortTransforms_items(transforms);
  EXPECT_NE(items, nullptr);
  ListPortTransform_destroy(items);

  auto list = PortTransforms_transforms(transforms);
  EXPECT_NE(list, nullptr);
  ListPortTransform_destroy(list);

  auto t = PortTransforms_at(transforms, 0);
  EXPECT_NE(t, nullptr);
  PortTransform_destroy(t);

  set_last_error(0, nullptr);
  PortTransforms_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_transforms(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PortTransformsTest, Mutators) {
  auto t = PortTransforms_create_empty();
  PortTransforms_push_back(t, pt);
  EXPECT_EQ(PortTransforms_size(t), 1);

  PortTransforms_erase_at(t, 0);
  EXPECT_EQ(PortTransforms_size(t), 0);

  PortTransforms_push_back(t, pt2);
  PortTransforms_clear(t);
  EXPECT_EQ(PortTransforms_size(t), 0);

  PortTransforms_destroy(t);

  set_last_error(0, nullptr);
  PortTransforms_push_back(nullptr, pt);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_push_back(transforms, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PortTransformsTest, ContainsIndex) {
  EXPECT_TRUE(PortTransforms_contains(transforms, pt));
  EXPECT_EQ(PortTransforms_index(transforms, pt), 0);

  set_last_error(0, nullptr);
  PortTransforms_contains(nullptr, pt);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_contains(transforms, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_contains(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  PortTransforms_index(nullptr, pt);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_index(transforms, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_index(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PortTransformsTest, EqualityIntersection) {
  auto t2 = PortTransforms_create_empty();
  PortTransforms_push_back(t2, pt);

  EXPECT_FALSE(PortTransforms_equal(transforms, t2));
  EXPECT_TRUE(PortTransforms_not_equal(transforms, t2));
  EXPECT_TRUE(PortTransforms_equal(transforms, transforms));
  EXPECT_FALSE(PortTransforms_not_equal(transforms, transforms));

  auto inter = PortTransforms_intersection(transforms, t2);
  EXPECT_NE(inter, nullptr);
  PortTransforms_destroy(inter);

  PortTransforms_destroy(t2);

  set_last_error(0, nullptr);
  PortTransforms_equal(nullptr, transforms);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_equal(transforms, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_equal(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  PortTransforms_not_equal(nullptr, transforms);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_not_equal(transforms, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_not_equal(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  PortTransforms_intersection(nullptr, transforms);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_intersection(transforms, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_intersection(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PortTransformsTest, ToJsonFromJson) {
  auto json = PortTransforms_to_json_string(transforms);
  EXPECT_NE(json, nullptr);

  auto t2 = PortTransforms_from_json_string(json);
  EXPECT_TRUE(PortTransforms_equal(transforms, t2));

  PortTransforms_destroy(t2);
  String_destroy(json);

  set_last_error(0, nullptr);
  PortTransforms_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PortTransforms_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
