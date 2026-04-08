#include <gtest/gtest.h>

#include <vector>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/ListLabelledMeasuredArray1D_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/math/AxesLabelledMeasuredArray1D_c_api.h"
#include "falcon-core/math/arrays/ControlArray_c_api.h"
#include "falcon-core/math/arrays/LabelledMeasuredArray1D_c_api.h"

class AxesLabelledMeasuredArray1DTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape[0] = 3;
    data[0]  = 1.0;
    data[1]  = 2.0;
    data[2]  = 3.0;
    shape[0] = 3;
    axes     = AxesLabelledMeasuredArray1D_create_empty();

    auto pre_item1 = ControlArray_from_data(data, shape, 1);
    auto pre_item2 = ControlArray_from_data(data, shape, 1);

    ca1d = track_labelled_control_array(
        LabelledMeasuredArray1D_from_measured_array(
            pre_item1,
            AcquisitionContext_create(
                Connection_create_plunger_gate(String_wrap("A")),
                InstrumentTypes_voltmeter(),
                SymbolUnit_create_volt())));

    ca2d = track_labelled_control_array(
        LabelledMeasuredArray1D_from_measured_array(
            pre_item2,
            AcquisitionContext_create(
                Connection_create_plunger_gate(String_wrap("A")),
                InstrumentTypes_voltmeter(),
                SymbolUnit_create_volt())));

    AxesLabelledMeasuredArray1D_push_back(axes, ca1d);
    AxesLabelledMeasuredArray1D_push_back(axes, ca2d);

    axes2 = AxesLabelledMeasuredArray1D_create_empty();
    AxesLabelledMeasuredArray1D_push_back(axes2, ca1d);
    AxesLabelledMeasuredArray1D_push_back(axes2, ca2d);
  }

  void TearDown() override {
    // Avoid double-free: if an item is contained in axes/axes2 then axes
    // destroy will own its destruction, so skip destroying those items here.
    std::vector<LabelledMeasuredArray1DHandle> remaining;
    for (auto h : created_items) {
      bool owned_by_axes = false;
      if (axes && AxesLabelledMeasuredArray1D_contains(axes, h))
        owned_by_axes = true;
      if (axes2 && AxesLabelledMeasuredArray1D_contains(axes2, h))
        owned_by_axes = true;
      if (!owned_by_axes) remaining.push_back(h);
    }

    if (axes) {
      AxesLabelledMeasuredArray1D_destroy(axes);
      axes = nullptr;
    }
    if (axes2) {
      AxesLabelledMeasuredArray1D_destroy(axes2);
      axes2 = nullptr;
    }

    for (auto h : remaining) {
      LabelledMeasuredArray1D_destroy(h);
    }
    created_items.clear();
  }

  LabelledMeasuredArray1DHandle track_labelled_control_array(
      LabelledMeasuredArray1DHandle h) {
    created_items.push_back(h);
    return h;
  }

  AxesLabelledMeasuredArray1DHandle axes  = nullptr;
  AxesLabelledMeasuredArray1DHandle axes2 = nullptr;
  LabelledMeasuredArray1DHandle     rawbuffer[2];
  double                            data[3];
  size_t                            shape[1];
  LabelledMeasuredArray1DHandle     ca2d;
  LabelledMeasuredArray1DHandle     ca1d;
  LabelledMeasuredArray1DHandle     ca2d_2;
  FArrayDoubleHandle                fa2d;

  std::vector<LabelledMeasuredArray1DHandle> created_items;
};

TEST_F(AxesLabelledMeasuredArray1DTest, CreateDestroy) {
  auto h = AxesLabelledMeasuredArray1D_create_empty();
  AxesLabelledMeasuredArray1D_destroy(h);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  LabelledMeasuredArray1DHandle     arr[2] = {ca2d, ca1d};
  ListLabelledMeasuredArray1DHandle handle =
      ListLabelledMeasuredArray1D_create(arr, 2);
  EXPECT_NO_THROW(AxesLabelledMeasuredArray1D_create(handle));
  ListLabelledMeasuredArray1D_destroy(handle);
}

TEST_F(AxesLabelledMeasuredArray1DTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesLabelledMeasuredArray1D_size(axes), 2u);
  LabelledMeasuredArray1DHandle     arr[2] = {ca2d, ca1d};
  ListLabelledMeasuredArray1DHandle handle =
      ListLabelledMeasuredArray1D_create(arr, 2);
  // ListLabelledMeasuredArray1DHandle out1[1] = {handle};
  auto label = AcquisitionContext_create(
      Connection_create_plunger_gate(String_wrap("A")),
      InstrumentTypes_voltmeter(),
      SymbolUnit_create_volt());
  auto lca = LabelledMeasuredArray1D_from_measured_array(
      MeasuredArray_from_data(data, shape, 1), label);
  ListLabelledMeasuredArray1D_destroy(handle);
  AxesLabelledMeasuredArray1D_push_back(axes, lca);
  LabelledMeasuredArray1DHandle out2[3];
  EXPECT_EQ(AxesLabelledMeasuredArray1D_items(axes, out2, 3), 3u);
  for (size_t i = 0; i < 3; ++i) {
    LabelledMeasuredArray1D_destroy(out2[i]);
  }

  AxesLabelledMeasuredArray1D_erase_at(axes, 2);
  AxesLabelledMeasuredArray1D_clear(axes);
  EXPECT_TRUE(AxesLabelledMeasuredArray1D_empty(axes));
}

TEST_F(AxesLabelledMeasuredArray1DTest, ContainsIndexEquality) {
  EXPECT_NO_THROW(AxesLabelledMeasuredArray1D_contains(
      axes, AxesLabelledMeasuredArray1D_at(axes, 0)));
  EXPECT_NO_THROW(AxesLabelledMeasuredArray1D_index(
      axes, AxesLabelledMeasuredArray1D_at(axes, 0)));
  EXPECT_NO_THROW(AxesLabelledMeasuredArray1D_equal(axes, axes2));
}

TEST_F(AxesLabelledMeasuredArray1DTest, SerializationRoundTrip) {
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW({
    auto json   = AxesLabelledMeasuredArray1D_to_json_string(axes);
    auto loaded = AxesLabelledMeasuredArray1D_from_json_string(json);
    AxesLabelledMeasuredArray1D_destroy(loaded);
    String_destroy(json);
  });
}

TEST_F(AxesLabelledMeasuredArray1DTest, EqualityWorks) {
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_equal(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_not_equal(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesLabelledMeasuredArray1D_equal(axes, axes));
  EXPECT_NO_THROW(AxesLabelledMeasuredArray1D_not_equal(axes, axes2));
}

TEST_F(AxesLabelledMeasuredArray1DTest, Intersection) {
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_intersection(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_intersection(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesLabelledMeasuredArray1D_intersection(axes, axes2));
}

TEST_F(AxesLabelledMeasuredArray1DTest, MiscNullChecks) {
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_push_back(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_push_back(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_push_back(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_contains(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_contains(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_index(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_index(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_items(nullptr, rawbuffer, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_items(axes, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledMeasuredArray1D_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
}
