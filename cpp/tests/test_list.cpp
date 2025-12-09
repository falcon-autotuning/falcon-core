#include <gtest/gtest.h>

#include <memory>
#include <string>
#include <thread>

#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Map.hpp"
#include "falcon_core/generic/Pair.hpp"

namespace {
using namespace falcon_core;
using namespace generic;
template <typename T>
void test_list_serialization_roundtrip(const std::vector<T>& values) {
  List<T>     list(values);
  std::string json         = list.to_json_string();
  auto        deserialized = List<T>::template from_json_string<List<T>>(json);
  EXPECT_EQ(list, *deserialized);
}
class StrSong : public Song {
  std::string _value;

 public:
  StrSong(std::string value = "") : _value(value) {}

  std::string value() const { return _value; }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this), _value);
  }
};
using StrSongSP = std::shared_ptr<StrSong>;
bool operator==(const StrSong& lhs, const StrSong& rhs) {
  return lhs.value() == rhs.value();
}
bool operator!=(const StrSong& lhs, const StrSong& rhs) {
  return !(lhs == rhs);
}
}  // namespace
CEREAL_REGISTER_TYPE(StrSong)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, StrSong)

CEREAL_REGISTER_TYPE(List<double>)
namespace {
using namespace falcon_core;
using namespace generic;
class ListTest : public ::testing::Test {
 protected:
  std::vector<double>      double_data;
  std::vector<StrSongSP>   song_data;
  std::vector<std::string> str_data;

  ListTest() {
    double_data = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    auto song1  = std::make_shared<StrSong>("hello");
    auto song2  = std::make_shared<StrSong>("world");
    auto song3  = std::make_shared<StrSong>("again");
    song_data   = {song1, song2, song3};
    str_data    = {"hello", "world", "again"};
  }
};

TEST_F(ListTest, CreateEmptyPrimitive) {
  auto list    = List<double>();
  auto correct = std::vector<double>();
  EXPECT_EQ(list.items(), correct);
}

TEST_F(ListTest, CreateEmptySong) {
  auto list    = List<StrSong>();
  auto correct = std::vector<std::shared_ptr<StrSong>>();
  EXPECT_EQ(list.items(), correct);
}

TEST_F(ListTest, CreateEmptyArrayPrimitive) {
  size_t length = 5;
  auto   list   = List<double>(length);
  EXPECT_EQ(list.items().size(), length);
}

TEST_F(ListTest, CreateDefaultPrimitive) {
  size_t length = 10;
  double value  = 8.2;
  auto   list   = List<double>(length, value);
  for (size_t i = 0; i < length; i++) {
    EXPECT_EQ(list.items()[i], value);
  }
}

TEST_F(ListTest, CreateDefaultSong) {
  size_t length = 10;
  auto   value  = std::make_shared<StrSong>("hello");
  auto   list   = List<StrSong>(length, value);
  for (size_t i = 0; i < length; i++) {
    EXPECT_EQ(*list.items()[i], *value);
  }
}

TEST_F(ListTest, CreateFullPrimitives) {
  List<double> list(double_data);
  for (size_t i = 0; i < double_data.size(); i++) {
    EXPECT_EQ(list.items()[i], double_data[i]);
  }
}

TEST_F(ListTest, CreateFullSong) {
  List<StrSong> list(song_data);
  for (size_t i = 0; i < song_data.size(); i++) {
    EXPECT_EQ(*list.items()[i], *song_data[i]);
  }
}

TEST_F(ListTest, CreateEmptyPrimitivePushBack) {
  auto   list  = List<double>();
  double value = 10.0;
  EXPECT_EQ(list.size(), 0);
  list.push_back(value);
  EXPECT_EQ(list[0], value);
  EXPECT_EQ(list.size(), 1);
}

TEST_F(ListTest, CreateEmptySongPushBack) {
  auto list  = List<StrSong>();
  auto value = std::make_shared<StrSong>("Whee");
  EXPECT_EQ(list.size(), 0);
  list.push_back(value);
  EXPECT_EQ(list[0], value);
  EXPECT_EQ(list.size(), 1);
}

TEST_F(ListTest, CreateFullPrimitivePushBack) {
  auto   list  = List<double>(double_data);
  double value = 10.0;
  list.push_back(value);
  EXPECT_EQ(list[10], value);
}

TEST_F(ListTest, CreateFullSongPushBack) {
  auto list  = List<StrSong>(song_data);
  auto value = std::make_shared<StrSong>("Whee");
  list.push_back(value);
  EXPECT_EQ(list[3], value);
}

TEST_F(ListTest, SizePrimitives) {
  auto list = List<double>(double_data);
  EXPECT_EQ(list.size(), 10);
}

TEST_F(ListTest, SizeSongs) {
  auto list = List<StrSong>(song_data);
  EXPECT_EQ(list.size(), 3);
}

TEST_F(ListTest, NotEmptyPrimitives) {
  auto list = List<double>(double_data);
  EXPECT_FALSE(list.empty());
}

TEST_F(ListTest, NotEmptySongs) {
  auto list = List<StrSong>(song_data);
  EXPECT_FALSE(list.empty());
}

TEST_F(ListTest, EmptyPrimitives) {
  auto list = List<double>();
  EXPECT_TRUE(list.empty());
}

TEST_F(ListTest, EmptySongs) {
  auto list = List<StrSong>();
  EXPECT_TRUE(list.empty());
}

TEST_F(ListTest, AtPrimitives) {
  auto list = List<double>(double_data);
  EXPECT_EQ(list.at(2), 2.0);
}

TEST_F(ListTest, AtSongs) {
  auto list = List<StrSong>(song_data);
  EXPECT_EQ(list.at(2)->value(), "again");
}

TEST_F(ListTest, AtPrimitivesOOB) {
  auto list = List<double>(double_data);
  EXPECT_THROW(list.at(20), std::out_of_range);
}

TEST_F(ListTest, AtSongsOOB) {
  auto list = List<StrSong>(song_data);
  EXPECT_THROW(list.at(20), std::out_of_range);
}

TEST_F(ListTest, BracketPrimitives) {
  auto list = List<double>(double_data);
  EXPECT_EQ(list[2], 2.0);
}

TEST_F(ListTest, BracketSongs) {
  auto list = List<StrSong>(song_data);
  EXPECT_EQ(list[2]->value(), "again");
}

TEST_F(ListTest, BracketPrimitivesOOB) {
  auto list = List<double>(double_data);
  EXPECT_THROW(list[20], std::out_of_range);
}

TEST_F(ListTest, BracketSongsOOB) {
  auto list = List<StrSong>(song_data);
  EXPECT_THROW(list[20], std::out_of_range);
}

TEST_F(ListTest, ItemsAccess) {
  List<double> list(double_data);
  EXPECT_EQ(list.items(), double_data);
  list.replace_at(0, 32.0);
  EXPECT_EQ(list.items()[0], 32.0);
}

TEST_F(ListTest, OOBAtPrimitive) {
  List<double> list(double_data);
  ASSERT_THROW(list[11], std::out_of_range);
}

TEST_F(ListTest, OOBAtSong) {
  List<StrSong> list(song_data);
  ASSERT_THROW(list[11], std::out_of_range);
}

TEST_F(ListTest, Iterators) {
  List<double> list(double_data);
  double       sum = 0.0;
  for (auto it = list.begin(); it != list.end(); ++it) {
    sum += *it;
  }
  EXPECT_EQ(sum, 45.0);
}

TEST_F(ListTest, RangeIterators) {
  List<double> list(double_data);
  double       sum = 0.0;
  for (const auto& value : list) {
    sum += value;
  }
  EXPECT_EQ(sum, 45.0);
}

TEST_F(ListTest, ConstIterators) {
  const List<double> list(double_data);
  double             sum = 0.0;
  for (auto it = list.begin(); it != list.end(); ++it) {
    sum += *it;
  }
  EXPECT_EQ(sum, 45.0);
}

TEST_F(ListTest, RangeConstIterators) {
  const List<double> list(double_data);
  double             sum = 0.0;
  for (const auto& value : list) {
    sum += value;
  }
  EXPECT_EQ(sum, 45.0);
}

TEST_F(ListTest, SongRangeIterators) {
  List<StrSong> list(song_data);
  std::string   total;
  for (const auto& value : list) {
    total.append(value->value());
  }
  EXPECT_EQ(total, "helloworldagain");
}

TEST_F(ListTest, SongRangeConstIterators) {
  const List<StrSong> list(song_data);
  std::string         total;
  for (const auto& value : list) {
    total.append(value->value());
  }
  EXPECT_EQ(total, "helloworldagain");
}

TEST_F(ListTest, ContainsPrimitive) {
  List<double> list(double_data);
  EXPECT_TRUE(list.contains(5.0));
  EXPECT_FALSE(list.contains(100.0));
}

TEST_F(ListTest, ContainsSong) {
  List<StrSong> list(song_data);
  auto          song = std::make_shared<StrSong>("hello");
  EXPECT_TRUE(list.contains(song));
  auto not_in_list = std::make_shared<StrSong>("not");
  EXPECT_FALSE(list.contains(not_in_list));
}

TEST_F(ListTest, IndexPrimitive) {
  List<double> list(double_data);
  EXPECT_EQ(list.index(5.0), 5);
  EXPECT_THROW(list.index(100.0), std::out_of_range);
}

TEST_F(ListTest, IndexSong) {
  List<StrSong> list(song_data);
  auto          song = std::make_shared<StrSong>("hello");
  EXPECT_EQ(list.index(song), 0);
  auto not_in_list = std::make_shared<StrSong>("not");
  EXPECT_THROW(list.index(not_in_list), std::out_of_range);
}

TEST_F(ListTest, InsertRange) {
  List<double>        list;
  std::vector<double> vals = {1.0, 2.0, 3.0};
  list.insert(list.begin(), vals.begin(), vals.end());
  EXPECT_EQ(list.size(), 3);
  EXPECT_EQ(list[0], 1.0);
}

TEST_F(ListTest, Intersection) {
  auto list1 =
      std::make_shared<List<double>>(std::vector<double>{1.0, 2.0, 3.0});
  auto list2 =
      std::make_shared<List<double>>(std::vector<double>{2.0, 3.0, 4.0});
  auto result = list1->intersection(list2);
  EXPECT_EQ(result->size(), 2);
  EXPECT_TRUE(result->contains(2.0));
  EXPECT_TRUE(result->contains(3.0));
}

TEST_F(ListTest, IntersectionEmpty) {
  auto list1  = std::make_shared<List<double>>(std::vector<double>{1.0});
  auto list2  = std::make_shared<List<double>>(std::vector<double>{2.0});
  auto result = list1->intersection(list2);
  EXPECT_EQ(result->size(), 0);
}

TEST_F(ListTest, Clear) {
  List<double> list(double_data);
  list.clear();
  EXPECT_TRUE(list.empty());
  EXPECT_EQ(list.size(), 0);
}

TEST_F(ListTest, EraseAt) {
  List<double> list(double_data);
  list.erase_at(1);
  EXPECT_EQ(list.at(1), 2.0);
}

TEST_F(ListTest, NoEraseAt) {
  List<double> list(double_data);
  EXPECT_THROW(list.erase_at(10), std::out_of_range);
}

TEST_F(ListTest, SerializeDeserialize) {
  List<double> list(double_data);
  auto         string = list.to_json_string();
  auto         list2  = List<double>::from_json_string<List<double>>(string);
  EXPECT_EQ(*list2, list);
}

TEST_F(ListTest, BackReturnsLastElement) {
  List<double> list(double_data);
  list.push_back(1);
  list.push_back(2);
  EXPECT_EQ(list.back(), 2);
  const auto& clist = list;
  EXPECT_EQ(clist.back(), 2);
}

TEST_F(ListTest, BackThrowsOnEmptyList) {
  List<int> empty_list;
  EXPECT_THROW(empty_list.back(), std::out_of_range);

  const List<int> const_empty_list;
  EXPECT_THROW(const_empty_list.back(), std::out_of_range);
}

TEST_F(ListTest, PushBackThrowsOnNullPointer) {
  List<StrSong> list(song_data);
  StrSongSP     bad;
  EXPECT_THROW(list.push_back(bad), std::invalid_argument);
}

TEST_F(ListTest, ContainsThrowsOnNullPointer) {
  List<StrSong> list(song_data);
  StrSongSP     bad;
  EXPECT_THROW(list.contains(bad), std::invalid_argument);
}

TEST_F(ListTest, IndexThrowsOnNullPointer) {
  List<StrSong> list(song_data);
  StrSongSP     bad;
  EXPECT_THROW(list.index(bad), std::invalid_argument);
}

TEST_F(ListTest, IntersectionThrowsOnNullPointer) {
  List<StrSong> list(song_data);
  EXPECT_THROW(list.intersection(nullptr), std::invalid_argument);
}

TEST_F(ListTest, EqualityPrimitives) {
  List<std::string> list(str_data);
  List<std::string> list2(str_data);
  list2.push_back(std::string("hi"));
  EXPECT_EQ(list, list);
  EXPECT_NE(list, list2);
}

TEST_F(ListTest, BackReturnsLastElementPrimitive) {
  List<double> list(double_data);
  EXPECT_EQ(list.back(), double_data.back());
  const List<double>& clist = list;
  EXPECT_EQ(clist.back(), double_data.back());
  std::vector<int> int_data = {1, 2};
  List<int>        list2(int_data);
  EXPECT_EQ(list2.back(), int_data.back());
  const List<int>& clist2 = list2;
  EXPECT_EQ(clist2.back(), int_data.back());
}

TEST_F(ListTest, BackReturnsLastElementSong) {
  List<StrSong> list(song_data);
  EXPECT_EQ(*list.back(), *song_data.back());
  const List<StrSong>& clist = list;
  EXPECT_EQ(*clist.back(), *song_data.back());
}

TEST_F(ListTest, BackThrowsOnEmptyListPrimitive) {
  List<int> empty_list;
  EXPECT_THROW(empty_list.back(), std::out_of_range);
  const List<int> const_empty_list;
  EXPECT_THROW(const_empty_list.back(), std::out_of_range);
  List<double> list;
  EXPECT_THROW(list.back(), std::out_of_range);
}

TEST_F(ListTest, EqualityPrimitiveEdgeCases) {
  List<double> list1({1.0, 2.0, 3.0});
  List<double> list2({1.0, 2.0, 3.0});
  List<double> list3(std::vector<double>{1.0, 2.0});
  List<double> list4({1.0, 2.0, 4.0});
  EXPECT_TRUE(list1 == list2);   // same size, same values
  EXPECT_FALSE(list1 == list3);  // different size
  EXPECT_FALSE(list1 == list4);  // same size, different values
}

TEST_F(ListTest, EqualityStringEdgeCases) {
  List<std::string> list1({"a", "b", "c"});
  List<std::string> list2({"a", "b", "c"});
  List<std::string> list3({"a", "b"});
  List<std::string> list4({"a", "b", "d"});
  EXPECT_TRUE(list1 == list2);   // same size, same values
  EXPECT_FALSE(list1 == list3);  // different size
  EXPECT_FALSE(list1 == list4);  // same size, different values
}

TEST_F(ListTest, EqualitySongEdgeCases) {
  auto song1 = std::make_shared<StrSong>("hello");
  auto song2 = std::make_shared<StrSong>("world");
  auto song3 = std::make_shared<StrSong>("again");
  auto song4 = std::make_shared<StrSong>("different");

  List<StrSong> list1({song1, song2, song3});
  List<StrSong> list2({song1, song2, song3});
  List<StrSong> list3({song1, song2});
  List<StrSong> list4({song1, song2, song4});

  EXPECT_TRUE(list1 == list2);   // same size, same values
  EXPECT_FALSE(list1 == list3);  // different size
  EXPECT_FALSE(list1 == list4);  // same size, different values
}

TEST_F(ListTest, MultiThreadedAt) {
  List<StrSong>            list(song_data);
  std::shared_ptr<StrSong> b = list.at(0);

  std::thread t1([&list, this] {
    std::shared_ptr<StrSong> song1 = std::make_shared<StrSong>("Changed");
    song_data[0]                   = song1;
  });
  t1.join();

  // b should still have the original title
  EXPECT_NE(b->value(), song_data[0]->value());
  EXPECT_EQ(list.at(0)->value(), "hello");
  EXPECT_EQ(b->value(), "hello");

  std::thread t([&list] {
    std::shared_ptr<StrSong> other = list.at(0);
    list.erase_at(0);
    EXPECT_EQ(list.at(0)->value(), "world");
  });
  t.join();

  // b should still have the original title
  EXPECT_NE(b->value(), song_data[0]->value());
  EXPECT_EQ(b->value(), "hello");
}

TEST(ListSerializationTest, PrimitiveTypes) {
  test_list_serialization_roundtrip<int>({1, 2, 3});
  test_list_serialization_roundtrip<double>({1.1, 2.2, 3.3});
  test_list_serialization_roundtrip<float>({1.1f, 2.2f, 3.3f});
  test_list_serialization_roundtrip<size_t>({1, 2, 3});
  test_list_serialization_roundtrip<std::string>({"a", "b", "c"});
}

TEST(ListSerializationTest, PairTypes) {
  using PairSD                               = Pair<std::string, double>;
  std::vector<std::shared_ptr<PairSD>> pairs = {
      std::make_shared<PairSD>("x", 1.0), std::make_shared<PairSD>("y", 2.0)};
  List<PairSD> list(pairs);
  std::string  json = list.to_json_string();
  auto deserialized = List<PairSD>::from_json_string<List<PairSD>>(json);
  // Compare by value
  ASSERT_EQ(list.size(), deserialized->size());
  for (size_t i = 0; i < list.size(); ++i) {
    EXPECT_EQ(list[i]->first(), deserialized->items()[i]->first());
    EXPECT_EQ(list[i]->second(), deserialized->items()[i]->second());
  }
}
}  // namespace
