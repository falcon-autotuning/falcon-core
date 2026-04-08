#include <gtest/gtest.h>

#include "cereal/access.hpp"
#include "cereal/types/polymorphic.hpp"
#include "falcon-core/generic/Pair.hpp"
namespace {
using namespace falcon_core::generic;

class Dummy : public Song {
  int _value;

 public:
  Dummy(int v = 0) : _value(v) {}
  bool operator==(const Dummy& other) const { return _value == other._value; }
  int  value() { return _value; }

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this), _value);
  }
};
using DummySP = std::shared_ptr<Dummy>;
}  // namespace
CEREAL_REGISTER_TYPE(::Dummy)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, ::Dummy)
using PID = falcon_core::generic::Pair<int, double>;
CEREAL_REGISTER_TYPE(PID)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PID);
using PDD = falcon_core::generic::Pair<::Dummy, ::Dummy>;
CEREAL_REGISTER_TYPE(PDD)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PDD);
namespace {
using namespace falcon_core::generic;

TEST(PairTest, PrimitiveTypes) {
  Pair<int, double> pair(42, 3.14);
  EXPECT_EQ(pair.first(), 42);
  EXPECT_EQ(pair.second(), 3.14);
}

TEST(PairTest, NonPrimitiveTypes) {
  auto               d1 = std::make_shared<Dummy>(7);
  auto               d2 = std::make_shared<Dummy>(9);
  Pair<Dummy, Dummy> pair(d1, d2);
  EXPECT_EQ(pair.first()->value(), 7);
  EXPECT_EQ(pair.second()->value(), 9);
}

TEST(PairTest, MixedTypes) {
  auto             d = std::make_shared<Dummy>(5);
  Pair<int, Dummy> pair(10, d);
  EXPECT_EQ(pair.first(), 10);
  EXPECT_EQ(pair.second()->value(), 5);
}

#if !defined(_WIN32)
TEST(PairTest, SerializationPrimitive) {
  Pair<int, double> orig(1, 2.5);
  auto              string = orig.to_json_string();
  auto              restored =
      Pair<int, double>::from_json_string<Pair<int, double>>(string);
  EXPECT_EQ(restored->first(), 1);
  EXPECT_EQ(restored->second(), 2.5);
}

TEST(PairTest, SerializationNonPrimitive) {
  auto               d1 = std::make_shared<Dummy>(11);
  auto               d2 = std::make_shared<Dummy>(22);
  Pair<Dummy, Dummy> orig(d1, d2);
  auto               string = orig.to_json_string();
  auto               restored =
      Pair<Dummy, Dummy>::from_json_string<Pair<Dummy, Dummy>>(string);
  EXPECT_EQ(restored->first()->value(), 11);
  EXPECT_EQ(restored->second()->value(), 22);
}
#endif
TEST(PairTest, Equality) {
  auto               d1 = std::make_shared<Dummy>(11);
  auto               d2 = std::make_shared<Dummy>(22);
  Pair<Dummy, Dummy> orig(d1, d2);
  auto               d3 = std::make_shared<Dummy>(11);
  auto               d4 = std::make_shared<Dummy>(24);
  Pair<Dummy, Dummy> orig1(d3, d4);
  EXPECT_EQ(orig, orig);
  EXPECT_NE(orig, orig1);
}
}  // namespace
