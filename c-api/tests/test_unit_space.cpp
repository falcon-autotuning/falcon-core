#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListInt_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/UnitSpace_c_api.h"
#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"
#include "falcon_core/math/domains/Domain_c_api.h"

class UnitSpaceTest : public ::testing::Test {
 protected:
  void SetUp() override {
    domain = Domain_create(0.0, 1.0);
    axes   = AxesDiscretizer_create_empty();
    d1     = Discretizer_create_cartesian_discretizer(0.1);
    d2     = Discretizer_create_cartesian_discretizer(0.2);
    AxesDiscretizer_push_back(axes, d1);
    AxesDiscretizer_push_back(axes, d2);
    double_list = ListDouble_create_empty();
    ListDouble_push_back(double_list, one);
    int_list = ListInt_create_empty();
    ListInt_push_back(int_list, int_one);
    axes_double = AxesDouble_create(double_list);
    axes_int    = AxesInt_create(int_list);
    one         = 1.0;
    int_one     = 1;
    unitspace   = UnitSpace_create(axes, domain);
  }
  void TearDown() override {
    UnitSpace_destroy(unitspace);
    Domain_destroy(domain);
    AxesDiscretizer_destroy(axes);
    Discretizer_destroy(d1);
    Discretizer_destroy(d2);
    AxesDouble_destroy(axes_double);
    AxesInt_destroy(axes_int);
    ListDouble_destroy(double_list);
    ListInt_destroy(int_list);
  }
  DomainHandle          domain;
  DiscretizerHandle     d1;
  DiscretizerHandle     d2;
  ListDoubleHandle      double_list;
  ListIntHandle         int_list;
  AxesDiscretizerHandle axes;
  AxesDoubleHandle      axes_double;
  AxesIntHandle         axes_int;
  double                one     = 1.0;
  int                   int_one = 1;
  UnitSpaceHandle       unitspace;
};

TEST_F(UnitSpaceTest, CreateDestroy) {
  auto us = UnitSpace_create(axes, domain);
  UnitSpace_destroy(us);
  set_last_error(0, nullptr);
  UnitSpace_create(nullptr, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_create(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(UnitSpaceTest, CreateRayspace) {
  auto us = UnitSpace_create_rayspace(1.0, 2.0, domain);
  UnitSpace_destroy(us);
  set_last_error(0, nullptr);
  UnitSpace_create_rayspace(1.0, 2.0, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(UnitSpaceTest, CreateCartesianspace) {
  auto us = UnitSpace_create_cartesianspace(axes_double, domain);
  UnitSpace_destroy(us);
  set_last_error(0, nullptr);
  UnitSpace_create_cartesianspace(nullptr, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_create_cartesianspace(axes_double, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(UnitSpaceTest, CreateCartesian1Dspace) {
  auto us = UnitSpace_create_cartesian1Dspace(1.0, domain);
  UnitSpace_destroy(us);
  set_last_error(0, nullptr);
  UnitSpace_create_cartesian1Dspace(1.0, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(UnitSpaceTest, CreateCartesian2Dspace) {
  auto us = UnitSpace_create_cartesian2Dspace(axes_double, domain);
  UnitSpace_destroy(us);
  set_last_error(0, nullptr);
  UnitSpace_create_cartesian2Dspace(nullptr, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_create_cartesian2Dspace(axes_double, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(UnitSpaceTest, AxesDomainSpaceShapeDimensionCompile) {
  auto axes  = UnitSpace_axes(unitspace);
  auto dom   = UnitSpace_domain(unitspace);
  auto shape = UnitSpace_shape(unitspace);
  EXPECT_GE(UnitSpace_dimension(unitspace), 0);
  UnitSpace_compile(unitspace);
  FArrayDoubleHandle space = UnitSpace_space(unitspace);
  AxesDiscretizer_destroy(axes);
  Domain_destroy(dom);
  ListInt_destroy(shape);
  FArrayDouble_destroy(space);
  set_last_error(0, nullptr);
  UnitSpace_axes(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_domain(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_shape(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_dimension(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_compile(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(UnitSpaceTest, CreateArray) {
  auto arr = UnitSpace_create_array(unitspace, axes_int);
  AxesControlArray_destroy(arr);
  set_last_error(0, nullptr);
  UnitSpace_create_array(nullptr, axes_int);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_create_array(unitspace, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(UnitSpaceTest, PushBackSizeEmptyEraseClearAtItemsContainsIndex) {
  auto d = Discretizer_create_cartesian_discretizer(0.5);
  UnitSpace_push_back(unitspace, d);
  EXPECT_GE(UnitSpace_size(unitspace), 1);
  EXPECT_FALSE(UnitSpace_empty(unitspace));
  UnitSpace_erase_at(unitspace, 0);
  UnitSpace_clear(unitspace);
  EXPECT_TRUE(UnitSpace_empty(unitspace));
  UnitSpace_push_back(unitspace, d);
  auto at = UnitSpace_at(unitspace, 0);
  Discretizer_destroy(at);
  DiscretizerHandle out[1];
  EXPECT_EQ(UnitSpace_items(unitspace, out, 1), 1);
  Discretizer_destroy(out[0]);
  EXPECT_TRUE(UnitSpace_contains(unitspace, d));
  EXPECT_EQ(UnitSpace_index(unitspace, d), 0);
  Discretizer_destroy(d);

  set_last_error(0, nullptr);
  UnitSpace_push_back(nullptr, d);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_push_back(unitspace, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_items(nullptr, out, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_items(unitspace, nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_contains(nullptr, d);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_contains(unitspace, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_index(nullptr, d);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_index(unitspace, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(UnitSpaceTest, IntersectionEqualNotEqual) {
  auto us2   = UnitSpace_create(axes, domain);
  auto inter = UnitSpace_intersection(unitspace, us2);
  EXPECT_TRUE(UnitSpace_equal(unitspace, us2));
  EXPECT_FALSE(UnitSpace_not_equal(unitspace, us2));
  UnitSpace_destroy(inter);
  UnitSpace_destroy(us2);
  set_last_error(0, nullptr);
  UnitSpace_intersection(nullptr, unitspace);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_intersection(unitspace, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_equal(nullptr, unitspace);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_equal(unitspace, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_not_equal(nullptr, unitspace);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_not_equal(unitspace, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(UnitSpaceTest, ToJsonFromJson) {
  auto json = UnitSpace_to_json_string(unitspace);
  auto us2  = UnitSpace_from_json_string(json);
  EXPECT_TRUE(UnitSpace_equal(unitspace, us2));
  UnitSpace_destroy(us2);
  String_destroy(json);
  set_last_error(0, nullptr);
  UnitSpace_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(UnitSpaceTest, SpaceCollection) {
  set_last_error(0, nullptr);
  UnitSpace_space(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  UnitSpace_space(unitspace);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(UnitSpaceTest, ItemsBufferTooSmall) {
  DiscretizerHandle out[0];
  set_last_error(0, nullptr);
  UnitSpace_items(unitspace, out, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
