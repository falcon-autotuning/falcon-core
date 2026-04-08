#include <falcon-core/generic/ListInterpretationContext_c_api.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListInterpretationContextTest : public ::testing::Test {
 protected:
  void destroy_string(InterpretationContextHandle sh) {
    InterpretationContext_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<InterpretationContextHandle> created_strings;
  InterpretationContextHandle              track_quantity(
                   const InterpretationContextHandle& s) {
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
    sh1 = track_quantity(
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp1),
                                     axes_dep1,
                                     SymbolUnit_create_volt()));
    sh2 = track_quantity(
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp2),
                                     axes_dep2,
                                     SymbolUnit_create_volt()));
  }
  InterpretationContextHandle sh1;
  InterpretationContextHandle sh2;
};

TEST_F(ListInterpretationContextTest, CreateEmpty) {
  auto handle = ListInterpretationContext_create_empty();
  EXPECT_TRUE(ListInterpretationContext_empty(handle));
  EXPECT_EQ(ListInterpretationContext_size(handle), 0);
  ListInterpretationContext_destroy(handle);
  set_last_error(0, nullptr);
  ListInterpretationContext_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInterpretationContextTest, FillValue) {
  auto handle = ListInterpretationContext_fill_value(3, sh1);
  EXPECT_EQ(ListInterpretationContext_size(handle), 3);
  ListInterpretationContext_destroy(handle);
}

TEST_F(ListInterpretationContextTest, CreateFromArray) {
  InterpretationContextHandle     arr[2] = {sh1, sh2};
  ListInterpretationContextHandle handle =
      ListInterpretationContext_create(arr, 2);
  EXPECT_EQ(ListInterpretationContext_size(handle), 2);
  set_last_error(0, nullptr);
  ListInterpretationContext_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListInterpretationContext_destroy(handle);
}

TEST_F(ListInterpretationContextTest, SizeEmptyInvalid) {
  auto handle = ListInterpretationContext_create_empty();
  EXPECT_EQ(ListInterpretationContext_size(handle), 0);
  ListInterpretationContext_destroy(handle);
  set_last_error(0, nullptr);
  ListInterpretationContext_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInterpretationContextTest, EmptyInvalid) {
  auto handle = ListInterpretationContext_create_empty();
  EXPECT_TRUE(ListInterpretationContext_empty(handle));
  ListInterpretationContext_destroy(handle);
  set_last_error(0, nullptr);
  ListInterpretationContext_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInterpretationContextTest, EraseAtClear) {
  auto handle = ListInterpretationContext_fill_value(2, sh1);
  ListInterpretationContext_erase_at(handle, 0);
  EXPECT_EQ(ListInterpretationContext_size(handle), 1);
  ListInterpretationContext_clear(handle);
  EXPECT_TRUE(ListInterpretationContext_empty(handle));
  ListInterpretationContext_destroy(handle);
  set_last_error(0, nullptr);
  ListInterpretationContext_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInterpretationContext_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInterpretationContextTest, PushBackContainsIndex) {
  auto handle = ListInterpretationContext_create_empty();
  ListInterpretationContext_push_back(handle, sh1);
  EXPECT_TRUE(ListInterpretationContext_contains(handle, sh1));
  EXPECT_EQ(ListInterpretationContext_index(handle, sh1), 0);
  ListInterpretationContext_destroy(handle);
  set_last_error(0, nullptr);
  ListInterpretationContext_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInterpretationContext_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInterpretationContext_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInterpretationContextTest, ItemsAt) {
  InterpretationContextHandle arr[2] = {sh1, sh2};
  auto                        handle = ListInterpretationContext_create(arr, 2);
  InterpretationContextHandle out[2];
  EXPECT_EQ(ListInterpretationContext_items(handle, out, 2), 2);
  ListInterpretationContext_destroy(handle);
  set_last_error(0, nullptr);
  ListInterpretationContext_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInterpretationContext_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInterpretationContext_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInterpretationContextTest, EqualNotEqualIntersection) {
  InterpretationContextHandle arr[2] = {sh1, sh2};
  auto                        h1     = ListInterpretationContext_create(arr, 2);
  auto                        h2     = ListInterpretationContext_create(arr, 2);
  EXPECT_TRUE(ListInterpretationContext_equal(h1, h2));
  EXPECT_FALSE(ListInterpretationContext_not_equal(h1, h2));
  auto h3 = ListInterpretationContext_intersection(h1, h2);
  EXPECT_EQ(ListInterpretationContext_size(h3), 2);
  ListInterpretationContext_destroy(h1);
  ListInterpretationContext_destroy(h2);
  ListInterpretationContext_destroy(h3);
  set_last_error(0, nullptr);
  ListInterpretationContext_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInterpretationContext_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInterpretationContext_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInterpretationContext_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInterpretationContext_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInterpretationContext_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInterpretationContextTest, ToJsonFromJson) {
  InterpretationContextHandle arr[1] = {sh1};
  auto                        handle = ListInterpretationContext_create(arr, 1);
  auto json    = ListInterpretationContext_to_json_string(handle);
  auto handle2 = ListInterpretationContext_from_json_string(json);
  EXPECT_TRUE(ListInterpretationContext_equal(handle, handle2));
  ListInterpretationContext_destroy(handle);
  ListInterpretationContext_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListInterpretationContext_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInterpretationContext_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInterpretationContextTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListInterpretationContext_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInterpretationContextTest, PushBackNull) {
  auto handle = ListInterpretationContext_create_empty();
  set_last_error(0, nullptr);
  ListInterpretationContext_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListInterpretationContext_destroy(handle);
}

TEST_F(ListInterpretationContextTest, ContainsNull) {
  auto handle = ListInterpretationContext_create_empty();
  set_last_error(0, nullptr);
  ListInterpretationContext_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListInterpretationContext_destroy(handle);
}

TEST_F(ListInterpretationContextTest, IndexNull) {
  auto handle = ListInterpretationContext_create_empty();
  set_last_error(0, nullptr);
  ListInterpretationContext_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListInterpretationContext_destroy(handle);
}

TEST_F(ListInterpretationContextTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListInterpretationContext_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInterpretationContextTest, At) {
  InterpretationContextHandle arr[2] = {sh1, sh2};
  auto                        handle = ListInterpretationContext_create(arr, 2);
  auto                        at0    = ListInterpretationContext_at(handle, 0);
  auto                        at1    = ListInterpretationContext_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListInterpretationContext_destroy(handle);
  set_last_error(0, nullptr);
  ListInterpretationContext_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
