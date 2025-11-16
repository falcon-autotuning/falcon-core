#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include <vector>

#include "falcon_core/generic/ListLabelledControlArray1D_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesLabelledControlArray1D_c_api.h"
#include "falcon_core/math/arrays/ControlArray_c_api.h"
#include "falcon_core/math/arrays/LabelledControlArray1D_c_api.h"

class AxesLabelledControlArray1DTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape[0] = 3;
    data[0]  = 1.0;
    data[1]  = 2.0;
    data[2]  = 3.0;
    shape[0] = 3;
    axes     = AxesLabelledControlArray1D_create_empty();

    auto pre_item1 = ControlArray_from_data(data, shape, 1);
    auto pre_item2 = ControlArray_from_data(data, shape, 1);

    ca1d =
        track_labelled_control_array(LabelledControlArray1D_from_controlarray(
            pre_item1,
            AcquisitionContext_create(
                Connection_create_plunger_gate(String_wrap("A")),
                InstrumentTypes_voltmeter(),
                SymbolUnit_create_volt())));

    ca2d =
        track_labelled_control_array(LabelledControlArray1D_from_controlarray(
            pre_item2,
            AcquisitionContext_create(
                Connection_create_plunger_gate(String_wrap("A")),
                InstrumentTypes_voltmeter(),
                SymbolUnit_create_volt())));

    AxesLabelledControlArray1D_push_back(axes, ca1d);
    AxesLabelledControlArray1D_push_back(axes, ca2d);

    axes2 = AxesLabelledControlArray1D_create_empty();
    AxesLabelledControlArray1D_push_back(axes2, ca1d);
    AxesLabelledControlArray1D_push_back(axes2, ca2d);
  }

  void TearDown() override {
    // Avoid double-free: if an item is contained in axes/axes2 then axes
    // destroy will own its destruction, so skip destroying those items here.
    std::vector<LabelledControlArray1DHandle> remaining;
    for (auto h : created_items) {
      bool owned_by_axes = false;
      if (axes && AxesLabelledControlArray1D_contains(axes, h))
        owned_by_axes = true;
      if (axes2 && AxesLabelledControlArray1D_contains(axes2, h))
        owned_by_axes = true;
      if (!owned_by_axes) remaining.push_back(h);
    }

    if (axes) {
      AxesLabelledControlArray1D_destroy(axes);
      axes = nullptr;
    }
    if (axes2) {
      AxesLabelledControlArray1D_destroy(axes2);
      axes2 = nullptr;
    }

    for (auto h : remaining) {
      LabelledControlArray1D_destroy(h);
    }
    created_items.clear();
  }

  LabelledControlArray1DHandle track_labelled_control_array(
      LabelledControlArray1DHandle h) {
    created_items.push_back(h);
    return h;
  }

  AxesLabelledControlArray1DHandle axes  = nullptr;
  AxesLabelledControlArray1DHandle axes2 = nullptr;
  LabelledControlArray1DHandle     rawbuffer[2];
  double                           data[3];
  size_t                           shape[1];
  LabelledControlArray1DHandle     ca2d;
  LabelledControlArray1DHandle     ca1d;
  LabelledControlArray1DHandle     ca2d_2;
  FArrayDoubleHandle               fa2d;

  std::vector<LabelledControlArray1DHandle> created_items;
};

TEST_F(AxesLabelledControlArray1DTest, CreateDestroy) {
  auto h = AxesLabelledControlArray1D_create_empty();
  AxesLabelledControlArray1D_destroy(h);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  LabelledControlArray1DHandle     arr[2] = {ca2d, ca1d};
  ListLabelledControlArray1DHandle handle =
      ListLabelledControlArray1D_create(arr, 2);
  EXPECT_NO_THROW(AxesLabelledControlArray1D_create(handle));
  ListLabelledControlArray1D_destroy(handle);
}

TEST_F(AxesLabelledControlArray1DTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesLabelledControlArray1D_size(axes), 2u);
  LabelledControlArray1DHandle     arr[2] = {ca2d, ca1d};
  ListLabelledControlArray1DHandle handle =
      ListLabelledControlArray1D_create(arr, 2);
  auto label = AcquisitionContext_create(
      Connection_create_plunger_gate(String_wrap("A")),
      InstrumentTypes_voltmeter(),
      SymbolUnit_create_volt());
  auto lca = LabelledControlArray1D_from_controlarray(
      ControlArray_from_data(data, shape, 1), label);
  LabelledControlArray1DHandle out[1] = {lca};
  auto h2 = AxesLabelledControlArray1D_create_raw(out, 1);
  if (h2) AxesLabelledControlArray1D_destroy(h2);
  ListLabelledControlArray1D_destroy(handle);
  //
  AxesLabelledControlArray1D_push_back(axes, lca);
  LabelledControlArray1DHandle out2[3];
  EXPECT_EQ(AxesLabelledControlArray1D_items(axes, out2, 3), 3u);
  for (size_t i = 0; i < 3; ++i) {
    LabelledControlArray1D_destroy(out2[i]);
  }

  AxesLabelledControlArray1D_erase_at(axes, 2);
  AxesLabelledControlArray1D_clear(axes);
  EXPECT_TRUE(AxesLabelledControlArray1D_empty(axes));
}

TEST_F(AxesLabelledControlArray1DTest, ContainsIndexEquality) {
  EXPECT_NO_THROW(AxesLabelledControlArray1D_contains(
      axes, AxesLabelledControlArray1D_at(axes, 0)));
  EXPECT_NO_THROW(AxesLabelledControlArray1D_index(
      axes, AxesLabelledControlArray1D_at(axes, 0)));
  EXPECT_NO_THROW(AxesLabelledControlArray1D_equal(axes, axes2));
}

TEST_F(AxesLabelledControlArray1DTest, SerializationRoundTrip) {
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW({
    auto json   = AxesLabelledControlArray1D_to_json_string(axes);
    auto loaded = AxesLabelledControlArray1D_from_json_string(json);
    AxesLabelledControlArray1D_destroy(loaded);
    String_destroy(json);
  });
}

TEST_F(AxesLabelledControlArray1DTest, EqualityWorks) {
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_equal(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_not_equal(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesLabelledControlArray1D_equal(axes, axes));
  EXPECT_NO_THROW(AxesLabelledControlArray1D_not_equal(axes, axes2));
}

TEST_F(AxesLabelledControlArray1DTest, Intersection) {
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_intersection(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_intersection(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesLabelledControlArray1D_intersection(axes, axes2));
}

TEST_F(AxesLabelledControlArray1DTest, MiscNullChecks) {
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_push_back(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_push_back(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_push_back(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_contains(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_contains(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_index(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_index(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_items(nullptr, rawbuffer, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_items(axes, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray1D_create_raw(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}
