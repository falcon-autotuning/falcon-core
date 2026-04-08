#include <gtest/gtest.h>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/PairInstrumentPortPortTransform_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentTypes_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class PairInstrumentPortPortTransformTest : public ::testing::Test {
 protected:
  void SetUp() override {
    t1 = InstrumentPort_create_knob(
        String_wrap("A"),
        Connection_create_plunger_gate(String_wrap("gate1")),
        InstrumentTypes_voltmeter(),
        SymbolUnit_create_volt(),
        String_wrap(""));
    t2    = PortTransform_create(t1, AnalyticFunction_create_identity());
    pair1 = PairInstrumentPortPortTransform_create(t1, t2);
    pair2 = PairInstrumentPortPortTransform_create(t1, t2);
  }
  void TearDown() override {
    PairInstrumentPortPortTransform_destroy(pair1);
    PairInstrumentPortPortTransform_destroy(pair2);
    InstrumentPort_destroy(t1);
    PortTransform_destroy(t2);
  }
  PairInstrumentPortPortTransformHandle pair1;
  PairInstrumentPortPortTransformHandle pair2;
  InstrumentPortHandle                  t1;
  PortTransformHandle                   t2;
};

TEST_F(PairInstrumentPortPortTransformTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairInstrumentPortPortTransform_create(nullptr, t2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInstrumentPortPortTransform_create(t1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInstrumentPortPortTransform_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInstrumentPortPortTransformTest, Accessors) {
  auto f = PairInstrumentPortPortTransform_first(pair1);
  auto s = PairInstrumentPortPortTransform_second(pair1);
  EXPECT_TRUE(InstrumentPort_equal(f, t1));
  EXPECT_TRUE(PortTransform_equal(s, t2));
  set_last_error(0, nullptr);
  PairInstrumentPortPortTransform_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInstrumentPortPortTransform_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInstrumentPortPortTransformTest, Equality) {
  EXPECT_TRUE(PairInstrumentPortPortTransform_equal(pair1, pair2));
  EXPECT_FALSE(PairInstrumentPortPortTransform_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairInstrumentPortPortTransform_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInstrumentPortPortTransform_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInstrumentPortPortTransform_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInstrumentPortPortTransform_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInstrumentPortPortTransformTest, ToJsonFromJson) {
  auto json = PairInstrumentPortPortTransform_to_json_string(pair1);
  auto p2   = PairInstrumentPortPortTransform_from_json_string(json);
  EXPECT_TRUE(PairInstrumentPortPortTransform_equal(pair1, p2));
  PairInstrumentPortPortTransform_destroy(p2);
  set_last_error(0, nullptr);
  PairInstrumentPortPortTransform_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairInstrumentPortPortTransform_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
