#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/generic/PairInterpretationContextQuantity_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class PairInterpretationContextQuantityTest : public ::testing::Test {
 protected:
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
    t1 = InterpretationContext_create(AxesMeasurementContext_create(axes_indp1),
                                      axes_dep1,
                                      SymbolUnit_create_volt());
    t2 = Quantity_create(1.0, SymbolUnit_create_volt());
    pair1 = PairInterpretationContextQuantity_create(t1, t2);
    pair2 = PairInterpretationContextQuantity_create(t1, t2);
  }
  void TearDown() override {
    PairInterpretationContextQuantity_destroy(pair1);
    PairInterpretationContextQuantity_destroy(pair2);
    InterpretationContext_destroy(t1);
    Quantity_destroy(t2);
  }
  PairInterpretationContextQuantityHandle pair1;
  PairInterpretationContextQuantityHandle pair2;
  InterpretationContextHandle             t1;
  QuantityHandle                          t2;
};

TEST_F(PairInterpretationContextQuantityTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairInterpretationContextQuantity_create(nullptr, t2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextQuantity_create(t1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextQuantity_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInterpretationContextQuantityTest, Accessors) {
  auto f = PairInterpretationContextQuantity_first(pair1);
  auto s = PairInterpretationContextQuantity_second(pair1);
  EXPECT_TRUE(InterpretationContext_equal(f, t1));
  EXPECT_TRUE(Quantity_equal(s, t2));
  set_last_error(0, nullptr);
  PairInterpretationContextQuantity_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextQuantity_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInterpretationContextQuantityTest, Equality) {
  EXPECT_TRUE(PairInterpretationContextQuantity_equal(pair1, pair2));
  EXPECT_FALSE(PairInterpretationContextQuantity_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairInterpretationContextQuantity_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextQuantity_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextQuantity_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextQuantity_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInterpretationContextQuantityTest, ToJsonFromJson) {
  auto json = PairInterpretationContextQuantity_to_json_string(pair1);
  auto p2   = PairInterpretationContextQuantity_from_json_string(json);
  EXPECT_TRUE(PairInterpretationContextQuantity_equal(pair1, p2));
  PairInterpretationContextQuantity_destroy(p2);
  set_last_error(0, nullptr);
  PairInterpretationContextQuantity_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextQuantity_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
