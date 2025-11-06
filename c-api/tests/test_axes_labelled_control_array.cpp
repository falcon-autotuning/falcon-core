#include <gtest/gtest.h>

#include "falcon_core/generic/ListLabelledControlArray_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesLabelledControlArray_c_api.h"
#include "falcon_core/math/arrays/ControlArray_c_api.h"
#include "falcon_core/math/arrays/LabelledControlArray_c_api.h"
class AxesLabelledControlArrayTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape2d[0]     = 2;
    shape2d[1]     = 3;
    data2d[0]      = 1.0;
    data2d[1]      = 2.0;
    data2d[2]      = 3.0;
    data2d[3]      = 1.0;
    data2d[4]      = 2.0;
    data2d[5]      = 3.0;
    axes           = AxesLabelledControlArray_create_empty();
    auto pre_item1 = ControlArray_from_data(data2d, shape2d, 2);
    auto pre_item2 = ControlArray_from_data(data2d, shape2d, 2);

    ca1d = LabelledControlArray_from_controlarray(
        pre_item1,
        AcquisitionContext_create(
            Connection_create_plunger_gate(String_wrap("A")),
            InstrumentTypes_voltmeter(),
            SymbolUnit_create_volt()));

    ca2d = LabelledControlArray_from_controlarray(
        pre_item2,
        AcquisitionContext_create(
            Connection_create_plunger_gate(String_wrap("A")),
            InstrumentTypes_voltmeter(),
            SymbolUnit_create_volt()));

    AxesLabelledControlArray_push_back(axes, ca1d);
    AxesLabelledControlArray_push_back(axes, ca2d);

    axes2 = AxesLabelledControlArray_create_empty();
    AxesLabelledControlArray_push_back(axes2, ca1d);
    AxesLabelledControlArray_push_back(axes2, ca2d);
  }
  void TearDown() override { AxesLabelledControlArray_destroy(axes); }

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
};

TEST_F(AxesLabelledControlArrayTest, CreateDestroy) {
  auto h = AxesLabelledControlArray_create_empty();
  AxesLabelledControlArray_destroy(h);
  EXPECT_THROW(AxesLabelledControlArray_create(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_destroy(nullptr),
               std::invalid_argument);
  LabelledControlArrayHandle     arr[2] = {ca2d, ca1d};
  ListLabelledControlArrayHandle handle =
      ListLabelledControlArray_create(arr, 2);
  EXPECT_NO_THROW(AxesLabelledControlArray_create(handle));
}

TEST_F(AxesLabelledControlArrayTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesLabelledControlArray_size(axes), 2u);
  LabelledControlArrayHandle     arr[2] = {ca2d, ca1d};
  ListLabelledControlArrayHandle handle =
      ListLabelledControlArray_create(arr, 2);
  ListLabelledControlArrayHandle out1[1] = {handle};
  LabelledControlArrayHandle     out[1]  = {
      ControlArray_from_data(data2d, shape2d, 2)};
  auto h2 = AxesLabelledControlArray_create_raw(out, 1);

  AxesLabelledControlArray_push_back(
      axes, ControlArray_from_data(data2d, shape2d, 2));
  LabelledControlArrayHandle out2[3];
  AxesLabelledControlArray_items(axes, out2, 3);
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
  EXPECT_THROW(AxesLabelledControlArray_from_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_NO_THROW({
    auto json   = AxesLabelledControlArray_to_json_string(axes);
    auto loaded = AxesLabelledControlArray_from_json_string(json);
    AxesLabelledControlArray_destroy(loaded);
    String_destroy(json);
  });
}

TEST_F(AxesLabelledControlArrayTest, EqualityWorks) {
  EXPECT_THROW(AxesLabelledControlArray_equal(axes, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_not_equal(nullptr, axes2),
               std::invalid_argument);
  EXPECT_NO_THROW(AxesLabelledControlArray_equal(axes, axes));
  EXPECT_NO_THROW(AxesLabelledControlArray_not_equal(axes, axes2));
}

TEST_F(AxesLabelledControlArrayTest, Intersection) {
  EXPECT_THROW(AxesLabelledControlArray_intersection(nullptr, axes2),
               std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_intersection(axes, nullptr),
               std::invalid_argument);
  EXPECT_NO_THROW(AxesLabelledControlArray_intersection(axes, axes2));
}

TEST_F(AxesLabelledControlArrayTest, MiscNullChecks) {
  EXPECT_THROW(AxesLabelledControlArray_destroy(nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_push_back(nullptr, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_push_back(axes, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_size(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_erase_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_push_back(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_contains(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_contains(axes, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_index(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_index(axes, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_items(nullptr, rawbuffer, 2),
               std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_items(axes, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesLabelledControlArray_create_raw(nullptr, 2),
               std::invalid_argument);
}
