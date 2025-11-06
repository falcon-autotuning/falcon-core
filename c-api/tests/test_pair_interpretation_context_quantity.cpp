#include <gtest/gtest.h>

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
  EXPECT_THROW(PairInterpretationContextQuantity_create(nullptr, t2),
               std::invalid_argument);
  EXPECT_THROW(PairInterpretationContextQuantity_create(t1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(PairInterpretationContextQuantity_destroy(nullptr),
               std::invalid_argument);
}

TEST_F(PairInterpretationContextQuantityTest, Accessors) {
  auto f = PairInterpretationContextQuantity_first(pair1);
  auto s = PairInterpretationContextQuantity_second(pair1);
  EXPECT_TRUE(InterpretationContext_equal(f, t1));
  EXPECT_TRUE(Quantity_equal(s, t2));
  EXPECT_THROW(PairInterpretationContextQuantity_first(nullptr),
               std::invalid_argument);
  EXPECT_THROW(PairInterpretationContextQuantity_second(nullptr),
               std::invalid_argument);
}

TEST_F(PairInterpretationContextQuantityTest, Equality) {
  EXPECT_TRUE(PairInterpretationContextQuantity_equal(pair1, pair2));
  EXPECT_FALSE(PairInterpretationContextQuantity_not_equal(pair1, pair2));
  EXPECT_THROW(PairInterpretationContextQuantity_equal(nullptr, pair2),
               std::invalid_argument);
  EXPECT_THROW(PairInterpretationContextQuantity_equal(pair1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(PairInterpretationContextQuantity_not_equal(nullptr, pair2),
               std::invalid_argument);
  EXPECT_THROW(PairInterpretationContextQuantity_not_equal(pair1, nullptr),
               std::invalid_argument);
}

TEST_F(PairInterpretationContextQuantityTest, ToJsonFromJson) {
  auto json = PairInterpretationContextQuantity_to_json_string(pair1);
  auto p2   = PairInterpretationContextQuantity_from_json_string(json);
  EXPECT_TRUE(PairInterpretationContextQuantity_equal(pair1, p2));
  PairInterpretationContextQuantity_destroy(p2);
  EXPECT_THROW(PairInterpretationContextQuantity_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(PairInterpretationContextQuantity_from_json_string(nullptr),
               std::invalid_argument);
}
