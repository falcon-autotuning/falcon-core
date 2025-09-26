#include <gtest/gtest.h>

#include <memory>

#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Map.hpp"
#include "falcon_core/generic/Pair.hpp"

using namespace falcon_core::generic;
// TODO: test all constructor for map
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

TEST_F(MapIntStringTest, OperatorSquareBracket) {
  (*map)[1] = "one";
  EXPECT_EQ(map->at(1), "one");
  EXPECT_EQ((*map)[2], "");
  EXPECT_EQ(map->size(), 2);
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
  EXPECT_TRUE(values->contains("one"));
  EXPECT_TRUE(values->contains("two"));
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
