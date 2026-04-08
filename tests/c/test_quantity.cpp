#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/math/Quantity_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class QuantityTest : public ::testing::Test {
 protected:
  void SetUp() override {
    unit           = SymbolUnit_create_meter();
    quantity       = Quantity_create(42.0, unit);
    other_quantity = Quantity_create(2.0, unit);
  }
  void TearDown() override {
    Quantity_destroy(quantity);
    Quantity_destroy(other_quantity);
    SymbolUnit_destroy(unit);
  }
  SymbolUnitHandle unit           = nullptr;
  QuantityHandle   quantity       = nullptr;
  QuantityHandle   other_quantity = nullptr;
};

TEST_F(QuantityTest, CreateDestroy) {
  auto q = Quantity_create(1.0, unit);
  Quantity_destroy(q);
  set_last_error(0, nullptr);
  Quantity_create(1.0, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(QuantityTest, ValueUnit) {
  EXPECT_DOUBLE_EQ(Quantity_value(quantity), 42.0);
  auto u = Quantity_unit(quantity);
  EXPECT_NE(u, nullptr);
  SymbolUnit_destroy(u);
  set_last_error(0, nullptr);
  Quantity_value(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_unit(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(QuantityTest, ConvertTo) {
  auto new_unit = SymbolUnit_create_millimeter();
  Quantity_convert_to(quantity, new_unit);
  SymbolUnit_destroy(new_unit);
  set_last_error(0, nullptr);
  Quantity_convert_to(nullptr, unit);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_convert_to(quantity, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(QuantityTest, MultiplyDivideAddSubtractIntDouble) {
  auto q1 = Quantity_multiply_int(quantity, 2);
  auto q2 = Quantity_multiply_double(quantity, 2.0);
  auto q3 = Quantity_divide_int(quantity, 2);
  auto q4 = Quantity_divide_double(quantity, 2.0);

  Quantity_destroy(q1);
  Quantity_destroy(q2);
  Quantity_destroy(q3);
  Quantity_destroy(q4);

  set_last_error(0, nullptr);
  Quantity_multiply_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_multiply_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_divide_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_divide_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(QuantityTest, MultiplyDivideAddSubtractQuantity) {
  auto q1 = Quantity_multiply_quantity(quantity, other_quantity);
  auto q2 = Quantity_divide_quantity(quantity, other_quantity);
  auto q3 = Quantity_add_quantity(quantity, other_quantity);
  auto q4 = Quantity_subtract_quantity(quantity, other_quantity);

  Quantity_destroy(q1);
  Quantity_destroy(q2);
  Quantity_destroy(q3);
  Quantity_destroy(q4);

  set_last_error(0, nullptr);
  Quantity_multiply_quantity(nullptr, other_quantity);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_multiply_quantity(quantity, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_divide_quantity(nullptr, other_quantity);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_divide_quantity(quantity, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_add_quantity(nullptr, other_quantity);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_add_quantity(quantity, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_subtract_quantity(nullptr, other_quantity);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_subtract_quantity(quantity, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(QuantityTest, MultiplyDivideAddSubtractEquals) {
  EXPECT_EQ(Quantity_multiply_equals_int(quantity, 2), quantity);
  EXPECT_EQ(Quantity_multiply_equals_double(quantity, 2.0), quantity);
  EXPECT_EQ(Quantity_multiply_equals_quantity(quantity, other_quantity),
            quantity);
  EXPECT_EQ(Quantity_divide_equals_int(quantity, 2), quantity);
  EXPECT_EQ(Quantity_divide_equals_double(quantity, 2.0), quantity);
  EXPECT_EQ(Quantity_divide_equals_quantity(quantity, other_quantity),
            quantity);
  EXPECT_EQ(Quantity_add_equals_quantity(quantity, other_quantity), quantity);
  EXPECT_EQ(Quantity_subtract_equals_quantity(quantity, other_quantity),
            quantity);

  set_last_error(0, nullptr);
  Quantity_multiply_equals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_multiply_equals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_multiply_equals_quantity(nullptr, other_quantity);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_multiply_equals_quantity(quantity, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_divide_equals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_divide_equals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_divide_equals_quantity(nullptr, other_quantity);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_divide_equals_quantity(quantity, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_add_equals_quantity(nullptr, other_quantity);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_add_equals_quantity(quantity, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_subtract_equals_quantity(nullptr, other_quantity);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_subtract_equals_quantity(quantity, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(QuantityTest, PowerNegateAbs) {
  auto q1 = Quantity_power(quantity, 2);
  auto q2 = Quantity_negate(quantity);
  auto q3 = Quantity_abs(quantity);

  Quantity_destroy(q1);
  Quantity_destroy(q2);
  Quantity_destroy(q3);

  set_last_error(0, nullptr);
  Quantity_power(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_negate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_abs(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(QuantityTest, EqualNotEqual) {
  EXPECT_TRUE(Quantity_equal(quantity, quantity));
  EXPECT_FALSE(Quantity_not_equal(quantity, quantity));
  set_last_error(0, nullptr);
  Quantity_equal(nullptr, quantity);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_equal(quantity, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_not_equal(nullptr, quantity);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_not_equal(quantity, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(QuantityTest, ToJsonFromJson) {
  auto json = Quantity_to_json_string(quantity);
  auto q2   = Quantity_from_json_string(json);
  EXPECT_TRUE(Quantity_equal(quantity, q2));
  Quantity_destroy(q2);
  String_destroy(json);
  set_last_error(0, nullptr);
  Quantity_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Quantity_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
