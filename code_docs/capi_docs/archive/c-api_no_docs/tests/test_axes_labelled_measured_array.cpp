#include <gtest/gtest.h>

#include <vector>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ListLabelledMeasuredArray_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesLabelledMeasuredArray_c_api.h"
#include "falcon_core/math/arrays/LabelledMeasuredArray_c_api.h"

class AxesLabelledMeasuredArrayTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape2d[0] = 2;
    shape2d[1] = 3;
    data2d[0]  = 1.0;
    data2d[1]  = 2.0;
    data2d[2]  = 3.0;
    data2d[3]  = 1.0;
    data2d[4]  = 2.0;
    data2d[5]  = 3.0;
    axes       = AxesLabelledMeasuredArray_create_empty();

    auto pre_item1 = MeasuredArray_from_data(data2d, shape2d, 2);
    auto pre_item2 = MeasuredArray_from_data(data2d, shape2d, 2);

    ca1d =
        track_labelled_control_array(LabelledMeasuredArray_from_measured_array(
            pre_item1,
            AcquisitionContext_create(
                Connection_create_plunger_gate(String_wrap("A")),
                InstrumentTypes_voltmeter(),
                SymbolUnit_create_volt())));

    ca2d =
        track_labelled_control_array(LabelledMeasuredArray_from_measured_array(
            pre_item2,
            AcquisitionContext_create(
                Connection_create_plunger_gate(String_wrap("A")),
                InstrumentTypes_voltmeter(),
                SymbolUnit_create_volt())));

    AxesLabelledMeasuredArray_push_back(axes, ca1d);
    AxesLabelledMeasuredArray_push_back(axes, ca2d);

    axes2 = AxesLabelledMeasuredArray_create_empty();
    AxesLabelledMeasuredArray_push_back(axes2, ca1d);
    AxesLabelledMeasuredArray_push_back(axes2, ca2d);
  }

  void TearDown() override {
    // Avoid double-free: if an item is contained in axes/axes2 then axes
    // destroy will own its destruction, so skip destroying those items here.
    std::vector<LabelledMeasuredArrayHandle> remaining;
    for (auto h : created_items) {
      bool owned_by_axes = false;
      if (axes && AxesLabelledMeasuredArray_contains(axes, h))
        owned_by_axes = true;
      if (axes2 && AxesLabelledMeasuredArray_contains(axes2, h))
        owned_by_axes = true;
      if (!owned_by_axes) remaining.push_back(h);
    }

    if (axes) {
      AxesLabelledMeasuredArray_destroy(axes);
      axes = nullptr;
    }
    if (axes2) {
      AxesLabelledMeasuredArray_destroy(axes2);
      axes2 = nullptr;
    }

    for (auto h : remaining) {
      LabelledMeasuredArray_destroy(h);
    }
    created_items.clear();
  }

  LabelledMeasuredArrayHandle track_labelled_control_array(
      LabelledMeasuredArrayHandle h) {
    created_items.push_back(h);
    return h;
  }

  AxesLabelledMeasuredArrayHandle axes  = nullptr;
  AxesLabelledMeasuredArrayHandle axes2 = nullptr;
  LabelledMeasuredArrayHandle     rawbuffer[2];
  double                          data2d[6];
  size_t                          shape2d[2];
  double                          data1d[6];
  size_t                          shape1d[1];
  LabelledMeasuredArrayHandle     ca2d;
  LabelledMeasuredArrayHandle     ca1d;
  LabelledMeasuredArrayHandle     ca2d_2;
  FArrayDoubleHandle              fa2d;

  std::vector<LabelledMeasuredArrayHandle> created_items;
};

TEST_F(AxesLabelledMeasuredArrayTest, CreateDestroy) {
  auto h = AxesLabelledMeasuredArray_create_empty();
  AxesLabelledMeasuredArray_destroy(h);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  LabelledMeasuredArrayHandle     arr[2] = {ca2d, ca1d};
  ListLabelledMeasuredArrayHandle handle =
      ListLabelledMeasuredArray_create(arr, 2);
  EXPECT_NO_THROW(AxesLabelledMeasuredArray_create(handle));
  ListLabelledMeasuredArray_destroy(handle);
}

TEST_F(AxesLabelledMeasuredArrayTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesLabelledMeasuredArray_size(axes), 2u);
  LabelledMeasuredArrayHandle     arr[2] = {ca2d, ca1d};
  ListLabelledMeasuredArrayHandle handle =
      ListLabelledMeasuredArray_create(arr, 2);
  // ListLabelledMeasuredArrayHandle out1[1] = {handle};
  auto label = AcquisitionContext_create(
      Connection_create_plunger_gate(String_wrap("A")),
      InstrumentTypes_voltmeter(),
      SymbolUnit_create_volt());
  auto lca = LabelledMeasuredArray_from_measured_array(
      MeasuredArray_from_data(data2d, shape2d, 2), label);
  LabelledMeasuredArrayHandle out[1] = {lca};
  ListLabelledMeasuredArray_destroy(handle);
  //
  AxesLabelledMeasuredArray_push_back(axes, lca);
  LabelledMeasuredArrayHandle out2[3];
  EXPECT_EQ(AxesLabelledMeasuredArray_items(axes, out2, 3), 3u);
  for (size_t i = 0; i < 3; ++i) {
    LabelledMeasuredArray_destroy(out2[i]);
  }

  AxesLabelledMeasuredArray_erase_at(axes, 2);
  AxesLabelledMeasuredArray_clear(axes);
  EXPECT_TRUE(AxesLabelledMeasuredArray_empty(axes));
}

TEST_F(AxesLabelledMeasuredArrayTest, ContainsIndexEquality) {
  EXPECT_NO_THROW(AxesLabelledMeasuredArray_contains(
      axes, AxesLabelledMeasuredArray_at(axes, 0)));
  EXPECT_NO_THROW(AxesLabelledMeasuredArray_index(
      axes, AxesLabelledMeasuredArray_at(axes, 0)));
  EXPECT_NO_THROW(AxesLabelledMeasuredArray_equal(axes, axes2));
}

TEST_F(AxesLabelledMeasuredArrayTest, SerializationRoundTrip) {
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW({
    auto json   = AxesLabelledMeasuredArray_to_json_string(axes);
    auto loaded = AxesLabelledMeasuredArray_from_json_string(json);
    AxesLabelledMeasuredArray_destroy(loaded);
    String_destroy(json);
  });
}

TEST_F(AxesLabelledMeasuredArrayTest, EqualityWorks) {
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_equal(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_not_equal(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesLabelledMeasuredArray_equal(axes, axes));
  EXPECT_NO_THROW(AxesLabelledMeasuredArray_not_equal(axes, axes2));
}

TEST_F(AxesLabelledMeasuredArrayTest, Intersection) {
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_intersection(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_intersection(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesLabelledMeasuredArray_intersection(axes, axes2));
}

TEST_F(AxesLabelledMeasuredArrayTest, MiscNullChecks) {
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_push_back(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_push_back(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_push_back(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_contains(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_contains(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_index(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_index(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_items(nullptr, rawbuffer, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_items(axes, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
}
