#include <gtest/gtest.h>

#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Map.hpp"
#include "falcon_core/generic/Pair.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/Quantity.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
namespace {
using namespace falcon_core::generic;
using namespace falcon_core::generic;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::math;
using namespace falcon_core::instrument_interfaces::names;
using namespace falcon_core::instrument_interfaces::port_transforms;
class MapIntStringTest : public ::testing::Test {
 protected:
  using Key     = int;
  using Value   = std::string;
  using MapType = Map<Key, Value>;
  std::shared_ptr<MapType> map;

  void SetUp() override { map = std::make_shared<MapType>(); }
};

TEST_F(MapIntStringTest, DefaultConstructEmpty) {
  EXPECT_EQ(map->size(), 0);
  EXPECT_TRUE(map->empty());
}

TEST_F(MapIntStringTest, InsertOrAssignAndFind) {
  map->insert_or_assign(1, "one");
  map->insert_or_assign(2, "two");
  EXPECT_EQ(map->size(), 2);
  EXPECT_EQ(map->at(1), "one");
  EXPECT_EQ(map->at(2), "two");
  EXPECT_TRUE(map->contains(1));
  EXPECT_FALSE(map->contains(3));
}

TEST_F(MapIntStringTest, InsertReturnsIteratorAndBool) {
  auto result = map->insert(1, "one");
  EXPECT_TRUE(result.second);
  EXPECT_EQ((*result.first)->first(), 1);
  EXPECT_EQ((*result.first)->second(), "one");
  auto result2 = map->insert(1, "uno");
  EXPECT_FALSE(result2.second);
  EXPECT_EQ((*result2.first)->second(), "one");
}

TEST_F(MapIntStringTest, EraseKey) {
  map->insert_or_assign(1, "one");
  map->insert_or_assign(2, "two");
  map->erase(1);
  EXPECT_FALSE(map->contains(1));
  EXPECT_EQ(map->size(), 1);
}

TEST_F(MapIntStringTest, ClearAndEmpty) {
  map->insert_or_assign(1, "one");
  map->clear();
  EXPECT_TRUE(map->empty());
  EXPECT_EQ(map->size(), 0);
}

TEST_F(MapIntStringTest, KeysAndValues) {
  map->insert_or_assign(1, "one");
  map->insert_or_assign(2, "two");
  auto keys   = map->keys();
  auto values = map->values();
  EXPECT_EQ(keys->size(), 2);
  EXPECT_EQ(values->size(), 2);
  EXPECT_TRUE(keys->contains(1));
  EXPECT_TRUE(keys->contains(2));
  EXPECT_TRUE(values->contains(std::string("one")));
  EXPECT_TRUE(values->contains(std::string("two")));
}

TEST_F(MapIntStringTest, AtThrowsIfNotFound) {
  EXPECT_THROW(map->at(42), std::out_of_range);
}

TEST_F(MapIntStringTest, ConstructFromVector) {
  std::vector<std::pair<int, std::string>> vec = {{1, "one"}, {2, "two"}};
  MapType                                  m(vec);
  EXPECT_EQ(m.size(), 2);
  EXPECT_EQ(m.at(1), "one");
  EXPECT_EQ(m.at(2), "two");
}

TEST_F(MapIntStringTest, ConstructFromList) {
  using PairType = Pair<int, std::string>;
  List<PairType> list;
  list.push_back(std::make_shared<PairType>(1, "one"));
  list.push_back(std::make_shared<PairType>(2, "two"));
  MapType m(list);
  EXPECT_EQ(m.size(), 2);
  EXPECT_EQ(m.at(1), "one");
  EXPECT_EQ(m.at(2), "two");
}

TEST(MapStringDouble, PushbackNull) {
  List<Pair<std::string, double>> list;
  PairSP<std::string, double>     bad;
  EXPECT_THROW(list.push_back(bad), std::invalid_argument);
}

TEST(MapConnectionDoubleTest, DefaultConstructEmpty) {
  Map<Connection, double> m;
  EXPECT_EQ(m.size(), 0);
  EXPECT_TRUE(m.empty());
}

TEST(MapConnectionDoubleTest, InsertOrAssignAndFind) {
  auto                    conn = Connection::BarrierGate("A");
  Map<Connection, double> m;
  m.insert_or_assign(conn, 1.23);
  EXPECT_EQ(m.at(conn), 1.23);
  EXPECT_TRUE(m.contains(conn));
}

TEST(MapConnectionDoubleTest, InsertReturnsIteratorAndBool) {
  auto                    conn = Connection::BarrierGate("A");
  Map<Connection, double> m;
  auto                    result = m.insert(conn, 1.23);
  EXPECT_TRUE(result.second);
  EXPECT_EQ((*result.first)->first(), conn);
  EXPECT_EQ((*result.first)->second(), 1.23);
  auto result2 = m.insert(conn, 2.34);
  EXPECT_FALSE(result2.second);
  EXPECT_EQ((*result2.first)->second(), 1.23);
}

TEST(MapConnectionDoubleTest, EraseKey) {
  auto                    conn = Connection::BarrierGate("A");
  Map<Connection, double> m;
  m.insert_or_assign(conn, 1.23);
  m.erase(conn);
  EXPECT_FALSE(m.contains(conn));
  EXPECT_EQ(m.size(), 0);
}

TEST(MapConnectionDoubleTest, KeysAndValues) {
  auto                    conn1 = Connection::BarrierGate("A");
  auto                    conn2 = Connection::BarrierGate("B");
  Map<Connection, double> m;
  m.insert_or_assign(conn1, 1.0);
  m.insert_or_assign(conn2, 2.0);
  auto keys   = m.keys();
  auto values = m.values();
  EXPECT_EQ(keys->size(), 2);
  EXPECT_EQ(values->size(), 2);
  EXPECT_TRUE(keys->contains(conn1));
  EXPECT_TRUE(keys->contains(conn2));
  EXPECT_TRUE(values->contains(1.0));
  EXPECT_TRUE(values->contains(2.0));
}

TEST(MapConnectionDoubleTest, AtThrowsIfNotFound) {
  Map<Connection, double> m;
  auto                    conn = Connection::BarrierGate("A");
  EXPECT_THROW(m.at(conn), std::out_of_range);
}

TEST(MapConnectionDoubleTest, ConstructFromVector) {
  auto conn1 = Connection::BarrierGate("A");
  auto conn2 = Connection::BarrierGate("B");
  std::vector<std::pair<ConnectionSP, double>> vec = {{conn1, 1.0},
                                                      {conn2, 2.0}};
  Map<Connection, double>                      m(vec);
  EXPECT_EQ(m.size(), 2);
  EXPECT_EQ(m.at(conn1), 1.0);
  EXPECT_EQ(m.at(conn2), 2.0);
}

TEST(MapConnectionDoubleTest, ConstructFromList) {
  using PairType = Pair<Connection, double>;
  List<PairType> list;
  auto           conn1 = Connection::BarrierGate("A");
  auto           conn2 = Connection::BarrierGate("B");
  list.push_back(std::make_shared<PairType>(conn1, 1.0));
  list.push_back(std::make_shared<PairType>(conn2, 2.0));
  Map<Connection, double> m(list);
  EXPECT_EQ(m.size(), 2);
  EXPECT_EQ(m.at(conn1), 1.0);
  EXPECT_EQ(m.at(conn2), 2.0);
}

TEST(MapConnectionDoubleTest, EqualityOperators) {
  auto                    conn1 = Connection::BarrierGate("A");
  auto                    conn2 = Connection::BarrierGate("B");
  Map<Connection, double> m1;
  Map<Connection, double> m2;
  m1.insert_or_assign(conn1, 1.0);
  m1.insert_or_assign(conn2, 2.0);
  m2.insert_or_assign(conn1, 1.0);
  m2.insert_or_assign(conn2, 2.0);
  EXPECT_TRUE(m1 == m2);
  EXPECT_FALSE(m1 != m2);

  m2.insert_or_assign(conn2, 3.0);
  EXPECT_FALSE(m1 == m2);
  EXPECT_TRUE(m1 != m2);
}

TEST(MapConnectionConnectionTest, AtThrowsIfNotFound) {
  Map<Connection, Connections> m;
  auto                         conn = Connection::BarrierGate("A");
  EXPECT_THROW(m.at(conn), std::out_of_range);
}

TEST(MapConnectionDoubleTest, SerializationAndEquality) {
  auto                    conn1 = Connection::BarrierGate("A");
  auto                    conn2 = Connection::BarrierGate("B");
  Map<Connection, double> m1;
  m1.insert_or_assign(conn1, 1.0);
  m1.insert_or_assign(conn2, 2.0);
  auto string = m1.to_json_string();
  auto m2 = Map<Connection, double>::from_json_string<Map<Connection, double>>(
      string);
  EXPECT_EQ(m1, *m2);
}
}  // namespace
