#include <falcon_core/generic/String_c_api.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"
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
    expr_x1                    = String_wrap("x[0]+1");
    expr_xy                    = String_wrap("x[0]+x[1]");
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
  set_last_error(0, nullptr);
  AnalyticFunction_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AnalyticFunction_create(nullptr, expr_x1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AnalyticFunction_create(label_x, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
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
  set_last_error(0, nullptr);
  AnalyticFunction_labels(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AnalyticFunctionTest, Evaluate) {
  auto handle = AnalyticFunction_create(label_x, expr_x1);
  EXPECT_DOUBLE_EQ(AnalyticFunction_evaluate(handle, args_x, 0.0), 3.0);
  AnalyticFunction_destroy(handle);
  set_last_error(0, nullptr);
  AnalyticFunction_evaluate(nullptr, args_x, 0.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AnalyticFunction_evaluate(handle, nullptr, 0.0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AnalyticFunctionTest, EvaluateArraywise) {
  auto handle = AnalyticFunction_create(label_x, expr_x1);
  auto arr    = AnalyticFunction_evaluate_arraywise(handle, args_x, 1.0, 3.0);
  EXPECT_EQ(FArrayDouble_size(arr), 3);
  FArrayDouble_destroy(arr);
  AnalyticFunction_destroy(handle);
  set_last_error(0, nullptr);
  AnalyticFunction_evaluate_arraywise(nullptr, args_x, 1.0, 3.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AnalyticFunction_evaluate_arraywise(handle, nullptr, 1.0, 3.0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AnalyticFunctionTest, EqualNotEqual) {
  auto handle1 = AnalyticFunction_create(label_x, expr_x1);
  auto handle2 = AnalyticFunction_create(label_x, expr_x1);
  EXPECT_TRUE(AnalyticFunction_equal(handle1, handle2));
  EXPECT_FALSE(AnalyticFunction_not_equal(handle1, handle2));
  AnalyticFunction_destroy(handle1);
  AnalyticFunction_destroy(handle2);
  set_last_error(0, nullptr);
  AnalyticFunction_equal(nullptr, handle2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AnalyticFunction_equal(handle1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AnalyticFunction_not_equal(nullptr, handle2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AnalyticFunction_not_equal(handle1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AnalyticFunctionTest, ToJsonFromJson) {
  auto handle  = AnalyticFunction_create(label_x, expr_x1);
  auto json    = AnalyticFunction_to_json_string(handle);
  auto handle2 = AnalyticFunction_from_json_string(json);
  EXPECT_TRUE(AnalyticFunction_equal(handle, handle2));
  AnalyticFunction_destroy(handle);
  AnalyticFunction_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  AnalyticFunction_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AnalyticFunction_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
