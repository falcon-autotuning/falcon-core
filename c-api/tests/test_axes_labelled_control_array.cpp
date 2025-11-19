#include <gtest/gtest.h>

#include <vector>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ListLabelledControlArray_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesLabelledControlArray_c_api.h"
#include "falcon_core/math/arrays/ControlArray_c_api.h"
#include "falcon_core/math/arrays/LabelledControlArray_c_api.h"

class AxesLabelledControlArrayTest : public ::testing::Test {
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
    axes       = AxesLabelledControlArray_create_empty();

    auto pre_item1 = ControlArray_from_data(data2d, shape2d, 2);
    auto pre_item2 = ControlArray_from_data(data2d, shape2d, 2);

    ca1d = track_labelled_control_array(LabelledControlArray_from_control_array(
        pre_item1,
        AcquisitionContext_create(
            Connection_create_plunger_gate(String_wrap("A")),
            InstrumentTypes_voltmeter(),
            SymbolUnit_create_volt())));

    ca2d = track_labelled_control_array(LabelledControlArray_from_control_array(
        pre_item2,
        AcquisitionContext_create(
            Connection_create_plunger_gate(String_wrap("A")),
            InstrumentTypes_voltmeter(),
            SymbolUnit_create_volt())));

    AxesLabelledControlArray_push_back(axes, ca1d);
    AxesLabelledControlArray_push_back(axes, ca2d);

    axes2 = AxesLabelledControlArray_create_empty();
    AxesLabelledControlArray_push_back(axes2, ca1d);
    AxesLabelledControlArray_push_back(axes2, ca2d);
  }

  void TearDown() override {
    // Avoid double-free: if an item is contained in axes/axes2 then axes
    // destroy will own its destruction, so skip destroying those items here.
    std::vector<LabelledControlArrayHandle> remaining;
    for (auto h : created_items) {
      bool owned_by_axes = false;
      if (axes && AxesLabelledControlArray_contains(axes, h))
        owned_by_axes = true;
      if (axes2 && AxesLabelledControlArray_contains(axes2, h))
        owned_by_axes = true;
      if (!owned_by_axes) remaining.push_back(h);
    }

    if (axes) {
      AxesLabelledControlArray_destroy(axes);
      axes = nullptr;
    }
    if (axes2) {
      AxesLabelledControlArray_destroy(axes2);
      axes2 = nullptr;
    }

    for (auto h : remaining) {
      LabelledControlArray_destroy(h);
    }
    created_items.clear();
  }

  LabelledControlArrayHandle track_labelled_control_array(
      LabelledControlArrayHandle h) {
    created_items.push_back(h);
    return h;
  }

  AxesLabelledControlArrayHandle axes  = nullptr;
  AxesLabelledControlArrayHandle axes2 = nullptr;
  LabelledControlArrayHandle     rawbuffer[2];
  double                         data2d[6];
  size_t                         shape2d[2];
  double                         data1d[6];
  size_t                         shape1d[1];
  LabelledControlArrayHandle     ca2d;
  LabelledControlArrayHandle     ca1d;
  LabelledControlArrayHandle     ca2d_2;
  FArrayDoubleHandle             fa2d;

  std::vector<LabelledControlArrayHandle> created_items;
};

TEST_F(AxesLabelledControlArrayTest, CreateDestroy) {
  auto h = AxesLabelledControlArray_create_empty();
  AxesLabelledControlArray_destroy(h);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  LabelledControlArrayHandle     arr[2] = {ca2d, ca1d};
  ListLabelledControlArrayHandle handle =
      ListLabelledControlArray_create(arr, 2);
  EXPECT_NO_THROW(AxesLabelledControlArray_create(handle));
  ListLabelledControlArray_destroy(handle);
}

TEST_F(AxesLabelledControlArrayTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesLabelledControlArray_size(axes), 2u);
  LabelledControlArrayHandle     arr[2] = {ca2d, ca1d};
  ListLabelledControlArrayHandle handle =
      ListLabelledControlArray_create(arr, 2);
  // ListLabelledControlArrayHandle out1[1] = {handle};
  auto label = AcquisitionContext_create(
      Connection_create_plunger_gate(String_wrap("A")),
      InstrumentTypes_voltmeter(),
      SymbolUnit_create_volt());
  auto lca = LabelledControlArray_from_control_array(
      ControlArray_from_data(data2d, shape2d, 2), label);
  LabelledControlArrayHandle out[1] = {lca};
  auto                       h2 = AxesLabelledControlArray_create_raw(out, 1);
  if (h2) AxesLabelledControlArray_destroy(h2);
  ListLabelledControlArray_destroy(handle);
  //
  AxesLabelledControlArray_push_back(axes, lca);
  LabelledControlArrayHandle out2[3];
  EXPECT_EQ(AxesLabelledControlArray_items(axes, out2, 3), 3u);
  for (size_t i = 0; i < 3; ++i) {
    LabelledControlArray_destroy(out2[i]);
  }

  AxesLabelledControlArray_erase_at(axes, 2);
  AxesLabelledControlArray_clear(axes);
  EXPECT_TRUE(AxesLabelledControlArray_empty(axes));
}

TEST_F(AxesLabelledControlArrayTest, ContainsIndexEquality) {
  EXPECT_NO_THROW(AxesLabelledControlArray_contains(
      axes, AxesLabelledControlArray_at(axes, 0)));
  EXPECT_NO_THROW(AxesLabelledControlArray_index(
      axes, AxesLabelledControlArray_at(axes, 0)));
  EXPECT_NO_THROW(AxesLabelledControlArray_equal(axes, axes2));
}

TEST_F(AxesLabelledControlArrayTest, SerializationRoundTrip) {
  set_last_error(0, nullptr);
  AxesLabelledControlArray_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW({
    auto json   = AxesLabelledControlArray_to_json_string(axes);
    auto loaded = AxesLabelledControlArray_from_json_string(json);
    AxesLabelledControlArray_destroy(loaded);
    String_destroy(json);
  });
}

TEST_F(AxesLabelledControlArrayTest, EqualityWorks) {
  set_last_error(0, nullptr);
  AxesLabelledControlArray_equal(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_not_equal(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesLabelledControlArray_equal(axes, axes));
  EXPECT_NO_THROW(AxesLabelledControlArray_not_equal(axes, axes2));
}

TEST_F(AxesLabelledControlArrayTest, Intersection) {
  set_last_error(0, nullptr);
  AxesLabelledControlArray_intersection(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_intersection(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesLabelledControlArray_intersection(axes, axes2));
}

TEST_F(AxesLabelledControlArrayTest, MiscNullChecks) {
  set_last_error(0, nullptr);
  AxesLabelledControlArray_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_push_back(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_push_back(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_push_back(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_contains(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_contains(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_index(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_index(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_items(nullptr, rawbuffer, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_items(axes, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesLabelledControlArray_create_raw(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}
