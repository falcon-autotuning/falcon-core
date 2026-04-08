#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/generic/PairInterpretationContextString_c_api.h"
#include "falcon-core/generic/String_c_api.h"

class PairInterpretationContextStringTest : public ::testing::Test {
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
    t2 = String_wrap("Test String");
    pair1 = PairInterpretationContextString_create(t1, t2);
    pair2 = PairInterpretationContextString_create(t1, t2);
  }
  void TearDown() override {
    PairInterpretationContextString_destroy(pair1);
    PairInterpretationContextString_destroy(pair2);
    InterpretationContext_destroy(t1);
  }
  PairInterpretationContextStringHandle pair1;
  PairInterpretationContextStringHandle pair2;
  InterpretationContextHandle           t1;
  StringHandle                          t2;
  bool String_equal(StringHandle a, StringHandle b) {
    if (a == nullptr || b == nullptr) {
      throw std::invalid_argument("Null StringHandle provided");
    }
    std::string str_a = std::string(a->raw, a->length);
    std::string str_b = std::string(b->raw, b->length);
    return std::string(str_a) == std::string(str_b);
  }
};

TEST_F(PairInterpretationContextStringTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairInterpretationContextString_create(nullptr, t2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextString_create(t1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextString_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInterpretationContextStringTest, Accessors) {
  auto f = PairInterpretationContextString_first(pair1);
  auto s = PairInterpretationContextString_second(pair1);
  EXPECT_TRUE(InterpretationContext_equal(f, t1));
  EXPECT_TRUE(String_equal(s, t2));
  set_last_error(0, nullptr);
  PairInterpretationContextString_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextString_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInterpretationContextStringTest, Equality) {
  EXPECT_TRUE(PairInterpretationContextString_equal(pair1, pair2));
  EXPECT_FALSE(PairInterpretationContextString_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairInterpretationContextString_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextString_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextString_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextString_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInterpretationContextStringTest, ToJsonFromJson) {
  auto json = PairInterpretationContextString_to_json_string(pair1);
  auto p2   = PairInterpretationContextString_from_json_string(json);
  EXPECT_TRUE(PairInterpretationContextString_equal(pair1, p2));
  PairInterpretationContextString_destroy(p2);
  set_last_error(0, nullptr);
  PairInterpretationContextString_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInterpretationContextString_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
