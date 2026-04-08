#include <falcon-core/generic/ListPairInterpretationContextDouble_c_api.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListPairInterpretationContextDoubleTest : public ::testing::Test {
 protected:
  void destroy_string(PairInterpretationContextDoubleHandle sh) {
    PairInterpretationContextDouble_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairInterpretationContextDoubleHandle> created_strings;
  PairInterpretationContextDoubleHandle              track_quantity(
                   const PairInterpretationContextDoubleHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    ListMeasurementContextHandle axes_indp1 =
        ListMeasurementContext_create_empty();
    ListMeasurementContext_push_back(
        axes_indp1,
        MeasurementContext_create(
            Connection_create_plunger_gate(String_wrap("gateA")),
            InstrumentTypes_voltmeter()));
    ListMeasurementContextHandle axes_dep1 =
        ListMeasurementContext_create_empty();
    ListMeasurementContext_push_back(
        axes_dep1,
        MeasurementContext_create(
            Connection_create_plunger_gate(String_wrap("gateB")),
            InstrumentTypes_voltmeter()));
    ListMeasurementContextHandle axes_indp2 =
        ListMeasurementContext_create_empty();
    ListMeasurementContext_push_back(
        axes_indp2,
        MeasurementContext_create(
            Connection_create_plunger_gate(String_wrap("gateC")),
            InstrumentTypes_voltmeter()));
    ListMeasurementContextHandle axes_dep2 =
        ListMeasurementContext_create_empty();
    ListMeasurementContext_push_back(
        axes_dep2,
        MeasurementContext_create(
            Connection_create_plunger_gate(String_wrap("gateD")),
            InstrumentTypes_voltmeter()));
    sh1 = track_quantity(PairInterpretationContextDouble_create(
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp1),
                                     axes_dep1,
                                     SymbolUnit_create_volt()),
        1.0));
    sh2 = track_quantity(PairInterpretationContextDouble_create(
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp2),
                                     axes_dep2,
                                     SymbolUnit_create_volt()),
        3.0));
  }
  PairInterpretationContextDoubleHandle sh1;
  PairInterpretationContextDoubleHandle sh2;
};

TEST_F(ListPairInterpretationContextDoubleTest, CreateEmpty) {
  auto handle = ListPairInterpretationContextDouble_create_empty();
  EXPECT_TRUE(ListPairInterpretationContextDouble_empty(handle));
  EXPECT_EQ(ListPairInterpretationContextDouble_size(handle), 0);
  ListPairInterpretationContextDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextDoubleTest, FillValue) {
  auto handle = ListPairInterpretationContextDouble_fill_value(3, sh1);
  EXPECT_EQ(ListPairInterpretationContextDouble_size(handle), 3);
  ListPairInterpretationContextDouble_destroy(handle);
}

TEST_F(ListPairInterpretationContextDoubleTest, CreateFromArray) {
  PairInterpretationContextDoubleHandle     arr[2] = {sh1, sh2};
  ListPairInterpretationContextDoubleHandle handle =
      ListPairInterpretationContextDouble_create(arr, 2);
  EXPECT_EQ(ListPairInterpretationContextDouble_size(handle), 2);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairInterpretationContextDouble_destroy(handle);
}

TEST_F(ListPairInterpretationContextDoubleTest, SizeEmptyInvalid) {
  auto handle = ListPairInterpretationContextDouble_create_empty();
  EXPECT_EQ(ListPairInterpretationContextDouble_size(handle), 0);
  ListPairInterpretationContextDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextDoubleTest, EmptyInvalid) {
  auto handle = ListPairInterpretationContextDouble_create_empty();
  EXPECT_TRUE(ListPairInterpretationContextDouble_empty(handle));
  ListPairInterpretationContextDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextDoubleTest, EraseAtClear) {
  auto handle = ListPairInterpretationContextDouble_fill_value(2, sh1);
  ListPairInterpretationContextDouble_erase_at(handle, 0);
  EXPECT_EQ(ListPairInterpretationContextDouble_size(handle), 1);
  ListPairInterpretationContextDouble_clear(handle);
  EXPECT_TRUE(ListPairInterpretationContextDouble_empty(handle));
  ListPairInterpretationContextDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextDoubleTest, PushBackContainsIndex) {
  auto handle = ListPairInterpretationContextDouble_create_empty();
  ListPairInterpretationContextDouble_push_back(handle, sh1);
  EXPECT_TRUE(ListPairInterpretationContextDouble_contains(handle, sh1));
  EXPECT_EQ(ListPairInterpretationContextDouble_index(handle, sh1), 0);
  ListPairInterpretationContextDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextDoubleTest, ItemsAt) {
  PairInterpretationContextDoubleHandle arr[2] = {sh1, sh2};
  auto handle = ListPairInterpretationContextDouble_create(arr, 2);
  PairInterpretationContextDoubleHandle out[2];
  EXPECT_EQ(ListPairInterpretationContextDouble_items(handle, out, 2), 2);
  ListPairInterpretationContextDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextDoubleTest, EqualNotEqualIntersection) {
  PairInterpretationContextDoubleHandle arr[2] = {sh1, sh2};
  auto h1 = ListPairInterpretationContextDouble_create(arr, 2);
  auto h2 = ListPairInterpretationContextDouble_create(arr, 2);
  EXPECT_TRUE(ListPairInterpretationContextDouble_equal(h1, h2));
  EXPECT_FALSE(ListPairInterpretationContextDouble_not_equal(h1, h2));
  auto h3 = ListPairInterpretationContextDouble_intersection(h1, h2);
  EXPECT_EQ(ListPairInterpretationContextDouble_size(h3), 2);
  ListPairInterpretationContextDouble_destroy(h1);
  ListPairInterpretationContextDouble_destroy(h2);
  ListPairInterpretationContextDouble_destroy(h3);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextDoubleTest, ToJsonFromJson) {
  PairInterpretationContextDoubleHandle arr[1] = {sh1};
  auto handle  = ListPairInterpretationContextDouble_create(arr, 1);
  auto json    = ListPairInterpretationContextDouble_to_json_string(handle);
  auto handle2 = ListPairInterpretationContextDouble_from_json_string(json);
  EXPECT_TRUE(ListPairInterpretationContextDouble_equal(handle, handle2));
  ListPairInterpretationContextDouble_destroy(handle);
  ListPairInterpretationContextDouble_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextDoubleTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextDoubleTest, PushBackNull) {
  auto handle = ListPairInterpretationContextDouble_create_empty();
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairInterpretationContextDouble_destroy(handle);
}

TEST_F(ListPairInterpretationContextDoubleTest, ContainsNull) {
  auto handle = ListPairInterpretationContextDouble_create_empty();
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairInterpretationContextDouble_destroy(handle);
}

TEST_F(ListPairInterpretationContextDoubleTest, IndexNull) {
  auto handle = ListPairInterpretationContextDouble_create_empty();
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairInterpretationContextDouble_destroy(handle);
}

TEST_F(ListPairInterpretationContextDoubleTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextDoubleTest, At) {
  PairInterpretationContextDoubleHandle arr[2] = {sh1, sh2};
  auto handle = ListPairInterpretationContextDouble_create(arr, 2);
  auto at0    = ListPairInterpretationContextDouble_at(handle, 0);
  auto at1    = ListPairInterpretationContextDouble_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairInterpretationContextDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextDouble_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
