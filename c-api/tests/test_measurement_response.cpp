#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include "falcon_core/communications/messages/MeasurementResponse_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/math/arrays/LabelledMeasuredArray_c_api.h"

class MeasurementResponseTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape_arr[0] = 2;
    shape_arr[1] = 2;
    zeros        = FArrayDouble_from_shape(shape_arr, 2);
    conn         = Connection_create_plunger_gate(String_wrap("plung"));
    label        = AcquisitionContext_create(
        conn, InstrumentTypes_voltmeter(), SymbolUnit_create_volt());
    arr         = LabelledMeasuredArray_from_farray(zeros, label);
    arrays_list = ListLabelledMeasuredArray_create_empty();
    empty_list  = ListLabelledMeasuredArray_create_empty();
    ListLabelledMeasuredArray_push_back(arrays_list, arr);
    arrays = LabelledArraysLabelledMeasuredArray_create(arrays_list);
    resp   = MeasurementResponse_create(arrays);
    resp2  = MeasurementResponse_create(
        LabelledArraysLabelledMeasuredArray_create(empty_list));
  }
  void TearDown() override {
    FArrayDouble_destroy(zeros);
    AcquisitionContext_destroy(label);
    Connection_destroy(conn);
    ListLabelledMeasuredArray_destroy(empty_list);
    ListLabelledMeasuredArray_destroy(arrays_list);
    MeasurementResponse_destroy(resp);
    MeasurementResponse_destroy(resp2);
    LabelledMeasuredArray_destroy(arr);
    LabelledArraysLabelledMeasuredArray_destroy(arrays);
  }
  ListLabelledMeasuredArrayHandle           empty_list;
  ListLabelledMeasuredArrayHandle           arrays_list;
  ConnectionHandle                          conn;
  size_t                                    shape_arr[2];
  AcquisitionContextHandle                  label;
  FArrayDoubleHandle                        zeros;
  LabelledMeasuredArrayHandle               arr;
  LabelledArraysLabelledMeasuredArrayHandle arrays;
  MeasurementResponseHandle                 resp;
  MeasurementResponseHandle                 resp2;
};

TEST_F(MeasurementResponseTest, CreateDestroy) {
  auto r = MeasurementResponse_create(arrays);
  MeasurementResponse_destroy(r);
  EXPECT_THROW(MeasurementResponse_create(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasurementResponse_destroy(nullptr), std::invalid_argument);
}

TEST_F(MeasurementResponseTest, Accessors) {
  auto a = MeasurementResponse_arrays(resp);
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray_size(a), 1);
  MeasurementResponse_destroy(a);
  EXPECT_THROW(MeasurementResponse_arrays(nullptr), std::invalid_argument);
}

TEST_F(MeasurementResponseTest, Equality) {
  EXPECT_FALSE(MeasurementResponse_equal(resp, resp2));
  EXPECT_TRUE(MeasurementResponse_not_equal(resp, resp2));
  EXPECT_TRUE(MeasurementResponse_equal(resp, resp));
  EXPECT_FALSE(MeasurementResponse_not_equal(resp, resp));

  EXPECT_THROW(MeasurementResponse_equal(nullptr, resp2),
               std::invalid_argument);
  EXPECT_THROW(MeasurementResponse_equal(resp, nullptr), std::invalid_argument);
  EXPECT_THROW(MeasurementResponse_not_equal(nullptr, resp2),
               std::invalid_argument);
  EXPECT_THROW(MeasurementResponse_not_equal(resp, nullptr),
               std::invalid_argument);
}

TEST_F(MeasurementResponseTest, ToJsonFromJson) {
  auto json = MeasurementResponse_to_json_string(resp);
  auto r2   = MeasurementResponse_from_json_string(json);
  EXPECT_TRUE(MeasurementResponse_equal(resp, r2));
  MeasurementResponse_destroy(r2);
  String_destroy(json);

  EXPECT_THROW(MeasurementResponse_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasurementResponse_from_json_string(nullptr),
               std::invalid_argument);
}
