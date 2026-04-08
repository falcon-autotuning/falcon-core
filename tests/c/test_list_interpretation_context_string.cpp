#include <falcon-core/generic/ListPairInterpretationContextString_c_api.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class ListPairInterpretationContextStringTest : public ::testing::Test {
 protected:
  void destroy_string(PairInterpretationContextStringHandle sh) {
    PairInterpretationContextString_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairInterpretationContextStringHandle> created_strings;
  PairInterpretationContextStringHandle              track_quantity(
                   const PairInterpretationContextStringHandle& s) {
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
    sh1 = track_quantity(PairInterpretationContextString_create(
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp1),
                                     axes_dep1,
                                     SymbolUnit_create_volt()),
        String_wrap("whee")));
    sh2 = track_quantity(PairInterpretationContextString_create(
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp2),
                                     axes_dep2,
                                     SymbolUnit_create_volt()),
        String_wrap("Whoah")));
  }
  PairInterpretationContextStringHandle sh1;
  PairInterpretationContextStringHandle sh2;
};

TEST_F(ListPairInterpretationContextStringTest, CreateEmpty) {
  auto handle = ListPairInterpretationContextString_create_empty();
  EXPECT_TRUE(ListPairInterpretationContextString_empty(handle));
  EXPECT_EQ(ListPairInterpretationContextString_size(handle), 0);
  ListPairInterpretationContextString_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextStringTest, FillValue) {
  auto handle = ListPairInterpretationContextString_fill_value(3, sh1);
  EXPECT_EQ(ListPairInterpretationContextString_size(handle), 3);
  ListPairInterpretationContextString_destroy(handle);
}

TEST_F(ListPairInterpretationContextStringTest, CreateFromArray) {
  PairInterpretationContextStringHandle     arr[2] = {sh1, sh2};
  ListPairInterpretationContextStringHandle handle =
      ListPairInterpretationContextString_create(arr, 2);
  EXPECT_EQ(ListPairInterpretationContextString_size(handle), 2);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairInterpretationContextString_destroy(handle);
}

TEST_F(ListPairInterpretationContextStringTest, SizeEmptyInvalid) {
  auto handle = ListPairInterpretationContextString_create_empty();
  EXPECT_EQ(ListPairInterpretationContextString_size(handle), 0);
  ListPairInterpretationContextString_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextStringTest, EmptyInvalid) {
  auto handle = ListPairInterpretationContextString_create_empty();
  EXPECT_TRUE(ListPairInterpretationContextString_empty(handle));
  ListPairInterpretationContextString_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextStringTest, EraseAtClear) {
  auto handle = ListPairInterpretationContextString_fill_value(2, sh1);
  ListPairInterpretationContextString_erase_at(handle, 0);
  EXPECT_EQ(ListPairInterpretationContextString_size(handle), 1);
  ListPairInterpretationContextString_clear(handle);
  EXPECT_TRUE(ListPairInterpretationContextString_empty(handle));
  ListPairInterpretationContextString_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextStringTest, PushBackContainsIndex) {
  auto handle = ListPairInterpretationContextString_create_empty();
  ListPairInterpretationContextString_push_back(handle, sh1);
  EXPECT_TRUE(ListPairInterpretationContextString_contains(handle, sh1));
  EXPECT_EQ(ListPairInterpretationContextString_index(handle, sh1), 0);
  ListPairInterpretationContextString_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextStringTest, ItemsAt) {
  PairInterpretationContextStringHandle arr[2] = {sh1, sh2};
  auto handle = ListPairInterpretationContextString_create(arr, 2);
  PairInterpretationContextStringHandle out[2];
  EXPECT_EQ(ListPairInterpretationContextString_items(handle, out, 2), 2);
  ListPairInterpretationContextString_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextStringTest, EqualNotEqualIntersection) {
  PairInterpretationContextStringHandle arr[2] = {sh1, sh2};
  auto h1 = ListPairInterpretationContextString_create(arr, 2);
  auto h2 = ListPairInterpretationContextString_create(arr, 2);
  EXPECT_TRUE(ListPairInterpretationContextString_equal(h1, h2));
  EXPECT_FALSE(ListPairInterpretationContextString_not_equal(h1, h2));
  auto h3 = ListPairInterpretationContextString_intersection(h1, h2);
  EXPECT_EQ(ListPairInterpretationContextString_size(h3), 2);
  ListPairInterpretationContextString_destroy(h1);
  ListPairInterpretationContextString_destroy(h2);
  ListPairInterpretationContextString_destroy(h3);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextStringTest, ToJsonFromJson) {
  PairInterpretationContextStringHandle arr[1] = {sh1};
  auto handle  = ListPairInterpretationContextString_create(arr, 1);
  auto json    = ListPairInterpretationContextString_to_json_string(handle);
  auto handle2 = ListPairInterpretationContextString_from_json_string(json);
  EXPECT_TRUE(ListPairInterpretationContextString_equal(handle, handle2));
  ListPairInterpretationContextString_destroy(handle);
  ListPairInterpretationContextString_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextStringTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextStringTest, PushBackNull) {
  auto handle = ListPairInterpretationContextString_create_empty();
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairInterpretationContextString_destroy(handle);
}

TEST_F(ListPairInterpretationContextStringTest, ContainsNull) {
  auto handle = ListPairInterpretationContextString_create_empty();
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairInterpretationContextString_destroy(handle);
}

TEST_F(ListPairInterpretationContextStringTest, IndexNull) {
  auto handle = ListPairInterpretationContextString_create_empty();
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairInterpretationContextString_destroy(handle);
}

TEST_F(ListPairInterpretationContextStringTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextStringTest, At) {
  PairInterpretationContextStringHandle arr[2] = {sh1, sh2};
  auto handle = ListPairInterpretationContextString_create(arr, 2);
  auto at0    = ListPairInterpretationContextString_at(handle, 0);
  auto at1    = ListPairInterpretationContextString_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairInterpretationContextString_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextString_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
