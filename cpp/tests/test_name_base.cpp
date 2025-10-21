#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon_core/autotuner_interfaces/names/NameBase.hpp"
namespace {
using namespace falcon_core::autotuner_interfaces::names;

TEST(NameBaseTest, ConstructFromString) {
  NameBase n("8", "");
  EXPECT_EQ(n.name(), "8");
}

TEST(NameBaseTest, ConstructFromInt) {
  NameBase n(42, "");
  EXPECT_EQ(n.num(), 42);
}

TEST(NameBaseTest, OperatorPlus) {
  NameBaseSP n1     = std::make_shared<NameBase>("3", "");
  NameBaseSP n2     = std::make_shared<NameBase>("4", "");
  auto       result = *n1 + n2;
  EXPECT_TRUE(result != nullptr);
  EXPECT_EQ(result->name(), std::string("7"));
}

TEST(NameBaseTest, OperatorMinus) {
  NameBaseSP n1     = std::make_shared<NameBase>("wow4", "wow");
  NameBaseSP n2     = std::make_shared<NameBase>("wow3", "wow");
  auto       result = *n1 - n2;
  EXPECT_TRUE(result != nullptr);
  EXPECT_EQ(result->name(), std::string("wow1"));
}

TEST(NameBaseTest, OperatorNullPlus) {
  NameBaseSP n1 = std::make_shared<NameBase>("scared3", "scared");
  EXPECT_THROW(*n1 + nullptr, std::invalid_argument);
}

TEST(NameBaseTest, OperatorNullMinus) {
  NameBaseSP n1 = std::make_shared<NameBase>("scared3", "scared");
  EXPECT_THROW(*n1 - nullptr, std::invalid_argument);
}

TEST(NameBaseTest, SerializationRoundTrip) {
  NameBase          orig("4", "");
  std::stringstream ss;
  auto              string = orig.to_json_string();
  auto              copy   = NameBase::from_json_string<NameBase>(string);
  EXPECT_EQ(orig.name(), copy->name());
}
}  // namespace
