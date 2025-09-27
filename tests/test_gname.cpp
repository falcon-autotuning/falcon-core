#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/names/Gname.hpp"
namespace {
using namespace falcon_core::autotuner_interfaces::names;

TEST(GnameTest, ConstructFromString) {
  Gname g("group1");
  EXPECT_EQ(g.name(), "group1");
  EXPECT_EQ(g.num(), 1);
}

TEST(GnameTest, ConstructFromInt) {
  Gname g(42);
  EXPECT_EQ(g.num(), 42);
  EXPECT_EQ(g.gname(), "group42");
}

TEST(GnameTest, SerializationRoundTrip) {
  Gname orig("group4");
  auto  string = orig.to_json_string();
  auto  copy   = NameBase::from_json_string<Gname>(string);
  ASSERT_NE(copy, nullptr);
  EXPECT_EQ(orig.name(), copy->name());
  EXPECT_EQ(orig.gname(), copy->gname());
}

}  // namespace
