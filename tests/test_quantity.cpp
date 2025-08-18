#include <gtest/gtest.h>

#include "falcon_core/math/Quantity.hpp"
#include "falcon_core/physics/units/Units.hpp"

using namespace falcon_core::math;
using namespace falcon_core::physics::units;

TEST(QuantityTest, Construction) {
  auto q1 =
      std::make_shared<Quantity>(10.0, std::make_shared<SymbolUnit>(Meter()));
  EXPECT_DOUBLE_EQ(q1->value(), 10.0);
  EXPECT_EQ(q1->unit()->symbol(), "m");
}

TEST(QuantityTest, Addition) {
  auto q1 =
      std::make_shared<Quantity>(10.0, std::make_shared<SymbolUnit>(Meter()));
  auto q2 =
      std::make_shared<Quantity>(5.0, std::make_shared<SymbolUnit>(Meter()));
  auto q_cm = std::make_shared<Quantity>(50.0, Meter().with_prefix("c"));

  auto sum1 = *q1 + q2;
  EXPECT_DOUBLE_EQ(sum1->value(), 15.0);
  EXPECT_EQ(sum1->unit()->symbol(), "m");

  auto sum2 = *q1 + q_cm;
  EXPECT_NEAR(sum2->value(), 10.5, 1e-9);
  EXPECT_EQ(sum2->unit()->symbol(), "m");
}

TEST(QuantityTest, Subtraction) {
  auto q1 =
      std::make_shared<Quantity>(10.0, std::make_shared<SymbolUnit>(Meter()));
  auto q2 =
      std::make_shared<Quantity>(5.0, std::make_shared<SymbolUnit>(Meter()));

  auto diff = *q1 - q2;
  EXPECT_DOUBLE_EQ(diff->value(), 5.0);
}

TEST(QuantityTest, Multiplication) {
  auto q1 =
      std::make_shared<Quantity>(10.0, std::make_shared<SymbolUnit>(Meter()));
  auto q2 =
      std::make_shared<Quantity>(5.0, std::make_shared<SymbolUnit>(Second()));

  auto product = *q1 * q2;
  EXPECT_DOUBLE_EQ(product->value(), 50.0);
  // Note: symbol generation for composite units might vary.
  // This test assumes a specific format like "m·s"
  EXPECT_EQ(product->unit()->symbol(), "m·s");
}

TEST(QuantityTest, Division) {
  auto q1 =
      std::make_shared<Quantity>(10.0, std::make_shared<SymbolUnit>(Meter()));
  auto q2 =
      std::make_shared<Quantity>(2.0, std::make_shared<SymbolUnit>(Second()));

  auto quotient = *q1 / q2;
  EXPECT_DOUBLE_EQ(quotient->value(), 5.0);
  EXPECT_EQ(quotient->unit()->symbol(), "m/s");
}

TEST(QuantityTest, Power) {
  auto q1 =
      std::make_shared<Quantity>(3.0, std::make_shared<SymbolUnit>(Meter()));

  auto squared = *q1 ^ 2;
  EXPECT_DOUBLE_EQ(squared->value(), 9.0);
  EXPECT_EQ(squared->unit()->symbol(), "m^2");
}
