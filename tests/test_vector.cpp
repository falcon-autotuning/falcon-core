#include <gtest/gtest.h>

#include <cereal/archives/json.hpp>
#include <memory>
#include <sstream>

#include "falcon_core/generic/Map.hpp"
#include "falcon_core/math/Vector.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
#include "falcon_core/physics/units/Units.hpp"

namespace tests {
using namespace falcon_core::math;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::physics::units;
using namespace falcon_core::generic;

TEST(VectorTest, SerializationRoundTrip) {
  auto unit  = std::make_shared<SymbolUnit>(Units::Volt);
  auto conn1 = std::make_shared<BaseConnection>("A");
  auto conn2 = std::make_shared<BaseConnection>("B");

  Map<BaseConnection, double> end(
      std::vector<std::pair<std::shared_ptr<BaseConnection>, double>>{
          {conn1, 1.0}, {conn2, 2.0}});
  Map<BaseConnection, double> start(
      std::vector<std::pair<std::shared_ptr<BaseConnection>, double>>{
          {conn1, 0.0}, {conn2, 1.0}});

  auto vec = std::make_shared<Vector>(end, start, unit);

  std::stringstream ss;
  {
    cereal::JSONOutputArchive oarchive(ss);
    oarchive(vec);
  }

  std::shared_ptr<Vector> vec2;
  {
    cereal::JSONInputArchive iarchive(ss);
    iarchive(vec2);
  }

  ASSERT_EQ((*vec2->end())[conn1], 1.0);
  ASSERT_EQ((*vec2->end())[conn2], 2.0);
  ASSERT_EQ((*vec2->start())[conn1], 0.0);
  ASSERT_EQ((*vec2->start())[conn2], 1.0);
  // ASSERT_EQ(vec2->unit(), unit);  // pointer equality
}

TEST(VectorTest, ArithmeticOperators) {
  auto unit  = std::make_shared<SymbolUnit>(Units::Volt);
  auto conn1 = std::make_shared<BaseConnection>("A");
  auto conn2 = std::make_shared<BaseConnection>("B");

  Map<BaseConnection, double> end1(
      std::vector<std::pair<std::shared_ptr<BaseConnection>, double>>{
          {conn1, 1.0}, {conn2, 2.0}});
  Map<BaseConnection, double> start1(
      std::vector<std::pair<std::shared_ptr<BaseConnection>, double>>{
          {conn1, 0.0}, {conn2, 1.0}});
  Map<BaseConnection, double> end2(
      std::vector<std::pair<std::shared_ptr<BaseConnection>, double>>{
          {conn1, 3.0}, {conn2, 4.0}});
  Map<BaseConnection, double> start2(
      std::vector<std::pair<std::shared_ptr<BaseConnection>, double>>{
          {conn1, 1.0}, {conn2, 2.0}});

  auto v1 = std::make_shared<Vector>(end1, start1, unit);
  auto v2 = std::make_shared<Vector>(end2, start2, unit);

  auto v_add = *v1 + *v2;
  EXPECT_DOUBLE_EQ((*v_add->end())[conn1], 4.0);
  EXPECT_DOUBLE_EQ((*v_add->end())[conn2], 6.0);
  EXPECT_DOUBLE_EQ((*v_add->start())[conn1], 1.0);
  EXPECT_DOUBLE_EQ((*v_add->start())[conn2], 3.0);

  auto v_sub = *v1 - *v2;
  EXPECT_DOUBLE_EQ((*v_sub->end())[conn1], -2.0);
  EXPECT_DOUBLE_EQ((*v_sub->end())[conn2], -2.0);
  EXPECT_DOUBLE_EQ((*v_sub->start())[conn1], -1.0);
  EXPECT_DOUBLE_EQ((*v_sub->start())[conn2], -1.0);

  auto v_mul = *v1 * 2.0;
  EXPECT_DOUBLE_EQ((*v_mul->end())[conn1], 2.0);
  EXPECT_DOUBLE_EQ((*v_mul->end())[conn2], 4.0);
  EXPECT_DOUBLE_EQ((*v_mul->start())[conn1], 0.0);
  EXPECT_DOUBLE_EQ((*v_mul->start())[conn2], 2.0);

  auto v_div = *v1 / 2.0;
  EXPECT_DOUBLE_EQ((*v_div->end())[conn1], 0.5);
  EXPECT_DOUBLE_EQ((*v_div->end())[conn2], 1.0);
  EXPECT_DOUBLE_EQ((*v_div->start())[conn1], 0.0);
  EXPECT_DOUBLE_EQ((*v_div->start())[conn2], 0.5);

  auto v_neg = -(*v1);
  EXPECT_DOUBLE_EQ((*v_neg->end())[conn1], -1.0);
  EXPECT_DOUBLE_EQ((*v_neg->end())[conn2], -2.0);
  EXPECT_DOUBLE_EQ((*v_neg->start())[conn1], -0.0);
  EXPECT_DOUBLE_EQ((*v_neg->start())[conn2], -1.0);
}

TEST(VectorTest, MagnitudeAndIndexing) {
  auto unit  = std::make_shared<SymbolUnit>(Units::Volt);
  auto conn1 = std::make_shared<BaseConnection>("A");
  auto conn2 = std::make_shared<BaseConnection>("B");

  Map<BaseConnection, double> end(
      std::vector<std::pair<std::shared_ptr<BaseConnection>, double>>{
          {conn1, 3.0}, {conn2, 4.0}});
  Map<BaseConnection, double> start(
      std::vector<std::pair<std::shared_ptr<BaseConnection>, double>>{
          {conn1, 0.0}, {conn2, 0.0}});

  auto vec = std::make_shared<Vector>(end, start, unit);

  EXPECT_DOUBLE_EQ(vec->magnitude(), 5.0);

  auto pair = (*vec)[conn1];
  EXPECT_DOUBLE_EQ(pair.first, 3.0);
  EXPECT_DOUBLE_EQ(pair.second, 0.0);

  pair = (*vec)[conn2];
  EXPECT_DOUBLE_EQ(pair.first, 4.0);
  EXPECT_DOUBLE_EQ(pair.second, 0.0);
}

TEST(VectorTest, UnitConversion) {
  auto unit1 = std::make_shared<SymbolUnit>(Units::Volt);
  auto unit2 = std::make_shared<SymbolUnit>(Units::Meter);
  auto conn1 = std::make_shared<BaseConnection>("A");

  Map<BaseConnection, double> end(
      std::vector<std::pair<std::shared_ptr<BaseConnection>, double>>{
          {conn1, 1.0}});
  Map<BaseConnection, double> start(
      std::vector<std::pair<std::shared_ptr<BaseConnection>, double>>{
          {conn1, 0.0}});

  auto vec = std::make_shared<Vector>(end, start, unit1);
  vec->convert_to(unit2);

  ASSERT_EQ(vec->unit(), unit2);
  ASSERT_EQ(vec->end()->unit(), unit2);
  ASSERT_EQ(vec->start()->unit(), unit2);
}
}  // namespace tests
