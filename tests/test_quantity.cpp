#include <gtest/gtest.h>

#include "falcon_core/math/Quantity.hpp"
#include "falcon_core/physics/units/Units.hpp"
namespace tests {
using namespace falcon_core::math;
using namespace falcon_core::physics::units;

TEST(QuantityTest, Construction) {
  auto q1 = std::make_shared<Quantity>(
      10.0, std::make_shared<SymbolUnit>(Units::Meter));
  EXPECT_DOUBLE_EQ(q1->value(), 10.0);
  EXPECT_EQ(q1->unit()->symbol(), "m");
}

TEST(QuantityTest, Addition) {
  auto q1 = std::make_shared<Quantity>(
      10.0, std::make_shared<SymbolUnit>(Units::Meter));
  auto q2 = std::make_shared<Quantity>(
      5.0, std::make_shared<SymbolUnit>(Units::Meter));
  auto q_cm = std::make_shared<Quantity>(50.0, Units::Meter.with_prefix("c"));

  auto sum1 = *q1 + q2;
  EXPECT_DOUBLE_EQ(sum1->value(), 15.0);
  EXPECT_EQ(sum1->unit()->symbol(), "m");

  auto sum2 = *q1 + q_cm;
  EXPECT_NEAR(sum2->value(), 10.5, 1e-9);
  EXPECT_EQ(sum2->unit()->symbol(), "m");
}

TEST(QuantityTest, Subtraction) {
  auto q1 = std::make_shared<Quantity>(
      10.0, std::make_shared<SymbolUnit>(Units::Meter));
  auto q2 = std::make_shared<Quantity>(
      5.0, std::make_shared<SymbolUnit>(Units::Meter));

  auto diff = *q1 - q2;
  EXPECT_DOUBLE_EQ(diff->value(), 5.0);
}

TEST(QuantityTest, Multiplication) {
  auto q1 = std::make_shared<Quantity>(
      10.0, std::make_shared<SymbolUnit>(Units::Meter));
  auto q2 = std::make_shared<Quantity>(
      5.0, std::make_shared<SymbolUnit>(Units::Second));

  auto product = *q1 * q2;
  EXPECT_DOUBLE_EQ(product->value(), 50.0);
  // Note: symbol generation for composite units might vary.
  // This test assumes a specific format like "m·s"
  EXPECT_EQ(product->unit()->symbol(), "m·s");
}

TEST(QuantityTest, Division) {
  auto q1 = std::make_shared<Quantity>(
      10.0, std::make_shared<SymbolUnit>(Units::Meter));
  auto q2 = std::make_shared<Quantity>(
      2.0, std::make_shared<SymbolUnit>(Units::Second));

  auto quotient = *q1 / q2;
  EXPECT_DOUBLE_EQ(quotient->value(), 5.0);
  EXPECT_EQ(quotient->unit()->symbol(), "m/s");
}

TEST(QuantityTest, Power) {
  auto q1 = std::make_shared<Quantity>(
      3.0, std::make_shared<SymbolUnit>(Units::Meter));

  auto squared = *q1 ^ 2;
  EXPECT_DOUBLE_EQ(squared->value(), 9.0);
  EXPECT_EQ(squared->unit()->symbol(), "m^2");
}

#include <cereal/archives/json.hpp>
#include <cereal/types/memory.hpp>

TEST(QuantityTest, SerializationRoundTrip) {
  // Create a Quantity of 42 meters
  auto q = std::make_shared<Quantity>(
      42.0, std::make_shared<SymbolUnit>(Units::Meter));

  // Serialize to JSON using the class helper
  std::string json = q->to_json_string();
  std::cout << "Serialized JSON:\n" << json << std::endl;

  // Deserialize from JSON using the class helper
  auto q2 = Quantity::from_json_string<Quantity>(json);

  ASSERT_TRUE(q2->unit() != nullptr) << "Deserialized unit is null!";
  ASSERT_DOUBLE_EQ(q->value(), q2->value());
  ASSERT_EQ(q->unit()->symbol(), q2->unit()->symbol());
}
}  // namespace tests
