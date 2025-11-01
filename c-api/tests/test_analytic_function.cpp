#include <falcon_core/generic/String_c_api.h>
#include <falcon_core/math/AnalyticFunction_c_api.h>
#include <gtest/gtest.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/MapStringDouble_c_api.h"

class AnalyticFunctionTest : public ::testing::Test {
 protected:
  void SetUp() override {
    StringHandle label_x_str   = String_wrap("x");
    StringHandle label_y_str   = String_wrap("y");
    StringHandle raw_labels[2] = {label_x_str, label_y_str};
    label_x                    = ListString_create(&label_x_str, 1);
    label_xy                   = ListString_create(raw_labels, 2);
    expr_x1                    = String_wrap("x+1");
    expr_xy                    = String_wrap("x+y");
    args_x                     = MapStringDouble_create_empty();
    MapStringDouble_insert(args_x, String_wrap("x"), 2.0);
  }
  void TearDown() override {
    ListString_destroy(label_x);
    ListString_destroy(label_xy);
    String_destroy(expr_x1);
    String_destroy(expr_xy);
    MapStringDouble_destroy(args_x);
  }
  ListStringHandle      label_x  = nullptr;
  ListStringHandle      label_xy = nullptr;
  StringHandle          expr_x1  = nullptr;
  StringHandle          expr_xy  = nullptr;
  MapStringDoubleHandle args_x   = nullptr;
};

TEST_F(AnalyticFunctionTest, CreateDestroy) {
  auto handle = AnalyticFunction_create(label_x, expr_x1);
  AnalyticFunction_destroy(handle);
  EXPECT_THROW(AnalyticFunction_destroy(nullptr), std::invalid_argument);
  EXPECT_THROW(AnalyticFunction_create(nullptr, expr_x1),
               std::invalid_argument);
  EXPECT_THROW(AnalyticFunction_create(label_x, nullptr),
               std::invalid_argument);
}

TEST_F(AnalyticFunctionTest, CreateIdentityConstant) {
  auto id = AnalyticFunction_create_identity();
  auto c  = AnalyticFunction_create_constant(42.0);
  AnalyticFunction_destroy(id);
  AnalyticFunction_destroy(c);
}

TEST_F(AnalyticFunctionTest, Labels) {
  auto handle     = AnalyticFunction_create(label_xy, expr_xy);
  auto out_labels = AnalyticFunction_labels(handle);
  EXPECT_EQ(ListString_size(out_labels), 2);
  ListString_destroy(out_labels);
  AnalyticFunction_destroy(handle);
  EXPECT_THROW(AnalyticFunction_labels(nullptr), std::invalid_argument);
}

TEST_F(AnalyticFunctionTest, Evaluate) {
  auto handle = AnalyticFunction_create(label_x, expr_x1);
  EXPECT_DOUBLE_EQ(AnalyticFunction_evaluate(handle, args_x, 0.0), 3.0);
  AnalyticFunction_destroy(handle);
  EXPECT_THROW(AnalyticFunction_evaluate(nullptr, args_x, 0.0),
               std::invalid_argument);
  EXPECT_THROW(AnalyticFunction_evaluate(handle, nullptr, 0.0),
               std::invalid_argument);
}

TEST_F(AnalyticFunctionTest, EvaluateArraywise) {
  auto handle = AnalyticFunction_create(label_x, expr_x1);
  auto arr    = AnalyticFunction_evaluate_arraywise(handle, args_x, 1.0, 3.0);
  EXPECT_EQ(FArrayDouble_size(arr), 4);
  FArrayDouble_destroy(arr);
  AnalyticFunction_destroy(handle);
  EXPECT_THROW(AnalyticFunction_evaluate_arraywise(nullptr, args_x, 1.0, 3.0),
               std::invalid_argument);
  EXPECT_THROW(AnalyticFunction_evaluate_arraywise(handle, nullptr, 1.0, 3.0),
               std::invalid_argument);
}

TEST_F(AnalyticFunctionTest, EqualNotEqual) {
  auto handle1 = AnalyticFunction_create(label_x, expr_x1);
  auto handle2 = AnalyticFunction_create(label_x, expr_x1);
  EXPECT_TRUE(AnalyticFunction_equal(handle1, handle2));
  EXPECT_FALSE(AnalyticFunction_not_equal(handle1, handle2));
  AnalyticFunction_destroy(handle1);
  AnalyticFunction_destroy(handle2);
  EXPECT_THROW(AnalyticFunction_equal(nullptr, handle2), std::invalid_argument);
  EXPECT_THROW(AnalyticFunction_equal(handle1, nullptr), std::invalid_argument);
  EXPECT_THROW(AnalyticFunction_not_equal(nullptr, handle2),
               std::invalid_argument);
  EXPECT_THROW(AnalyticFunction_not_equal(handle1, nullptr),
               std::invalid_argument);
}

TEST_F(AnalyticFunctionTest, ToJsonFromJson) {
  auto handle  = AnalyticFunction_create(label_x, expr_x1);
  auto json    = AnalyticFunction_to_json_string(handle);
  auto handle2 = AnalyticFunction_from_json_string(json);
  EXPECT_TRUE(AnalyticFunction_equal(handle, handle2));
  AnalyticFunction_destroy(handle);
  AnalyticFunction_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(AnalyticFunction_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(AnalyticFunction_from_json_string(nullptr),
               std::invalid_argument);
}
