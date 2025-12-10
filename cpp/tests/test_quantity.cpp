#include <gtest/gtest.h>

#include <cereal/archives/json.hpp>
#include <cereal/types/memory.hpp>

#include "falcon_core/math/Quantity.hpp"

namespace {
using namespace falcon_core::math;
using namespace falcon_core::physics::units;

class QuantityTest : public ::testing::Test {
 protected:
  SymbolUnitSP meter     = SymbolUnit::Meter();
  SymbolUnitSP second    = SymbolUnit::Second();
  SymbolUnitSP volt      = SymbolUnit::Volt();
  SymbolUnitSP null_unit = nullptr;
  QuantitySP   q10m = std::make_shared<Quantity>(10.0, SymbolUnit::Meter());
  QuantitySP   q5m  = std::make_shared<Quantity>(5.0, SymbolUnit::Meter());
  QuantitySP   q50cm =
      std::make_shared<Quantity>(50.0, SymbolUnit::Meter()->with_prefix("c"));
  QuantitySP q2s = std::make_shared<Quantity>(2.0, SymbolUnit::Second());
  QuantitySP q5s = std::make_shared<Quantity>(5.0, SymbolUnit::Second());
};

TEST_F(QuantityTest, Construction) {
  auto q = std::make_shared<Quantity>(10.0, meter);
  EXPECT_DOUBLE_EQ(q->value(), 10.0);
  EXPECT_EQ(q->unit()->symbol(), "m");
}

TEST_F(QuantityTest, ConstructionNullUnitThrows) {
  EXPECT_THROW({ Quantity q(1.0, nullptr); }, std::invalid_argument);
}

TEST_F(QuantityTest, Addition) {
  auto sum1 = *q10m + q5m;
  EXPECT_DOUBLE_EQ(sum1->value(), 15.0);
  EXPECT_EQ(sum1->unit()->symbol(), "m");
  auto sum2 = *q10m + q50cm;
  EXPECT_NEAR(sum2->value(), 10.5, 1e-9);
  EXPECT_EQ(sum2->unit()->symbol(), "m");
}

TEST_F(QuantityTest, AdditionNullptrThrows) {
  EXPECT_THROW({ *q10m + nullptr; }, std::invalid_argument);
}

TEST_F(QuantityTest, Subtraction) {
  auto diff = *q10m - q5m;
  EXPECT_DOUBLE_EQ(diff->value(), 5.0);
}

TEST_F(QuantityTest, SubtractionNullptrThrows) {
  EXPECT_THROW({ *q10m - nullptr; }, std::invalid_argument);
}

TEST_F(QuantityTest, Multiplication) {
  auto product = *q10m * q5s;
  EXPECT_DOUBLE_EQ(product->value(), 50.0);
  EXPECT_EQ(product->unit()->symbol(), "m·s");
}

TEST_F(QuantityTest, MultiplicationNullptrThrows) {
  EXPECT_THROW({ *q10m* nullptr; }, std::invalid_argument);
}

TEST_F(QuantityTest, Division) {
  auto quotient = *q10m / q2s;
  EXPECT_DOUBLE_EQ(quotient->value(), 5.0);
  EXPECT_EQ(quotient->unit()->symbol(), "m/s");
}

TEST_F(QuantityTest, DivisionNullptrThrows) {
  EXPECT_THROW({ *q10m / nullptr; }, std::invalid_argument);
}

TEST_F(QuantityTest, Power) {
  auto squared = *q10m ^ 2;
  EXPECT_DOUBLE_EQ(squared->value(), 100.0);
  EXPECT_EQ(squared->unit()->symbol(), "m^2");
}

TEST_F(QuantityTest, NegationAndAbs) {
  auto neg = -(*q10m);
  EXPECT_DOUBLE_EQ(neg->value(), -10.0);
  auto absq = neg->abs();
  EXPECT_DOUBLE_EQ(absq->value(), 10.0);
}

// TEST_F(QuantityTest, CompoundAssignmentOperators) {
//   Quantity q(10.0, meter);
//   q += 5;
//   EXPECT_DOUBLE_EQ(q.value(), 15.0);
//   q -= 2.0;
//   EXPECT_DOUBLE_EQ(q.value(), 13.0);
//   q *= 2;
//   EXPECT_DOUBLE_EQ(q.value(), 26.0);
//   q /= 2.0;
//   EXPECT_DOUBLE_EQ(q.value(), 13.0);
// }

TEST_F(QuantityTest, CompoundAssignmentNullptrThrows) {
  Quantity q(10.0, meter);
  EXPECT_THROW(q += nullptr, std::invalid_argument);
  EXPECT_THROW(q -= nullptr, std::invalid_argument);
  EXPECT_THROW(q *= nullptr, std::invalid_argument);
  EXPECT_THROW(q /= nullptr, std::invalid_argument);
}

TEST_F(QuantityTest, ConvertToNullptrThrows) {
  Quantity q(10.0, meter);
  EXPECT_THROW(q.convert_to(nullptr), std::invalid_argument);
}

TEST_F(QuantityTest, EqualityOperators) {
  Quantity q1(10.0, meter);
  Quantity q2(10.0, meter);
  Quantity q3(5.0, meter);
  EXPECT_TRUE(q1 == q2);
  EXPECT_FALSE(q1 != q2);
  EXPECT_FALSE(q1 == q3);
  EXPECT_TRUE(q1 != q3);
}

TEST_F(QuantityTest, SerializationRoundTrip) {
  auto        q    = std::make_shared<Quantity>(42.0, meter);
  std::string json = q->to_json_string();
  auto        q2   = Quantity::from_json_string<Quantity>(json);
  ASSERT_TRUE(q2->unit() != nullptr);
  ASSERT_EQ(*q, *q2);
}

TEST_F(QuantityTest, ConvertToChangesUnitAndValue) {
  // 1 meter = 100 centimeters
  Quantity     q(1.0, SymbolUnit::Meter());
  SymbolUnitSP cm = SymbolUnit::Meter()->with_prefix("c");
  q.convert_to(cm);
  EXPECT_NEAR(q.value(), 100.0, 1e-9);
  EXPECT_EQ(q.unit()->symbol(), "cm");
}

TEST_F(QuantityTest, MultiplyByInt) {
  Quantity q(3.0, meter);
  auto     result = q * 4;
  EXPECT_DOUBLE_EQ(result->value(), 12.0);
  EXPECT_EQ(result->unit()->symbol(), "m");
}

TEST_F(QuantityTest, MultiplyByDouble) {
  Quantity q(2.5, meter);
  auto     result = q * 2.0;
  EXPECT_DOUBLE_EQ(result->value(), 5.0);
  EXPECT_EQ(result->unit()->symbol(), "m");
}

TEST_F(QuantityTest, MultiplyAssignByDouble) {
  Quantity q(3.0, meter);
  q *= 2.0;
  EXPECT_DOUBLE_EQ(q.value(), 6.0);
  EXPECT_EQ(q.unit()->symbol(), "m");
}

TEST_F(QuantityTest, MultiplyAssignByQuantity) {
  Quantity   q(3.0, meter);
  QuantitySP q2 = std::make_shared<Quantity>(2.0, meter);
  q *= q2;
  EXPECT_DOUBLE_EQ(q.value(), 6.0);
  EXPECT_EQ(q.unit()->symbol(), "m");
}

TEST_F(QuantityTest, MultiplyAssignByQuantityNullptrThrows) {
  Quantity q(3.0, meter);
  EXPECT_THROW(q *= nullptr, std::invalid_argument);
}

TEST_F(QuantityTest, DivideByInt) {
  Quantity q(10.0, meter);
  auto     result = q / 2;
  EXPECT_DOUBLE_EQ(result->value(), 5.0);
  EXPECT_EQ(result->unit()->symbol(), "m");
}

TEST_F(QuantityTest, DivideByDouble) {
  Quantity q(10.0, meter);
  auto     result = q / 2.5;
  EXPECT_DOUBLE_EQ(result->value(), 4.0);
  EXPECT_EQ(result->unit()->symbol(), "m");
}

TEST_F(QuantityTest, DivideAssignByInt) {
  Quantity q(10.0, meter);
  q /= 2;
  EXPECT_DOUBLE_EQ(q.value(), 5.0);
  EXPECT_EQ(q.unit()->symbol(), "m");
}

TEST_F(QuantityTest, DivideAssignByQuantity) {
  Quantity   q(10.0, meter);
  QuantitySP q2 = std::make_shared<Quantity>(2.0, meter);
  q /= q2;
  EXPECT_DOUBLE_EQ(q.value(), 5.0);
  EXPECT_EQ(q.unit()->symbol(), "m");
}

TEST_F(QuantityTest, DivideAssignByQuantityNullptrThrows) {
  Quantity q(10.0, meter);
  EXPECT_THROW(q /= nullptr, std::invalid_argument);
}

TEST_F(QuantityTest, AddIntThrows) {
  Quantity q(10.0, meter);
  EXPECT_THROW(q + 2, std::runtime_error);
}

TEST_F(QuantityTest, AddDoubleThrows) {
  Quantity q(10.0, meter);
  EXPECT_THROW(q + 2.0, std::runtime_error);
}

// TEST_F(QuantityTest, AddAssignByDouble) {
//   Quantity q(10.0, meter);
//   q += 2.5;
//   EXPECT_DOUBLE_EQ(q.value(), 12.5);
//   EXPECT_EQ(q.unit()->symbol(), "m");
// }
//
TEST_F(QuantityTest, AddAssignByQuantity) {
  Quantity   q(10.0, meter);
  QuantitySP q2 = std::make_shared<Quantity>(2.0, meter);
  q += q2;
  EXPECT_DOUBLE_EQ(q.value(), 12.0);
  EXPECT_EQ(q.unit()->symbol(), "m");
}

TEST_F(QuantityTest, AddAssignByQuantityNullptrThrows) {
  Quantity q(10.0, meter);
  EXPECT_THROW(q += nullptr, std::invalid_argument);
}

TEST_F(QuantityTest, AdditionIncompatibleUnitsThrows) {
  QuantitySP q_meter  = std::make_shared<Quantity>(1.0, SymbolUnit::Meter());
  QuantitySP q_second = std::make_shared<Quantity>(2.0, SymbolUnit::Second());
  EXPECT_THROW(*q_meter + q_second, std::runtime_error);
}

TEST_F(QuantityTest, SubtractionIncompatibleUnitsThrows) {
  QuantitySP q_meter  = std::make_shared<Quantity>(1.0, SymbolUnit::Meter());
  QuantitySP q_second = std::make_shared<Quantity>(2.0, SymbolUnit::Second());
  EXPECT_THROW(*q_meter - q_second, std::runtime_error);
}

TEST_F(QuantityTest, SubtractIntThrows) {
  Quantity q(10.0, meter);
  EXPECT_THROW(q - 2, std::runtime_error);
}

TEST_F(QuantityTest, SubtractDoubleThrows) {
  Quantity q(10.0, meter);
  EXPECT_THROW(q - 2.0, std::runtime_error);
}

// TEST_F(QuantityTest, SubtractAssignByInt) {
//   Quantity q(10.0, meter);
//   q -= 3;
//   EXPECT_DOUBLE_EQ(q.value(), 7.0);
//   EXPECT_EQ(q.unit()->symbol(), "m");
// }
}  // namespace
