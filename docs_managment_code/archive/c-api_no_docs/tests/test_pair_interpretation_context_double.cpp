#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/generic/PairInterpretationContextDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class PairInterpretationContextDoubleTest : public ::testing::Test {
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
    t2 = 1.0;
    pair1 = PairInterpretationContextDouble_create(t1, t2);
    pair2 = PairInterpretationContextDouble_create(t1, t2);
  }
  void TearDown() override {
    PairInterpretationContextDouble_destroy(pair1);
    PairInterpretationContextDouble_destroy(pair2);
    InterpretationContext_destroy(t1);
  }
  PairInterpretationContextDoubleHandle pair1;
  PairInterpretationContextDoubleHandle pair2;
  InterpretationContextHandle           t1;
  double                                t2;
};

TEST_F(PairInterpretationContextDoubleTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairInterpretationContextDouble_create(nullptr, t2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextDouble_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInterpretationContextDoubleTest, Accessors) {
  auto f = PairInterpretationContextDouble_first(pair1);
  auto s = PairInterpretationContextDouble_second(pair1);
  EXPECT_TRUE(InterpretationContext_equal(f, t1));
  EXPECT_TRUE(s == t2);
  set_last_error(0, nullptr);
  PairInterpretationContextDouble_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextDouble_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInterpretationContextDoubleTest, Equality) {
  EXPECT_TRUE(PairInterpretationContextDouble_equal(pair1, pair2));
  EXPECT_FALSE(PairInterpretationContextDouble_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairInterpretationContextDouble_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextDouble_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextDouble_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextDouble_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInterpretationContextDoubleTest, ToJsonFromJson) {
  auto json = PairInterpretationContextDouble_to_json_string(pair1);
  auto p2   = PairInterpretationContextDouble_from_json_string(json);
  EXPECT_TRUE(PairInterpretationContextDouble_equal(pair1, p2));
  PairInterpretationContextDouble_destroy(p2);
  set_last_error(0, nullptr);
  PairInterpretationContextDouble_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextDouble_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
