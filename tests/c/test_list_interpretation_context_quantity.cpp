#include <falcon-core/generic/ListPairInterpretationContextQuantity_c_api.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class ListPairInterpretationContextQuantityTest : public ::testing::Test {
 protected:
  void destroy_string(PairInterpretationContextQuantityHandle sh) {
    PairInterpretationContextQuantity_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairInterpretationContextQuantityHandle> created_strings;
  PairInterpretationContextQuantityHandle              track_quantity(
                   const PairInterpretationContextQuantityHandle& s) {
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
    sh1 = track_quantity(PairInterpretationContextQuantity_create(
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp1),
                                     axes_dep1,
                                     SymbolUnit_create_volt()),
        Quantity_create(5.0, SymbolUnit_create_ampere())));
    sh2 = track_quantity(PairInterpretationContextQuantity_create(
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp2),
                                     axes_dep2,
                                     SymbolUnit_create_volt()),
        Quantity_create(5.0, SymbolUnit_create_ampere())));
  }
  PairInterpretationContextQuantityHandle sh1;
  PairInterpretationContextQuantityHandle sh2;
};

TEST_F(ListPairInterpretationContextQuantityTest, CreateEmpty) {
  auto handle = ListPairInterpretationContextQuantity_create_empty();
  EXPECT_TRUE(ListPairInterpretationContextQuantity_empty(handle));
  EXPECT_EQ(ListPairInterpretationContextQuantity_size(handle), 0);
  ListPairInterpretationContextQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextQuantityTest, FillValue) {
  auto handle = ListPairInterpretationContextQuantity_fill_value(3, sh1);
  EXPECT_EQ(ListPairInterpretationContextQuantity_size(handle), 3);
  ListPairInterpretationContextQuantity_destroy(handle);
}

TEST_F(ListPairInterpretationContextQuantityTest, CreateFromArray) {
  PairInterpretationContextQuantityHandle     arr[2] = {sh1, sh2};
  ListPairInterpretationContextQuantityHandle handle =
      ListPairInterpretationContextQuantity_create(arr, 2);
  EXPECT_EQ(ListPairInterpretationContextQuantity_size(handle), 2);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairInterpretationContextQuantity_destroy(handle);
}

TEST_F(ListPairInterpretationContextQuantityTest, SizeEmptyInvalid) {
  auto handle = ListPairInterpretationContextQuantity_create_empty();
  EXPECT_EQ(ListPairInterpretationContextQuantity_size(handle), 0);
  ListPairInterpretationContextQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextQuantityTest, EmptyInvalid) {
  auto handle = ListPairInterpretationContextQuantity_create_empty();
  EXPECT_TRUE(ListPairInterpretationContextQuantity_empty(handle));
  ListPairInterpretationContextQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextQuantityTest, EraseAtClear) {
  auto handle = ListPairInterpretationContextQuantity_fill_value(2, sh1);
  ListPairInterpretationContextQuantity_erase_at(handle, 0);
  EXPECT_EQ(ListPairInterpretationContextQuantity_size(handle), 1);
  ListPairInterpretationContextQuantity_clear(handle);
  EXPECT_TRUE(ListPairInterpretationContextQuantity_empty(handle));
  ListPairInterpretationContextQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextQuantityTest, PushBackContainsIndex) {
  auto handle = ListPairInterpretationContextQuantity_create_empty();
  ListPairInterpretationContextQuantity_push_back(handle, sh1);
  EXPECT_TRUE(ListPairInterpretationContextQuantity_contains(handle, sh1));
  EXPECT_EQ(ListPairInterpretationContextQuantity_index(handle, sh1), 0);
  ListPairInterpretationContextQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextQuantityTest, ItemsAt) {
  PairInterpretationContextQuantityHandle arr[2] = {sh1, sh2};
  auto handle = ListPairInterpretationContextQuantity_create(arr, 2);
  PairInterpretationContextQuantityHandle out[2];
  EXPECT_EQ(ListPairInterpretationContextQuantity_items(handle, out, 2), 2);
  ListPairInterpretationContextQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextQuantityTest, EqualNotEqualIntersection) {
  PairInterpretationContextQuantityHandle arr[2] = {sh1, sh2};
  auto h1 = ListPairInterpretationContextQuantity_create(arr, 2);
  auto h2 = ListPairInterpretationContextQuantity_create(arr, 2);
  EXPECT_TRUE(ListPairInterpretationContextQuantity_equal(h1, h2));
  EXPECT_FALSE(ListPairInterpretationContextQuantity_not_equal(h1, h2));
  auto h3 = ListPairInterpretationContextQuantity_intersection(h1, h2);
  EXPECT_EQ(ListPairInterpretationContextQuantity_size(h3), 2);
  ListPairInterpretationContextQuantity_destroy(h1);
  ListPairInterpretationContextQuantity_destroy(h2);
  ListPairInterpretationContextQuantity_destroy(h3);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextQuantityTest, ToJsonFromJson) {
  PairInterpretationContextQuantityHandle arr[1] = {sh1};
  auto handle  = ListPairInterpretationContextQuantity_create(arr, 1);
  auto json    = ListPairInterpretationContextQuantity_to_json_string(handle);
  auto handle2 = ListPairInterpretationContextQuantity_from_json_string(json);
  EXPECT_TRUE(ListPairInterpretationContextQuantity_equal(handle, handle2));
  ListPairInterpretationContextQuantity_destroy(handle);
  ListPairInterpretationContextQuantity_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextQuantityTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextQuantityTest, PushBackNull) {
  auto handle = ListPairInterpretationContextQuantity_create_empty();
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairInterpretationContextQuantity_destroy(handle);
}

TEST_F(ListPairInterpretationContextQuantityTest, ContainsNull) {
  auto handle = ListPairInterpretationContextQuantity_create_empty();
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairInterpretationContextQuantity_destroy(handle);
}

TEST_F(ListPairInterpretationContextQuantityTest, IndexNull) {
  auto handle = ListPairInterpretationContextQuantity_create_empty();
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairInterpretationContextQuantity_destroy(handle);
}

TEST_F(ListPairInterpretationContextQuantityTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairInterpretationContextQuantityTest, At) {
  PairInterpretationContextQuantityHandle arr[2] = {sh1, sh2};
  auto handle = ListPairInterpretationContextQuantity_create(arr, 2);
  auto at0    = ListPairInterpretationContextQuantity_at(handle, 0);
  auto at1    = ListPairInterpretationContextQuantity_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairInterpretationContextQuantity_destroy(handle);
  set_last_error(0, nullptr);
  ListPairInterpretationContextQuantity_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
