#include <gtest/gtest.h>

#include <memory>
#include <stdexcept>
#include <vector>

#include "falcon-core/generic/List.hpp"
#include "falcon-core/generic/Song.hpp"
#include "falcon-core/math/Axes.hpp"
namespace {
using namespace falcon_core::math;
using namespace falcon_core::generic;

class DummySong : public Song {
 public:
  DummySong(int v) : value(v) {}
  int  value;
  bool operator==(const DummySong& other) const { return value == other.value; }
  bool operator!=(const DummySong& other) const { return value != other.value; }
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this), value);
  }
};

using DummySongSP = std::shared_ptr<DummySong>;

TEST(AxesTest, DefaultConstructor) {
  Axes<int> axes;
  EXPECT_EQ(axes.size(), 0);
}

TEST(AxesTest, ContainerConstructor) {
  std::vector<int> vec{1, 2, 3};
  Axes<int>        axes(vec);
  EXPECT_EQ(axes.size(), 3);
  EXPECT_EQ(axes.at(0), 1);
}

TEST(AxesTest, ListSPConstructor) {
  auto list = std::make_shared<List<int>>();
  list->push_back(10);
  list->push_back(20);
  Axes<int> axes(list);
  EXPECT_EQ(axes.size(), 2);
  EXPECT_EQ(axes.at(1), 20);
}

TEST(AxesTest, ListSPConstructorNullThrows) {
  ListSP<int> null_list;
  EXPECT_THROW(Axes<int> axes(null_list), std::invalid_argument);
}

TEST(AxesTest, EqualityPrimitive) {
  Axes<int> axes1({1, 2, 3});
  Axes<int> axes2({1, 2, 3});
  Axes<int> axes3({1, 2, 4});
  EXPECT_TRUE(axes1 == axes2);
  EXPECT_FALSE(axes1 == axes3);
  EXPECT_TRUE(axes1 != axes3);
}

TEST(AxesTest, EqualitySong) {
  DummySongSP              s1 = std::make_shared<DummySong>(1);
  DummySongSP              s2 = std::make_shared<DummySong>(2);
  DummySongSP              s3 = std::make_shared<DummySong>(1);
  std::vector<DummySongSP> v1{s1, s2};
  std::vector<DummySongSP> v2{s3, s2};
  std::vector<DummySongSP> v3{s2, s1};
  Axes<DummySong>          axes1(v1);
  Axes<DummySong>          axes2(v2);
  Axes<DummySong>          axes3(v3);
  EXPECT_TRUE(axes1 == axes2);
  EXPECT_FALSE(axes1 == axes3);
  EXPECT_TRUE(axes1 != axes3);
}

TEST(AxesTest, SerializationRoundTrip) {
  Axes<int> axes({1, 2, 3});
  auto      json  = axes.to_json_string();
  auto      axes2 = Axes<int>::from_json_string<Axes<int>>(json);
  EXPECT_EQ(axes, *axes2);
}
}  // namespace
