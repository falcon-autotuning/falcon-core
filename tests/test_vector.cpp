#include <gtest/gtest.h>

#include <cereal/archives/json.hpp>
#include <memory>
#include <sstream>

#include "falcon_core/math/Vector.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

using namespace falcon_core::math;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::physics::units;

TEST(VectorTest, SerializationRoundTrip) {
  auto           unit = std::make_shared<SymbolUnit>(Units::Volt);
  BaseConnection conn1("A");
  BaseConnection conn2("B");

  std::map<BaseConnection, double> end{{conn1, 1.0}, {conn2, 2.0}};
  std::map<BaseConnection, double> start{{conn1, 0.0}, {conn2, 1.0}};

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

  ASSERT_EQ(vec2->end()->get(conn1), 1.0);
  ASSERT_EQ(vec2->end()->get(conn2), 2.0);
  ASSERT_EQ(vec2->start()->get(conn1), 0.0);
  ASSERT_EQ(vec2->start()->get(conn2), 1.0);
  ASSERT_EQ(vec2->unit(), unit);  // pointer equality
}

TEST(VectorTest, ArithmeticOperators) {
  auto           unit = std::make_shared<SymbolUnit>(Units::Volt);
  BaseConnection conn1("A");
  BaseConnection conn2("B");

  std::map<BaseConnection, double> end1{{conn1, 1.0}, {conn2, 2.0}};
  std::map<BaseConnection, double> start1{{conn1, 0.0}, {conn2, 1.0}};
  std::map<BaseConnection, double> end2{{conn1, 3.0}, {conn2, 4.0}};
  std::map<BaseConnection, double> start2{{conn1, 1.0}, {conn2, 2.0}};

  auto v1 = std::make_shared<Vector>(end1, start1, unit);
  auto v2 = std::make_shared<Vector>(end2, start2, unit);

  auto v_add = *v1 + *v2;
  EXPECT_DOUBLE_EQ(v_add->end()->get(conn1), 4.0);
  EXPECT_DOUBLE_EQ(v_add->end()->get(conn2), 6.0);
  EXPECT_DOUBLE_EQ(v_add->start()->get(conn1), 1.0);
  EXPECT_DOUBLE_EQ(v_add->start()->get(conn2), 3.0);

  auto v_sub = *v1 - *v2;
  EXPECT_DOUBLE_EQ(v_sub->end()->get(conn1), -2.0);
  EXPECT_DOUBLE_EQ(v_sub->end()->get(conn2), -2.0);
  EXPECT_DOUBLE_EQ(v_sub->start()->get(conn1), -1.0);
  EXPECT_DOUBLE_EQ(v_sub->start()->get(conn2), -1.0);

  auto v_mul = *v1 * 2.0;
  EXPECT_DOUBLE_EQ(v_mul->end()->get(conn1), 2.0);
  EXPECT_DOUBLE_EQ(v_mul->end()->get(conn2), 4.0);
  EXPECT_DOUBLE_EQ(v_mul->start()->get(conn1), 0.0);
  EXPECT_DOUBLE_EQ(v_mul->start()->get(conn2), 2.0);

  auto v_div = *v1 / 2.0;
  EXPECT_DOUBLE_EQ(v_div->end()->get(conn1), 0.5);
  EXPECT_DOUBLE_EQ(v_div->end()->get(conn2), 1.0);
  EXPECT_DOUBLE_EQ(v_div->start()->get(conn1), 0.0);
  EXPECT_DOUBLE_EQ(v_div->start()->get(conn2), 0.5);

  auto v_neg = -(*v1);
  EXPECT_DOUBLE_EQ(v_neg->end()->get(conn1), -1.0);
  EXPECT_DOUBLE_EQ(v_neg->end()->get(conn2), -2.0);
  EXPECT_DOUBLE_EQ(v_neg->start()->get(conn1), -0.0);
  EXPECT_DOUBLE_EQ(v_neg->start()->get(conn2), -1.0);
}

TEST(VectorTest, MagnitudeAndIndexing) {
  auto           unit = std::make_shared<SymbolUnit>(Units::Volt);
  BaseConnection conn1("A");
  BaseConnection conn2("B");

  std::map<BaseConnection, double> end{{conn1, 3.0}, {conn2, 4.0}};
  std::map<BaseConnection, double> start{{conn1, 0.0}, {conn2, 0.0}};

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
  auto           unit1 = std::make_shared<SymbolUnit>(Units::Volt);
  auto           unit2 = std::make_shared<SymbolUnit>(Units::Meter);
  BaseConnection conn1("A");

  std::map<BaseConnection, double> end{{conn1, 1.0}};
  std::map<BaseConnection, double> start{{conn1, 0.0}};

  auto vec = std::make_shared<Vector>(end, start, unit1);
  vec->convert_to(unit2);

  ASSERT_EQ(vec->unit(), unit2);
  ASSERT_EQ(vec->end()->unit(), unit2);
  ASSERT_EQ(vec->start()->unit(), unit2);
}
