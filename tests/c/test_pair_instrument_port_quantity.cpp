#include <gtest/gtest.h>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/PairInstrumentPortQuantity_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon-core/math/Quantity_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class PairInstrumentPortQuantityTest : public ::testing::Test {
protected:
  void SetUp() override {
    port = InstrumentPort_create_knob(
        String_wrap("A"), String_wrap("inst"),
        Connection_create_plunger_gate(String_wrap("gate1")),
        INSTRUMENT_VOLTMETER, SymbolUnit_create_volt(), String_wrap(""));

    quantity = Quantity_create(1.23, SymbolUnit_create_volt());

    pair1 = PairInstrumentPortQuantity_create(port, quantity);

    pair2 = PairInstrumentPortQuantity_create(port, quantity);
  }

  void TearDown() override {
    PairInstrumentPortQuantity_destroy(pair1);
    PairInstrumentPortQuantity_destroy(pair2);

    InstrumentPort_destroy(port);
    Quantity_destroy(quantity);
  }

  PairInstrumentPortQuantityHandle pair1;
  PairInstrumentPortQuantityHandle pair2;

  InstrumentPortHandle port;
  QuantityHandle quantity;
};

TEST_F(PairInstrumentPortQuantityTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairInstrumentPortQuantity_create(nullptr, quantity);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  PairInstrumentPortQuantity_create(port, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  PairInstrumentPortQuantity_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInstrumentPortQuantityTest, Accessors) {
  auto first = PairInstrumentPortQuantity_first(pair1);

  auto second = PairInstrumentPortQuantity_second(pair1);

  EXPECT_TRUE(InstrumentPort_equal(first, port));

  EXPECT_TRUE(Quantity_equal(second, quantity));

  InstrumentPort_destroy(first);
  Quantity_destroy(second);

  set_last_error(0, nullptr);
  PairInstrumentPortQuantity_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  PairInstrumentPortQuantity_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInstrumentPortQuantityTest, Equality) {
  EXPECT_TRUE(PairInstrumentPortQuantity_equal(pair1, pair2));

  EXPECT_FALSE(PairInstrumentPortQuantity_not_equal(pair1, pair2));

  set_last_error(0, nullptr);
  PairInstrumentPortQuantity_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  PairInstrumentPortQuantity_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  PairInstrumentPortQuantity_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  PairInstrumentPortQuantity_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInstrumentPortQuantityTest, Copy) {
  auto copy = PairInstrumentPortQuantity_copy(pair1);

  EXPECT_TRUE(PairInstrumentPortQuantity_equal(pair1, copy));

  PairInstrumentPortQuantity_destroy(copy);

  set_last_error(0, nullptr);
  PairInstrumentPortQuantity_copy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairInstrumentPortQuantityTest, ToJsonFromJson) {
  auto json = PairInstrumentPortQuantity_to_json_string(pair1);

  auto copy = PairInstrumentPortQuantity_from_json_string(json);

  EXPECT_TRUE(PairInstrumentPortQuantity_equal(pair1, copy));

  PairInstrumentPortQuantity_destroy(copy);
  String_destroy(json);

  set_last_error(0, nullptr);
  PairInstrumentPortQuantity_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  PairInstrumentPortQuantity_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
